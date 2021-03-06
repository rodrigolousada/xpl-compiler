#ifndef __CDK_VARIABLEDECLARATIONNODE_H__
#define __CDK_VARIABLEDECLARATIONNODE_H__

#include <cdk/ast/expression_node.h>
#include <string>

namespace xpl {

  /**
   * Class for describing variable declaration nodes.
   */
  class variable_declaration_node: public cdk::basic_node {
    bool _is_public;
    bool _is_used;
    basic_type * _type;
    std::string *_name;
    cdk::expression_node *_value;
    
  public:
    inline variable_declaration_node(int lineno, bool is_public, bool is_used, basic_type * type, std::string *name, cdk::expression_node * value) :
        cdk::basic_node(lineno), _is_public(is_public), _is_used(is_used), _type(type), _name(name), _value(value) {
    }


  public:
     inline bool is_public() {
      return _is_public;
    }
    
    inline bool is_used() {
      return _is_used;
    }

    inline basic_type *type() {
      return _type;
    }
    
    inline std::string *name() {
      return _name;
    }
    
    inline cdk::expression_node *value() {
      return _value;
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_declaration_node(this, level);
    }

  };

} // xpll

#endif