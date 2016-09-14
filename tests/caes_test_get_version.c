/*
 * Library get version test program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "caes_test_libcaes.h"
#include "caes_test_libcstring.h"
#include "caes_test_macros.h"
#include "caes_test_unused.h"

/* Tests retrieving the library version
 * Returns 1 if successful or 0 if not
 */
int caes_test_get_version(
     void )
{
	const char *version_string = NULL;
	int result                 = 0;

	version_string = libcaes_get_version();

	result = libcstring_narrow_string_compare(
	          version_string,
	          LIBCAES_VERSION_STRING,
	          9 );

	CAES_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc CAES_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] CAES_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc CAES_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] CAES_TEST_ATTRIBUTE_UNUSED )
#endif
{
	CAES_TEST_UNREFERENCED_PARAMETER( argc )
	CAES_TEST_UNREFERENCED_PARAMETER( argv )

	CAES_TEST_RUN(
	 "libcaes_get_version",
	 caes_test_get_version() )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

