#include <iostream>
#include <time.h>
#include <exception>
#include <string>
#include <vector>
#include <map>

//#include "libconfig.h++"
#include "MyLogger.h"
#include "TestClass.h"

/*
#include "itkImage.h"
#include "itkImageSeriesReader.h"
#include "itkNiftiImageIO.h"
#include "itkCastImageFilter.h"
#include "itkImageFileWriter.h"
#include "itkBinaryImageToLabelMapFilter.h"

#include "AirwaySegmentation.h"

using namespace ALPHA::PUMO;

*/
//
// void loadCfg(std::string strConfPath, libconfig::Config & mConfig)
// {
// 	try {
// 		mConfig.readFile(strConfPath.c_str());
// 	} catch(libconfig::FileIOException &e) {
// 		std::cout << "read file [ " << strConfPath << " ] FileIOException" << std::endl;
// 	} catch(libconfig::ParseException &e) {
// 		std::cout << "read file [ " << strConfPath << " ],ParaseException: " << e.getError() << ",line:" << e.getLine() << std::endl;
// 	} catch(...) {
// 		std::cout << "read file [" << strConfPath << " ] unknown exception" << std::endl;
// 	}
// }


int main()
{
	//time_t timestamp1 = time(NULL);

	//MyLogger * myLoger = nullptr;
	MyLogger::getInstance();
	MyLogger::getInstance();
	MyLogger::getInstance();
	MyLogger * myLoger = MyLogger::getInstance();
	MyLogger * myLoger2 = MyLogger::getInstance();
	Test();

// 	std::string strConfPath = "./pulmonary_nodule_config.cfg";
// 	libconfig::Config mConfig;
// 	loadCfg(strConfPath, mConfig);
//
// 	//int
// 	try {
// 		float num = mConfig.lookup("POSTPROCESS.AIRWAY_MODEL_THRESHOLD");
// 		//std::cout << "POSTPROCESS.AIRWAY_MODEL_THRESHOLD:" << num << std::endl;
// 		LOG4CPLUS_DEBUG(myLoger->m_rootLog, "POSTPROCESS.AIRWAY_MODEL_THRESHOLD:" << num);
// 	} catch(...) {
// 		LOG4CPLUS_WARN(myLoger->m_rootLog, "Get Number from " << strConfPath << " failed ...");
// 	}
// 	//string
// 	try {
// 		std::string str = mConfig.lookup("POSTPROCESS.AIRWAY_MODEL");
// 		//or
// 		//mConfig.lookupValue("STRING", str);
// 		LOG4CPLUS_DEBUG(myLoger2->m_rootLog, "POSTPROCESS.AIRWAY_MODEL:" << str);
// 	} catch(...) {
// 		LOG4CPLUS_FATAL(myLoger->m_rootLog, "Get String from " << strConfPath << " failed ...");
// 	}
//
//
// 	//Array
// 	const libconfig::Setting &root = mConfig.getRoot();
// 	const libconfig::Setting &arr = root["POSTPROCESS"]["AIRWAY_INPUT_SHAPE"];
// 	int cnt = arr.getLength();
// 	std::cout << "POSTPROCESS.AIRWAY_INPUT_SHAPE.LENGTH:" << cnt << std::endl;
// 	//vector<string> vs;
// 	for(int i = 0; i < cnt; ++i) {
// 		int tmp = arr[i];
// 		//vs.push_back(tmp);
// 		LOG4CPLUS_DEBUG(myLoger->m_rootLog, "Array[" << i << "]:" << tmp);
// 	}


	/*
	//save csv
	PumoBaseData pumoResults;
	for (int i = 0; i < 10; i++)
	{
		NoduleInfo tempData;
		if (i > 5)
		{
			tempData = pumoResults.NodulePrepOutput[i - 1];
		}
		if (i == 5)
		{
			tempData.coordX = 23.22;
			tempData.coordY = 34.33;
			tempData.coordZ = 45.44;
			tempData.uid = "test_xp";
		}
		tempData.lungSegmentIndex = i;
		pumoResults.NodulePrepOutput.push_back(tempData);
	}
	std::string savepath = "temp_results.csv";
	LOG4CPLUS_DEBUG(myLoger->m_rootLog, "temp_results savepath:" << savepath);
	pumoResults.NoduleInfoList2Csv(pumoResults.NodulePrepOutput, savepath);
	*/

	/*
	//load csv
	std::string loadpath = "temp_results.csv";
	std::string savepath_2 = "temp_results_2.csv";
	PumoBaseData pumoResults;
	pumoResults.m_seriesUID = "test_xp";
	LOG4CPLUS_DEBUG(myLoger->m_rootLog, "temp_results loadpath:" << loadpath);
	pumoResults.Csv2NoduleInfoList(pumoResults.NodulePrepOutput, loadpath);
	pumoResults.NoduleInfoList2Csv(pumoResults.NodulePrepOutput, savepath_2);
	*/

	/*
	std::string itkLungMaskPath("/home/alpha_cpp/PythonTest/LungLeaf/test_data/1.3.12.2.1107.5.1.4.73757.30000017051300372645500010243lung.nii");
	std::string itkPredictionPath("/home/alpha_cpp/PythonTest/LungLeaf/test_data/1.3.12.2.1107.5.1.4.73757.30000017051300372645500010243Predition3DResUnet.nii");

	std::cout << "input mask path: " << itkLungMaskPath << std::endl;
	std::cout << "input prediction path: " << itkPredictionPath << std::endl;

	ImageType::Pointer itkLungMask = ImageType::New();
	ImageType::Pointer itkPrediction = ImageType::New();

	loadNii(itkLungMaskPath, itkLungMask.GetPointer());
	loadNii(itkPredictionPath, itkPrediction.GetPointer());

	time_t timestamp2 = time(NULL);
	std::cout << "----------- intial time: " << difftime(timestamp2, timestamp1) << std::endl;

	AirwaySegmentation lungleafpost;
	lungleafpost.itkInitial(itkLungMask, itkPrediction);
	lungleafpost.itkFissureSegBinMake();

	time_t timestamp3 = time(NULL);
	std::cout << "----------- step3 time: " << difftime(timestamp3, timestamp2) << std::endl;

	//lungleafpost.itkFissureSegBinSet();
	lungleafpost.leftFissurePixelMake();           // get the left fissure
	lungleafpost.rightFissurePixelMake();          // get the right fissure
	lungleafpost.rightFeetFissurePixelMake();      // get the right feet fissure
	lungleafpost.Update();                         // update

	time_t timestamp4 = time(NULL);
	std::cout << "----------- step4 time: " << difftime(timestamp4, timestamp3) << std::endl;

	//lungleafpost.testUse();

	//std::string outputFilenameFissureSegBin("./lung_leaf_post/itkFissureSegBin.nii.gz");
	//saveNii(outputFilenameFissureSegBin, lungleafpost.itkFissureSegBinGet().GetPointer());

	//PixelListTpye rightFeetFissurePixel = lungleafpost.rightFeetFissurePixelGet();
	//std::cout << "PixelListRightFeet size: " << rightFeetFissurePixel.size() << std::endl;
	//std::cout << "PixelListRightFeet list: " << rightFeetFissurePixel[1100].x << "," << rightFeetFissurePixel[1100].y << "," << rightFeetFissurePixel[1100].z << std::endl;

	//std::cout << "################### results show ####################"<< std::endl;

	std::cout << "LeftFissureCoeff: ";
	for (int i = 0; i < lungleafpost.LeftFissureCoeffGet().size(); i++)
		std::cout << lungleafpost.LeftFissureCoeffGet()[i] << ", ";
	std::cout << std::endl;
	std::string savepathLeft("/home/alpha_cpp/Output_linux/data/lung_leaf_post/itkLeftfissureImage.nii.gz");
	//saveNii(savepathLeft, (CharImageType*)lungleafpost.itkLeftfissureImageGet());

	std::cout << "coeffHyperRightFeet: ";
	for (int i = 0; i < lungleafpost.coeffHyperRightFeetGet().size(); i++)
		std::cout << lungleafpost.coeffHyperRightFeetGet()[i] << ", ";
	std::cout << std::endl;
	std::string savepathRightFeet("/home/alpha_cpp/Output_linux/data/lung_leaf_post/itkRightFeetFissure.nii.gz");
	//saveNii(savepathRightFeet, lungleafpost.itkRightFeetFissureGet().GetPointer());

	std::cout << "coeffHyperRightHead: ";
	for (int i = 0; i < lungleafpost.coeffHyperRightHeadGet().size(); i++)
		std::cout << lungleafpost.coeffHyperRightHeadGet()[i] << ", ";
	std::cout << std::endl;
	std::string savepathRightHead("/home/alpha_cpp/Output_linux/data/lung_leaf_post/itkRightHeadFissure.nii.gz");
	//saveNii(savepathRightHead, lungleafpost.itkRightHeadFissureGet().GetPointer());

	time_t timestamp5 = time(NULL);
	std::cout << "----------- save time: " << difftime(timestamp5, timestamp4) << std::endl;
	*/


// 	char flag;
// 	std::cout << "press 'y' to quit.." << std::endl;
// 	std::cin >> flag;
}
