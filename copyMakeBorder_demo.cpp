




<!DOCTYPE html>
<html class="   ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    
    
    <title>opencv/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp at master · Itseez/opencv · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="Itseez/opencv" name="twitter:title" /><meta content="opencv - Open Source Computer Vision Library" name="twitter:description" /><meta content="https://avatars1.githubusercontent.com/u/1786446?s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars1.githubusercontent.com/u/1786446?s=400" property="og:image" /><meta content="Itseez/opencv" property="og:title" /><meta content="https://github.com/Itseez/opencv" property="og:url" /><meta content="opencv - Open Source Computer Vision Library" property="og:description" />

    <link rel="assets" href="https://assets-cdn.github.com/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035">
    

    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
      <meta name="google-analytics" content="UA-3769691-2">

    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="415858A4:4108:DE0C6A5:53AD72E1" name="octolytics-dimension-request_id" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico" />


    <meta content="authenticity_token" name="csrf-param" />
<meta content="TzofrIiNDA2QG7C2ocRCExM6PeR3juAMQFwXQmhSAcn0aaR4Flac0G9nW54ZyDYhkmH2iqns49keBSeXWJcxzA==" name="csrf-token" />

    <link href="https://assets-cdn.github.com/assets/github-bbf4e7b5ed0367744288dcb496d8dcb1b048f4a2.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://assets-cdn.github.com/assets/github2-0917742d67e3f1202b0ccb0086cd7bc8f365566b.css" media="all" rel="stylesheet" type="text/css" />
    


    <meta http-equiv="x-pjax-version" content="9a986c072ca221c7aa2087752c4d53e7">

      
  <meta name="description" content="opencv - Open Source Computer Vision Library" />


  <meta content="1786446" name="octolytics-dimension-user_id" /><meta content="Itseez" name="octolytics-dimension-user_login" /><meta content="5108051" name="octolytics-dimension-repository_id" /><meta content="Itseez/opencv" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="5108051" name="octolytics-dimension-repository_network_root_id" /><meta content="Itseez/opencv" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/Itseez/opencv/commits/master.atom" rel="alternate" title="Recent Commits to opencv:master" type="application/atom+xml" />

  </head>


  <body class="logged_out  env-production  vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      
      <div class="header header-logged-out">
  <div class="container clearfix">

    <a class="header-logo-wordmark" href="https://github.com/">
      <span class="mega-octicon octicon-logo-github"></span>
    </a>

    <div class="header-actions">
        <a class="button primary" href="/join">Sign up</a>
      <a class="button signin" href="/login?return_to=%2FItseez%2Fopencv%2Fblob%2Fmaster%2Fsamples%2Fcpp%2Ftutorial_code%2FImgTrans%2FcopyMakeBorder_demo.cpp">Sign in</a>
    </div>

    <div class="command-bar js-command-bar  in-repository">

      <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
          <li class="features"><a href="/features">Features</a></li>
          <li class="enterprise"><a href="https://enterprise.github.com/">Enterprise</a></li>
          <li class="blog"><a href="/blog">Blog</a></li>
      </ul>
        <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<div class="commandbar">
  <span class="message"></span>
  <input type="text" data-hotkey="s, /" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    
      data-repo="Itseez/opencv"
      data-branch="master"
      data-sha="7a0b751e4508a2bad4e920140a823bd7ae9b5a91"
  >
  <div class="display hidden"></div>
</div>

    <input type="hidden" name="nwo" value="Itseez/opencv" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target" role="button" aria-haspopup="true">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container" aria-hidden="true">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="help tooltipped tooltipped-s" aria-label="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
    </div>

  </div>
</div>



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">


  <li>
      <a href="/login?return_to=%2FItseez%2Fopencv"
    class="minibutton with-count star-button tooltipped tooltipped-n"
    aria-label="You must be signed in to star a repository" rel="nofollow">
    <span class="octicon octicon-star"></span>
    Star
  </a>

    <a class="social-count js-social-count" href="/Itseez/opencv/stargazers">
      2,868
    </a>

  </li>

    <li>
      <a href="/login?return_to=%2FItseez%2Fopencv"
        class="minibutton with-count js-toggler-target fork-button tooltipped tooltipped-n"
        aria-label="You must be signed in to fork a repository" rel="nofollow">
        <span class="octicon octicon-repo-forked"></span>
        Fork
      </a>
      <a href="/Itseez/opencv/network" class="social-count">
        2,661
      </a>
    </li>
</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo"></span>
          <span class="author"><a href="/Itseez" class="url fn" itemprop="url" rel="author"><span itemprop="title">Itseez</span></a></span><!--
       --><span class="path-divider">/</span><!--
       --><strong><a href="/Itseez/opencv" class="js-current-repository js-repo-home-link">opencv</a></strong>

          <span class="page-context-loader">
            <img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/Itseez/opencv" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-hotkey="g c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /Itseez/opencv">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/Itseez/opencv/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g p" data-selected-links="repo_pulls /Itseez/opencv/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>67</span>
            <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/Itseez/opencv/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /Itseez/opencv/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/Itseez/opencv/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /Itseez/opencv/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Network">
        <a href="/Itseez/opencv/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /Itseez/opencv/network">
          <span class="octicon octicon-repo-forked"></span> <span class="full-word">Network</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/Itseez/opencv.git" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/Itseez/opencv.git" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/Itseez/opencv" readonly="readonly">
    <span class="url-box-clippy">
    <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/Itseez/opencv" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <a href="https://help.github.com/articles/which-remote-url-should-i-use" class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <span class="octicon octicon-question"></span>
  </a>
</p>



                <a href="/Itseez/opencv/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download Itseez/opencv as a zip file"
                   title="Download Itseez/opencv as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<a href="/Itseez/opencv/blob/2d81595ed4ac44dd02779485bdd76ec15edb4ee7/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:64dc0ea8998393e4fba3041e553dcbc6 -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target css-truncate" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    title="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button css-truncate-target">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-x js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/blob/2.4/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4">2.4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/blob/2.4.9.x-prep/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.9.x-prep"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.9.x-prep">2.4.9.x-prep</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/blob/master/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/perf4au/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="perf4au"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="perf4au">perf4au</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/carma_release.0.0.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="carma_release.0.0.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="carma_release.0.0.1">carma_release.0.0.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/3.0-ocl-tp2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="3.0-ocl-tp2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="3.0-ocl-tp2">3.0-ocl-tp2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/3.0-ocl-tech-preview/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="3.0-ocl-tech-preview"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="3.0-ocl-tech-preview">3.0-ocl-tech-preview</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.9/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.9"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.9">2.4.9</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.8.2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.8.2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.8.2">2.4.8.2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.8.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.8.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.8.1">2.4.8.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.8/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.8"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.8">2.4.8</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.7-rc1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.7-rc1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.7-rc1">2.4.7-rc1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.7.2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.7.2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.7.2">2.4.7.2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.7.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.7.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.7.1">2.4.7.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.7/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.7"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.7">2.4.7</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.6.2-rc1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.6.2-rc1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.6.2-rc1">2.4.6.2-rc1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.6.2r3/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.6.2r3"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.6.2r3">2.4.6.2r3</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.6.2r2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.6.2r2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.6.2r2">2.4.6.2r2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.6.2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.6.2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.6.2">2.4.6.2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.6.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.6.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.6.1">2.4.6.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.6/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.6"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.6">2.4.6</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.5/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.5"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.5">2.4.5</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.4-beta/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.4-beta"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.4-beta">2.4.4-beta</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.4/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.4"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.4">2.4.4</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.3-rc/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.3-rc"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.3-rc">2.4.3-rc</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.3.2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.3.2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.3.2">2.4.3.2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.3.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.3.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.3.1">2.4.3.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.3/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.3"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.3">2.4.3</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.2">2.4.2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.1">2.4.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.4.0/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.4.0"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.4.0">2.4.0</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.3.1/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.3.1"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.3.1">2.3.1</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.3.0/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.3.0"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.3.0">2.3.0</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/Itseez/opencv/tree/2.2/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
                 data-name="2.2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="2.2">2.2</a>
            </div> <!-- /.select-menu-item -->
        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="button-group right">
    <a href="/Itseez/opencv/find/master"
          class="js-show-file-finder minibutton empty-icon tooltipped tooltipped-s"
          data-pjax
          data-hotkey="t"
          aria-label="Quickly jump between files">
      <span class="octicon octicon-list-unordered"></span>
    </a>
    <button class="js-zeroclipboard minibutton zeroclipboard-button"
          data-clipboard-text="samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp"
          aria-label="Copy to clipboard"
          data-copied-hint="Copied!">
      <span class="octicon octicon-clippy"></span>
    </button>
  </div>

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Itseez/opencv" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">opencv</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Itseez/opencv/tree/master/samples" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">samples</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Itseez/opencv/tree/master/samples/cpp" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">cpp</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Itseez/opencv/tree/master/samples/cpp/tutorial_code" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">tutorial_code</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/Itseez/opencv/tree/master/samples/cpp/tutorial_code/ImgTrans" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">ImgTrans</span></a></span><span class="separator"> / </span><strong class="final-path">copyMakeBorder_demo.cpp</strong>
  </div>
</div>


  <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/Itseez/opencv/contributors/master/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp">
    Fetching contributors…

    <div class="participation">
      <p class="loader-loading"><img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif" width="16" /></p>
      <p class="loader-error">Cannot retrieve contributors at this time</p>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
        <span class="meta-divider"></span>
          <span>74 lines (57 sloc)</span>
          <span class="meta-divider"></span>
        <span>1.753 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
              <a class="minibutton disabled tooltipped tooltipped-w" href="#"
                 aria-label="You must be signed in to make or propose changes">Edit</a>
          <a href="/Itseez/opencv/raw/master/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp" class="minibutton " id="raw-url">Raw</a>
            <a href="/Itseez/opencv/blame/master/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp" class="minibutton js-update-url-with-hash">Blame</a>
          <a href="/Itseez/opencv/commits/master/samples/cpp/tutorial_code/ImgTrans/copyMakeBorder_demo.cpp" class="minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->
          <a class="minibutton danger disabled empty-icon tooltipped tooltipped-w" href="#"
             aria-label="You must be signed in to make or propose changes">
          Delete
        </a>
      </div><!-- /.actions -->
    </div>
      
  <div class="blob-wrapper data type-c js-blob-data">
       <table class="file-code file-diff tab-size-8">
         <tr class="file-code-line">
           <td class="blob-line-nums">
             <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>

           </td>
           <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="cm">/**</span></div><div class='line' id='LC2'><span class="cm"> * @file copyMakeBorder_demo.cpp</span></div><div class='line' id='LC3'><span class="cm"> * @brief Sample code that shows the functionality of copyMakeBorder</span></div><div class='line' id='LC4'><span class="cm"> * @author OpenCV team</span></div><div class='line' id='LC5'><span class="cm"> */</span></div><div class='line' id='LC6'><br/></div><div class='line' id='LC7'><span class="cp">#include &quot;opencv2/imgproc/imgproc.hpp&quot;</span></div><div class='line' id='LC8'><span class="cp">#include &quot;opencv2/highgui/highgui.hpp&quot;</span></div><div class='line' id='LC9'><span class="cp">#include &lt;stdlib.h&gt;</span></div><div class='line' id='LC10'><span class="cp">#include &lt;stdio.h&gt;</span></div><div class='line' id='LC11'><br/></div><div class='line' id='LC12'><span class="k">using</span> <span class="k">namespace</span> <span class="n">cv</span><span class="p">;</span></div><div class='line' id='LC13'><br/></div><div class='line' id='LC14'><span class="c1">/// Global Variables</span></div><div class='line' id='LC15'><span class="n">Mat</span> <span class="n">src</span><span class="p">,</span> <span class="n">dst</span><span class="p">;</span></div><div class='line' id='LC16'><span class="kt">int</span> <span class="n">top</span><span class="p">,</span> <span class="n">bottom</span><span class="p">,</span> <span class="n">left</span><span class="p">,</span> <span class="n">right</span><span class="p">;</span></div><div class='line' id='LC17'><span class="kt">int</span> <span class="n">borderType</span><span class="p">;</span></div><div class='line' id='LC18'><span class="k">const</span> <span class="kt">char</span><span class="o">*</span> <span class="n">window_name</span> <span class="o">=</span> <span class="s">&quot;copyMakeBorder Demo&quot;</span><span class="p">;</span></div><div class='line' id='LC19'><span class="n">RNG</span> <span class="nf">rng</span><span class="p">(</span><span class="mi">12345</span><span class="p">);</span></div><div class='line' id='LC20'><br/></div><div class='line' id='LC21'><span class="cm">/**</span></div><div class='line' id='LC22'><span class="cm"> * @function main</span></div><div class='line' id='LC23'><span class="cm"> */</span></div><div class='line' id='LC24'><span class="kt">int</span> <span class="nf">main</span><span class="p">(</span> <span class="kt">int</span><span class="p">,</span> <span class="kt">char</span><span class="o">**</span> <span class="n">argv</span> <span class="p">)</span></div><div class='line' id='LC25'><span class="p">{</span></div><div class='line' id='LC26'><br/></div><div class='line' id='LC27'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">c</span><span class="p">;</span></div><div class='line' id='LC28'><br/></div><div class='line' id='LC29'>&nbsp;&nbsp;<span class="c1">/// Load an image</span></div><div class='line' id='LC30'>&nbsp;&nbsp;<span class="n">src</span> <span class="o">=</span> <span class="n">imread</span><span class="p">(</span> <span class="n">argv</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="p">);</span></div><div class='line' id='LC31'><br/></div><div class='line' id='LC32'>&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span> <span class="o">!</span><span class="n">src</span><span class="p">.</span><span class="n">data</span> <span class="p">)</span></div><div class='line' id='LC33'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC34'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot; No data entered, please enter the path to an image file </span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC35'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="o">-</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC36'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC37'><br/></div><div class='line' id='LC38'>&nbsp;&nbsp;<span class="c1">/// Brief how-to for this program</span></div><div class='line' id='LC39'>&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span> <span class="s">&quot;</span><span class="se">\n</span><span class="s"> </span><span class="se">\t</span><span class="s"> copyMakeBorder Demo: </span><span class="se">\n</span><span class="s">&quot;</span> <span class="p">);</span></div><div class='line' id='LC40'>&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span> <span class="s">&quot;</span><span class="se">\t</span><span class="s"> -------------------- </span><span class="se">\n</span><span class="s">&quot;</span> <span class="p">);</span></div><div class='line' id='LC41'>&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span> <span class="s">&quot; ** Press &#39;c&#39; to set the border to a random constant value </span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC42'>&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span> <span class="s">&quot; ** Press &#39;r&#39; to set the border to be replicated </span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC43'>&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span> <span class="s">&quot; ** Press &#39;ESC&#39; to exit the program </span><span class="se">\n</span><span class="s">&quot;</span><span class="p">);</span></div><div class='line' id='LC44'><br/></div><div class='line' id='LC45'>&nbsp;&nbsp;<span class="c1">/// Create window</span></div><div class='line' id='LC46'>&nbsp;&nbsp;<span class="n">namedWindow</span><span class="p">(</span> <span class="n">window_name</span><span class="p">,</span> <span class="n">WINDOW_AUTOSIZE</span> <span class="p">);</span></div><div class='line' id='LC47'><br/></div><div class='line' id='LC48'>&nbsp;&nbsp;<span class="c1">/// Initialize arguments for the filter</span></div><div class='line' id='LC49'>&nbsp;&nbsp;<span class="n">top</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="p">(</span><span class="mf">0.05</span><span class="o">*</span><span class="n">src</span><span class="p">.</span><span class="n">rows</span><span class="p">);</span> <span class="n">bottom</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="p">(</span><span class="mf">0.05</span><span class="o">*</span><span class="n">src</span><span class="p">.</span><span class="n">rows</span><span class="p">);</span></div><div class='line' id='LC50'>&nbsp;&nbsp;<span class="n">left</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="p">(</span><span class="mf">0.05</span><span class="o">*</span><span class="n">src</span><span class="p">.</span><span class="n">cols</span><span class="p">);</span> <span class="n">right</span> <span class="o">=</span> <span class="p">(</span><span class="kt">int</span><span class="p">)</span> <span class="p">(</span><span class="mf">0.05</span><span class="o">*</span><span class="n">src</span><span class="p">.</span><span class="n">cols</span><span class="p">);</span></div><div class='line' id='LC51'>&nbsp;&nbsp;<span class="n">dst</span> <span class="o">=</span> <span class="n">src</span><span class="p">;</span></div><div class='line' id='LC52'><br/></div><div class='line' id='LC53'>&nbsp;&nbsp;<span class="n">imshow</span><span class="p">(</span> <span class="n">window_name</span><span class="p">,</span> <span class="n">dst</span> <span class="p">);</span></div><div class='line' id='LC54'><br/></div><div class='line' id='LC55'>&nbsp;&nbsp;<span class="k">for</span><span class="p">(;;)</span></div><div class='line' id='LC56'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC57'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">c</span> <span class="o">=</span> <span class="n">waitKey</span><span class="p">(</span><span class="mi">500</span><span class="p">);</span></div><div class='line' id='LC58'><br/></div><div class='line' id='LC59'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span> <span class="p">(</span><span class="kt">char</span><span class="p">)</span><span class="n">c</span> <span class="o">==</span> <span class="mi">27</span> <span class="p">)</span></div><div class='line' id='LC60'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span> <span class="k">break</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC61'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span> <span class="k">if</span><span class="p">(</span> <span class="p">(</span><span class="kt">char</span><span class="p">)</span><span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;c&#39;</span> <span class="p">)</span></div><div class='line' id='LC62'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span> <span class="n">borderType</span> <span class="o">=</span> <span class="n">BORDER_CONSTANT</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC63'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span> <span class="k">if</span><span class="p">(</span> <span class="p">(</span><span class="kt">char</span><span class="p">)</span><span class="n">c</span> <span class="o">==</span> <span class="sc">&#39;r&#39;</span> <span class="p">)</span></div><div class='line' id='LC64'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">{</span> <span class="n">borderType</span> <span class="o">=</span> <span class="n">BORDER_REPLICATE</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC65'><br/></div><div class='line' id='LC66'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">Scalar</span> <span class="n">value</span><span class="p">(</span> <span class="n">rng</span><span class="p">.</span><span class="n">uniform</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="mi">255</span><span class="p">),</span> <span class="n">rng</span><span class="p">.</span><span class="n">uniform</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="mi">255</span><span class="p">),</span> <span class="n">rng</span><span class="p">.</span><span class="n">uniform</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="mi">255</span><span class="p">)</span> <span class="p">);</span></div><div class='line' id='LC67'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">copyMakeBorder</span><span class="p">(</span> <span class="n">src</span><span class="p">,</span> <span class="n">dst</span><span class="p">,</span> <span class="n">top</span><span class="p">,</span> <span class="n">bottom</span><span class="p">,</span> <span class="n">left</span><span class="p">,</span> <span class="n">right</span><span class="p">,</span> <span class="n">borderType</span><span class="p">,</span> <span class="n">value</span> <span class="p">);</span></div><div class='line' id='LC68'><br/></div><div class='line' id='LC69'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">imshow</span><span class="p">(</span> <span class="n">window_name</span><span class="p">,</span> <span class="n">dst</span> <span class="p">);</span></div><div class='line' id='LC70'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC71'><br/></div><div class='line' id='LC72'>&nbsp;&nbsp;<span class="k">return</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC73'><span class="p">}</span></div></pre></div></td>
         </tr>
       </table>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.05437s from github-fe138-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-x close js-ajax-error-dismiss" aria-label="Dismiss error"></a>
      Something went wrong with that request. Please try again.
    </div>


      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-7e83b343734e1b60b9e3f241fabdf7ef833678e9.js" type="text/javascript"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github-0f06d0f46fe7bcfbf31f2380f23aec15ba21b8ec.js" type="text/javascript"></script>
      
      
        <script async src="https://www.google-analytics.com/analytics.js"></script>
  </body>
</html>

