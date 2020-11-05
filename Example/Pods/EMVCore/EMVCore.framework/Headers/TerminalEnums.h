//
//  TerminalEnums.h
//  EMVCore
//

#ifndef TerminalEnums_h
#define TerminalEnums_h

// TODO: IMPORTANT: Any changes done to any of these enums' values should also be updated in
//                  EnumStringValues.h.

// TODO: Update these Enums to follow Objective C style

typedef NS_ENUM(NSUInteger, TerminalAuthenticationCapability)
{
    NO_CAPABILITY,
    PIN_ENTRY,
    ELECTRONIC_SIGNATURE,
    INOPERATIVE,
    OTHER
};

typedef NS_ENUM(NSUInteger, TerminalInputCapability)
{
    UNKNOWN,
    NO_TERMINAL_MANUAL,
    MAGSTRIPE_READ_ONLY,
    OCR,
    ICC_CHIP_READ_ONLY,
    KEYED_ENTRY_ONLY,
    MAGSTRIPE_CONTACTLESS_ONLY,
    MAGSTRIPE_KEYED_ENTRY_ONLY,
    MAGSTRIPE_ICC_ONLY,
    ICC_KEYED_ENTRY_ONLY,
    ICC_CHIP_CONTACT_CONTACTLESS,
    ICC_CONTACTLESS_ONLY,
    OTHER_CAPABILITY_FOR_MASTERCARD
};

typedef NS_ENUM(NSUInteger, TerminalOperatingEnvironment)
{
    ON_MERCHANT_PREMISES_ATTENDED,
    NO_TERMINAL,
    ON_MERCHANT_PREMISES_UNATTENDED,
    OFF_MERCHANT_PREMISES_ATTENDED,
    OFF_MERCHANT_PREMISES_UNATTENDED,
    ON_CARDHOLDER_PREMISES_UNATTENDED,
    OFF_CARDHOLDER_PREMISES_UNATTENDED,
    OFF_MERCHANT_PREMISES_MERCHANT_MOBILE_POS,
    ON_MERCHANT_PREMISES_MERCHANT_MOBILE_POS,
    OFF_MERCHANT_PREMISES_CARDHOLDER_MOBILE_POS,
    ON_MERCHANT_PREMISES_CARDHOLDER_MOBILE_POS,
    ELECTRONIC_DELIVERY_OF_PRODUCT,
    PHYSICAL_DELIVERY_OF_PRODUCT
};

typedef NS_ENUM(NSUInteger, TerminalOutputCapability)
{
    PRINT_AND_DISPLAY,
    PRINT_ONLY,
    DISPLAY_ONLY,
    NO_OUTPUT_CAPABILITY,
};

typedef NS_ENUM(NSUInteger, TerminalType)
{
    INGENICO_RP450C,
    INGENICO_RP45BT,
    INGENICO_MOBY_3000,
    INGENICO_MOBY_8500,
    BBPOS_CHIPPER_2X,
    NO_READER
};

typedef NS_ENUM(NSUInteger, ConnectionType)
{
    AUDIO_JACK,
    BLUETOOTH,
    TCP_IP,
    USB
};

typedef NS_ENUM(NSUInteger, TerminalInteractionType)
{
    EMV_APPLICATION_SELECTION,
    FINAL_AMOUNT_CONFIRMATION,
    HOST_PROCESSING
};

typedef NS_ENUM(NSUInteger, TerminalStatus)
{
    IDLE,

    /**
     * EMV kernel is configured and now ready for a transaction to begin.
     */
    WAITING_FOR_TRANSACTION,

    /**
     * A transaction is in progress. Terminal is performing actions associated with MSR and EMV transactions.
     */
    TRANSACTION,

    /**
     * A transaction is in progress and the terminal is waiting for the amounts to be set.
     */
    WAITING_FOR_AMOUNT,

    /**
     * A transaction is in progress and the terminal is waiting for application selection.
     */
    WAITING_FOR_APPLICATION_SELECTION,

    /**
     * A transaction is in progress. Online processing is being performed. Transaction cannot be cancelled at this
     * point.
     */
    PROCESSING,

    /**
     * The terminal readers have been initialized and are ready for the card to be presented.
     */
    WAITING_FOR_CARD,

    /**
     * The terminal detected a card but was unable to read the data successfully.
     * <p>
     * The cardholder shall be prompted to present the card again.
     */
    BAD_READ_DETECTED,

    /**
     * The terminal detected multiple cards within the RFID field.
     * <p>
     * The cardholder shall be prompted to try again and only present one card.
     */
    MULTIPLE_CARDS_DETECTED,

    /**
     * The terminal detected an ICC being swiped without technical fallback being triggered.
     */
    ICC_SWIPE_DETECTED,

    /**
     * The terminal has failed to read the chip of an ICC and has initiated technical fallback.
     * <p>
     * The cardholder shall be prompted to remove the card and swipe instead of inserting.
     */
    TECHNICAL_FALLBACK_INITIATED,

    /**
     * The terminal has successfully captured card data.
     */
    CARD_DETECTED,

    /**
     * The terminal is unable to read the card data and the error is irrecoverable. The transaction
     * should be restarted.
     */
    CARD_READ_ERROR,

    /**
     * The terminal detected that the card has been removed after the transaction completed.
     */
    CARD_REMOVED_AFTER_TRANSACTION_COMPLETE,

    /**
     * The terminal has finished processing the contactless card and indicates that the card should
     * be removed from the RFID field.
     */
    CONTACTLESS_CARD_STILL_IN_FIELD,

    /**
     * The terminal is unable to use the RFID field for the field and suggests using the contact
     * interface.
     */
    CONTACTLESS_INTERFACE_FAILED_TRY_CONTACT,

    /**
     * The terminal requested that the card remain in the ICC slot or RFID field while processing.
     */
    DO_NOT_REMOVE_CARD,

    /**
     * The terminal is busy processing a command and is unable to fulfill the request to process
     * another command.
     */
    DEVICE_BUSY,

    /**
     * The terminal requested PIN entry.
     */
    ENTER_PIN,

    /**
     * The terminal indicates that only one more PIN entry attempt is allowed.
     */
    LAST_PIN_ATTEMPT,

    /**
     * The terminal indicates that PIN entry succeeded.
     */
    PIN_ACCEPTED,

    /**
     * The terminal indicates PIN entry failed and should be re-attempted.
     */
    RETRY_PIN,

    /**
     * The terminal indicates that the card should be removed.
     */
    REMOVE_CARD,

    /**
     * The terminal indicates that it is performing the configuration process.
     */
    CONFIGURING,

    /**
     * The terminal indicates that the cardholder should check their phone.
     */
    SEE_PHONE,

    /**
     * For none of the other Terminal Status options.
     */
    NONE
};

typedef NS_ENUM(NSUInteger, TerminalDecisionType)
{
    /**
     * The transaction was approved by the host and the terminal.
     */
    TerminalDecisionTypeApprovedOnline,

    /**
     * The transaction was approved offline by the terminal without host processing.
     */
    TerminalDecisionTypeApprovedOffline,

    /**
     * The transaction was declined online by the host.
     */
    TerminalDecisionTypeDeclinedOnline,

    /**
     * The transaction was declined offline by the terminal or chip.
     */
    TerminalDecisionTypeDeclinedOffline,

    /**
     * The transaction was declined by the terminal or chip after being approved by the host.
     * In these scenarios a reversal should be performed on the host approved transaction ID.
     */
    TerminalDecisionTypeReversalRequired,

    /**
     * The transaction was cancelled either by the consumer or the merchant.
     */
    TerminalDecisionTypeTransactionCancelled,

    /**
     * A host response was never received.
     * The transaction should be treated as a decline.
     */
    TerminalDecisionTypeHostUnreachable,
};

typedef NS_ENUM(NSUInteger, TerminalAction)
{
    SETUP,
    INFO,
    TENDER_GOODS,
    TENDER_SERVICES,
    TENDER_REFUND,
};

#endif /* TerminalEnums_h */
