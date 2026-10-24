#include "som_c.h"

/* C0BAD5 select_door_tile_variant_and_deferred_audio_parameter   [class C, 93 bytes, 50 instructions]
 * Source: src/rom/select_door_tile_variant_and_deferred_audio_parameter.s
 * Documented in docs/ui-native-map-door-controller.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void select_door_tile_variant_and_deferred_audio_parameter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    uint8_t a5;
    uint8_t a_hi5;
    if (a == 5) {
        a5 = 0xE8;
        a_hi5 = 0;
    } else {
        uint8_t a4;
        uint8_t a_hi4;
        if (a == 6) {
            a4 = 0xE9;
            a_hi4 = 1;
        } else {
            uint8_t a3;
            uint8_t a_hi3;
            if (a == 7) {
                a3 = 0xEA;
                a_hi3 = 2;
            } else {
                uint8_t a2;
                uint8_t a_hi2;
                if (a == 8) {
                    a2 = 0xEB;
                    a_hi2 = 3;
                } else {
                    uint8_t a1;
                    uint8_t a_hi1;
                    if (a == 9) {
                        a1 = 0xEB;
                        a_hi1 = 0;
                    } else {
                        a1 = 0xEC;
                        a_hi1 = 1;
                    }
                    a2 = a1;
                    a_hi2 = a_hi1;
                }
                a3 = a2;
                a_hi3 = a_hi2;
            }
            a4 = a3;
            a_hi4 = a_hi3;
        }
        a5 = a4;
        a_hi5 = a_hi4;
    }
    RAM8(0x0095) = a5;
    uint8_t value = RAM8(0xE020 + x);
    RAM8(0x0118) = value & 0xF0;
    uint8_t value2 = RAM8(0x0118);
    RAM8(0x0119) = ((value & 0xF0) >> 4) | value2;
    r->a = (a_hi5 << 8) | (((value & 0xF0) >> 4) | value2);
    r->c = (value & 0xF0) >> 3 & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BAD5, SOM_RTS, "gen", select_door_tile_variant_and_deferred_audio_parameter, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 93, 50)
