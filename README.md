# String Template Class

`stringTemplate` is a C++ class that provides a way to create template strings where a specific placeholder is replaced by a series of arguments. It is useful for generating dynamic output, such as creating HTML or XML markup.

## Usage

To use `stringTemplate`, create an instance of the class and set the placeholder to be used. The default placeholder is `{}`.

```c++
stringTemplate theTemplate;
theTemplate.usePlaceholder("{}");
```

You can then use the `templateString()` function to generate a string based on a given template and a list of arguments:

```c++
std::string result = theTemplate.templateString("Hello {}, welcome to {}!", "John", "my website");
```


In this example, the `{}` placeholders in the template string will be replaced by the "John" and "my website" arguments, respectively.

The `getPlaceholder()` function can be used to retrieve the current placeholder:

```c++
std::string placeholder = theTemplate.getPlaceholder();
```
