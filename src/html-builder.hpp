#pragma once

#include <string>
#include <vector>

namespace html {

struct attribute {
	std::string name, value;
};

class element {
  protected:
	std::string tag, inner_text;
	bool paired;
	std::vector<element> children;
	std::vector<attribute> attributes;

	explicit element(const std::string &tag, const std::string &text = "", bool paired = true);

  public:
	element &addAttribute(const std::string &name, const std::string &value);

	element &operator<<(element el);

	element &operator<<(std::string);

	void dumpToString(std::string &) const;
};

struct text : public element {
	text(std::string content);
};

struct html : public element {
	explicit html();
};
struct head : public element {
	explicit head();
};
struct body : public element {
	explicit body();
};
struct span : public element {
	explicit span();
};
struct main : public element {
	explicit main();
};
struct div : public element {
	explicit div();
};
struct h1 : public element {
	explicit h1();
};
struct h2 : public element {
	explicit h2();
};
struct h3 : public element {
	explicit h3();
};
struct h4 : public element {
	explicit h4();
};
struct h5 : public element {
	explicit h5();
};
struct h6 : public element {
	explicit h6();
};
struct p : public element {
	explicit p();
};
struct b : public element {
	explicit b();
};
struct i : public element {
	explicit i();
};
struct a : public element {
	explicit a();
};

struct input : public element {
	explicit input();
};
struct link : public element {
	explicit link();
};
struct meta : public element {
	explicit meta();
};
struct img : public element {
	explicit img();
};
struct br : public element {
	explicit br();
};

} // namespace html