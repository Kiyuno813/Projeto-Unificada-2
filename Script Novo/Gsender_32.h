#ifndef G_SENDER
#define G_SENDER
#define GS_SERIAL_LOG_1         // Print to Serial only server responce
//#define GS_SERIAL_LOG_2       //  Print to Serial client commands and server responce
#include <WiFiClientSecure.h>

class Gsender
{
   protected:
       Gsender();
   private:
       const int SMTP_PORT = 465;
       const char* SMTP_SERVER = "smtp.gmail.com";
       const char* EMAILBASE64_LOGIN = "ZXNwODI2NnRlc3RlQGdtYWlsLmNvbQ==";
       const char* EMAILBASE64_PASSWORD = "MTIzNDU2Nzg5ZXNw";
       const char* FROM = "xxxxxx@mail.com";
       const char* _error = nullptr;
       char* _subject = nullptr;
       String _serverResponce;
       static Gsender* _instance;
       bool AwaitSMTPResponse(WiFiClientSecure &client, const String &resp = "", uint16_t timeOut = 60000);

   public:
       static Gsender* Instance();
       Gsender* Subject(const char* subject);
       Gsender* Subject(const String &subject);
       bool Send(const String &to, const String &message);
	   bool Send(int num, const String to[], const String &message);	   
       String getLastResponce();
       const char* getError();
};
#endif // G_SENDER
