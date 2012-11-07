//
//  RDActivityViewController.h
//  APOD
//
//  Created by Robert Dougan on 11/5/12.
//  Copyright (c) 2012 Robert Dougan. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RDActivityViewControllerDelegate.h"

@interface RDActivityViewController : UIActivityViewController <UIActivityItemSource>

@property (nonatomic, assign) id <RDActivityViewControllerDelegate> delegate;

- (id)initWithDelegate:(id <RDActivityViewControllerDelegate>)delegate;
- (id)initWithDelegate:(id)delegate maximumNumberOfItems:(int)maximumNumberOfItems;

@end
