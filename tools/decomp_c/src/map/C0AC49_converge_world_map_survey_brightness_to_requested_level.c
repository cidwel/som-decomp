#include "som_c.h"

/* C0AC49 converge_world_map_survey_brightness_to_requested_level   [class D, 21 bytes, 10 instructions]
 * Source: src/rom/converge_world_map_survey_brightness_to_requested_level.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void converge_world_map_survey_brightness_to_requested_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value = RAM8(0x000C);
    uint8_t value2 = RAM8(0x000D);
    uint8_t a2;
    if (value == value2) {
        a2 = value;
    } else {
        uint8_t a1;
        if (value >= value2) {
            a1 = (uint8_t)(value - 1);
        } else {
            a1 = (uint8_t)(value + 1);
        }
        RAM8(0x000C) = a1;
        a2 = a1;
    }
    RAM8(0x2100) = a2;
    r->c = value >= value2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AC49, SOM_RTS, "gen", converge_world_map_survey_brightness_to_requested_level, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 21, 10)
