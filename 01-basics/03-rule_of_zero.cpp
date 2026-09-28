// The "Rule of Zero" in C++ states that if a class does not explicitly require custom destructor, 
// copy constructor, copy assignment operator, or move semantics, then it should not provide them 
// explicitly. Instead, it should rely on the compiler- generated defaults. 
//
// This approach leverages the compiler's ability to automatically generate these special member 
// functions, leading to cleaner and more concise code.
//
// Rule of Zero, you minimize the chances of errors in managing resources manually, reduce code 
// duplication, and improve code readability and maintainability.