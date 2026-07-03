# References & Pointers

## Goal

Understand:

- What a pointer is
- What a reference is
- When to use each
- How parameters are passed to functions
- Common interview questions

---

# Memory

Every variable lives somewhere in memory.

```cpp
int x = 10;
```

Example:

```

Address      Value

0x100        10

```

The operator `&` returns the address.

```cpp
std::cout << &x;
```

Output (example):

```

0x100

```

---

# Pointer

A pointer stores an address.

```cpp
int x = 10;

int* ptr = &x;
```

Memory:

```

x

0x100
+------+
|  10  |
+------+

ptr

0x200
+--------+
| 0x100  |
+--------+

```

`ptr` is **not** the integer.

`ptr` stores **where the integer is**.

---

## Dereferencing

```cpp
*ptr = 20;
```

Read as:

> Go to the address stored inside ptr and modify the object there.

After:

```cpp
*ptr = 20;
```

```

x = 20

```

---

# Reference

A reference is another name for an existing object.

```cpp
int x = 10;

int& ref = x;
```

Think of it like:

```

ref
│
│
▼

x

```

Changing one changes the other.

```cpp
ref = 30;
```

Result:

```cpp
x == 30
```

---

# Reference vs Pointer

Reference

✔ must refer to a valid object

✔ cannot be reseated

✔ cannot be nullptr

✔ acts like an alias

Pointer

✔ stores an address

✔ can be nullptr

✔ can point somewhere else later

✔ can perform pointer arithmetic

---

# Example

```cpp
int a = 5;
int b = 10;

int* ptr = &a;

ptr = &b;
```

Pointer now points to `b`.

A reference cannot do this.

---

# Passing Parameters

## Pass by Value

```cpp
void foo(int x)
```

A copy is created.

Changes do NOT affect the caller.

---

## Pass by Pointer

```cpp
void foo(int* ptr)
```

A copy of the pointer is created.

Both pointers still point to the same object.

Changing

```cpp
*ptr
```

changes the original object.

Changing

```cpp
ptr
```

does NOT affect the caller.

---

## Pass by Reference

```cpp
void foo(int& ref)
```

No copy of the object is made.

`ref` becomes another name for the original object.

Changing `ref` changes the original.

---

# Pointer Copy

```cpp
int value = 10;

int* p = &value;

foo(p);
```

Inside:

```cpp
void foo(int* ptr)
```

Memory:

```

p ----------+
             |
             ▼

value

ptr ---------+

```

Both pointers point to the same integer.

But they are different variables.

```

p != ptr

```

Changing

```cpp
ptr = nullptr;
```

does NOT change `p`.

---

# Reference Parameter

```cpp
void foo(int& x)
```

Memory:

```

value

▲
│

x

```

There is no second integer.

Both names refer to the same object.

---

# Reference to Pointer

```cpp
void foo(int*& ptr)
```

This means:

```

reference

↓

pointer

↓

object

```

Now changing

```cpp
ptr = nullptr;
```

also changes the pointer in the caller.

---

# nullptr

Always initialize pointers.

Good:

```cpp
int* ptr = nullptr;
```

Avoid:

```cpp
int* ptr;
```

Uninitialized pointers contain garbage addresses.

Dereferencing them is Undefined Behavior.

---

# Interview Questions

## Why use references instead of pointers?

References express that an object must exist.

Pointers express optional ownership or optional access.

---

## Why pass by const reference?

Instead of

```cpp
void print(std::string text)
```

use

```cpp
void print(const std::string& text)
```

Benefits:

- no copy
- faster
- cannot modify the object

---

## const Pointer Cheat Sheet

```cpp
const int* p;
```

Pointer to const int.

You can move the pointer.

You cannot modify the integer.

---

```cpp
int* const p;
```

Const pointer.

Pointer cannot move.

Integer can change.

---

```cpp
const int* const p;
```

Const pointer to const integer.

Neither can change.

---

# Best Practices

✅ Prefer references when nullptr is not valid.

✅ Prefer `const T&` for read-only parameters.

✅ Use pointers when "no object" is a valid state.

✅ Initialize pointers with nullptr.

✅ Avoid raw owning pointers.

Prefer:

```cpp
std::unique_ptr
```

or

```cpp
std::shared_ptr
```

---

# Things I Learned

- A pointer stores an address.
- A reference is an alias.
- Passing by value copies the object.
- Passing a pointer copies the pointer.
- Passing by reference creates no copy.
- A copied pointer still points to the same object.
- Changing a pointer is different from changing the object it points to.

---

# Summary

| Feature             | Pointer   | Reference |
|---------------------|---------- |-----------|
| Stores Address      |      x    |           |
| Can be nullptr      |      x    |           |
| Can change target   |      x    |           |
| Dereference required|      x    |           |
| Acts as alias       |           |      x    |

---

# Next Topic

Smart Pointers

- unique_ptr
- shared_ptr
- weak_ptr
- RAII