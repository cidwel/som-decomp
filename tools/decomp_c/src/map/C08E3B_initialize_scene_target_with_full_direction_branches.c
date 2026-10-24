#include "som_c.h"

/* C08E3B initialize_scene_target_with_full_direction_branches   [class B, 98 bytes, 49 instructions]
 * Source: src/rom/initialize_scene_target_with_full_direction_branches.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void initialize_scene_target_with_full_direction_branches(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x008C) = 1;
    RAM8(0x008D) = 0;
    uint8_t value = RAM8(0x00E3);
    if ((value & 6) == 0) {
        if (!(value & 0x01)) {
            JSR(c, 0x8E94, 0xC08E9E); /* compute_wrapped_scene_target_deltas_and_direction_flags */
            RAM16_SET(0x0084, RAM16(0x0000));
            uint16_t value3 = RAM16(0x0002);
            RAM16_SET(0x0088, value3);
            r->a = value3;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        JSR(c, 0x8E6D, 0xC08E9E); /* compute_wrapped_scene_target_deltas_and_direction_flags */
        uint16_t a_all2 = r->a;
        RAM8(0x00F2) = 0;
        uint8_t value4 = RAM8(0x008D);
        uint8_t a7;
        if (value4 & 0x80) {
            uint8_t a2;
            if (!(value4 & 0x40)) {
                a2 = 1;
            } else {
                uint8_t a1;
                if (value4 & 0x40) {
                    a1 = 0;
                } else {
                    a1 = 3;
                }
                a2 = a1;
            }
            a7 = a2;
        } else {
            uint8_t a6;
            if (!(value4 & 0x40)) {
                a6 = 2;
            } else {
                uint8_t a5;
                if (value4 & 0x40) {
                    a5 = 3;
                } else {
                    uint8_t a4;
                    if (!(value4 & 0x40)) {
                        a4 = 1;
                    } else {
                        uint8_t a3;
                        if (value4 & 0x40) {
                            a3 = 0;
                        } else {
                            a3 = 3;
                        }
                        a4 = a3;
                    }
                    a5 = a4;
                }
                a6 = a5;
            }
            a7 = a6;
        }
        RAM8(0x00F7) = a7;
        r->a = (a_all2 >> 8 << 8) | a7;
        r->v = value4 & 0x40;
        r->mf = 1;
        r->xf = 1;
        TAIL_CALL(c, 0xC0900A, SOM_RTS); /* compute_bounded_scene_target_angle_with_hardware_division */
    }
    RAM8(0x008F) = 3;
    RAM8(0x008E) = 0xFF;
    RAM8(0x00F8) = 0xE0;
    RAM8(0x00F2) = 0;
    RAM8(0x0086) = 0x80;
    RAM16_SET(0x0084, RAM16(0x00FA));
    uint16_t value6 = RAM16(0x00FC);
    RAM16_SET(0x0088, value6);
    RAM16_SET(0x008A, 0);
    r->a = value6;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08E3B, SOM_RTS, "gen", initialize_scene_target_with_full_direction_branches, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 99, 49)
