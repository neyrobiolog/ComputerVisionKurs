#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/flann/miniflann.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <conio.h>

using std::cout;
using std::cerr;
using std::endl;

using namespace cv;
using namespace std;

string ch;
//vector<System::Windows::Forms::CheckBox> items;

//SURF и FlannBased (matcher)
Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("FlannBased");
Ptr<DescriptorExtractor> extractor = new SurfDescriptorExtractor();
SurfFeatureDetector detector(500);

// BOW
int dictionarySize = 1500;								// Число центроидов кластеров
TermCriteria tc(CV_TERMCRIT_ITER, 10, 0.001);			// Критерий остановки
BOWKMeansTrainer bowTrainer(dictionarySize, tc, 1);
BOWImgDescriptorExtractor bowDE(extractor, matcher);

// SVM
CvSVM svm;

int classes_count = 3;
int images_count = 30;//60;

string *namesClasses;

namespace CV_ImageClassification {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_train;
	protected: 
	private: System::Windows::Forms::Button^  button_classification;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox13;
	private: System::Windows::Forms::CheckBox^  checkBox14;
	private: System::Windows::Forms::CheckBox^  checkBox15;
	private: System::Windows::Forms::CheckBox^  checkBox16;
	private: System::Windows::Forms::CheckBox^  checkBox17;
	private: System::Windows::Forms::CheckBox^  checkBox18;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox10;
	private: System::Windows::Forms::CheckBox^  checkBox11;
	private: System::Windows::Forms::CheckBox^  checkBox12;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox2;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_train = (gcnew System::Windows::Forms::Button());
			this->button_classification = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_train
			// 
			this->button_train->Location = System::Drawing::Point(47, 350);
			this->button_train->Name = L"button_train";
			this->button_train->Size = System::Drawing::Size(143, 55);
			this->button_train->TabIndex = 0;
			this->button_train->Text = L"Обучение";
			this->button_train->UseVisualStyleBackColor = true;
			this->button_train->Click += gcnew System::EventHandler(this, &Form1::button_train_Click);
			// 
			// button_classification
			// 
			this->button_classification->Location = System::Drawing::Point(265, 350);
			this->button_classification->Name = L"button_classification";
			this->button_classification->Size = System::Drawing::Size(143, 55);
			this->button_classification->TabIndex = 1;
			this->button_classification->Text = L"Классификация";
			this->button_classification->UseVisualStyleBackColor = true;
			this->button_classification->Click += gcnew System::EventHandler(this, &Form1::button_classification_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(21, 41);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(63, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"scissors";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(52, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(336, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Классификация изображений";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox13);
			this->groupBox1->Controls->Add(this->checkBox14);
			this->groupBox1->Controls->Add(this->checkBox15);
			this->groupBox1->Controls->Add(this->checkBox16);
			this->groupBox1->Controls->Add(this->checkBox17);
			this->groupBox1->Controls->Add(this->checkBox18);
			this->groupBox1->Controls->Add(this->checkBox7);
			this->groupBox1->Controls->Add(this->checkBox8);
			this->groupBox1->Controls->Add(this->checkBox9);
			this->groupBox1->Controls->Add(this->checkBox10);
			this->groupBox1->Controls->Add(this->checkBox11);
			this->groupBox1->Controls->Add(this->checkBox12);
			this->groupBox1->Controls->Add(this->checkBox5);
			this->groupBox1->Controls->Add(this->checkBox6);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Location = System::Drawing::Point(45, 77);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(363, 249);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Выберите классы изображений для дальнейшей работы";
			// 
			// checkBox13
			// 
			this->checkBox13->AutoSize = true;
			this->checkBox13->Location = System::Drawing::Point(271, 212);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(60, 17);
			this->checkBox13->TabIndex = 22;
			this->checkBox13->Text = L"dolphin";
			this->checkBox13->UseVisualStyleBackColor = true;
			// 
			// checkBox14
			// 
			this->checkBox14->AutoSize = true;
			this->checkBox14->Location = System::Drawing::Point(271, 177);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(69, 17);
			this->checkBox14->TabIndex = 21;
			this->checkBox14->Text = L"dollar_bill";
			this->checkBox14->UseVisualStyleBackColor = true;
			// 
			// checkBox15
			// 
			this->checkBox15->AutoSize = true;
			this->checkBox15->Location = System::Drawing::Point(271, 143);
			this->checkBox15->Name = L"checkBox15";
			this->checkBox15->Size = System::Drawing::Size(44, 17);
			this->checkBox15->TabIndex = 20;
			this->checkBox15->Text = L"cup";
			this->checkBox15->UseVisualStyleBackColor = true;
			// 
			// checkBox16
			// 
			this->checkBox16->AutoSize = true;
			this->checkBox16->Location = System::Drawing::Point(271, 109);
			this->checkBox16->Name = L"checkBox16";
			this->checkBox16->Size = System::Drawing::Size(47, 17);
			this->checkBox16->TabIndex = 19;
			this->checkBox16->Text = L"crab";
			this->checkBox16->UseVisualStyleBackColor = true;
			// 
			// checkBox17
			// 
			this->checkBox17->AutoSize = true;
			this->checkBox17->Location = System::Drawing::Point(271, 75);
			this->checkBox17->Name = L"checkBox17";
			this->checkBox17->Size = System::Drawing::Size(49, 17);
			this->checkBox17->TabIndex = 18;
			this->checkBox17->Text = L"chair";
			this->checkBox17->UseVisualStyleBackColor = true;
			// 
			// checkBox18
			// 
			this->checkBox18->AutoSize = true;
			this->checkBox18->Location = System::Drawing::Point(271, 41);
			this->checkBox18->Name = L"checkBox18";
			this->checkBox18->Size = System::Drawing::Size(72, 17);
			this->checkBox18->TabIndex = 17;
			this->checkBox18->Text = L"cellphone";
			this->checkBox18->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(146, 212);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(66, 17);
			this->checkBox7->TabIndex = 16;
			this->checkBox7->Text = L"car_side";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(146, 177);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(63, 17);
			this->checkBox8->TabIndex = 15;
			this->checkBox8->Text = L"butterfly";
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(146, 143);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(62, 17);
			this->checkBox9->TabIndex = 14;
			this->checkBox9->Text = L"buddha";
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(146, 109);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(87, 17);
			this->checkBox10->TabIndex = 13;
			this->checkBox10->Text = L"brontosaurus";
			this->checkBox10->UseVisualStyleBackColor = true;
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->Location = System::Drawing::Point(146, 75);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(49, 17);
			this->checkBox11->TabIndex = 12;
			this->checkBox11->Text = L"brain";
			this->checkBox11->UseVisualStyleBackColor = true;
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->Location = System::Drawing::Point(146, 41);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(69, 17);
			this->checkBox12->TabIndex = 11;
			this->checkBox12->Text = L"binocular";
			this->checkBox12->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(21, 212);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(59, 17);
			this->checkBox5->TabIndex = 10;
			this->checkBox5->Text = L"beaver";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(21, 178);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(52, 17);
			this->checkBox6->TabIndex = 9;
			this->checkBox6->Text = L"barrel";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(21, 143);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(41, 17);
			this->checkBox3->TabIndex = 8;
			this->checkBox3->Text = L"ant";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(21, 109);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(68, 17);
			this->checkBox4->TabIndex = 7;
			this->checkBox4->Text = L"airplanes";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(21, 75);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(59, 17);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"anchor";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 417);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_classification);
			this->Controls->Add(this->button_train);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Классификация изображений";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
			string typeClasses(int i)
			{
				if (i == 1)
					return "airplanes";
				if (i == 2)
					return "brontosaurus";
				if (i == 3)
					return "butterfly";
			}

			// Подготовка данных для словаря с использованием алгоритма K-means
			void readImgs() 
			{
				IplImage *img = NULL;

				// Загрузка очередного класса изображений
				for (int i = 1; i <= classes_count; i++)
				{
					//string typeClass = typeClasses(i);
					string typeClass = namesClasses[i - 1];
					vector<cv::String> fn;
					string str = "C:/CV_Kursach/101_ObjectCategories/" + typeClass + "/" + to_string(i) + "*.jpg";
					glob(str, fn, false);

					vector<Mat> images;
					size_t count = fn.size();
					for (size_t j = 0; j < count; j++)
					{
						images.push_back(imread(fn[j]));
						const char* ch = fn[j].c_str();
						img = cvLoadImage(ch, 0);

						// Поиск ключевых точек на изображении
						vector<KeyPoint> keypoint;
						detector.detect(img, keypoint);

						Mat features;
						// Рассчитать дескрипторы
						extractor->compute(img, keypoint, features);
						// Добавить дескрипторы в словарь
						bowTrainer.add(features);
					}
				}

				return;
			}

			 // ОБУЧЕНИЕ
	private: System::Void button_train_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				classes_count = checkNumClasses();

				namesClasses = new string[classes_count];
				nameClasses();

				IplImage *img2 = NULL;

				readImgs();
	
				// Подсчет дескрипторов
				vector<Mat> descriptors = bowTrainer.getDescriptors();
				int count = 0;
				for (vector<Mat>::iterator iter = descriptors.begin(); iter != descriptors.end(); iter++)
				{
					count += iter->rows;
				}
				cout << "Кластеризация " << count << " дескрипторов..." << endl;

				// Центры кластеров - слова словаря. Кластеризация дескрипторов
				Mat dictionary = bowTrainer.cluster();
				bowDE.setVocabulary(dictionary);


				//***********************************************************
				// SVM-классификация изображений: обучение классификатора
				//***********************************************************

				// Подготовка тренировочной выборки
				Mat labels(0, 1, CV_32FC1);						// Матрица для номеров классов изображений тренировочной выборки
				Mat trainingData(0, dictionarySize, CV_32FC1);	// Матрица для изображений тренировочной выборки 
	
				vector<KeyPoint> keypoint1;						// Матрица для ключевых точек изображения
				Mat bowDescriptor1;								// Матрица для дескрипторов изображения

				for (int j = 1; j <= classes_count; j++)
				{
					for (int i = 1; i <= images_count; i++) 
					{
						// Загрузка очердного изображения
						string typeClass = typeClasses(j);
						//string typeClass = namesClasses[j-1];
						string str = "C:\\CV_Kursach\\101_ObjectCategories\\" + typeClass + "\\" + to_string(i) + ".jpg";
						const char* ch = str.c_str();
						const char* imageName = ch;
						img2 = cvLoadImage(imageName, 0);
			
						// Поиск ключевых точек на изображении
						detector.detect(img2, keypoint1);
						// Вычисление дескрипторов изображения
						bowDE.compute(img2, keypoint1, bowDescriptor1);

						// Добавление изображения в тренировочную выборку
						trainingData.push_back(bowDescriptor1);
						// Запоминаем номер класса изображения
						labels.push_back((float)j);
					}
				}

				// SVM-параметры и собственно SVM
				CvSVMParams params;
				params.kernel_type = CvSVM::RBF;		// Тип ядра SVM: RBF - радиальная базисная функция 
				params.svm_type = CvSVM::C_SVC;			// Тип формулировки SVM: C_SVC (для классификации n-классов) 
				params.gamma = 0.50625000000000009;		// Гамма-параметр функции RBF-ядра
				params.C = 312.50000000000000;			// Параметр оптимизации для C_SVC
				params.term_crit = cvTermCriteria(CV_TERMCRIT_ITER, 100, 0.000001);		// Критерий завершения итеративной процедуры обучения SVM
				//CvSVM svm;

				// Обучение SVM-классификатора
				svm.train(trainingData, labels, cv::Mat(), cv::Mat(), params);

			 }
			 				
			// КЛАССИФИКАЦИЯ ИЗОБРАЖЕНИЙ
	private: System::Void button_classification_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				IplImage *img2 = NULL;
				Mat rightResult(0, 1, CV_32FC1);	// Матрица ожидаемых результатов
				Mat results(0, 1, CV_32FC1);		// Матрица фактических результатов
				vector<KeyPoint> keypoint2;			// Матрица для ключевых точек изображения
				Mat bowDescriptor2;					// Матрица для дескрипторов изображения

				int imageNumber = 0;
				for (int j = 1; j <= classes_count; j++)
				{
					for (int i = 1; i <= 10; i++) 
					{
						imageNumber++;

						// Загрузка очердного изображения
						string str = "C:\\CV_Kursach\\eval1\\" + to_string(j) + " (" + to_string(i) + ").jpg";
						const char* imageName = str.c_str();
						img2 = cvLoadImage(imageName, 0);

						// Поиск ключевых точек на изображении
						detector.detect(img2, keypoint2);
						// Вычисление дескрипторов изображения
						bowDE.compute(img2, keypoint2, bowDescriptor2);

						// Какой должен быть ответ
						rightResult.push_back((float)j);
						// Фактический ответ
						float response = svm.predict(bowDescriptor2);
						results.push_back(response);
						//cout <<imageNumber<< ") определен: " << response << ", фактический:" << j << endl;

						// Распределение изображений по папкам
						string typeClass = typeClasses(j);
						string resultPath = "C:\\CV_Kursach\\Result\\" + typeClass + "\\" + to_string(imageNumber) + ".jpg";
						const char* imageResultName = resultPath.c_str();
						cvSaveImage(imageResultName, img2);
					}
				}

			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			{
			}

			 int checkNumClasses()
			 {
				 int numClasses = 0;
				 if (checkBox1->Checked)
					 numClasses++;
				 if (checkBox2->Checked)
					 numClasses++;
				 if (checkBox3->Checked)
					 numClasses++;
				 if (checkBox4->Checked)
					 numClasses++;
				 if (checkBox5->Checked)
					 numClasses++;
				 if (checkBox6->Checked)
					 numClasses++;
				 if (checkBox7->Checked)
					 numClasses++;
				 if (checkBox8->Checked)
					 numClasses++;
				 if (checkBox9->Checked)
					 numClasses++;
				 if (checkBox10->Checked)
					 numClasses++;
				 if (checkBox11->Checked)
					 numClasses++;
				 if (checkBox12->Checked)
					 numClasses++;
				 if (checkBox13->Checked)
					 numClasses++;
				 if (checkBox14->Checked)
					 numClasses++;
				 if (checkBox15->Checked)
					 numClasses++;
				 if (checkBox16->Checked)
					 numClasses++;
				 if (checkBox17->Checked)
					 numClasses++;
				 if (checkBox18->Checked)
					 numClasses++;

				 return numClasses;
			 }

			 void nameClasses()
			 {
				 int numClasses = 0;
				 if (checkBox1->Checked)
				 {
					 namesClasses[numClasses] = "scissors";
					 numClasses++;
				 }
				 if (checkBox2->Checked)
				 {
					 namesClasses[numClasses] = "anchor";
					 numClasses++;
				 }
				 if (checkBox3->Checked)
				 {
					 namesClasses[numClasses] = "ant";
					 numClasses++;
				 }
				 if (checkBox4->Checked)
				 {
					 namesClasses[numClasses] = "airplanes";
					 numClasses++;
				 }
				 if (checkBox5->Checked)
				 {
					 namesClasses[numClasses] = "beaver";
					 numClasses++;
				 }
				 if (checkBox6->Checked)
				 {
					 namesClasses[numClasses] = "barrel";
					 numClasses++;
				 }
				 if (checkBox7->Checked)
				 {
					 namesClasses[numClasses] = "car_side";
					 numClasses++;
				 }
				 if (checkBox8->Checked)
				 {
					 namesClasses[numClasses] = "butterfly";
					 numClasses++;
				 }
				 if (checkBox9->Checked)
				 {
					 namesClasses[numClasses] = "buddha";
					 numClasses++;
				 }
				 if (checkBox10->Checked)
				 {
					 namesClasses[numClasses] = "brontosaurus";
					 numClasses++;
				 }
				 if (checkBox11->Checked)
				 {
					 namesClasses[numClasses] = "brain";
					 numClasses++;
				 }
				 if (checkBox12->Checked)
				 {
					 namesClasses[numClasses] = "binocular";
					 numClasses++;
				 }
				 if (checkBox13->Checked)
				 {
					 namesClasses[numClasses] = "dolphin";
					 numClasses++;
				 }
				 if (checkBox14->Checked)
				 {
					 namesClasses[numClasses] = "dollar_bill";
					 numClasses++;
				 }
				 if (checkBox15->Checked)
				 {
					 namesClasses[numClasses] = "cup";
					 numClasses++;
				 }
				 if (checkBox16->Checked)
				 {
					 namesClasses[numClasses] = "crab";
					 numClasses++;
				 }
				 if (checkBox17->Checked)
				 {
					 namesClasses[numClasses] = "chair";
					 numClasses++;
				 }
				 if (checkBox18->Checked)
				 {
					 namesClasses[numClasses] = "cellphone";
					 numClasses++;
				 }
			 }
};
}
