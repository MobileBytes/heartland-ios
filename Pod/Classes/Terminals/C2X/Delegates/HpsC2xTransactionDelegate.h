#import <Foundation/Foundation.h>
#import "C2XEnums.h"
#import "HpsTerminalResponse.h"
#import "HpsCardholderInteractionRequest.h"

NS_ASSUME_NONNULL_BEGIN

@protocol HpsC2xTransactionDelegate <NSObject>

- (void)onStatusUpdate:(HpsC2xTransactionStatus)transactionStatus;
- (void)onCardholderInteractionRequested:(HpsCardholderInteractionRequest *)request;
- (void)onTransactionComplete:(HpsTerminalResponse *)response;
- (void)onError:(NSError *)emvError;

@end

NS_ASSUME_NONNULL_END
