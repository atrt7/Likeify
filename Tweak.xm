#import "Likeify.h"
#include <RemoteLog.h>
#import <substrate.h>

//static id <HUBComponentLayoutManager> homeHugsLayoutManager;
//static id <HUBComponentLayoutManager> browseComponentLayoutManager;
static id <HUBComponentLayoutManager> albumComponentLayoutManager;
static SPTFreeTierAlbumViewController *albumViewController;
static NSString *bundlePrefix = @"/Library/MobileSubstrate/DynamicLibraries/com.atrt7.likeify.bundle";

/*%hook SPTHomeUIComponentLayoutManager

-(id)initWithHugsLayoutManager:(id)arg1 theme:(id)arg2 {
    id <HUBComponentLayoutManager> tempHugsLayoutManager = [[%c(HUGSComponentLayoutManager) alloc] initWithTheme:self.theme.sptTheme];
    id tempOrig = %orig(tempHugsLayoutManager, arg2);
    *homeHugsLayoutManager = &tempHugsLayoutManager;
    return tempOrig;
}

%end*/

/*%hook SPTHomeUIComponentLayoutManager

-(id)initWithHugsLayoutManager:(id)arg1 theme:(id)arg2 {
    homeHugsLayoutManager = [[%c(HUGSComponentLayoutManager) alloc] initWithTheme:arg2];
    return %orig(homeHugsLayoutManager, arg2);
}

%end*/

/*%hook SPTHubViewController

-(id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 impressionLogger:(id)arg9 loadingLogger:(id)arg10 shareDragDelegateFactory:(id)arg11 {
    if([((NSString *) arg2) isEqualToString:@"browse"]) {
        //((HUBContainerView *) (self.viewIfLoaded)).componentLayoutManager = homeHugsLayoutManager;
        browseComponentLayoutManager = [[%c(HUGSComponentLayoutManager) alloc] initWithTheme:arg1];
        //browseComponentLayoutManager = (HUGSComponentLayoutManager *) arg5;
        return %orig(arg1, arg2, arg3, arg4, browseComponentLayoutManager, arg6, arg7, arg8, arg9, arg10, arg11);
    } else {
        return %orig(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
    }
}

-(id)initWithTheme:(id)arg1 pageIdentifier:(id)arg2 pageURI:(id)arg3 componentRegistry:(id)arg4 componentLayoutManager:(id)arg5 imageLoaderFactory:(id)arg6 commandHandler:(id)arg7 viewModelProvider:(id)arg8 initialViewModel:(id)arg9 impressionLogger:(id)arg10 loadingLogger:(id)arg11 shareDragDelegateFactory:(id)arg12 {
    if([((NSString *) arg2) isEqualToString:@"browse"]) {
        //((HUBContainerView *) (self.viewIfLoaded)).componentLayoutManager = homeHugsLayoutManager;
        browseComponentLayoutManager = [[%c(HUGSComponentLayoutManager) alloc] initWithTheme:arg1];
        //browseComponentLayoutManager = (id <HUBComponentLayoutManager>) arg5;
        return %orig(arg1, arg2, arg3, arg4, browseComponentLayoutManager, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
    } else {
        return %orig(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
    }
}

%end*/

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

//- (void)configureWithModel:(id)arg1 {
//    %orig(arg1);
//}

%end

/*%hook SPTFreeTierAlbumTrackRowComponentView

%new
-(void)likeButtonClicked:(UIButton *)sender {
    sender.selected = !sender.selected;
    RLog(@"BUTTON PRESS");
}

-(id)initWithFrame:(struct CGRect)arg1 encoreComponentFactory:(id)arg2 testManager:(id)arg3 {
    SPTFreeTierAlbumTrackRowComponentView *tempOrig = %orig(arg1, arg2, arg3);
    //UIAction *likeButtonAction = [UIAction actionWithTitle:@"Foo!" image:[UIImage systemImageNamed:@"foo"] identifier:nil handler:^(__kindof UIAction* _Nonnull action) {
    //[self performMenuCommandBaz:record];
    //}]];
    //UIButton *likeButton = [UIButton buttonWithType:UIButtonTypeCustom primaryAction:likeButtonAction];
    UIButton *likeButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonUnselected" ofType:@"png"]] forState:UIControlStateNormal];
    [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonSelected" ofType:@"png"]] forState:UIControlStateSelected];
    [likeButton setImage:[UIImage imageNamed:[bundle pathForResource:@"likeButtonHighlighted" ofType:@"png"]] forState:UIControlStateHighlighted];
    [likeButton addTarget:tempOrig action:@selector(likeButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    likeButton.frame = CGRectMake(((arg1.origin.x + 10) / 2), ((arg1.origin.y + 25) / 2), 35, 35);
    likeButton.clipsToBounds = YES;
    likeButton.layer.cornerRadius = 35/2.0f;
    //button.layer.borderColor=[UIColor redColor].CGColor;
    likeButton.layer.borderWidth=2.0f;
    //likeButton.layer.borderColor = [UIColor whiteColor].CGColor;
    [tempOrig addSubview:likeButton];
    //[self bringSubviewToFront:likeButton];
    return tempOrig;
}

%end*/

/*%hook SPTTransparentAdjustableView

%new
-(void)likeButtonClicked:(UIButton *)sender {
    sender.selected = !sender.selected;
    RLog(@"BUTTON PRESS");
}

- (id)initWithFrame:(struct CGRect)arg1 {

    return %orig(arg1);
}

%end*/

/*%hook SPTUBIMobileAlbumPage_TrackList_TrackPreviewEventFactoryImplementation

+ (id)factoryWithPosition:(long long)arg1 uri:(id)arg2 components:(id)arg3 parentAbsoluteLocation:(id)arg4 {
    RLog(@"factoryWithPosition: %@, %@, %@, %@", arg1, arg2, arg3, arg4);
    return %orig(arg1, arg2, arg3, arg4);
}

- (id)initWithPosition:(long long)arg1 uri:(id)arg2 components:(id)arg3 parentAbsoluteLocation:(id)arg4 {
    RLog(@"initWithPosition: %@, %@, %@, %@", arg1, arg2, arg3, arg4);
    return %orig(arg1, arg2, arg3, arg4);
}

%end*/

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

/*- (void)resetContainerFromPoint:(struct CGPoint)arg1 subjectToInertia:(_Bool)arg2 horizontalVelocity:(double)arg3 withCompletionBlock:(id)arg4 {
    %orig(arg1, arg2, arg3, arg4);
    if(self.containerView.subviews.count != 0) {
        if(self.containerView.subviews[0].subviews.count != 0) {
            if(self.containerView.superview.superview.superview.subviews.count == 2) {
                //[self.superview.superview.subviews[1].layer addAnimation:self.containerView.layer]
                //for(id temp in [self.containerView.layer animationKeys]) {
                    //RLog(@"key: %@\tanimation: %@\n", temp, ((CASpringAnimation *) [self.containerView.layer animationForKey:temp]).fromValue);
                    //CASpringAnimation *tempAnimation = [self.containerView.layer animationForKey:temp];
                    //CASpringAnimation *likeButtonAnimation = [tempAnimation copy];
                    //[self.superview.superview.subviews[1].layer addAnimation:likeButtonAnimation forKey:temp];
                    //RLog(@"key: %@\tanimation: %@\n", temp, likeButtonAnimation);
                //}
                //RLog(@"RESET");
                //self.superview.superview.subviews[1].frame = CGRectMake((5 + likeButtonOffset), ((25) / 2), 35, 35);
                //RLog(@"1:%f", self.containerView.frame.origin.x);
                //if(!self.ongoingGesture) {
                //    self.superview.superview.subviews[1].frame = CGRectMake((5), ((25) / 2), 35, 35);
                //}
            }
        }
    }
}*/

/*- (id)shelfForOffset:(double)arg1 {
    if(self.containerView.subviews.count != 0) {
        if(self.containerView.subviews[0].subviews.count != 0) {
            if(self.containerView.superview.superview.superview.subviews.count == 2) {
                self.containerView.subviews[1].frame = CGRectMake((5 + self.containerView.frame.origin.x), ((25) / 2), 35, 35);
                //self.superview.superview.subviews[1].frame = CGRectMake((5 + likeButtonOffset), ((25) / 2), 35, 35);
                //RLog(@"1:%f", self.containerView.frame.origin.x);
                //if(!self.ongoingGesture) {
                //    self.superview.superview.subviews[1].frame = CGRectMake((5), ((25) / 2), 35, 35);
                //}
            }
        }
    }
    return %orig(arg1);
}*/

- (id)containerView {
    UIView *tempOrig = (UIView *) %orig;
    //RLog(@"containerView: %d\n", self.containerView.subviews.count);
    //RLog(@"containerView: %d\n", tempOrig.subviews.count);
    if(tempOrig.subviews.count != 0) {
        if(tempOrig.subviews[0].subviews.count != 0) {
            /*if(tempOrig.superview.superview.superview.subviews.count == 2) {
                self.superview.superview.subviews[1].frame = CGRectMake((5 + tempOrig.frame.origin.x), ((25) / 2), 35, 35);
                //self.superview.superview.subviews[1].frame = CGRectMake((5 + likeButtonOffset), ((25) / 2), 35, 35);
                RLog(@"1:%f", tempOrig.frame.origin.x);
                //if(!self.ongoingGesture) {
                //    self.superview.superview.subviews[1].frame = CGRectMake((5), ((25) / 2), 35, 35);
                //}
            }*/

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

//%hook HUGSCustomViewControl

/*- (id)initWithView:(id)arg1 onHighlightChange:(id)arg2 onSelectionChange:(id)arg3 {
    HUGSCustomViewControl *tempOrig = %orig(arg1, arg2, arg3);
    if([tempOrig.contentView isKindOfClass:%c(SPTEncoreSwipeableTableViewCell)]) {
        RLog(@"initWithView: %d", ((SPTEncoreSwipeableTableViewCell *) tempOrig.contentView).containerView.subviews.count);
    }
    return tempOrig;
}

- (id)initWithStatefulView:(id)arg1 {
    HUGSCustomViewControl *tempOrig = %orig(arg1);
    if([tempOrig.contentView isKindOfClass:%c(SPTEncoreSwipeableTableViewCell)]) {
        RLog(@"initWithStatefulView: %d", ((SPTEncoreSwipeableTableViewCell *) tempOrig.contentView).containerView.subviews.count);
    }
    return tempOrig;
}*/

//%end

/*%hook HUGSComponentLayoutManager

-(double)horizontalOffsetForComponentsWithLayoutTraits:(id)arg1 firstComponentLeadingHorizontalOffset:(double)arg2 lastComponentTrailingHorizontalOffset:(double)arg3 {
    if(self == albumComponentLayoutManager) {
        double tempOrig = %orig(arg1, arg2, arg3);
        //RLog(@"%p\t%p", self, homeHugsLayoutManager);
        return tempOrig + 30;
    } else {
        return %orig;
    }
}

%end*/