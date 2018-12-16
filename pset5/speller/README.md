# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

an artificial long word said to mean a lung disease caused by inhaling very fine ash and sand dust

## According to its man page, what does `getrusage` do?

getrusage() returns resource usage measures for integer who. Who in this case is always RUSAGE_SELF, which returns statistics for the calling process


## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

cuz it saves on time

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

It reads the text character by character until it reaches the end of file (EOF). If it sees a alphabetical charcter or apostrophe (provided that it doesn't begin the sentence), the character is appended into a word array.
If the word is too long and larger than LENGTH, the file is read until the end of the longass fake word and index is reset to 0 to start a new word. In case of digits, the rest of the ALPHANUMERIC string is consumed and index
is also reset. Otherwise the current character must be the end of a word, and the word array is topped off with a null character, word count is added to by 1, and the check function is called to check the spelling of the word.
Timecheck is updated, index is reset to prepare for the next word.




## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

Using fscanf with a formatter like "%s" would take ANY string separated by a whitespace, meaning that numerical characters and symbols would be added into words.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

So we don't tamper with the times lol
