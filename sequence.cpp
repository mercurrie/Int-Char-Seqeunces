// FILE: sequence.cpp
// CLASS IMPLEMENTED: sequence (see sequence.h for documentation).

#include <cassert>
#include "sequence.h"

namespace sequenceOfNum
{
   sequence::sequence() : used(0), current_index(0) { }

   void sequence::start() { current_index = 0; }

   void sequence::end()
   { current_index = (used > 0) ? used - 1 : 0; }

   void sequence::advance()
   {
      assert( is_item() );
      ++current_index;
   }

   void sequence::move_back()
   {
      assert( is_item() );
      if (current_index == 0)
         current_index = used;
      else
         --current_index;
   }

   void sequence::add(const value_type& entry)
   {
      assert( size() < CAPACITY );

      size_type i;

      if ( ! is_item() )
      {
         if (used > 0)
            for (i = used; i >= 1; --i)
               data[i] = data[i - 1];
         data[0] = entry;
         current_index = 0;
      }
      else
      {
         ++current_index;
         for (i = used; i > current_index; --i)
            data[i] = data[i - 1];
         data[current_index] = entry;
      }
      ++used;
   }

   void sequence::remove_current()
   {
      assert( is_item() );

      size_type i;

      for (i = current_index + 1; i < used; ++i)
         data[i - 1] = data[i];
      --used;
   }

   sequence::size_type sequence::size() const { return used; }

   bool sequence::is_item() const { return (current_index < used); }

   sequence::value_type sequence::current() const
   {
      assert( is_item() );

      return data[current_index];
   }
}

namespace sequenceOfChar
{
   sequence::sequence() : used(0), current_index(0) { }

   void sequence::start() { current_index = 0; }

   void sequence::end() { current_index = (used > 0) ? used - 1 : 0; }

   void sequence::advance()
   {
      assert( is_item() );
      ++current_index;
   }

   void sequence::move_back()
   {
      assert( is_item() );
      if (current_index == 0)
         current_index = used;
      else
         --current_index;
   }

   void sequence::add(const value_type& entry)
   {
      assert( size() < CAPACITY );

      size_type i;

      if ( ! is_item() )
      {
         if (used > 0)
            for (i = used; i >= 1; --i)
               data[i] = data[i - 1];
         data[0] = entry;
         current_index = 0;
      }
      else
      {
         ++current_index;
         for (i = used; i > current_index; --i)
            data[i] = data[i - 1];
         data[current_index] = entry;
      }
      ++used;
   }

   void sequence::remove_current()
   {
      assert( is_item() );

      size_type i;

      for (i = current_index + 1; i < used; ++i)
         data[i - 1] = data[i];
      --used;
   }

   sequence::size_type sequence::size() const { return used; }

   bool sequence::is_item() const { return (current_index < used); }

   sequence::value_type sequence::current() const
   {
      assert( is_item() );

      return data[current_index];
   }
}
