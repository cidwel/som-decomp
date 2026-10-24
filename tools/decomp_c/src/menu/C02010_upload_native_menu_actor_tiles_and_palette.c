#include "som_c.h"

/* C02010 upload_native_menu_actor_tiles_and_palette   [class D, 74 bytes, 36 instructions]
 * Source: src/rom/upload_native_menu_actor_tiles_and_palette.s
 * Documented in docs/event-menu-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BCV.
 */
static void upload_native_menu_actor_tiles_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS16_SET(c, 0x002116, 0x4200);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 2;
    for (;;) {
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = 8;
        for (;;) {
            uint16_t value = BUS16(c, 0xD2DA30 + x2);
            BUS16_SET(c, 0x002118, value);
            a_hi2 = value >> 8;
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 - 1);
            if (!(y2 != 0)) break;
        }
        uint16_t y3 = 8;
        for (;;) {
            BUS16_SET(c, 0x002118, 0);
            y3 = (uint16_t)(y3 - 1);
            if (!(y3 != 0)) break;
        }
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    BUS8_SET(c, 0x002121, 0x81);
    uint8_t a_hi3 = a_hi1;
    uint16_t x3 = 0x30;
    uint16_t y4 = 6;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xD2DBC0 + x3);
        BUS8_SET(c, 0x002122, value2);
        x3 = (uint16_t)(x3 + 1);
        y4 = (uint16_t)(y4 - 1);
        if (!(y4 != 0)) break;
    }
    r->a = (a_hi3 << 8) | a;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02010, SOM_RTS, "gen", upload_native_menu_actor_tiles_and_palette, 0, L_B | L_C | L_V, 3, 1, 0, 74, 36)
