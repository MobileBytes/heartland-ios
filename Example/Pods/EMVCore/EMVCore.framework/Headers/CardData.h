//
//  CardData.h
//  EMVCore
//

#import <Foundation/Foundation.h>
#import "CommonEnums.h"

@class Address;
@class TLVObject;

NS_ASSUME_NONNULL_BEGIN

@interface CardData : NSObject <NSCopying>

@property (nonatomic, copy, nullable) NSString *track1;
@property (nonatomic, copy, nullable) NSString *track2;
@property (nonatomic, copy, nullable) NSString *track3;
@property (nonatomic, copy, nullable) NSString *encryptedData;
@property (nonatomic, copy, nullable) NSString *packedEncryptedData;
@property (nonatomic, copy, nullable) NSString *ksn;
@property (nonatomic, copy, nullable) NSArray<TLVObject *> *emvTLVData;
@property (nonatomic, copy, nullable) NSString *pinBlock;
@property (nonatomic, copy, nullable) NSString *pinKSN;
@property (nonatomic, copy, nullable) NSString *pan;
@property (nonatomic, copy, nullable) NSString *expirationDate;
@property (nonatomic, copy, nullable) NSString *cvv2;
@property (nonatomic, copy, nullable) NSString *postalCode;
@property (nonatomic, copy, nullable) NSString *cardholderName;
@property (nonatomic, copy, nullable) NSString *cardNumber;
@property (nonatomic, copy, nullable) Address *cardholderAddress;
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *decodedTLVDictionary;
@property (nonatomic, assign) AvsType avsType;
@property (nonatomic, assign) CardDataSourceType cardDataSourceType;
@property (nonatomic, assign) FallbackReason fallbackReason;
@property (nonatomic, assign) EncryptionType encryptionType;
@property (nonatomic, assign) LastChipRead lastChipRead;
@property (nonatomic, assign) CardType cardType;
@property (nonatomic, assign) CvmResult cvmResult;

@end

NS_ASSUME_NONNULL_END
