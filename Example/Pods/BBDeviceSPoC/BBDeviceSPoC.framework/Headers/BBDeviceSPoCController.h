//
//  BBDeviceSPoCController
//
//  Created by Alex Wong on 2019-04-25
//  Copyright (c) 2019 BBPOS Limited. All rights reserved.
//  RESTRICTED DOCUMENT
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BBDeviceSPoCController : NSObject{
}

+ (BBDeviceSPoCController *)sharedController;

#pragma mark - Public

- (NSString *)getApiVersion;
- (NSString *)getApiBuildNumber;

@end
