# Arrays of Objects -- Introduction  
*Topics:*  
-Creating object arrays  
-Initializing object arrays  
-Accessing object arrays  

**Basic Notes:**  

## Objects can be the elements of an array.  
*e.g.*  
Foo f[size];(array of type size)  
When the array is defined size constructors are executed.  
If we want to pass arguments we need an initializtion list.  
*e.g.*  
Foo f[] = {8, 6, 7}; 
Note that the parameters inside the initialization list are passed to the constructor of the object Foo. in this case all the defined parameters are passed to the 1 parameter constructor.   

## What do we need to pass multiple arguments to the object constructor?  
*We are using the following technique:*  
Foo f[] = { Foo(8,6), Foo(7,5), Foo(3,0) };
In this case we are invoking the 2 parameter constructor for each array element.  
Of course we can mix and match both techniques according to our needs.  
*e.g.* Foo f[] = {6, Foo(4,3), 2}; 
In this case we are using the 2 parameter constructor for the second element of the array and the 1 parameter constructor for the other elements.  

## Accessing Objects in an Array
*To do that we combine the array and the object logic:*  
*e.g.*  
To call a function of a certain array member we do:(if the object is f)  
f[1].getX();  
Or: f[1].setX(12);  
You get the idea.  

**Now it is time to look into the first example on this folder**


