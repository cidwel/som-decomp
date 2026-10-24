#include "som_c.h"

/* C1EA99 event_reload_map_pieces_and_redraw   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/event_reload_map_pieces_and_redraw.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_reload_map_pieces_and_redraw(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint16_t value = RAM16(0x00D1);
    r->c = 1;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEAA1, 0x00CAFF); GUARD_JSL(c, sp_call, 0xEAA1); } /* reload_map_pieces_preserving_low_scratch_and_redraw */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EA99, SOM_RTS, "gen", event_reload_map_pieces_and_redraw, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 10, 5)
