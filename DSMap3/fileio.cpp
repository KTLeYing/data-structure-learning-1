/******************************************************************************************
*FunctionName:ReadFile                                                                    *
*                                                                                         *
*Description:��ȡ�������ļ��������洢���ı��ĵ���                                       *
*                                                                                         *
*Date:                                                                                    *
*                                                                                         *
*Maker:������                                                                             *
******************************************************************************************/


#include<stdio.h>
#include<iostream>
#include<io.h>
#include<fstream>
#include<cstdlib>
#include<string.h>        //����string������

#include "header.h"          //����headerͷ�ļ�

using namespace std;

#define ERROR 0

int ReadFile(ElecMap *eMap)
{
    FILE *fp,*fileWrite;     //����ָ��FILE�ṹ��ָ�����*pf��fileWrite
    int roadNum=0;               //��ʼ����·����Ϊ0
    unsigned short recordSize;       //ʹ��ȫ�ֱ����Ľṹ�������������
    unsigned int LinkID;
    unsigned short roadNameLen;
    unsigned int roadInfo;              //��·��Ϣ
    char roadName[30];            //����洢��·����

    unsigned int disclass;
    unsigned int brunch;
    int flag;

    if((fp=fopen("d:\\GTBL.dat","rb"))==NULL)      //�ж�GTBL�ļ��Ƿ�Ϊ�գ���Ϊ�����ʧ��
    {
       cout<<"�ļ���ʧ��!\n";
       exit(0);
    }
    cout<<"�ļ��򿪳ɹ�!\n";                    //�ļ����ܿգ���ɹ����ļ�������ȡ�������ļ�

    fileWrite=fopen("d:\\Map3.txt","w");         //�ļ�ָ��fileWriteָ��Ҫ�洢��ȥ��Ŀ���ı��ļ�����д���ı��ļ���
    cout<<"�ļ���ȡ��......\n";
    while(1)
    {
        fread(&recordSize,sizeof(short int),1,fp);    //��ȡһ��short int��2���ֽڣ��ĵ�·��¼��С����ȡ��ַ
        if(feof(fp))                                  //�����ȡ���������ļ��Ľ�βʱ��������ȡ
            break;
        fread(&LinkID,sizeof(long),1,fp);          //��ȡһ��long��4���ֽڣ��ĵ�·LinkID����ȡ���ַ
        fread(&roadNameLen,sizeof(short int),1,fp);            //��ȡһ��short int��2���ֽڣ���·���ֵĳ��ȣ���ȡ���ַ
        fread(&roadInfo,sizeof(long),1,fp);                  //��ȡһ��long��4���ֽڣ���·��Ϣ����ȡ���ַ

        recordSize=M_CHG_INT16(recordSize);                    //���ú귴ת�����͵�16λ�����룬��ת��·��¼��С
        LinkID=M_CHG_INT32(LinkID);                          //���ú귴ת�����͵�32λ�����룬��תLinkID
        roadNameLen=M_CHG_INT16(roadNameLen);               //���ú귴ת�����͵�16λ�����룬��ת��·���ĳ���
        roadInfo=M_CHG_INT32(roadInfo);                     //���ú귴ת�����͵�32λ�����룬��ת��·��Ϣ

        flag=GET_FLAG(roadInfo);                      //��ȡ������޵�·���Ƶ�flag
        brunch=GET_BRUNCH(roadInfo);                  //��ȡ��·��֧����
        disclass=GET_DISPCLASS(roadInfo);               //��ȡ��·����

        if(recordSize>12)                        //�����¼��С����12��ǰ�����õ��ڴ棩���������ڴ���·��������ȡ��·��
        {
            fread(roadName,recordSize-12,1,fp);  //roadName��һ�����飬���ǵ�ַ����������ȡַ���š�&��
            strcpy(eMap->roadRecord[eMap->roadNum].roadName,roadName);     //�Ѷ������ı��ĵ�·���Ƹ��ƽṹ������ĵ�·�����½����ı���
        }
        eMap->roadRecord[eMap->roadNum].recordSize=recordSize;             //�ѻ�ȡ�ļ�¼��С��ֵ���ṹ������ļ�¼��С
        eMap->roadRecord[eMap->roadNum].LinkID=LinkID;          //�ѻ�ȡ��LinkID��ֵ���ṹ������LinkID
        eMap->roadRecord[eMap->roadNum].roadInfo=roadInfo;         //�ѻ�ȡ�ĵ�·��Ϣ��ֵ���ṹ������ĵ�·��Ϣ

        eMap->roadRecord[eMap->roadNum].brunch=brunch;
        eMap->roadRecord[eMap->roadNum].disclass=disclass;
        eMap->roadRecord[eMap->roadNum].flag=flag;


        fprintf(fileWrite,"%d\t��Ϣ��С:%d\tLinkID:%d\t����Flag:%d\t�ֲ�·��:%d\t����:%d\t",  //�ѻ�ȡ��һ����·�ĸ�����Ϣд��ȥ�ı��ĵ���
                eMap->roadNum+1,recordSize,LinkID,flag,brunch,disclass);
        if(recordSize>12)                         //�����¼��С����12�����пռ�洢��·���ƣ�
           fprintf(fileWrite,"��·����:%s\n",roadName);            //�ѻ�ȡ�ĵ�·��д���ļ�
        else
            fprintf(fileWrite,"�޵�·����\n");                  //�����¼��СС�ڴ���12�������ڴ�ռ�洢��·��
        eMap->roadNum++;                        //ѭ��һ�Σ�д��һ����·����·������1�����ṹ������������1��
    }
    cout<<"��ȡ��¼һ��Ϊ:"<<eMap->roadNum<<endl;     //�����·������

    fclose(fp);             //�ر��ļ�
    cout<<"�ļ���ȡ�ɹ�!\n";
    return 0;
}




