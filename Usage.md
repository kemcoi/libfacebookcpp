# Details #

LibFacebookCpp has been designed to provide easy access to Facebook content using the cURL library. Usage has been simplified to requesting basic Facebook Object classes (User, Photos, Notes, etc) from a Facebook::Session class. These Facebook Object classes are then able to request Connections and access information. Write support is currently not supported.

The Facebook::Session class provides a single convenience method, GetAuthenticationURL(), which builds an Authentication URL for a user to accept. Once the user has accepted, another method in Facebook::Session, Authenticate(), will provide the caller with Facebook::Session object, which is tied to a single user. From there, Facebook::Session provides multiple accessors to retrieve information about the current user. Note that each Facebook::Session object will be linked to only one user.



TODO: Example

TODO: Add more stuff