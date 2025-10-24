## Домашнее задание к занятию «Структурные шаблоны: Proxy, Decorator, Adapter»

### Задание 1. Decorator

#### Цель задания
Научиться применять паттерн «Декоратор».

#### Описание

В программу рендеринга HTML из лекции добавьте новые классы для декорирования текста.
```
class Paragraph: ...

auto text_block = new Paragraph(new Text());
text_block->render("Hello world");

>>> <p>Hello world</p>
```

```
class Reversed: ...

auto text_block = new Reversed(new Text());
text_block->render("Hello world");

>>> dlrow olleH
```

```
class Link: ...

auto text_block = new Link(new Text());
text_block->render("netology.ru", "Hello world");

>>> <a href=netology.ru>Hello world</a>
```

#### Обратите внимание

1. Сигнатура метода `Link::render()` не совпадает с сигнатурой оригинального метода.
2. Для разворота строки используйте функцию `std::reverse`.
