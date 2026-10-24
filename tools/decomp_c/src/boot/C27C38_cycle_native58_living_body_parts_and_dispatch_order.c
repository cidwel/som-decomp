#include "som_c.h"

/* C27C38 cycle_native58_living_body_parts_and_dispatch_order   [class B, 39 bytes, 18 instructions]
 * Source: src/rom/cycle_native58_living_body_parts_and_dispatch_order.s
 * Documented in docs/boss-native58-parent-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void cycle_native58_living_body_parts_and_dispatch_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0190 + x);
    if (!(value & 0x8000)) {
        uint8_t a_hi1 = value >> 8;
        uint16_t y1 = y;
        bool overflow1 = overflow;
        for (;;) {
            RAM16_SET(0x00B0 + x, (uint16_t)(RAM16(0x00B0 + x) + 1));
            if (RAM16(0x00B0 + x) >= 3) {
                RAM16_SET(0x00B0 + x, 0);
            }
            uint16_t value3 = RAM16(0x00B0 + x);
            uint16_t value4 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600));
            a_hi1 = value4 >> 8;
            y1 = (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600);
            overflow1 = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600)) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600) ^ 0xE600) & 0x8000) != 0;
            if (!(value4 & 0x8000)) break;
        }
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = x;
        r->y = y1;
        r->v = overflow1;
        JSR(c, 0x7C5D, 0xC27C5F); /* dispatch_native58_body_part_order */
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27C38, SOM_RTS, "gen", cycle_native58_living_body_parts_and_dispatch_order, 0, L_X, 1, 0, 0, 39, 18)
