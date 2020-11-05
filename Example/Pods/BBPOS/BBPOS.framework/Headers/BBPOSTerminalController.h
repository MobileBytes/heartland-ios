//
// BBPOSTerminalController.h
// BBPOS
//

#import <Foundation/Foundation.h>
#import <EMVCore/TerminalControllerProtocol.h>
#import <EMVCore/TerminalDelegate.h>

@class TransactionConfiguration;

@interface BBPOSTerminalController : NSObject<TerminalControllerProtocol, TerminalDelegate>

#pragma mark - Properties

@property (nonatomic, strong) TerminalRequest *terminalRequest;

#pragma mark - Methods

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)sharedInstance;
- (id<TerminalControllerProtocol>)initializeWith:(TerminalType)terminalType
                                    withTerminal:(TerminalConfiguration *)terminalConfiguration
                                       andConfig:(TransactionConfiguration *)transactionConfig
                                    withDelegate:(id<TerminalDelegate>)delegate;

@end
