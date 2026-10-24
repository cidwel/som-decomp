#include "som_c.h"

/* 7EC826 release_registered_vram_buffer   [class B, 50 bytes, 29 instructions]
 * Source: src/boot/release_registered_vram_buffer.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: BYCV.
 */
static void release_registered_vram_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0500) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0x7F;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC838, 0x7EC73B); GUARD_JSR(c, sp_call, 0xC838); } /* find_registered_vram_buffer */
    r->sp += 6;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x10002 + (uint8_t)x_ret2);
        if (m_ret) {
            RAM8(0x10002 + (uint8_t)x_ret2) = 0;
            r->x = value;
            r->y = value;
            r->z = value == 0;
            r->n = value & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC844, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xC844); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 6;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret2 = r->mf;
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            if (x_ret3) {
                uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                if (m_ret2) {
                    uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + value2);
                    BUS8_SET(c, (db_ret << 0x10) + value2, 0);
                    r->a = (a_all2 >> 8 << 8) | value3;
                    r->x = value2;
                    r->z = value3 == 0;
                    r->n = value3 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value4 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value9 = RAM8(0x0000 + sp0);
                    r->c = value7 & 0x01;
                    r->v = value7 & 0x40;
                    r->mf = value7 & 0x20;
                    r->xf = value7 & 0x10;
                    r->db = value4;
                    r->dp = (value9 << 8) | value8;
                    r->i = value7 & 0x04;
                    r->d = value7 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value10 = BUS16_RDP(c, (db_ret << 0x10) + value2);
                    BUS16_SET(c, (db_ret << 0x10) + value2, 0);
                    r->a = value10;
                    r->x = value2;
                    r->z = value10 == 0;
                    r->n = value10 & 0x8000;
                    r->mf = 0;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value11 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value16 = RAM8(0x0000 + sp0);
                    r->c = value14 & 0x01;
                    r->v = value14 & 0x40;
                    r->mf = value14 & 0x20;
                    r->xf = value14 & 0x10;
                    r->db = value11;
                    r->dp = (value16 << 8) | value15;
                    r->i = value14 & 0x04;
                    r->d = value14 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                if (m_ret2) {
                    uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + value17);
                    BUS8_SET(c, (db_ret << 0x10) + value17, 0);
                    r->a = (a_all2 >> 8 << 8) | value18;
                    r->x = value17;
                    r->z = value18 == 0;
                    r->n = value18 & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value19 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value22 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value23 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value24 = RAM8(0x0000 + sp0);
                    r->c = value22 & 0x01;
                    r->v = value22 & 0x40;
                    r->mf = value22 & 0x20;
                    r->xf = value22 & 0x10;
                    r->db = value19;
                    r->dp = (value24 << 8) | value23;
                    r->i = value22 & 0x04;
                    r->d = value22 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + value17);
                    BUS16_SET(c, (db_ret << 0x10) + value17, 0);
                    r->a = value25;
                    r->x = value17;
                    r->z = value25 == 0;
                    r->n = value25 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value26 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value29 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value30 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value31 = RAM8(0x0000 + sp0);
                    r->c = value29 & 0x01;
                    r->v = value29 & 0x40;
                    r->mf = value29 & 0x20;
                    r->xf = value29 & 0x10;
                    r->db = value26;
                    r->dp = (value31 << 8) | value30;
                    r->i = value29 & 0x04;
                    r->d = value29 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        } else {
            RAM16_SET(0x10002 + (uint8_t)x_ret2, 0);
            r->x = value;
            r->y = value;
            r->z = value == 0;
            r->n = value & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC844, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xC844); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 6;
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            bool m_ret7 = r->mf;
            bool x_ret13 = r->xf;
            uint16_t a_all7 = r->a;
            if (x_ret13) {
                uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 1));
                if (m_ret7) {
                    uint8_t value33 = BUS8_RDP(c, (db_ret6 << 0x10) + value32);
                    BUS8_SET(c, (db_ret6 << 0x10) + value32, 0);
                    r->a = (a_all7 >> 8 << 8) | value33;
                    r->x = value32;
                    r->z = value33 == 0;
                    r->n = value33 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value34 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value37 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value38 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value39 = RAM8(0x0000 + sp0);
                    r->c = value37 & 0x01;
                    r->v = value37 & 0x40;
                    r->mf = value37 & 0x20;
                    r->xf = value37 & 0x10;
                    r->db = value34;
                    r->dp = (value39 << 8) | value38;
                    r->i = value37 & 0x04;
                    r->d = value37 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value40 = BUS16_RDP(c, (db_ret6 << 0x10) + value32);
                    BUS16_SET(c, (db_ret6 << 0x10) + value32, 0);
                    r->a = value40;
                    r->x = value32;
                    r->z = value40 == 0;
                    r->n = value40 & 0x8000;
                    r->mf = 0;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value41 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value44 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value45 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value46 = RAM8(0x0000 + sp0);
                    r->c = value44 & 0x01;
                    r->v = value44 & 0x40;
                    r->mf = value44 & 0x20;
                    r->xf = value44 & 0x10;
                    r->db = value41;
                    r->dp = (value46 << 8) | value45;
                    r->i = value44 & 0x04;
                    r->d = value44 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 1));
                if (m_ret7) {
                    uint8_t value48 = BUS8_RDP(c, (db_ret6 << 0x10) + value47);
                    BUS8_SET(c, (db_ret6 << 0x10) + value47, 0);
                    r->a = (a_all7 >> 8 << 8) | value48;
                    r->x = value47;
                    r->z = value48 == 0;
                    r->n = value48 & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value49 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value52 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value53 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value54 = RAM8(0x0000 + sp0);
                    r->c = value52 & 0x01;
                    r->v = value52 & 0x40;
                    r->mf = value52 & 0x20;
                    r->xf = value52 & 0x10;
                    r->db = value49;
                    r->dp = (value54 << 8) | value53;
                    r->i = value52 & 0x04;
                    r->d = value52 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value55 = BUS16_RDP(c, (db_ret6 << 0x10) + value47);
                    BUS16_SET(c, (db_ret6 << 0x10) + value47, 0);
                    r->a = value55;
                    r->x = value47;
                    r->z = value55 == 0;
                    r->n = value55 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value56 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value59 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value60 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value61 = RAM8(0x0000 + sp0);
                    r->c = value59 & 0x01;
                    r->v = value59 & 0x40;
                    r->mf = value59 & 0x20;
                    r->xf = value59 & 0x10;
                    r->db = value56;
                    r->dp = (value61 << 8) | value60;
                    r->i = value59 & 0x04;
                    r->d = value59 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        }
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x_ret2);
        uint16_t value62 = BUS16(c, 0x7F0002 + x_ret2);
        if (m_ret) {
            BUS8_SET(c, 0x7F0002 + x_ret2, 0);
            r->x = value62;
            r->y = value62;
            r->z = value62 == 0;
            r->n = value62 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC844, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xC844); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 6;
            uint16_t dp_ret11 = r->dp;
            uint8_t db_ret11 = r->db;
            bool m_ret12 = r->mf;
            bool x_ret23 = r->xf;
            uint16_t a_all12 = r->a;
            if (x_ret23) {
                uint8_t value63 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 1));
                if (m_ret12) {
                    uint8_t value64 = BUS8_RDP(c, (db_ret11 << 0x10) + value63);
                    BUS8_SET(c, (db_ret11 << 0x10) + value63, 0);
                    r->a = (a_all12 >> 8 << 8) | value64;
                    r->x = value63;
                    r->y = (uint8_t)value62;
                    r->z = value64 == 0;
                    r->n = value64 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value65 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value68 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value69 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value70 = RAM8(0x0000 + sp0);
                    r->c = value68 & 0x01;
                    r->v = value68 & 0x40;
                    r->mf = value68 & 0x20;
                    r->xf = value68 & 0x10;
                    r->db = value65;
                    r->dp = (value70 << 8) | value69;
                    r->i = value68 & 0x04;
                    r->d = value68 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value71 = BUS16_RDP(c, (db_ret11 << 0x10) + value63);
                    BUS16_SET(c, (db_ret11 << 0x10) + value63, 0);
                    r->a = value71;
                    r->x = value63;
                    r->y = (uint8_t)value62;
                    r->z = value71 == 0;
                    r->n = value71 & 0x8000;
                    r->mf = 0;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value72 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value75 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value76 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value77 = RAM8(0x0000 + sp0);
                    r->c = value75 & 0x01;
                    r->v = value75 & 0x40;
                    r->mf = value75 & 0x20;
                    r->xf = value75 & 0x10;
                    r->db = value72;
                    r->dp = (value77 << 8) | value76;
                    r->i = value75 & 0x04;
                    r->d = value75 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value78 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 1));
                if (m_ret12) {
                    uint8_t value79 = BUS8_RDP(c, (db_ret11 << 0x10) + value78);
                    BUS8_SET(c, (db_ret11 << 0x10) + value78, 0);
                    r->a = (a_all12 >> 8 << 8) | value79;
                    r->x = value78;
                    r->z = value79 == 0;
                    r->n = value79 & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value80 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value83 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value84 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value85 = RAM8(0x0000 + sp0);
                    r->c = value83 & 0x01;
                    r->v = value83 & 0x40;
                    r->mf = value83 & 0x20;
                    r->xf = value83 & 0x10;
                    r->db = value80;
                    r->dp = (value85 << 8) | value84;
                    r->i = value83 & 0x04;
                    r->d = value83 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value86 = BUS16_RDP(c, (db_ret11 << 0x10) + value78);
                    BUS16_SET(c, (db_ret11 << 0x10) + value78, 0);
                    r->a = value86;
                    r->x = value78;
                    r->z = value86 == 0;
                    r->n = value86 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value87 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value90 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value91 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value92 = RAM8(0x0000 + sp0);
                    r->c = value90 & 0x01;
                    r->v = value90 & 0x40;
                    r->mf = value90 & 0x20;
                    r->xf = value90 & 0x10;
                    r->db = value87;
                    r->dp = (value92 << 8) | value91;
                    r->i = value90 & 0x04;
                    r->d = value90 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        } else {
            BUS16_SET(c, 0x7F0002 + x_ret2, 0);
            r->x = value62;
            r->y = value62;
            r->z = value62 == 0;
            r->n = value62 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC844, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xC844); } /* release_native_heap_suffix_through_bank_7f_api */
            r->sp += 6;
            uint16_t dp_ret16 = r->dp;
            uint8_t db_ret16 = r->db;
            bool m_ret17 = r->mf;
            bool x_ret33 = r->xf;
            uint16_t a_all17 = r->a;
            if (x_ret33) {
                uint8_t value93 = BUS8_RDP(c, (uint16_t)(dp_ret16 + 1));
                if (m_ret17) {
                    uint8_t value94 = BUS8_RDP(c, (db_ret16 << 0x10) + value93);
                    BUS8_SET(c, (db_ret16 << 0x10) + value93, 0);
                    r->a = (a_all17 >> 8 << 8) | value94;
                    r->x = value93;
                    r->y = (uint8_t)value62;
                    r->z = value94 == 0;
                    r->n = value94 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value95 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value98 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value99 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value100 = RAM8(0x0000 + sp0);
                    r->c = value98 & 0x01;
                    r->v = value98 & 0x40;
                    r->mf = value98 & 0x20;
                    r->xf = value98 & 0x10;
                    r->db = value95;
                    r->dp = (value100 << 8) | value99;
                    r->i = value98 & 0x04;
                    r->d = value98 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value101 = BUS16_RDP(c, (db_ret16 << 0x10) + value93);
                    BUS16_SET(c, (db_ret16 << 0x10) + value93, 0);
                    r->a = value101;
                    r->x = value93;
                    r->y = (uint8_t)value62;
                    r->z = value101 == 0;
                    r->n = value101 & 0x8000;
                    r->mf = 0;
                    r->xf = 1;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value102 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value105 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value106 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value107 = RAM8(0x0000 + sp0);
                    r->c = value105 & 0x01;
                    r->v = value105 & 0x40;
                    r->mf = value105 & 0x20;
                    r->xf = value105 & 0x10;
                    r->db = value102;
                    r->dp = (value107 << 8) | value106;
                    r->i = value105 & 0x04;
                    r->d = value105 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                uint16_t value108 = BUS16_RDP(c, (uint16_t)(dp_ret16 + 1));
                if (m_ret17) {
                    uint8_t value109 = BUS8_RDP(c, (db_ret16 << 0x10) + value108);
                    BUS8_SET(c, (db_ret16 << 0x10) + value108, 0);
                    r->a = (a_all17 >> 8 << 8) | value109;
                    r->x = value108;
                    r->z = value109 == 0;
                    r->n = value109 & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value110 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value113 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value114 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value115 = RAM8(0x0000 + sp0);
                    r->c = value113 & 0x01;
                    r->v = value113 & 0x40;
                    r->mf = value113 & 0x20;
                    r->xf = value113 & 0x10;
                    r->db = value110;
                    r->dp = (value115 << 8) | value114;
                    r->i = value113 & 0x04;
                    r->d = value113 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value116 = BUS16_RDP(c, (db_ret16 << 0x10) + value108);
                    BUS16_SET(c, (db_ret16 << 0x10) + value108, 0);
                    r->a = value116;
                    r->x = value108;
                    r->z = value116 == 0;
                    r->n = value116 & 0x8000;
                    r->mf = 0;
                    r->xf = 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xC84F, 0x7ED678); GUARD_JSR(c, sp_call, 0xC84F); } /* release_matching_vram_tag */
                    r->sp += 6;
                    uint8_t value117 = RAM8(0x0000 + sp0 - 5);
                    uint8_t value120 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value121 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value122 = RAM8(0x0000 + sp0);
                    r->c = value120 & 0x01;
                    r->v = value120 & 0x40;
                    r->mf = value120 & 0x20;
                    r->xf = value120 & 0x10;
                    r->db = value117;
                    r->dp = (value122 << 8) | value121;
                    r->i = value120 & 0x04;
                    r->d = value120 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        }
    }
}
SOM_REGISTER(0x7EC826, SOM_RTS, "gen", release_registered_vram_buffer, 0, L_B | L_Y | L_C | L_V, 7, 1, 0, 50, 29)
