/*****************************************************************************************
 *  Copyright(c) 2016 Yang Zhizhuang (Software School of Dalian University of Technology)
 *  All rights reserved.
 *
 *  文件名称: loginfeedbackmessage.h
 *  简要描述:
 *
 *  创建日期: 2016-6-22
 *  作者: Yang Zhizhuang
 *  说明:
 *
 *  修改日期:
 *  作者:
 *  说明:
 ****************************************************************************************/
#ifndef LOGINFEEDBACKMESSAGE_H
#define LOGINFEEDBACKMESSAGE_H
#include "./base/message.h"

class loginFeedBackMessage : public Message
{
public:
    loginFeedBackMessage();
    loginFeedBackMessage(std::string username,std::string status);
    std::string getJsonString();
    bool loadfromJson(std::string textJson);
    std::string user;
    std::string stat;
};

#endif // LOGINFEEDBACKMESSAGE_H
