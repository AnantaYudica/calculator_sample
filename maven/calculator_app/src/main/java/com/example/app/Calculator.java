package com.example.app;
import java.awt.event.*;  
import javax.swing.*;

public class Calculator {
    
    private static Calculator ms_instance = null;

    public native String print();
    public native int key(String val);

    private JTextField m_output;

    static
    {
        System.loadLibrary("calculator_jni");
    }

    private Calculator() {
        m_output = new JTextField();
    }

    public static synchronized Calculator getInstance()
    {
        if (ms_instance == null)
        {
            ms_instance = new Calculator();
        }
  
        return ms_instance;
    }

    JTextField getOutput()
    {
        return m_output;
    }

    public static void main( String[] args )
    {
        Calculator calc = Calculator.getInstance();
        JFrame frame = new JFrame("Calculator");
        getInstance().getOutput().setBounds(5, 5, 370, 30);
        getInstance().getOutput().setHorizontalAlignment(JTextField.TRAILING);
        getInstance().getOutput().setEditable(false);
        getInstance().getOutput().setText(calc.print());
        frame.add(getInstance().getOutput());
        JButton[] keys = {
            new JButton("0"),
            new JButton("1"),
            new JButton("2"),
            new JButton("3"),
            new JButton("4"),
            new JButton("5"),
            new JButton("6"),
            new JButton("7"),
            new JButton("8"),
            new JButton("9"),
        };
        int key_w = 70;
        int key_h = 70;
        keys[7].setBounds(5 + (key_w * 0) + (5 * 0), 40 + (key_h * 0), key_w, key_h);
        keys[8].setBounds(5 + (key_w * 1) + (5 * 1), 40 + (key_h * 0), key_w, key_h);
        keys[9].setBounds(5 + (key_w * 2) + (5 * 2), 40 + (key_h * 0), key_w, key_h);
        
        keys[4].setBounds(5 + (key_w * 0) + (5 * 0), 40 + (key_h * 1) + (5 * 1), key_w, key_h);
        keys[5].setBounds(5 + (key_w * 1) + (5 * 1), 40 + (key_h * 1) + (5 * 1), key_w, key_h);
        keys[6].setBounds(5 + (key_w * 2) + (5 * 2), 40 + (key_h * 1) + (5 * 1), key_w, key_h);
        
        keys[1].setBounds(5 + (key_w * 0) + (5 * 0), 40 + (key_h * 2) + (5 * 2), key_w, key_h);
        keys[2].setBounds(5 + (key_w * 1) + (5 * 1), 40 + (key_h * 2) + (5 * 2), key_w, key_h);
        keys[3].setBounds(5 + (key_w * 2) + (5 * 2), 40 + (key_h * 2) + (5 * 2), key_w, key_h);
        
        keys[0].setBounds(5 + (key_w * 0) + (5 * 0), 40 + (key_h * 3) + (5 * 3), key_w, key_h);
        
        keys[0].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("0");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[1].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("1");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[2].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("2");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[3].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("3");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[4].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("4");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[5].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("5");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[5].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("5");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[6].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("6");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[7].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("7");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[8].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("8");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        keys[9].addActionListener(new ActionListener(){  
            public void actionPerformed(ActionEvent e){  
                Calculator.getInstance().key("9");
                getInstance().getOutput().setText(Calculator.getInstance().print());
            }  
        });  
        for(JButton b : keys)
        {
            frame.add(b);
        }


        frame.setSize(400,400);
        frame.setResizable(false);
        frame.setLayout(null);
        frame.setVisible(true); 
        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
