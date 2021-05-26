#include <iostream>
#include <string>
#include <memory>

struct Istrategy{ 
	virtual ~Istrategy(){}
	
	virtual auto compute(double x, double y) const -> double = 0;
	virtual auto name() const -> const std::string = 0; 
	virtual auto clone() const -> Istrategy* = 0;
}


class Context{
	
private :
	
	std::unique_ptr<Istrategy> _strategy;
	
public :

	Context()
		: _strategy(nullptr) {}
	Context(Istrategy* s)
		: _strategy{s} {}
	Context
		: _strategy{s.clone} {}
	auto setStrategy(IStrategy* s){
		_strategy.reset(s);
		}
	auto setStrategy(const IStrategy& s){
		_strategy.reset(s.clone());
		
		}
		
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

