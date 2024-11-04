//
//  HpsUPATipAdjustBuilderTests.swift
//  Heartland-iOS-SDK-SampleAppTests
//

import Foundation
@testable import Heartland_iOS_SDK
import XCTest

class HpsUPATipAdjustBuilderTests: XCTestCase {
    
    private func setupDevice() -> HpsUpaDevice? {
        let config = HpsConnectionConfig()
        config.ipAddress = "192.168.31.107"
        config.port = "8081"
        config.connectionMode = HpsConnectionModes.TCP_IP.rawValue
        return HpsUpaDevice(config: config)
    }
}
