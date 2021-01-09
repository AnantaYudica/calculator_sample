const exec = require('child_process').execSync;
const os = require('os');
const path = require("path");

const ng = path.join(process.cwd() , "../angular/node_modules/.bin/ng")
const out_path = path.join(process.cwd(), "dist")
const base_href = path.join(process.cwd(), "dist/")
const angular_base_dir = path.join(process.cwd() , "../angular")

exec(ng + " b calculator-sample --output-path " + out_path + 
    " --base-href " + base_href, {'stdio': 'inherit', "cwd": angular_base_dir})
