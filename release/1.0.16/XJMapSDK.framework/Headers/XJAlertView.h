//
//  XJAlertView.h
//  XJmapSDK
//
//  Created by zhangty on 2017/7/14.
//  Copyright © 2017年 XJmap. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^XJAlertViewCompletion)(NSUInteger selectedOtherButtonIndex);

@interface XJAlertView : NSObject

+ (void)showAlertWithTitle:(NSString *)title
                   message:(NSString *)message
         cancelButtonTitle:(NSString *)cancelButtonTitle
         otherButtonTitles:(NSArray *)otherButtonTitles
                completion:(XJAlertViewCompletion)completion NS_EXTENSION_UNAVAILABLE_IOS("");

+ (void)showNetworkNotReachable;

@end
