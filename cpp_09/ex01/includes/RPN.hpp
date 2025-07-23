#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
    static int evaluate(const std::string& expr);
private:
	RPN();
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
};

#endif
