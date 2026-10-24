#include "som_c.h"

/* C76AA4 read_selected_native_party_status_excluding_low_two_bits   [class A, 19 bytes, 10 instructions]
 * Source: src/rom/read_selected_native_party_status_excluding_low_two_bits.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void read_selected_native_party_status_excluding_low_two_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    uint16_t value = RAM16(0x19FE);
    uint16_t value2 = RAM16(ACTOR_STATUS + (uint16_t)(((((uint8_t)value << 8) | (value >> 8)) & 0xFF00) << 1));
    r->a = value2 & 0xFFFC;
    r->c = (((uint8_t)value << 8) | (value >> 8)) & 0xFF00 & 0x8000;
    r->z = (value2 & 0xFFFC) == 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76AA4, SOM_RTS, "gen", read_selected_native_party_status_excluding_low_two_bits, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 0, 0, 19, 10)
