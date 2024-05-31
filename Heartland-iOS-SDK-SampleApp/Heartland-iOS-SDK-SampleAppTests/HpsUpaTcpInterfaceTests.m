//
//  HpsUpaTcpInterfaceTests.m
//  Heartland-iOS-SDK-SampleAppTests
//
//  Created by Desimini, Wilson on 3/13/24.
//

#import <XCTest/XCTest.h>
#import <Heartland_iOS_SDK/HpsTerminalUtilities.h>
#import <Heartland_iOS_SDK/HpaEnums.h>
#import <Heartland_iOS_SDK/UpaEnums.h>
#import <Heartland_iOS_SDK/HpsUpaRequest.h>
#import <Heartland_iOS_SDK/HpsConnectionConfig.h>
#import <Heartland_iOS_SDK/HpsTcpInterface.h>
#import <Heartland_iOS_SDK/HpsUpaTcpInterface.h>
#import <Heartland_iOS_SDK/MBUPAErrorType.h>

// MARK: - Mocks

@interface MockHpsTcpInterface : HpsTcpInterface

@property (nonatomic, copy) void (^sendDataOnOpenBlock)(NSData *, BOOL);

@end

@implementation MockHpsTcpInterface

- (void)openConnection {
    [self.delegate tcpInterfaceDidOpenStream];
}

- (void)sendData:(NSData *)data onOpen:(BOOL)onOpen {
    if (_sendDataOnOpenBlock) {
        _sendDataOnOpenBlock(data, onOpen);
    }
    [self.delegate tcpInterfaceDidWriteData];
}

@end

@interface HpsUpaTcpInterface ()

- (instancetype)initWithInterface:(HpsTcpInterface *)interface;

@end

// MARK: - Tests

@interface HpsUpaTcpInterfaceTests : XCTestCase

@end

@implementation HpsUpaTcpInterfaceTests

- (void)test_send_concurrentMessageErrorOnNextSend {
    // given
    HpsConnectionConfig *config = [[HpsConnectionConfig alloc] init];
    config.shouldFailConcurrentMessaging = YES;
    MockHpsTcpInterface *tcp1 = [[MockHpsTcpInterface alloc] init];
    tcp1.config = config;
    MockHpsTcpInterface *tcp2 = [[MockHpsTcpInterface alloc] init];
    tcp2.config = config;
    HpsUpaTcpInterface *upaTcp1 = [[HpsUpaTcpInterface alloc] initWithInterface:tcp1];
    HpsUpaTcpInterface *upaTcp2 = [[HpsUpaTcpInterface alloc] initWithInterface:tcp2];
    HpsUpaRequest *request = [[HpsUpaRequest alloc] init];
    request.message = @"MSG";
    id<IHPSDeviceMessage> message = [HpsTerminalUtilities BuildRequest:request.JSONString
                                                            withFormat:UPA];
    
    // when
    XCTestExpectation *expectation1 = [self expectationWithDescription:@"invoke send 1"];
    expectation1.expectedFulfillmentCount = 2;
    [tcp1 setSendDataOnOpenBlock:^(NSData *data, BOOL onOpen) {
        // then
        XCTAssertNotNil(data);
        XCTAssertTrue(onOpen);
        [expectation1 fulfill];
    }];
    [upaTcp1 send:message andUPAResponseBlock:^(JsonDoc *json, NSError *error) {
        // then
        XCTAssertEqual(error.code, MBUPAErrorTypeConnectionForceClose);
        [expectation1 fulfill];
    }];
    XCTestExpectation *expectation2 = [self expectationWithDescription:@"block send 2 w error"];
    [tcp2 setSendDataOnOpenBlock:^(NSData *data, BOOL onOpen) {
        // then
        XCTFail(@"tcp2 sent data");
    }];
    [upaTcp2 send:message andUPAResponseBlock:^(JsonDoc *json, NSError *error) {
        // then
        XCTAssertEqual(error.code, MBUPAErrorTypeConcurrentMessages);
        [expectation2 fulfill];
    }];
    dispatch_async(dispatch_get_main_queue(), ^{
        [upaTcp1 disconnect];
        [upaTcp2 disconnect];
    });
    [self waitForExpectations:@[expectation1, expectation2]];
    
    // when send 1 all done with..
    expectation2 = [self expectationWithDescription:@"invoke send 2"];
    expectation2.expectedFulfillmentCount = 2;
    [tcp2 setSendDataOnOpenBlock:^(NSData *data, BOOL onOpen) {
        // then
        XCTAssertNotNil(data);
        XCTAssertTrue(onOpen);
        [expectation2 fulfill];
    }];
    [upaTcp2 send:message andUPAResponseBlock:^(JsonDoc *json, NSError *error) {
        // then
        XCTAssertEqual(error.code, MBUPAErrorTypeConnectionForceClose);
        [expectation2 fulfill];
    }];
    dispatch_async(dispatch_get_main_queue(), ^{
        [upaTcp2 disconnect];
    });
    [self waitForExpectations:@[expectation2]];
}

- (void)test_send_NextSendIfConcurrentMessagesAllowed {
    // given
    HpsConnectionConfig *config = [[HpsConnectionConfig alloc] init];
    config.shouldFailConcurrentMessaging = NO;
    MockHpsTcpInterface *tcp1 = [[MockHpsTcpInterface alloc] init];
    tcp1.config = config;
    MockHpsTcpInterface *tcp2 = [[MockHpsTcpInterface alloc] init];
    tcp2.config = config;
    HpsUpaTcpInterface *upaTcp1 = [[HpsUpaTcpInterface alloc] initWithInterface:tcp1];
    HpsUpaTcpInterface *upaTcp2 = [[HpsUpaTcpInterface alloc] initWithInterface:tcp2];
    HpsUpaRequest *request = [[HpsUpaRequest alloc] init];
    request.message = @"MSG";
    id<IHPSDeviceMessage> message = [HpsTerminalUtilities BuildRequest:request.JSONString
                                                            withFormat:UPA];

    // when
    XCTestExpectation *expectation1 = [self expectationWithDescription:@"send 1"];
    expectation1.expectedFulfillmentCount = 2;
    [tcp1 setSendDataOnOpenBlock:^(NSData *data, BOOL onOpen) {
        // then
        XCTAssertNotNil(data);
        XCTAssertTrue(onOpen);
        [expectation1 fulfill];
    }];
    [upaTcp1 send:message andUPAResponseBlock:^(JsonDoc *json, NSError *error) {
        // then
        XCTAssertEqual(error.code, MBUPAErrorTypeConnectionForceClose);
        [expectation1 fulfill];
    }];
    XCTestExpectation *expectation2 = [self expectationWithDescription:@"send 2"];
    expectation2.expectedFulfillmentCount = 2;
    [tcp2 setSendDataOnOpenBlock:^(NSData *data, BOOL onOpen) {
        // then
        XCTAssertNotNil(data);
        XCTAssertTrue(onOpen);
        [expectation2 fulfill];
    }];
    [upaTcp2 send:message andUPAResponseBlock:^(JsonDoc *json, NSError *error) {
        // then
        XCTAssertEqual(error.code, MBUPAErrorTypeConnectionForceClose);
        [expectation2 fulfill];
    }];
    dispatch_async(dispatch_get_main_queue(), ^{
        [upaTcp1 disconnect];
        [upaTcp2 disconnect];
    });
    [self waitForExpectations:@[expectation1, expectation2]];
}

@end
