#include "som_c.h"

/* C0457C refresh_actor_appearance_native   [class C, 211 bytes, 90 instructions]
 * Source: src/rom/refresh_actor_appearance_native.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void refresh_actor_appearance_native(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4581, 0xC04518); GUARD_JSR(c, sp_call, 0x4581); } /* prepare_actor_appearance_context */
    r->sp += 4;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4584, 0xC047DD); GUARD_JSR(c, sp_call, 0x4584); } /* classify_actor_appearance_from_sprite */
    r->sp += 4;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FB + x_ret2);
    if ((value & 0x30) == 0) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FA + x_ret2);
        BUS8_SET(c, (db_ret << 0x10) + 0xE1FA + x_ret2, value2 | 4);
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FB + x_ret2);
        if ((value3 & 0x40) != 0) {
            r->a = (a_all2 >> 8 << 8) | value3;
            r->z = (value3 & 0x40) == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x45E8, 0xC047DD); GUARD_JSR(c, sp_call, 0x45E8); } /* classify_actor_appearance_from_sprite */
            r->sp += 4;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x45EB, 0xC0474F); GUARD_JSR(c, sp_call, 0x45EB); } /* load_actor_base_attributes_for_appearance */
            r->sp += 4;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x45EE, 0xC04860); GUARD_JSR(c, sp_call, 0x45EE); } /* prepare_actor_appearance_table_pointers */
            r->sp += 4;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x45F1, 0xC04BBE); GUARD_JSR(c, sp_call, 0x45F1); } /* reduce_and_clamp_actor_appearance_attributes */
            r->sp += 4;
            uint16_t x_ret5 = r->x;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x45F4, 0xC04A53); GUARD_JSR(c, sp_call, 0x45F4); } /* reorder_actor_attribute_bit_pairs */
            r->sp += 4;
            uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1AB + x_ret5);
            BUS8_SET(c, (db_ret << 0x10) + 0xE1AB + x_ret5, value4 | 0x12);
            uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1E3 + x_ret5);
            BUS8_SET(c, 0x004202, value5);
            BUS8_SET(c, 0x004203, 7);
            uint16_t value6 = BUS16(c, 0x004216);
            uint16_t value7 = BUS16(c, 0xD0BDC5 + value6);
            BUS16_SET(c, (db_ret << 0x10) + 0xE199 + x_ret5, value7);
            uint16_t value8 = BUS16(c, 0xD0BDC1 + value6);
            BUS16_SET(c, (db_ret << 0x10) + 0xE194 + x_ret5, value8);
            uint8_t value9 = BUS8(c, 0xD0BDC3 + value6);
            BUS8_SET(c, (db_ret << 0x10) + 0xE197 + x_ret5, value9);
            uint8_t value10 = BUS8(c, 0xD0BDC4 + value6);
            uint8_t value11 = BUS8_RDP(c, (db_ret << 0x10) + 0xE188 + x_ret5);
            BUS8_SET(c, (db_ret << 0x10) + 0xE198 + x_ret5, (uint8_t)(value10 + value11));
            uint8_t value12 = BUS8(c, 0xD0BDC7 + value6);
            BUS8_SET(c, (db_ret << 0x10) + 0xE1F7 + x_ret5, value12);
            uint8_t value13 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1C0 + x_ret5);
            BUS8_SET(c, (db_ret << 0x10) + 0xE19C + x_ret5, value13);
            BUS8_SET(c, (db_ret << 0x10) + 0xE19B + x_ret5, value13);
            r->a = (value8 >> 8 << 8) | value13;
            r->y = x_ret5;
            r->c = value10 + value11 > 0xFF;
            r->z = x_ret5 == 0;
            r->n = x_ret5 & 0x8000;
            r->v = ((value10 ^ (uint8_t)(value10 + value11)) & (value11 ^ (uint8_t)(value10 + value11)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x464A, 0xC04BF9); GUARD_JSR(c, sp_call, 0x464A); } /* cap_actor_appearance_word_and_byte_attributes */
            r->sp += 4;
            uint8_t value14 = RAM8(0x0000 + sp0 - 3);
            uint8_t value15 = RAM8(0x0000 + sp0 - 2);
            uint8_t value16 = RAM8(0x0000 + sp0 - 1);
            uint8_t value17 = RAM8(0x0000 + sp0);
            r->c = value14 & 0x01;
            r->z = ((value17 << 8) | value16) == 0;
            r->n = ((value17 << 8) | value16) & 0x8000;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->db = value15;
            r->dp = (value17 << 8) | value16;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        r->a = (a_all2 >> 8 << 8) | value3;
        r->z = (value3 & 0x40) == 0;
        r->n = value3 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45A0, 0xC048E6); GUARD_JSR(c, sp_call, 0x45A0); } /* read_appearance_level_and_party_charge */
        r->sp += 4;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45A3, 0xC0474F); GUARD_JSR(c, sp_call, 0x45A3); } /* load_actor_base_attributes_for_appearance */
        r->sp += 4;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45A6, 0xC04860); GUARD_JSR(c, sp_call, 0x45A6); } /* prepare_actor_appearance_table_pointers */
        r->sp += 4;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45A9, 0xC04AFF); GUARD_JSR(c, sp_call, 0x45A9); } /* apply_packed_appearance_attribute_adjustments */
        r->sp += 4;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45AC, 0xC04BBE); GUARD_JSR(c, sp_call, 0x45AC); } /* reduce_and_clamp_actor_appearance_attributes */
        r->sp += 4;
        uint16_t x_ret13 = r->x;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45AF, 0xC049AA); GUARD_JSR(c, sp_call, 0x45AF); } /* derive_actor_appearance_palette_attributes */
        r->sp += 4;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all14 = r->a;
        uint16_t y_ret7 = r->y;
        RAM8(0x0000 + sp0 - 4) = y_ret7 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)y_ret7;
        uint8_t value18 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 0xC2)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 0xC0)) + 0x1006, BUS8_RDP(c, (uint16_t)(dp_ret + 0xC2)));
        BUS8_SET(c, (db_ret << 0x10) + 0xE196 + x_ret13, value18);
        RAM8(0x0000 + sp0 - 4) = y_ret7 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)y_ret7;
        uint8_t value19 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 0xC2)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 0xC0)) + 0x100B, BUS8_RDP(c, (uint16_t)(dp_ret + 0xC2)));
        BUS8_SET(c, (db_ret << 0x10) + 0xE1F7 + x_ret13, value19);
        r->a = (a_all14 >> 8 << 8) | value19;
        r->z = y_ret7 == 0;
        r->n = y_ret7 & 0x8000;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45C6, 0xC04A53); GUARD_JSR(c, sp_call, 0x45C6); } /* reorder_actor_attribute_bit_pairs */
        r->sp += 4;
        uint16_t a_all15 = r->a;
        uint8_t value20 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1AB + x_ret13);
        BUS8_SET(c, (db_ret << 0x10) + 0xE1AB + x_ret13, value20 | 0x12);
        r->a = (a_all15 >> 8 << 8) | (value20 | 0x12);
        r->z = (value20 | 0x12) == 0;
        r->n = (value20 | 0x12) & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x45D1, 0xC04BF9); GUARD_JSR(c, sp_call, 0x45D1); } /* cap_actor_appearance_word_and_byte_attributes */
        r->sp += 4;
        uint8_t value21 = RAM8(0x0000 + sp0 - 3);
        uint8_t value22 = RAM8(0x0000 + sp0 - 2);
        uint8_t value23 = RAM8(0x0000 + sp0 - 1);
        uint8_t value24 = RAM8(0x0000 + sp0);
        r->c = value21 & 0x01;
        r->z = ((value24 << 8) | value23) == 0;
        r->n = ((value24 << 8) | value23) & 0x8000;
        r->v = value21 & 0x40;
        r->mf = value21 & 0x20;
        r->xf = value21 & 0x10;
        r->db = value22;
        r->dp = (value24 << 8) | value23;
        r->i = value21 & 0x04;
        r->d = value21 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    r->a = (a_all2 >> 8 << 8) | value;
    r->z = (value & 0x30) == 0;
    r->n = value & 0x80;
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL_FRAME(c, 0xC04576, SOM_RTL, 4); /* restore_actor_appearance_context_long */
}
SOM_REGISTER(0xC0457C, SOM_RTL, "gen", refresh_actor_appearance_native, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 211, 90)
