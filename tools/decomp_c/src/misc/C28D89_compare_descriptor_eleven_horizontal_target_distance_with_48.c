#include "som_c.h"

/* C28D89 compare_descriptor_eleven_horizontal_target_distance_with_48   [class A, 28 bytes, 15 instructions]
 * Source: src/rom/compare_descriptor_eleven_horizontal_target_distance_with_48.s
 * Documented in docs/boss-descriptor-eleven-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BC.
 */
static void compare_descriptor_eleven_horizontal_target_distance_with_48(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00A9 + value);
    uint16_t value3 = RAM16(0x002B + value);
    uint16_t value4 = RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value3 - value4) & 0x8000)) {
        a1 = (uint8_t)(value3 - value4);
        a_hi1 = (uint16_t)(value3 - value4) >> 8;
    } else {
        uint16_t value5 = RAM16(0x02C7);
        a1 = (uint8_t)(((uint16_t)(value3 - value4) ^ value5) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value3 - value4) ^ value5) + 1) >> 8;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = ((a_hi1 << 8) | a1) >= 0x30;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28D89, SOM_RTS, "gen", compare_descriptor_eleven_horizontal_target_distance_with_48, 0, L_B | L_C, 1, 0, 0, 28, 15)
