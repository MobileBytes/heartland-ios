//
//  TransactionManager.h
//  HeartlandSDK
//

#import <Foundation/Foundation.h>
#import <EMVCore/EMVCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface TransactionManager : NSObject <TransactionManagerProtocol>

// Methods
+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
