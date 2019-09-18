//
//  ExampleLocationViewController.m
//  XJMapSDK_Demo
//
//  Created by zhangty on 2018/12/25.
//  Copyright © 2018 xunji. All rights reserved.
//

#import "ExampleLocationViewController.h"
#import <XJmapSDK/XJmapSDK.h>
#import "APIKey.h"

@interface ExampleLocationViewController ()<XJmapLocationDelegate>
    
@property (nonatomic, strong)XJmapLocationManger *manger;
    
@end

@implementation ExampleLocationViewController
    
- (void)dealloc {
    [self.manger stopLocatingEngine];
}
    
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.manger = [XJmapLocationManger new];
    self.manger.locationTimeOut = 20;
    self.manger.delegate = self;
    
    [self.manger startLocationEngine:(NSString *)MapId];
}
    
- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    
    [self.manger stopLocatingEngine];
}
    
- (void)xjmapLocationManager:(XJmapLocationManger *_Nullable)manager didUpdateLocation:(XJLocationInfo *_Nullable)location {
    if (location.inThisMap) {
        NSLog(@"在医院里面");
        [XJAlertView showAlertWithTitle:nil message:@"在院内" cancelButtonTitle:@"OK" otherButtonTitles:nil completion:nil];
    }else {
        [XJAlertView showAlertWithTitle:nil message:@"在院外" cancelButtonTitle:@"OK" otherButtonTitles:nil completion:nil];
    }
}
    
    @end
