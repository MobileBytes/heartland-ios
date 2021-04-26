//
//  HRGMSDeviceManager.h
//  Heartland-iOS-SDK_Example
//
//  Created by Desimini, Wilson on 4/26/21.
//  Copyright © 2021 Shaunti Fondrisi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Heartland_iOS_SDK/HpsConnectionConfig.h>
#import "HRGMS+Notifications.h"

NS_ASSUME_NONNULL_BEGIN

@interface HRGMSDeviceManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, readonly) BOOL deviceIsScanning;

- (void)addDeviceWithConfig:(HpsConnectionConfig *)config;
- (void)startScan;
- (void)stopScan;

@end

NS_ASSUME_NONNULL_END
