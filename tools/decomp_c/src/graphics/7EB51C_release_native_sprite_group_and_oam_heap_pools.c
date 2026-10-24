#include "som_c.h"

/* 7EB51C release_native_sprite_group_and_oam_heap_pools   [class B, 33 bytes, 18 instructions]
 * Source: src/boot/release_native_sprite_group_and_oam_heap_pools.s
 * Documented in docs/boot-native-heap-release-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_native_sprite_group_and_oam_heap_pools(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x102C8);
    r->a = (a_hi << 8) | 0x7F;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB52C, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB52C); } /* release_native_heap_suffix_through_bank_7f_api */
    r->sp += 4;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x02CA);
        r->x = value2;
        r->y = (uint8_t)y;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB532, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB532); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 4;
        uint8_t db_ret2 = r->db;
        bool x_ret3 = r->xf;
        if (x_ret3) {
            uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x02CC);
            r->x = value3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->xf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB538, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB538); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 4;
            uint8_t value4 = RAM8(0x0000 + sp0 - 3);
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            r->c = value5 & 0x01;
            r->z = ((value7 << 8) | value6) == 0;
            r->n = ((value7 << 8) | value6) & 0x8000;
            r->v = value5 & 0x40;
            r->mf = value5 & 0x20;
            r->xf = value5 & 0x10;
            r->db = value4;
            r->dp = (value7 << 8) | value6;
            r->i = value5 & 0x04;
            r->d = value5 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value8 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x02CC);
            r->x = value8;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB538, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB538); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 4;
            uint8_t value9 = RAM8(0x0000 + sp0 - 3);
            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->c = value10 & 0x01;
            r->z = ((value12 << 8) | value11) == 0;
            r->n = ((value12 << 8) | value11) & 0x8000;
            r->v = value10 & 0x40;
            r->mf = value10 & 0x20;
            r->xf = value10 & 0x10;
            r->db = value9;
            r->dp = (value12 << 8) | value11;
            r->i = value10 & 0x04;
            r->d = value10 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CA);
        r->x = value13;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB532, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB532); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 4;
        uint8_t db_ret5 = r->db;
        bool x_ret9 = r->xf;
        if (x_ret9) {
            uint8_t value14 = BUS8_RDP(c, (db_ret5 << 0x10) + 0x02CC);
            r->x = value14;
            r->y = (uint8_t)y;
            r->z = value14 == 0;
            r->n = value14 & 0x80;
            r->xf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB538, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB538); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 4;
            uint8_t value15 = RAM8(0x0000 + sp0 - 3);
            uint8_t value16 = RAM8(0x0000 + sp0 - 2);
            uint8_t value17 = RAM8(0x0000 + sp0 - 1);
            uint8_t value18 = RAM8(0x0000 + sp0);
            r->c = value16 & 0x01;
            r->z = ((value18 << 8) | value17) == 0;
            r->n = ((value18 << 8) | value17) & 0x8000;
            r->v = value16 & 0x40;
            r->mf = value16 & 0x20;
            r->xf = value16 & 0x10;
            r->db = value15;
            r->dp = (value18 << 8) | value17;
            r->i = value16 & 0x04;
            r->d = value16 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value19 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x02CC);
            r->x = value19;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB538, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xB538); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 4;
            uint8_t value20 = RAM8(0x0000 + sp0 - 3);
            uint8_t value21 = RAM8(0x0000 + sp0 - 2);
            uint8_t value22 = RAM8(0x0000 + sp0 - 1);
            uint8_t value23 = RAM8(0x0000 + sp0);
            r->c = value21 & 0x01;
            r->z = ((value23 << 8) | value22) == 0;
            r->n = ((value23 << 8) | value22) & 0x8000;
            r->v = value21 & 0x40;
            r->mf = value21 & 0x20;
            r->xf = value21 & 0x10;
            r->db = value20;
            r->dp = (value23 << 8) | value22;
            r->i = value21 & 0x04;
            r->d = value21 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7EB51C, SOM_RTS, "gen", release_native_sprite_group_and_oam_heap_pools, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 33, 18)
