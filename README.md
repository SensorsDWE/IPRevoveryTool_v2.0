# IpRecoveryTool_v2.0

# IDE / Compiler / SDK

* qt-windows-opensource-5.2.0-mingw48_opengl-x86-offline.exe

* IDE : Qt Creator 3.0.0
* Qt version : 5.2.0 MinGW 32bit
* Compiler : MinGW 4.8 32bit for C++


# Debug

You need this dll :
- Qt5Cored.dll  
- Qt5Widgetsd.dll  
- Qt5Networkd.dll  
- Qt5Guid.dll  
- libgcc_s_dw2-1.dll  
- libstdc++-6.dll  
- libwinpthread-1.dll

# Installer NSIS

* Installer available in Box : Box\IP Recovery Tool - Evaltech\IpRecoveryTool_v1.0\CD_ROM_635_0867_BL\Software\Tools\nsis-2.46-setup.exe
* Script available this repository : https://github.schneider-electric.com/Sensors/IpRecoveryTool_v2.0/Appli/src/installer/NSIS_InstallerScript.nsi
     ==> VERSION (line 10) to be modified
	 ==> INSTALLER_NAME (line 13) to be adapted to your environment
	 ==> IpRecoveryTool Project shall be installed on your computer with the same locations as defined in the script
