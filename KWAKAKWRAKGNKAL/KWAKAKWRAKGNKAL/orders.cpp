#include "orders.h"

string & orders::getmission()
{
	return mission;
}

string & orders::getvailiddate()
{
	return validdate;
}

void orders::setmission(string & newmission)
{
	mission = newmission;
}

void orders::setvaliddate(string newdate)
{
	validdate = newdate;
}

void orders::print_all()
{
	std::cout << this->getDestCity() << std::endl
		<< this->getDestCountry() << std::endl
		<< mission << std::endl
		<< validdate << std::endl;
}

//operator overload for copying relevant information from the visa
//changes the visa so that it always displays "Military" as its reason if this is invoked
orders & orders::operator=(visa & thevisa)
{
	this->setDestCountry(thevisa.getDestCountry());
	this->setDestCity(thevisa.getDestCity());
	thevisa.setVisaType((string)"Military");
	return *this;
}
void orders::corrupt_mission(int odds)
{
	for (int i = 0; i < mission.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false)
		{
			mission[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void orders::corrupt_validdate(int odds)
{
	for (int i = 0; i < validdate.length(); i++)
	{
		if (!(rand() % (100 / odds)) && valid != false && i != 2 && i != 5)
		{
			validdate[i] = 97 + rand() % 26;
			valid = false;
		}

	}
}
void orders::orders_mastercorrupt(int odds)
{
	orders::corrupt_validdate(odds);
	orders::corrupt_mission(odds);

}

void orders::draw(sf::RenderWindow & window)
{

	string sex_str;
	sf::Font normal;
	sf::Font bold;

	if (!normal.loadFromFile("DejaVuSansMono.ttf"))
	{
		// Error...
	}
	if (bold.loadFromFile("DejaVuSansMono-Bold.ttf"))
	{
		//Error
	}

	sf::RectangleShape card(sf::Vector2f(900, 900));
	sf::Text static_info_IDno("ID: ", bold, 30); // says id is bold,30 pixels
	sf::Text static_info_DOB("DOB: ", bold, 30); //These are constants for all id
	sf::Text static_info_SEX("SEX: ", bold, 30);
	sf::Text static_info_FIRST("FIRST: ", bold, 30);
	sf::Text static_info_LAST("LAST: ", bold, 30);
	sf::Text static_info_HEIGHT("HEIGHT: ", bold, 30);
	sf::Text static_info_WEIGHT("WEIGHT: ", bold, 30);
	sf::Text static_info_EXPD("EXP DATE: ", bold, 30);
	sf::Text static_info_COUNTRY("COUNTRY: ", bold, 30); //need to set position
	sf::Text static_info_MISSION("MISSION: ", bold, 30);
	sf::Text static_info_VALIDDATE("VALIDDATE: ", bold, 30);
														 //	
														 //	
	static_info_IDno.setPosition(0, 50);
	static_info_DOB.setPosition(0, 100);
	static_info_SEX.setPosition(0, 150);
	static_info_FIRST.setPosition(0, 200);
	static_info_LAST.setPosition(0, 250);
	static_info_HEIGHT.setPosition(0, 300);
	static_info_WEIGHT.setPosition(0, 350);
	static_info_EXPD.setPosition(0, 50);
	static_info_COUNTRY.setPosition(0, 100);
	static_info_MISSION.setPosition(0, 150);
	static_info_VALIDDATE.setPosition(0, 200);
	card.setFillColor(sf::Color(0,150,50,255));
	card.setPosition(0, 0);
	//	
	sf::Text IDno_draw;
	sf::Text DOB_draw;
	sf::Text sex_draw;
	sf::Text firstN_draw;
	sf::Text lastN_draw;
	sf::Text height_draw;
	sf::Text weight_draw;
	sf::Text date_draw;
	sf::Text country_draw;
	sf::Text mission_draw;
	sf::Text validdate_draw;
	window.display();
	//	

	IDno_draw.setFont(normal);
	DOB_draw.setFont(normal);
	sex_draw.setFont(normal);
	firstN_draw.setFont(normal);
	lastN_draw.setFont(normal);
	height_draw.setFont(normal);
	weight_draw.setFont(normal);
	date_draw.setFont(normal);
	country_draw.setFont(normal);
	mission_draw.setFont(normal);
	validdate_draw.setFont(normal);
	//		

	IDno_draw.setPosition(200, 50);
	DOB_draw.setPosition(200, 100);
	sex_draw.setPosition(200, 150);
	firstN_draw.setPosition(200, 200);
	lastN_draw.setPosition(200, 250);
	height_draw.setPosition(200, 300);
	weight_draw.setPosition(200, 350);
	date_draw.setPosition(200, 50);
	country_draw.setPosition(200, 100);
	mission_draw.setPosition(200, 150);
	validdate_draw.setPosition(200, 200);
	//	
	IDno_draw.setCharacterSize(25);
	DOB_draw.setCharacterSize(25);
	sex_draw.setCharacterSize(25);
	firstN_draw.setCharacterSize(25);
	lastN_draw.setCharacterSize(25);
	height_draw.setCharacterSize(25);
	weight_draw.setCharacterSize(25);
	date_draw.setCharacterSize(25);
	country_draw.setCharacterSize(25);
	mission_draw.setCharacterSize(25);
	validdate_draw.setCharacterSize(25);
	//		
	IDno_draw.setString(IDno);
	DOB_draw.setString(DoB);
	if (sex == true)
	{
		sex_str = "m";
	}
	else
	{
		sex_str = "f";
	}
	sex_draw.setString(sex_str);
	firstN_draw.setString(firstN);
	lastN_draw.setString(lastN);
	height_draw.setString(std::to_string(height));
	weight_draw.setString(std::to_string(weight));
	date_draw.setString(date);
	country_draw.setString(country);
	mission_draw.setString(mission);
	validdate_draw.setString(validdate);
	//		
	window.draw(card);
	//window.draw(static_info_IDno); // says id is bold,30 pixels
	//window.draw(static_info_DOB); //These are constants for all id
	//window.draw(static_info_SEX);
	//window.draw(static_info_FIRST);
	//window.draw(static_info_LAST);
	//window.draw(static_info_HEIGHT);
	//window.draw(static_info_WEIGHT);
	window.draw(static_info_EXPD);
	window.draw(static_info_COUNTRY);
	window.draw(static_info_MISSION);
	window.draw(static_info_VALIDDATE);

	//window.draw(IDno_draw);
	//window.draw(DOB_draw);
	//window.draw(sex_draw);
	//window.draw(firstN_draw);
	//window.draw(lastN_draw);
	//window.draw(height_draw);
	//window.draw(weight_draw);
	window.draw(date_draw);
	window.draw(country_draw);
	window.draw(mission_draw);
	window.draw(validdate_draw);

}
