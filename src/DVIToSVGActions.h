/***********************************************************************
** DVIToSVGActions.h                                                  **
**                                                                    **
** This file is part of dvisvgm -- the DVI to SVG converter           **
** Copyright (C) 2005-2009 Martin Gieseking <martin.gieseking@uos.de> **
**                                                                    **
** This program is free software; you can redistribute it and/or      **
** modify it under the terms of the GNU General Public License        **
** as published by the Free Software Foundation; either version 2     **
** of the License, or (at your option) any later version.             **
**                                                                    **
** This program is distributed in the hope that it will be useful,    **
** but WITHOUT ANY WARRANTY; without even the implied warranty of     **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      **
** GNU General Public License for more details.                       **
**                                                                    **
** You should have received a copy of the GNU General Public License  **
** along with this program; if not, write to the Free Software        **
** Foundation, Inc., 51 Franklin Street, Fifth Floor,                 **
** Boston, MA 02110-1301, USA.                                        **
***********************************************************************/

#ifndef DVITOSVGACTIONS_H
#define DVITOSVGACTIONS_H

#include <map>
#include <set>
#include "DVIActions.h"
#include "TransformationMatrix.h"

using std::map;
using std::set;

class CharmapTranslator;
class DVIReader;
class FileFinder;
class Font;
class SpecialManager;
class XMLElementNode;

class DVIToSVGActions : public DVIActions
{
	typedef map<const Font*, CharmapTranslator*> CharmapTranslatorMap;
	typedef map<const Font*, set<int> > UsedCharsMap;
	public:
		DVIToSVGActions (const DVIReader &reader, XMLElementNode *svgelem);
		~DVIToSVGActions ();
		void setChar (double x, double y, unsigned c, const Font *f);
		void setRule (double x, double y, double height, double width);
		void moveToX (double x) {_xmoved = true;}
		void moveToY (double y) {_ymoved = true;}
		void defineFont (int num, const Font *font);
		void setFont (int num, const Font *font);
		void special (const string &s);
		void preamble (const string &cmt);
		void postamble ();
		void beginPage (Int32 *c);
		void endPage ();
		const UsedCharsMap& getUsedChars () const {return _usedCharsMap;}
		void setProcessSpecials (bool ps);
		void setTransformation (const TransformationMatrix &tm);
		CharmapTranslator* getCharmapTranslator (const Font *font) const;

	private:
		const DVIReader &_dviReader;
		SpecialManager *_specialManager;
		bool _xmoved, _ymoved;
		int _pageCount;
		int _currentFont;
		XMLElementNode *svgElement, *pageElement, *styleElement, *charElement;
		CharmapTranslatorMap _charmapTranslatorMap;
		UsedCharsMap _usedCharsMap;
		TransformationMatrix *_transMatrix;
};


#endif
