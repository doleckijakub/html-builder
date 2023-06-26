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