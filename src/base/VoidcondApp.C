#include "VoidcondApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<VoidcondApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

VoidcondApp::VoidcondApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  VoidcondApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  VoidcondApp::associateSyntax(_syntax, _action_factory);
}

VoidcondApp::~VoidcondApp()
{
}

// External entry point for dynamic application loading
extern "C" void VoidcondApp__registerApps() { VoidcondApp::registerApps(); }
void
VoidcondApp::registerApps()
{
  registerApp(VoidcondApp);
}

// External entry point for dynamic object registration
extern "C" void VoidcondApp__registerObjects(Factory & factory) { VoidcondApp::registerObjects(factory); }
void
VoidcondApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void VoidcondApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { VoidcondApp::associateSyntax(syntax, action_factory); }
void
VoidcondApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
