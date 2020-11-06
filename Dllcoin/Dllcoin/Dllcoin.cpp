// Dllcoin.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include"stdafx.h"
#include "cv.h"   
#include "cxcore.h"   
#include "highgui.h"
#include<string>
using namespace std;

//��Ƭ����
extern "C" __declspec(dllexport)int show_pian( char *filename1,int val,int pian_val)   
{   
    //����IplImageָ��   
    IplImage* img = NULL;   
    IplImage* cannyImg = NULL; 
    img=cvLoadImage(filename1,0);   
    //����ͼ��ǿ��ת��ΪGray    
		
    //Ϊcanny��Եͼ������ռ�   
    cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);   
    //canny��Ե���   
    cvCanny(img, cannyImg, val, val*3, 3);     
	int r,g,b;
	int i,j;
	int gray[256];//ͳ�ƻҶ�ֵ
	for(i=0;i<256;i++)
	{
		gray[i]=0;
	}
	//������ɨ��
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=0;j<(cannyImg->height)-10;j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}
	//���ҵ���ɨ��
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=(cannyImg->height)-10;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}
	//���ϵ���ɨ��
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=0;j<(cannyImg->width);j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	//���µ���ɨ��
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=cannyImg->width-1;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}

	//ͳ�ƻҶ�ֱ��ͼ
	for(i=0;i<(img->height)-10;i++)
	{
		for(j=0;j<(img->width);j++)
		{
			r=CV_IMAGE_ELEM(img,uchar,i,3*j);
			g=CV_IMAGE_ELEM(img,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(img,uchar,i,3*j+2);
			if(r!=255&&g!=255&&b!=255)
			{
				gray[r]++;
			}
		}
	}
	int ans[30];
	for(int i=0;i<30;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<250;i++)
	{
		ans[i/10]+=gray[i];
	}
	int maxx=0;
	int max_flag=0;
	for(int i=0;i<25;i++)
	{
		if(ans[i]>maxx)
		{
			maxx=ans[i];
			max_flag=i;
		}
	}  
    //�ͷ�ͼ��   
    cvReleaseImage( &img );   
    cvReleaseImage( &cannyImg );   
	if(max_flag>=pian_val)return 1;
	else return 0;
} 


//Բ������
extern "C" __declspec(dllexport)int show_huan( char *filename1,int val,int huan_val)   
{   
    //����IplImageָ��   
    IplImage* img = NULL;   
    IplImage* cannyImg = NULL; 
	//����ͼ��ǿ��ת��ΪGray 
    img=cvLoadImage(filename1,0);   
    //Ϊcanny��Եͼ������ռ�   
    cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);   
    //canny��Ե���   
    cvCanny(img, cannyImg, val, 3*val, 3);   
	int r,g,b;
	int i,j;
	int gray[256];
	for(i=0;i<256;i++)
	{
		gray[i]=0;
	}
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=0;j<(cannyImg->height)-10;j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}

	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=(cannyImg->height)-10;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}

	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=0;j<(cannyImg->width);j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=cannyImg->width-1;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	for(i=0;i<(img->height)-10;i++)
	{
		for(j=0;j<(img->width);j++)
		{
			r=CV_IMAGE_ELEM(img,uchar,i,3*j);
			g=CV_IMAGE_ELEM(img,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(img,uchar,i,3*j+2);
			if(r!=255&&g!=255&&b!=255)
			{
				gray[r]++;
			}
		}
	}
	int ans[30];
	for(int i=0;i<30;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<250;i++)
	{
		ans[i/10]+=gray[i];
	}
	int maxx=0;
	int max_flag=0;
	for(int i=0;i<20;i++)
	{
		if(ans[i]>maxx)
		{
			maxx=ans[i];
			max_flag=i;
		}
	}
    //�ͷ�ͼ��   
    cvReleaseImage( &img );   
    cvReleaseImage( &cannyImg );   
	if(max_flag>=huan_val)return 0;
	else return 1;
} 


char wndname[] = "Edge";
char tbarname[] = "Threshold";
int edge_thresh = 1;

IplImage *image = 0, *cedge = 0, *gray = 0, *edge = 0;

void on_trackbar(int h)
{
    cvSmooth( gray, edge, CV_BLUR, 3, 3, 0, 0 );
    cvNot( gray, edge );

    // Run the edge detector on grayscale
    cvCanny(gray, edge, (float)edge_thresh, (float)edge_thresh*3, 3);

    cvZero( cedge );
    // copy edge points
    cvCopy( image, cedge, edge );

    cvShowImage(wndname, cedge);
}


extern "C" __declspec(dllexport)void adjustment_val(char *filename1)
{
   // char* filename = argc == 2 ? argv[1] : (char*)"fruits.jpg";

    image = cvLoadImage( filename1, 1);

    // Create the output image
    cedge = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, 3);

    // Convert to grayscale
    gray = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, 1);
    edge = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, 1);
    cvCvtColor(image, gray, CV_BGR2GRAY);

    // Create a window
    cvNamedWindow(wndname, 0);

    // create a toolbar 
    cvCreateTrackbar(tbarname, wndname, &edge_thresh, 100, on_trackbar);

    // Show the image
    on_trackbar(0);

    // Wait for a key stroke; the same function arranges events processing
    cvWaitKey(0);
    cvReleaseImage(&image);
    cvReleaseImage(&gray);
    cvReleaseImage(&edge);
    cvDestroyWindow(wndname);

}













extern "C" __declspec(dllexport)int Getval_huan_zheng(char *filename1,int val)
{
	//����IplImageָ��   
    IplImage* img = NULL;   
    IplImage* cannyImg = NULL; 
	//����ͼ��ǿ��ת��ΪGray 
    img=cvLoadImage(filename1,0);   
    //Ϊcanny��Եͼ������ռ�   
    cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);   
    //canny��Ե���   
    cvCanny(img, cannyImg, val, 3*val, 3);   
	int r,g,b;
	int i,j;
	int gray[256];
	for(i=0;i<256;i++)
	{
		gray[i]=0;
	}
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=0;j<(cannyImg->height)-10;j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}

	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=(cannyImg->height)-10;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}

	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=0;j<(cannyImg->width);j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=cannyImg->width-1;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	for(i=0;i<(img->height)-10;i++)
	{
		for(j=0;j<(img->width);j++)
		{
			r=CV_IMAGE_ELEM(img,uchar,i,3*j);
			g=CV_IMAGE_ELEM(img,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(img,uchar,i,3*j+2);
			if(r!=255&&g!=255&&b!=255)
			{
				gray[r]++;
			}
		}
	}
	int ans[30];
	for(int i=0;i<30;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<250;i++)
	{
		ans[i/10]+=gray[i];
	}
	int maxx=0;
	int max_flag=0;
	for(int i=0;i<20;i++)
	{
		if(ans[i]>maxx)
		{
			maxx=ans[i];
			max_flag=i;
		}
	}
    //�ͷ�ͼ��   
    cvReleaseImage( &img );   
    cvReleaseImage( &cannyImg );   
	return max_flag;
}
extern "C" __declspec(dllexport)int Getval_huan_fan(char *filename1,int val)
{
	//����IplImageָ��   
    IplImage* img = NULL;   
    IplImage* cannyImg = NULL; 
	//����ͼ��ǿ��ת��ΪGray 
    img=cvLoadImage(filename1,0);   
    //Ϊcanny��Եͼ������ռ�   
    cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);   
    //canny��Ե���   
    cvCanny(img, cannyImg, val, 3*val, 3);   
	int r,g,b;
	int i,j;
	int gray[256];
	for(i=0;i<256;i++)
	{
		gray[i]=0;
	}
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=0;j<(cannyImg->height)-10;j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}

	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=(cannyImg->height)-10;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}

	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=0;j<(cannyImg->width);j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=cannyImg->width-1;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	for(i=0;i<(img->height)-10;i++)
	{
		for(j=0;j<(img->width);j++)
		{
			r=CV_IMAGE_ELEM(img,uchar,i,3*j);
			g=CV_IMAGE_ELEM(img,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(img,uchar,i,3*j+2);
			if(r!=255&&g!=255&&b!=255)
			{
				gray[r]++;
			}
		}
	}
	int ans[30];
	for(int i=0;i<30;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<250;i++)
	{
		ans[i/10]+=gray[i];
	}
	int maxx=0;
	int max_flag=0;
	for(int i=0;i<20;i++)
	{
		if(ans[i]>maxx)
		{
			maxx=ans[i];
			max_flag=i;
		}
	}
    //�ͷ�ͼ��   
    cvReleaseImage( &img );   
    cvReleaseImage( &cannyImg );   
	return max_flag;
}
extern "C" __declspec(dllexport)int Getval_pian_zheng(char *filename1,int val)
{
	//����IplImageָ��   
    IplImage* img = NULL;   
    IplImage* cannyImg = NULL; 
    img=cvLoadImage(filename1,0);   
    //����ͼ��ǿ��ת��ΪGray    
		
    //Ϊcanny��Եͼ������ռ�   
    cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);   
    //canny��Ե���   
    cvCanny(img, cannyImg, val, val*3, 3);     
	int r,g,b;
	int i,j;
	int gray[256];//ͳ�ƻҶ�ֵ
	for(i=0;i<256;i++)
	{
		gray[i]=0;
	}
	//������ɨ��
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=0;j<(cannyImg->height)-10;j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}
	//���ҵ���ɨ��
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=(cannyImg->height)-10;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}
	//���ϵ���ɨ��
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=0;j<(cannyImg->width);j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	//���µ���ɨ��
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=cannyImg->width-1;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}

	//ͳ�ƻҶ�ֱ��ͼ
	for(i=0;i<(img->height)-10;i++)
	{
		for(j=0;j<(img->width);j++)
		{
			r=CV_IMAGE_ELEM(img,uchar,i,3*j);
			g=CV_IMAGE_ELEM(img,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(img,uchar,i,3*j+2);
			if(r!=255&&g!=255&&b!=255)
			{
				gray[r]++;
			}
		}
	}
	int ans[30];
	for(int i=0;i<30;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<250;i++)
	{
		ans[i/10]+=gray[i];
	}
	int maxx=0;
	int max_flag=0;
	for(int i=0;i<25;i++)
	{
		if(ans[i]>maxx)
		{
			maxx=ans[i];
			max_flag=i;
		}
	}  
    //�ͷ�ͼ��   
    cvReleaseImage( &img );   
    cvReleaseImage( &cannyImg );   
	return max_flag;
}

extern "C" __declspec(dllexport)int Getval_pian_fan(char *filename1,int val)
{
	//����IplImageָ��   
    IplImage* img = NULL;   
    IplImage* cannyImg = NULL; 
    img=cvLoadImage(filename1,0);   
    //����ͼ��ǿ��ת��ΪGray    
		
    //Ϊcanny��Եͼ������ռ�   
    cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);   
    //canny��Ե���   
    cvCanny(img, cannyImg, val, val*3, 3);     
	int r,g,b;
	int i,j;
	int gray[256];//ͳ�ƻҶ�ֵ
	for(i=0;i<256;i++)
	{
		gray[i]=0;
	}
	//������ɨ��
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=0;j<(cannyImg->height)-10;j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}
	//���ҵ���ɨ��
	for(i=0;i<(cannyImg->width);i++)
	{
		for(j=(cannyImg->height)-10;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i);
			g=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,j,3*i+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,j,3*i)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+1)=255;
				CV_IMAGE_ELEM(img,uchar,j,3*i+2)=255;
			}
			else break;
		}
	}
	//���ϵ���ɨ��
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=0;j<(cannyImg->width);j++)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}
	//���µ���ɨ��
	for(i=0;i<(cannyImg->height)-10;i++)
	{
		for(j=cannyImg->width-1;j>0;j--)
		{
			r=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j);
			g=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(cannyImg,uchar,i,3*j+2);
			if(r<255&&g<255&&b<255)
			{
				CV_IMAGE_ELEM(img,uchar,i,3*j)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+1)=255;
				CV_IMAGE_ELEM(img,uchar,i,3*j+2)=255;
			}
			else break;
		}
	}

	//ͳ�ƻҶ�ֱ��ͼ
	for(i=0;i<(img->height)-10;i++)
	{
		for(j=0;j<(img->width);j++)
		{
			r=CV_IMAGE_ELEM(img,uchar,i,3*j);
			g=CV_IMAGE_ELEM(img,uchar,i,3*j+1);
			b=CV_IMAGE_ELEM(img,uchar,i,3*j+2);
			if(r!=255&&g!=255&&b!=255)
			{
				gray[r]++;
			}
		}
	}
	int ans[30];
	for(int i=0;i<30;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<250;i++)
	{
		ans[i/10]+=gray[i];
	}
	int maxx=0;
	int max_flag=0;
	for(int i=0;i<25;i++)
	{
		if(ans[i]>maxx)
		{
			maxx=ans[i];
			max_flag=i;
		}
	}  
    //�ͷ�ͼ��   
    cvReleaseImage( &img );   
    cvReleaseImage( &cannyImg );   
	return max_flag;
}