#include "som_c.h"

/* C20F83 advance_boss_object_counters_and_dispatch_definition   [class C, 14 bytes, hand written]
 * INC $0096,X and $00AD,X (object counters), then jumps through the definition pointer at word $008E,X stored to $0276.
 * Entry: D=$0200, DB=$7E; the accumulator width is whatever the caller left (M flag read at run time).
 * Ends in `jmp (abs)`, so the routine tail-calls the pointer stored in direct page; the target's RTS returns to the caller.
 */
static void advance_boss_object_counters_and_dispatch_definition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (r->mf) { RAM8(0x0096 + x)++; RAM8(0x00AD + x)++; }
    else { RAM16_SET(0x0096 + x, (uint16_t)(RAM16(0x0096 + x) + 1)); RAM16_SET(0x00AD + x, (uint16_t)(RAM16(0x00AD + x) + 1)); }
    const uint16_t value = r->mf ? RAM8(0x008E + x) : RAM16(0x008E + x);
    r->a = r->mf ? (r->a & 0xFF00) | value : value;
    r->z = value == 0;
    r->n = r->mf ? (value & 0x80) != 0 : (value & 0x8000) != 0;
    if (r->mf) RAM8(0x0276) = (uint8_t)value; else RAM16_SET(0x0276, value);
    TAIL_CALL(c, 0xC20000 | RAM16(0x0276), SOM_RTS);
}
SOM_REGISTER(0xC20F83, SOM_RTS, "hand", advance_boss_object_counters_and_dispatch_definition, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 16, -1, -1, 14, 5)
