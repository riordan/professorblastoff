/*
#TODOS:
* Error handling
 * Detecting an unprocesable (non-SURF-able) image
 * Detecting a wrongly flipped image
* Figure out why it's oversizing (I think it has to do with the floats so it works with integer operations and is resizing the)



*/


#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>

using namespace cv;

void readme();  


// This is the part where we rip off Stack OverFlow
//http://stackoverflow.com/questions/16587274/opencv-2-4-3-warpperspective-with-reversed-homography-on-a-cropped-image
cv::Rect computeWarpedContourRegion(const std::vector<Point2f> & points, const cv::Mat & homography)
{
    std::vector<cv::Point2f> transformed_points(points.size());

    for(unsigned int i=0; i<points.size(); ++i)
    {
        // warp the points
        transformed_points[i].x = points[i].x * homography.at<double>(0,0) + points[i].y * homography.at<double>(0,1) + homography.at<double>(0,2) ;
        transformed_points[i].y = points[i].x * homography.at<double>(1,0) + points[i].y * homography.at<double>(1,1) + homography.at<double>(1,2) ;
    }

    // dehomogenization necessary?
    if(homography.rows == 3)
    {
        float homog_comp;
        for(unsigned int i=0; i<transformed_points.size(); ++i)
        {
            homog_comp = points[i].x * homography.at<double>(2,0) + points[i].y * homography.at<double>(2,1) + homography.at<double>(2,2) ;
            transformed_points[i].x /= homog_comp;
            transformed_points[i].y /= homog_comp;
        }
    }

    // now find the bounding box for these points:
    cv::Rect boundingBox = cv::boundingRect(transformed_points);
    return boundingBox;
}

cv::Mat adjustHomography(const cv::Rect & transformedRegion, const cv::Mat & homography)
{
    if(homography.rows == 2) throw("homography adjustement for affine matrix not implemented yet");

    // unit matrix
    cv::Mat correctionHomography = cv::Mat::eye(3,3,CV_64F);
    // correction translation
    correctionHomography.at<double>(0,2) = -transformedRegion.x;
    correctionHomography.at<double>(1,2) = -transformedRegion.y;


    return correctionHomography * homography;
}






/** @function main */
int main( int argc, char** argv )
{
  if( argc != 3 )
  { readme(); return -1; }

  Mat img_object = imread( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
  Mat img_scene = imread( argv[2], CV_LOAD_IMAGE_GRAYSCALE );
  Mat img_color = imread( argv[2], CV_LOAD_IMAGE_UNCHANGED );

std::cout<<"Scene size:"<<std::endl<<img_scene.size()<<std::endl;


  if( !img_object.data || !img_scene.data )
  { std::cout<< " --(!) Error reading images " << std::endl; return -1; }


/*
  //-- STEP 0: Pad the shit out of img_scene
  // BEGIN STUPID RESIZE
  int oldWidth = img_scene.size().width;
  int oldHeight = img_scene.size().height;

  
  // Calculate the hypotenuse of Haystack (ceil everything to keep it int-y)
  int newWidth = (int)ceil(sqrt((oldWidth*oldWidth)+(oldHeight*oldHeight)));
  int newHeight = (int)ceil(sqrt((oldWidth*oldWidth)+(oldHeight*oldHeight)));
  //std::cout << "New Haystack image attributes" << std::endl;
  //std::cout << "New Width:" <<  newWidth << std::endl;
  //std::cout  << "New Height:" <<  newHeight << std::endl;
  
  // Calculate how much padding you need
  int padWidth = (int)ceil( (newWidth - oldWidth)/2 );
  int padHeight = (int)ceil( ( newHeight - oldHeight) /2);
  //std::cout << "New PADDINGHaystack image attributes" << std::endl;
  //std::cout << "Padding Width:" <<  padWidth << std::endl;
  //std::cout  << "Padding Height:" <<  padHeight << std::endl;
  
  copyMakeBorder(img_scene, img_scene, padHeight, padHeight, padWidth, padWidth, BORDER_CONSTANT);
  
  //END STUPID RESIZE
*/




  //-- Step 1: Detect the keypoints using SURF Detector
  int minHessian = 400;

  SurfFeatureDetector detector( minHessian );

  std::vector<KeyPoint> keypoints_object, keypoints_scene;

  detector.detect( img_object, keypoints_object );
  detector.detect( img_scene, keypoints_scene );

  //-- Step 2: Calculate descriptors (feature vectors)
  SurfDescriptorExtractor extractor;

  Mat descriptors_object, descriptors_scene;

  extractor.compute( img_object, keypoints_object, descriptors_object );
  extractor.compute( img_scene, keypoints_scene, descriptors_scene );

  //-- Step 3: Matching descriptor vectors using FLANN matcher
  FlannBasedMatcher matcher;
  std::vector< DMatch > matches;
  matcher.match( descriptors_object, descriptors_scene, matches );

  double max_dist = 0; double min_dist = 100;

  //-- Quick calculation of max and min distances between keypoints
  for( int i = 0; i < descriptors_object.rows; i++ )
  { double dist = matches[i].distance;
    if( dist < min_dist ) min_dist = dist;
    if( dist > max_dist ) max_dist = dist;
  }

  printf("-- Max dist : %f \n", max_dist );
  printf("-- Min dist : %f \n", min_dist );

  //-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
  std::vector< DMatch > good_matches;

  for( int i = 0; i < descriptors_object.rows; i++ )
  { if( matches[i].distance < 3*min_dist )
     { good_matches.push_back( matches[i]); }
  }

  Mat img_matches;
  drawMatches( img_object, keypoints_object, img_scene, keypoints_scene,
               good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
               vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

  //-- Localize the object
  std::vector<Point2f> obj;
  std::vector<Point2f> scene;

  for( int i = 0; i < good_matches.size(); i++ )
  {
    //-- Get the keypoints from the good matches
    obj.push_back( keypoints_object[ good_matches[i].queryIdx ].pt );
    scene.push_back( keypoints_scene[ good_matches[i].trainIdx ].pt );
  }

  Mat H = findHomography( obj, scene, CV_RANSAC );


  std::cout<< "Homography Matrix" << std::endl << H << std::endl<<std::endl;
  std::cout<< "Inverted Homography Matrix" << std::endl << H.inv() << std::endl;

  //-- Get the corners from the image_1 ( the object to be "detected" )
  std::vector<Point2f> obj_corners(4);
  obj_corners[0] = cvPoint(0,0); obj_corners[1] = cvPoint( img_object.cols, 0 );
  obj_corners[2] = cvPoint( img_object.cols, img_object.rows ); obj_corners[3] = cvPoint( 0, img_object.rows );
  std::vector<Point2f> scene_corners(4);

  perspectiveTransform( obj_corners, scene_corners, H);

  //-- Draw lines between the corners (the mapped object in the scene - image_2 )
  line( img_matches, scene_corners[0] + Point2f( img_object.cols, 0), scene_corners[1] + Point2f( img_object.cols, 0), Scalar(0, 255, 0), 4 );
  line( img_matches, scene_corners[1] + Point2f( img_object.cols, 0), scene_corners[2] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[2] + Point2f( img_object.cols, 0), scene_corners[3] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[3] + Point2f( img_object.cols, 0), scene_corners[0] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );

  //-- Show detected matches
  //imshow( "Good Matches & Object detection", img_matches );
  //waitKey(0);
  


cv::Rect region = computeWarpedContourRegion(scene_corners,H);

std::cout << "Region Rectangle: " <<std::endl << region << std::endl;


Mat aH = adjustHomography(region, H);
std::cout << "Adjusted homography of inverse:" << std::endl<<adjustHomography(region, H)<<std::endl;

Mat please;

warpPerspective(img_color, please, aH, region.size());

//show output
//imshow("Hopefully working math", please);
//waitKey(0);

std::cout<<"Needle size:"<<please.size()<<std::endl;

// Write needle to disk
  imwrite( "outneedle.tif", please );


/*


  //And now we wait

  warpPerspective(img_scene, img_scene, H, img_scene.size(), WARP_INVERSE_MAP);

  //-- Show detected matches
  imshow( "Show me a Needle", img_scene );

  waitKey(0);


  // Write needle to disk
  imwrite( "outneedle.tif", img_scene );

*/

  return 0;
  }

  /** @function readme */
  void readme()
  { std::cout << " Usage: ./SURF_descriptor <img1> <img2>" << std::endl; }