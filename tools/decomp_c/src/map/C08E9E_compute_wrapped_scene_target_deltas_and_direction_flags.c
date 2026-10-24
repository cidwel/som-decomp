#include "som_c.h"

/* C08E9E compute_wrapped_scene_target_deltas_and_direction_flags   [class B, 134 bytes, 68 instructions]
 * Source: src/rom/compute_wrapped_scene_target_deltas_and_direction_flags.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void compute_wrapped_scene_target_deltas_and_direction_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x0004, (RAM16(0x0110) & 0xFF) << 1 << 1 << 1 << 1);
    RAM16_SET(0x0006, (RAM16(0x0111) & 0xFF) << 1 << 1 << 1 << 1);
    uint16_t value3 = RAM16(0x00FA);
    uint16_t value4 = RAM16(0x0004);
    uint8_t a_hi3;
    if (value3 >= value4) {
        uint8_t a_hi1;
        if ((uint16_t)(value3 - value4) < 0x0800) {
            RAM16_SET(0x0000, (uint16_t)(value3 - value4));
            uint16_t value5 = RAM16(0x008D);
            RAM16_SET(0x008D, value5 ^ 0x80);
            a_hi1 = (value5 ^ 0x80) >> 8;
        } else {
            RAM16_SET(0x0000, (uint16_t)(((uint16_t)(value3 - value4) ^ 0x0FFF) + 1));
            a_hi1 = (uint16_t)(((uint16_t)(value3 - value4) ^ 0x0FFF) + 1) >> 8;
        }
        a_hi3 = a_hi1;
    } else {
        uint8_t a_hi2;
        if ((uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) < 0x0800) {
            RAM16_SET(0x0000, (uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1));
            a_hi2 = (uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) >> 8;
        } else {
            RAM16_SET(0x0000, (uint16_t)(((uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) ^ 0x0FFF) + 1));
            uint16_t value6 = RAM16(0x008D);
            RAM16_SET(0x008D, value6 ^ 0x80);
            a_hi2 = (value6 ^ 0x80) >> 8;
        }
        a_hi3 = a_hi2;
    }
    uint16_t value7 = RAM16(0x00FC);
    uint16_t value8 = RAM16(0x0006);
    uint8_t a_hi6;
    if (value7 >= value8) {
        uint8_t a_hi4;
        if ((uint16_t)(value7 - value8) < 0x0800) {
            RAM16_SET(0x0002, (uint16_t)(value7 - value8));
            uint16_t value9 = RAM16(0x008D);
            RAM16_SET(0x008D, value9 ^ 0x40);
            a_hi4 = (value9 ^ 0x40) >> 8;
        } else {
            RAM16_SET(0x0002, (uint16_t)(((uint16_t)(value7 - value8) ^ 0x0FFF) + 1));
            a_hi4 = (uint16_t)(((uint16_t)(value7 - value8) ^ 0x0FFF) + 1) >> 8;
        }
        a_hi6 = a_hi4;
    } else {
        uint8_t a_hi5;
        if ((uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1) < 0x0800) {
            RAM16_SET(0x0002, (uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1));
            a_hi5 = (uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1) >> 8;
        } else {
            RAM16_SET(0x0002, (uint16_t)(((uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1) ^ 0x0FFF) + 1));
            uint16_t value10 = RAM16(0x008D);
            RAM16_SET(0x008D, value10 ^ 0x40);
            a_hi5 = (value10 ^ 0x40) >> 8;
        }
        a_hi6 = a_hi5;
    }
    RAM16_SET(0x0084, RAM16(0x0000) >> 1);
    uint16_t value12 = RAM16(0x0002);
    RAM16_SET(0x0088, value12 >> 1);
    RAM16_SET(0x0086, 0);
    RAM16_SET(0x008A, 0);
    RAM16_SET(0x008E, 0x01FF);
    r->a = 0x01FF;
    r->c = value12 & 0x01;
    r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08E9E, SOM_RTS, "gen", compute_wrapped_scene_target_deltas_and_direction_flags, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 134, 68)
