//
// Created by Administrator on 2020/3/25.
//

#ifndef ALGODEMO_LOOP_D_H
#define ALGODEMO_LOOP_D_H

#ifndef WIN32

#include <string>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
namespace oyas{
    namespace loop{
        using namespace std;
        void init_deamon(string str="/tmp"){
            pid_t pid=fork();
            if(pid<0){
                exit(2);
            }else if(pid>0){
                exit(0);
            }
            auto ssid_r=setsid();
            if(ssid_r==-1){
                exit(2);
            }
            pid=fork();
            if(pid<0){
                exit(2);
            }else if(pid>0){
                exit(0);
            }
            chdir(str.c_str());
            int tablesz=getdtablesize();
            for(int i=0;i<tablesz;i++){
                close(i);
            }
            umask(0);
            return;
        }
        void write_log(string name="oyas.daemon.log",string path="/tmp"){
            string fpath=path+"/"+name;
            auto fp=open(fpath.c_str(),O_CREAT|O_RDWR|O_APPEND,0600);
            if(fp>0){
                string stmp="hello\n";
                //stmp+=asctime(localtime(&tm));//old fun;
                write(fp,stmp.c_str(), sizeof(stmp.c_str()));
            }
            if(fp>0){
                close(fp);
            }
        }
    }
}

#endif
#endif //ALGODEMO_LOOP_D_H
