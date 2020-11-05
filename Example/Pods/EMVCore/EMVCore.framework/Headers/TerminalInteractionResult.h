//
//  TerminalInteractionResult.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalEnums.h"
#import "GatewayResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface TerminalInteractionResult : NSObject

@property (nonatomic, assign) int selectedApplicationIndex;
@property (nonatomic) BOOL finalAmountConfirmed;
@property (nonatomic, copy, nullable) GatewayResponse *gatewayResponse;
@property (nonatomic, assign) TerminalInteractionType terminalInteractionType;

@end

NS_ASSUME_NONNULL_END
