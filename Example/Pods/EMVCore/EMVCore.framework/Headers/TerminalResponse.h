//
//  TerminalResponse.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalEnums.h"
#import "CardData.h"

NS_ASSUME_NONNULL_BEGIN

@interface TerminalResponse : NSObject

@property (nonatomic, assign) TerminalAction terminalAction;
@property (nonatomic, assign) TerminalDecisionType terminalDecisionType;
@property (nonatomic, copy, nullable) NSString *message;
@property (nonatomic, copy, nullable) CardData *cardData;

- (instancetype)initWithTerminalAction:(TerminalAction)terminalAction;

@end

NS_ASSUME_NONNULL_END
