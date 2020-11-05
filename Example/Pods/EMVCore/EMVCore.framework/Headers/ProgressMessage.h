//
//  ProgressMessage.h
//  EMVCore
//

#ifndef ProgressMessage_h
#define ProgressMessage_h

/**
     - PROGRESS_MESSAGE_PleaseInsertCard: Message indicating cardholder should insert card.
     - PROGRESS_MESSAGE_TryAnotherInterface: To indicate cardholder should try card a different way (swipe,tap,insert)
     - PROGRESS_MESSAGE_PleaseRemoveCard: Message indicating cardholder should remove card
     - PROGRESS_MESSAGE_SwipeDetected: Message indicating a card swipe has been detected
     - PROGRESS_MESSAGE_WaitingforCardSwipe: Message indicating the card reader is waiting for card swipe
     - PROGRESS_MESSAGE_WaitingforDevice: Message indicating the device is waiting
     - PROGRESS_MESSAGE_DecodingStarted: Message indicating card reader is processing card data
     - PROGRESS_MESSAGE_CommandSent: Message indicating a command has been sent to the card reader
     - PROGRESS_MESSAGE_ICCErrorSwipeCard: Message indicating ICC error and card should be swiped
     - PROGRESS_MESSAGE_SwipeErrorReswipe: Message indicating cardholder should reswipe card
     - PROGRESS_MESSAGE_MagCardDataInsertCard: Message indicating cardholder should insert card instead of swipe
     - PROGRESS_MESSAGE_CardInserted: Message indicating a card has been inserted
     - PROGRESS_MESSAGE_CardReadError: Message indicating card read failed
     - PROGRESS_MESSAGE_Unknown: Message indicating Unknown progress state
     - PROGRESS_MESSAGE_ApplicationSelectionStarted: Message indicating application selection started
     - PROGRESS_MESSAGE_ApplicationSelectionCompleted: Message indicating application selection is complete
     - PROGRESS_MESSAGE_CardHolderPressedCancelKey: Message indicating cardholder pressed cancel button on terminal
     - PROGRESS_MESSAGE_ContactlessTransactionRevertedToContact: Message indicating cardholder should use contact
     - PROGRESS_MESSAGE_DeviceBusy: Message indicating device is already processing a command
     - PROGRESS_MESSAGE_FirstPinEntryPrompt: Message indicating first pin entry prompt should be shown
     - PROGRESS_MESSAGE_ErrorReadingContactlessCard: Message indicating contactless card read failed
     - PROGRESS_MESSAGE_LastPinEntryPrompt: Message indicating last pin try should be shown
     - PROGRESS_MESSAGE_MultipleContactlessCardsDetected: Message indicating multiple contactless cards detected
     - PROGRESS_MESSAGE_PinEntryFailed: Message indicating pin entry failed
     - PROGRESS_MESSAGE_PinEntryInProgress: Message indicating pin is being entered
     - PROGRESS_MESSAGE_PinEntrySuccessful: Message indicating pin entry success
     - PROGRESS_MESSAGE_RetryPinEntryPrompt: Message indicating pin should be tried again
     - PROGRESS_MESSAGE_SwipeErrorReswipeMagStripe: Message indicating magstrip should be retried
     - PROGRESS_MESSAGE_UpdatingFirmware: Message indicating firmware update in progress
     - PROGRESS_MESSAGE_TapDetected: Message indicating tap was detected
     - PROGRESS_MESSAGE_ContactlessCardStillInField: Message indicating contactless card still near reader
     - PROGRESS_MESSAGE_FirstEnterNewPINPrompt: Message indicating new pin first prompt
     - PROGRESS_MESSAGE_ValidateNewPINPrompt: Message indicating validate new pin prompt
     - PROGRESS_MESSAGE_RetryEnterNewPINPrompt: Message indicating enter a new pin
     - PROGRESS_MESSAGE_PINChangeFailed: Message indicating pin change failed
     - PROGRESS_MESSAGE_PINChangeEnded: Message indicating pin change ended
     - PROGRESS_MESSAGE_PleaseSeePhone: Message indicating cardholder should view their consumer device - CD-CVM fail
     - PROGRESS_MESSAGE_ContactlessInterfaceFailedTryContact: Message indicating to try contact interface
     - PROGRESS_MESSAGE_PresentCardAgain: Message indicating card should be represented to terminal
     - PROGRESS_MESSAGE_CardRemoved: Message indicating card was removed
     - PROGRESS_MESSAGE_NotAuthorized: Message indicating request was not authorized
     - PROGRESS_MESSAGE_CompleteCardRemove: Message indicating complete card remove
     - PROGRESS_MESSAGE_RemoveCard: Message indicating card should be removed
     - PROGRESS_MESSAGE_InsertOrSwipeCard: Message indicating card reader waiting for insert or swipe
     - PROGRESS_MESSAGE_TransactionVoid: Message indicating transaction was voided - post auth chip decline
     - PROGRESS_MESSAGE_CardReadOkRemoveCard: To indicate device completed reading card data and card can be removed
     - PROGRESS_MESSAGE_ProcessingTransaction: Message indicating transaction is being processed
     - PROGRESS_MESSAGE_CardHolderBypassedPIN: Message indicating cardholder bypassed pin entry
     - PROGRESS_MESSAGE_NotAccepted: Message indicating card not accepted
     - PROGRESS_MESSAGE_ProcessingDoNotRemoveCard: Message indicating cardholder should not remove card
     - PROGRESS_MESSAGE_Authorizing: Message indicating transaction went online
     - PROGRESS_MESSAGE_NotAcceptedRemoveCard: Message indicating card not accepted and can be removed
     - PROGRESS_MESSAGE_CardError: Message indicating card error
     - PROGRESS_MESSAGE_CardErrorRemoveCard: Message indicating card error and card may be removed
     - PROGRESS_MESSAGE_Cancelled: Message indicating card reader action has been canceled. like waiting for card
     - PROGRESS_MESSAGE_CancelledRemoveCard: Message indicating action canceled and card may be removed
     - PROGRESS_MESSAGE_TransactionVoidRemoveCard: Message indicating transaction is void and card may be removed
     - PROGRESS_MESSAGE_UnknownAID: Message indicating AID is unknown by card reader.
 */
typedef NS_ENUM(NSUInteger, ProgressMessage) {
    PROGRESS_MESSAGE_PLEASE_INSERT_CARD,
    PROGRESS_MESSAGE_TRY_ANOTHER_INTERFACE,
    PROGRESS_MESSAGE_PLEASE_REMOVE_CARD,
    PROGRESS_MESSAGE_SWIPE_DETECTED,
    PROGRESS_MESSAGE_WAITING_FOR_CARD_SWIPE,
    PROGRESS_MESSAGE_WAITING_FOR_DEVICE,
    PROGRESS_MESSAGE_DECODING_STARTED,
    PROGRESS_MESSAGE_COMMAND_SENT,
    PROGRESS_MESSAGE_ICC_ERROR_SWIPE_CARD,
    PROGRESS_MESSAGE_SWIPE_ERROR_RESWIPE,
    PROGRESS_MESSAGE_MAG_CARD_DATA_INSERT_CARD,
    PROGRESS_MESSAGE_CARD_INSERTED,
    PROGRESS_MESSAGE_CARD_READ_ERROR,
    PROGRESS_MESSAGE_UNKNOWN,
    PROGRESS_MESSAGE_APPLICATION_SELECTION_STARTED,
    PROGRESS_MESSAGE_APPLICATION_SELECTION_COMPLETED,
    PROGRESS_MESSAGE_CARD_HOLDER_PRESSED_CANCEL_KEY,
    PROGRESS_MESSAGE_CONTACTLESS_TRANSACTION_REVERTED_TO_CONTACT,
    PROGRESS_MESSAGE_DEVICE_BUSY,
    PROGRESS_MESSAGE_FIRST_PIN_ENTRY_PROMPT,
    PROGRESS_MESSAGE_ERROR_READING_CONTACTLESS_CARD,
    PROGRESS_MESSAGE_LAST_PIN_ENTRY_PROMPT,
    PROGRESS_MESSAGE_MULTIPLE_CONTACTLESS_CARDS_DETECTED,
    PROGRESS_MESSAGE_PIN_ENTRY_FAILED,
    PROGRESS_MESSAGE_PIN_ENTRY_IN_PROGRESS,
    PROGRESS_MESSAGE_PIN_ENTRY_SUCCESSFUL,
    PROGRESS_MESSAGE_RETRY_PIN_ENTRY_PROMPT,
    PROGRESS_MESSAGE_SWIPE_ERROR_RESWIPE_MAG_STRIPE,
    PROGRESS_MESSAGE_UPDATING_FIRMWARE,
    PROGRESS_MESSAGE_TAP_DETECTED,
    PROGRESS_MESSAGE_CONTACTLESS_CARD_STILL_IN_FIELD,
    PROGRESS_MESSAGE_FIRST_ENTER_NEW_PIN_PROMPT,
    PROGRESS_MESSAGE_VALIDATE_NEW_PIN_PROMPT,
    PROGRESS_MESSAGE_RETRY_ENTER_NEW_PIN_PROMPT,
    PROGRESS_MESSAGE_PIN_CHANGE_FAILED,
    PROGRESS_MESSAGE_PIN_CHANGE_ENDED,
    PROGRESS_MESSAGE_PLEASE_SEE_PHONE,
    PROGRESS_MESSAGE_CONTACTLESS_INTERFACE_FAILED_TRY_CONTACT,
    PROGRESS_MESSAGE_PRESENT_CARD_AGAIN,
    PROGRESS_MESSAGE_CARD_REMOVED,
    // 1.8 enums
    PROGRESS_MESSAGE_CARD_BLOCKED,
    PROGRESS_MESSAGE_NOT_AUTHORIZED,
    PROGRESS_MESSAGE_COMPLETE_CARD_REMOVE,
    PROGRESS_MESSAGE_REMOVE_CARD,
    PROGRESS_MESSAGE_INSERT_OR_SWIPE_CARD,
    PROGRESS_MESSAGE_TRANSACTION_VOID,
    PROGRESS_MESSAGE_CARD_READ_OK_REMOVE_CARD,
    PROGRESS_MESSAGE_PROCESSING_TRANSACTION,
    PROGRESS_MESSAGE_CARD_HOLDER_BYPASSED_PIN,
    PROGRESS_MESSAGE_NOT_ACCEPTED,
    PROGRESS_MESSAGE_PROCESSING_DO_NOT_REMOVE_CARD,
    PROGRESS_MESSAGE_AUTHORIZING,
    PROGRESS_MESSAGE_NOT_ACCEPTED_REMOVE_CARD,
    PROGRESS_MESSAGE_CARD_ERROR,
    PROGRESS_MESSAGE_CARD_ERROR_REMOVE_CARD,
    PROGRESS_MESSAGE_CANCELLED,
    PROGRESS_MESSAGE_CANCELLED_REMOVE_CARD,
    PROGRESS_MESSAGE_TRANSACTION_VOID_REMOVE_CARD,
    PROGRESS_MESSAGE_UNKNOWN_AID
};

#endif
