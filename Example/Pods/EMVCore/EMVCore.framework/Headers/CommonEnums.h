//
//  CommonEnums.h
//  EMVCore
//

#ifndef CommonEnums_h
#define CommonEnums_h

// TODO: IMPORTANT: Any changes done to any of these enums' values should also be updated in
//                  EnumStringValues.h.

// Supported Types (works in conjunction `dictionaryForEnumType:(NSUInteger)enumType` of EnumStringValues)
typedef NS_ENUM(NSUInteger, StringValueForEnumType)
{
    TerminalTypeEnum = 1,
    GatewayTypeEnum,
    ConnectionTypeEnum,
    TransactionTypeEnum,
    CommercialCardDataFieldEnum,
    EMVErrorTypeEnum,
    TerminalStatusEnum,
    CardTypeEnum,
    CvmResultEnum,
    CardDataSourceTypeEnum,
    PinStatementTypeEnum,
    CurrencyCodeEnum,
    CountryCodeEnum,
    TransactionResultTypeEnum,
};

/**
 Indicates the components of the address needed for Address Verification System.

 - AvsTypeZip: Zip Only
 - AvsTypeZipAddress: Address and Zip required
 - AvsTypeNone: None
 */
typedef NS_ENUM(NSUInteger, AvsType)
{
    AvsTypeZip,
    AvsTypeZipAddress,
    AvsTypeNone
};

/**
 * Sources from which card data can be captured and processed.
 */
typedef NS_ENUM(NSUInteger, CardDataSourceType)
{
    /**
     * Card data was captured from a Mag Stripe Read.
     */
    CardDataSourceTypeMSR,

    /**
     * Card data was captured from the EMV.
     */
    CardDataSourceTypeEMV,

    /**
     * Card data was captured via NFC, with Mag Stripe formatted data.
     */
    CardDataSourceTypeContactlessMSR,

    /**
     * Card data was captured via NFC, with EMV formatted data.
     */
    CardDataSourceTypeContactlessEMV,

    /**
     * Card data was entered manually on an Encrypted PIN Pad (EPP)
     */
    CardDataSourceTypeKeyed,

    /**
     * Card data was presented over a phone.
     */
    CardDataSourceTypePhone,

    /**
     * Card data was sent through parcel services.
     */
    CardDataSourceTypeMail,

    /**
     * Card data was captured via an E-commerce channel.
     */
    CardDataSourceTypeInternet,

    /**
     * To fallback to either options of EMV or MSR.
     */
    CardDataSourceTypeFallback,

    /**
     * If none of the Card Source Type Matches.
     */
    CardDataSourceTypeNone
};

typedef NS_ENUM(NSUInteger, CardType)
{
    CardTypeVisaCard,
    CardTypeMasterCard,
    CardTypeAmexCard,
    CardTypeDiscoverCard,
    CardTypeJCBCard,
    CardTypeDinersClubCard,
    CardTypeMaestroCard,
    CardTypeUnionPayCard,
    CardTypeUnknown
};

typedef NS_ENUM(NSUInteger, CurrencyCode)
{
    CurrencyCodeUSD,
};

typedef NS_ENUM(NSUInteger, CountryCode)
{
    CountryCodeUS,
};

/**
 Indicates if the card is a purchasing or commercial card and if so, what type.

 - CommercialCardBusiness: Business
 - CommercialCardVisaCommerce: Visa Commerce
 - CommercialCardB2BSettlementEligible: B2B Settlement Eligible
 - CommercialCardCorporate: Corporate
 - CommercialCardPurchase: Purchase
 - CommercialCardNonCommercial: Non commercial
 */
typedef NS_ENUM(NSUInteger, CommercialCard)
{
    CommercialCardBusiness,
    CommercialCardVisaCommerce,
    CommercialCardB2BSettlementEligible,
    CommercialCardCorporate,
    CommercialCardPurchase,
    CommercialCardNonCommercial
};

/**
 Describes the type of cardholder verification that was performed and the result
 */
typedef NS_ENUM(NSInteger, CvmResult)
{
    /**
     * PIN Entry was performed and successfully verified by the gateway and/or host.
     */
    PIN_ONLINE = 0x01,

    /**
     * Encrypted PIN Entry was performed and successfully verified by the ICC and EMV kernel.
     */
    PIN_OFFLINE_ENCR = 0x02,

    /**
     * PIN Entry was performed and successfully verified by the ICC and EMV kernel.
     */
    PIN_OFFLINE_PLAIN = 0x03,

    /**
     * Signature should be captured either electronically or on a printed receipt.
     */
    SIGNATURE_REQUIRED = 0x5E,

    /**
     * No cardholder verification was performed.
     */
    NO_CVM_REQUESTED = 0x1F,

    /**
     * The cardholder verification method and result are not available.
     */
    NOT_AVAILABLE = 0x00
};

typedef NS_ENUM(NSUInteger, PinStatementType)
{
    /**
     * PIN is not supported by the terminal in the context of the current transaction.
     */
    PIN_NOT_SUPPORTED,

    /**
     * PIN was verified either locally by ICC or remotely by the host.
     */
    PIN_VERIFIED,

    /**
     * PIN entry was prompted, but the user bypassed it.
     */
    PIN_BYPASSED,

    /**
     * PIN could not be verified and is now locked.
     */
    PIN_LOCKED
};

typedef NS_ENUM(NSUInteger, EncryptionType)
{
    EncryptionTypeTDES,
    EncryptionTypeDUKPT,
    EncryptionTypeVoltage,
    EncryptionTypeIDT_TDES,
    EncryptionTypeNone
};

typedef NS_ENUM(NSUInteger, ErrorType)
{
    NOT_INITIALIZED,
    CONFIGURATION_ERROR,
    INITIALIZATION_ERROR,
    NOT_CONNECTED,
    HOST_CONFIG_NOT_SUPPORTED,
    INVALID_DATA,
    TERMINAL_CONFIG_NOT_SUPPORTED,
    TERMINAL_ERROR,
    TRANSACTION_ERROR,
    INVALID_REQUEST,
    GENERAL_ERROR,
    BATTERY_TOO_LOW
};

typedef NS_ENUM(NSUInteger, FallbackReason)
{
    FallbackReasonEmptyCandidateList,
    FallbackReasonIccError,
    FallbackReasonOther,
    FallbackReasonNone
};

typedef NS_ENUM(NSUInteger, LastChipRead)
{
    LastChipReadSuccessful,
    LastChipReadFailed,
    LastChipReadNotAChipTransaction,
    LastChipReadUnknown
};

/**
 Transaction Void Reasons :

    - ReversalReasonUndefined: Undefined
    - ReversalReasonVoidedByCustomer: Voided by Customer after Transaction approved by Host
    - ReversalReasonDeviceTimeOut: The terminal times out during a card interaction
    - ReversalReasonDeviceUnavailable: Communication to the terminal fails after host processing
    - ReversalReasonPartialReversal: Patial Transaction Void
    - ReversalReasonPrematureChipRemoval: User removes chip before Host approves the Transaction
    - ReversalReasonChipDeclined: Chip decline after Host processing
 */
typedef NS_ENUM(NSUInteger, ReversalReason)
{
    ReversalReasonUndefined,
    ReversalReasonVoidedByCustomer,
    ReversalReasonDeviceTimeOut,
    ReversalReasonDeviceUnavailable,
    ReversalReasonPartialReversal,
    ReversalReasonPrematureChipRemoval,
    ReversalReasonChipDeclined
};

/**
    Indicates the type of tax being applied to the transaction. Interchange rates for a transaction
    can be affected based on the way the taxes are applied.
 */
typedef NS_ENUM(NSUInteger, TaxCategory)
{
    TaxCategoryTotal,
    TaxCategorySale,
    TaxCategoryService,
    TaxCategoryDuty,
    TaxCategoryVAT,
    TaxCategoryAlternate,
    TaxCategoryNational,
    TaxCategoryTaxExempt
};

typedef NS_ENUM(NSUInteger, TenderType)
{
    TenderTypeCredit,
    TenderTypeDebit
};

typedef NS_ENUM(NSUInteger, TransactionResultType)
{
    TransactionResultTypeApproved,
    TransactionResultTypeDeclinedOffline,
    TransactionResultTypeDeclinedOnline,
    TransactionResultTypePartiallyApproved,
    TransactionResultTypePostAuthReversal,
    TransactionResultTypeCallIssuer,
    TransactionResultTypeCancelled
};

typedef NS_ENUM(NSUInteger, TransactionStatus)
{
    /**
     * The configured terminal is ready for the cardholder to present their card.
     */
    TransactionStatusWaitingForCard,

    /**
     * The presented card could not be read successfully. The cardholder shall be prompted to
     * present their card again.
     */
    TransactionStatusBadRead,

    /**
     * A chip was detected on the swiped card. The cardholder shall be prompted to insert their
     * card or present another card.
     */
    TransactionStatusICCSwiped,

    /**
     * The chip on a card could not be read successfully after several attempts. The cardholder
     * shall be prompted to swipe their card or present another card.
     */
    TransactionStatusFallbackInitiated,

    /**
     * Multiple cards were detected within the NFC Field. The cardholder should be prompted to
     * present a single card.
     */
    TransactionStatusMultipleCardsDetected,

    /**
     * Data was successfully captured from a card.
     */
    TransactionStatusCardRead,

    /**
     * The ICC chip could not be read by the terminal.
     * <p>
     * The cardholder shall be prompted to remove the card and swipe instead of inserting.
     */
    TransactionStatusTechnicalFallbackInitiated,

    /**
     * The terminal is unable to read the card data and the error is irrecoverable. The transaction
     * should be restarted.
     */
    TransactionStatusCardReadError,

    /**
     * The terminal detected that the card has been removed after the transaction completed.  The
     * customer-facing display should be updated to reflect this.
     */
    TransactionStatusCardRemovedAfterTransactionComplete,

    /**
     * The terminal has finished processing the contactless card and the customer should be prompted
     * to remove the card from the RFID field.
     */
    TransactionStatusContactlessCardStillInField,

    /**
     * The terminal is unable to use the RFID field to capture card data. The customer should be
     * prompted to use the contact interface.
     */
    TransactionStatusContactlessInterfaceFailedTryContact,

    /**
     * The cardholder should be prompted to leave the card in the ICC slot or RFID field while
     * processing.
     */
    TransactionStatusDoNotRemoveCard,

    /**
     * The cardholder is notified that the current request cannot be fulfilled because the terminal
     * is processing.
     */
    TransactionStatusDeviceBusy,

    /**
     * The cardholder should be prompted to enter their PIN.
     */
    TransactionStatusEnterPin,

    /**
     * The cardholder should be notified that only one more PIN entry attempt is allowed.
     */
    TransactionStatusLastPinAttempt,

    /**
     * The cardholder should be notified that PIN entry succeeded.
     */
    TransactionStatusPinAccepted,

    /**
     * The cardholder should be notified that PIN entry failed and should be prompted to try again.
     */
    TransactionStatusRetryPin,

    /**
     * The cardholder should be prompted to remove the card.
     */
    TransactionStatusRemoveCard,

    /**
     * The cardholder should be prompted to wait while the terminal is being configured.
     */
    TransactionStatusConfiguring,

    /**
     * The cardholder should be referred to their phone for further instructions.
     */
    TransactionStatusSeePhone,

    /**
     * Transaction Status None of other Transaction status.
     */
    TransactionStatusNone,
};

typedef NS_ENUM(NSUInteger, TransactionType)
{
    TransactionTypeSale,
    TransactionTypeAuth,
    TransactionTypeCapture,
    TransactionTypeForcedAuth,
    TransactionTypeVoid,
    TransactionTypeRefundWithCard,
    TransactionTypeRefundWithReference,
    TransactionTypeTipAdjust,
    TransactionTypeBatchClose,
    // The TransactionTypeNone type tells that transaction was none of the `TransactionType` types.
    TransactionTypeNone,
};

#endif /* CommonEnums_h */
