#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");

	ofSetLineWidth(1);
	ofSetColor(ofColor(255, 0, 0));

	this->noise_value = ofRandom(10);
	
	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	ofRotateZ(90);

	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
	ofEnableLighting();
	this->light.enable();

	float x_span = ofGetWidth() / 6;
	float angle = 0;

	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += 25)
	{
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += 25) {

			float noise_x = ofNoise(x * 0.0025, y * 0.0025, 0, ofGetFrameNum() * 0.025);

			ofPushMatrix();
			ofTranslate(ofVec3f(x, y, 0));
			box.set(25 * noise_x);
			box.draw();
			box.enableColors();
			ofPopMatrix();}
	}

	//for (int r = 300; r > 100; r -= 13)
	//{
	//	this->icoSphere.setRadius(r);
	//	vector<ofMeshFace> triangles = icoSphere.getMesh().getUniqueFaces();

	//	ofColor c;
	//	c.setHsb(ofMap(r, 300, 100, 0, 255), 255, 255);
	//	ofSetColor(c);

	//	for (int i = 0; i < triangles.size(); i++) {
	//		ofVec3f avg = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;
	//		float n_x = ofNoise(tmp_noise_x, avg.x * 0.0025, avg.y * 0.0025, avg.z * 0.0025);
	//		float n_y = ofNoise(tmp_noise_y, avg.x * 0.0025, avg.y * 0.0025, avg.z * 0.0025);
	//		float n_z = ofNoise(tmp_noise_z, avg.x * 0.0025, avg.y * 0.0025, avg.z * 0.0025);

	//		ofPushMatrix();
	//		ofTranslate(avg);

	//		ofRotateX(360 * n_x);
	//		ofRotateY(360 * n_y);
	//		ofRotateZ(360 * n_z);
	//
	//		box.set(10, 10, 10);
	//		box.draw();
	//		box.enableColors();
	//		ofPopMatrix();
	//	}

	//	tmp_noise_x += 0.05;
	//	tmp_noise_y += 0.05;
	//	tmp_noise_z += 0.05;
	//}

	//this->noise_x += 0.025;
	//this->noise_y += 0.025;
	//this->noise_z += 0.025;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}