#include "som_c.h"

/* C76081 publish_three_native_shop_five_bit_icon_selectors   [class B, 57 bytes, 34 instructions]
 * Source: src/rom/publish_three_native_shop_five_bit_icon_selectors.s
 * Documented in docs/event-menu-shop-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void publish_three_native_shop_five_bit_icon_selectors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0xA23E + ((RAM16(0xA24E) & 0xFF) << 1));
    r->a = value2;
    r->x = 0;
    r->mf = 0;
    r->xf = 1;
    r->sp -= 2;
    JSR(c, 0x6095, 0xC760BA); /* store_native_shop_five_bit_selector_and_form_oam_coordinate */
    r->sp += 2;
    uint16_t a_all = r->a;
    RAM8(0x9C00) = (uint8_t)a_all;
    r->a = value2 >> 5;
    r->mf = 0;
    r->xf = 1;
    r->sp -= 2;
    JSR(c, 0x60A3, 0xC760BA); /* store_native_shop_five_bit_selector_and_form_oam_coordinate */
    r->sp += 2;
    uint16_t a_all2 = r->a;
    RAM8(0x9C04) = (uint8_t)a_all2;
    r->a = value2 >> 0x0A;
    r->mf = 0;
    r->xf = 1;
    JSR(c, 0x60B0, 0xC760BA); /* store_native_shop_five_bit_selector_and_form_oam_coordinate */
    uint16_t a_all3 = r->a;
    RAM8(0x9C08) = (uint8_t)a_all3;
    r->y = (uint8_t)a_all3;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76081, SOM_RTS, "gen", publish_three_native_shop_five_bit_icon_selectors, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 57, 34)
