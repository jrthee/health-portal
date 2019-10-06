using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace BodyMassIndex
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double bmi;
            double vazn = double.Parse(numericUpDown2.Value.ToString());
            double ghad2 = Math.Pow(double.Parse(numericUpDown1.Value.ToString()), 2);
            bmi = vazn / ghad2;
            if (bmi.ToString().Length > 5)
            {
                textBox1.Text = (vazn / ghad2).ToString().Remove(5);
            }
            else
            {
                textBox1.Text = (vazn / ghad2).ToString();
            }
            if (bmi < 16.5 && bmi > 11)
            {
                label15.Visible = true;
                label16.Visible = false;
                label17.Visible = false;
                label18.Visible = false;
                label19.Visible = false;
            }
            else if (bmi < 18.5 && bmi > 16.5)
            {
                label15.Visible = false;
                label16.Visible = true;
                label17.Visible = false;
                label18.Visible = false;
                label19.Visible = false;
            }
            else if (bmi < 25 && bmi > 18.5)
            {
                label15.Visible = false;
                label16.Visible = false;
                label17.Visible = true;
                label18.Visible = false;
                label19.Visible = false;
            }
            else if (bmi < 30 && bmi > 25)
            {
                label15.Visible = false;
                label16.Visible = false;
                label17.Visible = false;
                label18.Visible = true;
                label19.Visible = false;
            }
            else if (bmi > 30)
            {
                label15.Visible = false;
                label16.Visible = false;
                label17.Visible = false;
                label18.Visible = true;
                label19.Visible = false;
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 0)
            {
                label14.Text = "22";
            }
            else if (comboBox1.SelectedIndex == 1)
            {
                label14.Text = "23";
            }
            else if (comboBox1.SelectedIndex == 2)
            {
                label14.Text = "24";
            }
            else if (comboBox1.SelectedIndex == 3)
            {
                label14.Text = "25";
            }
            else if (comboBox1.SelectedIndex == 4)
            {
                label14.Text = "26";
            }
            else if (comboBox1.SelectedIndex == 5)
            {
                label14.Text = "27";
            }
        }
        
        //FeetToMeters
        private void button3_Click(object sender, EventArgs e)
        {
            var feet = double.Parse(numericUpDown3.Value.ToString());
            var meters = feet * 0.304800610;

            textBox2.Text = meters.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var lbs = double.Parse(numericUpDown4.Value.ToString());
            var kg = lbs * 0.45359237;

            textBox3.Text = kg.ToString();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        /// <summary>
        ///     Execute a command as if from the command prompt, given the full path and it's arguments.
        /// </summary>
        /// <param name="command">The command to be run</param>
        /// <param name="arguments">The arguments to be passed to the command</param>
        /// <param name="output">The output of the command</param>
        /// <param name="timeOut">Timeout (in minutes) before which the command is aborted</param>
        /// <returns>The return status code.</returns>
        private static int ExecuteCommand(string command, string arguments, ref string output, int timeOut)
        {

            int returnVal = -1;

            ProcessStartInfo startInfo = new ProcessStartInfo();

            startInfo.FileName = command;
            startInfo.WindowStyle = ProcessWindowStyle.Normal;
            Process process = new Process();
            process.StartInfo = startInfo;
            process.Start();
            returnVal = 0;

            return returnVal;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            RunClient(textBox4.Text);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            RunClient(textBox5.Text);
        }

        private void RunClient(string clientPath)
        {
            int exitCode = 0;
            string argument = String.Empty;
            string output = String.Empty;
            _engineLock.EnterReadLock();

            try
            {
                string appPath = Application.StartupPath;

                string filePath = appPath + "\\" + clientPath;

                exitCode = ExecuteCommand(filePath, argument, ref output, 5);
            }
            finally
            {
                _engineLock.ExitReadLock();
            }

            if (exitCode != 0)
            {
                Console.WriteLine("Error executing the client");
            }
        }

        ReaderWriterLockSlim _engineLock = new ReaderWriterLockSlim();

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void TextBox5_TextChanged(object sender, EventArgs e)
        {

        }
    }
}