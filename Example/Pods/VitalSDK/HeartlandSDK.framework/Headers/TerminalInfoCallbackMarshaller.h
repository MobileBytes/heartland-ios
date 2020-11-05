//
//  TerminalInfoCallbackMarshaller.h
//  HeartlandSDK
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TerminalInfoCallbackMarshaller : NSObject

// Methods
- (void)callbackOnTerminalInfo:(TerminalInfo *)terminalInfo;
- (void)callbackOnError:(NSError *)error;
- (void)updatDelegate:(id<TerminalInfoDelegate>)delegate;

// Init
- (instancetype)initWithTerminalInfoDelegate:(id<TerminalInfoDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
