#include "som_c.h"

/* D0D1AE build_fixed_seven_native_menu_descriptor_rows   [class A, 33 bytes, 17 instructions]
 * Source: src/rom/build_fixed_seven_native_menu_descriptor_rows.s
 * Documented in docs/event-menu-descriptor-sources.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void build_fixed_seven_native_menu_descriptor_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x1828);
    uint8_t a1 = 7;
    uint8_t a_hi1 = 0;
    uint16_t x1 = value;
    uint16_t y1 = y;
    for (;;) {
        uint16_t value2 = BUS16(c, 0xD8FD60 + x1);
        BUS16_SET(c, 0x0000 + y1, value2);
        bool again = (uint16_t)(((a_hi1 << 8) | a1) - 1) != 0;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 2);
        uint16_t y1_next = (uint16_t)(y1 + 2);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        if (!again) break;
    }
    uint16_t value3 = RAM16(0x1876);
    RAM16_SET(0x182E, value3 & 0xFF);
    r->a = value3 & 0xFF;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = (value3 & 0xFF) == 0;
    r->n = value3 & 0xFF & 0x8000;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D1AE, SOM_RTS, "hand", build_fixed_seven_native_menu_descriptor_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 33, 17)
