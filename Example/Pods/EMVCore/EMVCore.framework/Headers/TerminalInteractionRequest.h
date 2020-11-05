//
//  TerminalInteractionRequest.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "TerminalEnums.h"
#import "CardData.h"

NS_ASSUME_NONNULL_BEGIN

@interface TerminalInteractionRequest : NSObject

@property (nonatomic, assign) TerminalInteractionType terminalInteractionType;
@property (nonatomic, copy, nullable) NSArray *applicationNames;
@property (nonatomic, copy, nullable) CardData *cardData;
@property (nonatomic, copy, nullable) NSDecimalNumber *finalAmount;

- (instancetype)initWithTermianlInteractionType:(TerminalInteractionType)terminalInteractionType;

@end

NS_ASSUME_NONNULL_END
