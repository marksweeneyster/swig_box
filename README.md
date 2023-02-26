# swig_box
sandbox for swig work

Currently CMakeLists has harcoded paths for swig on my win machine.

I tested the polymorphic behavior of the FubarFactory in python. The **TypeTwo** version performs an "add" by taking the product.

``` console 
>>> import pyfubar as pfb
>>>
>>> f1 = pfb.FuFactory.MakeFuTypeOne()
>>>
>>> f2 = pfb.FuFactory.MakeFuTypeTwo()
>>>

>>> f1.add(-1.1, 3.7)
2.6
>>> f2.add(-1.1, 3.7)
-4.07
>>> 

>>> type(f1)
<class 'pyfubar.IFu'>

>>> type(f2) 
<class 'pyfubar.IFu'>
>>>

>>> quit()

```
