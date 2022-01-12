//
//  XJShareConfig.h
//  XJmapSDK
//
//  Created by zhangty on 2017/9/12.
//  Copyright © 2017年 XJmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, XJShareType) {
    XJShareTypeUnkown,
    XJShareTypeWeChat, //微信
    XJShareTypeQQ,     //QQ
    XJShareTypeSMS,    //短信
    XJShareTypeCopy,   //复制
};

@interface XJShareConfig : NSObject

@property (nonatomic, copy)NSString *scheme;
@property (nonatomic, strong)UIImage *imageIcon;
@property (nonatomic, readonly)NSArray *supportPlatforms;

+ (instancetype)sharedInstance;

+ (void)showSharePlatforms:(NSArray *)showPlatforms;

+ (void)sendShare:(XJShareType)type title:(NSString *)title desc:(NSString *)desc url:(NSString *)url;

@end
