#include "som_c.h"

/* C20439 upload_boss_mode7_matrix_and_tile_rows   [class D, 136 bytes, 53 instructions]
 * Source: src/rom/upload_boss_mode7_matrix_and_tile_rows.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0200.  Callers read: ABYCV.
 */
static void upload_boss_mode7_matrix_and_tile_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x00211B, RAM8(0x02CD));
    BUS8_SET(c, 0x00211B, RAM8(0x02CE));
    BUS8_SET(c, 0x00211C, RAM8(0x02CF));
    BUS8_SET(c, 0x00211C, RAM8(0x02D0));
    BUS8_SET(c, 0x00211D, RAM8(0x02D1));
    BUS8_SET(c, 0x00211D, RAM8(0x02D2));
    BUS8_SET(c, 0x00211E, RAM8(0x02D3));
    BUS8_SET(c, 0x00211E, RAM8(0x02D4));
    BUS8_SET(c, 0x00211F, RAM8(0x02D5));
    BUS8_SET(c, 0x00211F, RAM8(0x02D6));
    BUS8_SET(c, 0x002120, RAM8(0x02D7));
    BUS8_SET(c, 0x002120, RAM8(0x02D8));
    BUS8_SET(c, 0x002115, 0);
    BUS8_SET(c, 0x004371, 0x18);
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint8_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        BUS16_SET(c, 0x004375, 0x20);
        RAM16_SET(0x0FAE, ((y1 << 8) | 0) >> 1);
        BUS16_SET(c, 0x002116, ((y1 << 8) | 0) >> 1);
        BUS8_SET(c, 0x004370, 0);
        BUS8_SET(c, 0x004374, 0x7F);
        uint16_t value13 = RAM16(0x0FAE);
        BUS16_SET(c, 0x004372, (uint16_t)((value13 >> 1) + 0xBC00));
        BUS8_SET(c, 0x00420B, 0x80);
        uint8_t a1_next = (uint8_t)((value13 >> 1) + 0xBC00);
        uint8_t a_hi1_next = (uint16_t)((value13 >> 1) + 0xBC00) >> 8;
        uint8_t y1_next = (uint8_t)(y1 + 1);
        bool carry1_next = (uint8_t)(y1 + 1) >= 0x10;
        bool overflow1_next = (((value13 >> 1) ^ (uint16_t)((value13 >> 1) + 0xBC00)) & ((uint16_t)((value13 >> 1) + 0xBC00) ^ 0xBC00) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 != 0x10)) break;
    }
    BUS8_SET(c, 0x002115, 0x80);
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20439, SOM_RTS, "gen", upload_boss_mode7_matrix_and_tile_rows, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 1, 136, 53)
