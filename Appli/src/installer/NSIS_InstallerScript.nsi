############################################################################################
#      NSIS Installation Script created by NSIS Quick Setup Script Generator v1.09.18
#               Entirely Edited with NullSoft Scriptable Installation System                
#              by Vlasis K. Barkas aka Red Wine red_wine@freemail.gr Sep 2006               
############################################################################################

!define APP_NAME "IpRecoveryTool"
!define COMP_NAME "Schneider Electric"
!define WEB_SITE "http://www.schneider-electric.com"
!define VERSION "2.03.00.01"
!define COPYRIGHT "Schneider © 2014"
!define DESCRIPTION "Ip Recovery Tool"
!define INSTALLER_NAME "D:\Projets\SCHNEIDER\0919_RetrouveIPv2\Livraisons\v2\IpRecoveryTool_v2_3_setup.exe"
!define MAIN_APP_EXE "IpRecoveryTool.exe"
!define INSTALL_TYPE "SetShellVarContext all"
!define REG_ROOT "HKLM"
!define REG_APP_PATH "Software\Microsoft\Windows\CurrentVersion\App Paths\${MAIN_APP_EXE}"
!define UNINSTALL_PATH "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}"

!define REG_START_MENU "Start Menu Folder"

var SM_Folder

######################################################################

VIProductVersion  "${VERSION}"
VIAddVersionKey "ProductName"  "${APP_NAME}"
VIAddVersionKey "CompanyName"  "${COMP_NAME}"
VIAddVersionKey "LegalCopyright"  "${COPYRIGHT}"
VIAddVersionKey "FileDescription"  "${DESCRIPTION}"
VIAddVersionKey "FileVersion"  "${VERSION}"

######################################################################

SetCompressor ZLIB
Name "${APP_NAME}"
Caption "${APP_NAME}"
OutFile "${INSTALLER_NAME}"
BrandingText "${APP_NAME}"
XPStyle on
InstallDirRegKey "${REG_ROOT}" "${REG_APP_PATH}" ""
InstallDir "C:\IpRecoveryTool"

######################################################################

!include "MUI.nsh"

!define MUI_ABORTWARNING
!define MUI_UNABORTWARNING

!insertmacro MUI_PAGE_WELCOME

!ifdef LICENSE_TXT
!insertmacro MUI_PAGE_LICENSE "${LICENSE_TXT}"
!endif

!ifdef REG_START_MENU
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "IpRecoveryTool"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "${REG_ROOT}"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${UNINSTALL_PATH}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "${REG_START_MENU}"
!insertmacro MUI_PAGE_STARTMENU Application $SM_Folder
!endif

!insertmacro MUI_PAGE_INSTFILES

!define MUI_FINISHPAGE_RUN "$INSTDIR\${MAIN_APP_EXE}"
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM

!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_UNPAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

######################################################################

Section -Prerequisites
  MessageBox MB_OK "This tool requires WinPcap 4.1.3 or higher. $\n$\nPress OK to install it."
    SetOutPath "$INSTDIR"
    File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\Tools\WinPcap_4_1_3.exe"
    ExecWait "$INSTDIR\WinPcap_4_1_3.exe"
    Delete "$INSTDIR\WinPcap_4_1_3.exe"
SectionEnd

######################################################################

Section -MainProgram
${INSTALL_TYPE}
SetOverwrite ifnewer
SetOutPath "$INSTDIR"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\config.xml"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\icudt51.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\icuin51.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\icuuc51.dll"
File "D:\Projets\SCHNEIDER\0919_RetrouveIPv2\Livraisons\v2\IpRecoveryTool.exe"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\libgcc_s_dw2-1.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\libstdc++-6.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\libwinpthread-1.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\qminimal.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\Qt5Core.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\Qt5Gui.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\Qt5Network.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\Qt5Widgets.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\qwindows.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\qwindowsd.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\WinDump.exe"
SetOutPath "$INSTDIR\translations"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\translations\en.qm"
SetOutPath "$INSTDIR\platforms"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\platforms\qminimal.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\platforms\qminimald.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\platforms\qoffscreen.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\platforms\qoffscreend.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\platforms\qwindows.dll"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\platforms\qwindowsd.dll"
SetOutPath "$INSTDIR\imageformats"
File "D:\Projets\SCHNEIDER\0867_RetrouveIP\Livraisons\LivraisonTotaleCourrier\Software\RawExecutables\imageformats\qjpeg.dll"
SectionEnd

######################################################################

Section -Icons_Reg
SetOutPath "$INSTDIR"
WriteUninstaller "$INSTDIR\uninstall.exe"

!ifdef REG_START_MENU
!insertmacro MUI_STARTMENU_WRITE_BEGIN Application
CreateDirectory "$SMPROGRAMS\$SM_Folder"
CreateShortCut "$SMPROGRAMS\$SM_Folder\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$SMPROGRAMS\$SM_Folder\uninstall.lnk" "$INSTDIR\uninstall.exe"
CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
!ifdef WEB_SITE
WriteIniStr "$INSTDIR\${APP_NAME} website.url" "InternetShortcut" "URL" "${WEB_SITE}"
CreateShortCut "$SMPROGRAMS\$SM_Folder\${APP_NAME} Website.lnk" "$INSTDIR\${APP_NAME} website.url"
!endif
!insertmacro MUI_STARTMENU_WRITE_END
!endif

!ifndef REG_START_MENU
CreateDirectory "$SMPROGRAMS\Schneider"
CreateShortCut "$SMPROGRAMS\Schneider\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
CreateShortCut "$SMPROGRAMS\Schneider\uninstall.lnk" "$INSTDIR\uninstall.exe"
CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${MAIN_APP_EXE}"
!ifdef WEB_SITE
WriteIniStr "$INSTDIR\${APP_NAME} website.url" "InternetShortcut" "URL" "${WEB_SITE}"
CreateShortCut "$SMPROGRAMS\Schneider\${APP_NAME} Website.lnk" "$INSTDIR\${APP_NAME} website.url"
!endif
!endif

WriteRegStr ${REG_ROOT} "${REG_APP_PATH}" "" "$INSTDIR\${MAIN_APP_EXE}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "DisplayName" "${APP_NAME}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "UninstallString" "$INSTDIR\uninstall.exe"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "DisplayIcon" "$INSTDIR\${MAIN_APP_EXE}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "DisplayVersion" "${VERSION}"
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "Publisher" "${COMP_NAME}"

!ifdef WEB_SITE
WriteRegStr ${REG_ROOT} "${UNINSTALL_PATH}"  "URLInfoAbout" "${WEB_SITE}"
!endif
SectionEnd

######################################################################

Section Uninstall
${INSTALL_TYPE}
Delete "$INSTDIR\config.xml"
Delete "$INSTDIR\icudt51.dll"
Delete "$INSTDIR\icuin51.dll"
Delete "$INSTDIR\icuuc51.dll"
Delete "$INSTDIR\IpRecoveryTool.exe"
Delete "$INSTDIR\libgcc_s_dw2-1.dll"
Delete "$INSTDIR\libstdc++-6.dll"
Delete "$INSTDIR\libwinpthread-1.dll"
Delete "$INSTDIR\qminimal.dll"
Delete "$INSTDIR\Qt5Core.dll"
Delete "$INSTDIR\Qt5Gui.dll"
Delete "$INSTDIR\Qt5Network.dll"
Delete "$INSTDIR\Qt5Widgets.dll"
Delete "$INSTDIR\qwindows.dll"
Delete "$INSTDIR\qwindowsd.dll"
Delete "$INSTDIR\WinDump.exe"
Delete "$INSTDIR\translations\en.qm"
Delete "$INSTDIR\platforms\qminimal.dll"
Delete "$INSTDIR\platforms\qminimald.dll"
Delete "$INSTDIR\platforms\qoffscreen.dll"
Delete "$INSTDIR\platforms\qoffscreend.dll"
Delete "$INSTDIR\platforms\qwindows.dll"
Delete "$INSTDIR\platforms\qwindowsd.dll"
Delete "$INSTDIR\imageformats\qjpeg.dll"
 
RmDir "$INSTDIR\imageformats"
RmDir "$INSTDIR\platforms"
RmDir "$INSTDIR\translations"
 
Delete "$INSTDIR\uninstall.exe"
!ifdef WEB_SITE
Delete "$INSTDIR\${APP_NAME} website.url"
!endif

RmDir "$INSTDIR"

!ifdef REG_START_MENU
!insertmacro MUI_STARTMENU_GETFOLDER "Application" $SM_Folder
Delete "$SMPROGRAMS\$SM_Folder\${APP_NAME}.lnk"
Delete "$SMPROGRAMS\$SM_Folder\uninstall.lnk"
!ifdef WEB_SITE
Delete "$SMPROGRAMS\$SM_Folder\${APP_NAME} Website.lnk"
!endif
Delete "$DESKTOP\${APP_NAME}.lnk"

RmDir "$SMPROGRAMS\$SM_Folder"
!endif

!ifndef REG_START_MENU
Delete "$SMPROGRAMS\Schneider\${APP_NAME}.lnk"
Delete "$SMPROGRAMS\Schneider\uninstall.lnk"
!ifdef WEB_SITE
Delete "$SMPROGRAMS\Schneider\${APP_NAME} Website.lnk"
!endif
Delete "$DESKTOP\${APP_NAME}.lnk"

RmDir "$SMPROGRAMS\Schneider"
!endif

DeleteRegKey ${REG_ROOT} "${REG_APP_PATH}"
DeleteRegKey ${REG_ROOT} "${UNINSTALL_PATH}"
SectionEnd

######################################################################

