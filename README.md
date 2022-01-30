# FBDSRT
Floppy BDS Runtime: A "cross-language runtime framework" for Minecraft BDS

## 大鸽子的公告

管理这个仓库的人是个大鸽子，没有人知道距离这个仓库下一次增加新的功能是什么时候。现在可用的事件和功能少得可怜，后续会***真·慢慢更新***出来的。

如何催更？浏览器打开这个网站：穷.tk

中文域名，打开它，然后向这个可怜的开发者资助，并催更，这个效果最好，他一定会以最快的速度对接LiteLoader然后把新的代码push到仓库

## 开源协议

我不知道LiteLoaderBDS的GPL3.0协议对我的这个项目是否仍然具有传染性，反正我本来就想用GPL3.0协议，这不是什么大问题

联系我：floppy#iruanp.com(请把#改为@)

## 原理

这是一个原理简单到可笑的、可以让各种语言都能够与MinecraftBDS通信的LiteLoader插件

### 第三方调用FBDSRT

FBDSRT内建了一个Web服务器，在这里为其他语言提供API进行调用

使用到的第三方库（感谢）：https://github.com/yhirose/cpp-httplib

### FBDSRT触发事件调用第三方

通过Windows提供的界面（由此可见目前此项目只能用于Windows桌面环境）向控件发送信息

这里我放出了一个易语言的demo

为了解决乱码问题，一定要都使用Unicode！

## 编译

