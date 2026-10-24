#include "som_c.h"

/* C760BA store_native_shop_five_bit_selector_and_form_oam_coordinate   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/store_native_shop_five_bit_selector_and_form_oam_coordinate.s
 * Documented in docs/event-menu-shop-records.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXCV.
 */
static void store_native_shop_five_bit_selector_and_form_oam_coordinate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    RAM16_SET(0xA1D1 + x, a & 0x1F);
    r->a = ((a & 0x1F) << 1) + 0xA7;
    r->x = (uint8_t)(x + 1);
    r->c = ((a & 0x1F) << 1) + 0xA7 > 0xFFFF;
    r->v = ((((a & 0x1F) << 1) ^ ((a & 0x1F) << 1) + 0xA7) & (((a & 0x1F) << 1) + 0xA7 ^ 0xA7) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC760BA, SOM_RTS, "gen", store_native_shop_five_bit_selector_and_form_oam_coordinate, 0, L_A | L_B | L_X | L_C | L_V, 1, 0, 1, 13, 7)
