#include "som_c.h"

/* C203D1 upload_boss_sixteen_tile_rows   [class D, 104 bytes, 48 instructions]
 * Source: src/rom/upload_boss_sixteen_tile_rows.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0200.  Callers read: ABYCV.
 */
static void upload_boss_sixteen_tile_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x004371, 0x18);
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint8_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        BUS16_SET(c, 0x004375, 0x40);
        RAM16_SET(0x0FAE, y1 << 1 << 1 << 1 << 1 << 1);
        BUS16_SET(c, 0x002116, (y1 << 1 << 1 << 1 << 1 << 1) + 0x3800);
        uint16_t value = RAM16(0x0FBC);
        uint8_t a_hi3;
        if ((uint16_t)(value + 0x10) & 0x8000) {
            BUS8_SET(c, 0x004370, 1);
            BUS8_SET(c, 0x004374, 0xC2);
            BUS16_SET(c, 0x004372, 0x04C1);
            a_hi3 = 4;
        } else {
            uint8_t a_hi2;
            if (!((uint16_t)((uint16_t)(value + 0x10) - 0x0100) & 0x8000)) {
                BUS8_SET(c, 0x004370, 1);
                BUS8_SET(c, 0x004374, 0xC2);
                BUS16_SET(c, 0x004372, 0x04C1);
                a_hi2 = 4;
            } else {
                BUS8_SET(c, 0x004370, 1);
                BUS8_SET(c, 0x004374, 0x7F);
                uint16_t value2 = RAM16(0x0FAE);
                BUS16_SET(c, 0x004372, (uint16_t)((uint16_t)(value2 << 1) + 0xBC00));
                a_hi2 = (uint16_t)((uint16_t)(value2 << 1) + 0xBC00) >> 8;
            }
            a_hi3 = a_hi2;
        }
        BUS8_SET(c, 0x00420B, 0x80);
        RAM16_SET(0x0FBC, (uint16_t)(value + 8));
        uint8_t a1_next = (uint8_t)(value + 8);
        uint8_t a_hi1_next = (uint16_t)(value + 8) >> 8;
        uint8_t y1_next = (uint8_t)(y1 + 1);
        bool carry1_next = (uint8_t)(y1 + 1) >= 0x10;
        bool overflow1_next = ((value ^ (uint16_t)(value + 8)) & ((uint16_t)(value + 8) ^ 8) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 != 0x10)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC203D1, SOM_RTS, "gen", upload_boss_sixteen_tile_rows, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 1, 104, 48)
