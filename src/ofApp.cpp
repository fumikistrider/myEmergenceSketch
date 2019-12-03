#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();


	gui.setup(); // most of the time you don't need a name
	gui.add(sliderAlign.setup("Align", 25, 1, 100));
	gui.add(sliderSeparate.setup("Separate", 25, 1, 100));
	gui.add(sliderCohesion.setup("Cohesion", 25, 1, 100));
	gui.add(sliderDistAlign.setup("Dist Align", 25, 1, 100));
	gui.add(sliderDistSeparation.setup("Dist Separation", 25, 1, 100));
	gui.add(sliderDistCohesion.setup("Dist Cohesion", 25, 1, 100));
	gui.add(sliderSpeed.setup("Speed", 5, 0, 10));
	gui.add(sliderTurn.setup("Turn", 5, 0, 10));
	gui.add(sliderForce.setup("Force", 0.5, 0, 1));

	// make attrPts
	for (int i = 0; i<10; i++) {
		float x = ofRandom(ofGetWidth());
		float y = ofRandom(ofGetHeight());
		float force = ofRandom(-5, -1);
		float dist = 100;
		flock.addAttractionPoint(x, y, force, dist);
	}

	// num, center x, center y, dev
	flock.setup(250, ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() / 4);

	flock.setBounds(0, 0, ofGetWidth(), ofGetHeight());
	flock.setBoundmode(1);
}

//--------------------------------------------------------------
void ofApp::update(){
	flock.setAlign(sliderAlign);
	flock.setSeparate(sliderSeparate);
	flock.setCohesion(sliderCohesion);
	flock.setDistAlign(sliderDistAlign);
	flock.setDistSeparation(sliderDistSeparation);
	flock.setDistCohesion(sliderDistCohesion);
	flock.setMaxSpeed(sliderSpeed);
	flock.setMaxTurn(sliderTurn);
	flock.setMaxForce(sliderForce);

	flock.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	//view attrpoints
	ofColor attrColor(100, 255, 0);
	ofColor repelColor(255, 128, 0);

	for (int i = 0; i<flock.attractionPoints.size(); i++) {
		AttractionPoint2d * ap = flock.attractionPoints[i];
		ofSetColor(ap->force > 0 ? attrColor : repelColor, ofMap(ABS(ap->force), 0, 250, 10, 200));
		ofRect(ap->x - ap->sensorDist / 2, ap->y - ap->sensorDist / 2, ap->sensorDist, ap->sensorDist);
		ofRect(ap->x - 2, ap->y - 2, 5, 5);
	}


	ofSetColor(0);
	for (int i = 0; i<flock.size(); i++) {
		Boid2d * b = flock.get(i);

		ofDrawCircle(b->x, b->y, 5);
		//float lm = 10.f;
		//ofLine(b->x, b->y, b->x + b->vx*lm, b->y + b->vy*lm);
	}

	gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	if (button == 0) {
		flock.add(x, y);
	}
	flock.removeBoid(0);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) {
	}
	else {
		vector<AttractionPoint2d*>* attr = flock.getAttractionPoints();
		attr->erase(attr->begin());
		float force = ofRandom(-5, -1);
		float dist = 100;
		flock.addAttractionPoint(x, y, force, dist);
	}
	//flock.removeBoid(0);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
