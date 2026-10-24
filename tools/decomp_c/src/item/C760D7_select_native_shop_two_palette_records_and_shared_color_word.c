#include "som_c.h"

/* C760D7 select_native_shop_two_palette_records_and_shared_color_word   [class B, 47 bytes, 24 instructions]
 * Source: src/rom/select_native_shop_two_palette_records_and_shared_color_word.s
 * Documented in docs/event-menu-shop-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_native_shop_two_palette_records_and_shared_color_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA24E);
    uint8_t value2 = BUS8(c, 0xC77159 + value);
    r->a = value2;
    r->y = 0;
    r->sp -= 2;
    JSR(c, 0x60E8, 0xC76106); /* copy_six_native_shop_palette_record_bytes */
    r->sp += 2;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t value3 = BUS8(c, 0xC77161 + value);
    r->a = (a_all >> 8 << 8) | value3;
    r->y = (uint16_t)(y_ret + 2);
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x60F3, 0xC76106); /* copy_six_native_shop_palette_record_bytes */
    r->sp += 2;
    uint16_t value4 = RAM16(0xA23E + (value << 1));
    RAM16_SET(0xA1B0, value4);
    RAM16_SET(0xA22D, value4);
    r->a = (r->a & 0x00FF) | ((value4 >> 8) << 8);
    r->x = value << 1;
    r->c = value & 0x8000;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC760D7, SOM_RTS, "gen", select_native_shop_two_palette_records_and_shared_color_word, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 47, 24)
