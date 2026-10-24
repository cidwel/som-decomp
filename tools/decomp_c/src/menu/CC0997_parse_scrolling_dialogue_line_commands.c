#include "som_c.h"

/* CC0997 parse_scrolling_dialogue_line_commands   [class C, 54 bytes, 23 instructions]
 * Source: src/rom/parse_scrolling_dialogue_line_commands.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void parse_scrolling_dialogue_line_commands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0999, 0xCC0B4E); GUARD_JSR(c, sp_call, 0x0999); } /* clear_scrolling_dialogue_ring_line */
    uint16_t a_all = r->a;
    uint16_t value = RAM16(0xA18F);
    RAM16_SET(0xA19B, value);
    uint16_t value2 = RAM16(0xA173);
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = value;
    uint16_t y1 = value2;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + 0x9000 + y1);
        uint8_t a1;
        if (value3 >= 0x7C) {
            a1 = (uint8_t)(value3 - 0x7C);
        } else {
            a1 = 4;
        }
        r->a = (uint8_t)(a1 << 1);
        r->x = (uint8_t)(a1 << 1);
        r->y = y1;
        r->c = a1 & 0x80;
        r->z = (uint8_t)(a1 << 1) == 0;
        r->n = (uint8_t)(a1 << 1) & 0x8000;
        r->v = ((value3 ^ 0x7C) & (value3 ^ (uint8_t)(value3 - 0x7C)) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp;
        switch ((uint8_t)(a1 << 1)) {
        case 0x0000: JSR(c, 0x09B4, 0xCC09CD); GUARD_JSR(c, sp_call, 0x09B4); break; /* set_scrolling_dialogue_line_indentation */
        case 0x0002: JSR(c, 0x09B4, 0xCC09E2); GUARD_JSR(c, sp_call, 0x09B4); break; /* reset_scrolling_dialogue_line_delay */
        case 0x0004: JSR(c, 0x09B4, 0xCC09E8); GUARD_JSR(c, sp_call, 0x09B4); break; /* begin_scrolling_dialogue_end_sequence */
        case 0x0006: JSR(c, 0x09B4, 0xCC09F4); GUARD_JSR(c, sp_call, 0x09B4); break; /* advance_scrolling_dialogue_line */
        case 0x0008: JSR(c, 0x09B4, 0xCC09FA); GUARD_JSR(c, sp_call, 0x09B4); break; /* write_scrolling_dialogue_character_tile */
        default: JSR(c, 0x09B4, 0xCC0000 | BUS16(c, 0xCC0000 + (uint16_t)(0x0B6F + ((uint8_t)(a1 << 1))))); GUARD_JSR(c, sp_call, 0x09B4);
        }
        }
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        if (x_ret2 != 0) { c->fail = 3; return; }
        a_hi1 = a_all2 >> 8;
        x1 = x_ret3;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!(!carry1)) break;
    }
    BUS16_SET(c, (data_bank << 0x10) + 0xA173, y1);
    BUS8_SET(c, (data_bank << 0x10) + 0xA20C, 3);
    uint8_t value4 = RAM8(0x1D04);
    RAM8(0x1D04) = value4 | 0x44;
    uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + 0xA161);
    BUS8_SET(c, (data_bank << 0x10) + 0xA161, (uint8_t)(value5 + 1));
    r->a = (a_hi1 << 8) | (value4 | 0x44);
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = (uint8_t)(value5 + 1) == 0;
    r->n = (uint8_t)(value5 + 1) & 0x80;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC0997, SOM_RTS, "gen", parse_scrolling_dialogue_line_commands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 54, 23)
