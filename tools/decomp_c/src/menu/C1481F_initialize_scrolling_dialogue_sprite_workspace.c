#include "som_c.h"

/* C1481F initialize_scrolling_dialogue_sprite_workspace   [class B, 41 bytes, 22 instructions]
 * Source: src/rom/initialize_scrolling_dialogue_sprite_workspace.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: B.
 */
static void initialize_scrolling_dialogue_sprite_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    r->a = 0x0238;
    r->x = 0x0238;
    r->c = 1;
    r->z = 0;
    r->n = 0;
    r->v = 0;
    r->mf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4836, 0xC13BD3); GUARD_JSR(c, sp_call, 0x4836); } /* initialize_spell_entity_heap */
    r->sp += 4;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    r->a = 0x0F03;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x483C, 0xC13D8F); GUARD_JSR(c, sp_call, 0x483C); } /* initialize_spell_entity_oam_workspace */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4840, 0xD3F4F1); GUARD_JSL(c, sp_call, 0x4840); } /* construct_scrolling_dialogue_sprite_list */
    r->sp += 4;
    bool x_ret5 = r->xf;
    uint16_t x_ret6 = r->x;
    if (x_ret5) {
        BUS8_SET(c, (db_ret << 0x10) + 0x8436, (uint8_t)x_ret6);
        uint8_t value = RAM8(0x0000 + sp0 - 3);
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->db = value;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0x8436, x_ret6);
        uint8_t value5 = RAM8(0x0000 + sp0 - 3);
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->db = value5;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC1481F, SOM_RTS, "gen", initialize_scrolling_dialogue_sprite_workspace, 0, L_B, 5, 1, 0, 41, 22)
