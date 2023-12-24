%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
 
  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  int para_num =0;
  FILE *output;


 int br_par = 0;
  int tip;
  int vrsta;
  bool ret=0;
  int jiro_idx;
  int br_arg = 0;
  int rel1;
  int rel2;
 int reg;
 int dvostruka=-1;
 int jiro_num=-1;
 int idx_switch=0;
 int tranga_num=-1;

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
%token _QMARK


%type <i> num_exp exp literal function_call argument rel_exp jiro_literal if_part postinc_statement nesto

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  :steva function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  | function_list
  {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

function_list
  : function
  | function_list function
  ;
  steva
  :g_prom
  |steva g_prom
  ;

g_prom
:_TYPE _ID _SEMICOLON
{
  if(lookup_symbol($2, GVAR) == NO_INDEX)
           insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
           code("\n%s: WORD\n 1",$2);
}
;
function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);

        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);

        else 
          err("Funkcija: '%s' je vec definisana!", $2);

        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter _RPAREN body
      {
        if(!ret && $1!=VOID)
         warning("Funkcija tipa INT/UNSIGNED treba da vrati vrednost odgovarajuceg tipa!");
        
        clear_symbols(fun_idx + br_par + 1);
        var_num = 0;
        br_par = 0;
        ret=0;

        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
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
            if(lookup_symbol($2,PAR) == NO_INDEX)
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
          if(lookup_symbol($4, PAR) == NO_INDEX)
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
  : _LBRACKET variable_list
  {
    if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));

        for(int idx = 14; idx <= get_last_element(); idx++)
    	  {
    	    if(get_atr2(idx) != 0 && get_kind(idx) == VAR)
    	      {
    	          gen_mov(get_atr2(idx), idx);
    	      }
    	      
    	    set_atr2(idx, 0);
    	  }


  } statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  :pocetak_var _SEMICOLON{

    for(int idx = 14; idx <= get_last_element(); idx++)
    	  {
    	    if(get_atr2(idx) == MAGIC_NUM && get_kind(idx) == VAR)
    	      {
    	          set_atr2(idx, 0);
    	      }
    	  }

  }
  |pocetak_var _ASSIGN num_exp _SEMICOLON
  { 
      if(tip != get_type($3))
        err("Tip deklarisanih varijabli i tip podatka koji im se dodeljuje se ne poklapaju");

        for(int idx = 14; idx <= get_last_element(); idx++)
    	  {
    	    if(get_atr2(idx) == MAGIC_NUM && get_kind(idx) == VAR)
    	      {
    	          set_atr2(idx, $3);
    	      }
    	  }

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
        if(lookup_symbol($1, VAR|PAR|GVAR) == NO_INDEX)  {        
           insert_symbol($1, VAR, tip, ++var_num, NO_ATR);
           set_atr2(lookup_symbol($1, VAR|PAR|GVAR) , MAGIC_NUM);
           }
        else 
           err("Promenjiva '%s' je vec definisana!", $1);
       }
| vars _COMMA _ID
{
        if(lookup_symbol($3, VAR|PAR|GVAR) == NO_INDEX)   {  
           insert_symbol($3, VAR, tip, ++var_num, NO_ATR);
           set_atr2(lookup_symbol($3, VAR|PAR|GVAR), MAGIC_NUM);
           }
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
      jiro_num++;
    }
   _LPAREN _ID
  {  
    idx_switch=lookup_symbol($4,VAR|PAR|GVAR);
    if(idx_switch==NO_INDEX){
    err(" Promenjiva '%s' mora biti prethodno deklarisana!",$4);}
    
    tip=get_type(idx_switch);
  }
   _RPAREN _LBRACKET tranga_exp toerana_exp _RBRACKET
  {
    code("\njiro_exit%d:",jiro_num);
    clear_symbols(jiro_idx+1);
  }
  ;

  break_exp
  :/*nista*/
  | _BREAK _SEMICOLON{

    code("\n\t\tJMP\tjiro_exit%d",jiro_num);
  }
  ;

  tranga_exp
  :_TRANGA jiro_literal
  {
    if(tip!=get_type($2)){
      err("Tip tranga iskaza mora biti istog tipa kao Jiro promenjiva!");
      }
      else{
    gen_cmp(idx_switch,$2);
    code("\n\t\t%s\t@tranga_false%d",opp_jumps[4 + ((tip - 1) * RELOP_NUMBER)],++tranga_num);}
  }
  _COLON statement break_exp{

    code("\n@tranga_false%d:",tranga_num);
  }

  |tranga_exp _TRANGA jiro_literal _COLON{
      if(tip!=get_type($3)){
      err("Tip tranga iskaza mora biti istog tipa kao Jiro promenjiva!");
      }
      else{
    gen_cmp(idx_switch,$3);
    code("\n\t\t%s\t@tranga_false%d",opp_jumps[4 + ((tip - 1) * RELOP_NUMBER)],++tranga_num);}
  } statement break_exp{
    code("\n@tranga_false%d:",tranga_num);
  }
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
      dvostruka++;
     int idx=lookup_symbol($4,ITR);
     if(idx==NO_INDEX){
       if($3==VOID){err("Ne moze inkeremnt biti tipa void!");
       }
      else{
        idx=insert_symbol($4,ITR,$3,(var_num+1+dvostruka),NO_ATR);
        code("\n@para%d:",++para_num);
        code("\n\t\tSUBS\t%%15,$4,%%15");
        code("\n\t\tMOV\t$0,-%d(%%14)",4*(var_num+1+dvostruka));
   
      code("\n@para_body%d:",para_num);
      }}
      
     else 
      err("Iterator '%s' vec postoji! ",$4);

     
    }
     _SEMICOLON rel_exp _SEMICOLON _PASO literal
    { 
     if(get_type(lookup_symbol($4,ITR))!=get_type($10))
        err("Iterator petlje '%s' i inkrement '%s' moraju biti istog tipa!",$4,get_name($10));

      code("\n\t\t%s\t@para_exit%d", opp_jumps[$7], para_num);
      code("\n@petlja%d:",para_num);
      
    } _RPAREN statement
   {  
     code("\n\t\tADDS\t-%d(%%14),$%s,-%d(%%14)",4*(var_num+1+dvostruka),get_name($10),4*(var_num+1+dvostruka));
     code("\n\t\tJMP\t@para_body%d",para_num);
     code("\n@para_exit%d:",para_num);
     if(dvostruka>=1){
       dvostruka--;
       para_num--;
     }else{
       dvostruka=-1;
       para_num++;
     }
     clear_symbols(lookup_symbol($4,ITR));
   }
  ;
postinc_statement:
_ID _POSTINC _SEMICOLON
 {
   int idx=lookup_symbol($1, VAR|PAR|ITR|GVAR);
    if(idx == NO_INDEX)      {    
      err("Promenjiva '%s' nema deklaraciju!", $1);}
      else{
        int a=get_type(idx);
        code("\n\t\t%s\t",ar_instructions[ADD + (a-1) * AROP_NUMBER]);

        gen_sym_name(idx);
        code(",");
        code("$1");
        code(",");
        gen_sym_name(idx);
     
      }
        
  }
;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX){
          err("Promenjiva '%s' nema deklaraciju!", $1);}
        else{
          if(get_type(idx) != get_type($3)){
            err("Promenjiva i vrednost koja joj se dodeljuje moraju biti istog tipa!");}
           gen_mov($3, idx);
            }
        
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3)){
          err("Promenjive u aritmetickim operacijama moraju biti istog tipa!");}
          else{
        int a = get_type($1);    
        code("\n\t\t%s\t", ar_instructions[$2 + (a - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, a);

         if(get_atr2($1)==1){
        code("\n\t\t%s\t", ar_instructions[(a - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        code("$1");
        code(",");
        gen_sym_name($1);
        set_atr2($1,0);
            }
        if(get_atr2($3)==1){
          a=get_type($3); 
         code("\n\t\t%s\t", ar_instructions[ (a - 1) * AROP_NUMBER]);
         gen_sym_name($3);
         code(",");
        code("$1");
        code(",");
        gen_sym_name($3);
        set_atr2($3,0);
        }
        }
      }
    
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|ITR|GVAR);
        if($$ == NO_INDEX)
          err("Promenjiva '%s' nema deklaraciju!", $1);
      }
  | function_call
  {
    $$ = take_reg();
    gen_mov(FUN_REG, $$);
  }
  |_ID _POSTINC
    { 
      $$=lookup_symbol($1, VAR|PAR|GVAR);
       if($$ == NO_INDEX)   {       
        err("Promenjiva '%s' nema deklaraciju!", $1);}
      else 
      {
        vrsta = get_kind($$);
      if(vrsta !=VAR && vrsta !=PAR && vrsta !=GVAR){
        err("Samo varijable i parametri mogu da se inkrementuju!");}
      else{
        set_atr2($$,1);
      }
        
      }
    }
    | function_call _POSTINC
    {
      err("Jezik ne podrzava postinkrement poziva funkcije! ('%s')",get_name(fcall_idx));
    }
   | _LPAREN num_exp _RPAREN
      { $$ = $2; }

   |_LPAREN
   rel_exp{
    code("\n\t\t%s\t@false%d", opp_jumps[$2], ++lab_num);
    code("\n@true%d:", lab_num);
   }
   _RPAREN _QMARK nesto _COLON nesto
   {
      $$ =take_reg();
      gen_mov($6,$$);
      code("\n\t\tJMP\t@exit%d",lab_num);
      code("\n@false%d:", lab_num);
      gen_mov($8,$$);

     code("\n@exit%d:", lab_num);
   }
;

nesto
:_ID
{
  if(lookup_symbol($1,VAR|PAR)==NO_INDEX)
    err("Promenljiva '%s' nema deklaraciju!",$1);

    $$=lookup_symbol($1,VAR|PAR);
}
|literal
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
          code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
          code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
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
        free_if_reg($1);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($1);
      $$ = br_arg;
    }
  |argument _COMMA num_exp
    { 
      br_arg++;
      if(get_type(fcall_idx+br_arg) != get_type($3))
        err("Tip promenjive argumenta '%s' se ne poklapa sa tipom parametra '%s' iz pozvane funkcije '%s' !",get_name($3),get_name(fcall_idx+br_arg),get_name(fcall_idx));
        free_if_reg($3);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($3);
      $$ = br_arg;
    }
  ;

if_statement
  : if_part %prec ONLY_IF
  { code("\n@exit%d:", $1); 
  if(get_atr2(rel1) == 1){
        
               int a = get_type(rel1);  
           	code("\n\t\t%s\t", ar_instructions[ADD + (a - 1) * AROP_NUMBER]);

           	gen_sym_name(rel1);
           	code(",");
           	code("$1");
           	code(",");
           	gen_sym_name(rel1);
    	   	set_atr2(rel1, 0);
        }
        
        if(get_atr2(rel2) == 1){
        
               int a = get_type(rel2);  
           	code("\n\t\t%s\t", ar_instructions[ADD + (a - 1) * AROP_NUMBER]);

           	gen_sym_name(rel2);
           	code(",");
           	code("$1");
           	code(",");
            gen_sym_name(rel2);
    	   	set_atr2(rel2, 0);
        }
      }

  | if_part _ELSE statement
  { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
  {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
        
  }
   rel_exp
   {
     code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
     code("\n@true%d:", $<i>3);
     
   } _RPAREN statement
   {

     code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
   }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("Tipovi promenjivih pri aritmetickim operacijama moraju biti isti!");
          $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
         
        gen_cmp($1, $3);

       if(get_atr2($1) == 1){
        	rel1 = $1;
        }
        
        if(get_atr2($3) == 1){
		rel2 = $3;
        }
        

       
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      { ret=1;
        if(get_type(fun_idx)==VOID)
          err("Void funkcija ne sme da vraca vrednost!");

        else if(get_type(fun_idx) != get_type($2))
          err("Funkcija ne vraca vrednost odgovarajuceg tipa!");
          gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx)); 
      }
  | _RETURN _SEMICOLON{
    ret=1;
    if(get_type(fun_idx)!=VOID)
      warning("Funkcija tipa INT/UNSIGNED treba da vrati vrednost odgovarajuceg tipa! ");
      
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx)); 
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
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();  
  fclose(output);

  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr) 
  return -1;
  else return error_count;
  }