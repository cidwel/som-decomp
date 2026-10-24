#include "som_c.h"

/* C76C58 publish_native_skill_count_and_selector_rows   [class B, 58 bytes, 28 instructions]
 * Source: src/rom/publish_native_skill_count_and_selector_rows.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void publish_native_skill_count_and_selector_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6C5A, 0xC76C92); GUARD_JSR(c, sp_call, 0x6C5A); } /* select_native_current_hero_weapon_skill_index */
    r->x = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6C60, 0xC76679); GUARD_JSR(c, sp_call, 0x6C60); } /* read_packed_native_weapon_skill_nibble_and_publish_glyph */
    uint8_t db_ret = r->db;
    bool x_ret2 = r->xf;
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x9C00);
    BUS16_SET(c, (db_ret << 0x10) + 0xA200, (uint16_t)((uint16_t)(value - 0xB5) + 1) & 0xFF);
    BUS16_SET(c, (db_ret << 0x10) + 0xA175, (uint16_t)((uint16_t)(value - 0xB5) + 1) & 0xFF);
    if (x_ret2) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        uint8_t a1 = 0x80;
        uint8_t a_hi1 = 0x21;
        uint16_t x1 = 0x01BA;
        bool carry1 = value >= 0xB5;
        bool zero1 = 0;
        bool overflow1 = ((value ^ 0xB5) & (value ^ (uint16_t)(value - 0xB5)) & 0x8000) != 0;
        for (;;) {
            BUS16_SET(c, (db_ret << 0x10) + 0x9000 + x1, (a_hi1 << 8) | a1);
            BUS16_SET(c, (db_ret << 0x10) + 0x9040 + x1, (uint16_t)(((a_hi1 << 8) | a1) + 2));
            RAM8(0x0000 + sp0) = (uint16_t)(((a_hi1 << 8) | a1) + 2) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(((a_hi1 << 8) | a1) + 2);
            uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0xA175);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA175, (uint16_t)(value2 - 1));
            uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 4);
            uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 0x80);
            bool carry1_next = x1 + 0x80 > 0xFFFF;
            bool zero1_next = (uint16_t)(value2 - 1) == 0;
            bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x80)) & ((uint16_t)(x1 + 0x80) ^ 0x80) & 0x8000) != 0;
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            carry1 = carry1_next;
            zero1 = zero1_next;
            overflow1 = overflow1_next;
            if (!((uint16_t)(value2 - 1) != 0)) break;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y;
        r->c = carry1;
        r->z = zero1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC76C58, SOM_RTS, "gen", publish_native_skill_count_and_selector_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 58, 28)
