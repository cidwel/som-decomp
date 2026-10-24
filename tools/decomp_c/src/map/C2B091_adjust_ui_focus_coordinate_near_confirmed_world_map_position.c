#include "som_c.h"

/* C2B091 adjust_ui_focus_coordinate_near_confirmed_world_map_position   [class B, 70 bytes, 30 instructions]
 * Source: src/rom/adjust_ui_focus_coordinate_near_confirmed_world_map_position.s
 * Documented in docs/ui-native-world-map-picker-exit.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void adjust_ui_focus_coordinate_near_confirmed_world_map_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint16_t value = RAM16(0x00FA);
    uint16_t value2 = RAM16(0x0128);
    uint8_t a_hi6;
    bool carry5;
    bool overflow6;
    if (!((uint16_t)((value & 0x0FFF) - value2) & 0x8000)) {
        uint8_t a1;
        uint8_t a_hi1;
        bool overflow1;
        if ((uint16_t)((value & 0x0FFF) - value2) < 0x0800) {
            a1 = (uint8_t)((value & 0x0FFF) - value2);
            a_hi1 = (uint16_t)((value & 0x0FFF) - value2) >> 8;
            overflow1 = (((value & 0x0FFF) ^ value2) & ((value & 0x0FFF) ^ (uint16_t)((value & 0x0FFF) - value2)) & 0x8000) != 0;
        } else {
            a1 = (uint8_t)((uint16_t)((uint16_t)((value & 0x0FFF) - value2) - 0x1000 - ((uint16_t)((value & 0x0FFF) - value2) >= 0x0800 ^ 1)) ^ 0xFFFF);
            a_hi1 = ((uint16_t)((uint16_t)((value & 0x0FFF) - value2) - 0x1000 - ((uint16_t)((value & 0x0FFF) - value2) >= 0x0800 ^ 1)) ^ 0xFFFF) >> 8;
            overflow1 = (((uint16_t)((value & 0x0FFF) - value2) ^ 0x1000) & ((uint16_t)((value & 0x0FFF) - value2) ^ (uint16_t)((uint16_t)((value & 0x0FFF) - value2) - 0x1000 - ((uint16_t)((value & 0x0FFF) - value2) >= 0x0800 ^ 1))) & 0x8000) != 0;
        }
        uint8_t a_hi2;
        bool carry1;
        bool overflow2;
        if (((a_hi1 << 8) | a1) >= 0x80) {
            a_hi2 = a_hi1;
            carry1 = ((a_hi1 << 8) | a1) >= 0x80;
            overflow2 = overflow1;
        } else {
            RAM16_SET(0x0128, (uint16_t)(value - 0x80) & 0x0FFF);
            a_hi2 = ((uint16_t)(value - 0x80) & 0x0FFF) >> 8;
            carry1 = value >= 0x80;
            overflow2 = ((value ^ 0x80) & (value ^ (uint16_t)(value - 0x80)) & 0x8000) != 0;
        }
        a_hi6 = a_hi2;
        carry5 = carry1;
        overflow6 = overflow2;
    } else {
        uint8_t a_hi5;
        bool carry4;
        bool overflow5;
        if ((uint16_t)((value & 0x0FFF) - value2) < 0xF801) {
            uint8_t a_hi3;
            bool carry2;
            bool overflow3;
            if ((uint16_t)((uint16_t)((value & 0x0FFF) - value2) + 0x1000 + ((uint16_t)((value & 0x0FFF) - value2) >= 0xF801)) >= 0x80) {
                a_hi3 = (uint16_t)((uint16_t)((value & 0x0FFF) - value2) + 0x1000 + ((uint16_t)((value & 0x0FFF) - value2) >= 0xF801)) >> 8;
                carry2 = (uint16_t)((uint16_t)((value & 0x0FFF) - value2) + 0x1000 + ((uint16_t)((value & 0x0FFF) - value2) >= 0xF801)) >= 0x80;
                overflow3 = (((uint16_t)((value & 0x0FFF) - value2) ^ (uint16_t)((uint16_t)((value & 0x0FFF) - value2) + 0x1000 + ((uint16_t)((value & 0x0FFF) - value2) >= 0xF801))) & ((uint16_t)((uint16_t)((value & 0x0FFF) - value2) + 0x1000 + ((uint16_t)((value & 0x0FFF) - value2) >= 0xF801)) ^ 0x1000) & 0x8000) != 0;
            } else {
                RAM16_SET(0x0128, (uint16_t)(value + 0x80) & 0x0FFF);
                a_hi3 = ((uint16_t)(value + 0x80) & 0x0FFF) >> 8;
                carry2 = value + 0x80 > 0xFFFF;
                overflow3 = ((value ^ (uint16_t)(value + 0x80)) & ((uint16_t)(value + 0x80) ^ 0x80) & 0x8000) != 0;
            }
            a_hi5 = a_hi3;
            carry4 = carry2;
            overflow5 = overflow3;
        } else {
            uint8_t a_hi4;
            bool carry3;
            bool overflow4;
            if ((uint16_t)((value & 0x0FFF) - value2) < 0xFF80) {
                a_hi4 = (uint16_t)((value & 0x0FFF) - value2) >> 8;
                carry3 = (uint16_t)((value & 0x0FFF) - value2) >= 0xFF80;
                overflow4 = (((value & 0x0FFF) ^ value2) & ((value & 0x0FFF) ^ (uint16_t)((value & 0x0FFF) - value2)) & 0x8000) != 0;
            } else {
                RAM16_SET(0x0128, (uint16_t)(value + 0x80) & 0x0FFF);
                a_hi4 = ((uint16_t)(value + 0x80) & 0x0FFF) >> 8;
                carry3 = value + 0x80 > 0xFFFF;
                overflow4 = ((value ^ (uint16_t)(value + 0x80)) & ((uint16_t)(value + 0x80) ^ 0x80) & 0x8000) != 0;
            }
            a_hi5 = a_hi4;
            carry4 = carry3;
            overflow5 = overflow4;
        }
        a_hi6 = a_hi5;
        carry5 = carry4;
        overflow6 = overflow5;
    }
    r->a = (a_hi6 << 8) | a;
    r->c = carry5;
    r->v = overflow6;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B091, SOM_RTL, "gen", adjust_ui_focus_coordinate_near_confirmed_world_map_position, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 70, 30)
