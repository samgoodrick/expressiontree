#ifndef EXPR_HPP
#define EXPR_HPP

#include <memory>

class Expr
{
public:
    virtual bool Evaluate() = 0;
    virtual ~Expr();
};

class TrueExpr : public Expr
{
    bool Evaluate(){ return true; }
};

class FalseExpr : public Expr
{
    bool Evaluate(){ return false; }
};

class AndExpr : public Expr
{
    Expr* e1;
    Expr* e2;
public:
    AndExpr( Expr* lhs, Expr* rhs );

    bool Evaluate();
};

class OrExpr : public Expr
{
    Expr* e1;
    Expr* e2;

    OrExpr( Expr* lhs, Expr* rhs );
    
    bool Evaluate();
};

class NotExpr : public Expr
{
    Expr* e;
public:
    NotExpr( Expr* ex );

    bool Evaluate();
};

#endif
