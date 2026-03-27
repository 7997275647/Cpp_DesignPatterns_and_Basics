#ifndef VECTOR_HPP
#define VECTOR_HPP

/************** Vector Data Type Practice ***********/
/* Vector Data Type is a dynamic array that can grow and shrink in size during runtime */
/* It is part of the C++ Standard Template Library (STL) and provides various functions to manipulate the elements in the vector */
/* It is implemented as a template class, which means it can hold any data type */
/* It is a sequence container that allows fast random access to elements and efficient insertion and deletion at the end of the vector */
/* Vector Operations: push_back(), pop_back(), at(), size(), empty() */

/*push_back() adds an element to the end of the vector */
/*pop_back() removes the last element from the vector */
/*at() returns a reference to the element at a specific position in the vector */
/*size() returns the number of elements in the vector */
/*empty() checks if the vector is empty or not */

/* Vector Element Access: front(), back() */

/*front() returns a reference to the first element in the vector */
/*back() returns a reference to the last element in the vector */

/* Vector Iterators: begin(), end(), rbegin(), rend() */

/*begin() returns an iterator pointing to the first element in the vector */
/*end() returns an iterator pointing to the past-the-end element in the vector */
/*rbegin() returns a reverse iterator pointing to the last element in the vector */
/*rend() returns a reverse iterator pointing to the past-the-end element in the vector */

/* Vector Capacity: capacity(), reserve(), shrink_to_fit() */

/*capacity() returns the number of elements that the vector can hold before it needs to reallocate memory */
/*reserve() requests that the vector capacity be at least enough to contain n elements */
/*shrink_to_fit() requests the container to reduce its capacity to fit its size */

/* Vector Modifiers: clear(), insert(), erase(), swap() */

/*clear() removes all elements from the vector */
/*insert() inserts elements into the vector */
/*erase() removes elements from the vector */
/*swap() exchanges the contents of two vectors */

void vectorDataTypePractice();

#endif // VECTOR_HPP