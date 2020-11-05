//
//  PorticoGatewayControllerProtocol.h
//  Portico
//

#ifndef PorticoGatewayControllerProtocol_h
#define PorticoGatewayControllerProtocol_h

#import <EMVCore/GatewayControllerProtocol.h>
#import <EMVCore/GatewayConfiguration.h>

@protocol PorticoGatewayControllerProtocol <GatewayControllerProtocol>

@property (nonatomic, strong, nonnull) GatewayConfiguration *configuration;

@end

#endif /* PorticoGatewayControllerProtocol_h */
