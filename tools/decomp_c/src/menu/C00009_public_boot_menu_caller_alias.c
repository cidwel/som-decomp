#include "som_c.h"

/* C00009 public_boot_menu_caller_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_boot_menu_caller_alias.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCV.
 */
static void public_boot_menu_caller_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC00089, SOM_RTS); /* enter_boot_menu_caller_from_public_alias */
}
SOM_REGISTER(0xC00009, SOM_RTS, "gen", public_boot_menu_caller_alias, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 3, 1)
