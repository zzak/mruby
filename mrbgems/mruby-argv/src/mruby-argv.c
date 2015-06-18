#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mruby.h"
#include "mruby/array.h"
#include "mruby/compile.h"
#include "mruby/dump.h"
#include "mruby/variable.h"
#include "mruby/ext/mruby-argv.h"

MRB_API void
mrb_parse_argv(mrb_state *mrb, int argc, char **argv)
{
  int i;
  mrb_value ARGV;
  ARGV = mrb_const_get(mrb, mrb_obj_value(mrb->object_class), mrb_intern_lit(mrb, "ARGV"));

  for (i = 0; i < argc; i++) {
    mrb_ary_push(mrb, ARGV, mrb_str_new_cstr(mrb, argv[i]));
  }
}

void
mrb_mruby_argv_gem_init(mrb_state* mrb)
{
  mrb_value ARGV;

  ARGV = mrb_ary_new(mrb);
  mrb_define_global_const(mrb, "ARGV", ARGV);
}

void
mrb_mruby_argv_gem_final(mrb_state* mrb)
{
}

