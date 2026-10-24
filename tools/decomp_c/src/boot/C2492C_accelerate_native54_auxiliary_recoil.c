#include "som_c.h"

/* C2492C accelerate_native54_auxiliary_recoil   [class B, 57 bytes, 23 instructions]
 * Source: src/rom/accelerate_native54_auxiliary_recoil.s
 * Documented in docs/boss-native54-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void accelerate_native54_auxiliary_recoil(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x003C + x, (uint16_t)(RAM16(0x003C + x) + 0x0600));
    RAM16_SET(0x0040 + x, (uint16_t)(RAM16(0x0040 + x) + 0x0400));
    RAM16_SET(0x00B4 + x, (uint16_t)(RAM16(0x00B4 + x) + RAM16(0x003C + x)));
    RAM16_SET(0x00B6 + x, (uint16_t)(RAM16(0x00B6 + x) + RAM16(0x0040 + x)));
    RAM8(0xF812 + y) = RAM8(0x00B5 + x);
    RAM8(0xF80E + y) = RAM8(0x00B7 + x);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2492C, SOM_RTS, "gen", accelerate_native54_auxiliary_recoil, 0, 0, 1, 0, 0, 57, 23)
