#include "som_c.h"

/* C28D62 set_descriptor_eleven_vertical_velocity_toward_target   [class A, 32 bytes, 15 instructions]
 * Source: src/rom/set_descriptor_eleven_vertical_velocity_toward_target.s
 * Documented in docs/boss-descriptor-eleven-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void set_descriptor_eleven_vertical_velocity_toward_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint16_t value2 = RAM16(0x0032 + x);
    uint16_t value3 = RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    if (value2 < value3) {
        RAM16_SET(0x0040 + x, 2);
        r->a = 2;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->c = value2 >= value3;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0040 + x, 0xFFFE);
    r->a = 0xFFFE;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = value2 >= value3;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28D62, SOM_RTS, "gen", set_descriptor_eleven_vertical_velocity_toward_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 32, 15)
