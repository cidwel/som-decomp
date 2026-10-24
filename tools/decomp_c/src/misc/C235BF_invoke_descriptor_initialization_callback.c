#include "som_c.h"

/* C235BF invoke_descriptor_initialization_callback   [class C, 13 bytes, hand written]
 * Loads the current descriptor index from $87 and calls its initialization callback (word at $00B4,X) unless it is zero.
 * Entry: D=$0200, DB=$7E; the accumulator width is whatever the caller left (M flag read at run time).
 * Ends in `jmp (abs)`, so the routine tail-calls the pointer stored in direct page; the target's RTS returns to the caller.
 */
static void invoke_descriptor_initialization_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->xf ? RAM8(0x0287) : RAM16(0x0287);
    r->x = x;
    const uint16_t value = r->mf ? RAM8(0x00B4 + x) : RAM16(0x00B4 + x);
    r->a = r->mf ? (r->a & 0xFF00) | value : value;
    r->z = value == 0;
    r->n = r->mf ? (value & 0x80) != 0 : (value & 0x8000) != 0;
    if (value == 0) RETURN_RTS(c);
    if (r->mf) RAM8(0x020C) = (uint8_t)value; else RAM16_SET(0x020C, value);
    TAIL_CALL(c, 0xC20000 | RAM16(0x020C), SOM_RTS);
}
SOM_REGISTER(0xC235BF, SOM_RTS, "hand", invoke_descriptor_initialization_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 16, -1, -1, 13, 6)
