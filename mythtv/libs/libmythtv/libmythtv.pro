######################################################################
# Automatically generated by qmake (1.02a) Tue Jul 16 20:40:47 2002
######################################################################

TEMPLATE = lib
TARGET = mythtv
CONFIG += thread staticlib 

include ( ../../settings.pro )

INCLUDEPATH += ../libNuppelVideo ../
TARGETDEPS = ../libNuppelVideo/libNuppelVideo.a

installfiles.path = $${PREFIX}/share/mythtv
installfiles.files = FreeSans.ttf
installfiles.files += settings.txt

INSTALLS = installfiles
 
# Input
HEADERS += channel.h frequencies.h tv.h recordingprofile.h ../libNuppelVideo/osd.h
HEADERS += ../libNuppelVideo/NuppelVideoPlayer.h 
HEADERS += ../libNuppelVideo/NuppelVideoRecorder.h
SOURCES += channel.cpp frequencies.c tv.cpp recordingprofile.cpp
