//
//  XJmapServices.h
//  XJmapSDK
//
//  Created by zhangty on 17/4/6.
//  Copyright © 2017年 XJmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "XJUserInfo.h"

//剪贴板内有位置共享口令
#define XJReceiveShareInfoNotification     @"XJNotificationReceiveShareInfo"

typedef void (^ XJOpenURLResult)(BOOL isValid, NSDictionary *params);


@protocol XJmapServicesDelegate <NSObject>

//监听partner下的医院列表请求返回（一般有两次，缓存、网络）
- (void)responseHospitalList:(NSArray *_Nullable)array error:(NSError *_Nullable)error;

@end

@class XJAppInfo;
@interface XJmapServices : NSObject {
    @private
    XJAppInfo  *appInfo;
    
}
@property (nonatomic, weak)id<XJmapServicesDelegate> _Nullable delegate;
@property (nonatomic, readonly)NSString * _Nullable appKey;
//验证Appkey的有效性
@property (nonatomic, assign)BOOL       isAppKeyValid;
//医院列表
@property (nonatomic, readonly)NSArray * _Nullable hospitalAry;
//用户信息
@property (nonatomic, strong)XJUserInfo * _Nullable userInfo;
//debug 模式可以请求到测试的地图资料
@property (nonatomic, assign)BOOL       debug;

+ (nonnull instancetype)sharedInstance;

+ (void)setAppKey:(nonnull NSString *)appKey;
//分享用的scheme
+ (void)setScheme:(nonnull NSString *)scheme;

- (void)application:(UIApplication *_Nonnull)application didFinishLaunchingWithOptions:(NSDictionary *_Nullable)launchOptions;

- (void)applicationWillEnterForeground:(UIApplication *_Nonnull)application;
- (BOOL)application:(UIApplication *_Nonnull)application openURL:(NSURL *_Nonnull)url block:(XJOpenURLResult _Nullable )block;
//位置共享功能需传入支持XJLocationShareProtocol的delegate
- (BOOL)application:(UIApplication *_Nonnull)application openURL:(NSURL *_Nonnull)url delegate:(id _Nullable)delegate;

//请求对应的医院列表
- (void)requestPartnerHospitalList;

//放在线程中处理，防止主线程卡住
- (BOOL)hasPermissionWith:(nonnull NSString *)mapId;
//忽略手机语言设置，强制设置App语言，需初始化时调用。(@"zh-Hans"、@"en"、@"zh-Hant")
- (void)setAppLanguage:(nullable NSString *)language;

+ (NSString *_Nullable)SDKVersion;

@end
