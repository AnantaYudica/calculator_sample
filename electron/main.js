const { app, BrowserWindow, ipcMain} = require('electron')
const hello = require('./build/Release/hello');
const calculator = require('./build/Release/calculator-intf');

function createWindow () {
  const win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    }
  })

  win.loadFile(`./dist/index.html`)
  const contents = win.webContents
  calculator.initialization(
    function(value){
      console.log("call val : " + value)
      contents.send("update_display", value)
  })
}

app.whenReady().then(createWindow)

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow()
  }
})


console.log(hello.hello())
console.log(calculator)

ipcMain.handle('display', (event)=> {
  return display_value
})

console.log("init")

ipcMain.on('btn_zero', (event, arg) => {
  calculator.input("0");
})

ipcMain.on('btn_one', (event, arg) => {
  calculator.input("1");
})

ipcMain.on('btn_two', (event, arg) => {
  calculator.input("2");
})

ipcMain.on('btn_three', (event, arg) => {
  calculator.input("3");
})

ipcMain.on('btn_four', (event, arg) => {
  calculator.input("4");
})

ipcMain.on('btn_five', (event, arg) => {
  calculator.input("5");
})

ipcMain.on('btn_six', (event, arg) => {
  calculator.input("6");
})

ipcMain.on('btn_seven', (event, arg) => {
  calculator.input("7");
})

ipcMain.on('btn_eight', (event, arg) => {
  calculator.input("8");
})

ipcMain.on('btn_nine', (event, arg) => {
  calculator.input("9");
})

ipcMain.on('btn_comma', (event, arg) => {
  calculator.input(".");
})

ipcMain.on('btn_div', (event, arg) => {
  calculator.input("/");
})

ipcMain.on('btn_mul', (event, arg) => {
  calculator.input("*");
})

ipcMain.on('btn_sub', (event, arg) => {
  calculator.input("-");
})

ipcMain.on('btn_sum', (event, arg) => {
  calculator.input("+");
})

ipcMain.on('btn_ans', (event, arg) => {
  calculator.input("=");
})



