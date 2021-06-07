#import "Likeify.h"
#include <RemoteLog.h>
#import <substrate.h>

static id <HUBComponentLayoutManager> albumComponentLayoutManager;
static SPTFreeTierAlbumViewController *albumViewController;
static NSString *bundlePrefix = @"/Library/MobileSubstrate/DynamicLibraries/com.atrt7.likeify.bundle";

%hook SPTFreeTierAlbumViewController

-(id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 impressionLogger:(id)arg9 loadingLogger:(id)arg10 ubiLogger:(id)arg11 feedbackButtonViewModel:(id)arg12 contextMenuButtonViewModel:(id)arg13 player:(id)arg14 offlineModel:(id)arg15 shareDragDelegateFactory:(id)arg16 pageInstanceIdProvider:(id)arg17 {
    if([((NSString *) arg2) isEqualToString:@"free-tier-album"]) {
        //((HUBContainerView *) (self.viewIfLoaded)).componentLayoutManager = homeHugsLayoutManager;
        albumComponentLayoutManager = [[%c(HUGSComponentLayoutManager) alloc] initWithTheme:arg1];
        SPTFreeTierAlbumViewController *tempOrig = %orig(arg1, arg2, arg3, arg4, albumComponentLayoutManager, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
        albumViewController = tempOrig;
        return tempOrig; 
    } else {
        return %orig(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
    }
}

%end

%hook SPTFreeTierAlbumUBILogger

- (id)logSwipeLeftLikeWithPosition:(long long)arg1 targetURI:(id)arg2 {
    NSString *tempOrig = %orig(arg1, arg2);
    RLog(@"arg1: %ld\targ2: %@\treturn: %@", arg1, arg2, tempOrig);
    return tempOrig;
}

%end

%hook SPTEncoreSwipeableTableViewCell

%new
-(void)likeButtonClicked:(UIButton *)sender {
    sender.selected = !sender.selected;
    //int index = MSHookIvar<HUBComponentModelImplementation *>(self.superview.superview, "_model").index;
    //NSURL *trackURI = [albumViewController.contextMenuButtonViewModel.albumViewModel.albumTracks objectAtIndex:index];
    //RLog(@"BUTTON:\t%@\n", [((SPTFreeTierAlbumUBILogger *) albumViewController.ubiLogger) logSwipeLeftLikeWithPosition:index targetURI:trackURI]);
    //RLog(@"BUTTON:\t%@\n", ((SPTask *) [albumViewController.contextMenuButtonViewModel createLikeAllTracksTask]).completedError);
    //[%c(SPTask) [[SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactoryImplementation factoryWithPosition:nil uri:nil components:nil parentAbsoluteLocation:nil] swipeLikeWithItemToBeLiked:trackURI] performWork: onQueue:];
    //RLog(@"BUTTON PRESS\t%@\n", trackURI);
}

- (id)containerView {
    UIView *tempOrig = (UIView *) %orig;
    if(tempOrig.subviews.count != 0) {
        if(tempOrig.subviews[0].subviews.count != 0) {

            if(tempOrig.subviews[0].subviews.count < 2) {
                CGRect tempFrame = tempOrig.subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].frame;
                tempOrig.subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].subviews[0].bounds = CGRectMake((tempFrame.origin.x - 30), tempFrame.origin.y, tempFrame.size.width, tempFrame.size.height);
                NSBundle *bundle = [[NSBundle alloc] initWithPath:bundlePrefix];
                UIButton *likeButton = [UIButton buttonWithType:UIButtonTypeCustom];
                [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonUnselected" ofType:@"png"]] forState:UIControlStateNormal];
                [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonSelected" ofType:@"png"]] forState:UIControlStateSelected];
                [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonHighlighted" ofType:@"png"]] forState:UIControlStateHighlighted];
                [likeButton addTarget:self action:@selector(likeButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
                likeButton.frame = CGRectMake(((tempOrig.frame.origin.x + 10) / 2), ((tempOrig.frame.origin.y + 25) / 2), 35, 35);
                likeButton.clipsToBounds = YES;
                likeButton.layer.cornerRadius = 35/2.0f;
                //button.layer.borderColor=[UIColor redColor].CGColor;
                likeButton.layer.borderWidth=2.0f;
                //likeButton.layer.borderColor = [UIColor whiteColor].CGColor;
                [tempOrig.subviews[0] addSubview:likeButton];
            }

        }

    }
    return tempOrig;
}

%end

%hook SPTUBIMobileAlbumPage_TrackList_TrackRowEventFactoryImplementation

- (id)swipeLikeWithItemToBeLiked:(id)arg1 {
    UBIInteractionEvent *tempOrig = %orig(arg1);
    RLog(@"LIKED: %@", tempOrig.errors);
    return tempOrig;
}

%end