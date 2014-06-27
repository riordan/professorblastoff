/**
 * @file SURF_Homography
 * @brief SURF detector + descriptor + FLANN Matcher + FindHomography
 * @author A. Huaman
 */

/**
* This is the worst thing to compile ever:
* g++ `Magick++-config --cxxflags --cppflags` -o newSURF newSURF.cpp `Magick++-config --ldflags --libs` $(pkg-config --libs opencv)
*/

/**
* Ideal point structure (facing correct side up):
* 3  2
* 0  1
*/


#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <Magick++.h> 
#include <math.h>
 
using namespace Magick; 
using namespace std;
using namespace cv;

void readme();

/**
 * @function main
 * @brief Main function
 */
int main( int argc, char** argv )
{
  if( argc != 3 )
  { readme(); return -1; }

  Mat img_object = imread( argv[1], IMREAD_GRAYSCALE ); //Needle
  Mat img_scene = imread( argv[2], IMREAD_GRAYSCALE ); //Haystack

  if( !img_object.data || !img_scene.data )
  { std::cout<< " --(!) Error reading images " << std::endl; return -1; }

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


  //-- Localize the object from img_1 in img_2
  std::vector<Point2f> obj;
  std::vector<Point2f> scene;

  for( size_t i = 0; i < good_matches.size(); i++ )
  {
    //-- Get the keypoints from the good matches
    obj.push_back( keypoints_object[ good_matches[i].queryIdx ].pt );
    scene.push_back( keypoints_scene[ good_matches[i].trainIdx ].pt );
  }

  Mat H = findHomography( obj, scene, RANSAC );

  //-- Get the corners from the image_1 ( the object to be "detected" )
  std::vector<Point2f> obj_corners(4);
  obj_corners[0] = Point(0,0); obj_corners[1] = Point( img_object.cols, 0 );
  obj_corners[2] = Point( img_object.cols, img_object.rows ); obj_corners[3] = Point( 0, img_object.rows );
  std::vector<Point2f> scene_corners(4);

  perspectiveTransform( obj_corners, scene_corners, H);


  //-- Draw lines between the corners (the mapped object in the scene - image_2 )
  Point2f offset( (float)img_object.cols, 0);
  std:cout<< "OFFSET POINTS: " << img_object.cols << std::endl;
  line( img_matches, scene_corners[0] + offset, scene_corners[1] + offset, Scalar(0, 255, 0), 4 );
  line( img_matches, scene_corners[1] + offset, scene_corners[2] + offset, Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[2] + offset, scene_corners[3] + offset, Scalar( 0, 255, 0), 4 );
  line( img_matches, scene_corners[3] + offset, scene_corners[0] + offset, Scalar( 0, 255, 0), 4 );

  //-- Show detected matches
  //imshow( "Good Matches & Object detection", img_matches );
  //waitKey(0);

  
/** Beginning of ImageMagick
//-- PASTED MAGICK++ CODE GOES HERE
  InitializeMagick(argv[0]);

  // Construct the image object. Seperating image construction from the 
  // the read operation ensures that a failure to read the image file 
  // doesn't render the image object useless. 
  Image image;
  image.read( argv[2] );
    // Read a file into image object 
    

    // Crop the image to specified size (width, height, xOffset, yOffset)
 //   image.crop( Geometry((int)scene_corners[0],(int)scene_corners[1], (int)scene_corners[2], (int)scene_corners[3]) );
//image.draw(DrawableCircle(100,100,1,1));
//image.draw(DrawableCircle((int)scene_corners[0].x,(int)scene_corners[0].y,1,1));
//image.draw(DrawableCircle((int)scene_corners[1].x,(int)scene_corners[1].y,1,1));
//image.draw(DrawableCircle((int)scene_corners[2].x,(int)scene_corners[2].y,1,1));
//image.draw(DrawableCircle((int)scene_corners[3].x,(int)scene_corners[3].y,1,1));
  image.draw(DrawableText(scene_corners[0].x, scene_corners[0].y, "0"));
  image.draw(DrawableText(scene_corners[1].x, scene_corners[1].y, "1"));
  image.draw(DrawableText(scene_corners[2].x, scene_corners[2].y, "2"));
  image.draw(DrawableText(scene_corners[3].x, scene_corners[3].y, "3"));



     //image.display();
    // Write the image to a file 
    image.write( "x.jpeg" ); 
* End of ImageMagick */


    // ROTATION TESTING
    std::cout << "Rotation Points:" << std::endl;
    std::cout << "Point 0: " << scene_corners[0].x << ", " << scene_corners[0].y << std::endl;
    std::cout << "Point 1: " << scene_corners[1].x << ", " << scene_corners[1].y << std::endl;
    std::cout << "Point 2: " << scene_corners[2].x << ", " << scene_corners[2].y << std::endl;
    std::cout << "Point 3: " << scene_corners[3].x << ", " << scene_corners[3].y << std::endl;


    //haystack dimensions
    std::cout << "Haystack image attributes" << std::endl;
    std::cout << "Width:" <<  img_scene.size().width << std::endl;
    std::cout  << "Height:" <<  img_scene.size().height << std::endl;

std::vector<Point2f> adjust_corners(4);

// CONCEPTUAL SECTION BREAK
// Now we create a copy of the Haystack, padded so we can rotate
//   the entire image without losing any data to cropping.

Mat img_PadHaystack;
img_PadHaystack = img_scene;
int oldWidth = img_scene.size().width;
int oldHeight = img_scene.size().height;

  //-- Show Haystack
imshow( "Haystack", img_scene );
waitKey(0);

// Calculate the hypotenuse of Haystack (ceil everything to keep it int-y)
int newWidth = (int)ceil(sqrt((oldWidth*oldWidth)+(oldHeight*oldHeight)));
int newHeight = (int)ceil(sqrt((oldWidth*oldWidth)+(oldHeight*oldHeight)));
std::cout << "New Haystack image attributes" << std::endl;
std::cout << "New Width:" <<  newWidth << std::endl;
std::cout  << "New Height:" <<  newHeight << std::endl;

// Calculate how much padding you need
int padWidth = (int)ceil( (newWidth - oldWidth)/2 );
int padHeight = (int)ceil( ( newHeight - oldHeight) /2);
std::cout << "New PADDINGHaystack image attributes" << std::endl;
std::cout << "Padding Width:" <<  padWidth << std::endl;
std::cout  << "Padding Height:" <<  padHeight << std::endl;

copyMakeBorder(img_scene, img_PadHaystack, padHeight, padHeight, padWidth, padWidth, BORDER_CONSTANT);
  //-- Show New Padded Haystack

// draw the box because yeah!
  line( img_PadHaystack, scene_corners[0] + (float)padWidth, scene_corners[1] + (float)padHeight, Scalar(0, 255, 0), 4 );
  line( img_PadHaystack, scene_corners[1]+ (float)padWidth, scene_corners[2] + (float)padHeight, Scalar( 0, 255, 0), 4 );
  line( img_PadHaystack, scene_corners[2]+ (float)padWidth, scene_corners[3] + (float)padHeight, Scalar( 0, 255, 0), 4 );
  line( img_PadHaystack, scene_corners[3]+ (float)padWidth, scene_corners[0] + (float)padHeight, Scalar( 0, 255, 0), 4 );
(float)

imshow( "Padded Haystack", img_PadHaystack );
waitKey(0);




// Show detected matches
 //imshow( "Show new rotated canvas", dest ); //old canvas because FUCK IT!
 //waitKey(0);




  return 0;
}

/**
 * @function readme
 */
void readme()
{ std::cout << " Usage: ./SURF_Homography <img1> <img2>" << std::endl; }




//You're going to have to rewrite all of this someday
/** How this should work:
* Runs SURF_Homography
* Finds needles's corners inside haystack
* Rotates haystack so it matches needle orientation (correct angling)
* Extract create crop of Needle from Haystack
* NEED METHODOLOGY FOR COLOR MATCHING THEN DO THAT
* Save Needle-big to disk
* CRAZYTOWN: Image classifier of colorbars


* How the rotation will work:
* Flip so origin (point 0) is at upper left and point 1 is on the same y axis
* Ensure point 2 & 3 are on the same y axis - if not set to whichever has lower y as both
* Point 1.x == Point 3.x (and set whichever is longer as origin point)

*/