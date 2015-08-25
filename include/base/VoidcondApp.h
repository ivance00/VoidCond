#ifndef VOIDCONDAPP_H
#define VOIDCONDAPP_H

#include "MooseApp.h"

class VoidcondApp;

template<>
InputParameters validParams<VoidcondApp>();

class VoidcondApp : public MooseApp
{
public:
  VoidcondApp(InputParameters parameters);
  virtual ~VoidcondApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* VOIDCONDAPP_H */
