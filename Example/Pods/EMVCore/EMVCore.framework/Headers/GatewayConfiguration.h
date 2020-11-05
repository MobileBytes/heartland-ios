//
//  GatewayConfiguration.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "GatewayEnums.h"
#import "EMVCoreConstants.h"

@interface GatewayConfiguration : NSObject

// Properties
@property (nonatomic, assign) GatewayType gatewayType;
@property (nonatomic, assign) GatewayMode gatewayMode;// Default is GatewayModeDebug
@property (nonatomic, copy, nonnull) NSString *posAppName;
@property (nonatomic, copy, nonnull) NSString *posAppVersion;
@property (nonatomic, strong, nullable) NSDictionary<NSString*, NSString*> *credentials;
@property (nonatomic, assign) int timeOut;
@property (nonatomic, assign) int maxRetryAttempts;

// Init
- (nonnull instancetype)initWithPOSAppVersion:(nonnull NSString *)posAppVersion
                                   posAppName:(nonnull NSString *)posAppName
                                  credentials:(nullable NSDictionary<NSString*, NSString*> *)credentials
                              gatewayProvider:(GatewayType)gatewayType NS_DESIGNATED_INITIALIZER;

@end
