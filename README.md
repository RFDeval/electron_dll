# electron_dll
How to call local .dll files in Electron App


# 1、制作调用本地dll的node addon

   1 binding.gyp 中添加 
   "libraries": ["../mt_32.lib"]
   
   2 cpp中include头文件
   
    #include "windows.h"
   
    #include "mt_32.h"
    
   3 node-gyp configure  build
   
   最后会生成 ./build/Release/mt3_addon.node

# 2、node下测试调用addon

    先连接读卡设备，然后测试连接读卡设备。
    
    node test.js

# 3、重新编译成electron能调用的addon

    由于electron和node采用了不同的v8引擎，所以需要重新build
    
    node-gyp rebuild --target=1.7.11 --arch=ia32 --dist-url=https://atom.io/download/electron

# 4、制作成node_module
    
     制作packeage.js文件和导出文件。

# 5、electron APP里测试。

     将整个文件夹copy到electron工程的node_modules下，同时需要将dll文件cpoy到 工程目录下。
     
     然后在electron里通过 require('mt3_addon');引用模块。
