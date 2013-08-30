LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := mokoid_2d.cpp surfaceflinger.cpp
LOCAL_MODULE := mysurface

#LOCAL_SHARED_LIBRARIES := libEGL libGLESv1_CM libui
LOCAL_SHARED_LIBRARIES := libsurfaceflinger

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

include $(BUILD_EXECUTABLE)
