//
//  GatewayDelegate.h
//  EMVCore
//

#ifndef GatewayDelegate_h
#define GatewayDelegate_h

@class GatewayResponse;

@protocol GatewayDelegate <NSObject>

/**
 Invoked when a response or error is received from host.
 @param gatewayResponse GatewayResponse received
 */
- (void)onGatewayResponse:(nullable GatewayResponse *)gatewayResponse;

@end

#endif /* GatewayDelegate_h */
