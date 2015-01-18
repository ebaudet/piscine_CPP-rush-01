# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 17:40:16 by gpetrov           #+#    #+#              #
#    Updated: 2015/01/18 17:31:57 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MAKEFILE      = Makefile

# config parameters

PROJECT_NAME  = ft_gkrellm
DIR_PROJECT   = .
DIR_QT		  = ~/Applications/Qt/5.4
DIR_XCODE_APP = /Applications/Xcode.app

####### Compiler, tools and options
CC            = gcc
CXX           = g++
DEFINES       = -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -isysroot $(DIR_XCODE_APP)/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -mmacosx-version-min=10.7 -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -g -isysroot $(DIR_XCODE_APP)/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -mmacosx-version-min=10.7 -Wall -W -fPIE $(DEFINES)
INCPATH       = -I $(DIR_QT)/clang_64/mkspecs/macx-clang -I$(DIR_PROJECT) -I $(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers -I $(DIR_QT)/clang_64/lib/QtGui.framework/Versions/5/Headers -I $(DIR_QT)/clang_64/lib/QtCore.framework/Versions/5/Headers -I. -I $(DIR_XCODE_APP)/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I $(DIR_XCODE_APP)/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -I. -F $(DIR_QT)/clang_64/lib
QMAKE         = $(DIR_QT)/clang_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = $(PROJECT_NAME)1.0.0
DISTDIR 	  = .tmp/$(PROJECT_NAME)1.0.0
LINK          = g++
LFLAGS        = -headerpad_max_install_names -Wl,-syslibroot,$(DIR_XCODE_APP)/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -mmacosx-version-min=10.7 -Wl,-rpath,$(DIR_QT)/clang_64/lib
LIBS          = $(SUBLIBS) -F $(DIR_QT)/clang_64/lib -framework QtWidgets -framework QtGui -framework QtCore -framework DiskArbitration -framework IOKit -framework OpenGL -framework AGL -lncurses
AR            = $(DIR_XCODE_APP)/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ar cq
RANLIB        = $(DIR_XCODE_APP)/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib -s
SED           = sed
STRIP         = 

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = $(DIR_PROJECT)/main.cpp \
		$(DIR_PROJECT)/Qtwindow.cpp moc_Qtwindow.cpp
OBJECTS       = main.o \
		Qtwindow.o \
		moc_Qtwindow.o
DIST          = $(DIR_QT)/clang_64/mkspecs/features/spec_pre.prf \
		$(DIR_QT)/clang_64/mkspecs/qdevice.pri \
		$(DIR_QT)/clang_64/mkspecs/features/device_config.prf \
		$(DIR_QT)/clang_64/mkspecs/common/shell-unix.conf \
		$(DIR_QT)/clang_64/mkspecs/common/unix.conf \
		$(DIR_QT)/clang_64/mkspecs/common/mac.conf \
		$(DIR_QT)/clang_64/mkspecs/common/macx.conf \
		$(DIR_QT)/clang_64/mkspecs/common/gcc-base.conf \
		$(DIR_QT)/clang_64/mkspecs/common/gcc-base-mac.conf \
		$(DIR_QT)/clang_64/mkspecs/common/clang.conf \
		$(DIR_QT)/clang_64/mkspecs/common/clang-mac.conf \
		$(DIR_QT)/clang_64/mkspecs/qconfig.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bluetooth.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_clucene_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_concurrent.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_core.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_core_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_dbus.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_dbus_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_declarative.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_declarative_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designer.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designer_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_enginio.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_enginio_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_gui.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_gui_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_help.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_help_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_location.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_location_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_macextras.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_macextras_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimedia.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_network.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_network_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_nfc.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_nfc_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_opengl.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_opengl_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_openglextensions.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_positioning.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_positioning_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_printsupport.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qml.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qml_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmltest.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quick.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quick_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_script.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_script_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_scripttools.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sensors.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sensors_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_serialport.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_serialport_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sql.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sql_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_svg.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_svg_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_testlib.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_testlib_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_uitools.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_uitools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webchannel.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webengine.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webengine_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginecore.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkit.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkit_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_websockets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_websockets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webview.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webview_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_widgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_widgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xml.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xml_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		$(DIR_QT)/clang_64/mkspecs/features/qt_functions.prf \
		$(DIR_QT)/clang_64/mkspecs/features/qt_config.prf \
		$(DIR_QT)/clang_64/mkspecs/macx-clang/qmake.conf \
		$(DIR_QT)/clang_64/mkspecs/features/spec_post.prf \
		$(DIR_QT)/clang_64/mkspecs/features/exclusive_builds.prf \
		$(DIR_QT)/clang_64/mkspecs/features/default_pre.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/default_pre.prf \
		$(DIR_QT)/clang_64/mkspecs/features/resolve_config.prf \
		$(DIR_QT)/clang_64/mkspecs/features/default_post.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/sdk.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/default_post.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/objective_c.prf \
		$(DIR_QT)/clang_64/mkspecs/features/warn_on.prf \
		$(DIR_QT)/clang_64/mkspecs/features/qt.prf \
		$(DIR_QT)/clang_64/mkspecs/features/resources.prf \
		$(DIR_QT)/clang_64/mkspecs/features/moc.prf \
		$(DIR_QT)/clang_64/mkspecs/features/unix/opengl.prf \
		$(DIR_QT)/clang_64/mkspecs/features/uic.prf \
		$(DIR_QT)/clang_64/mkspecs/features/unix/thread.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/rez.prf \
		$(DIR_QT)/clang_64/mkspecs/features/testcase_targets.prf \
		$(DIR_QT)/clang_64/mkspecs/features/exceptions.prf \
		$(DIR_QT)/clang_64/mkspecs/features/yacc.prf \
		$(DIR_QT)/clang_64/mkspecs/features/lex.prf \
		$(DIR_PROJECT)/$(PROJECT_NAME).pro $(DIR_PROJECT)/Qtwindow.h $(DIR_PROJECT)/main.cpp \
		$(DIR_PROJECT)/Qtwindow.cpp
QMAKE_TARGET  = $(PROJECT_NAME)
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = $(PROJECT_NAME)

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-isysroot \
		$(DIR_XCODE_APP)/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk \
		-mmacosx-version-min=10.7 \
		-Wall \
		-W



first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET): ui_qtwindow.h $(OBJECTS)  
	@test -d $(PROJECT_NAME).app/Contents/MacOS/ || mkdir -p $(PROJECT_NAME).app/Contents/MacOS/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: $(DIR_PROJECT)/$(PROJECT_NAME).pro $(DIR_QT)/clang_64/mkspecs/macx-clang/qmake.conf $(DIR_QT)/clang_64/mkspecs/features/spec_pre.prf \
		$(DIR_QT)/clang_64/mkspecs/qdevice.pri \
		$(DIR_QT)/clang_64/mkspecs/features/device_config.prf \
		$(DIR_QT)/clang_64/mkspecs/common/shell-unix.conf \
		$(DIR_QT)/clang_64/mkspecs/common/unix.conf \
		$(DIR_QT)/clang_64/mkspecs/common/mac.conf \
		$(DIR_QT)/clang_64/mkspecs/common/macx.conf \
		$(DIR_QT)/clang_64/mkspecs/common/gcc-base.conf \
		$(DIR_QT)/clang_64/mkspecs/common/gcc-base-mac.conf \
		$(DIR_QT)/clang_64/mkspecs/common/clang.conf \
		$(DIR_QT)/clang_64/mkspecs/common/clang-mac.conf \
		$(DIR_QT)/clang_64/mkspecs/qconfig.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bluetooth.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_clucene_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_concurrent.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_core.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_core_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_dbus.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_dbus_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_declarative.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_declarative_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designer.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designer_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_enginio.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_enginio_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_gui.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_gui_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_help.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_help_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_location.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_location_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_macextras.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_macextras_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimedia.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_network.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_network_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_nfc.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_nfc_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_opengl.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_opengl_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_openglextensions.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_positioning.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_positioning_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_printsupport.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qml.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qml_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmltest.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quick.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quick_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_script.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_script_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_scripttools.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sensors.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sensors_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_serialport.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_serialport_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sql.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sql_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_svg.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_svg_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_testlib.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_testlib_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_uitools.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_uitools_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webchannel.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webengine.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webengine_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginecore.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkit.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkit_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_websockets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_websockets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webview.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webview_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_widgets.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_widgets_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xml.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xml_private.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		$(DIR_QT)/clang_64/mkspecs/features/qt_functions.prf \
		$(DIR_QT)/clang_64/mkspecs/features/qt_config.prf \
		$(DIR_QT)/clang_64/mkspecs/macx-clang/qmake.conf \
		$(DIR_QT)/clang_64/mkspecs/features/spec_post.prf \
		$(DIR_QT)/clang_64/mkspecs/features/exclusive_builds.prf \
		$(DIR_QT)/clang_64/mkspecs/features/default_pre.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/default_pre.prf \
		$(DIR_QT)/clang_64/mkspecs/features/resolve_config.prf \
		$(DIR_QT)/clang_64/mkspecs/features/default_post.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/sdk.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/default_post.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/objective_c.prf \
		$(DIR_QT)/clang_64/mkspecs/features/warn_on.prf \
		$(DIR_QT)/clang_64/mkspecs/features/qt.prf \
		$(DIR_QT)/clang_64/mkspecs/features/resources.prf \
		$(DIR_QT)/clang_64/mkspecs/features/moc.prf \
		$(DIR_QT)/clang_64/mkspecs/features/unix/opengl.prf \
		$(DIR_QT)/clang_64/mkspecs/features/uic.prf \
		$(DIR_QT)/clang_64/mkspecs/features/unix/thread.prf \
		$(DIR_QT)/clang_64/mkspecs/features/mac/rez.prf \
		$(DIR_QT)/clang_64/mkspecs/features/testcase_targets.prf \
		$(DIR_QT)/clang_64/mkspecs/features/exceptions.prf \
		$(DIR_QT)/clang_64/mkspecs/features/yacc.prf \
		$(DIR_QT)/clang_64/mkspecs/features/lex.prf \
		$(DIR_PROJECT)/$(PROJECT_NAME).pro \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/QtWidgets.prl \
		$(DIR_QT)/clang_64/lib/QtGui.framework/QtGui.prl \
		$(DIR_QT)/clang_64/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -spec macx-clang CONFIG+=debug CONFIG+=x86_64 -o Makefile $(DIR_PROJECT)/$(PROJECT_NAME).pro
		$(DIR_QT)/clang_64/mkspecs/features/spec_pre.prf:
		$(DIR_QT)/clang_64/mkspecs/qdevice.pri:
		$(DIR_QT)/clang_64/mkspecs/features/device_config.prf:
		$(DIR_QT)/clang_64/mkspecs/common/shell-unix.conf:
		$(DIR_QT)/clang_64/mkspecs/common/unix.conf:
		$(DIR_QT)/clang_64/mkspecs/common/mac.conf:
		$(DIR_QT)/clang_64/mkspecs/common/macx.conf:
		$(DIR_QT)/clang_64/mkspecs/common/gcc-base.conf:
		$(DIR_QT)/clang_64/mkspecs/common/gcc-base-mac.conf:
		$(DIR_QT)/clang_64/mkspecs/common/clang.conf:
		$(DIR_QT)/clang_64/mkspecs/common/clang-mac.conf:
		$(DIR_QT)/clang_64/mkspecs/qconfig.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bluetooth.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_clucene_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_concurrent.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_concurrent_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_core.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_core_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_dbus.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_dbus_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_declarative.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_declarative_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designer.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designer_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_enginio.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_enginio_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_gui.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_gui_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_help.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_help_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_location.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_location_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_macextras.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_macextras_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimedia.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimedia_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_network.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_network_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_nfc.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_nfc_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_opengl.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_opengl_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_openglextensions.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_positioning.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_positioning_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_printsupport.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_printsupport_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qml.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qml_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmltest.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qmltest_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quick.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quick_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickwidgets.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_script.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_script_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_scripttools.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_scripttools_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sensors.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sensors_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_serialport.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_serialport_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sql.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_sql_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_svg.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_svg_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_testlib.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_testlib_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_uitools.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_uitools_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webchannel.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webchannel_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webengine.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webengine_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginecore.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkit.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkit_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_websockets.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_websockets_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webview.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_webview_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_widgets.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_widgets_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xml.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xml_private.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
		$(DIR_QT)/clang_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
		$(DIR_QT)/clang_64/mkspecs/features/qt_functions.prf:
		$(DIR_QT)/clang_64/mkspecs/features/qt_config.prf:
		$(DIR_QT)/clang_64/mkspecs/macx-clang/qmake.conf:
		$(DIR_QT)/clang_64/mkspecs/features/spec_post.prf:
		$(DIR_QT)/clang_64/mkspecs/features/exclusive_builds.prf:
		$(DIR_QT)/clang_64/mkspecs/features/default_pre.prf:
		$(DIR_QT)/clang_64/mkspecs/features/mac/default_pre.prf:
		$(DIR_QT)/clang_64/mkspecs/features/resolve_config.prf:
		$(DIR_QT)/clang_64/mkspecs/features/default_post.prf:
		$(DIR_QT)/clang_64/mkspecs/features/mac/sdk.prf:
		$(DIR_QT)/clang_64/mkspecs/features/mac/default_post.prf:
		$(DIR_QT)/clang_64/mkspecs/features/mac/objective_c.prf:
		$(DIR_QT)/clang_64/mkspecs/features/warn_on.prf:
		$(DIR_QT)/clang_64/mkspecs/features/qt.prf:
		$(DIR_QT)/clang_64/mkspecs/features/resources.prf:
		$(DIR_QT)/clang_64/mkspecs/features/moc.prf:
		$(DIR_QT)/clang_64/mkspecs/features/unix/opengl.prf:
		$(DIR_QT)/clang_64/mkspecs/features/uic.prf:
		$(DIR_QT)/clang_64/mkspecs/features/unix/thread.prf:
		$(DIR_QT)/clang_64/mkspecs/features/mac/rez.prf:
		$(DIR_QT)/clang_64/mkspecs/features/testcase_targets.prf:
		$(DIR_QT)/clang_64/mkspecs/features/exceptions.prf:
		$(DIR_QT)/clang_64/mkspecs/features/yacc.prf:
		$(DIR_QT)/clang_64/mkspecs/features/lex.prf:
$(DIR_PROJECT)/$(PROJECT_NAME).pro:
	$(DIR_QT)/clang_64/lib/QtWidgets.framework/QtWidgets.prl:
	$(DIR_QT)/clang_64/lib/QtGui.framework/QtGui.prl:
	$(DIR_QT)/clang_64/lib/QtCore.framework/QtCore.prl:
qmake: FORCE
	@$(QMAKE) -spec macx-clang CONFIG+=debug CONFIG+=x86_64 -o Makefile $(DIR_PROJECT)/$(PROJECT_NAME).pro

qmake_all: FORCE

$(PROJECT_NAME).app/Contents/PkgInfo: 
	@test -d $(PROJECT_NAME).app/Contents || mkdir -p $(PROJECT_NAME).app/Contents
	@$(DEL_FILE) $(PROJECT_NAME).app/Contents/PkgInfo
	@echo "APPL????" >$(PROJECT_NAME).app/Contents/PkgInfo
$(PROJECT_NAME).app/Contents/Resources/empty.lproj: 
	@test -d $(PROJECT_NAME).app/Contents/Resources || mkdir -p $(PROJECT_NAME).app/Contents/Resources
	@touch $(PROJECT_NAME).app/Contents/Resources/empty.lproj
	
$(PROJECT_NAME).app/Contents/Info.plist: 
	@test -d $(PROJECT_NAME).app/Contents || mkdir -p $(PROJECT_NAME).app/Contents
	@$(DEL_FILE) $(PROJECT_NAME).app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@FULL_VERSION@,1.0.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@BUNDLEIDENTIFIER@,com.yourcompany.$(PROJECT_NAME),g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,$(PROJECT_NAME),g" -e "s,@TYPEINFO@,????,g" $(DIR_QT)/clang_64/mkspecs/macx-clang/Info.plist.app >$(PROJECT_NAME).app/Contents/Info.plist

all: Makefile \
		$(PROJECT_NAME).app/Contents/PkgInfo \
		$(PROJECT_NAME).app/Contents/Resources/empty.lproj \
		$(PROJECT_NAME).app/Contents/Info.plist $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents $(DIR_PROJECT)/Qtwindow.h $(DISTDIR)/
	$(COPY_FILE) --parents $(DIR_PROJECT)/main.cpp $(DIR_PROJECT)/Qtwindow.cpp $(DISTDIR)/
	$(COPY_FILE) --parents $(DIR_PROJECT)/qtwindow.ui $(DISTDIR)/


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core

fclean: clean
	-$(DEL_FILE) $(PROJECT_NAME)
	-$(DEL_FILE) -r $(PROJECT_NAME).app

distclean: clean 
	-$(DEL_FILE) -r $(PROJECT_NAME).app
#	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_Qtwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Qtwindow.cpp
moc_Qtwindow.cpp: $(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QMainWindow \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/qmainwindow.h \
		$(DIR_PROJECT)/Qtwindow.h
		$(DIR_QT)/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -I $(DIR_QT)/clang_64/mkspecs/macx-clang -I ~/rendu/cplusplus_piscine/$(PROJECT_NAME)01/github -I $(DIR_QT)/clang_64/lib/QtWidgets.framework/Headers -I $(DIR_QT)/clang_64/lib/QtGui.framework/Headers -I $(DIR_QT)/clang_64/lib/QtCore.framework/Headers -I. -F $(DIR_QT)/clang_64/lib $(DIR_PROJECT)/Qtwindow.h -o moc_Qtwindow.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_qtwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_qtwindow.h
ui_qtwindow.h: $(DIR_PROJECT)/qtwindow.ui
	$(DIR_QT)/clang_64/bin/uic $(DIR_PROJECT)/qtwindow.ui -o ui_qtwindow.h

compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: $(DIR_PROJECT)/main.cpp $(DIR_PROJECT)/Qtwindow.h \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QMainWindow \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/qmainwindow.h \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QApplication \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/qapplication.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o $(DIR_PROJECT)/main.cpp

Qtwindow.o: $(DIR_PROJECT)/Qtwindow.cpp $(DIR_PROJECT)/Qtwindow.h \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/QMainWindow \
		$(DIR_QT)/clang_64/lib/QtWidgets.framework/Versions/5/Headers/qmainwindow.h \
		ui_qtwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Qtwindow.o $(DIR_PROJECT)/Qtwindow.cpp

moc_Qtwindow.o: moc_Qtwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Qtwindow.o moc_Qtwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
