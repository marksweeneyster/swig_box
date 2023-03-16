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
