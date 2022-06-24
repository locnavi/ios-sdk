//
//  XJLocationShareProtocol.h
//  XJmapSDK
//
//  Created by zhangty on 2017/9/13.
//  Copyright © 2017年 XJmap. All rights reserved.
//

#ifndef XJLocationShareProtocol_h
#define XJLocationShareProtocol_h

#import <Foundation/Foundation.h>
#import "XJShareConfig.h"

@protocol XJLocationShareProtocol <NSObject>
@required

- (void)XJLocationShare:(XJShareType)type title:(NSString *)title desc:(NSString *)desc url:(NSString *)url thumbImage:(UIImage *)image;

@end


#endif /* XJLocationShareProtocol_h */
