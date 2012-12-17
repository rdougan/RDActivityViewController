# RDActivityViewController

This is a simple override of [UIActivityViewController](http://developer.apple.com/library/ios/#documentation/UIKit/Reference/UIActivityViewController_Class/Reference/Reference.html%23//apple_ref/occ/cl/UIActivityViewController) which makes it easier to set multiple items for each UIActivityType.

## Usage

* Add all files into your Xcode project.

* Import `RDActivityViewController.h` into your project:
    
        #import "RDActivityViewController.h";

* Set your class as a `RDActivityViewControllerDelegate` delegate:

        ...
    
        @interface MyClass : NSObject <RDActivityViewControllerDelegate>
    
        ...

* Implement the required `activityViewController:activityViewController itemsForActivityType:activityType` method in the delegate. You should always return an `NSArray` of [activityItems](http://developer.apple.com/library/ios/#documentation/UIKit/Reference/UIActivityViewController_Class/Reference/Reference.html%23//apple_ref/occ/cl/UIActivityViewController):

        - (NSArray *)activityViewController:(NSArray *)activityViewController itemsForActivityType:(NSString *)activityType {
            if ([activityType isEqualToString:UIActivityTypeMail]) {
                return @[
                    @"This is the message which appears",
                    @"...in the mail sharing dialog.",
                    [UIImage imageName:@"an-image.png"]
                ];
            } else {
                return @[@"Default message"];
            }
        }

* And finally, create the RDActivityViewController:

        RDActivityViewController *viewController = [[RDActivityViewController alloc] initWithDelegate:self];

## Using with custom application activities

To use a custom activity, you can call `[[RDActivityViewController alloc] initWithDelegate:self maximumNumberOfItems:numItems applicationActivities:appActivities placeholderItem:defaultPlaceholder];`
    
This lets you share items that might not be sharable with particular activity types (e.g. some UIActivity implementations may only accept NSURL, AVAsset, etc.. objects.)

For example, using [TUSafariActivity](https://github.com/davbeck/TUSafariActivity) to open an item in Safari:

```
UIActivity *safariActivity = [[TUSafariActivity alloc] init];

RDActivityViewController *viewController = [[RDActivityViewController alloc] initWithDelegate:viewControllerDelegate maximumNumberOfItems:10 applicationActivities:@[safariActivity] placeholderItem:[NSURL URLWithString:@"http://github.com"]];

```

Of course, you can still replace the placeholder item in your delegate method.