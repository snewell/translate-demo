translate-demo
==============
An expiermental project to play with modernizing a C++ interface.  The use
case is a project that has to translate data from one form to another;
practice examples could be JSON to SQL, one type of SQL to another, or even
modifying the input in some way before writing it back to the same format
(e.g., making strings uppercase).

This code is an attempt to start with a concrete :code:`class` that does all
the work, and eventually end up with nothing object-oriented all all.  The
final algorithm-based solution includes a method to use existing code via
:code:`template` specialization.
