//
//  AppDelegate.h
//  SoundCleod
//
//  Created by Márton Salomváry on 2012/12/11.
//  Copyright (c) 2012 Márton Salomváry. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>
#import "PopupController.h"
#import "UrlPromptController.h"
#import "../SPMediaKeyTap/SPMediaKeyTap.h"
#import "../DHSwipeWebView/DHSwipeWebView.h"
#import "AppDelegate.h"

extern NSURL *baseUrl;

@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate> {
    SPMediaKeyTap *keyTap;
}

@property (assign) IBOutlet NSWindow *window;
@property (weak) IBOutlet DHSwipeWebView *webView;
@property (weak) IBOutlet PopupController *popupController;
@property (weak) IBOutlet UrlPromptController *urlPromptController;

- (WebView *)webView:(WebView *)sender createWebViewWithRequest:(NSURLRequest *)request;
- (void)webView:(WebView *)sender decidePolicyForNavigationAction:(NSDictionary *)actionInformation
        request:(NSURLRequest *)request frame:(WebFrame *)frame decisionListener:(id)listener;
- (void)webView:(WebView *)webView decidePolicyForNewWindowAction:(NSDictionary *)actionInformation request:(NSURLRequest *)request newFrameName:(NSString *)frameName decisionListener:(id < WebPolicyDecisionListener >)listener;

- (void)receiveSleepNotification:(NSNotification*)note;

- (void)next;
- (void)prev;
- (void)playPause;
- (void)help;
- (void)trigger:(int)keyCode;
- (BOOL)isPlaying;

- (void)navigate:(NSString*)permalink;
- (IBAction)showHelp:(id)sender;
+ (BOOL)isSCURL:(NSURL *)url;

@end
