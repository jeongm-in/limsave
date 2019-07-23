# limsave

## What is this?

- Windows 10 by default displays beautiful images in the lock screen. 
- These images are saved under  `DRIVE:/Users/USERNAME/AppData/Local/Packages/Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy/LocalState/Assets`, and users can rename the files in this folder to back them up for later use. 
- This command line program will save and rename the image files for you with a single command line prompt. 
- * This program is a C++ version of my [Windows10-Spotlight-Crawler](https://github.com/jeongm/Windows10-Spotlight-Crawler) with added usability.

## Usage

1. Save to Default location
 - `$ limsave.exe`
 - This will by default save the images under `DRIVE:/Users/USERNAME/Desktop/limsave`
2. Save to Custom location
  - `$ limsave.exe P:/ath/To/Custom/Directory`
  - This will save images to provided Custom directory.
  - If invalid directory is given, program will not proceed.
  

## Build information
- This program is intended to run only on `Windows 10`.
- This program was built in `Windows 10 Pro Build 1809`,`Microsoft Visual Studio 2019`, using `ISO C++ 17 Standard`.


## Contributors
- Jeong Min Lim (@jeongm-in)
