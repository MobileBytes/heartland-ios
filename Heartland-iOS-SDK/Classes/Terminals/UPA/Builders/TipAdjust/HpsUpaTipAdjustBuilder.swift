//
//  HpsUpaTipAdjustBuilder.swift
//  Heartland-iOS-SDK
//

import Foundation

enum HpsUpaTipAdjustBuilderError: LocalizedError {
    case invalidRequest
    
    var errorDescription: String? {
        switch self {
        case .invalidRequest:
            return "Invalid HpsUpaTipAdjust request submitted"
        }
    }
}

public class HpsUpaTipAdjustBuilder {
    private var upaDevice: HpsUpaDevice

    public init(with device: HpsUpaDevice) {
        upaDevice = device
    }

    public func execute(request: HpsUpaTipAdjust, completion: @escaping (HpsUpaResponse?, Error?) -> Void) {
        if let requestData = try? JSONEncoder().encode(request),
           let requestString = String(data: requestData, encoding: .utf8) {
            upaDevice.processTransaction(withJSONString: requestString) { response, str, error in
                completion(response as? HpsUpaResponse, error)
            }
        } else {
            completion(nil, HpsUpaTipAdjustBuilderError.invalidRequest)
        }
    }
}
