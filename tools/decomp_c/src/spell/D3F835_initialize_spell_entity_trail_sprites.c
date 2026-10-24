#include "som_c.h"

/* D3F835 initialize_spell_entity_trail_sprites   [class B, 141 bytes, 70 instructions]
 * Source: src/rom/initialize_spell_entity_trail_sprites.s
 * Documented in docs/actor-cast-entity-trail-init.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void initialize_spell_entity_trail_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0D) + 0xA > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_f882 = 0;
    uint8_t x_f882 = 0;
    uint16_t direct_page_f882 = 0;
    uint8_t data_bank_f882 = 0;
    uint8_t a_hi_f8822 = 0;
    uint16_t x_f8822 = 0;
    uint16_t direct_page_f8822 = 0;
    uint8_t data_bank_f8822 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0D) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7E;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0D), y);
    r->x = 0xFD4A;
    r->c = (uint16_t)(sp0 - 3) >= 0x0A;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0D);
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF851, 0xC12E90); GUARD_JSL(c, sp_call, 0xF851); } /* construct_spell_graphics_audio_resources_long */
    r->sp += 14;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0D)) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x0002 + (uint16_t)(sp0 - 0x0D));
        RAM16_SET(0x001A + value, (uint8_t)x_ret2);
        RAM16_SET(0x002A + value, 0);
        RAM16_SET(0x001C + value, 0x3711);
        RAM16_SET(0x001E + value, 0x345A);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0027 + value);
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0024 + value);
        RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0022 + value);
        RAM8(0x000A + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0020 + value);
        a_hi_f882 = 0x34;
        x_f882 = value;
        direct_page_f882 = (uint16_t)(sp0 - 0x0D);
        data_bank_f882 = 0x7E;
        goto shared_F882;
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0D), x_ret2);
        uint16_t value6 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0D));
        RAM16_SET(0x001A + value6, x_ret2);
        RAM16_SET(0x002A + value6, 0);
        RAM16_SET(0x001C + value6, 0x3711);
        RAM16_SET(0x001E + value6, 0x345A);
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0027 + value6);
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0024 + value6);
        RAM8(0x0009 + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0022 + value6);
        RAM8(0x000A + (uint16_t)(sp0 - 0x0D)) = RAM8(0x0020 + value6);
        a_hi_f8822 = 0x34;
        x_f8822 = value6;
        direct_page_f8822 = (uint16_t)(sp0 - 0x0D);
        data_bank_f8822 = 0x7E;
        goto shared_F882_1;
    }
    shared_F882:;
    RAM8(0x0004 + direct_page_f882) = x_f882;
    uint8_t value11 = RAM8(0x0006 + direct_page_f882);
    RAM8(0x0006 + direct_page_f882) = (uint8_t)(value11 + 0x40);
    uint8_t value12 = BUS8_RDP(c, (data_bank_f882 << 0x10) + x_f882);
    uint8_t value13 = RAM8(0x0007 + direct_page_f882);
    uint8_t value14 = RAM8(0x0009 + direct_page_f882);
    r->a = ((uint8_t)(value11 + 0x40) << 8) | value12;
    r->x = value13;
    r->y = value14;
    r->c = value11 + 0x40 > 0xFF;
    r->z = value14 == 0;
    r->n = value14 & 0x80;
    r->v = ((value11 ^ (uint8_t)(value11 + 0x40)) & ((uint8_t)(value11 + 0x40) ^ 0x40) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_f882;
    r->dp = direct_page_f882;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF895, 0xD3F8C2); GUARD_JSR(c, sp_call, 0xF895); } /* construct_spell_entity_trail_sprite_object */
    r->sp += 14;
    uint8_t db_ret = r->db;
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    if (x_ret3) {
        uint8_t value15 = RAM8(0x0004 + direct_page_f882);
        BUS16_SET(c, (db_ret << 0x10) + 2 + value15, (uint8_t)x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value15, 0x480B);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value15, 0x4806);
        RAM8(0x0001 + direct_page_f882)--;
        if (RAM8(0x0001 + direct_page_f882) != 0) {
            a_hi_f882 = value15 + 8 >> 8;
            x_f882 = (uint8_t)(value15 + 8);
            data_bank_f882 = db_ret;
            goto shared_F882;
        }
        uint8_t value16 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value17 = RAM8(0x0000 + sp0 - 2);
        uint8_t value18 = RAM8(0x0000 + sp0 - 1);
        uint8_t value19 = RAM8(0x0000 + sp0);
        r->mf = value17 & 0x20;
        r->xf = value17 & 0x10;
        r->db = value16;
        r->dp = (value19 << 8) | value18;
        r->i = value17 & 0x04;
        r->d = value17 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value20 = RAM16(0x0004 + direct_page_f882);
        BUS16_SET(c, (db_ret << 0x10) + 2 + value20, x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value20, 0x480B);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value20, 0x4806);
        RAM8(0x0001 + direct_page_f882)--;
        if (RAM8(0x0001 + direct_page_f882) != 0) {
            a_hi_f8822 = (uint16_t)(value20 + 8) >> 8;
            x_f8822 = (uint16_t)(value20 + 8);
            direct_page_f8822 = direct_page_f882;
            data_bank_f8822 = db_ret;
            goto shared_F882_1;
        }
        uint8_t value21 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value22 = RAM8(0x0000 + sp0 - 2);
        uint8_t value23 = RAM8(0x0000 + sp0 - 1);
        uint8_t value24 = RAM8(0x0000 + sp0);
        r->mf = value22 & 0x20;
        r->xf = value22 & 0x10;
        r->db = value21;
        r->dp = (value24 << 8) | value23;
        r->i = value22 & 0x04;
        r->d = value22 & 0x08;
        RETURN_RTS(c);
    }
    shared_F882_1:;
    RAM16_SET(0x0004 + direct_page_f8822, x_f8822);
    uint8_t value25 = RAM8(0x0006 + direct_page_f8822);
    RAM8(0x0006 + direct_page_f8822) = (uint8_t)(value25 + 0x40);
    uint8_t value26 = BUS8_RDP(c, (data_bank_f8822 << 0x10) + x_f8822);
    uint16_t value27 = RAM16(0x0007 + direct_page_f8822);
    uint16_t value28 = RAM16(0x0009 + direct_page_f8822);
    r->a = ((uint8_t)(value25 + 0x40) << 8) | value26;
    r->x = value27;
    r->y = value28;
    r->c = value25 + 0x40 > 0xFF;
    r->z = value28 == 0;
    r->n = value28 & 0x8000;
    r->v = ((value25 ^ (uint8_t)(value25 + 0x40)) & ((uint8_t)(value25 + 0x40) ^ 0x40) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f8822;
    r->dp = direct_page_f8822;
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF895, 0xD3F8C2); GUARD_JSR(c, sp_call, 0xF895); } /* construct_spell_entity_trail_sprite_object */
    r->sp += 14;
    uint8_t db_ret2 = r->db;
    bool x_ret5 = r->xf;
    uint16_t x_ret6 = r->x;
    if (x_ret5) {
        uint8_t value29 = RAM8(0x0004 + direct_page_f8822);
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value29, (uint8_t)x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value29, 0x480B);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value29, 0x4806);
        RAM8(0x0001 + direct_page_f8822)--;
        if (RAM8(0x0001 + direct_page_f8822) != 0) {
            a_hi_f882 = value29 + 8 >> 8;
            x_f882 = (uint8_t)(value29 + 8);
            direct_page_f882 = direct_page_f8822;
            data_bank_f882 = db_ret2;
            goto shared_F882;
        }
        uint8_t value30 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value31 = RAM8(0x0000 + sp0 - 2);
        uint8_t value32 = RAM8(0x0000 + sp0 - 1);
        uint8_t value33 = RAM8(0x0000 + sp0);
        r->mf = value31 & 0x20;
        r->xf = value31 & 0x10;
        r->db = value30;
        r->dp = (value33 << 8) | value32;
        r->i = value31 & 0x04;
        r->d = value31 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value34 = RAM16(0x0004 + direct_page_f8822);
        BUS16_SET(c, (db_ret2 << 0x10) + 2 + value34, x_ret6);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + value34, 0x480B);
        BUS16_SET(c, (db_ret2 << 0x10) + 6 + value34, 0x4806);
        RAM8(0x0001 + direct_page_f8822)--;
        if (RAM8(0x0001 + direct_page_f8822) != 0) {
            a_hi_f8822 = (uint16_t)(value34 + 8) >> 8;
            x_f8822 = (uint16_t)(value34 + 8);
            data_bank_f8822 = db_ret2;
            goto shared_F882_1;
        }
        uint8_t value35 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value36 = RAM8(0x0000 + sp0 - 2);
        uint8_t value37 = RAM8(0x0000 + sp0 - 1);
        uint8_t value38 = RAM8(0x0000 + sp0);
        r->mf = value36 & 0x20;
        r->xf = value36 & 0x10;
        r->db = value35;
        r->dp = (value38 << 8) | value37;
        r->i = value36 & 0x04;
        r->d = value36 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3F835, SOM_RTS, "gen", initialize_spell_entity_trail_sprites, 0, 0, 15, 1, 0, 141, 70)
