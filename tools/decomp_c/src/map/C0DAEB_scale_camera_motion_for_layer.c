#include "som_c.h"

/* C0DAEB scale_camera_motion_for_layer   [class A, 51 bytes, 31 instructions]
 * Source: src/rom/scale_camera_motion_for_layer.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void scale_camera_motion_for_layer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t x = r->x;
    RAM8(0x0000) = a;
    uint8_t value = RAM8(0x0A80 + x);
    if (value != 0) {
        if (value != 1) {
            if (value != 2) {
                uint8_t value2 = RAM8(0x0000);
                uint8_t value3 = RAM8(0x0000);
                RAM8(0x0000) <<= 1;
                SET_A8(r, ((uint8_t)(value2 << 2) >> 1) | (value3 >> 7 << 7));
                r->c = 0;
                r->z = (((uint8_t)(value2 << 2) >> 1) | (value3 >> 7 << 7)) == 0;
                r->n = (((uint8_t)(value2 << 2) >> 1) | (value3 >> 7 << 7)) & 0x80;
                RETURN_RTS(c);
            }
            uint8_t value4 = RAM8(0x0000);
            SET_A8(r, value4);
            r->c = 0;
            r->z = value4 == 0;
            r->n = value4 & 0x80;
            RETURN_RTS(c);
        }
        uint8_t value5 = RAM8(0x0000);
        uint8_t a1;
        if ((value5 & 0x7F) >> 1 != 0) {
            a1 = (value5 & 0x7F) >> 1;
        } else {
            RAM8(0x0A81 + x)++;
            a1 = RAM8(0x0A81 + x) & 1;
        }
        uint8_t value7 = RAM8(0x0000);
        RAM8(0x0000) <<= 1;
        SET_A8(r, ((uint8_t)(a1 << 1) >> 1) | (value7 >> 7 << 7));
        r->c = 0;
        r->z = (((uint8_t)(a1 << 1) >> 1) | (value7 >> 7 << 7)) == 0;
        r->n = (((uint8_t)(a1 << 1) >> 1) | (value7 >> 7 << 7)) & 0x80;
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->c = 1;
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DAEB, SOM_RTS, "gen", scale_camera_motion_for_layer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 51, 31)
