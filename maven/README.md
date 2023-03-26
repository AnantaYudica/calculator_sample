

## Install
- install maven
-  install jdk
- install visual studio (MSVC) for windows

## Build
### Windows
- run cmd
- run ```vcvars64.bat``` or ```vcvars32.bat``` in {VISUAL STUDIO}\VC\Auxiliary\Build 
- append to INCLUDE in Enviroment with {JDK_HOME}/include and {JDK_HOME}/include/win32
- run ```mvn clean package```

### Mac

### Linux

## Run 
```java -jar {workspaceFolder}/maven/build/calculator_app-{version}.jar```
