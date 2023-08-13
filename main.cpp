#include <iostream>
#include <string>
int command(std::string &str) {
  if (str == "move") return 1;
  else if (str == "resize") return 2;
  else if (str == "display") return 3;
  else if (str == "close") return 4;
  else return 0;
}

class Display {
  int y = 50;
  int x = 80;
 public:
  int ValueX() {
    return x;
  }
  int ValueY() {
    return y;
  }
};

class Window {
  int x = 0;
  int y = 50;
  int width = 20;
  int height = 20;
  Display display_;
 public:
  //----------------------------------------------------------
  void Move() {
    std::cout << "Enter coordinate X:";
    std::cin >> x;
    if (x > display_.ValueX()) x = display_.ValueX();
    if (x < 0) x = 0;
    std::cout << "Enter coordinate Y:";
    std::cin >> y;
    if (y > display_.ValueY()) y = display_.ValueY();
    if (y < 0) y = 0;
    std::cout << "Coordinate X: " << x << " Coordinate Y: " << y << std::endl;
  }
  //----------------------------------------------------------
  void Resize() {
    std::cout << "Enter window width:";
    std::cin >> width;
    if (x + width > display_.ValueX()) width = display_.ValueX();
    if (width < 0) width = 0;
    std::cout << "Enter window height:";
    std::cin >> height;
    if (y - height < 0) height = 0;
    if (y < 0) height = 0;
    std::cout << "Window width: " << width << " Window height: " << height << std::endl;
  }
  //----------------------------------------------------------
  void Display() {
    for (int k = 1; k <= 50; k++) {
      for (int i = 1; i <= 80; ++i) {
        if (i > x && i < (x + width) && k > (50 - y) && k < (50 - y + height))
          std::cout << 1;
        else
          std::cout << 0;
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  Window window;
  std::string str;

  do {
    std::cout << "Enter command: "
              << "<move> <resize> <display> or <close>" << std::endl;
    std::cin >> str;
    switch (command(str)) {
      case 1://if move
        window.Move();
        break;
      case 2://if resize
        window.Resize();
        break;
      case 3://if display
        window.Display();
        break;
      case 4:// if close
        std::cout << "Work finished." << std::endl;
        break;
      case 0://if error
        std::cout << "Enter error command. Repeat please." << std::endl;
    }
  } while (str != "close");
  return 0;
}
