const http = require('http')
const fs = require('fs')

const host = 'localhost';
const port = 80;

const index_html_path = __dirname + '/index.html'
const calc_wasm_path = __dirname + '/calculatorBind.wasm'
const calc_js_path = __dirname + '/calculatorBind.js'

var index_read = fs.readFileSync(index_html_path)
var index_stat = fs.statSync(index_html_path)
var calc_wasm_read = fs.readFileSync(calc_wasm_path)
var calc_wasm_stat = fs.statSync(calc_wasm_path)
var calc_js_read = fs.readFileSync(calc_js_path)
var calc_js_stat = fs.statSync(calc_js_path)

function getIndex()
{
    var curr_stat = fs.statSync(index_html_path)
    if (curr_stat.mtimeMs > index_stat.mtimeMs)
    {
        index_read = fs.readFileSync(index_html_path)
        index_stat = curr_stat
    }
    return index_read;
}

function getCalcWasm()
{
    var curr_stat = fs.statSync(calc_wasm_path)
    if (curr_stat.mtimeMs > calc_wasm_stat.mtimeMs)
    {
        calc_wasm_read = fs.readFileSync(calc_wasm_path)
        calc_wasm_stat = curr_stat
    }
    return calc_wasm_read;
}

function getCalcJs()
{
    var curr_stat = fs.statSync(calc_js_path)
    if (curr_stat.mtimeMs > calc_js_stat.mtimeMs)
    {
        calc_js_read = fs.readFileSync(calc_js_path)
        calc_js_stat = curr_stat
    }
    return calc_js_read;
}

const requestListener = function (req, res) 
{
    console.log(req.url);
    if (req.url === '/calculatorBind.wasm')
    {
        res.setHeader("Content-Type", "application/wasm");
        res.writeHead(200);
        res.end(getCalcWasm());
    }
    else if (req.url === '/calculatorBind.js')
    {
        
        res.setHeader("Content-Type", "text/javascript");
        res.writeHead(200);
        res.end(getCalcJs());
    }
    else
    {
        res.setHeader("Content-Type", "text/html");
        res.writeHead(200);
        res.end(getIndex());
    }
}

const server = http.createServer(requestListener)

server.listen(port, host, () => {
    console.log(`Server is running on http://${host}:${port}`)
});

