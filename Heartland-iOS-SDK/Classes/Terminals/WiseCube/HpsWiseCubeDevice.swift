import Foundation

@objcMembers
public class HpsWiseCubeDevice: GMSDevice, IWiseCubeDeviceInterface {
    public init(config: HpsConnectionConfig) {
        super.init(
            config: config,
            entryModes: [
                .contact,
                .contactless,
                .manual,
<<<<<<< HEAD
                .quickChip
=======
>>>>>>> hps/release/2.0.8
            ],
            terminalType: .bbpos_wisecube
        )
    }
}
