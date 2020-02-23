

/*

参考文章链接  https://www.cnblogs.com/17bdw/p/6790197.html

编译环境 win10 vc6.0

需要管理员权限,win7测试可用
*/

#include "stdafx.h"
#ifndef UNICODE    
#define UNICODE    
#endif    
#include  <stdio.h>  
#include  <windows.h>  
#include  <lm.h>  
#pragma comment(lib,"netapi32")    
int Usage(wchar_t *);    
int wmain(int argc, wchar_t *argv[])    
{    


    // 定义USER_INFO_1结构体
    USER_INFO_1 ui;    
    DWORD dwError = 0;     
    ui.usri1_name = L"Mikasa";            // 账户    
    ui.usri1_password = L"password@123";      // 密码
    ui.usri1_priv = USER_PRIV_USER;    
    ui.usri1_home_dir = NULL;    
    ui.usri1_comment = NULL;    
    ui.usri1_flags = UF_SCRIPT;    
    ui.usri1_script_path = NULL;    
      
    if(NetUserAdd(NULL, 1, (LPBYTE)&ui, &dwError) == NERR_Success)    
    {    

        printf("Success!");
    
    }    
    else    
    {    
        //添加失败    
        printf("Fail");

    }    

    // 添加用户到administrators组
    LOCALGROUP_MEMBERS_INFO_3 account;    
    account.lgrmi3_domainandname=ui.usri1_name;      
    if( NetLocalGroupAddMembers(NULL,L"Administrators",3,(LPBYTE)&account,1) == NERR_Success )    
    {    
        //添加成功    
        printf("Success");
    }    
    else    
    {    
        //添加失败    
        printf("Fail");
    }    

    return 0;
}    



/*
参考文章链接  https://www.cnblogs.com/17bdw/p/6790197.html
*/