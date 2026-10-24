#include "som_c.h"

/* C0900A compute_bounded_scene_target_angle_with_hardware_division   [class B, 112 bytes, 61 instructions]
 * Source: src/rom/compute_bounded_scene_target_angle_with_hardware_division.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void compute_bounded_scene_target_angle_with_hardware_division(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t y = r->y;
    uint16_t value = RAM16(0x0084);
    RAM16_SET(0x0000, value);
    uint16_t value2 = RAM16(0x00F7);
    uint16_t value3 = RAM16(0x0088);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value2 & 0x01)) {
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
    } else {
        RAM16_SET(0x0000, value3);
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
    }
    RAM16_SET(0x0002, (a_hi1 << 8) | a1);
    RAM16_SET(0x0004, 0);
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        uint16_t value4 = RAM16(0x0000);
        if (value4 >= 0x0100) {
            RAM16_SET(0x0000, RAM16(0x0000) >> 1);
            RAM16_SET(0x0002, RAM16(0x0002) >> 1);
            a_hi2 = value4 >> 8;
            continue;
        }
        uint16_t value7 = RAM16(0x0002);
        if (value7 >= 0x0100) {
            RAM16_SET(0x0000, RAM16(0x0000) >> 1);
            RAM16_SET(0x0002, RAM16(0x0002) >> 1);
            a_hi2 = value7 >> 8;
            continue;
        }
        a_hi2 = value7 >> 8;
        break;
    }
    uint16_t value10 = RAM16(0x0000);
    if (value10 >= RAM16(0x0002)) {
        RAM8(0x0000 + sp0) = value10 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value10;
        RAM16_SET(0x0000, RAM16(0x0002));
        RAM16_SET(0x0002, value10);
        RAM16_SET(0x0004, (uint16_t)(RAM16(0x0004) - 1));
    }
    uint16_t value13 = RAM16(0x0000);
    BUS16_SET(c, 0x004204, (uint16_t)(value13 << 4));
    BUS8_SET(c, 0x004206, RAM8(0x0002));
    uint8_t value15 = BUS8(c, 0x004214);
    uint8_t a2;
    if (value15 < 0x11) {
        a2 = value15;
    } else {
        a2 = 0x10;
    }
    uint8_t value16 = BUS8(c, 0x00907A + (uint8_t)(((uint16_t)(value13 << 4) >> 8 << 8) | a2));
    uint8_t value17 = RAM8(0x0004);
    uint8_t a3;
    if (!(value17 & 0x80)) {
        a3 = value16;
    } else {
        a3 = value16 ^ 0xFF;
    }
    RAM8(0x0096) = a3;
    RAM8(0x00F6) = a3;
    uint8_t value18 = RAM8(0x00F7);
    RAM8(0x0097) = value18;
    r->a = ((uint16_t)(value13 << 4) >> 8 << 8) | value18;
    r->x = (uint8_t)(((uint16_t)(value13 << 4) >> 8 << 8) | a2);
    r->y = y;
    r->c = value15 >= 0x11;
    r->v = value17 & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0900A, SOM_RTS, "gen", compute_bounded_scene_target_angle_with_hardware_division, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 112, 61)
