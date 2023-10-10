//
//
//  HpsUPASAFTests.swift
//  Heartland-iOS-SDK-SampleAppTests
//

import Foundation
@testable import Heartland_iOS_SDK
import XCTest

class HpsUPASAFTests: XCTestCase {
    private func setupDevice() -> HpsUpaDevice? {
        let config = HpsConnectionConfig()
        config.username = "701420636"
        config.password = "$Test1234"
        config.licenseID = "145801"
        config.siteID = "145898"
        config.deviceID = "90916202"
        config.ipAddress = "192.168.1.213"
        config.port = "8081"
        config.connectionMode = HpsConnectionModes.TCP_IP.rawValue
        return HpsUpaDevice(config: config)
    }

    func testSendSAFExecute() {
        let expectation = XCTestExpectation(description: "Wait for execution...")
        let device = setupDevice()

        guard let device else {
            XCTFail("Device is nil")
            return
        }

        let builder = HpsUpaSAFTransactionBuilder(with: device)

        let sendSAF = HpsUpaSendSaf(data: HpsUpaCommandPayloadNoData(command: HpsUpaSendSafConstants.command, requestId: "123", ecrId: "123"))

        builder.execute(request: sendSAF) { response, safResponse, error in
            XCTAssertNotNil(response)
            XCTAssertNotNil(safResponse)
            XCTAssertNil(error)

            expectation.fulfill()
        }

        wait(for: [expectation], timeout: 1000)
    }

    func testGetSAFExecute() {
        let expectation = XCTestExpectation(description: "Wait for execution...")
        let device = setupDevice()

        guard let device else {
            XCTFail("Device is nil")
            return
        }

        let builder = HpsUpaSAFTransactionBuilder(with: device)

        let getSAF = HpsUpaGetSaf(data: HpsUpaCommandPayload(command: HpsUpaGetSafConstants.command, ecrId: "123", requestId: "123", data: HpsUpaGetSafData(params: HpsUpaGetSafDataReportOutput(reportOutput: "ReturnData"))))

        builder.execute(request: getSAF) { response, safResponse, error in
            XCTAssertNotNil(response)
            XCTAssertNotNil(safResponse)
            XCTAssertNil(error)

            expectation.fulfill()
        }

        wait(for: [expectation], timeout: 1000)
    }

    func testUPASAFResponseFromData() throws {
        let raw = MBUPASAFMockPayload.responseRaw
        let data = try XCTUnwrap(raw.data(using: .utf8))
        let response = try JSONDecoder().decode(HpsUpaSafResponse.self, from: data)
        XCTAssertEqual(response.data?.data?.safDetails?.count, 3)
    }

    func testDeleteSAFExecute() {
        let expectation = XCTestExpectation(description: "Wait for execution...")
        let device = setupDevice()

        guard let device else {
            XCTFail("Device is nil")
            return
        }
        
        let builder = HpsUpaSAFTransactionBuilder(with: device)
        
        let deleteSAF = HpsUpaDeleteSaf(data: HpsUpaCommandPayload(
            command: HpsUpaDeleteSafConstants.command,
            ecrId: "123",
            requestId: "123",
            data: HpsUpaDeleteSafData.init(transaction: HpsUpaDeleteSafTransaction.init(tranNo: "1", safReferenceNumber: "11"))
        ))
        
        builder.execute(request: deleteSAF, response: { response, deleteSafResponse, error in
            XCTAssertNotNil(response)
            XCTAssertNotNil(deleteSafResponse)
            XCTAssertNil(error)

            expectation.fulfill()
        })
        
        wait(for: [expectation], timeout: 1000)
    }
}

fileprivate enum MBUPASAFMockPayload {
    static let responseRaw =
"""
{
    "data":
    {
        "EcrId": "1",
        "cmdResult":
        {
            "result": "Success"
        },
        "data":
        {
            "SafDetails":
            [
                {
                    "SafCount": "1",
                    "SafRecords":
                    [
                        {
                            "baseAmount": "10.00",
                            "cardAcquisition": "INSERT",
                            "cardType": "MasterCard",
                            "clerkId": "1234",
                            "invoiceNbr": "1",
                            "maskedPan": "541333******4111",
                            "referenceNumber": "1844276576",
                            "responseCode": "00",
                            "responseText": "APPROVAL",
                            "safReferenceNumber": "P0000006",
                            "surcharge": "0.00",
                            "taxAmount": "0.00",
                            "tipAmount": "0.00",
                            "totalAmount": "10.00",
                            "tranNo": "0006",
                            "transactionTime": "03/06/23 12:24 AM",
                            "transactionType": "1"
                        }
                    ],
                    "SafTotal": "0",
                    "SafType": "AUTHORIZED TRANSACTIONS"
                },
                {
                    "SafCount": "1",
                    "SafRecords":
                    [
                        {
                            "baseAmount": "10.33",
                            "cardAcquisition": "SWIPE",
                            "cardType": "Visa",
                            "clerkId": "1234",
                            "invoiceNbr": "1",
                            "maskedPan": "531717******0008",
                            "responseCode": "00",
                            "surcharge": "0.00",
                            "taxAmount": "0.00",
                            "tipAmount": "0.00",
                            "totalAmount": "10.33",
                            "tranNo": "0009",
                            "transactionTime": "02/01/23 2:52 PM",
                            "transactionType": "1"
                        }
                    ],
                    "SafTotal": "5.00",
                    "SafType": "PENDING TRANSACTIONS"
                },
                {
                    "SafCount": "1",
                    "SafRecords":
                    [
                        {
                            "baseAmount": "10.11",
                            "cardAcquisition": "SWIPE",
                            "cardType": "MasterCard",
                            "clerkId": "1234",
                            "invoiceNbr": "1",
                            "maskedPan": "531717******0008",
                            "referenceNumber": "1844346664",
                            "responseCode": "00",
                            "responseText": "CHIP READ REQ INSERT CARD",
                            "safReferenceNumber": "P0000002",
                            "surcharge": "0.00",
                            "taxAmount": "0.00",
                            "tipAmount": "0.00",
                            "totalAmount": "10.11",
                            "tranNo": "0005",
                            "transactionTime": "03/05/23 11:11 PM",
                            "transactionType": "1"
                        }
                    ],
                    "SafTotal": "10.11",
                    "SafType": "FAILED TRANSACTIONS"
                }
            ],
            "multipleMessage": "0"
        },
        "message": "MSG",
        "requestId": "1",
        "response": "GetSAFReport"
    }
}
"""
}
