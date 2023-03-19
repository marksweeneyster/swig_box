# swig_box
sandbox for swig work

For cmake invocation add a parameter for the SWIG executable path
``` console
#windows example
cmake .. -DSWIG_EXECUTABLE=C:/tools/swig/swigwin-4.1.1/swig <other params>

#linux example
cmake .. -DSWIG_EXECUTABLE=/home/mark/Dev/tools/swig/install/bin/swig <other params>
```

I tested the polymorphic behavior of the FubarFactory in python. The **TypeTwo** version performs an "add" by taking the product.
It also is hardcoded to have a non-zero Error value.  **Noop** is a no-op implementation that always returns 0 for an add. 

``` console 
>>> import pyfubar as pfb
>>>
>>> f1 = pfb.FuFactory.MakeFuTypeOne()
>>> f2 = pfb.FuFactory.MakeFuTypeTwo() 
>>> fnoop = pfb.FuFactory.MakeFuNoop()    
>>>
>>> f1.add(-1.1, 3.7)
2.6

>>> f2.add(-1.1, 3.7) 
-4.07

>>> fnoop.add(-1.1, 3.7) 
0.0

>>> f1.getErr()
0
>>> f2.getErr() 
1
>>> fnoop.getErr() 
0

>>> type(f1)
<class 'pyfubar.IFu'>

>>> type(f2) 
<class 'pyfubar.IFu'>

>>> type(fnoop) 
<class 'pyfubar.IFu'>

>>> quit()

```
