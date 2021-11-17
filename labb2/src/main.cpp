//Vera Sol Nygren








// struct Person
// {
//   std::string fnamn;
//   std::string enamn;
//   std::string nummer;
// };

// void visa_person (std::string fnamn, std::vector<Person> &telefonbok)
// {
//     // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post som skall visas. 
    
//     // Om det finns en eller flera person-poster med detta förnamn i registret, 
//     // så skall telefonnumret till dessa visas, på formen: "förnamn efternamn: telefonnummer".
//     for(Person p : telefonbok)
//     {
//         if(p.fnamn == fnamn)
//         {
//             std::string enamn = p.enamn;
//             std::string nummer = p.nummer;
//             std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;
//         }
//     }

    
//     // Om ingen person-post hittas med det sökta förnamnet, så skall följande skrivas ut.
//     std::cout << "Hittade inget nummer!" << std::endl;
// }

// void skriv_hela_telefonreg (std::vector<Person> &telefonbok)
// {
//     // Denna funktion tar emot ett telefonregister och visar samtliga poster i 
//     // telefonregistret på formen: "förnamn efternamn: telefonnummer".
    
//     for(Person p : telefonbok){
//         std::cout << p.fnamn << " " << p.enamn << ": " << p.nummer << std::endl;
//     }

    
// }

// void ny_person (std::string fnamn, std::string enamn, std::string nummer, std::vector<Person> &telefonbok)
// {
    

//     // Denna funktion tar emot ett telefonregister och ett förnamn, ett efternamn och 
//     // ett telefonnummer till den nya person-post som skall skapas och läggas till i telefonboken, 
//     // därefter läggs person-posten till registret.
//     Person p;
//     p.fnamn = fnamn;
//     p.enamn = enamn;
//     p.nummer = nummer;
//     telefonbok.push_back(p);
   
// }

// void ta_bort_person (std::string fnamn, std::vector<Person> &telefonbok)
// {

//     // Denna funktion tar emot ett telefonregister och ett förnamn på den person-post 
//     // som skall tas bort ur registret.
//     // Om det finns fler person-poster med samma förnamn, så tas alla dessa bort.
    
//     // När en person-post tas bort så skrivs namnet på person-posten ut på skärmen (förnamn efternamn), 
//     // men ingen användardialog skall finnas, dvs. användaren skall inte bekräfta borttag.
	
// 	//Iterator som är nödvändig för att spara positionen i och med radering - för att göra det lättare att 
// 	//iterera över ett föränderligt underlag. 

// 	for (int i = 0 ; i < telefonbok.size(); i++)
// 	{
// 		if(telefonbok[i].fnamn == fnamn)
// 		{
// 			std::cout << fnamn << " " << telefonbok[i].enamn << " tas bort nu." << std::endl;
// 			telefonbok.erase(telefonbok.begin() + i);
// 		}
// 	}
    
// 	// std ::vector<Person>::iterator it;

// 	// it = std ::remove_if(
//     //     telefonbok.begin(), telefonbok.end(),
//     //     [](Person p, std::string fnamn) {std::cout << p.fnamn << " " << p.enamn << " tas nu bort. \n"; return (p.fnamn == fnamn); });

// }

// int main ()
// {
//     // Dessa personer skall finnas med som person-poster i telefonregistret.
//     /*
//     "Christina", "Nyberg","0707423653"
//     "Josefin", "Danielsson", "0705463245"
//     "Ellen", "Lindgren", "0705643229"
//     "Stig", "Ek", "0705673247"
//     "Linus", "Jonasson", "0703457923"
//     "Adam", "Nordin", "0203456297"
//     */

    
//     // Här ska du deklarera den variabel som skall innehålla ditt register!

//     std::vector<Person> telefonbok;
    
//     ny_person("Christina" , "Nyberg", "0707423653", telefonbok);
//     ny_person("Josefin", "Danielsson", "0705463245", telefonbok);
//     ny_person("Ellen", "Lindgren", "0705643229", telefonbok);
//     ny_person("Stig", "Ek", "0705673247", telefonbok);
//     ny_person("Linus", "Jonasson", "0703457923", telefonbok);
//     ny_person("Adam", "Nordin", "0203456297", telefonbok);
    
    
//     // Här skall en liten kommandostyrd huvudmeny skrivas. Observera att vissa kommandon
//     // behöver fler värden som skall matas in. I menyn skall följande val 
//     // av Kommandon finnas:
//     //  Ny person               - 'n' förnamn efternamn telefonnummer
//     //  Visa en person          - 'v' förnamn
//     //  Skriv hela telefonboken - 's'
//     //  Ta bort en person       - 'd' förnamn
//     //  Avsluta                 – 'q'
    
    
//     char command;
//     std::string fnamn, enamn, nummer;

//     while(true){
//         //lista tillgängliga kommandon?
        
        
//         std::cout << "Kommando: ";
//         std::cin >> command;
        
//         switch(command){
//             case 'n' : 
//                 //ta in hela namnet, och skicka in
//                 std::cin >> fnamn >> enamn >> nummer;
//                 ny_person (fnamn, enamn, nummer, telefonbok);
//                 break;
//             case 'v' : 
//                 //ta in förnamn!
//                 std::cin >> fnamn;
//                 visa_person (fnamn, telefonbok);
//                 break;
//             case 's' : 
//                 skriv_hela_telefonreg (telefonbok);
//                 break;
//             case 'd' : 
//             //ta in förnamn
//                 std::cin >> fnamn;
//                 ta_bort_person (fnamn, telefonbok);
//                 break;
//             case 'q' : 
//                 return 0;
//             default :
//                 std::cout << "Känner ej igen kommandot " << command << " försök igen!" << std::endl;
//         }        
//     }
// }

