//
//  TransactionCallbackMarshaller.h
//  HeartlandSDK
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TransactionCallbackMarshaller : NSObject

// Methods
- (void)callbackOnError:(NSError *)error;
- (void)callbackOnStatusUpdate:(TransactionStatus)status;
- (void)callbackOnCardholderInteractionRequested:(CardholderInteractionRequest *)request;
- (void)callbackOnTransactionResponse:(TransactionResponse *)response;
- (void)updateDelegate:(id<TransactionDelegate>)delegate;

// Init
- (instancetype)initWithTransactionDelegate:(id<TransactionDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
