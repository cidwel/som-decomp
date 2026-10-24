#include "som_c.h"

/* C0AD17 initialize_complete_world_map_survey_background_and_color_planes   [class D, 204 bytes, 83 instructions]
 * Source: src/rom/initialize_complete_world_map_survey_background_and_color_planes.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCV.
 */
static void initialize_complete_world_map_survey_background_and_color_planes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    RAM8(0x2115) = 0x80;
    uint8_t x1 = 0xCE;
    for (;;) {
        RAM8(0x0300 + x1) = 0;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    RAM8(0x210D) = 0;
    RAM8(0x210D) = 0;
    RAM8(0x210E) = 0;
    RAM8(0x210E) = 0;
    RAM8(0x2105) = 3;
    RAM8(0x2131) = 0;
    RAM8(0x2107) = 0x78;
    RAM8(0x210B) = 0;
    RAM8(0x2130) = 1;
    RAM8(0x212C) = 0x11;
    RAM8(0x2115) = 0x80;
    RAM8(0x4374) = 0;
    RAM16_SET(0x0300, 0);
    RAM16_SET(0x2116, 0);
    RAM16_SET(0x4372, 0);
    RAM16_SET(0x4370, 0x1809);
    RAM16_SET(0x4375, 0xF000);
    RAM8(0x420B) = 0x80;
    RAM16_SET(0x2116, 0x7800);
    uint16_t x2 = 0;
    for (;;) {
        RAM16_SET(0x2118, x2);
        x2 = (uint16_t)(x2 + 1);
        if (!(x2 < 0x03C0)) break;
    }
    uint16_t x3 = 0;
    for (;;) {
        RAM16_SET(0x2118, x3);
        x3 = (uint16_t)(x3 + 1);
        if (!(x3 < 0x40)) break;
    }
    uint8_t a_hi1 = 0x78;
    uint8_t x4 = 0;
    bool carry1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0xC64780 + x4);
        RAM8(0x0000 + sp0) = value;
        RAM8(0x1D800 + x4) = value & 7;
        uint8_t value2 = RAM8(0x0000 + sp0);
        RAM8(0x0000 + sp0) = value2;
        RAM8(0x1D900 + x4) = value2 & 0x38;
        RAM8(0x1DA00 + x4) = (RAM8(0x0000 + sp0) & 0xC0) >> 2;
        uint8_t x4_next = (uint8_t)(x4 + 1);
        bool carry1_next = (uint8_t)(x4 + 1) >= 0xC0;
        x4 = x4_next;
        carry1 = carry1_next;
        if (!(x4 != 0xC0)) break;
    }
    RAM8(0x1D800 + x4) = 0;
    RAM8(0x1D900 + x4) = 0;
    RAM8(0x1DA00 + x4) = 0;
    RAM8(0x2121) = 0xF1;
    RAM8(0x2122) = 0xFF;
    RAM8(0x2122) = 0xFF;
    RAM8(0x2122) = 0x1F;
    RAM8(0x2122) = 0;
    RAM8(0x2121) = 0;
    RAM8(0x2122) = 0;
    RAM8(0x2122) = 0;
    r->x = x4;
    r->y = (uint8_t)((a_hi << 8) | 0x80);
    r->c = carry1;
    r->v = overflow;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AD17, SOM_RTS, "gen", initialize_complete_world_map_survey_background_and_color_planes, 0, L_X | L_Y | L_C | L_V, 1, 1, 0, 204, 83)
