# JetFighter Simulator using OpenGL

This is a game similar to to emulate a jet fighter plane game. The standard game consists of the following:
  - Multiple views
  - Total of 28 Checkpoints in Game
  - Try to reach the maximum score by covering maximum distance and by passing through circular ring, by shooting enemies, shooting parachutes.

# New Features!

  - To Know All the Features go through the Assignment2.pdf 

# Installation

Jet Fighter Simulation requires C++ and OpenGl to run.
The following development packages of the following libraries should be installed:
 - GLEW
 - GLFW3
 - GLM
 - AO
 - libmpg123

Installation instructions
### For Fedora
```
$ sudo pkgconf-pkg-config dnf install glew-devel glfw-devel glm-devel cmake pkgconf 
```
### For Ubuntu
```
$ sudo apt install libglew-dev libglfw3-dev libglm-dev cmake pkg-config
```
(Use apt-get if you don’t have aptitude installed but I suggest installing it)
### For Mac
Install homebrew
```
brew install glew glfw glm cmake pkg-config
```
### For Other distros
Use the equivalent of apt search or dnf search and make sure you install the devel packages
### Driver Issues
If you do face driver issues, try to update your drivers. If you continue facing issues even after installing, I suggest you update your operating system to the latest stable release. You can also try building the libraries, but it would be a waste of time IMO.

# How to Run

To run, clone the directory, make sure all the required packages are installed, then type the following commands, inside the cloned directory.

```sh
$ cd build
$ ./graphics_asgn1
```
If you want to make some edits then make sure to run the following commands to compile the changes:
```
$ cd build
$ make all
$ ./graphics_asgn1
```

# Controls

For controls follow the pdf [help.pdf] present in the directory. To open run the command :
```
$ xdg-open help.pdf
```
License
-------
The MIT License https://parthgoyal.mit-license.org/

Copyright &copy; 2019 Parth Goyal <parth.goyal@research.iiit.ac.in>
