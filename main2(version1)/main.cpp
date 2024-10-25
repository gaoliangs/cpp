#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "data.h"
#include "topo.h"
#include "symbol.h"
#include "matrix.h"
#include "func.h"
#include "output.h"
#include "util.h"
#include "symbolic.h"

int main() {
    std::string topo = "((COLST,(newdataHH_CATAU,(newdataPM_BUCRH_APAVI_LEPDI,TYTAL))),newdataCAGTM_newdataMN_FALPE_CARCR)";
    std::vector<std::string> taxaorder = splitTopo(topo);

    std::vector<std::vector<std::string>> data = readCSV("newseq1.csv");
    std::vector<std::string> taxaname = data[0];
    std::vector<std::vector<std::string>> taxadata(data.begin() + 1, data.end());

    std::vector<std::string> singletaxa, grouptaxa;
    std::tie(singletaxa, grouptaxa) = classifyTaxa(taxaname, data);

    std::vector<int> smloc = getIndices(taxaorder, singletaxa);
    std::vector<int> gm = getIndices(taxaname, grouptaxa);
    std::vector<int> gmloc = getIndices(taxaorder, grouptaxa);

    std::vector<std::string> markerdata = generateMarkerData(topo, taxaname, taxadata);
    std::vector<std::vector<std::string>> trivial_marker = generateTrivialMarker(taxaname.size(), gm);
    std::vector<std::string> trivialtopo = generateTrivialTopo(topo, taxaname, trivial_marker);

    int n_edge = countOccurrences(topo, '(') - 1;
    int n_leaf = taxaname.size();

    std::vector<Symbol> t = createSymbols('t', n_edge + 1);
    std::vector<Symbol> c = createSymbols('c', n_edge + 1);
    std::vector<Symbol> tl = createSymbols("tl", n_leaf + 1);

    Matrix matrix_leaf_group = createMatrixLeafGroup(tl[0]);
    Matrix matrix_internal = createMatrixInternal(t[0], c[0]);
    Matrix matrix_leaf = createMatrixLeaf();

    SymbolicExpression sumlambda = calculateSumLambda(t, c, n_leaf);

    writeLambdaFormulaCpp("lambda_formula.cpp", "lambda_formula.h", markerdata);
    writeLambdaFormulaTrivialCpp("lambda_formula_trivial.cpp", "lambda_formula_trivial.h", trivialtopo);
    writeVariablesCpp("variables.cpp", "variables.h", t, c, gmloc);
    writeTreeScoreToFile("treescore.m", n_edge, gm.size(), sumlambda);

    std::cout << "C++代码已经生成完毕。" << std::endl;

    return 0;
}
