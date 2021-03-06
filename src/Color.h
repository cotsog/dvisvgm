/*************************************************************************
** Color.h                                                              **
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

#ifndef DVISVGM_COLOR_H
#define DVISVGM_COLOR_H

#include <string>
#include <valarray>
#include <vector>
#include "types.h"
#include "VectorIterator.h"

#ifdef TRANSPARENT
#undef TRANSPARENT
#endif

class Color
{
	public:
		static bool SUPPRESS_COLOR_NAMES;
		static const Color BLACK;
		static const Color WHITE;
		static const Color TRANSPARENT;

		enum ColorSpace {GRAY_SPACE, RGB_SPACE, CMYK_SPACE, LAB_SPACE};

	public:
		Color () : _rgb(0) {}
		Color (UInt32 rgb) : _rgb(rgb)           {}
		Color (UInt8 r, UInt8 g, UInt8 b)        {setRGB(r,g,b);}
		Color (double r, double g, double b)     {setRGB(r,g,b);}
		Color (const std::valarray<double> &rgb) {setRGB(rgb);}
		Color (const char *name);
		Color (const std::string &name);
//		Color (ColorSpace colorSpace, std::vector<double>::const_iterator &it) {set(colorSpace, it);}
		operator UInt32 () const                 {return _rgb;}
		bool operator == (const Color &c) const  {return _rgb == c._rgb;}
		bool operator != (const Color &c) const  {return _rgb != c._rgb;}
		void setRGB (UInt8 r, UInt8 g, UInt8 b)  {_rgb = (r << 16) | (g << 8) | b;}
		void setRGB (double r, double g, double b);
		void setRGB (const std::valarray<double> &rgb) {setRGB(rgb[0], rgb[1], rgb[2]);}
		bool setPSName (std::string name, bool case_sensitive=true);
		void setGray (UInt8 g)  {setRGB(g,g,g);}
		void setGray (double g) {setRGB(g,g,g);}
		void setGray (const std::valarray<double> &gray) {setRGB(gray[0], gray[0], gray[0]);}
		void setHSB (double h, double s, double b);
		void setCMYK (double c, double m, double y, double k);
		void setCMYK (const std::valarray<double> &cmyk);
		void setXYZ (double x, double y, double z);
		void setXYZ (const std::valarray<double> &xyz);
		void setLab (double l, double a, double b);
		void setLab (const std::valarray<double> &lab);
		void set (ColorSpace colorSpace, VectorIterator<double> &it);
		double getGray () const;
		void getGray (std::valarray<double> &gray) const;
		void getRGB (double &r, double &g, double &b) const;
		void getRGB (std::valarray<double> &rgb) const;
		void getCMYK (double &c, double &m, double &y, double &k) const;
		void getCMYK (std::valarray<double> &cmyk) const;
		void getXYZ (double &x, double &y, double &z) const;
		void getLab (double &l, double &a, double &b) const;
		void getLab (std::valarray<double> &lab) const;
		void operator *= (double c);
		double deltaE (const Color &c) const;
		std::string rgbString () const;
		std::string svgColorString (bool rgbonly) const;
		std::string svgColorString () const {return svgColorString(SUPPRESS_COLOR_NAMES);}
		static void CMYK2RGB (const std::valarray<double> &cmyk, std::valarray<double> &rgb);
		static void RGB2CMYK (const std::valarray<double> &rgb, std::valarray<double> &cmyk);
		static void HSB2RGB (const std::valarray<double> &hsb, std::valarray<double> &rgb);
		static void RGB2XYZ (std::valarray<double> rgb, std::valarray<double> &xyz);
		static void XYZ2RGB (const std::valarray<double> &xyz, std::valarray<double> &rgb);
		static void RGB2Lab (const std::valarray<double> &rgb, std::valarray<double> &lab);
		static void Lab2XYZ (const std::valarray<double> &lab, std::valarray<double> &xyz);
		static int numComponents (ColorSpace colorSpace);

	private:
		UInt32 _rgb;
};

#endif
