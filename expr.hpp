#ifndef EXPR_HPP
#define EXPR_HPP

#include "astcontext.hpp"

class BoolExpr;
class AndExpr;
class OrExpr;
class XorExpr;
class NotExpr;
class ConditionalExpr;
class OrElseExpr;
class AndThenExpr;
class IntExpr;
class NegativeExpr;
class AddExpr;
class SubtrExpr;
class MulExpr;
class DivExpr;
class RemExpr;
class EqualExpr;
class NotEqualExpr;
class LessExpr;
class GreaterExpr;
class LessEqualExpr;
class GreaterEqualExpr;
class IdExpr;

class Expr
{
public:    
    struct Visitor;
    virtual const Type* Check( ASTContext& context ) = 0;
    virtual void Accept( Visitor& ) = 0;
    virtual ~Expr();
};

struct Expr::Visitor
{    
    virtual void visit( BoolExpr* ) = 0;
    virtual void visit( AndExpr* ) = 0;
    virtual void visit( OrExpr* ) = 0;
    virtual void visit( XorExpr* ) = 0;
    virtual void visit( NotExpr* ) = 0;
    virtual void visit( ConditionalExpr* ) = 0;
    virtual void visit( OrElseExpr* ) = 0;
    virtual void visit( AndThenExpr* ) = 0;
    virtual void visit( IntExpr* ) = 0;
    virtual void visit( NegativeExpr* ) = 0;
    virtual void visit( AddExpr* ) = 0;
    virtual void visit( SubtrExpr* ) = 0;
    virtual void visit( MulExpr* ) = 0;
    virtual void visit( DivExpr* ) = 0;
    virtual void visit( RemExpr* ) = 0;
    virtual void visit( EqualExpr* ) = 0;
    virtual void visit( NotEqualExpr* ) = 0;
    virtual void visit( LessExpr* ) = 0;
    virtual void visit( GreaterExpr* ) = 0;
    virtual void visit( LessEqualExpr* ) = 0;
    virtual void visit( GreaterEqualExpr* ) = 0;
};

// BOOLEAN EXPRESSIONS

class BoolExpr : public Expr
{
public:    
    int value;
    BoolExpr( int val );
    const Type* Check( ASTContext& context ) override;
    void Accept( Visitor& v );
};

class AndExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    AndExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    const Type* Check( ASTContext& context ) override;
    void Accept( Visitor& v );
};

class OrExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    OrExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    
    const Type* Check( ASTContext& context ) override;
    void Accept( Visitor& v );
};

class XorExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    
    XorExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class NotExpr : public Expr
{
public:    
    Expr* e1;
    NotExpr( Expr* ex, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class ConditionalExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    Expr* e3;
    
    ConditionalExpr( Expr* ex_if, Expr* ex_then, Expr* ex_else, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class OrElseExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    OrElseExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class AndThenExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;

    AndThenExpr( Expr* ex_if, Expr* ex_then, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

// INTEGER EXPRESSIONS
class IntExpr : public Expr
{
public:    
    int value;
    IntExpr( int val, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class NegativeExpr : public Expr
{
public:
    Expr* e1;
    NegativeExpr( Expr* ex, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class AddExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    AddExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class SubtrExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    SubtrExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class MulExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    MulExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class DivExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    DivExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class RemExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    RemExpr( Expr* lhs, Expr* rhs, ASTContext& context );
    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class EqualExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    EqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;  
};

class NotEqualExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    NotEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;  
};

class LessExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    LessExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;

};

class GreaterExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    GreaterExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;

};

class LessEqualExpr : public Expr
{
public:
    Expr* e1;
    Expr* e2;
    LessEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;

};

class GreaterEqualExpr : public Expr
{
public:    
    Expr* e1;
    Expr* e2;
    GreaterEqualExpr( Expr* lhs, Expr* rhs, ASTContext& context );

    void Accept( Visitor& v );
    const Type* Check( ASTContext& context ) override;
};

class IdExpr : public Expr
{
};

#endif

