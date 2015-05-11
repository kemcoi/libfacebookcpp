1) How do I contribute to this project?
> Contributing is easy! Checkout the source code. Read our StyleGuide. Hack up a patch. Create a new issue with your patch attached and either of the active developer would gladly code review it and apply the patch. It is as simple as that! We'll even give a special contribution to you!

2) When I compile LibFacebookCpp, I get lots of warning.
> We are aware of the many warnings produced during the compile and linking stages and are actively working to reduce their number. If you have a patch that does so, feel free to submit it to us.

3) How do I find the documentation of the LibFacebookCpp's API?
> We document our code using Doxygen. Just run Doxygen with the Doxyfile in the tree with the base of the tree as the working directory. The documentation will be generated under docs\.

4) Is LibFacebookCpp thread-safe?
> Yes. LibFacebookCpp is thread-safe, but only upto the session level. Which means that, a single instance of `LibFacebookCpp::Session` and any child objects obtained from it should not be accessed from multiple thread simultaneously. Hence, if you require access from a worker thread, you should create a new session or transfer the ownership of the Session and any child objects to the worker thread.

5) Does LibFacebookCpp support Unicode?
> Yes. Facebook returns all its data outside the ASCII range to be escaped in the standard javascript Unicode escape syntax. LibFacebookCpp does not parse this and passes this string back to the calling code. Thus, in effect, leaving the calling code to handle Unicode as it suits best.