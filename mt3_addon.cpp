
#include "windows.h"
#include "mt_32.h"
#include <node.h>
using namespace v8;

// 连接设备
void Connect(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
    
  HANDLE icdev;
  icdev = NULL;
  __int16 com;
  if(icdev!=NULL)
  {
    close_device(icdev);
  }
  com=1;
  icdev = open_device((unsigned char)com, (unsigned long)115200);
  
  int value=0;
  if ((long)icdev <= 0)
  {
  }
  else
  {
  	dev_beep(icdev, 2, 5, 2);	
	value=1;	
  }
  Local<Number> num = Number::New(isolate, value);
  args.GetReturnValue().Set(value);
}


void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "connect", Connect);  
}


NODE_MODULE(RFID, Init)