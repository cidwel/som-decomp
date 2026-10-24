#include "som_c.h"

/* D3F9B8 project_spell_entity_trail_sprite_frames   [class B, 101 bytes, 53 instructions]
 * Source: src/rom/project_spell_entity_trail_sprite_frames.s
 * Documented in docs/actor-cast-entity-trail-objects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void project_spell_entity_trail_sprite_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), 0x14);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    bool carry1 = (uint16_t)(sp0 - 3) >= 6;
    bool overflow1 = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 9);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + 8 + x1);
        BUS16_RMW_SET(c, (data_bank << 0x10) + 8 + x1, (uint16_t)(value - 1));
        if ((uint16_t)(value - 1) != 0) {
            RAM16_SET(0x0001 + direct_page, (uint16_t)(RAM16(0x0001 + direct_page) - 1));
            if (RAM16(0x0001 + direct_page) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x10);
                bool carry1_next = x1 + 0x10 > 0xFFFF;
                bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi1_next2 = (uint16_t)(x1 + 0x10) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 0x10);
            bool carry1_next2 = x1 + 0x10 > 0xFFFF;
            bool overflow1_next2 = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            carry1 = carry1_next2;
            overflow1 = overflow1_next2;
            break;
        }
        RAM16_SET(0x0005 + direct_page, (uint16_t)(RAM16(0x0005 + direct_page) + 1));
        uint16_t value2 = BUS16_RDP(c, (data_bank << 0x10) + 6 + x1);
        uint16_t value3 = BUS16_RDP(c, (data_bank << 0x10) + 2 + x1);
        RAM8(0x0000 + sp0 - 9) = value3 >> 8;
        RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value3;
        uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + 4 + x1);
        RAM8(0x0000 + sp0 - 0x0B) = value4 >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)value4;
        RAM16_SET(0x0003 + direct_page, x1);
        r->a = value4;
        r->x = value2;
        r->y = x1;
        r->c = carry1;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->v = overflow1;
        r->mf = false;
        r->xf = false;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 13;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF9E2, 0xC12E94); GUARD_JSL(c, sp_call, 0xF9E2); } /* project_packed_spell_entity_sprite_record_long */
        r->sp += 13;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint16_t value5 = RAM16(0x0003 + dp_ret);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value5, x_ret);
        uint16_t value10 = BUS16_RDP(c, (db_ret << 0x10) + 0x0C + value5);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0x0C + value5, (uint16_t)(value10 - 1));
        if ((uint16_t)(value10 - 1) == 0) {
            RAM16_SET(0x0001 + dp_ret, (uint16_t)(RAM16(0x0001 + dp_ret) - 1));
            if (RAM16(0x0001 + dp_ret) != 0) {
                a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
                x1 = (uint16_t)(value5 + 0x10);
                carry1 = value5 + 0x10 > 0xFFFF;
                overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
                data_bank = db_ret;
                direct_page = dp_ret;
                continue;
            }
            a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
            x1 = (uint16_t)(value5 + 0x10);
            carry1 = value5 + 0x10 > 0xFFFF;
            overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
            break;
        }
        BUS16_SET(c, (db_ret << 0x10) + 8 + value5, 1);
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0x0C + value5);
        if (value11 != 3) {
            RAM16_SET(0x0001 + dp_ret, (uint16_t)(RAM16(0x0001 + dp_ret) - 1));
            if (RAM16(0x0001 + dp_ret) != 0) {
                a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
                x1 = (uint16_t)(value5 + 0x10);
                carry1 = value5 + 0x10 > 0xFFFF;
                overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
                data_bank = db_ret;
                direct_page = dp_ret;
                continue;
            }
            a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
            x1 = (uint16_t)(value5 + 0x10);
            carry1 = value5 + 0x10 > 0xFFFF;
            overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
            break;
        }
        BUS16_SET(c, (db_ret << 0x10) + 8 + value5, 0x20);
        RAM16_SET(0x0001 + dp_ret, (uint16_t)(RAM16(0x0001 + dp_ret) - 1));
        if (RAM16(0x0001 + dp_ret) != 0) {
            a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
            x1 = (uint16_t)(value5 + 0x10);
            carry1 = value5 + 0x10 > 0xFFFF;
            overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
            continue;
        }
        a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
        x1 = (uint16_t)(value5 + 0x10);
        carry1 = value5 + 0x10 > 0xFFFF;
        overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        break;
    }
    RAM16_SET(0x0000 + sp0 - 4, RAM16(0x0005 + direct_page));
    uint8_t value15 = RAM8(0x0000 + sp0 - 2);
    uint8_t value16 = RAM8(0x0000 + sp0 - 1);
    uint8_t value17 = RAM8(0x0000 + sp0);
    r->mf = value15 & 0x20;
    r->xf = value15 & 0x10;
    r->db = data_bank;
    r->dp = (value17 << 8) | value16;
    r->i = value15 & 0x04;
    r->d = value15 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F9B8, SOM_RTS, "hand", project_spell_entity_trail_sprite_frames, 0, 0, 13, 1, 0, 101, 53)
