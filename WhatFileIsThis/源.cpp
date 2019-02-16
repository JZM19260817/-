#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum filetype {Bmp,Jpg,Gif,Png,Tiff,Cad,Psd,Rtf,Xml,Html,Doc或者Xls,Pdf,Zip,Rar,Wav};
int FileHeaderCheck(string &path)
{
	unsigned char BmpHeader[] = { 0x42,0x4d,0xf6,0xb8,0x59 }; //BMP头文件
	unsigned char JPGHeader[] = { 0xff,0xd8,0xff,0xe1 };   //JPG,JPEG头文件
	unsigned char GIFHeader[] = { 0x47,0x49,0x46,0x38 }; //GIF头文件
	unsigned char PNGHeader[] = { 0x89,0x50,0x4e,0x47 };//PNG
	unsigned char TIFFHeader[] = { 0x49,0x49,0x2a,0x00 };//TIFF
	unsigned char CADHeader[] = { 0x41,0x43,0x31,0x30 };
	unsigned char PSDHeader[] = { 0x38,0x42,0x50,0x53 };
	unsigned char RTFHeader[] = { 0x7b,0x5c,0x72,0x74,0x66 };
	unsigned char XMLHeader[] = { 0x3c,0x3f,0x78,0x6d,0x6c };
	unsigned char HTMLHeader[] = { 0x68,0x74,0x6d,0x6d,0x3e };
	unsigned char DocXlsHeader[] = { 0xd0,0xcf,0x11,0xe0 };
	unsigned char PDFHeader[] = { 0x25,0x50,0x44,0x46,0x2d,0x31,0x2e };
	unsigned char ZIPHeader[] = { 0x50,0x4b,0x03,0x04 };
	unsigned char RARHeader[] = { 0x52,0x61,0x72,0x21 };
	unsigned char WAVHeader[] = { 0x57,0x41,0x56,0x45 };
	unsigned char *idata[] = { BmpHeader,JPGHeader,GIFHeader,PNGHeader,TIFFHeader,CADHeader,
		PSDHeader,RTFHeader,XMLHeader,HTMLHeader,DocXlsHeader,PDFHeader,ZIPHeader,RARHeader,
		WAVHeader };
	ifstream readf(path.c_str(), ios::binary);
	int count = 4;
	unsigned char ch[4];
	if (!readf.is_open())
		return 255;
	for (int i = 0; i < count; i++)
		readf >> ch[i];
	//开始检测文件类型
	int j = 0;
	if (memcmp(ch, idata[0], 2) == 0)
	{
		return 0;
	}
	j++;

	while (idata[j])
	{
		if (memcmp(ch, idata[j], count) == 0)
		{
			return j;
		}
		j++;
		if (j >= 3)
			return 255;
	}
	//cout <<"文件头:"<< ch << endl;
	//不属于任何类型时返回255
	return 255;
}

int main()
{
	string str;
	string kind;
	cin >> str;
	switch (FileHeaderCheck(str))
	{
		case Bmp:
		{
			kind="Bmp";
			break;
		}
		case Jpg:
		{
			kind="jpg";
			break;
		}
		case Gif:
		{
			kind = "gif";
			break;
		}
		case Png:
		{
			kind = "png";
			break;
		}
		case Tiff:
		{
			kind = "Tiff";
			break;
		}
		case Cad:
		{
			kind = "Cad";
			break;
		}
		case Psd:
		{
			kind = "psd";
			break;
		}
		case Rtf:
		{
			kind = "rtf";
			break;
		}
		case Xml:
		{
			kind = "xml";
			break;
		}
		case Html:
		{
			kind = "html";
			break;
		}
		case Doc或者Xls:
		{
			kind = "Doc或者xls";
			break;
		}
		case Pdf:
		{
			kind = "pdf";
			break;
		}
		case Zip:
		{
			kind = "zip";
			break;
		}
		case Rar:
		{
			kind = "rar";
			break;
		}
		case Wav:
		{
			kind = "wav";
			break;
		}
		default:break;
	}
	if (kind != "NULL")
		cout << "这是一个"<<kind<<"文件" << endl;
	else cout << "没检查出来，用WinHex吧" << endl;
		system("pause");
	return 0;
}