//
//  main.cpp
//  Task-2.1-Decorator
//
//  Created by Маргарет  on 30.07.2024.
//

#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};

class Decorator : public Text {
public:
    Decorator(Text* _text) : text(_text){}
    Text* text;
};

class Paragraph : public Decorator {
public:
    Paragraph(Text* _text) : Decorator(_text) {}
    void render(const std::string& data) {
        std::cout << "<p>";
        text->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public Decorator {
public:
    Reversed(Text* _text) : Decorator(_text) {}
    void render(std::string data) {
        std::reverse(data.begin(), data.end());
        text->render(data);
    }
};

class Link : public Decorator {
public:
    Link(Text* _text) : Decorator(_text) {}
    void render(std::string website, std::string data) {
        std::cout << "<a href=" << website << ">" << data << "</a>";
    }
};

int main(int argc, const char * argv[]) {
    auto par_text = new Paragraph(new Text());
    par_text->render("Hello");
    std::cout << "\n";
    auto rev_text = new Reversed(new Text());
    rev_text->render("Hello");
    std::cout << "\n";
    auto link_text =  new Link(new Text());
    link_text->render("netology.ru", "Hello");
    std::cout << "\n";
    return 0;
}
