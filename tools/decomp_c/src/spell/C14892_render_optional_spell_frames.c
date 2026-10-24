#include "som_c.h"

/* C14892 render_optional_spell_frames   [class B, 71 bytes, 34 instructions]
 * Source: src/rom/render_optional_spell_frames.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void render_optional_spell_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    uint16_t value = RAM16(0xCFF7);
    if ((value & 0x0F) == 0) {
        r->a = value & 0x0F;
        r->z = dp == 0;
        r->n = dp & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value2 = BUS16(c, 0xDCFE8A + (uint16_t)((uint16_t)((value & 0x0F) - 1) << 1));
    uint16_t value3 = RAM16(0x8436);
    RAM16_SET(0x010E + value3, value2);
    uint16_t value4 = RAM16(0x010C + value3);
    if (value2 < value4) {
        RAM16_SET(0x010C + value3, value2);
    }
    r->a = value2;
    r->x = value3;
    r->c = value2 >= value4;
    r->z = value2 == value4;
    r->n = (uint16_t)(value2 - value4) & 0x8000;
    r->db = 0x7E;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x48C3, 0xC14848); GUARD_JSR(c, sp_call, 0x48C3); } /* clear_spell_frame_oam_workspace */
    r->sp += 4;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0x8436);
        r->x = value5;
        r->y = (uint8_t)y_ret;
        r->z = value5 == 0;
        r->n = value5 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x48CA, 0xD3F79F); GUARD_JSL(c, sp_call, 0x48CA); } /* expand_and_render_spell_frame_group */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint8_t value6 = RAM8(0x00EC);
        RAM8(0x00EC) = value6 | 8;
        uint8_t value7 = RAM8(0x0000 + sp0 - 3);
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        uint8_t value9 = RAM8(0x0000 + sp0 - 1);
        uint8_t value10 = RAM8(0x0000 + sp0);
        r->a = (a_all2 >> 8 << 8) | (value6 | 8);
        r->c = value8 & 0x01;
        r->z = ((value10 << 8) | value9) == 0;
        r->n = ((value10 << 8) | value9) & 0x8000;
        r->v = value8 & 0x40;
        r->mf = value8 & 0x20;
        r->xf = value8 & 0x10;
        r->db = value7;
        r->dp = (value10 << 8) | value9;
        r->i = value8 & 0x04;
        r->d = value8 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0x8436);
        r->x = value11;
        r->z = value11 == 0;
        r->n = value11 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x48CA, 0xD3F79F); GUARD_JSL(c, sp_call, 0x48CA); } /* expand_and_render_spell_frame_group */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        uint8_t value12 = RAM8(0x00EC);
        RAM8(0x00EC) = value12 | 8;
        uint8_t value13 = RAM8(0x0000 + sp0 - 3);
        uint8_t value14 = RAM8(0x0000 + sp0 - 2);
        uint8_t value15 = RAM8(0x0000 + sp0 - 1);
        uint8_t value16 = RAM8(0x0000 + sp0);
        r->a = (a_all3 >> 8 << 8) | (value12 | 8);
        r->c = value14 & 0x01;
        r->z = ((value16 << 8) | value15) == 0;
        r->n = ((value16 << 8) | value15) & 0x8000;
        r->v = value14 & 0x40;
        r->mf = value14 & 0x20;
        r->xf = value14 & 0x10;
        r->db = value13;
        r->dp = (value16 << 8) | value15;
        r->i = value14 & 0x04;
        r->d = value14 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC14892, SOM_RTS, "gen", render_optional_spell_frames, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 71, 34)
