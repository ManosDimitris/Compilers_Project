#include<iostream>
#include<vector>
#include "./quad.hpp"

vector<quad *> quads;

int main(){

    expr *expr_1 = NewExpr(var_e);
    expr *expr_10 = NewExpr(constnum_e);
    expr_10->numConst = 10;

    emit(assign, expr_10, NULL, expr_1, -1, 1);

    printQuads();

    return 0;
}
