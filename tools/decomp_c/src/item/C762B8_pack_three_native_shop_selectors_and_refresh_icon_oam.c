#include "som_c.h"

/* C762B8 pack_three_native_shop_selectors_and_refresh_icon_oam   [class B, 69 bytes, 29 instructions]
 * Source: src/rom/pack_three_native_shop_selectors_and_refresh_icon_oam.s
 * Documented in docs/event-menu-shop-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void pack_three_native_shop_selectors_and_refresh_icon_oam(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA24E);
    RAM16_SET(0xA23E + (uint8_t)(value << 1), 0);
    RAM16_SET(0xA173, 3);
    uint8_t a_hi1 = 0;
    uint16_t y1 = 0;
    do {
        RAM16_SET(0xA1CE, 5);
        uint8_t a1 = RAM16(0xA1D1 + y1) & 0x1F;
        uint8_t a_hi2 = 0;
        do {
            RAM16_SET(0xA23E + (uint8_t)(value << 1), (RAM16(0xA23E + (uint8_t)(value << 1)) >> 1) | ((((a_hi2 << 8) | a1) & 1) << 0x0F));
            RAM16_SET(0xA1CE, (uint16_t)(RAM16(0xA1CE) - 1));
            uint8_t a1_next = (uint8_t)(((a_hi2 << 8) | a1) >> 1);
            uint8_t a_hi2_next = ((a_hi2 << 8) | a1) >> 9;
            a1 = a1_next;
            a_hi2 = a_hi2_next;
        } while (RAM16(0xA1CE) != 0);
        RAM16_SET(0xA173, (uint16_t)(RAM16(0xA173) - 1));
        a_hi1 = a_hi2;
        y1 = (uint16_t)(y1 + 1);
    } while (RAM16(0xA173) != 0);
    RAM16_SET(0xA23E + (uint8_t)(value << 1), RAM16(0xA23E + (uint8_t)(value << 1)) >> 1);
    RAM16_SET(0xA22D, RAM16(0xA23E + (uint8_t)(value << 1)));
    r->v = overflow;
    JSR(c, 0x62F6, 0xC76081); /* publish_three_native_shop_five_bit_icon_selectors */
    RAM8(0xA20A) |= 4;
    SET_A8(r, 4);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC762B8, SOM_RTS, "gen", pack_three_native_shop_selectors_and_refresh_icon_oam, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 69, 29)
