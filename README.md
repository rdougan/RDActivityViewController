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
