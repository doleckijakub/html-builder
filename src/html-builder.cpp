#include "html-builder.hpp"

namespace html {

element::element(const std::string &tag, const std::string &text, bool paired)
	: tag(tag), inner_text(text), paired(paired) {
}

element &element::addAttribute(const std::string &name, const std::string &value) {
	attributes.push_back({name, value});
	return *this;
}

element &element::operator<<(element el) {
	children.push_back(el);
	return *this;
}

element &element::operator<<(std::string content) {
	return *this << text(content);
}

void element::dumpToString(std::string &target) const {
	if (tag.empty()) {
		target += inner_text;
	} else {
		// start tag
		target += "<";
		target += tag;

		for (const auto &attr : attributes) {
			target += " ";
			target += attr.name;
			if (!attr.value.empty()) {
				target += "=\"";
				target += attr.value;
				target += "\"";
			}
		}

		if (!paired)
			target += " /";
		target += ">";

		// content
		target += inner_text;
		for (const auto &child : children) {
			child.dumpToString(target);
		}

		// end tag
		if (paired) {
			target += "</";
			target += tag;
			target += ">";
		}
	}
}

text::text(std::string content) : element("", content, false) {
}

html::html() : element("html", "", true) {
}
head::head() : element("head", "", true) {
}
body::body() : element("body", "", true) {
}
span::span() : element("span", "", true) {
}
main::main() : element("main", "", true) {
}
div::div() : element("div", "", true) {
}
h1::h1() : element("h1", "", true) {
}
h2::h2() : element("h2", "", true) {
}
h3::h3() : element("h3", "", true) {
}
h4::h4() : element("h4", "", true) {
}
h5::h5() : element("h5", "", true) {
}
h6::h6() : element("h6", "", true) {
}
p::p() : element("p", "", true) {
}
b::b() : element("b", "", true) {
}
i::i() : element("i", "", true) {
}
a::a() : element("a", "", true) {
}

input::input() : element("input", "", false) {
}
link::link() : element("link", "", false) {
}
meta::meta() : element("meta", "", false) {
}
img::img() : element("img", "", false) {
}
br::br() : element("br", "", false) {
}

} // namespace html