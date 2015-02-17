#pragma once

#include "rapidcheck/Seq.h"

namespace rc {
namespace seq {

//! Drops the first `n` elements from the given `Seq`.
template<typename T>
Seq<T> drop(std::size_t n, Seq<T> seq);

//! Takes the first `n` elements from the given `Seq`.
template<typename T>
Seq<T> take(std::size_t n, Seq<T> seq);

//! Drops all elements until the given predicate returns true.
template<typename Predicate, typename T>
Seq<T> dropWhile(Predicate &&pred, Seq<T> seq);

//! Takes elements until there is an element which does not match the predicate.
template<typename Predicate, typename T>
Seq<T> takeWhile(Predicate &&pred, Seq<T> seq);

//! Takes elements from the given `Seq`s and passes them as arguments to the
//! given callable and returns a `Seq` of such return values. For a single
//! `Seq`, this is regular "map" function but for more than one, it's what is
//! usually called "zipping with" a function. The length of the returned `Seq`
//! will be the length of the shortest `Seq` passed in.
//!
//! Fun fact: Also works with no sequences and in that case returns an infinite
//! sequence of the return values of calling the given callable.
template<typename Mapper, typename ...Ts>
Seq<typename std::result_of<Mapper(Ts...)>::type>
map(Mapper &&mapper, Seq<Ts> ...seqs);

} // namespace seq
} // namespace rc

#include "Transform.hpp"