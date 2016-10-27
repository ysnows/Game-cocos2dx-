//
//  FileHelper.cpp
//  Game
//
//  Created by 咸光金 on 2016/10/27.
//
//

#include <stdio.h>


//static float myRand_0_1()
//{
//	cc_timeval psv;
//	CCTime::gettimeofdayCocos2d( &psv, nullptr );    // 获取本地时间
//	//根据时间产生随机种子
//	unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000;
//	srand(tsrans);    //设定随机数种子
//	return CCRANDOM_0_1();
//}
//2013.4.11使用http://codingnow.cn/cocos2d-x/939.html的思路
//先判断apk文件外部的/data/data/ + package路径下是否存在要复制的文件
//Both Android and iOS useful?: //
static inline bool isFileExist(const char* pFileName)
{
    if( !pFileName ) return false;
    //filePath is :/data/data/ + package name
    //std::string filePath =FileUtils::getInstance()->getWriteablePath();
    std::string filePath =FileUtils::getInstance()->getWritablePath();
    filePath += pFileName;
    
    FILE *fp = fopen(filePath.c_str(),"r");
    if(fp)
    {
        fclose(fp);
        return true;
    }
    return false;
}
//把apk中assets目录下的文件拷贝到/data/data/${packagename}/下
static inline void copyData(const char* pFileName)
{
    std::string strPath;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS||CC_TARGET_PLATFORM==CC_PLATFORM_MAC)
    strPath = FileUtils::getInstance()->fullPathFromRelativeFile(pFileName,".");
#else
#if  (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    strPath = FileUtils::getInstance()->fullPathForFilename(pFileName);
#endif
#endif
    //unsigned long len = 0;
    ssize_t len;
    unsigned char *data = nullptr;
    
    data = FileUtils::getInstance()->getFileData(strPath.c_str(),"r",&len);
    std::string destPath =FileUtils::getInstance()->getWritablePath();
    destPath += pFileName;
    
    FILE *fp = fopen(destPath.c_str(),"w+");
    fwrite(data,sizeof(char),len,fp);
    fclose(fp);
    delete []data;
    data = nullptr;
}

