#include "som_c.h"

/* C1F5CE upload_map_scroll_graphics_templates   [class D, 95 bytes, 44 instructions]
 * Source: src/rom/upload_map_scroll_graphics_templates.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void upload_map_scroll_graphics_templates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t value2 = BUS8(c, 0xC80400 + RAM8(0x001C));
    RAM8(0x0000) = 0;
    uint8_t a1 = 0;
    uint8_t a_hi1 = (((a_hi << 8) | value2) & 0xFF) << 1 >> 8;
    uint16_t x1 = (((a_hi << 8) | value2) & 0xFF) << 1;
    bool carry1 = ((a_hi << 8) | value2) & 0xFF & 0x8000;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value3 = BUS8(c, 0xC80441 + x1);
        BUS8_SET(c, 0x002115, 0x80);
        BUS8_SET(c, 0x004374, 0xDC);
        BUS16_SET(c, 0x004372, ((((value3 & 0x3F) << 1) | 0x80) << 8) | 0);
        BUS16_SET(c, 0x004370, 0x1801);
        BUS16_SET(c, 0x004375, 0x80);
        uint16_t value4 = RAM16(0x0000);
        BUS16_SET(c, 0x002116, ((((value4 & 7) << 8) | 0) >> 2) + 0x3600);
        BUS8_SET(c, 0x00420B, 0x80);
        RAM8(0x0000)++;
        uint8_t value5 = RAM8(0x0000);
        a1 = value5;
        a_hi1 = ((((value4 & 7) << 8) | 0) >> 2) + 0x3600 >> 8;
        x1 = (uint16_t)(x1 + 1);
        carry1 = value5 >= 8;
        overflow1 = ((((((value4 & 7) << 8) | 0) >> 2) ^ ((((value4 & 7) << 8) | 0) >> 2) + 0x3600) & (((((value4 & 7) << 8) | 0) >> 2) + 0x3600 ^ 0x3600) & 0x8000) != 0;
        if (!(a1 < 8)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F5CE, SOM_RTS, "gen", upload_map_scroll_graphics_templates, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 95, 44)
