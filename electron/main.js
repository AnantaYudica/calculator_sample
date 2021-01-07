const { app, BrowserWindow } = require('electron')

function createWindow () {
  const win = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      nodeIntegration: true
    }
  })

  win.loadFile(`./dist/index.html`)
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

const hello = require('./build/Release/hello');
const calculator = require('./build/Release/calculator-intf');

console.log(hello.hello())
console.log(calculator)

calculator.initialization(
  function(){
    console.log(arguments[0])
})
console.log("init")

calculator.input("1");
