TARGET := iphone:clang:latest:13.0
ARCHS = arm64 arm64e
INSTALL_TARGET_PROCESSES = Spotify
THEOSDEVICEIP = 192.168.254.67

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = Likeify

Likeify_FILES = Tweak.xm
Likeify_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

BUNDLE_NAME = com.atrt7.likeify
com.atrt7.likeify_INSTALL_PATH = /Library/MobileSubstrate/DynamicLibraries

include $(THEOS_MAKE_PATH)/bundle.mk

after-install::
	install.exec "killall -9 SpringBoard"
