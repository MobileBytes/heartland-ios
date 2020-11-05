//
//  GatewayControllerProtocol.h
//  EMVCore
//

#ifndef GatewayControllerProtocol_h
#define GatewayControllerProtocol_h

@class GatewayRequest;

@protocol GatewayControllerProtocol <NSObject>

/**
 Invoke to perform all type of GatewayRequests.
 @param gatewayRequest Request data to be passed to the host implementation.
 */
- (void)sendRequest:(nonnull GatewayRequest *)gatewayRequest;

@end

#endif /* GatewayControllerProtocol_h */
