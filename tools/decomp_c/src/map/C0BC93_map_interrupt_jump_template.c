#include "som_c.h"

/* C0BC93 map_interrupt_jump_template   [class A, 8 bytes, 2 instructions]
 * Source: src/rom/map_interrupt_jump_template.s
 * Entry: M=any X=any DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void map_interrupt_jump_template(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    TAIL_CALL(c, 0x00C0A8, SOM_RTS); /* service_complete_map_frame_nmi */
}
SOM_REGISTER(0xC0BC93, SOM_RTS, "gen", map_interrupt_jump_template, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 8, 2)
