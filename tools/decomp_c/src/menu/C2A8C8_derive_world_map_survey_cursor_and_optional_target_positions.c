#include "som_c.h"

/* C2A8C8 derive_world_map_survey_cursor_and_optional_target_positions   [class B, 76 bytes, 44 instructions]
 * Source: src/rom/derive_world_map_survey_cursor_and_optional_target_positions.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABY.
 */
static void derive_world_map_survey_cursor_and_optional_target_positions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x0315);
    uint8_t a1;
    if (value == 0) {
        a1 = value;
    } else {
        a1 = 0x20;
    }
    RAM8(0x0302) = a1;
    uint8_t value2 = RAM8(0x03E3);
    uint8_t a_hi1;
    if (!(value2 & 0x40)) {
        a_hi1 = a_hi;
    } else {
        RAM16_SET(0x0300, RAM16(0x0128) >> 4);
        uint16_t value4 = RAM16(0x012A);
        uint8_t value5 = RAM8(0x0302);
        RAM8(0x0811) = (uint8_t)((uint8_t)((uint8_t)(value4 >> 4) - value5) - 8 - ((uint8_t)(value4 >> 4) >= value5 ^ 1));
        RAM8(0x0810) = RAM8(0x0300);
        a_hi1 = value4 >> 4 >> 8;
    }
    RAM8(0x0300) = (uint8_t)(((RAM8(0x0308) >> 1) | ((RAM8(0x0309) & 1) << 7)) - 0x10);
    uint8_t value9 = RAM8(0x030B);
    uint8_t value10 = RAM8(0x030A);
    RAM8(0x0301) = (uint8_t)((uint8_t)(((value10 >> 1) | ((value9 & 1) << 7)) - 0x10) - RAM8(0x0302) - (((value10 >> 1) | ((value9 & 1) << 7)) >= 0x10 ^ 1));
    r->a = RAM16(0x0300);
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A8C8, SOM_RTS, "gen", derive_world_map_survey_cursor_and_optional_target_positions, 0, L_A | L_B | L_Y, 1, 1, 0, 76, 44)
