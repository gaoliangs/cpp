#include "lambda_formula.h"

std::vector<std::string> getLambdaFormula() {
    return {
        "((1,(1,(1,1))),0)",
        "((?,(01,(01,0))),0)",
        "((1,(0,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(01,(01,1))),01)",
        "((?,(0,(1,1))),0)",
        "((0,(0,(1,1))),1)",
        "((0,(0,(1,1))),0)",
        "((0,(0,(0,1))),01)",
        "((1,(1,(1,0))),0)",
        "((?,(01,(01,1))),1)",
        "((?,(0,(01,0))),01)",
        "((1,(01,(1,?))),1)",
        "((0,(1,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((1,(1,(01,0))),0)",
        "((?,(1,(01,1))),0)",
        "((0,(0,(1,1))),0)",
        "((1,(1,(1,1))),0)",
        "((1,(1,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(1,(1,?))),0)",
        "((0,(1,(1,1))),0)",
        "((?,(1,(1,1))),0)",
        "((?,(1,(01,0))),01)",
        "((0,(1,(1,1))),1)",
        "((1,(0,(1,1))),1)",
        "((0,(0,(1,1))),1)",
        "((0,(01,(01,1))),0)",
        "((0,(1,(1,1))),01)",
        "((0,(1,(1,1))),0)",
        "((?,(1,(1,1))),0)",
        "((0,(1,(01,0))),0)",
        "((0,(0,(1,0))),1)",
        "((0,(1,(1,?))),0)",
        "((1,(1,(1,1))),0)",
        "((?,(1,(0,1))),0)",
        "((0,(0,(01,1))),1)",
        "((1,(01,(01,0))),1)",
        "((?,(0,(0,1))),01)",
        "((?,(1,(0,?))),1)",
        "((?,(01,(0,?))),1)",
        "((?,(01,(0,?))),1)",
        "((?,(0,(1,?))),1)",
        "((?,(1,(0,0))),1)",
        "((0,(01,(0,0))),1)",
        "((0,(1,(0,0))),1)",
        "((?,(0,(01,0))),01)",
        "((?,(0,(1,?))),1)",
        "((0,(01,(0,0))),1)",
        "((?,(1,(0,?))),1)",
        "((0,(01,(0,0))),1)",
        "((0,(0,(1,0))),01)",
        "((0,(0,(0,1))),1)",
        "((?,(01,(0,1))),1)",
        "((0,(1,(0,0))),1)",
        "((0,(01,(01,0))),0)",
        "((?,(1,(?,1))),0)",
        "((0,(1,(0,1))),01)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((?,(01,(?,1))),1)",
        "((0,(0,(1,?))),1)",
        "((0,(1,(01,1))),0)",
        "((?,(1,(1,0))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(0,(0,1))),1)",
        "((1,(1,(1,1))),0)",
        "((?,(1,(0,1))),0)",
        "((?,(1,(0,1))),0)",
        "((?,(0,(0,1))),1)",
        "((1,(0,(0,0))),01)",
        "((1,(0,(0,0))),01)",
        "((1,(0,(0,0))),01)",
        "((1,(1,(0,0))),0)",
        "((1,(0,(0,0))),1)",
        "((1,(01,(1,?))),1)",
        "((1,(0,(1,1))),0)",
        "((1,(0,(0,0))),1)",
        "((1,(1,(0,?))),1)",
        "((1,(1,(0,0))),0)",
        "((1,(0,(0,0))),01)",
        "((1,(1,(0,0))),0)",
        "((1,(0,(0,1))),0)",
        "((1,(1,(0,1))),0)",
        "((1,(1,(0,0))),01)",
        "((1,(01,(0,0))),0)",
        "((0,(1,(1,0))),1)",
        "((1,(1,(0,?))),0)",
        "((1,(01,(0,?))),0)",
        "((1,(1,(?,1))),0)",
        "((?,(0,(1,0))),1)",
        "((0,(01,(1,0))),0)",
        "((?,(01,(1,?))),1)",
        "((?,(01,(1,0))),01)",
        "((?,(1,(0,0))),1)",
        "((?,(1,(1,?))),0)",
        "((?,(01,(0,0))),1)",
        "((1,(1,(1,1))),0)",
        "((?,(1,(0,?))),1)",
        "((0,(1,(1,?))),1)",
        "((?,(1,(0,1))),0)",
        "((0,(01,(0,1))),0)",
        "((1,(1,(0,0))),0)",
        "((?,(1,(0,1))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(1,(0,1))),0)",
        "((?,(1,(0,1))),0)",
        "((?,(01,(?,1))),0)",
        "((0,(01,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((1,(1,(1,1))),0)",
        "((0,(0,(1,1))),?)",
        "((1,(0,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((1,(1,(1,0))),0)",
        "((1,(1,(1,1))),01)",
        "((1,(01,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(0,(1,0))),01)",
        "((1,(1,(1,1))),0)",
        "((1,(0,(1,0))),0)",
        "((1,(1,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((1,(0,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(0,(1,0))),01)",
        "((0,(1,(1,1))),01)",
        "((?,(01,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(1,(01,1))),0)",
        "((1,(1,(01,0))),01)",
        "((0,(1,(1,0))),0)",
        "((?,(1,(1,1))),0)",
        "((0,(0,(01,1))),0)",
        "((1,(0,(1,1))),0)",
        "((?,(1,(1,1))),01)",
        "((?,(0,(1,1))),1)",
        "((1,(0,(1,0))),0)",
        "((0,(1,(1,?))),0)",
        "((?,(0,(01,0))),1)",
        "((1,(0,(1,1))),01)",
        "((1,(0,(1,1))),01)",
        "((?,(01,(1,?))),1)",
        "((1,(?,(1,1))),0)",
        "((?,(0,(1,1))),0)",
        "((1,(1,(1,1))),0)",
        "((1,(1,(0,0))),1)",
        "((0,(0,(1,1))),0)",
        "((?,(1,(1,1))),0)",
        "((0,(1,(1,0))),0)",
        "((?,(0,(01,0))),1)",
        "((0,(1,(1,0))),0)",
        "((0,(1,(01,0))),0)",
        "((0,(1,(1,?))),0)",
        "((0,(1,(1,0))),0)",
        "((1,(1,(01,1))),1)",
        "((0,(1,(1,1))),1)",
        "((1,(1,(1,0))),1)",
        "((0,(01,(1,?))),0)",
        "((?,(1,(1,?))),0)",
        "((1,(01,(1,1))),0)",
        "((0,(1,(01,0))),01)",
        "((1,(0,(01,1))),1)",
        "((1,(0,(1,1))),0)",
        "((0,(1,(1,0))),0)",
        "((0,(0,(1,1))),0)",
        "((?,(0,(1,0))),1)",
        "((0,(0,(1,1))),0)",
        "((0,(01,(1,1))),0)",
        "((0,(0,(01,1))),1)",
        "((0,(01,(1,1))),0)",
        "((?,(1,(01,0))),0)",
        "((1,(0,(1,0))),1)",
        "((1,(1,(1,0))),1)",
        "((1,(1,(1,?))),0)",
        "((0,(1,(1,1))),0)",
        "((1,(1,(1,1))),0)",
        "((0,(1,(1,1))),1)",
        "((1,(1,(1,?))),0)",
        "((0,(1,(1,1))),0)",
        "((?,(01,(01,1))),0)",
        "((?,(0,(1,1))),1)",
        "((1,(1,(1,1))),01)",
        "((0,(1,(1,0))),0)",
        "((1,(01,(1,1))),1)",
        "((0,(1,(1,1))),0)",
        "((0,(1,(1,1))),1)",
        "((0,(0,(1,1))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((?,(1,(1,1))),01)",
        "((?,(1,(1,1))),0)",
        "((0,(1,(01,0))),0)",
        "((1,(1,(1,?))),0)",
        "((?,(1,(1,1))),0)",
        "((0,(01,(1,1))),0)",
        "((?,(1,(1,1))),0)",
        "((?,(1,(1,?))),0)",
        "((0,(1,(1,1))),0)",
        "((?,(1,(01,1))),0)",
        "((1,(0,(1,1))),0)",
        "((?,(1,(1,0))),1)",
        "((0,(0,(1,1))),0)",
        "((?,(0,(1,1))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(01,(1,1))),0)",
        "((0,(1,(1,0))),0)",
        "((0,(0,(01,1))),0)",
        "((?,(1,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(01,(1,?))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(0,(1,1))),0)",
        "((1,(0,(1,0))),0)",
        "((?,(01,(01,?))),0)",
        "((1,(1,(1,1))),0)",
        "((0,(01,(1,0))),0)",
        "((1,(1,(1,1))),0)",
        "((1,(1,(1,0))),0)",
        "((?,(1,(1,?))),0)",
        "((0,(0,(1,1))),0)",
        "((0,(0,(1,0))),1)",
        "((1,(0,(1,0))),0)",
        "((1,(1,(01,0))),0)",
        "((0,(1,(1,1))),0)",
        "((0,(01,(1,?))),0)",
        "((0,(1,(01,?))),0)",
        "((0,(1,(1,0))),?)",
        "((0,(0,(01,0))),01)",
        "((0,(0,(1,1))),1)",
        "((?,(1,(0,0))),01)",
        "((?,(1,(1,0))),0)",
        "((?,(01,(0,1))),01)",
        "((?,(1,(01,1))),0)",
        "((?,(1,(1,1))),01)",
        "((?,(1,(01,?))),0)",
        "((?,(01,(1,1))),0)",
        "((?,(0,(1,1))),0)",
        "((0,(1,(0,?))),1)",
        "((1,(0,(0,1))),1)",
        "((?,(1,(0,1))),0)",
        "((1,(01,(0,1))),0)",
        "((?,(01,(1,1))),1)",
        "((0,(1,(1,1))),1)",
        "((?,(1,(1,0))),0)",
        "((?,(1,(1,1))),0)",
        "((0,(1,(01,1))),0)",
        "((1,(1,(01,1))),1)",
        "((0,(1,(0,0))),1)",
        "((1,(01,(1,0))),1)",
        "((0,(1,(01,0))),0)",
        "((?,(1,(1,1))),0)",
        "((1,(0,(0,0))),01)",
        "((?,(1,(1,0))),0)",
        "((?,(1,(0,1))),1)",
        "((1,(1,(1,1))),01)",
        "((?,(0,(0,1))),1)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(01,(0,1))),0)",
        "((1,(1,(01,1))),0)",
        "((0,(0,(01,1))),0)",
        "((1,(0,(0,1))),0)",
        "((0,(0,(0,1))),01)",
        "((0,(0,(0,1))),1)",
        "((1,(0,(01,1))),0)",
        "((0,(01,(0,1))),0)",
        "((0,(1,(?,1))),0)",
        "((1,(?,(1,0))),1)",
        "((?,(1,(0,1))),0)",
        "((0,(0,(0,1))),01)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((1,(0,(0,1))),0)",
        "((?,(0,(0,1))),1)",
        "((0,(1,(0,1))),0)",
        "((1,(0,(0,1))),0)",
        "((0,(1,(?,1))),0)",
        "((1,(01,(0,1))),0)",
        "((1,(0,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(1,1))),0)",
        "((?,(0,(0,1))),1)",
        "((0,(1,(01,1))),0)",
        "((?,(01,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((1,(1,(0,1))),0)",
        "((1,(0,(0,1))),0)",
        "((0,(0,(0,1))),01)",
        "((1,(01,(0,1))),1)",
        "((1,(1,(0,1))),0)",
        "((0,(01,(0,1))),1)",
        "((?,(01,(0,1))),0)",
        "((0,(0,(01,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(01,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),0)",
        "((0,(1,(0,1))),1)",
        "((?,(1,(0,1))),0)"
    };
}