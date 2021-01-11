import { Component } from '@angular/core';
import { IpcRenderer } from 'electron';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'calculator-sample';

  private ipc;
  constructor(){
    if ((<any>window).require) {
      try {
        this.ipc = (<any>window).require('electron').ipcRenderer;
        this.ipc.on('update_display', async (event : any, result : string) => {
          console.log("call update_display")
          var out = document.getElementById('display_output');
          if (out != null)
          {
            const cast_out = <HTMLInputElement>out;
            cast_out.value = result;
          }
        });
      } catch (e) {
        throw e;
      }
    } else {
      console.warn('App not running inside Electron!');
    }
  }
  btn_zero()
  {
    this.ipc.send("btn_zero");
  }
  btn_one()
  {
    this.ipc.send("btn_one");
  }
  btn_two()
  {
    this.ipc.send("btn_two");
  }
  btn_three()
  {
    this.ipc.send("btn_three");
  }
  btn_four()
  {
    this.ipc.send("btn_four");
  }
  btn_five()
  {
    this.ipc.send("btn_five");
  }
  btn_six()
  {
    this.ipc.send("btn_six");
  }
  btn_seven()
  {
    this.ipc.send("btn_seven");
  }
  btn_eight()
  {
    this.ipc.send("btn_eight");
  }
  btn_nine()
  {
    this.ipc.send("btn_nine");
  }
  btn_comma()
  {
    this.ipc.send("btn_comma");
  }
  btn_div()
  {
    this.ipc.send("btn_div");
  }
  btn_mul()
  {
    this.ipc.send("btn_mul");
  }
  btn_sub()
  {
    this.ipc.send("btn_sub");
  }
  btn_sum()
  {
    this.ipc.send("btn_sum");
  }
  btn_ans()
  {
    this.ipc.send("btn_ans");
  }
}

