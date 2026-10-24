#include "som_c.h"

/* C1386F project_packed_spell_entity_sprite_record   [class B, 123 bytes, 67 instructions]
 * Source: src/rom/project_packed_spell_entity_sprite_record.s
 * Documented in docs/actor-cast-entity-projection.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void project_packed_spell_entity_sprite_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp + 2;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0xB > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0 - 2) = dp >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 5) = x >> 8;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = x >> 8;
    RAM8(0x0000 + sp0 - 9) = (uint8_t)x;
    uint16_t value = BUS16(c, 0xDCF800 + x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), value);
    uint16_t value2 = RAM16(0x0000 + y);
    uint8_t value3 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
    bool m_flag;
    bool x_flag;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value3 == 0xFF) {
        r->x = value2;
        r->c = value3 >= 0xFF;
        r->z = value3 == 0xFF;
        r->n = (uint8_t)(value3 - 0xFF) & 0x80;
        r->mf = 1;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x38E0, 0xC14090); GUARD_JSR(c, sp_call, 0x38E0); } /* hide_spell_entity_sprite_oam_entry */
        r->sp += 8;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        m_flag = m_ret;
        x_flag = x_ret;
        y1 = y;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        uint8_t a1;
        if ((((value >> 8 << 8) | value3) & 0x3F) < 0x30) {
            a1 = ((value >> 8 << 8) | value3) & 0x3F;
        } else {
            a1 = (((value >> 8 << 8) | value3) & 0x3F) + 0x10;
        }
        RAM16_SET(0x0006 + value2, a1 + 0x0100);
        RAM8(0x0000 + value2) = RAM8(0x0001 + (uint16_t)(sp0 - 7)) & 0xC0;
        uint8_t value5 = RAM8(0x0002 + (uint16_t)(sp0 - 7));
        uint16_t value6 = RAM16(0x000A + (uint16_t)(sp0 - 7));
        RAM16_SET(0x0002 + value2, (uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6));
        uint8_t value7 = RAM8(0x0002 + (uint16_t)(sp0 - 7));
        uint16_t value8 = RAM16(0x0008 + (uint16_t)(sp0 - 7));
        RAM16_SET(0x0004 + value2, (uint16_t)((uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) + value8));
        r->x = value2;
        r->c = (uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) + value8 > 0xFFFF;
        r->z = (uint16_t)((uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) + value8) == 0;
        r->n = (uint16_t)((uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) + value8) & 0x8000;
        r->v = (((uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) ^ (uint16_t)((uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) + value8)) & (value8 ^ (uint16_t)((uint16_t)(((((uint16_t)((uint16_t)((((a1 + 0x0100 >> 8 << 8) | (value5 >> 2)) & 0x3C) - 0x20) + value6) >> 8 << 8) | (uint8_t)(value7 << 2)) & 0x3C) - 0x20) + value8)) & 0x8000) != 0;
        r->mf = 1;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x38DB, 0xC14118); GUARD_JSR(c, sp_call, 0x38DB); } /* publish_spell_entity_individual_sprite_projection */
        r->sp += 8;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t y_ret = r->y;
        m_flag = m_ret2;
        x_flag = x_ret3;
        y1 = y_ret;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    if (x_flag) {
        uint8_t value9 = RAM8(0x0000 + sp0 - 9);
        uint8_t value10 = RAM8(0x0000 + sp0 - 8);
        if (m_flag) {
            c->fail = 3;
            return;
        } else {
            uint8_t value20 = RAM8(0x0000 + sp0 - 3);
            uint8_t value21 = RAM8(0x0000 + sp0 - 2);
            uint8_t value22 = RAM8(0x0000 + sp0 - 1);
            r->x = (uint8_t)(value9 + 2);
            r->y = (uint8_t)y1;
            r->mf = value20 & 0x20;
            r->xf = value20 & 0x10;
            r->db = value10;
            r->dp = (value22 << 8) | value21;
            r->i = value20 & 0x04;
            r->d = value20 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 1;
            RETURN_RTS(c);
        }
    } else {
        uint8_t value23 = RAM8(0x0000 + sp0 - 9);
        uint8_t value24 = RAM8(0x0000 + sp0 - 8);
        uint8_t value25 = RAM8(0x0000 + sp0 - 7);
        if (m_flag) {
            uint8_t value28 = RAM8(0x0000 + sp0 - 4);
            uint8_t value29 = RAM8(0x0000 + sp0 - 3);
            uint8_t value30 = RAM8(0x0000 + sp0 - 2);
            r->x = (uint16_t)(((value24 << 8) | value23) + 2);
            r->y = y1;
            r->mf = value28 & 0x20;
            r->xf = value28 & 0x10;
            r->db = value25;
            r->dp = (value30 << 8) | value29;
            r->i = value28 & 0x04;
            r->d = value28 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint8_t value35 = RAM8(0x0000 + sp0 - 2);
            uint8_t value36 = RAM8(0x0000 + sp0 - 1);
            uint8_t value37 = RAM8(0x0000 + sp0);
            r->x = (uint16_t)(((value24 << 8) | value23) + 2);
            r->y = y1;
            r->mf = value35 & 0x20;
            r->xf = value35 & 0x10;
            r->db = value25;
            r->dp = (value37 << 8) | value36;
            r->i = value35 & 0x04;
            r->d = value35 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            r->sp += 2;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC1386F, SOM_RTS, "gen", project_packed_spell_entity_sprite_record, SOM_UNWINDS, L_X | L_Y, 10, 0, 0, 123, 67)
