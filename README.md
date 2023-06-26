# HTML Builder

My HTML builder is a simple C++ utility based on the [builder design pattern](https://en.wikipedia.org/wiki/Builder_pattern). An example of this utility usage can be seen in [example.cpp](example.cpp).

## Compilation

The [src](src) directory provides two files, one [header](src/html-builder.hpp) and one [source](src/html-builder.cpp). To compile the program either use the provided [Makefile](Makefile) by doing

```terminal
$ make all
```

Or simply, using your compiler of choice compile the [source file](src/html-builder.cpp) as either a library or add it to the executable sources.

## Usage

*__Note__: At the moment, no extensive documentation is provided with the library. To see an example of the library in work, you can refer to [example.cpp](example.cpp).*

To use HTML builder, there are four functions you need to know

### Constructors

Many HTML elements are [supported](#support) by the library and can be instatiated in code by calling their constructors. The classes are called in the same way as the HTML elements, eg.

```cpp
html::body body = html::body();
```

### Stream insertion operator

To append content to an element, the stream insertion operator should be used. It allows for appending children elements and plain text into the body of an element, eg.

```cpp
body << "Lorem ipsum dolor sit amet, consectetur adipiscing elit" << html::br();
```

### addAttribute

At the moment, the only way to alter the elements' attributes is the addAttribute function, it can be called on any object inherited from html::element, and it's arguments are `attribute name` and `value`, eg.

```cpp
body << html::a().addAttribute("href", "example.com");
```

### dumpToString

To get the resulting HTML as std::string, simply use dumpToString function on the root element of the html structure;

```cpp
std::string output;
body.dumpToString(output);
std::cout << output << std::endl;
```

## Final usage example

By combining all four of the aforementioned functions, any html document can be built. Below is an example showed in [example.cpp](example.cpp) and its output;

```cpp
#include "html-builder.hpp"

#include <iostream>

int main() {
	auto html = html::html();

	{
		auto head = html::head();

		head << html::link().addAttribute("rel", "stylesheet").addAttribute("href", "style.css");
		head << html::link().addAttribute("rel", "stylesheet").addAttribute("href", "index.css");

		html << head;
	}

	{
		auto body = html::body();

		body << (html::a().addAttribute("href", "//google.com") << html::img().addAttribute("src", "some_image.png"));

		html << body;
	}

	std::string output;

	html.dumpToString(output);

	std::cout << output;
}
```

Plain output:

```html
<html><head><link rel="stylesheet" href="style.css" /><link rel="stylesheet" href="index.css" /></head><body><a href="//google.com"><img src="some_image.png" /></a></body></html>
```

Output parsed to show the structure:

```html
<html>
	<head>
		<link rel="stylesheet" href="style.css" />
		<link rel="stylesheet" href="index.css" />
	</head>
	<body>
		<a href="//google.com">
			<img src="some_image.png" />
		</a>
	</body>
</html>
```

## Support

The HTML Builder at the moment supports these HTML elements:

- html
- head
- body
- span
- h1
- h2
- h3
- h4
- h5
- h6
- p
- b
- i
- a
- input
- link
- meta
- img
- br

But is there is any HTMl element you don't see implemented, feel free to mention that in [issues](https://github.com/doleckijakub/html-builder/issues) or simply create your own element by inheriting from html::element class

```cpp
struct unimplemented_html_element : public html::element {
	explicit unimplemented_html_element() : element("unimplemented_html_element", "", true) {}
};
```

The string `"unimplemented_html_element"` is the name of the element in html code.
The string `""` is the initial content of the element and should usually be empty.
The value `true` indicates whether elements of this type should be paired.

Example of paired element:
```html
<p></p>
```

Example of unpaired element:
```html
<br />
```
