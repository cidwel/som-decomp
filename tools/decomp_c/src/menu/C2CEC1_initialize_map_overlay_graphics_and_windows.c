#include "som_c.h"

/* C2CEC1 initialize_map_overlay_graphics_and_windows   [class D, 247 bytes, 97 instructions]
 * Source: src/rom/initialize_map_overlay_graphics_and_windows.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_map_overlay_graphics_and_windows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool overflow = r->v;
    RAM16_SET(0x00B4, (uint16_t)(RAM16(0x00B4) - 2));
    RAM16_SET(0x00B6, (uint16_t)(RAM16(0x00B6) - 1));
    BUS16_SET(c, 0x004372, 0x0380);
    BUS8_SET(c, 0x004374, 0xC8);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS16_SET(c, 0x004375, 0x60);
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x002116, 0x4100);
    BUS8_SET(c, 0x00420B, 0x80);
    uint16_t value3 = BUS16(c, 0xC80340);
    BUS16_SET(c, 0x002116, ((value3 & 0xFF) << 1 << 1 << 1 << 1 << 1) | 0x5800);
    uint8_t a_hi1 = (((value3 & 0xFF) << 1 << 1 << 1 << 1 << 1) | 0x5800) >> 8;
    uint8_t x1 = 0x10;
    for (;;) {
        BUS16_SET(c, 0x002118, 0x3020);
        BUS16_SET(c, 0x002118, 0x3021);
        a_hi1 = 0x30;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t a_hi2 = a_hi1;
    uint8_t x2 = 0x10;
    for (;;) {
        BUS16_SET(c, 0x002118, 0x3022);
        BUS16_SET(c, 0x002118, 0x3023);
        a_hi2 = 0x30;
        x2 = (uint8_t)(x2 - 1);
        if (!(x2 != 0)) break;
    }
    uint8_t a_hi3 = a_hi2;
    uint8_t x3 = 0x10;
    for (;;) {
        BUS16_SET(c, 0x002118, 0x3424);
        BUS16_SET(c, 0x002118, 0x3425);
        a_hi3 = 0x34;
        x3 = (uint8_t)(x3 - 1);
        if (!(x3 != 0)) break;
    }
    uint8_t a_hi4 = a_hi3;
    uint8_t x4 = 0;
    for (;;) {
        uint16_t value4 = BUS16(c, 0xC80340 + x4);
        RAM16_SET(0xEF80 + x4, value4);
        a_hi4 = value4 >> 8;
        x4 = (uint8_t)(x4 + 2);
        if (!(x4 < 0x80)) break;
    }
    RAM16_SET(0xEF80, 1);
    RAM16_SET(0xEF01, 0xEF80);
    RAM16_SET(0xEF04, 0xEF80);
    RAM16_SET(0xEF0A, 0xEF80);
    RAM16_SET(0xEF07, 0xEF82);
    RAM16_SET(0xEF20, 0x0960);
    RAM16_SET(0xEF22, 0x0160);
    RAM16_SET(0xEF24, 0);
    r->x = x4;
    r->y = y;
    r->v = overflow;
    r->mf = 0;
    JSR(c, 0xCF80, 0xC2C7B2); /* configure_map_overlay_hdma_channels */
    RAM8(0xEF0C) = 0;
    uint8_t value5 = BUS8(c, 0xC80340);
    RAM8(0xEF00) = (uint8_t)(value5 << 2);
    RAM8(0xEF03) = (uint8_t)((uint8_t)(value5 << 2) - 1);
    RAM8(0xEF06) = 0x9F;
    RAM8(0xEF09) = 0x40;
    RAM8(0x002C) = 0x0C;
    BUS8_SET(c, 0x002123, 0x22);
    BUS8_SET(c, 0x002124, 3);
    BUS8_SET(c, 0x00212E, 1);
    SET_A8(r, 1);
    r->c = (uint8_t)(value5 << 1) & 0x80;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2CEC1, SOM_RTL, "gen", initialize_map_overlay_graphics_and_windows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 247, 97)
