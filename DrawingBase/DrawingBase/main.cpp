#include "graphics.h"

using namespace std;
using namespace mssm;

class Button {
    // fields for position and size
    Vec2d position;
    double width;
    double height;
    string text;
public:
    Button(Vec2d position, double width, double height, string text);
    void draw(Graphics& g);
    void addBttons(string text);
};

class Panel {
    // fields for position and size
    Vec2d position;
    double width;
    double height;
    vector<Button> Buttons;
public:
    void addBttons(string text);
    Panel(Vec2d position, double width, double height);
    void draw(Graphics& g);
};
//Button::Button(Vec2d pos, int w, int h)
//    {
//    position = pos;
//    width = w;
//    height = h;
//}

//Button::Button(Vec2d postition, int width, int height)
//{
//    position = position;
//    width = width;
//    height = height;
//}
Panel::Panel(Vec2d position, double width, double height)
    : position {position},
    width{width},
    height{height}
{

}

Button::Button(Vec2d position, double width, double height, string text)
      : position {position},
      width{width},
      height{height},
      text{text}
{
}

void Button::draw(Graphics& g)
{
    g.rect(position, width, height);
    g.text(position.x + 10, position.y + 25, 25, text);
}

void Panel::addBttons(string text) {

    Button button{{position.x + 10, 10 + position.y + 90*Buttons.size()}, width/3, height/5, text};

    Buttons.push_back(button);
}
void Panel::draw(Graphics &g){
    g.rect(position, width, height);
    for(double i = 0; i < Buttons.size(); i++){
        Buttons[i].draw(g);
  }
}
void graphicsMain(Graphics& g)
{
    Panel panel{{100, 100}, 300, 400};
    
    panel.addBttons("Ok");
    panel.addBttons("Cancel");
    panel.addBttons("Explode");
   
//    Button button1{{100,100},100, 40};
//    Button button2{{100,400},120, 20};
    while (g.draw()) {

        g.clear();

        panel.draw(g);

        for (const Event& e : g.events())
        {
            switch (e.evtType)
            {
            case EvtType::MousePress:
                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::MouseWheel:
                break;
            case EvtType::MouseMove:
                break;
            case EvtType::KeyPress:
                break;
            case EvtType::KeyRelease:
                break;
            default:
                break;
            }
        }
    }
}

int main()
{
    Graphics g("Drawing", 800, 600, graphicsMain);
}
