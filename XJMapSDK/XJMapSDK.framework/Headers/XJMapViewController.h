//
//  XJMapViewController.h
//  XJmapSDK
//
//  Created by zhangty on 17/4/7.
//  Copyright © 2017年 XJmap. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XJLocationShareProtocol.h"

@class XJHospital;
@interface XJMapViewController : UIViewController

- (nonnull instancetype)initWithMapId:(nonnull NSString *)mapId;

- (nonnull instancetype)initWithHospitalInfo:(nonnull XJHospital *)hospital;

- (nonnull instancetype)initWithMapId:(nonnull NSString *)mapId targetName:(nonnull NSString *)targetName targetId:(nonnull NSString *)targetId;

- (nonnull instancetype)initWithMapId:(nonnull NSString *)mapId searchName:(nonnull NSString *)searchName;

@property (nonatomic, weak, nullable)id<XJLocationShareProtocol> locationShareDelegate;

- (void)setShareMapId:(NSString *_Nullable)mapId groupId:(NSString *_Nullable)groupId;
- (void)setShareGroupNumber:(NSString *_Nullable)number params:(NSMutableDictionary *_Nullable)params;
- (void)setLocationShareInfo:(nonnull NSDictionary *)params;
@end
