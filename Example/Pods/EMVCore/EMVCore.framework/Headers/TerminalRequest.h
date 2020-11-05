//
//  TerminalRequest.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalConfiguration.h"
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface TerminalRequest : NSObject

@property (nonatomic, copy, nullable) NSDecimalNumber *totalAmount;
@property (nonatomic, copy, nullable) NSDecimalNumber *tipAmount;
@property (nonatomic, copy, nullable) NSDecimalNumber *cashBackAmount;
@property (nonatomic, copy, nullable) TerminalConfiguration *terminalConfiguration;
@property (nonatomic, assign) TenderType tenderType;
@property (nonatomic, assign) TransactionType transactionType;
@property (nonatomic, assign) TerminalAction terminalAction;

- (instancetype)initWithTerminalAction:(TerminalAction)terminalAction;

@end

NS_ASSUME_NONNULL_END
