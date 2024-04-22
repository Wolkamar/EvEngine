// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <fstream>
// #include <string>

// template <class S>
// class Actor
// {
// protected:
// 	S shape;
// 	sf::Color color;

// 	std::string name = "";

// 	float width = 0;
// 	float height = 0;
// 	float posX = 0;
// 	float posY = 0;
// 	float speedX = 0;
// 	float speedY = 0;

// public:

// 	void setPos(float x, float y)
// 	{
// 		posX = x;
// 		posY = y;
// 		getShape()->setPosition(x, y);
// 	}

// 	void move()
// 	{
// 		setPos(posX + speedX, posY + speedY);
// 		if ((posX > -0.05f && posX < 0.05f) && (posY > -0.05f && posY < 0.05f)) exit(-1);
// 	}

// 	void setName(std::string newName)
// 	{
// 		name = newName;
// 	}

// 	void setSpeed(float sx, float sy)
// 	{
// 		speedX = sx;
// 		speedY = sy;
// 	}

// 	void reverseXSpeed()
// 	{
// 		speedX = -speedX;
// 	}

// 	void reverseYSpeed()
// 	{
// 		speedY = -speedY;
// 	}

// 	float getLeft()
// 	{
// 		return posX;
// 	}

// 	float getTop()
// 	{
// 		return posY;
// 	}

// 	float getRight()
// 	{
// 		return posX + width;
// 	}

// 	float getBottom()
// 	{
// 		return posY + height;
// 	}

// 	float getWidth()
// 	{
// 		return width;
// 	}

// 	float getHeight()
// 	{
// 		return height;
// 	}

// 	std::string getName()
// 	{
// 		return name;
// 	}

// 	S* getShape()
// 	{
// 		return &shape;
// 	}

// 	void print()
// 	{
// 		std::cout << name << "\n";
// 	}

// 	~Actor()
// 	{
// 		std::cout << "Destr " << name << "\n";
// 	}
// };

// class CircleActor : public virtual Actor<sf::CircleShape>
// {
// 	sf::CircleShape shape;

// public:

// 	CircleActor() {}

// 	CircleActor(std::string newName, float x, float y, float sx, float sy, sf::Color color, float radius)
// 	{
// 		shape = sf::CircleShape(radius);

// 		setName(newName);
// 		setSize(radius);
// 		setPos(x, y);
// 		setSpeed(sx, sy);
// 		setColor(color);
// 	}

// 	void setColor(sf::Color newColor)
// 	{
// 		color = newColor;
// 		getShape()->setFillColor(color);
// 	}

// 	void setSize(float radius)
// 	{
// 		width = radius;
// 		height = radius;
// 		getShape()->setRadius(radius);
// 	}

// 	float getRight()
// 	{
// 		return posX + width * 2;
// 	}

// 	float getBottom()
// 	{
// 		return posY + height * 2;
// 	}
// };

// class RectangleActor : public virtual Actor<sf::RectangleShape>
// {
// 	sf::RectangleShape shape;

// public:

// 	RectangleActor()
// 	{}

// 	RectangleActor(std::string name, float x, float y, float sx, float sy, sf::Color color, float width, float height)
// 	{
// 		shape = sf::RectangleShape();

// 		setName(name);
// 		setSize(width, height);
// 		setPos(x, y);
// 		setSpeed(sx, sy);
// 		setColor(color);
// 	}

// 	void setColor(sf::Color newColor)
// 	{
// 		color = newColor;
// 		getShape()->setFillColor(color);
// 	}

// 	void setSize(float newWidth, float newHeight)
// 	{
// 		width = newWidth;
// 		height = newHeight;
// 		getShape()->setSize(sf::Vector2f(newWidth, newHeight));
// 	}
// };

// //template <class G>
// //class GameObject : public CircleActor, public RectangleActor
// //{
// //protected:
// //	S shape;
// //	sf::Color color;
// //
// //	std::string name = "";
// //
// //	float width = 0;
// //	float height = 0;
// //	float posX = 0;
// //	float posY = 0;
// //	float speedX = 0;
// //	float speedY = 0;
// //
// //public:
// //
// //	void setPos(float x, float y)
// //	{
// //		posX = x;
// //		posY = y;
// //		getShape()->setPosition(x, y);
// //	}
// //
// //	void move()
// //	{
// //		setPos(posX + speedX*15.f, posY + speedY*15.f);
// //	}
// //
// //	void setName(std::string newName)
// //	{
// //		name = newName;
// //	}
// //
// //	void setSpeed(float sx, float sy)
// //	{
// //		speedX = sx;
// //		speedY = sy;
// //	}
// //
// //	void reverseXSpeed()
// //	{
// //		speedX = -speedX;
// //	}
// //
// //	void reverseYSpeed()
// //	{
// //		speedY = -speedY;
// //	}
// //
// //	float getLeft()
// //	{
// //		return posX;
// //	}
// //
// //	float getTop()
// //	{
// //		return posY;
// //	}
// //
// //	float getRight()
// //	{
// //		return posX + width;
// //	}
// //
// //	float getBottom()
// //	{
// //		return posY + height;
// //	}
// //
// //	float getWidth()
// //	{
// //		return width;
// //	}
// //
// //	float getHeight()
// //	{
// //		return height;
// //	}
// //
// //	std::string getName()
// //	{
// //		return name;
// //	}
// //
// //	S* getShape()
// //	{
// //		return &shape;
// //	}
// //
// //	void print()
// //	{
// //		std::cout << name << "\n";
// //	}
// //
// //	~Actor()
// //	{
// //		std::cout << "Destr " << name << "\n";
// //	}
// //};

// std::ifstream loadConfigFile()
// {
// 	std::ifstream file("a1config.txt");

// 	if (!file)
// 	{
// 		std::cerr << "Bad cfg file";
// 		exit(-1);
// 	}
// 	else
// 	{
// 		std::cout << "File good\n";
// 	}

// 	return file;
// }

// template <class S>
// void updateShape(S* shape, sf::RenderWindow* window, sf::Font font)
// {
// 	sf::Vector2u wSize = window->getSize();
// 	if (shape->getLeft() <= 0 || shape->getRight() >= wSize.x)
// 	{
// 		shape->reverseXSpeed();
// 	}
// 	if (shape->getTop() <= 0 || shape->getBottom() >= wSize.y)
// 	{
// 		shape->reverseYSpeed();
// 	}
// 	shape->move();
// }

// int main()
// {
// 	const int wWidth = 800;
// 	const int wHeight = 600;
// 	const std::string wName = "Assignment 1";

// 	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), wName);
// 	sf::Font font;

// 	std::vector<CircleActor*> circles;
// 	std::vector<RectangleActor*> rectangles;
// 	std::vector<sf::Text*> circleTexts;
// 	std::vector<sf::Text*> rectangleTexts;
// 	std::string name;
// 	unsigned int fontSize = 10;
// 	sf::Color fontColor;

// 	std::ifstream file = loadConfigFile();

// 	while (file >> name)
// 	{
// 		if (name == "Rectangle")
// 		{
// 			float x, y, sx, sy, width, height;
// 			int r, g, b;

// 			file >> name;
// 			file >> x >> y;
// 			file >> sx >> sy;
// 			file >> r >> g >> b;
// 			file >> width >> height;

// 			sf::Color color(r, g, b);

// 			RectangleActor* rectangle = new RectangleActor(name, x, y, sx, sy, color, width, height);
// 			rectangles.push_back(rectangle);
// 			rectangle->print();

// 			sf::Text* text = new sf::Text();
// 			rectangleTexts.push_back(text);
// 		}
// 		else if (name == "Circle")
// 		{
// 			float x, y, sx, sy, radius;
// 			int r, g, b;

// 			file >> name;
// 			file >> x >> y;
// 			file >> sx >> sy;
// 			file >> r >> g >> b;
// 			file >> radius;

// 			sf::Color color(r, g, b);

// 			CircleActor* circle = new CircleActor(name, x, y, sx, sy, color, radius);
// 			circles.push_back(circle);
// 			circle->print();

// 			sf::Text* text = new sf::Text();
// 			circleTexts.push_back(text);
// 		}
// 		else if (name == "Font")
// 		{
// 			int size, r, g, b;
// 			file >> name;
// 			file >> size >> r >> g >> b;

// 			if (!font.loadFromFile(name))
// 			{
// 				std::cerr << "Bad font";
// 				exit(-1);
// 			}

// 			fontSize = size;
// 			fontColor = sf::Color(r, g, b);

// 			std::cout << "Font ready\n";
// 		}
// 		else if (name == "Window")
// 		{
// 			int width, height;
// 			file >> width >> height;

// 			window.setSize(sf::Vector2u(width, height));
// 		}
// 		else
// 		{
// 			window.setTitle(name);
// 		}
// 	}

// 	for (sf::Text* t : circleTexts)
// 	{
// 		t->setFont(font);
// 		t->setCharacterSize(fontSize);
// 		t->setFillColor(fontColor);
// 	}
// 	for (sf::Text* t : rectangleTexts)
// 	{
// 		t->setFont(font);
// 		t->setCharacterSize(fontSize);
// 		t->setFillColor(fontColor);
// 	}

// 	while (window.isOpen())
// 	{
// 		sf::Event event;
// 		while (window.pollEvent(event))
// 		{
// 			if (event.type == sf::Event::Closed) window.close();
// 		}
// 		window.clear();

// 		for (int i = 0; i < 3; ++i)
// 		{
// 			updateShape<CircleActor>(circles[i], &window, font);
// 			sf::CircleShape* shape = circles[i]->getShape();
// 			window.draw(*shape);

// 			std::string circleName = circles[i]->getName();
// 			//std::string circleName = "asd";

// 			float charsNumber = circleName.size();


// 			sf::Text text = sf::Text();
// 			text.setString(circleName);
// 			//text.setFont(font);
// 			text.setCharacterSize(fontSize);

// 			//sf::FloatRect rect = text.getLocalBounds();

// 			//float textX = circles[i]->getLeft() + (circles[i]->getWidth()) - rect.width / 2;
// 			//float textY = circles[i]->getTop() + (circles[i]->getHeight()) - rect.height / 2;
// 			text.setPosition(0, 0);

// 			window.draw(text);
// 		}
// 		for (int i = 0; i < 3; ++i)
// 		{
// 			updateShape<RectangleActor>(rectangles[i], &window, font);
// 			sf::RectangleShape* shape = rectangles[i]->getShape();
// 			window.draw(*shape);

// 			std::string rectangleName = rectangles[i]->getName();
// 			//std::string rectangleName = "asd";

// 			float charsNumber = rectangleName.size();


// 			sf::Text text = sf::Text();
// 			text.setString(rectangleName);
// 			//text.setFont(font);
// 			text.setCharacterSize(fontSize);

// 			sf::FloatRect rect = text.getLocalBounds();

// 			float textX = rectangles[i]->getLeft() + (rectangles[i]->getWidth() / 2) - rect.width/2;
// 			float textY = rectangles[i]->getTop() + (rectangles[i]->getHeight() / 2.f) - rect.height/2;
// 			text.setPosition(textX, textY);

// 			window.draw(text);
// 		}

// 		window.display();
// 	}

// 	return 0;
// }
