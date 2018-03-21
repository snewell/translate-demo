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


Building
--------
You'll need a fairly modern version of CMake_ since this project uses the
:code:`cxx_std_17` compiler feature; if your version doesn't recognize that
feautre, you can hack the same behavior by adding whatever flag your compiler
uses to enable C++17 mode.  The only C++17 feature used is
:code:`std::optional`, so you can get most of the affect using
:code:`boost::optional` if you don't have a modern enough compiler.

I've tested it with gcc-7.3.0 and clang-6.0.0 (with libc++) on an x86_64
Gentoo Linux system.


Evolution
---------
All work is performed under the assumption that a series of
:code:`std::string`\s need to be converted to uppercase.  Work is broken into
reading (getting the next :code:`std::string` to operate on), mutating (making
everything uppercase), and writing (printing the mutated :code:`std::string`).

The initial stage is a :code:`class` that performs all the work itself.  Logic
for reading, mutating, and writing is tightly coupled.  Work is available in
:code:`translator.hpp` and :code:`translate.cpp`.

The next step is breaking the coupling; all logic is still in a single
:code:`class`, but the implmentation of each stage is in an independant
function.  The main function (:code:`translate`), calls into each of the
functions.  Work is available in :code:`translator_split.hpp` and
:code:`translate.cpp`.

Next, the work is broken into a series of :code:`class`\es following the single
responsibility principle.  :code:`translate` is now a free function and takes
three arguments: a :code:`Reader`, a :code:`Mutator`, and a :code:`Writer`.
This also permits dependency injection, making it possible to test
:code:`translate` directly.  As a bonus, templates were introduced to support
more than just :code:`std::string` operations.  Work is in
:code:`translator_interfaces.hpp` and :code:`translate_interfaces.cpp`.

Finally, all specific implmentations are discarded and an algorithmic solution
is introduced.  :code:`translate` operates on three callable objects that
depend on duck typing.  :code:`translate_algo.cpp` demonstrates this
functionality using lambdas.  :code:`translate_algo_reuse.cpp` is an example
of this design that leverages an existing :code:`class` (effectively what was
written in any of the previous stages) by using a simple wrapper.  The
implementation of :code:`translate` is in :code:`translate.hpp` along with
default versions of the wrappers.


.. _CMake: https://www.cmake.org
