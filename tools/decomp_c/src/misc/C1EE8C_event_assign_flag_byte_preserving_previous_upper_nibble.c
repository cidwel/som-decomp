#include "som_c.h"

/* C1EE8C event_assign_flag_byte_preserving_previous_upper_nibble   [class A, 29 bytes, 14 instructions]
 * Source: src/rom/event_assign_flag_byte_preserving_previous_upper_nibble.s
 * Documented in docs/event-vm-actor-movement.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_assign_flag_byte_preserving_previous_upper_nibble(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value;
    BUS8_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, value);
    RAM8(0x0000) = value;
    uint8_t value2 = RAM8(0x0005);
    RAM8(EVENT_FLAG_BYTES + value2) = (RAM8(EVENT_FLAG_BYTES + value2) & 0xF0) | RAM8(0x0000);
    uint16_t value4 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value4 + 3));
    r->a = (uint16_t)(value4 + 3);
    r->x = value2;
    r->y = 2;
    r->c = value4 + 3 > 0xFFFF;
    r->z = (uint16_t)(value4 + 3) == 0;
    r->n = (uint16_t)(value4 + 3) & 0x8000;
    r->v = ((value4 ^ (uint16_t)(value4 + 3)) & ((uint16_t)(value4 + 3) ^ 3) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EE8C, SOM_RTS, "hand", event_assign_flag_byte_preserving_previous_upper_nibble, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 29, 14)
