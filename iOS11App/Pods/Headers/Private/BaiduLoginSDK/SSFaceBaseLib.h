//
//  SSFaceBaseLib.h
//  SSDKLib
//
//  Created by Gong,Jialiang on 2022/3/2.
//  Copyright © 2022 bang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
// SSDK
#import "SSFaceDetectionManager.h"

__attribute__((visibility("default")))
@interface SSFaceBaseLib : NSObject

+ (instancetype)sharedInstance;

// 更新属性
- (void)setDetectManager:(SSFaceDetectionManager *)manager;

- (void)setAudioBufferQueue:(dispatch_queue_t)queue;

- (void)setVideoBufferQueue:(dispatch_queue_t)queue;

- (void)connectPreviewLayer:(AVCaptureVideoPreviewLayer *)pLayer;

// 配置操作摄像头
- (void)openCamera;

- (void)closeCamera;

- (BOOL)sessionIsRunning;

- (void)updateSessionConfiguration:(void(^)())block;

- (void)updateSessionPresent:(NSString *)present;

- (void)addVideoDataOutput;

- (NSDictionary *)videoOutputSettings;

- (void)addAudioDevice;

- (AVCaptureConnection *)configConnection;

- (void)removeSessionConfig;

- (void)configCamerasInputWithError:(NSError **)error;

- (BOOL)addInputDeviceInputWithPosition:(AVCaptureDevicePosition)position;

- (void)changeCameraPosition:(AVCaptureDevicePosition)position;

- (void)cancelRecorderWriting;

- (void)configureVideoWriter:(BOOL)recordAudio fileURL:(NSURL *)fileURL imageWidth:(NSNumber *)imageWidth imageHeight:(NSNumber *)imageHeight;

- (void)faceCaptureVideoWithCaptureOutput:(AVCaptureOutput *)captureOutput sampleBuffer:(CMSampleBufferRef)sampleBuffer connection:(AVCaptureConnection *)connection;

- (void)stopRecordingVideoWithSuccessHandler:(void(^)())successCompletion failHandler:(void(^)())failCompletion;

// IDL调用
- (void)setIDLEnableSound:(BOOL)enableSound;

- (void)resetIDL;

- (void)idlLivenessWithImage:(UIImage *)image previewRect:(CGRect)previewRect detectRect:(CGRect)detectRect completionHandler:(SSLivenessNormalCompletion)completion;

- (void)idlDetectWithImage:(UIImage *)image previewRect:(CGRect)previewRect detectRect:(CGRect)detectRect completionHandler:(SSDetectStrategyCompletion)completion;

- (NSDictionary *)faceInfoToDictionary:(id)faceInfo;

- (NSDictionary *)faceCropImageInfoToDictionary:(id)cropInfo;

- (NSString *)faceCropImageInfoOriginalImageEncryptStr:(id)cropInfo;

- (NSString *)faceCropImageInfoCropImageWithBlackEncryptStr:(id)cropInfo;

@end


