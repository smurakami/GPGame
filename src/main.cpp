#include "ofMain.h"
#include "testApp.h"
#include "MyRandom.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
  
//  int seed = time(NULL);
//  cout << "seed: " << seed << endl;
//  srand(seed);
  int seed = 1390555239;
  cout << "seed: " << seed << endl;
  srand(seed);
  
  
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
