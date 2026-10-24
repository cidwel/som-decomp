#include "som_c.h"

/* C26C77 advance_captured_boss_target_y_and_set_recovery   [class A, 40 bytes, 19 instructions]
 * Source: src/rom/advance_captured_boss_target_y_and_set_recovery.s
 * Documented in docs/boss-native-child-capture.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_captured_boss_target_y_and_set_recovery(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint16_t value2 = RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    RAM16_SET(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), (uint16_t)(value2 + 2));
    if (RAM8(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) == 0) {
        RAM8(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x0E;
    }
    RAM8(0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 1;
    r->a = ((uint16_t)(value2 + 2) >> 8 << 8) | 1;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = value2 + 2 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((value2 ^ (uint16_t)(value2 + 2)) & ((uint16_t)(value2 + 2) ^ 2) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26C77, SOM_RTS, "gen", advance_captured_boss_target_y_and_set_recovery, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 40, 19)
