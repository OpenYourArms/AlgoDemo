//
// Created by Administrator on 2020/3/26.
//

#ifndef ALGODEMO_MISC_H
#define ALGODEMO_MISC_H

#ifndef WIN32

#include <string>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
namespace oyas{
    string get_time_str()
    {
        time_t rawtime;
        struct tm timeinfo;
        char buffer [128] = {0};
        time (&rawtime);
        localtime_r(&rawtime,&timeinfo);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
        return string(buffer);
    }
    void wt_log(string path,string text){
        auto fp=open(path.c_str(),O_CREAT|O_RDWR|O_APPEND,0600);
        string tmp=get_time_str();
        tmp+="\t\t";
        tmp+=text;
        tmp+="\n";
        if(fp>0){
            write(fp,tmp.c_str(), sizeof(tmp.c_str()));
        }
        if(fp>0){
            close(fp);
        }
    }


}

#endif

#endif //ALGODEMO_MISC_H
