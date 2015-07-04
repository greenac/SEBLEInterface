//
//  SEBLEInterfaceManager.h
//  SEBLEInterface
//
//  Created by Andre Green on 6/14/15.
//  Copyright (c) 2015 Andre Green. All rights reserved.
//

#import <Foundation/Foundation.h>

@import CoreBluetooth;
@import QuartzCore;

@class SEBLEInterfaceMangager;
@class SEBLEPeripheral;

@protocol SEBLEInterfaceManagerDelegate <NSObject>

- (void)bleInterfaceManager:(SEBLEInterfaceMangager *)interfaceManager didUpdateDeviceValues:(NSDictionary *)values;
- (void)bleInterfaceManager:(SEBLEInterfaceMangager *)interfaceManger discoveredPeripheral:(SEBLEPeripheral *)peripheral;
- (void)bleInterfaceManager:(SEBLEInterfaceMangager *)interfaceManager connectPeripheral:(SEBLEPeripheral *)peripheral;
- (void)bleInterfaceManager:(SEBLEInterfaceMangager *)interfaceManager removePeripheral:(SEBLEPeripheral *)peripheral;

@end

@interface SEBLEInterfaceMangager : NSObject<CBCentralManagerDelegate, CBPeripheralDelegate>

@property (nonatomic, weak) id<SEBLEInterfaceManagerDelegate>delegate;

+ (id)manager;
- (void)addPeripheralNamed:(NSString *)name;
- (void)removePeripheralNamed:(NSString *)name;
- (void)writeToPeripheralWithUDID:(NSString *)peripheralUUID
                      serviceUUID:(NSString *)serviceUUID
               characteristicUUID:(NSString *)characteristicUUID
                             data:(NSData *)data;
- (void)startScan;
- (void)stopScan;

// remove me...just for testing
- (void)runTests;
@end
