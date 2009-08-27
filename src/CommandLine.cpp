// This file was automatically generated by opt2cpp.
// It is part of the dvisvgm package and published under the terms
// of the GNU General Public License version 3 or later.
// See file COPYING for further details.
// (C) 2009 Martin Gieseking <martin.gieseking@uos.de>

#include <cstdio>
#include <iostream>
#include <iomanip>
#include "InputReader.h"
#include "CommandLine.h"

using namespace std;

const CmdLineParserBase::Option CommandLine::_options[] = {
   {'p', "page", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_page)},
   {'m', "map-file", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_map_file)},
   {'b', "bbox-format", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_bbox_format)},
   {'o', "output", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_output)},
   {'s', "stdout", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_stdout)},
   {'n', "no-fonts", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_no_fonts)},
   {'\0', "no-styles", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_no_styles)},
   {'z', "zip", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_zip)},
   {'r', "rotate", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_rotate)},
   {'c', "scale", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_scale)},
   {'t', "translate", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_translate)},
   {'T', "transform", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_transform)},
   {'C', "cache", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_cache)},
   {'M', "mag", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_mag)},
   {'\0', "no-mktexmf", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_no_mktexmf)},
   {'S', "no-specials", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_no_specials)},
   {'a', "trace-all", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_trace_all)},
   {'h', "help", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_help)},
   {'l', "list-specials", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_list_specials)},
   {'v', "verbosity", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_verbosity)},
   {'V', "version", new OptionHandlerImpl<CommandLine>(&CommandLine::handle_version)},
};

void CommandLine::init () {
   CmdLineParserBase::init();
   _page_given = false;
   _map_file_given = false;
   _bbox_format_given = false;
   _output_given = false;
   _stdout_given = false;
   _no_fonts_given = false;
   _no_styles_given = false;
   _zip_given = false;
   _rotate_given = false;
   _scale_given = false;
   _translate_given = false;
   _transform_given = false;
   _cache_given = false;
   _mag_given = false;
   _no_mktexmf_given = false;
   _no_specials_given = false;
   _trace_all_given = false;
   _help_given = false;
   _list_specials_given = false;
   _verbosity_given = false;
   _version_given = false;

   _page_arg = 1;
   _map_file_arg.clear();
   _bbox_format_arg = "min";
   _output_arg.clear();
   _zip_arg = 9;
   _rotate_arg = 0;
   _scale_arg.clear();
   _translate_arg.clear();
   _transform_arg.clear();
   _cache_arg.clear();
   _mag_arg = 4;
   _no_specials_arg.clear();
   _verbosity_arg = 7;
}

void CommandLine::help () const {
   puts("This program converts DVI files, as created by TeX/LaTeX to\nthe XML-based scalable vector graphics format SVG.\n\nUsage: dvisvgm [options] dvifile\n");
   puts("Input options:");
   puts("  -p, --page=number             choose page to convert (default: 1)");
   puts("  -m, --map-file=[+]filename    set [additional] font map file name");
   puts("\nSVG output options:");
   puts("  -b, --bbox-format=fmt         set format of bounding box (default: min)");
   puts("  -o, --output=filename         set name of output file");
   puts("  -s, --stdout                  write SVG output to stdout");
   puts("  -n, --no-fonts                draw glyphs by using path elements");
   puts("      --no-styles               don't use styles to reference fonts");
   puts("  -z, --zip[=level]             create compressed .svgz file (default: 9)");
   puts("\nSVG transformations:");
   puts("  -r, --rotate=angle            rotate page content clockwise");
   puts("  -c, --scale=sx[,sy]           scale page content");
   puts("  -t, --translate=tx[,ty]       shift page content");
   puts("  -T, --transform=commands      transform page content");
   puts("\nProcessing options:");
   puts("  -C, --cache[=dir]             set/print path of cache directory");
   puts("  -M, --mag=factor              magnification of Metafont output (default: 4)");
   puts("      --no-mktexmf              don't try to create missing fonts");
   puts("  -S, --no-specials[=prefixes]  don't process [selected] specials");
   puts("  -a, --trace-all               trace all glyphs of used bitmap fonts");
   puts("\nMessage options:");
   puts("  -h, --help                    print this help and exit");
   puts("  -l, --list-specials           print supported special sets and exit");
   puts("  -v, --verbosity=level         set verbosity level (0-7) (default: 7)");
   puts("  -V, --version                 print version and exit");
}


void CommandLine::handle_page(InputReader &ir, const Option &opt, bool longopt) {
   if (getUIntArg(ir, opt, longopt, _page_arg))
      _page_given = true;
}


void CommandLine::handle_map_file(InputReader &ir, const Option &opt, bool longopt) {
   if (getStringArg(ir, opt, longopt, _map_file_arg))
      _map_file_given = true;
}


void CommandLine::handle_bbox_format(InputReader &ir, const Option &opt, bool longopt) {
   if (getStringArg(ir, opt, longopt, _bbox_format_arg))
      _bbox_format_given = true;
}


void CommandLine::handle_output(InputReader &ir, const Option &opt, bool longopt) {
   if (getStringArg(ir, opt, longopt, _output_arg))
      _output_given = true;
}


void CommandLine::handle_stdout(InputReader &ir, const Option &opt, bool longopt) {
   _stdout_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_no_fonts(InputReader &ir, const Option &opt, bool longopt) {
   _no_fonts_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_no_styles(InputReader &ir, const Option &opt, bool longopt) {
   _no_styles_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_zip(InputReader &ir, const Option &opt, bool longopt) {
   if (ir.eof() || getIntArg(ir, opt, longopt, _zip_arg))
      _zip_given = true;
}


void CommandLine::handle_rotate(InputReader &ir, const Option &opt, bool longopt) {
   if (getDoubleArg(ir, opt, longopt, _rotate_arg))
      _rotate_given = true;
}


void CommandLine::handle_scale(InputReader &ir, const Option &opt, bool longopt) {
   if (getStringArg(ir, opt, longopt, _scale_arg))
      _scale_given = true;
}


void CommandLine::handle_translate(InputReader &ir, const Option &opt, bool longopt) {
   if (getStringArg(ir, opt, longopt, _translate_arg))
      _translate_given = true;
}


void CommandLine::handle_transform(InputReader &ir, const Option &opt, bool longopt) {
   if (getStringArg(ir, opt, longopt, _transform_arg))
      _transform_given = true;
}


void CommandLine::handle_cache(InputReader &ir, const Option &opt, bool longopt) {
   if (ir.eof() || getStringArg(ir, opt, longopt, _cache_arg))
      _cache_given = true;
}


void CommandLine::handle_mag(InputReader &ir, const Option &opt, bool longopt) {
   if (getDoubleArg(ir, opt, longopt, _mag_arg))
      _mag_given = true;
}


void CommandLine::handle_no_mktexmf(InputReader &ir, const Option &opt, bool longopt) {
   _no_mktexmf_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_no_specials(InputReader &ir, const Option &opt, bool longopt) {
   if (ir.eof() || getStringArg(ir, opt, longopt, _no_specials_arg))
      _no_specials_given = true;
}


void CommandLine::handle_trace_all(InputReader &ir, const Option &opt, bool longopt) {
   _trace_all_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_help(InputReader &ir, const Option &opt, bool longopt) {
   _help_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_list_specials(InputReader &ir, const Option &opt, bool longopt) {
   _list_specials_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::handle_verbosity(InputReader &ir, const Option &opt, bool longopt) {
   if (getUIntArg(ir, opt, longopt, _verbosity_arg))
      _verbosity_given = true;
}


void CommandLine::handle_version(InputReader &ir, const Option &opt, bool longopt) {
   _version_given = checkNoArg(ir, opt, longopt);
}


void CommandLine::status () const {
   cout << 'p'<< setw(20) << "page " << page_given() << setw(10) << page_arg() << endl;
   cout << 'm'<< setw(20) << "map-file " << map_file_given() << setw(10) << map_file_arg() << endl;
   cout << 'b'<< setw(20) << "bbox-format " << bbox_format_given() << setw(10) << bbox_format_arg() << endl;
   cout << 'o'<< setw(20) << "output " << output_given() << setw(10) << output_arg() << endl;
   cout << 's'<< setw(20) << "stdout " << stdout_given() << endl;
   cout << 'n'<< setw(20) << "no-fonts " << no_fonts_given() << endl;
   cout << ' '<< setw(20) << "no-styles " << no_styles_given() << endl;
   cout << 'z'<< setw(20) << "zip " << zip_given() << setw(10) << zip_arg() << endl;
   cout << 'r'<< setw(20) << "rotate " << rotate_given() << setw(10) << rotate_arg() << endl;
   cout << 'c'<< setw(20) << "scale " << scale_given() << setw(10) << scale_arg() << endl;
   cout << 't'<< setw(20) << "translate " << translate_given() << setw(10) << translate_arg() << endl;
   cout << 'T'<< setw(20) << "transform " << transform_given() << setw(10) << transform_arg() << endl;
   cout << 'C'<< setw(20) << "cache " << cache_given() << setw(10) << cache_arg() << endl;
   cout << 'M'<< setw(20) << "mag " << mag_given() << setw(10) << mag_arg() << endl;
   cout << ' '<< setw(20) << "no-mktexmf " << no_mktexmf_given() << endl;
   cout << 'S'<< setw(20) << "no-specials " << no_specials_given() << setw(10) << no_specials_arg() << endl;
   cout << 'a'<< setw(20) << "trace-all " << trace_all_given() << endl;
   cout << 'h'<< setw(20) << "help " << help_given() << endl;
   cout << 'l'<< setw(20) << "list-specials " << list_specials_given() << endl;
   cout << 'v'<< setw(20) << "verbosity " << verbosity_given() << setw(10) << verbosity_arg() << endl;
   cout << 'V'<< setw(20) << "version " << version_given() << endl;
   CmdLineParserBase::status();
}

