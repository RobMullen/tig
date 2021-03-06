/* Copyright (c) 2006-2014 Jonas Fonseca <jonas.fonseca@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef TIG_OPTIONS_H
#define TIG_OPTIONS_H

#include "tig/tig.h"
#include "tig/util.h"

/*
 * Option variables.
 */

#define OPTION_INFO(_) \
	_(author_width,			int,			VIEW_NO_FLAGS) \
	_(blame_options,		const char **,		VIEW_BLAME_LIKE) \
	_(commit_order,			enum commit_order,	VIEW_LOG_LIKE) \
	_(diff_context,			int,			VIEW_DIFF_LIKE) \
	_(diff_options,			const char **,		VIEW_DIFF_LIKE) \
	_(editor_line_number,		bool,			VIEW_NO_FLAGS) \
	_(file_filter,			bool,			VIEW_DIFF_LIKE | VIEW_LOG_LIKE) \
	_(focus_child,			bool,			VIEW_NO_FLAGS) \
	_(horizontal_scroll,		double,			VIEW_NO_FLAGS) \
	_(id_width,			int,			VIEW_NO_FLAGS) \
	_(ignore_case,			bool,			VIEW_NO_FLAGS) \
	_(ignore_space,			enum ignore_space,	VIEW_DIFF_LIKE) \
	_(line_graphics,		enum graphic,		VIEW_NO_FLAGS) \
	_(line_number_interval,		int,			VIEW_NO_FLAGS) \
	_(mouse,			bool,			VIEW_NO_FLAGS) \
	_(mouse_scroll,			int,			VIEW_NO_FLAGS) \
	_(read_git_colors,		bool,			VIEW_NO_FLAGS) \
	_(show_author,			enum author,		VIEW_NO_FLAGS) \
	_(show_changes,			bool,			VIEW_NO_FLAGS) \
	_(show_date,			enum date,		VIEW_NO_FLAGS) \
	_(show_file_size,		enum file_size,		VIEW_NO_FLAGS) \
	_(show_filename,		enum filename,		VIEW_NO_FLAGS) \
	_(show_filename_width,		int,			VIEW_NO_FLAGS) \
	_(show_id,			bool,			VIEW_NO_FLAGS) \
	_(show_line_numbers,		bool,			VIEW_NO_FLAGS) \
	_(show_notes,			bool,			VIEW_NO_FLAGS) \
	_(show_refs,			bool,			VIEW_NO_FLAGS) \
	_(show_rev_graph,		bool,			VIEW_LOG_LIKE) \
	_(split_view_height,		double,			VIEW_RESET_DISPLAY) \
	_(status_untracked_dirs,	bool,			VIEW_STATUS_LIKE) \
	_(tab_size,			int,			VIEW_NO_FLAGS) \
	_(title_overflow,		int,			VIEW_NO_FLAGS) \
	_(vertical_split,		enum vertical_split,	VIEW_RESET_DISPLAY | VIEW_DIFF_LIKE) \
	_(wrap_lines,			bool,			VIEW_NO_FLAGS) \

#define DEFINE_OPTION_EXTERNS(name, type, flags) extern type opt_##name;
OPTION_INFO(DEFINE_OPTION_EXTERNS);

/*
 * Global state variables.
 */

extern iconv_t opt_iconv_out;
extern char opt_editor[SIZEOF_STR];
extern const char **opt_cmdline_argv;
extern const char **opt_rev_argv;
extern const char **opt_file_argv;
extern char opt_env_lines[64];
extern char opt_env_columns[64];
extern char *opt_env[];

/*
 * Mapping between options and command argument mapping.
 */

void update_options_from_argv(const char *argv[]);

const char *ignore_space_arg();
const char *commit_order_arg();
const char *diff_context_arg();
const char *show_notes_arg();

/*
 * Option loading and parsing.
 */

enum status_code parse_int(int *opt, const char *arg, int min, int max);
enum status_code parse_step(double *opt, const char *arg);
enum status_code set_option(const char *opt, int argc, const char *argv[]);
int load_options(void);
int load_git_config(void);

#endif
/* vim: set ts=8 sw=8 noexpandtab: */
