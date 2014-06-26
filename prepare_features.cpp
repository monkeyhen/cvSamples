#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <vector>
#include <string>

using namespace cv;
using namespace std;


class wellFeature
{
private:
	string inputfilename;
	Mat inputImg;
	vector<KeyPoint> features;

public:
	int detectFeatures(const string& filename);

};

int wellFeature::detectFeatures(const string&  filename)
{
	Mat img = imread(filename);
	Ptr<FeatureDetector> mdetector = FeatureDetector::create("HARRIS");
	vector<KeyPoint> keypoints1;
	Ptr<DescriptorExtractor> mdescriptor = DescriptorExtractor::create('')

	if (mdetector.empty())
		throw runtime_error("fail to creat a detector");

	mdetector->detect(img, keypoints1);
	

	
	

}