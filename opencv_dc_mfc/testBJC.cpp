#include "stdafx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include<vector>
#include <fstream>//fstream�����������࣬����ʵ��c++���ļ��Ĳ���
#include <iomanip>

using namespace std;
using namespace cv;

int testBJC()
{
	Mat background;
	Mat temp;
	Mat result;

	int FrameCount = 0;
	VideoCapture capture("2.mp4");

	if (!capture.isOpened())
	{
		cout << "��ȡ��Ƶ����" << endl;
		return -1;
	}
	else
	{
		long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);//��ȡ��Ƶ����֡��
		capture.read(background);
		resize(background, background, Size(300, 200));//resizeΪ300*200��ͼ��ԭ����720*480
		cvtColor(background, background, CV_RGB2GRAY);//תΪ�Ҷ�ͼ

		ofstream File;//ofstream��ʵ�����ļ�д����
		File.open("test.xls", ios::_Noreplace | fstream::trunc);//ios::_Noreplace ��һ���ļ�ʱ������ļ������ڣ��������ļ�
		vector<int>ivec(totalFrameNumber);//�ɱ�����ivec����СΪ��֡

		VideoWriter writer("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, Size(640, 480));

		while (capture.read(temp))
		{

			int PixelCount = 0;

			FrameCount++;
			resize(temp, temp, Size(300, 200));//resizeΪ300*200��ͼ��ԭ����720*480
			cvtColor(temp, temp, CV_RGB2GRAY);//תΪ�Ҷ�ͼ
			absdiff(background, temp, result);//�ͱ�������,���result
			addWeighted(background, 0.98, temp, 1 - 0.98, 0, background);

			//����ͼ�񣬶�ֵ������ֵΪ50
			for (int i = 0; i < result.rows; i++) {
				for (int j = 0; j < result.cols; j++) {
					if (result.at<uchar>(i, j) < 50) {
						result.at<uchar>(i, j) = 0;
					}
					else {
						PixelCount++;
						result.at<uchar>(i, j) = 255;
					}
				}
			}
			File << PixelCount << endl;	//д��excel
		}
		
		File.close();//�ͷ�
	}
	return 0;
}