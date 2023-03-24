
##

### Download & Install emsdk 
https://emscripten.org/docs/getting_started/downloads.html Open the link and follow the instructions

### Build c++ source into calculator lib
`emcc ../src/Calculator.cpp -I../include -c -o calculator.o`

### Build bind source and link calculator lib into wasm + js
`emcc -lembind src/Bind.cxx calculator.o -I../include -o calculatorBind.js`

### Install server
`npm install`

### Run server
`npm start`
