#include "som_c.h"

/* C00089 enter_boot_menu_caller_from_public_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/enter_boot_menu_caller_from_public_alias.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCV.
 */
static void enter_boot_menu_caller_from_public_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC000C9, SOM_RTS); /* open_load_game_menu_and_enter_selected_map_or_cold_boot */
}
SOM_REGISTER(0xC00089, SOM_RTS, "gen", enter_boot_menu_caller_from_public_alias, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 3, 1)
