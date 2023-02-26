/* File : fubar.i */
%module pyfubar

%include <std_unique_ptr.i>

%unique_ptr(fubar::IFu)

%{
#include <memory>
#include "FuInterface.hpp"
%}


%include "FuInterface.hpp"
%include <memory>

%newobject fubar::FuFactory::MakeFuTypeOne();
%newobject fubar::FuFactory::MakeFuTypeTwo();