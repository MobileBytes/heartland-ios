//
//  TerminalControllerFactory.h
//  EMVCore
//

#import "TerminalEnums.h"
#import "TerminalControllerProtocol.h"
#import "TerminalConfiguration.h"
#import "TerminalDelegate.h"

#ifndef TerminalControllerFactory_h
#define TerminalControllerFactory_h

@class TransactionConfiguration;

@protocol TerminalControllerFactory <NSObject>

+ (nonnull NSArray<NSString *> *)supportedTerminals;
+ (nonnull NSArray<NSString *> *)supportedConnections;
+ (nullable id<TerminalControllerProtocol>)createTermminalOfType:(TerminalType)terminalType
                                                            with:(nullable TerminalConfiguration *)terminalConfiguration
                                                  andTransaction:(nullable TransactionConfiguration *)transactionConfiguration
                                                    withDelegate:(nullable id<TerminalDelegate>)delegate;
@end

#endif /* TerminalControllerFactory_h */
