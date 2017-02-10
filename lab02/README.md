Some of the lab exercises this week will involve making changes 
to the book's code in the shaffer/ directory.  A convenient way
to do this without messing up the original code is to work on 
a "branch". This is a feature of git and most other version
control systems that lets you maintain multiple versions of 
a repository in parallel.  To do this for today's lab, enter this
command:

    git checkout -b lab02

Then you can freely change the files, save the changes, test, and
so on.  When you have a version you're happy with, you can commit
it to the repository.  If you changed, for example, the files
list.h and alist.h, then do this:

    git add list.h alist.h
    git commit -m "put a message here to remember what you did"

Then, to revert to the original files:

    git checkout master

To return to the modified files:

    git checkout lab02


(1) In lecture I noted that some of the virtual methods of List
could actually be implemented, once and for all, as non-virtual methods
in terms of other methods (this is what I called "generic code",
or, maybe confusingly, "template methods").

Reimplement as many of the methods of List as you can as non-virtual
methods, ensuring that they behave the same way as the existing implementations
for AList and LList.  To do this for a given method, delete the "virtual"
keyword from the method (and the "= 0;") and provide the
implementation in list.h.  You can then delete the implementations
of that method from alist.h and llist.h.

(2) Provide another generic method in list.h implemented entirely
in terms of virtual methods, with this signature:

bool find(const E& item) {....}

It should return true if and only if the object "item" is contained in the 
list.  See p. 99 of the text for an implementation as a standalone
function that you can use as a model. Note that this isn't declared
as const (even though in a sense it ought to be) since an implementation
will require looping over the list, which is non-const since we 
maintain the current position as state.

(3) [Shaffer exercise 4.6] Add to the LList class a method to reverse the order of the elements in the list.  Your algorithm should run in linear time in the number of elements in the list.

(4) [Shaffer project 4.2] One solution to the problem of running out of
space for an array-based list is to replace the array with a larger
one whenever the original array overflows. A good rule that is both
space and time efficient is to double the current size of the array
when there is an overflow.  Re-implement the code in alist.h to support
this array-doubling rule in place of the Assert statements in 
methods insert and append.
