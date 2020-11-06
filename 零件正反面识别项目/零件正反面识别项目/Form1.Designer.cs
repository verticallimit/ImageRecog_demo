namespace 零件正反面识别项目
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.btn_choice1 = new System.Windows.Forms.Button();
            this.btn_choice2 = new System.Windows.Forms.Button();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.btn_idf1 = new System.Windows.Forms.Button();
            this.btn_idf2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(32, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(187, 29);
            this.label1.TabIndex = 0;
            this.label1.Text = "圆环零件识别";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(419, 27);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(187, 29);
            this.label2.TabIndex = 1;
            this.label2.Text = "铁片零件识别";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(37, 82);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(167, 126);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // btn_choice1
            // 
            this.btn_choice1.Location = new System.Drawing.Point(228, 145);
            this.btn_choice1.Name = "btn_choice1";
            this.btn_choice1.Size = new System.Drawing.Size(76, 34);
            this.btn_choice1.TabIndex = 3;
            this.btn_choice1.Text = "选择图片";
            this.btn_choice1.UseVisualStyleBackColor = true;
            this.btn_choice1.Click += new System.EventHandler(this.btn_choice1_Click);
            // 
            // btn_choice2
            // 
            this.btn_choice2.Location = new System.Drawing.Point(594, 145);
            this.btn_choice2.Name = "btn_choice2";
            this.btn_choice2.Size = new System.Drawing.Size(66, 34);
            this.btn_choice2.TabIndex = 4;
            this.btn_choice2.Text = "选择图片";
            this.btn_choice2.UseVisualStyleBackColor = true;
            this.btn_choice2.Click += new System.EventHandler(this.btn_choice2_Click);
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(405, 82);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(167, 126);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 5;
            this.pictureBox2.TabStop = false;
            // 
            // btn_idf1
            // 
            this.btn_idf1.Location = new System.Drawing.Point(80, 239);
            this.btn_idf1.Name = "btn_idf1";
            this.btn_idf1.Size = new System.Drawing.Size(88, 34);
            this.btn_idf1.TabIndex = 6;
            this.btn_idf1.Text = "识别";
            this.btn_idf1.UseVisualStyleBackColor = true;
            this.btn_idf1.Click += new System.EventHandler(this.btn_idf1_Click);
            // 
            // btn_idf2
            // 
            this.btn_idf2.Location = new System.Drawing.Point(461, 243);
            this.btn_idf2.Name = "btn_idf2";
            this.btn_idf2.Size = new System.Drawing.Size(87, 30);
            this.btn_idf2.TabIndex = 7;
            this.btn_idf2.Text = "识别";
            this.btn_idf2.UseVisualStyleBackColor = true;
            this.btn_idf2.Click += new System.EventHandler(this.btn_idf2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(714, 383);
            this.Controls.Add(this.btn_idf2);
            this.Controls.Add(this.btn_idf1);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.btn_choice2);
            this.Controls.Add(this.btn_choice1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "零件识别系统";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button btn_choice1;
        private System.Windows.Forms.Button btn_choice2;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Button btn_idf1;
        private System.Windows.Forms.Button btn_idf2;
    }
}

