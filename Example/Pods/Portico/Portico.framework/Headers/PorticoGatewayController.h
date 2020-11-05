//
//  PorticoGatewayController.h
//  Portico
//

#import <Foundation/Foundation.h>
#import <EMVCore/GatewayDelegate.h>
#import <EMVCore/GatewayControllerProtocol.h>

@interface PorticoGatewayController : NSObject <GatewayControllerProtocol>

// Methods
+ (nonnull instancetype)sharedInstance;
- (nullable id<GatewayControllerProtocol>)initWithGatewayConfiguration:(nullable GatewayConfiguration*)configurations
                                                              delegate:(nullable id<GatewayDelegate>)porticoDelegate;

@end
