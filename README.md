# XJMapSDK-iOS

XJMapSDK-iOS 是一套基于 iOS 8.0 及以上版本的室内地图应用程序开发接口，供开发者在自己的iOS应用中加入室内地图相关的功能，包括：地图显示（多楼层、多栋楼）、室内导航、模拟导航、语音播报等功能。

## 获取AppKey
请联系richard.chin@xunji-iot.com获取appKey、mapId

## 使用CocoaPods部署
在Podfile中使用命令如下：
```bash
pod 'XJMapSDK', '~> 1.0.19'
```
然后运行以下命令

```bash
$ pod install
```

## 手动集成
1. 将SDK文件中包含的XJMapSDK.framework添加到工程中。
2. 开发者需要在工程中链接上：CoreTelephony.framework、SystemConfiguration.framework、CFNetwork.framework、libz.tbd、libc++.tbd、libsqlite3.tbd。
3. 同时需要在Embedded Binaries 中链接上XJMapSDK.framework(动态链接库）如下图所示

<img alt="XJMapSDK" src="Readme.asset/linked.jpg">

### 注意
导入XJmapSDK后需要
- Build Settings中将Enable Bitcode 改成 NO。
- 在Info.plist中添加授权申明（iOS 13新增加蓝牙访问权限 “NSBluetoothAlwaysUsageDescription“）
```bash
	<key>NSBluetoothPeripheralUsageDescription</key>
	<string>开启蓝牙以使用室内导航服务</string>
	<key>NSBluetoothAlwaysUsageDescription</key>
	<string>开启蓝牙以使用室内导航服务</string>
	<key>NSLocationWhenInUseUsageDescription</key>
	<string>在室外定位及导航等服务中使用您的位置信息 </string>
	<key>NSLocationWhenInUseUsageDescription</key>
	<string>在室外定位及导航等服务中使用您的位置信息 </string>
	<key>NSMicrophoneUsageDescription</key>
	<string>在语音识别中需要使用麦克风</string>
  ```
- 若提示'XJMapSDK/XJMapSDK.h' file not found的话，需要在Build Setting->Framework Search Paths中配置framework的路径（如demo工程中的路径可设置‘$(PROJECT_DIR)/../XJMapSDK’）
  
## 使用说明  

### SDK初始化
  在 didFinishLaunchingWithOptions里面添加以下代码即可，appKey为邮件中获取的
```objective-c
    //初始化Ipsmap
    [XJmapServices setAppKey:appKey];
    //正式上线的地图不需要设置该属性
    [XJmapServices sharedInstance].debug = YES;
    // sdk默认读取手机语言设置，调用以下方法可忽略手机配置，强制使用参数设定语言，支持@"zh-Hans"、@"en"、@"zh-Hant"
    //[[XJmapServices sharedInstance] setAppLanguage:@"zh-Hans"];
    [[XJmapServices sharedInstance] application:application didFinishLaunchingWithOptions:launchOptions];
    //可配置要分享的渠道，默认分享微信跟短信
    //[XJShareConfig showSharePlatforms:@[@(XJShareTypeWeChat), @(XJShareTypeQQ), @(XJShareTypeSMS)]];
    //可配置是否显示蓝牙信号弱等提示，默认为true
    //[[XJmapServices sharedInstance] showSignalStrengthTip:false];
```


### 显示室内地图
   增加了两个配置属性，默认禁用分享位置功能和停车打卡功能
```objective-c
    XJMapViewController *vc = [[XJMapViewController alloc] initWithMapId:@"3aBi8Pl1oy"];
    //vc.shareLocationEnable = true; //开启分享位置功能
    //vc.checkInEnable = true;	//开启停车打卡功能
    [self.navigationController pushViewController:vc animated:YES];
```
  
### 导航至具体地址
```objective-c
    XJMapViewController *vc = [[XJMapViewController alloc] initWithMapId:@"3aBi8Pl1oy" targetName:@"服务台" targetId:@"10000"];
    [self.navigationController pushViewController:vc animated:YES];
```
### 搜索名称
```objective-c
    XJMapViewController *vc = [[XJMapViewController alloc] initWithMapId:@"3aBi8Pl1oy" searchName:@"服务台"];
    [self.navigationController pushViewController:vc animated:YES];
```
### 是否在地图范围内的接口
```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.manger = [XJmapLocationManger new];
    self.manger.locationTimeOut = 20;
    self.manger.delegate = self;
    
    [self.manger startLocationEngine:@"3aBi8Pl1oy"];
}

- (void)xjmapLocationManager:(XJmapLocationManger *_Nullable)manager didUpdateLocation:(XJLocationInfo *_Nullable)location 
{
    if (location.inThisMap) {
        NSLog(@"在医院里面");
    }
}
```	
