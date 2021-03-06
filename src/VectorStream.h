/*************************************************************************
** VectorStream.h                                                       **
**                                                                      **
** This file is part of dvisvgm -- the DVI to SVG converter             **
** Copyright (C) 2005-2015 Martin Gieseking <martin.gieseking@uos.de>   **
**                                                                      **
** This program is free software; you can redistribute it and/or        **
** modify it under the terms of the GNU General Public License as       **
** published by the Free Software Foundation; either version 3 of       **
** the License, or (at your option) any later version.                  **
**                                                                      **
** This program is distributed in the hope that it will be useful, but  **
** WITHOUT ANY WARRANTY; without even the implied warranty of           **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         **
** GNU General Public License for more details.                         **
**                                                                      **
** You should have received a copy of the GNU General Public License    **
** along with this program; if not, see <http://www.gnu.org/licenses/>. **
*************************************************************************/

#ifndef DVISVGM_VECTORSTREAM_H
#define DVISVGM_VECTORSTREAM_H

#include <istream>
#include <vector>


template <typename T>
struct VectorStreamBuffer : public std::streambuf
{
	VectorStreamBuffer (std::vector<T> &source) {
		setg((char*)&source[0], (char*)&source[0], (char*)&source[0]+source.size());
	}
};


template <typename T>
class VectorInputStream : public std::istream
{
	public:
		VectorInputStream (std::vector<T> &source) : std::istream(&_buf), _buf(source) {}
	private:
		VectorStreamBuffer<T> _buf;
};

#endif
