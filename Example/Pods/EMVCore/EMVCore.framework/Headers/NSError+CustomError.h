//
//  NSError+CustomError.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSError (CustomError)

+ (instancetype)emvErrorType:(ErrorType)errorType
             emvErrorMessage:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
