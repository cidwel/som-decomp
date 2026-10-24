#include "som_c.h"

/* C76106 copy_six_native_shop_palette_record_bytes   [class A, 31 bytes, 18 instructions]
 * Source: src/rom/copy_six_native_shop_palette_record_bytes.s
 * Documented in docs/event-menu-shop-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void copy_six_native_shop_palette_record_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM16_SET(0xA173, (uint16_t)(((a_hi << 8) | a) << 1));
    uint16_t value = RAM16(0xA173);
    uint8_t a1 = 6;
    uint8_t a_hi1 = (uint16_t)((uint16_t)(((a_hi << 8) | a) << 2) + value) >> 8;
    uint16_t x1 = (uint16_t)((uint16_t)(((a_hi << 8) | a) << 2) + value);
    uint16_t y1 = y;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xD2DB80 + x1);
        RAM8(0xA1A6 + y1) = value2;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value2;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->v = (((uint16_t)(((a_hi << 8) | a) << 2) ^ (uint16_t)((uint16_t)(((a_hi << 8) | a) << 2) + value)) & (value ^ (uint16_t)((uint16_t)(((a_hi << 8) | a) << 2) + value)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76106, SOM_RTS, "gen", copy_six_native_shop_palette_record_bytes, 0, L_B | L_Y | L_V, 1, 1, 0, 31, 18)
