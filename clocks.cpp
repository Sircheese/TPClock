//written by Alexander Molina Nasaev
//Caution! Wet code!
// ```````                                                        ```````
//````                                                             `````
//``                                                                 ```
//`                                                                     
//                               ./ssss/.                               
//                             -hy+:-::+yh-                             
//                            od/::::::::/do                            
//                          `yh::::::::::::yy`                          
//                         `hs::::::::::::::sh`                         
//                        .do::::::::::::::::od.                        
//                       -m+::::://:::::::::::+m-                       
//                      /m/:::/++//+/::::::::::/m/                      
//                     od::::-::sms::::::::::::::do                     
//                    sh::::::::dNd:::::::::::::::hs                    
//                  `hy::/o+::::dNd:-::::::::::::::yh`                  
//                 .do::dNNNN/::dNd:::::::::::::::::sd.                 
//                -m+:::NNNNNoodNNs::::::::::::::::::+m-                
//               :m/:::::oyhdNNNm/::::::::::::::::::::/m:               
//              +d/::::::smNNNNNNh+::::::+oyho:::::::-:/d+              
//             sd::::::yNNdsmNNNNNNNmmmNNNNdmNms:::::::::ds             
//           `yy:::::::NNy:::sNNNNNNNNNh+::::omNms::::::::yy`           
//          `ds::::::::NNy:::::+shdmmmNNNdyo+::odm/::::::::sd`          
//         .do:::::::::NNy:::::::::::::/oydNNNs::::::-::::::od.         
//        -m+:::::::::/yd+::::::::::::::::::+dNNs::::/ys:+hd/+m-        
//       /m/::::::::://+++/:::::::::::::::::::+dNN+:/+:/yy+:::/m/       
//      /m::-::::::::::::::::::::::::::::://////+o::::+oo+::-:::m/      
//     `N/::+ssssssssssssssssssssssssssyhyyssyyssssssssssssss/::/N`     
//     -N:::shdddddhdddddddddddddddddddhddddddhddddddhddddddh+:::N-     
//      hy::::::::::::::::::::::::::::::::::::::::::::::::::::::yh      
//      `ohs+::::::::::::::::::::::::::::::::::::::::::::::::+sho`      
//         -+osssssssssssssssssssssssssssssssssssssssssssssso+-         
//``                                                                  ``
//```                                                                ```
//``````                                                          ``````
//```````                                                        ```````

#include "clocks.h"
#include <ctime>

/*Like a professional programmer i'm using those parameters. Even if they are 
unnecessary*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	system("title TPClock");

	OutManager outManager;

	outManager.printMessage("Программа TPClock приветствует Вас!");
	outManager.printMessage("\n");
	outManager.printMessage("С помощью TPClock Вы можете заглянуть в будущее и узнать какое время будет через 23 часа");
	outManager.printMessage("\n");
	Sleep(2000);

	/*My imagination was fucked*/
	SkyNet skynet;
	TimeFinder timeFinder;
	Time time, answerTime;
	IATA* strategy;

	/*Please, don't ask me about this shit!*/
	bool wrong_command = true;
	while (wrong_command)
	{
		wrong_command = false;
		system("cls");
		outManager.printMessage("Введите 1, чтобы отправить DeLorian");
		outManager.printMessage("\n");
		outManager.printMessage("Введите 2, чтобы отправить T800 (ответ будет через 23 часа)");
		outManager.printMessage("\n");
		outManager.printMessage("Введите 3, чтобы завершить работу программы");
		outManager.printMessage("\n");
		int command;

		cin >> command;
		switch (command)
		{
			case 1:
			{
				strategy = new DeLorean;
				skynet.setStrategy(strategy);
			};
			break;
			case 2:
			{
				strategy = new T800;
				skynet.setStrategy(strategy);
			};
			break;
			case 3:
			{
				system("cls");
				outManager.printMessage("Пока!");
				outManager.printMessage("\n");
				Sleep(3000);
				exit(1);
			};
			break;
			default: 
			{
				system("cls");
				wrong_command = true;
				outManager.printMessage("Ты серьезно? Прочитай инструкцию внимательнее (это не сложно)");
				outManager.printMessage("\n");
				outManager.printMessage("Давай попробуем еще раз!");
				outManager.printMessage("\n");
				Sleep(2000);
			};
		};
	};

	system("cls");
	time = timeFinder.findTime();

	answerTime = skynet.getAnswer();

	outManager.printMessage("Начальное время ");
	outManager.printMessage(time.getHours());
	outManager.printMessage(":");
	outManager.printMessage(time.getMinutes());
	outManager.printMessage(":");
	outManager.printMessage(time.getSeconds());
	outManager.printMessage("\n");

	outManager.printMessage("Новое время ");
	outManager.printMessage(answerTime.getHours());
	outManager.printMessage(":");
	outManager.printMessage(answerTime.getMinutes());
	outManager.printMessage(":");
	outManager.printMessage(answerTime.getSeconds());
	outManager.printMessage("\n");

	system("pause");

	return 0;
};

