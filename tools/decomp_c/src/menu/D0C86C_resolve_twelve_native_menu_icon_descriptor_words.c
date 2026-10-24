#include "som_c.h"

/* D0C86C resolve_twelve_native_menu_icon_descriptor_words   [class B, 55 bytes, 29 instructions]
 * Source: src/rom/resolve_twelve_native_menu_icon_descriptor_words.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void resolve_twelve_native_menu_icon_descriptor_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint8_t a1 = 0x0C;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = 0x1880;
    uint16_t y1 = 0x18C0;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x0000 + sp0) = a1;
        RAM8(0x0000 + sp0 - 1) = x1 >> 8;
        RAM8(0x0000 + sp0 - 2) = (uint8_t)x1;
        uint8_t value = BUS8(c, 0x000000 + y1);
        uint8_t a2;
        uint8_t a_hi2;
        bool overflow2;
        if (value != 0xFF) {
            uint16_t value2 = BUS16(c, 0xD8FD62);
            uint16_t value3 = BUS16(c, 0xD8FD60 + (uint16_t)(((((a_hi1 << 8) | value) & 0xFF) << 1) + value2));
            a2 = (uint8_t)value3;
            a_hi2 = value3 >> 8;
            overflow2 = ((((((a_hi1 << 8) | value) & 0xFF) << 1) ^ (uint16_t)(((((a_hi1 << 8) | value) & 0xFF) << 1) + value2)) & (value2 ^ (uint16_t)(((((a_hi1 << 8) | value) & 0xFF) << 1) + value2)) & 0x8000) != 0;
        } else {
            a2 = 0xFF;
            a_hi2 = 0xFF;
            overflow2 = overflow1;
        }
        BUS16_SET(c, x1, (a_hi2 << 8) | a2);
        a1 = (uint8_t)(RAM8(0x0000 + sp0) - 1);
        a_hi1 = a_hi2;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 1);
        overflow1 = overflow2;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0C86C, SOM_RTS, "gen", resolve_twelve_native_menu_icon_descriptor_words, 0, L_B | L_X | L_Y | L_V, 3, 0, 0, 55, 29)
