#include "som_c.h"

/* C0D2C2 advance_and_clamp_actor_vertical_motion   [class A, 30 bytes, 14 instructions]
 * Source: src/rom/advance_and_clamp_actor_vertical_motion.s
 * Documented in docs/map-actor-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XCV.
 */
static void advance_and_clamp_actor_vertical_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool negative = r->n;
    uint8_t a3;
    bool carry1;
    bool overflow1;
    if (negative) {
        uint8_t value = RAM8(0xE045 + x);
        uint8_t a1;
        if (!((uint8_t)(a + value) & 0x80)) {
            a1 = (uint8_t)(a + value);
        } else {
            RAM8(0xE008 + x) = 0;
            a1 = 0;
        }
        a3 = a1;
        carry1 = a + value > 0xFF;
        overflow1 = ((a ^ (uint8_t)(a + value)) & (value ^ (uint8_t)(a + value)) & 0x80) != 0;
    } else {
        uint8_t value2 = RAM8(0xE045 + x);
        uint8_t a2;
        if (!((uint8_t)(a + value2) & 0x80)) {
            a2 = (uint8_t)(a + value2);
        } else {
            RAM8(0xE008 + x) = 0;
            a2 = 0x7F;
        }
        a3 = a2;
        carry1 = a + value2 > 0xFF;
        overflow1 = ((a ^ (uint8_t)(a + value2)) & (value2 ^ (uint8_t)(a + value2)) & 0x80) != 0;
    }
    RAM8(0xE045 + x) = a3;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D2C2, SOM_RTS, "gen", advance_and_clamp_actor_vertical_motion, 0, L_X | L_C | L_V, 1, 1, 0, 30, 14)
