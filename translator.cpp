#include "translator.hpp"
#include <iostream>
#include <sstream>

Translator::Translator( ASTContext& cxt )
	:cxt( cxt )
{
}

Expr* Translator::on_add( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	return new AddExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_sub( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new SubtrExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_mul( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new MulExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_div( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new DivExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_rem( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new RemExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_neg( Expr* ast_1 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	return new NegativeExpr( ast_1, cxt );
}

Expr* Translator::on_and( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.boolTy )
	{
		std::stringstream ss;		
		ss << "Expected bool type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.boolTy )
	{
		std::stringstream ss;		
		ss << "Expected bool type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new AndExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_or( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.boolTy )
	{
		std::stringstream ss;		
		ss << "Expected bool type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.boolTy )
	{
		std::stringstream ss;		
		ss << "Expected bool type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new OrExpr( ast_1, ast_2, cxt );
}
Expr* Translator::on_cond( Expr* ast_1, Expr* ast_2, Expr* ast_3 )
{
	if( ast_1->Check( cxt ) != &cxt.boolTy )
	{
		std::stringstream ss;		
		ss << "Expected bool type in conditional expression\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	return new ConditionalExpr( ast_1, ast_2, ast_3, cxt );
}

Expr* Translator::on_equal( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new EqualExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_inequal( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new NotEqualExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_less( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new LessExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_greater( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new GreaterExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_lesseq( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new LessEqualExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_greatereq( Expr* ast_1, Expr* ast_2 )
{
	if( ast_1->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 1\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( ast_2->Check( cxt ) != &cxt.intTy )
	{
		std::stringstream ss;		
		ss << "Expected int type in expression 2\n";
		throw std::runtime_error( ss.str().c_str() );
	}	
	return new GreaterEqualExpr( ast_1, ast_2, cxt );
}

Expr* Translator::on_not( Expr* ast_1 )
{
	if( ast_1->Check( cxt ) != &cxt.boolTy )
	{
		std::stringstream ss;		
		ss << "Expected bool type in not expression\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	return new NotExpr( ast_1, cxt );
}

stmt* Translator::on_decl_stmt( decl* d )
{
	return new decl_stmt( d );
}

stmt* Translator::on_expr_stmt( Expr* e )
{
	return new expr_stmt( e );
}

decl* Translator::on_var_decl( const Type* t, symbol* n )
{
	var_decl* var = new var_decl( n, t );
	// add the declaration of n as a variable
	return var;
}

decl* Translator::on_var_compl( decl* d, Expr* e )
{
	var_decl* var = static_cast<var_decl*>( d );
	var->set_init( e );
	return var;
}

const Type* Translator::on_bool_type() const
{
	return &cxt.boolTy;
}

const Type* Translator::on_int_type() const
{
	return &cxt.intTy;
}

symbol* Translator::on_id( Token* t )
{
	IdToken* id = dynamic_cast<IdToken*>( t );
	return id->name;
}
