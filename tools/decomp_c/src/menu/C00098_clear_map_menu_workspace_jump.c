#include "som_c.h"

/* C00098 clear_map_menu_workspace_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/clear_map_menu_workspace_jump.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXY.
 */
static void clear_map_menu_workspace_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    TAIL_CALL(c, 0xC01063, SOM_RTL); /* clear_map_menu_workspace */
}
SOM_REGISTER(0xC00098, SOM_RTL, "gen", clear_map_menu_workspace_jump, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 3, 1)
