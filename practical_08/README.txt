A private constructor prevents normal construction from outside the class.

getInstance() returns a reference to one function-local static instance, created on the first call.

The static instance is reused on later calls and is destroyed automatically when the program ends.

Deleting the copy constructor and copy assignment operator prevents copies of the singleton.

A useful application is sharing one configuration object, such as the display theme, across a program.

The benefit is one consistent source of settings. A tradeoff is shared global state, which can make testing and dependencies harder to manage.

The example is single-threaded; concurrent changes to shared settings would need suitable synchronization.

Result/Outcome
I learned how the Singleton pattern provides one shared settings object. I used a private constructor and deleted copying to prevent extra instances. I confirmed that two references access the same object and see the same theme value.
