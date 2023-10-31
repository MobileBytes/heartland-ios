//
//  HpsUPAStartCardTests.swift
//  Heartland-iOS-SDK-SampleAppTests
//

import Foundation
@testable import Heartland_iOS_SDK
import XCTest

class HpsStartCardLoggerMock: NSObject, HpsInterfaceLogging {
    func hpsInterfaceDidDisconnect() {
    }

    func hpsInterfaceDidReceive(_ data: Data!) {
        let description = String(data: data, encoding: .utf8) ?? ""
        print("hpsInterfaceDidReceive - \(String(data: data, encoding: .utf8) ?? "")")
    }

    func hpsInterfaceDidReceiveError(_ error: Error!) {
        let description = error.localizedDescription
        print("hpsInterfaceDidReceiveError - \(description)")
    }

    func willLogHPSInterface(with config: HpsConnectionConfig!) {
    }
}

class HpsUPAStartCardTests: XCTestCase {
    private func setupDevice() -> HpsUpaDevice? {
        let config = HpsConnectionConfig()
        config.username = ""
        config.password = ""
        config.licenseID = ""
        config.siteID = ""
        config.deviceID = ""
        config.ipAddress = "192.168.4.127"
        config.port = "8081"
        config.connectionMode = HpsConnectionModes.TCP_IP.rawValue
        config.logger = HpsStartCardLoggerMock()
        return HpsUpaDevice(config: config)
    }

    func testStartCardAcquisitionTypesSerialization() throws {
        /// 1 valid type
        try verifyEncoding([.manual], "Manual")
        /// multiple valid types
        try verifyEncoding([.manual, .swipe], "Manual|Swipe")
        /// all valid types
        try verifyEncoding([.contact, .contactless, .manual, .scan, .swipe], "Contact|Contactless|Manual|Scan|Swipe")
        /// empty
        try verifyEncoding([], "")
    }
    
    private func verifyEncoding(
        _ acquisitionTypes: [HpsUpaStartCardParamsAcquisitionType],
        _ expectedRawAcquisitionTypes: String
    ) throws {
        let params = HpsUpaStartCardParams(acquisitionTypes: acquisitionTypes)
        let dataFromParams = try JSONEncoder().encode(params)
        let objFromParams = try JSONSerialization.jsonObject(with: dataFromParams)
        let jsonFromParams = try XCTUnwrap(objFromParams as? [String: Any])
        XCTAssertEqual(jsonFromParams["acquisitionTypes"] as? String, expectedRawAcquisitionTypes)
    }
    
    func testStartCardExecute() {
        let expectation = XCTestExpectation(description: "Wait for execution...")
        let device = setupDevice()

        guard let device else {
            XCTFail("Device is nil")
            return
        }

        let builder = HpsUpaStartCardTransactionBuilder(with: device)
        
        let params = HpsUpaStartCardParams(acquisitionTypes: [.swipe],
                                           timeout: nil,
                                           header: nil,
                                           displayTotalAmount: nil,
                                           promptForManualEntryPassword: nil,
                                           brandIcon1: nil,
                                           brandIcon2: nil)

        let pi = HpsUpaStartCardProcessingIndicators(quickChip: "Y",
                                                     checkLuhn: nil,
                                                     securityCode: nil,
                                                     cardTypeFilter: nil)

        let tx = HpsUpaStartCardTransaction(totalAmount: "1.24",
                                            cashBackAmount: nil,
                                            tranDate: nil,
                                            tranTime: nil,
                                            transactionType: "Sale")

        let data = HpsUpaCommandPayload<HpsUpaStartCardDataDetails>(
            command: HpsUpaStartCardConstants.command,
            ecrId: "123",
            requestId: "1234",
            data: HpsUpaStartCardDataDetails(
                params: params,
                processingIndicators: pi,
                transaction: tx
            )
        )

        let request = HpsUpaStartCard(data: data)

        builder.execute(request: request) { upaResponse, error in
            XCTAssertNotNil(upaResponse)
            XCTAssertNil(error)

            expectation.fulfill()
        }

        wait(for: [expectation], timeout: 1000)
    }
}
