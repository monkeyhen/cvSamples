#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/nonfree.hpp>

#include <vector>
#include <string>
#include <iostream>

using namespace cv;
using namespace std;


class wellFeature
{
private:
	const char* inputfilename;
	Mat inputImg;
	vector<KeyPoint> features;

public:
	wellFeature(string inputName) {
		inputfilename = inputName.c_str();
	}
	Mat detectFeatures();

};

Mat wellFeature::detectFeatures()
{
	Mat img = imread(inputfilename);
	Ptr<FeatureDetector> mdetector = FeatureDetector::create("HARRIS");
	vector<KeyPoint> keypoints1;
	Ptr<DescriptorExtractor> mdescriptor = DescriptorExtractor::create("SIFT");
	Mat descriptor1;

	mdetector->detect(img, keypoints1);
	mdescriptor->compute(img, keypoints1, descriptor1);

	if (mdetector.empty())
		throw runtime_error("fail to creat a detector");

	Mat outImg;
	drawKeypoints(img, keypoints1, outImg, Scalar::all(-1));
	imshow("sky", outImg);
	waitKey(1000);

	return descriptor1;
}

int t_main()
{
	wellFeature t1("baboon.jpj");
	t1.detectFeatures();
	return 0;
}

int main()
{
	t_main();
	return 0;
}