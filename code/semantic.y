%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;

  int br_par = 0;
  int tip;
  int vrsta;
  bool ret=0;
  int jiro_idx;
  int br_arg = 0;
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP

%token _COMMA
%token _POSTINC
%token _PARA
%token _PASO
%token _JIRO
%token _TRANGA
%token _TOERANA
%token _COLON
%token _BREAK


%type <i> num_exp exp literal function_call argument rel_exp jiro_literal

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("Program mora da sadrzi main() funkciju");
       }
  ;

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);

        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);

        else 
          err("Funkcija: '%s' je vec definisana!", $2);
      }
    _LPAREN parameter _RPAREN body
      {
        if(!ret && $1!=VOID)
         warning("Funkcija tipa INT/UNSIGNED treba da vrati vrednost odgovarajuceg tipa!");
        
        clear_symbols(fun_idx + br_par + 1);
        var_num = 0;
        br_par = 0;
        ret=0;
      }
  ;

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | _TYPE _ID
      {
        if($1 == VOID)
          err("Promenjive ne mogu da budu VOID tipa");

        else{
            if(lookup_symbol($2, VAR|PAR) == NO_INDEX)
            {
              insert_symbol($2, PAR, $1, ++br_par, NO_ATR);
              set_atr1(fun_idx, br_par);
              set_atr2(fun_idx, $1);
            }

            else
              err("Promenjiva '%s' je vec definisana", $2);
            }
      }
  | parameter _COMMA _TYPE _ID
      {
        if(get_type($3) == VOID)
            err("Promenjive ne mogu da budu VOID tipa");

        else{
          if(lookup_symbol($4, VAR|PAR) == NO_INDEX)
          {
            insert_symbol($4, PAR, $3, ++br_par, NO_ATR);
            set_atr1(fun_idx, br_par);
            set_atr2(fun_idx, $3);
          }
          else
            err("Promenjiva '%s' je vec definisana",$4);
            }
      }
  ;

body
  : _LBRACKET variable_list statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  :pocetak_var _SEMICOLON
  |pocetak_var _ASSIGN num_exp _SEMICOLON
  { 
      if(tip != get_type($3))
        err("Tip deklarisanih varijabli i tip podatka koji im se dodeljuje se ne poklapaju");
  }
  ;

pocetak_var
:_TYPE
    {if($1==VOID)
    err("Promenjiva ne moze biti tipa VOID!");
    tip=$1;
    } 
  vars 
;

vars
: _ID 
       {
        if(lookup_symbol($1, VAR|PAR) == NO_INDEX)          
           insert_symbol($1, VAR, tip, ++var_num, NO_ATR);
        else 
           err("Promenjiva '%s' je vec definisana!", $1);
       }
| vars _COMMA _ID
{
        if(lookup_symbol($3, VAR|PAR) == NO_INDEX)     
           insert_symbol($3, VAR, tip, ++var_num, NO_ATR);
        else 
           err("Promenjiva '%s' je vec definisana!", $3);
      }
;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | postinc_statement
  | return_statement
  | para_statement
  | jiro_statement
  ;

  jiro_statement
  :_JIRO 
    {
      jiro_idx=get_last_element();
    }
   _LPAREN _ID
  {  
    if(lookup_symbol($4,VAR|PAR)==NO_INDEX)
    err(" Promenjiva '%s' mora biti prethodno deklarisana!",$4);
    tip=get_type(lookup_symbol($4,VAR|PAR));
  }
   _RPAREN _LBRACKET tranga_exp toerana_exp _RBRACKET
  {
    clear_symbols(jiro_idx+1);
  }
  ;

  break_exp
  :/*nista*/
  | _BREAK _SEMICOLON
  ;

  tranga_exp
  :_TRANGA jiro_literal
  {
    if(tip!=get_type($2))
      err("Tip tranga iskaza mora biti istog tipa kao Jiro promenjiva!");
  }
  _COLON statement break_exp

  |tranga_exp _TRANGA jiro_literal _COLON statement break_exp
  ;
jiro_literal
:_INT_NUMBER
    { 
      if(lookup_symbol($1,JLIT)==NO_INDEX)
        $$ = insert_symbol($1, JLIT, INT ,NO_ATR, NO_ATR);
      else 
        err("Svi literali u tranga iskazu se moraju razlikovati! ('%s')",$1);
    }

| _UINT_NUMBER
    { 
        if(lookup_symbol($1,JLIT)==NO_INDEX)
          $$ = insert_symbol($1, JLIT, UINT ,NO_ATR, NO_ATR);
        else 
          err("Svi literali u tranga iskazu se moraju razlikovati! ('%s')",$1);
    }
;
  toerana_exp
  :/* nista*/
  |_TOERANA _COLON statement 
  ;

    para_statement
  :_PARA _LPAREN _TYPE _ID 
    {
     int ind=lookup_symbol($4,ITR);
     if(ind==NO_INDEX)
      insert_symbol($4,ITR,$3,NO_ATR,NO_ATR);

     else 
      err("Iterator '%s' vec postoji! ",$4);
    }
     _SEMICOLON rel_exp _SEMICOLON _PASO literal
    { 
     if(get_type(lookup_symbol($4,ITR))!=get_type($10))
        err("Iterator petlje '%s' i inkrement '%s' moraju biti istog tipa!",$4,get_name($10));
      
    } _RPAREN statement
   {   
     clear_symbols(lookup_symbol($4,ITR));
   }
  ;
postinc_statement:
_ID _POSTINC _SEMICOLON
 {
    if((lookup_symbol($1, VAR|PAR|ITR)) == NO_INDEX)          
      err("Promenjiva '%s' nema deklaraciju!", $1);
        
  }
;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        if(idx == NO_INDEX)
          err("Promenjiva '%s' nema deklaraciju!", $1);
        else
          if(get_type(idx) != get_type($3))
            err("Promenjiva i vrednost koja joj se dodeljuje moraju biti istog tipa!");
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("Promenjive u aritmetickim operacijama moraju biti istog tipa!");
      }
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|ITR);
        if($$ == NO_INDEX)
          err("Promenjiva '%s' nema deklaraciju!", $1);
      }
  | function_call
  |_ID _POSTINC
    {
       if((lookup_symbol($1, VAR|PAR)) == NO_INDEX)          
        err("Promenjiva '%s' nema deklaraciju!", $1);
      else 
      {
        vrsta = get_kind(lookup_symbol($1, VAR|PAR));
      if(vrsta !=VAR && vrsta !=PAR)
        err("Samo varijable i parametri mogu da se inkrementuju!");
      }    
      $$=lookup_symbol($1, VAR|PAR);
    }
    | function_call _POSTINC
    {
      err("Jezik ne podrzava postinkrement poziva funkcije! ('%s')",get_name(fcall_idx));
    }
;
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' nije funkcija!", $1);
      }
    _LPAREN argument _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("Broj argumenata poziva funkcije '%s' nije ispravan!",get_name(fcall_idx));
        else
        {
          set_type(FUN_REG, get_type(fcall_idx));
          $$ = FUN_REG;
          br_arg=0;
        }
      
      }
  ;

argument
  : /* empty */
    { $$ = 0; }

  | num_exp
    { 
      br_arg++;
      if(get_type(fcall_idx+br_arg) != get_type($1))
        err("Tip promenjive argumenta '%s' se ne poklapa sa tipom parametra '%s' iz pozvane funkcije '%s' !",get_name($1),get_name(fcall_idx+br_arg),get_name(fcall_idx));

      $$ = br_arg;
    }
  |argument _COMMA num_exp
    { 
      br_arg++;
      if(get_type(fcall_idx+br_arg) != get_type($3))
        err("Tip promenjive argumenta '%s' se ne poklapa sa tipom parametra '%s' iz pozvane funkcije '%s' !",get_name($3),get_name(fcall_idx+br_arg),get_name(fcall_idx));
      $$ = br_arg;
    }
  ;

if_statement
  : if_part %prec ONLY_IF
  | if_part _ELSE statement
  ;

if_part
  : _IF _LPAREN rel_exp _RPAREN statement
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("Tipovi promenjivih pri aritmetickim operacijama moraju biti isti!");
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      { ret=1;
        if(get_type(fun_idx)==VOID)
          err("Void funkcija ne sme da vraca vrednost!");

        else if(get_type(fun_idx) != get_type($2))
          err("Funkcija ne vraca vrednost odgovarajuceg tipa!");
      }
  | _RETURN _SEMICOLON{
    ret=1;
    if(get_type(fun_idx)!=VOID)
      warning("Funkcija tipa INT/UNSIGNED treba da vrati vrednost odgovarajuceg tipa! ");
  }
  ;
  

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  clear_symtab();  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr) 
  return -1;
  else return error_count;
  }