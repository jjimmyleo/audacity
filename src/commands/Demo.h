/**********************************************************************

  Audacity: A Digital Audio Editor

  Demo.h

  James Crook

**********************************************************************/

#ifndef __AUDACITY_DEMO_COMMAND__
#define __AUDACITY_DEMO_COMMAND__

#include <wx/event.h>
#include <wx/string.h>
#include <wx/textctrl.h>

#include "AudacityCommand.h"
#include "../SampleFormat.h"

class ShuttleGui;

#define DEMO_PLUGIN_SYMBOL XO("Demo")

class DemoCommand final : public AudacityCommand
{
public:
   // CommandDefinitionInterface overrides
   wxString GetSymbol() override {return DEMO_PLUGIN_SYMBOL;};
   wxString GetDescription() override {return _("Does the demo action.");};
   bool DefineParams( ShuttleParams & S ) override;
   void PopulateOrExchange(ShuttleGui & S) override;
   bool Apply(const CommandContext & context) override;

   // AudacityCommand overrides
   wxString ManualPage() override {return wxT("Demo");};

private:
   double delay;
   double decay;
};

#endif // __AUDACITY_DEMO_COMMAND__
