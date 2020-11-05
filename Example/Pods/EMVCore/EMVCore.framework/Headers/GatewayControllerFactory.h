//
//  GatewayControllerFactory.h
//  EMVCore
//

#ifndef GatewayControllerFactory_h
#define GatewayControllerFactory_h

#import "GatewayDelegate.h"

// Gateway Controller Factory
@protocol GatewayControllerFactory <NSObject>

+ (nonnull NSArray<NSString *> *)supportedGateways;
+ (nonnull NSArray<NSString *> *)supportedTerminals;
+ (nullable id<GatewayControllerProtocol>)createGatewayWith:(nullable GatewayConfiguration *)gatewayConfig
                                        withGatewayDelegate:(nullable id<GatewayDelegate>)delegate;

@end

#endif /* GatewayControllerFactory_h */
