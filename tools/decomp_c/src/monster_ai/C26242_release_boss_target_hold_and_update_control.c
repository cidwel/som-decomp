#include "som_c.h"

/* C26242 release_boss_target_hold_and_update_control   [class B, 49 bytes, 22 instructions]
 * Source: src/rom/release_boss_target_hold_and_update_control.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_boss_target_hold_and_update_control(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x007E + x, 1);
    uint16_t value = RAM16(0x00A9 + x);
    if (RAM8(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) == 0) {
        if (!(RAM8(0x0190 + x) & 0x80)) {
            RAM8(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x0E;
        }
    }
    RAM8(0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 1;
    uint8_t value4 = RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = value4 & 0x7F;
    r->a = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) >> 8 << 8 | (value4 & 0x7F);
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->z = (value4 & 0x7F) == 0;
    r->n = value4 & 0x7F & 0x80;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26242, SOM_RTS, "gen", release_boss_target_hold_and_update_control, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 22)
