#import <Foundation/Foundation.h>
#import "HpsUpaResponse.h"
#import "HpsUpaDevice.h"
#import "HpsTransactionDetails.h"

@interface HpsUpaAdjustBuilder : NSObject
{
    HpsUpaDevice *device;
}

@property (nonatomic, readwrite) uint64_t referenceNumber;
@property (nonatomic, strong) NSString *ecrId;
@property (nonatomic, strong) NSDecimalNumber *gratuity;
@property (nonatomic, strong) NSString *terminalRefNumber;
@property (nonatomic, strong) NSString *transactionId;
@property (nonatomic, strong) HpsTransactionDetails *details;

- (void) execute:(void(^)(HpsUpaResponse*, NSError*))responseBlock;
- (id)initWithDevice: (HpsUpaDevice*)upaDevice;

@end
