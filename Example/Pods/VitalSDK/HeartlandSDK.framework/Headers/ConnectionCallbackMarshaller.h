//
//  ConnectionCallbackMarshaller.h
//  HeartlandSDK
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ConnectionCallbackMarshaller : NSObject

// Methods
- (void)callbackOnError:(NSError *)error;
- (void)callbackOnConnected:(TerminalInfo *)terminalInfo;
- (void)callbackOnDisconnected;
- (void)updateDelegate:(id<TerminalConnectionDelegate>)delegate;

// Init
- (instancetype)initWithTerminalConnectionDelegate:(id<TerminalConnectionDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
