#pragma once
#include <cstdint>
#include <deque>
#include <mutex>

#if !defined(LIST_3_3)
#define LIST_3_3

template<typename T, typename Container = std::deque<T>>
class stack
{
public:
  explicit stack(const Container&);
  explicit stack(Container&& = Container());

  template<class Alloc>
  explicit stack(const Alloc&);

  template<class Alloc>
  stack(const Container&, const Alloc&);

  template<class Alloc>
  stack(Container&&, const Alloc&);

  template<class Alloc>
  stack(stack&&, const Alloc&);

  bool
  empty() const;

  std::size_t
  size() const;

  T&
  top();

  T const&
  top() const;
  void
  push(T const&);
  void
  push(T&&);
  void
  pop();
  void
  swap(stack&&);

  template<class... Args>
  void
  emplace(Args&&... args); // C++14的新特性
};

#endif // LISt_3_3

#if !defined(LIST_3_6)
#define LIST_3_6

#endif // LISt_3_6

#ifndef LIST_3_7
#define LIST_3_7
/*
使用锁的层次结构
虽然，
定义锁的顺序是一种特殊情况，但锁的层次的意义在于提供对运行时约定是否被坚持的检查。
这个建议需要对你的应用进行分层， 并且识别在给定层上所有可上锁的互斥量。
当代码试图对一个互斥量上锁， 在该层锁已被低层持有时， 上锁是不允许的。
你可以在运行时 对其进行检查，
通过分配层数到每个互斥量上，以及记录被每个线程上锁的互斥量。 下面的
代码列表中将展示两个线程如何使用分层互斥
*/

#endif // LIST_3_7

#ifndef LISt_3_9
#define LISt_3_9

struct some_big_object
{};

void
swap(some_big_object& lhs, some_big_object& rhs);

class X
{
private:
  some_big_object some_detail;
  std::mutex m;

public:
  X(some_big_object const& sd)
    : some_detail(sd)
  {
  }

  friend void
  swap(X& lhs, X& rhs)
  {
    if (&lhs == &rhs)
      return;
    std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock); // 1
    std::unique_lock<std::mutex> lock_b(
      rhs.m, std::defer_lock); // 1 std::defer_lock 留下未上锁的互斥量
    std::lock(lock_a, lock_b); // 2 互斥量在这里上锁
    swap(lhs.some_detail, rhs.some_detail);
  }
};

#endif // LISt_3_9
       // #undef LISt_3_9

#ifndef LISt_3_10
#define LISt_3_10

class Y
{
private:
  int some_detail;
  mutable std::mutex m;

  int
  get_detail() const
  {
    std::lock_guard<std::mutex> lock_a(m); // 1
    return some_detail;
  }

public:
  Y(int sd)
    : some_detail(sd)
  {
  }

  friend bool
  operator==(Y const& lhs, Y const& rhs)
  {
    if (&lhs == &rhs)
      return true;
    int const lhs_value = lhs.get_detail(); // 2
    int const rhs_value = rhs.get_detail(); // 3
    return lhs_value == rhs_value;          // 4
  }
};
#endif