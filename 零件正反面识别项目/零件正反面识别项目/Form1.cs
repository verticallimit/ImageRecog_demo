using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Runtime.InteropServices;

namespace 零件正反面识别项目
{
    public partial class Form1 : Form
    {
        [DllImport("Dllcoin.dll", CharSet = CharSet.Ansi)]
        public static extern int show_pian(string filename);
        [DllImport("Dllcoin.dll", CharSet = CharSet.Ansi)]
        public static extern int show_huan(string filename);
        string filename;
        public Form1()
        {
            InitializeComponent();
        }

        private void btn_choice1_Click(object sender, EventArgs e)
        {
            OpenFileDialog opnDlg1 = new OpenFileDialog();
            try
            {
                if (opnDlg1.ShowDialog() == DialogResult.OK)
                {
                    pictureBox1.Image = Image.FromFile(opnDlg1.FileName);
                    filename = opnDlg1.FileName;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("图片读取有误");
            }
        }

        private void btn_choice2_Click(object sender, EventArgs e)
        {
            OpenFileDialog opnDlg2 = new OpenFileDialog();
            try
            {
                if (opnDlg2.ShowDialog() == DialogResult.OK)
                {
                    pictureBox2.Image = Image.FromFile(opnDlg2.FileName);
                    filename = opnDlg2.FileName;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("图片读取有误");
            }
        }
        /// <summary>
        /// 识别圆环的正反面
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btn_idf1_Click(object sender, EventArgs e)
        {
            int ans = show_huan(filename);
            if (ans == 1)
                MessageBox.Show("圆环正面");
            else
                MessageBox.Show("圆环反面");
        }
        /// <summary>
        /// 识别铁片的正反面
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btn_idf2_Click(object sender, EventArgs e)
        {
            int ans = show_pian(filename);
            if (ans == 1)
                MessageBox.Show("铁片正面");
            else
                MessageBox.Show("铁片反面");
        }

    }
}
