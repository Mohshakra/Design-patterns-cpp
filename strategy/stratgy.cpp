#include <iostream>
#include <string>
#include <memory>

struct IStrategy{ 

	virtual ~IStrategy(){std::cout << std::endl;}
	virtual auto compute(double x, double y) const -> double = 0;
	virtual auto name() const -> const std::string = 0; 
	virtual auto clone() const -> IStrategy* = 0;

};


class Context{
	
private :
	
	std::unique_ptr<IStrategy> _strategy;
	
public :

	Context()
		: _strategy(nullptr) {}
	// Context(IStrategy* s)
	// 	: _strategy{s} {}

	Context(IStrategy& s)
		
		: _strategy(s.clone()) 
		
		{
			std::cout << "hello world";
		}

	auto setStrategy(IStrategy* s){
		_strategy.reset(s);
		}



	// auto setStrategy(const IStrategy& s){
	// 	_strategy.reset(s.clone());
		
	// 	}
		
	auto compute(double x, double y) -> void {
		if(_strategy == nullptr)
			std::runtime_error("ERROR: strategy not set");
		double result = _strategy->compute(x, y);
		std::cout << " Strategy = " << _strategy->name() << " "
				
				<< "(  x = " << x << " ; "
				<< "y = " << y << " )"
				<< "\n";
				std::cout << "Result = " << result << "\n";
		
		}

};


class AddStrategy: public IStrategy 
{

	public :
		auto name() const -> const std::string{
			return "add";
		}
		auto compute(double x, double y) const -> double {
			return x + y ; 
		}
		auto clone() const -> IStrategy* {
			std::cerr << "\n     [Trace] AddStrategy => I was cloned "<< "\n" ;
			return new AddStrategy(*this);
		}


};

class MulStrategy: public IStrategy 
{
	public :

		auto name() const -> const std::string{
			return "Multiplication";
		}
		auto compute(double x, double y) const -> double {
			return x * y;
		}
		auto clone() const -> IStrategy*{
			std::cerr << "\n  [Trace] MulStrategy => I was cloned" << "\n";
			return new MulStrategy(*this);
		}


};

class SubStrategy: public IStrategy 
{

	public :
		auto name() const -> const std::string{
			return "Subtract";
		}
		auto compute(double x, double y) const -> double {
			return x - y ; 
		}
		auto clone() const -> IStrategy* {
			std::cerr << "\n    [Trace] AddStrategy => I was cloned "<< "\n" ;
			return new SubStrategy(*this);
		}
	
	

};


int main(){

	Context ctx;
	// std::cout << "====== Straregy = add =====" << "\n";
	ctx.setStrategy(new AddStrategy);
	ctx.compute(3.0, 4.0);

	// std::cout <<  "====== Straregy = mul =====" << "\n";
	ctx.setStrategy(new MulStrategy);
	ctx.compute(2, 5);

	// std::cout <<  "====== Straregy = Sub =====" << "\n";
	ctx.setStrategy(new SubStrategy);
	ctx.compute(5, 1);



	return 0;
}