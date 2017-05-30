#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T21:43:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrawingApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DrawingArea.cpp \
    LineContainer.cpp \
    src/AnError.cpp \
    src/AREF.cpp \
    src/BinDataTypeReader.cpp \
    src/Boundary.cpp \
    src/Box.cpp \
    src/Element.cpp \
    src/GDSIIDesign.cpp \
    src/GDSIIDesignReader.cpp \
    src/GDSIIRecord.cpp \
    src/GDSIISourceConsole.cpp \
    src/GDSIISourceTXT.cpp \
    src/GlobalOptions.cpp \
    src/GUIClient.cpp \
    src/LayerForView.cpp \
    src/Node.cpp \
    src/Path.cpp \
    src/Record00_Header.cpp \
    src/record01_bgnlib.cpp \
    src/record02_libname.cpp \
    src/Record03_Units.cpp \
    src/record04_endlib.cpp \
    src/Record05_Bgnstr.cpp \
    src/record06_strname.cpp \
    src/Record07_Endstr.cpp \
    src/record08_boundary.cpp \
    src/Record09_Path.cpp \
    src/record10_sref.cpp \
    src/Record11_Aref.cpp \
    src/record12_text.cpp \
    src/Record13_Layer.cpp \
    src/record14_datatype.cpp \
    src/Record15_Width.cpp \
    src/Record16_XY.cpp \
    src/Record17_Endel.cpp \
    src/record18_sname.cpp \
    src/Record19_Colrow.cpp \
    src/record20_textnode.cpp \
    src/Record21_Node.cpp \
    src/record22_texttype.cpp \
    src/Record23_Presentation.cpp \
    src/record24_spacing.cpp \
    src/Record25_String.cpp \
    src/record26_strans.cpp \
    src/Record27_Mag.cpp \
    src/record28_angle.cpp \
    src/Record31_Reflibs.cpp \
    src/record32_fonts.cpp \
    src/Record33_Pathtype.cpp \
    src/record34_generations.cpp \
    src/Record35_Attrtable.cpp \
    src/record36_styptable.cpp \
    src/Record37_Strtype.cpp \
    src/record38_elflags.cpp \
    src/Record39_Elkey.cpp \
    src/record40_linktype.cpp \
    src/Record41_Linkeys.cpp \
    src/record42_nodetype.cpp \
    src/Record43_Propattr.cpp \
    src/record44_propvalue.cpp \
    src/Record45_Box.cpp \
    src/record46_boxtype.cpp \
    src/Record47_Plex.cpp \
    src/record48_bgnextn.cpp \
    src/Record49_Endextn.cpp \
    src/record50_tapenum.cpp \
    src/Record51_Tapecode.cpp \
    src/record52_strclass.cpp \
    src/Record53_Reserved.cpp \
    src/record54_format.cpp \
    src/Record55_Mask.cpp \
    src/record56_endmasks.cpp \
    src/Record57_Libdirsize.cpp \
    src/record58_srfname.cpp \
    src/Record59_Libsecur.cpp \
    src/RecordSupplier.cpp \
    src/SourceFactory.cpp \
    src/SREF.cpp \
    src/Structure.cpp \
    src/Text.cpp \
    src/GDSIIBinSource.cpp

HEADERS  += mainwindow.h \
    DrawingArea.h \
    LineContainer.h \
    src/ACL.h \
    src/AnError.h \
    src/AREF.h \
    src/BinDataTypeReader.h \
    src/Boundary.h \
    src/Box.h \
    src/Element.h \
    src/GDSIIDesign.h \
    src/GDSIIDesignReader.h \
    src/GDSIIRecord.h \
    src/GDSIISourceConsole.h \
    src/GDSIISourceTXT.h \
    src/GlobalOptions.h \
    src/GUIClient.h \
    src/IGDSIISource.h \
    src/LayerForView.h \
    src/Node.h \
    src/Path.h \
    src/Point.h \
    src/Record00_Header.h \
    src/record01_bgnlib.h \
    src/record02_libname.h \
    src/Record03_Units.h \
    src/record04_endlib.h \
    src/Record05_Bgnstr.h \
    src/record06_strname.h \
    src/Record07_Endstr.h \
    src/record08_boundary.h \
    src/Record09_Path.h \
    src/record10_sref.h \
    src/Record11_Aref.h \
    src/record12_text.h \
    src/Record13_Layer.h \
    src/record14_datatype.h \
    src/Record15_Width.h \
    src/Record16_XY.h \
    src/Record17_Endel.h \
    src/record18_sname.h \
    src/Record19_Colrow.h \
    src/record20_textnode.h \
    src/Record21_Node.h \
    src/record22_texttype.h \
    src/Record23_Presentation.h \
    src/record24_spacing.h \
    src/Record25_String.h \
    src/record26_strans.h \
    src/Record27_Mag.h \
    src/record28_angle.h \
    src/Record31_Reflibs.h \
    src/record32_fonts.h \
    src/Record33_Pathtype.h \
    src/record34_generations.h \
    src/Record35_Attrtable.h \
    src/record36_styptable.h \
    src/Record37_Strtype.h \
    src/record38_elflags.h \
    src/Record39_Elkey.h \
    src/record40_linktype.h \
    src/Record41_Linkeys.h \
    src/record42_nodetype.h \
    src/Record43_Propattr.h \
    src/record44_propvalue.h \
    src/Record45_Box.h \
    src/record46_boxtype.h \
    src/Record47_Plex.h \
    src/record48_bgnextn.h \
    src/Record49_Endextn.h \
    src/record50_tapenum.h \
    src/Record51_Tapecode.h \
    src/record52_strclass.h \
    src/Record53_Reserved.h \
    src/record54_format.h \
    src/Record55_Mask.h \
    src/record56_endmasks.h \
    src/Record57_Libdirsize.h \
    src/record58_srfname.h \
    src/Record59_Libsecur.h \
    src/RecordSupplier.h \
    src/SourceFactory.h \
    src/SREF.h \
    src/Structure.h \
    src/Text.h \
    src/GDSIIBinSource.h

FORMS    += mainwindow.ui
