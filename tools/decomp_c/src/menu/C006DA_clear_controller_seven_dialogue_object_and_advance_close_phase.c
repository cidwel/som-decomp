#include "som_c.h"

/* C006DA clear_controller_seven_dialogue_object_and_advance_close_phase   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/clear_controller_seven_dialogue_object_and_advance_close_phase.s
 * Documented in docs/event-dialogue-window-close.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void clear_controller_seven_dialogue_object_and_advance_close_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x1D14);
    RAM8(0x0000 + value) = 0;
    RAM8(0xA15E)++;
    r->a = value;
    r->x = value;
    r->z = RAM8(0xA15E) == 0;
    r->n = RAM8(0xA15E) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC006DA, SOM_RTS, "gen", clear_controller_seven_dialogue_object_and_advance_close_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 7)
