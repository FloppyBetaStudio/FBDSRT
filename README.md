# FBDSRT
Floppy BDS Runtime: A "cross-language runtime framework" for Minecraft BDS

## 原理

这是一个原理简单到可笑的、可以让各种语言都能够与MinecraftBDS通信的LiteLoader插件

### 第三方调用FBDSRT

FBDSRT内建了一个Web服务器，在这里为其他语言提供API进行调用

使用到的第三方库（感谢）：https://github.com/yhirose/cpp-httplib

### FBDSRT触发事件调用第三方

通过Windows提供的界面（由此可见目前此项目只能用于Windows桌面环境）向控件发送信息

这里我放出了一个易语言的demo

为了解决乱码问题，一定要都使用Unicode！
