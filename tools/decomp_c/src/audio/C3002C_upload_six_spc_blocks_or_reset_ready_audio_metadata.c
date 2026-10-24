#include "som_c.h"
/* SOM_POLL_HOOK */

/* C3002C upload_six_spc_blocks_or_reset_ready_audio_metadata   [class D, 1395 bytes, 688 instructions]
 * Source: src/rom/upload_six_spc_blocks_or_reset_ready_audio_metadata.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void upload_six_spc_blocks_or_reset_ready_audio_metadata(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x7F;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = a >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 6) = x >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 8) = y >> 8;
    RAM8(0x0000 + sp0 - 9) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 0x0A) = 0;
    RAM8(0x0000 + sp0 - 0x0A) = 0x1E;
    RAM8(0x0000 + sp0 - 0x0B) = 0;
    uint16_t y1 = 0x0800;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint16_t value = BUS16(c, 0x002140);
        if (value == 0xBBAA) {
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value2 = BUS16(c, 0x002140);
                if (!(value2 != 0xBBAA)) break;
            }
            uint8_t value3 = BUS8(c, 0xC30014);
            BUS8_SET(c, 0x002142, value3);
            uint8_t value4 = BUS8(c, 0xC30015);
            BUS8_SET(c, 0x002143, value4);
            BUS8_SET(c, 0x002141, 0xCC);
            BUS8_SET(c, 0x002140, 0xCC);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value5 = BUS8(c, 0x002140);
                if (!(value5 != 0xCC)) break;
            }
            uint8_t a1 = 0xCC;
            uint8_t a_hi1 = a >> 8;
            uint16_t x1 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value6 = BUS8(c, 0xC30008 + x1);
                RAM8(0x1E14) = value6;
                uint8_t value7 = BUS8(c, 0xC30009 + x1);
                RAM8(0x1E15) = value7;
                RAM8(0x1E16) = 0xC3;
                uint8_t value8 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14), RAM8(0x1E16));
                RAM8(0x1E10) = (uint8_t)(value8 + 2);
                uint8_t value9 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + 1, RAM8(0x1E16));
                RAM8(0x1E11) = (uint8_t)(value9 + (value8 + 2 > 0xFF));
                uint8_t a2 = (uint8_t)(value9 + (value8 + 2 > 0xFF));
                uint8_t a_hi2 = 0;
                uint16_t y2 = 2;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value10 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y2, RAM8(0x1E16));
                    BUS8_SET(c, 0x002141, value10);
                    BUS8_SET(c, 0x002140, a_hi2);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value11 = BUS8(c, 0x002140);
                        if (!(a_hi2 != value11)) break;
                    }
                    uint16_t value12 = RAM16(0x1E10);
                    a2 = value10;
                    a_hi2 = (uint8_t)(a_hi2 + 1);
                    y2 = (uint16_t)(y2 + 1);
                    if (!(y2 != value12)) break;
                }
                uint8_t a3;
                if ((uint8_t)(a_hi2 + 3) != 0) {
                    a3 = (uint8_t)(a_hi2 + 3);
                } else {
                    a3 = (uint8_t)(a_hi2 + 4);
                }
                if ((uint16_t)(x1 + 2) != 0x0C) {
                    uint8_t value13 = BUS8(c, 0xC30014 + (uint16_t)(x1 + 2));
                    BUS8_SET(c, 0x002142, value13);
                    uint8_t value14 = BUS8(c, 0xC30015 + (uint16_t)(x1 + 2));
                    BUS8_SET(c, 0x002143, value14);
                    BUS8_SET(c, 0x002141, a3);
                    BUS8_SET(c, 0x002140, a3);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value15 = BUS8(c, 0x002140);
                        if (!(a3 != value15)) break;
                    }
                    a1 = a3;
                    a_hi1 = value14;
                    x1 = (uint16_t)(x1 + 2);
                    continue;
                }
                a1 = a3;
                a_hi1 = a2;
                x1 = (uint16_t)(x1 + 2);
                break;
            }
            BUS16_SET(c, 0x002142, 0x0200);
            BUS8_SET(c, 0x002141, 0);
            BUS8_SET(c, 0x002140, a1);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value16 = BUS8(c, 0x002140);
                if (!(a1 != value16)) break;
            }
            BUS8_SET(c, 0x002140, 0);
            uint16_t x2 = 0x0100;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS8_SET(c, 0x001DFF + x2, 0);
                x2 = (uint16_t)(x2 - 1);
                if (!(x2 != 0)) break;
            }
            RAM8(0x1E05) = 0xFF;
            uint16_t value17 = BUS16(c, 0xC31AE2);
            RAM16_SET(0x1EF8, (uint16_t)(value17 + 0x4800));
            RAM16_SET(0x1E48, (uint16_t)(value17 + 0x4800));
            uint16_t x3 = 0x0800;
            for (;;) {
                LOOP_GUARD(loop_guard);
                x3 = (uint16_t)(x3 - 1);
                if (!(x3 != 0)) break;
            }
            RAM8(0x1EFA) = 0;
            RAM8(0x1EFB) = 0xC3;
            RAM8(0x1EF0) = 2;
            uint8_t a4;
            if (1) {
                a4 = 2;
            } else {
                a4 = 3;
            }
            RAM8(0x1EF2) = (uint8_t)(((uint8_t)(a4 << 3) ^ 0xFF) + 0xFB);
            RAM8(0x1EF1) = 0;
            uint8_t value18 = RAM8(0x0000 + sp0 - 9);
            uint8_t value19 = RAM8(0x0000 + sp0 - 8);
            uint8_t value20 = RAM8(0x0000 + sp0 - 7);
            uint8_t value21 = RAM8(0x0000 + sp0 - 6);
            uint8_t value22 = RAM8(0x0000 + sp0 - 5);
            uint8_t value23 = RAM8(0x0000 + sp0 - 4);
            uint8_t value24 = RAM8(0x0000 + sp0 - 3);
            uint8_t value25 = RAM8(0x0000 + sp0 - 2);
            uint8_t value26 = RAM8(0x0000 + sp0 - 1);
            uint8_t value27 = RAM8(0x0000 + sp0);
            r->a = (value23 << 8) | value22;
            r->x = (value21 << 8) | value20;
            r->y = (value19 << 8) | value18;
            r->c = value24 & 0x01;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->v = value24 & 0x40;
            r->mf = value24 & 0x20;
            r->xf = value24 & 0x10;
            r->db = value27;
            r->dp = (value26 << 8) | value25;
            r->i = value24 & 0x04;
            r->d = value24 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        if ((uint16_t)(y1 - 1) != 0) {
            y1 = (uint16_t)(y1 - 1);
            continue;
        }
        uint16_t value28 = RAM16(0x1EF8);
        if (value28 == 0) {
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value29 = BUS16(c, 0x002140);
                if (!(value29 != 0xBBAA)) break;
            }
            uint8_t value30 = BUS8(c, 0xC30014);
            BUS8_SET(c, 0x002142, value30);
            uint8_t value31 = BUS8(c, 0xC30015);
            BUS8_SET(c, 0x002143, value31);
            BUS8_SET(c, 0x002141, 0xCC);
            BUS8_SET(c, 0x002140, 0xCC);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value32 = BUS8(c, 0x002140);
                if (!(value32 != 0xCC)) break;
            }
            uint8_t a5 = 0xCC;
            uint8_t a_hi3 = a >> 8;
            uint16_t x4 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value33 = BUS8(c, 0xC30008 + x4);
                RAM8(0x1E14) = value33;
                uint8_t value34 = BUS8(c, 0xC30009 + x4);
                RAM8(0x1E15) = value34;
                RAM8(0x1E16) = 0xC3;
                uint8_t value35 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14), RAM8(0x1E16));
                RAM8(0x1E10) = (uint8_t)(value35 + 2);
                uint8_t value36 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + 1, RAM8(0x1E16));
                RAM8(0x1E11) = (uint8_t)(value36 + (value35 + 2 > 0xFF));
                uint8_t a6 = (uint8_t)(value36 + (value35 + 2 > 0xFF));
                uint8_t a_hi4 = 0;
                uint16_t y3 = 2;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value37 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y3, RAM8(0x1E16));
                    BUS8_SET(c, 0x002141, value37);
                    BUS8_SET(c, 0x002140, a_hi4);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value38 = BUS8(c, 0x002140);
                        if (!(a_hi4 != value38)) break;
                    }
                    uint16_t value39 = RAM16(0x1E10);
                    a6 = value37;
                    a_hi4 = (uint8_t)(a_hi4 + 1);
                    y3 = (uint16_t)(y3 + 1);
                    if (!(y3 != value39)) break;
                }
                uint8_t a7;
                if ((uint8_t)(a_hi4 + 3) != 0) {
                    a7 = (uint8_t)(a_hi4 + 3);
                } else {
                    a7 = (uint8_t)(a_hi4 + 4);
                }
                if ((uint16_t)(x4 + 2) != 0x0C) {
                    uint8_t value40 = BUS8(c, 0xC30014 + (uint16_t)(x4 + 2));
                    BUS8_SET(c, 0x002142, value40);
                    uint8_t value41 = BUS8(c, 0xC30015 + (uint16_t)(x4 + 2));
                    BUS8_SET(c, 0x002143, value41);
                    BUS8_SET(c, 0x002141, a7);
                    BUS8_SET(c, 0x002140, a7);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value42 = BUS8(c, 0x002140);
                        if (!(a7 != value42)) break;
                    }
                    a5 = a7;
                    a_hi3 = value41;
                    x4 = (uint16_t)(x4 + 2);
                    continue;
                }
                a5 = a7;
                a_hi3 = a6;
                x4 = (uint16_t)(x4 + 2);
                break;
            }
            BUS16_SET(c, 0x002142, 0x0200);
            BUS8_SET(c, 0x002141, 0);
            BUS8_SET(c, 0x002140, a5);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value43 = BUS8(c, 0x002140);
                if (!(a5 != value43)) break;
            }
            BUS8_SET(c, 0x002140, 0);
            uint16_t x5 = 0x0100;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS8_SET(c, 0x001DFF + x5, 0);
                x5 = (uint16_t)(x5 - 1);
                if (!(x5 != 0)) break;
            }
            RAM8(0x1E05) = 0xFF;
            uint16_t value44 = BUS16(c, 0xC31AE2);
            RAM16_SET(0x1EF8, (uint16_t)(value44 + 0x4800));
            RAM16_SET(0x1E48, (uint16_t)(value44 + 0x4800));
            uint16_t x6 = 0x0800;
            for (;;) {
                LOOP_GUARD(loop_guard);
                x6 = (uint16_t)(x6 - 1);
                if (!(x6 != 0)) break;
            }
            RAM8(0x1EFA) = 0;
            RAM8(0x1EFB) = 0xC3;
            RAM8(0x1EF0) = 2;
            uint8_t a8;
            if (1) {
                a8 = 2;
            } else {
                a8 = 3;
            }
            RAM8(0x1EF2) = (uint8_t)(((uint8_t)(a8 << 3) ^ 0xFF) + 0xFB);
            RAM8(0x1EF1) = 0;
            uint8_t value45 = RAM8(0x0000 + sp0 - 9);
            uint8_t value46 = RAM8(0x0000 + sp0 - 8);
            uint8_t value47 = RAM8(0x0000 + sp0 - 7);
            uint8_t value48 = RAM8(0x0000 + sp0 - 6);
            uint8_t value49 = RAM8(0x0000 + sp0 - 5);
            uint8_t value50 = RAM8(0x0000 + sp0 - 4);
            uint8_t value51 = RAM8(0x0000 + sp0 - 3);
            uint8_t value52 = RAM8(0x0000 + sp0 - 2);
            uint8_t value53 = RAM8(0x0000 + sp0 - 1);
            uint8_t value54 = RAM8(0x0000 + sp0);
            r->a = (value50 << 8) | value49;
            r->x = (value48 << 8) | value47;
            r->y = (value46 << 8) | value45;
            r->c = value51 & 0x01;
            r->z = value54 == 0;
            r->n = value54 & 0x80;
            r->v = value51 & 0x40;
            r->mf = value51 & 0x20;
            r->xf = value51 & 0x10;
            r->db = value54;
            r->dp = (value53 << 8) | value52;
            r->i = value51 & 0x04;
            r->d = value51 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        if (value28 != RAM16(0x1E48)) {
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value56 = BUS16(c, 0x002140);
                if (!(value56 != 0xBBAA)) break;
            }
            uint8_t value57 = BUS8(c, 0xC30014);
            BUS8_SET(c, 0x002142, value57);
            uint8_t value58 = BUS8(c, 0xC30015);
            BUS8_SET(c, 0x002143, value58);
            BUS8_SET(c, 0x002141, 0xCC);
            BUS8_SET(c, 0x002140, 0xCC);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value59 = BUS8(c, 0x002140);
                if (!(value59 != 0xCC)) break;
            }
            uint8_t a9 = 0xCC;
            uint8_t a_hi5 = a >> 8;
            uint16_t x7 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value60 = BUS8(c, 0xC30008 + x7);
                RAM8(0x1E14) = value60;
                uint8_t value61 = BUS8(c, 0xC30009 + x7);
                RAM8(0x1E15) = value61;
                RAM8(0x1E16) = 0xC3;
                uint8_t value62 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14), RAM8(0x1E16));
                RAM8(0x1E10) = (uint8_t)(value62 + 2);
                uint8_t value63 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + 1, RAM8(0x1E16));
                RAM8(0x1E11) = (uint8_t)(value63 + (value62 + 2 > 0xFF));
                uint8_t a10 = (uint8_t)(value63 + (value62 + 2 > 0xFF));
                uint8_t a_hi6 = 0;
                uint16_t y4 = 2;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value64 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y4, RAM8(0x1E16));
                    BUS8_SET(c, 0x002141, value64);
                    BUS8_SET(c, 0x002140, a_hi6);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value65 = BUS8(c, 0x002140);
                        if (!(a_hi6 != value65)) break;
                    }
                    uint16_t value66 = RAM16(0x1E10);
                    a10 = value64;
                    a_hi6 = (uint8_t)(a_hi6 + 1);
                    y4 = (uint16_t)(y4 + 1);
                    if (!(y4 != value66)) break;
                }
                uint8_t a11;
                if ((uint8_t)(a_hi6 + 3) != 0) {
                    a11 = (uint8_t)(a_hi6 + 3);
                } else {
                    a11 = (uint8_t)(a_hi6 + 4);
                }
                if ((uint16_t)(x7 + 2) != 0x0C) {
                    uint8_t value67 = BUS8(c, 0xC30014 + (uint16_t)(x7 + 2));
                    BUS8_SET(c, 0x002142, value67);
                    uint8_t value68 = BUS8(c, 0xC30015 + (uint16_t)(x7 + 2));
                    BUS8_SET(c, 0x002143, value68);
                    BUS8_SET(c, 0x002141, a11);
                    BUS8_SET(c, 0x002140, a11);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value69 = BUS8(c, 0x002140);
                        if (!(a11 != value69)) break;
                    }
                    a9 = a11;
                    a_hi5 = value68;
                    x7 = (uint16_t)(x7 + 2);
                    continue;
                }
                a9 = a11;
                a_hi5 = a10;
                x7 = (uint16_t)(x7 + 2);
                break;
            }
            BUS16_SET(c, 0x002142, 0x0200);
            BUS8_SET(c, 0x002141, 0);
            BUS8_SET(c, 0x002140, a9);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value70 = BUS8(c, 0x002140);
                if (!(a9 != value70)) break;
            }
            BUS8_SET(c, 0x002140, 0);
            uint16_t x8 = 0x0100;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS8_SET(c, 0x001DFF + x8, 0);
                x8 = (uint16_t)(x8 - 1);
                if (!(x8 != 0)) break;
            }
            RAM8(0x1E05) = 0xFF;
            uint16_t value71 = BUS16(c, 0xC31AE2);
            RAM16_SET(0x1EF8, (uint16_t)(value71 + 0x4800));
            RAM16_SET(0x1E48, (uint16_t)(value71 + 0x4800));
            uint16_t x9 = 0x0800;
            for (;;) {
                LOOP_GUARD(loop_guard);
                x9 = (uint16_t)(x9 - 1);
                if (!(x9 != 0)) break;
            }
            RAM8(0x1EFA) = 0;
            RAM8(0x1EFB) = 0xC3;
            RAM8(0x1EF0) = 2;
            uint8_t a12;
            if (1) {
                a12 = 2;
            } else {
                a12 = 3;
            }
            RAM8(0x1EF2) = (uint8_t)(((uint8_t)(a12 << 3) ^ 0xFF) + 0xFB);
            RAM8(0x1EF1) = 0;
            uint8_t value72 = RAM8(0x0000 + sp0 - 9);
            uint8_t value73 = RAM8(0x0000 + sp0 - 8);
            uint8_t value74 = RAM8(0x0000 + sp0 - 7);
            uint8_t value75 = RAM8(0x0000 + sp0 - 6);
            uint8_t value76 = RAM8(0x0000 + sp0 - 5);
            uint8_t value77 = RAM8(0x0000 + sp0 - 4);
            uint8_t value78 = RAM8(0x0000 + sp0 - 3);
            uint8_t value79 = RAM8(0x0000 + sp0 - 2);
            uint8_t value80 = RAM8(0x0000 + sp0 - 1);
            uint8_t value81 = RAM8(0x0000 + sp0);
            r->a = (value77 << 8) | value76;
            r->x = (value75 << 8) | value74;
            r->y = (value73 << 8) | value72;
            r->c = value78 & 0x01;
            r->z = value81 == 0;
            r->n = value81 & 0x80;
            r->v = value78 & 0x40;
            r->mf = value78 & 0x20;
            r->xf = value78 & 0x10;
            r->db = value81;
            r->dp = (value80 << 8) | value79;
            r->i = value78 & 0x04;
            r->d = value78 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        uint8_t value82 = RAM8(0x1E00);
        if (value82 != 0xF0) {
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value83 = BUS16(c, 0x002140);
                if (!(value83 != 0xBBAA)) break;
            }
            uint8_t value84 = BUS8(c, 0xC30014);
            BUS8_SET(c, 0x002142, value84);
            uint8_t value85 = BUS8(c, 0xC30015);
            BUS8_SET(c, 0x002143, value85);
            BUS8_SET(c, 0x002141, 0xCC);
            BUS8_SET(c, 0x002140, 0xCC);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value86 = BUS8(c, 0x002140);
                if (!(value86 != 0xCC)) break;
            }
            uint8_t a13 = 0xCC;
            uint8_t a_hi7 = a >> 8;
            uint16_t x10 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value87 = BUS8(c, 0xC30008 + x10);
                RAM8(0x1E14) = value87;
                uint8_t value88 = BUS8(c, 0xC30009 + x10);
                RAM8(0x1E15) = value88;
                RAM8(0x1E16) = 0xC3;
                uint8_t value89 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14), RAM8(0x1E16));
                RAM8(0x1E10) = (uint8_t)(value89 + 2);
                uint8_t value90 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + 1, RAM8(0x1E16));
                RAM8(0x1E11) = (uint8_t)(value90 + (value89 + 2 > 0xFF));
                uint8_t a14 = (uint8_t)(value90 + (value89 + 2 > 0xFF));
                uint8_t a_hi8 = 0;
                uint16_t y5 = 2;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value91 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y5, RAM8(0x1E16));
                    BUS8_SET(c, 0x002141, value91);
                    BUS8_SET(c, 0x002140, a_hi8);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value92 = BUS8(c, 0x002140);
                        if (!(a_hi8 != value92)) break;
                    }
                    uint16_t value93 = RAM16(0x1E10);
                    a14 = value91;
                    a_hi8 = (uint8_t)(a_hi8 + 1);
                    y5 = (uint16_t)(y5 + 1);
                    if (!(y5 != value93)) break;
                }
                uint8_t a15;
                if ((uint8_t)(a_hi8 + 3) != 0) {
                    a15 = (uint8_t)(a_hi8 + 3);
                } else {
                    a15 = (uint8_t)(a_hi8 + 4);
                }
                if ((uint16_t)(x10 + 2) != 0x0C) {
                    uint8_t value94 = BUS8(c, 0xC30014 + (uint16_t)(x10 + 2));
                    BUS8_SET(c, 0x002142, value94);
                    uint8_t value95 = BUS8(c, 0xC30015 + (uint16_t)(x10 + 2));
                    BUS8_SET(c, 0x002143, value95);
                    BUS8_SET(c, 0x002141, a15);
                    BUS8_SET(c, 0x002140, a15);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value96 = BUS8(c, 0x002140);
                        if (!(a15 != value96)) break;
                    }
                    a13 = a15;
                    a_hi7 = value95;
                    x10 = (uint16_t)(x10 + 2);
                    continue;
                }
                a13 = a15;
                a_hi7 = a14;
                x10 = (uint16_t)(x10 + 2);
                break;
            }
            BUS16_SET(c, 0x002142, 0x0200);
            BUS8_SET(c, 0x002141, 0);
            BUS8_SET(c, 0x002140, a13);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value97 = BUS8(c, 0x002140);
                if (!(a13 != value97)) break;
            }
            BUS8_SET(c, 0x002140, 0);
            uint16_t x11 = 0x0100;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS8_SET(c, 0x001DFF + x11, 0);
                x11 = (uint16_t)(x11 - 1);
                if (!(x11 != 0)) break;
            }
            RAM8(0x1E05) = 0xFF;
            uint16_t value98 = BUS16(c, 0xC31AE2);
            RAM16_SET(0x1EF8, (uint16_t)(value98 + 0x4800));
            RAM16_SET(0x1E48, (uint16_t)(value98 + 0x4800));
            uint16_t x12 = 0x0800;
            for (;;) {
                LOOP_GUARD(loop_guard);
                x12 = (uint16_t)(x12 - 1);
                if (!(x12 != 0)) break;
            }
            RAM8(0x1EFA) = 0;
            RAM8(0x1EFB) = 0xC3;
            RAM8(0x1EF0) = 2;
            uint8_t a16;
            if (1) {
                a16 = 2;
            } else {
                a16 = 3;
            }
            RAM8(0x1EF2) = (uint8_t)(((uint8_t)(a16 << 3) ^ 0xFF) + 0xFB);
            RAM8(0x1EF1) = 0;
            uint8_t value99 = RAM8(0x0000 + sp0 - 9);
            uint8_t value100 = RAM8(0x0000 + sp0 - 8);
            uint8_t value101 = RAM8(0x0000 + sp0 - 7);
            uint8_t value102 = RAM8(0x0000 + sp0 - 6);
            uint8_t value103 = RAM8(0x0000 + sp0 - 5);
            uint8_t value104 = RAM8(0x0000 + sp0 - 4);
            uint8_t value105 = RAM8(0x0000 + sp0 - 3);
            uint8_t value106 = RAM8(0x0000 + sp0 - 2);
            uint8_t value107 = RAM8(0x0000 + sp0 - 1);
            uint8_t value108 = RAM8(0x0000 + sp0);
            r->a = (value104 << 8) | value103;
            r->x = (value102 << 8) | value101;
            r->y = (value100 << 8) | value99;
            r->c = value105 & 0x01;
            r->z = value108 == 0;
            r->n = value108 & 0x80;
            r->v = value105 & 0x40;
            r->mf = value105 & 0x20;
            r->xf = value105 & 0x10;
            r->db = value108;
            r->dp = (value107 << 8) | value106;
            r->i = value105 & 0x04;
            r->d = value105 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        BUS8_SET(c, 0x002141, 8);
        BUS8_SET(c, 0x002140, 0);
        uint16_t x13 = 0xF0;
        for (;;) {
            LOOP_GUARD(loop_guard);
            BUS8_SET(c, 0x001DFF + x13, 0);
            x13 = (uint16_t)(x13 - 1);
            if (!(x13 != 0)) break;
        }
        uint16_t value109 = RAM16(0x1EF8);
        RAM16_SET(0x1E48, value109);
        RAM8(0x1E05) = 0xFF;
        RAM8(0x1E00) = 0xF0;
        uint8_t a_hi9 = a >> 8;
        uint16_t x14 = x13;
        for (;;) {
            LOOP_GUARD(loop_guard);
            break;
        }
        uint8_t value110 = RAM8(0x1E00);
        RAM8(0x1E00) = 0;
        if (value110 == 0) {
            uint8_t value111 = RAM8(0x0000 + sp0 - 9);
            uint8_t value112 = RAM8(0x0000 + sp0 - 8);
            uint8_t value113 = RAM8(0x0000 + sp0 - 7);
            uint8_t value114 = RAM8(0x0000 + sp0 - 6);
            uint8_t value115 = RAM8(0x0000 + sp0 - 5);
            uint8_t value116 = RAM8(0x0000 + sp0 - 4);
            uint8_t value117 = RAM8(0x0000 + sp0 - 3);
            uint8_t value118 = RAM8(0x0000 + sp0 - 2);
            uint8_t value119 = RAM8(0x0000 + sp0 - 1);
            uint8_t value120 = RAM8(0x0000 + sp0);
            r->a = (value116 << 8) | value115;
            r->x = (value114 << 8) | value113;
            r->y = (value112 << 8) | value111;
            r->c = value117 & 0x01;
            r->z = value120 == 0;
            r->n = value120 & 0x80;
            r->v = value117 & 0x40;
            r->mf = value117 & 0x20;
            r->xf = value117 & 0x10;
            r->db = value120;
            r->dp = (value119 << 8) | value118;
            r->i = value117 & 0x04;
            r->d = value117 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        if (value110 & 0x80) {
            r->a = (a_hi9 << 8) | value110;
            r->x = x14;
            r->y = value109;
            r->c = value82 <= 0xF0;
            r->z = value110 == 0;
            r->n = value110 & 0x80;
            r->v = overflow;
            r->mf = 1;
            r->db = 0;
            r->dp = 0x1E00;
            TAIL_CALL_FRAME(c, 0xC3059F, SOM_RTL, 10); /* send_non_music_audio_command_packet */
        }
        if (value110 == 1) {
            uint8_t value121 = RAM8(0x1E02);
            RAM8(0x0000 + sp0 - 0x0A) = value121 & 0x0F;
            uint8_t value122 = RAM8(0x1E01);
            RAM8(0x0000 + sp0 - 0x0B) = value122;
            uint16_t value123 = RAM16(0x1E05);
            uint8_t a_hi39;
            uint16_t direct_page2;
            if ((((value121 & 0x0F) << 8) | value122) == value123) {
                a_hi39 = value110;
                direct_page2 = 0x1E00;
            } else {
                uint8_t value124 = BUS8(c, 0x002142);
                if (value124 != 0) {
                    uint8_t value125 = RAM8(0x1E02);
                    if ((value125 & 0xF0) != 0) {
                        BUS8_SET(c, 0x002141, value125 & 0xF0);
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint8_t value126 = BUS8(c, 0x002140);
                            if (!(value126 == 0x83)) break;
                        }
                        BUS8_SET(c, 0x002140, 0x83);
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint8_t value127 = BUS8(c, 0x002140);
                            if (!(value127 != 0x83)) break;
                        }
                        BUS8_SET(c, 0x002140, 0);
                    }
                }
                uint8_t value128 = RAM8(0x1E05);
                if (!(value128 & 0x80)) {
                    RAM8(0x1E09) = value128;
                    RAM16_SET(0x1E0A, RAM16(0x1E06));
                }
                uint8_t value130 = RAM8(0x1E01);
                BUS8_SET(c, 0x002141, value130);
                RAM8(0x1E05) = value130;
                uint8_t value131 = RAM8(0x1E02);
                BUS8_SET(c, 0x002142, value131);
                RAM8(0x1E06) = value131 & 0x0F;
                uint8_t value132 = RAM8(0x1E03);
                BUS8_SET(c, 0x002143, value132);
                RAM8(0x1E07) = value132;
                uint8_t a17 = value132;
                uint8_t a_hi10 = value110;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value133 = BUS8(c, 0x002141);
                    a17 = value133;
                    if (!(a17 != 0)) break;
                }
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value134 = BUS8(c, 0x002140);
                    if (!(a_hi10 == value134)) break;
                }
                BUS8_SET(c, 0x002140, a_hi10);
                bool carry1 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value135 = BUS8(c, 0x002140);
                    carry1 = a_hi10 >= value135;
                    if (!(a_hi10 != value135)) break;
                }
                r->a = ((uint8_t)(a_hi10 + 1) << 8) | a17;
                r->y = value109;
                r->c = carry1;
                r->z = a17 == 0;
                r->n = a17 & 0x80;
                r->v = overflow;
                r->mf = 1;
                r->db = 0;
                r->dp = 0x1E00;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0202, 0xC3060A); GUARD_JSR(c, sp_call, 0x0202); } /* configure_music_echo_and_evict_samples_above_echo_limit */
                r->sp += 10;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all = r->a;
                BUS8_SET(c, 0x002141, 2);
                uint8_t value136 = RAM8(0x1EF3);
                uint8_t a18;
                uint8_t a_hi11;
                if (value136 == 0) {
                    a18 = value136;
                    a_hi11 = a_all >> 8;
                } else {
                    r->a = (a_all >> 8 << 8) | value136;
                    r->z = value136 == 0;
                    r->n = value136 & 0x80;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x020E, 0xC3067E); GUARD_JSR(c, sp_call, 0x020E); } /* transfer_fixed_extra_music_data_to_apu_address_2c00 */
                    r->sp += 10;
                    uint16_t a_all2 = r->a;
                    a18 = (uint8_t)a_all2;
                    a_hi11 = a_all2 >> 8;
                }
                BUS16_SET(c, 0x002142, 0x1A00);
                BUS8_SET(c, 0x002140, a_hi11);
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value137 = BUS8(c, 0x002140);
                    if (!(a_hi11 != value137)) break;
                }
                uint16_t value138 = RAM16(0x1E05);
                RAM8(0x0000 + sp0 - 0x0A) = 0;
                RAM8(0x0000 + sp0 - 0x0B) = value138 & 0xFF;
                RAM16_SET(0x1EEA, (value138 & 0xFF) << 1);
                uint16_t value139 = RAM16(0x1EEA);
                uint8_t value140 = BUS8(c, 0xC33D39 + (uint16_t)((value138 & 0xFF) + value139));
                RAM8(0x1E14) = value140;
                uint8_t value141 = BUS8(c, 0xC33D3A + (uint16_t)((value138 & 0xFF) + value139));
                RAM8(0x1E15) = value141;
                uint8_t value142 = BUS8(c, 0xC33D3B + (uint16_t)((value138 & 0xFF) + value139));
                RAM8(0x1E16) = value142;
                uint16_t value143 = RAM16(0x1E14);
                RAM8(0x1E14) = 0;
                RAM8(0x1E15) = 0;
                uint8_t value144 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + value143, RAM8(0x1E16));
                if ((uint16_t)(value143 + 1) == 0) {
                    RAM8(0x1E16)++;
                }
                uint8_t value145 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(value143 + 1), RAM8(0x1E16));
                RAM8(0x0000 + sp0 - 0x0A) = value145;
                if ((uint16_t)(value143 + 2) == 0) {
                    RAM8(0x1E16)++;
                }
                RAM8(0x0000 + sp0 - 0x0B) = value144;
                RAM8(0x1EF3) = 0;
                if (((value145 << 8) | value144) >= 0x1200) {
                    RAM8(0x1EF3)++;
                }
                uint8_t a_hi12 = 0x80;
                uint16_t x15 = (value145 << 8) | value144;
                uint16_t y6 = (uint16_t)(value143 + 2);
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value146 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y6, RAM8(0x1E16));
                    BUS8_SET(c, 0x002142, value146);
                    if ((uint16_t)(y6 + 1) == 0) {
                        RAM8(0x1E16)++;
                    }
                    uint8_t value147 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(y6 + 1), RAM8(0x1E16));
                    BUS8_SET(c, 0x002143, value147);
                    if ((uint16_t)(y6 + 2) == 0) {
                        RAM8(0x1E16)++;
                    }
                    BUS8_SET(c, 0x002140, a_hi12);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value148 = BUS8(c, 0x002140);
                        if (!(a_hi12 != value148)) break;
                    }
                    uint8_t a19;
                    if ((uint8_t)(a_hi12 + 1) != 0) {
                        a19 = (uint8_t)(a_hi12 + 1);
                    } else {
                        a19 = (uint8_t)(a_hi12 + 2);
                    }
                    a_hi12 = a19;
                    x15 = (uint16_t)(x15 - 2);
                    y6 = (uint16_t)(y6 + 2);
                    if (!(!(x15 & 0x8000))) break;
                }
                uint16_t x16 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    BUS16_SET(c, (uint16_t)(x16 + 0x1E8A), 0);
                    BUS16_SET(c, (uint16_t)(x16 + 0x1ECA), 0);
                    x16 = (uint16_t)(x16 + 2);
                    if (!(x16 != 0x20)) break;
                }
                uint16_t value149 = RAM16(0x1E04);
                RAM16_SET(0x1E12, ((value149 & 0xFF00) >> 3) + 0x20);
                RAM16_SET(0x1E14, 0x1EAA);
                RAM16_SET(0x1E16, 0x1ECA);
                uint8_t a_hi13 = 0x1E;
                uint16_t x17 = (value149 & 0xFF00) >> 3;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint16_t value150 = BUS16(c, 0xC33F22 + x17);
                    BUS16_SET(c, RAM16(0x1E14), value150);
                    RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                    RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                    uint16_t y7 = 0;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint16_t value151 = BUS16(c, 0x001E28 + y7);
                        if (value150 == value151) {
                            BUS16_SET(c, 0x001E8A + y7, value150);
                        } else {
                            if ((uint16_t)(y7 + 2) != 0x20) {
                                y7 = (uint16_t)(y7 + 2);
                                continue;
                            }
                            BUS16_SET(c, RAM16(0x1E16), value150);
                            RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                            RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                        }
                        break;
                    }
                    uint16_t value152 = RAM16(0x1E12);
                    a_hi13 = value150 >> 8;
                    x17 = (uint16_t)(x17 + 2);
                    if (!(x17 != value152)) break;
                }
                uint16_t value153 = RAM16(0x1ECA);
                bool m_flag;
                uint8_t a_hi33;
                if (value153 != 0) {
                    RAM16_SET(0x1E17, 0);
                    uint8_t a_hi14 = value153 >> 8;
                    uint16_t x18 = 0;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value154 = BUS8_RDP(c, (uint16_t)(x18 + 0x1ECA));
                        if (value154 != 0) {
                            RAM8(0x0000 + sp0 - 0x0A) = x18 >> 8;
                            RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x18;
                            RAM8(0x0000 + sp0 - 0x0C) = 0;
                            RAM8(0x0000 + sp0 - 0x0D) = ((a_hi14 << 8) | (uint8_t)(value154 - 1)) & 0xFF;
                            RAM16_SET(0x1EEA, (((a_hi14 << 8) | (uint8_t)(value154 - 1)) & 0xFF) << 1);
                            uint16_t value155 = RAM16(0x1EEA);
                            uint8_t value156 = BUS8(c, 0xC33DF9 + (uint16_t)((((a_hi14 << 8) | (uint8_t)(value154 - 1)) & 0xFF) + value155));
                            RAM8(0x1E14) = value156;
                            uint8_t value157 = BUS8(c, 0xC33DFA + (uint16_t)((((a_hi14 << 8) | (uint8_t)(value154 - 1)) & 0xFF) + value155));
                            RAM8(0x1E15) = value157;
                            uint8_t value158 = BUS8(c, 0xC33DFB + (uint16_t)((((a_hi14 << 8) | (uint8_t)(value154 - 1)) & 0xFF) + value155));
                            RAM8(0x1E16) = value158;
                            uint16_t value159 = RAM16(0x1E14);
                            RAM8(0x1E14) = 0;
                            RAM8(0x1E15) = 0;
                            uint8_t value160 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + value159, RAM8(0x1E16));
                            uint8_t value161 = RAM8(0x1E17);
                            RAM8(0x1E17) = (uint8_t)(value160 + value161);
                            if ((uint16_t)(value159 + 1) == 0) {
                                RAM8(0x1E16)++;
                            }
                            uint8_t value162 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(value159 + 1), RAM8(0x1E16));
                            RAM8(0x1E18) = (uint8_t)(value162 + RAM8(0x1E18) + (value160 + value161 > 0xFF));
                            a_hi14 = (uint16_t)((((a_hi14 << 8) | (uint8_t)(value154 - 1)) & 0xFF) + value155) >> 8;
                            x18 = (uint16_t)(x18 + 2);
                            continue;
                        }
                        break;
                    }
                    uint8_t a_hi15 = a_hi14;
                    uint16_t x19 = 0;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint16_t value164 = BUS16_RDP(c, (uint16_t)(x19 + 0x1E28));
                        if (value164 != 0) {
                            a_hi15 = value164 >> 8;
                            x19 = (uint16_t)(x19 + 2);
                            continue;
                        }
                        a_hi15 = value164 >> 8;
                        break;
                    }
                    uint16_t value165 = BUS16_RDP(c, (uint16_t)(x19 + 0x1E48));
                    uint16_t value166 = RAM16(0x1E17);
                    uint8_t a_hi29;
                    if (value165 + value166 > 0xFFFF) {
                        uint8_t a_hi16 = (uint16_t)(value165 + value166) >> 8;
                        uint16_t x20 = 0x1E;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint16_t value167 = BUS16_RDP(c, (uint16_t)(x20 + 0x1E88));
                            uint16_t x21;
                            if (value167 != 0) {
                                x21 = x20;
                            } else {
                                if ((uint16_t)(x20 - 2) != 0) {
                                    a_hi16 = value167 >> 8;
                                    x20 = (uint16_t)(x20 - 2);
                                    continue;
                                }
                                x21 = (uint16_t)(x20 - 2);
                            }
                            a_hi16 = value167 >> 8;
                            x20 = x21;
                            break;
                        }
                        RAM16_SET(0x1E24, x20);
                        uint8_t a_hi17 = a_hi16;
                        uint16_t x22 = 0;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint16_t value168 = BUS16_RDP(c, (uint16_t)(x22 + 0x1E8A));
                            uint16_t x23;
                            if (value168 == 0) {
                                x23 = x22;
                            } else {
                                if ((uint16_t)(x22 + 2) != 0x20) {
                                    a_hi17 = value168 >> 8;
                                    x22 = (uint16_t)(x22 + 2);
                                    continue;
                                }
                                x23 = (uint16_t)(x22 + 2);
                            }
                            a_hi17 = value168 >> 8;
                            x22 = x23;
                            break;
                        }
                        uint16_t value169 = RAM16(0x1E24);
                        uint8_t a_hi21;
                        if (x22 != value169) {
                            BUS8_SET(c, 0x002141, 7);
                            RAM8(0x1E10) = 0;
                            uint8_t a_hi18 = a_hi17;
                            uint16_t y8 = 0;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint16_t value170 = BUS16(c, 0x001E8A + y8);
                                uint8_t a_hi20;
                                if (value170 == 0) {
                                    uint8_t a20 = (uint8_t)value170;
                                    uint8_t a_hi19 = value170 >> 8;
                                    uint16_t x24 = y8;
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        if ((uint16_t)(x24 + 2) != RAM16(0x1E24)) {
                                            uint16_t value172 = BUS16_RDP(c, (uint16_t)(x24 + 0x1E8C));
                                            if (value172 != 0) {
                                                a20 = (uint8_t)value172;
                                                a_hi19 = value172 >> 8;
                                                x24 = (uint16_t)(x24 + 2);
                                                break;
                                            }
                                            a20 = (uint8_t)value172;
                                            a_hi19 = value172 >> 8;
                                            x24 = (uint16_t)(x24 + 2);
                                            continue;
                                        }
                                        a_hi18 = a_hi19;
                                        goto leave_loop_C30387;
                                    }
                                    BUS16_SET(c, (uint16_t)(x24 + 0x1E28), 0);
                                    BUS16_SET(c, (uint16_t)(x24 + 0x1E8A), 0);
                                    BUS16_SET(c, 0x001E28 + y8, (a_hi19 << 8) | a20);
                                    uint16_t value173 = BUS16_RDP(c, (uint16_t)(x24 + 0x1E48));
                                    BUS16_SET(c, 0x002142, value173);
                                    uint8_t value174 = RAM8(0x1E10);
                                    BUS8_SET(c, 0x002140, value174);
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        uint8_t value175 = BUS8(c, 0x002140);
                                        if (!(value174 != value175)) break;
                                    }
                                    RAM8(0x1E10)++;
                                    uint16_t value176 = BUS16(c, 0x001E48 + y8);
                                    BUS16_SET(c, 0x002142, value176);
                                    uint8_t value177 = RAM8(0x1E10);
                                    BUS8_SET(c, 0x002140, value177);
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        uint8_t value178 = BUS8(c, 0x002140);
                                        if (!(value177 != value178)) break;
                                    }
                                    RAM8(0x1E10)++;
                                    uint16_t value179 = BUS16_RDP(c, (uint16_t)(x24 + 0x1E6A));
                                    BUS16_SET(c, 0x002142, value179);
                                    BUS16_SET(c, 0x001E6A + y8, value179);
                                    uint16_t value180 = BUS16(c, 0x001E48 + y8);
                                    BUS16_SET(c, 0x001E4A + y8, (uint16_t)(value179 + value180));
                                    uint8_t value181 = RAM8(0x1E10);
                                    BUS8_SET(c, 0x002140, value181);
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        uint8_t value182 = BUS8(c, 0x002140);
                                        if (!(value181 != value182)) break;
                                    }
                                    RAM8(0x1E10)++;
                                    if ((uint16_t)(y8 + 2) != RAM16(0x1E24)) {
                                        a_hi18 = (uint16_t)(value179 + value180) >> 8;
                                        y8 = (uint16_t)(y8 + 2);
                                        continue;
                                    }
                                    a_hi20 = (uint16_t)(value179 + value180) >> 8;
                                } else {
                                    if ((uint16_t)(y8 + 2) != RAM16(0x1E24)) {
                                        a_hi18 = value170 >> 8;
                                        y8 = (uint16_t)(y8 + 2);
                                        continue;
                                    }
                                    a_hi20 = value170 >> 8;
                                }
                                a_hi18 = a_hi20;
                                y8 = (uint16_t)(y8 + 2);
                                break;
                            }
                            leave_loop_C30387:;
                            uint16_t x25 = y8;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                BUS16_SET(c, (uint16_t)(x25 + 0x1E28), 0);
                                x25 = (uint16_t)(x25 + 2);
                                if (!(x25 != 0x20)) break;
                            }
                            a_hi21 = a_hi18;
                        } else {
                            uint16_t x26 = x22;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                BUS16_SET(c, (uint16_t)(x26 + 0x1E28), 0);
                                x26 = (uint16_t)(x26 + 2);
                                if (!(x26 != 0x20)) break;
                            }
                            a_hi21 = a_hi17;
                        }
                        a_hi29 = a_hi21;
                    } else {
                        uint16_t value185 = RAM16(0x1EF1);
                        uint8_t a_hi28;
                        if ((uint16_t)(value165 + value166) >= value185) {
                            uint8_t a_hi22 = (uint16_t)(value165 + value166) >> 8;
                            uint16_t x27 = 0x1E;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint16_t value186 = BUS16_RDP(c, (uint16_t)(x27 + 0x1E88));
                                uint16_t x28;
                                if (value186 != 0) {
                                    x28 = x27;
                                } else {
                                    if ((uint16_t)(x27 - 2) != 0) {
                                        a_hi22 = value186 >> 8;
                                        x27 = (uint16_t)(x27 - 2);
                                        continue;
                                    }
                                    x28 = (uint16_t)(x27 - 2);
                                }
                                a_hi22 = value186 >> 8;
                                x27 = x28;
                                break;
                            }
                            RAM16_SET(0x1E24, x27);
                            uint8_t a_hi23 = a_hi22;
                            uint16_t x29 = 0;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint16_t value187 = BUS16_RDP(c, (uint16_t)(x29 + 0x1E8A));
                                uint16_t x30;
                                if (value187 == 0) {
                                    x30 = x29;
                                } else {
                                    if ((uint16_t)(x29 + 2) != 0x20) {
                                        a_hi23 = value187 >> 8;
                                        x29 = (uint16_t)(x29 + 2);
                                        continue;
                                    }
                                    x30 = (uint16_t)(x29 + 2);
                                }
                                a_hi23 = value187 >> 8;
                                x29 = x30;
                                break;
                            }
                            uint16_t value188 = RAM16(0x1E24);
                            uint8_t a_hi27;
                            if (x29 != value188) {
                                BUS8_SET(c, 0x002141, 7);
                                RAM8(0x1E10) = 0;
                                uint8_t a_hi24 = a_hi23;
                                uint16_t y9 = 0;
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    uint16_t value189 = BUS16(c, 0x001E8A + y9);
                                    uint8_t a_hi26;
                                    if (value189 == 0) {
                                        uint8_t a21 = (uint8_t)value189;
                                        uint8_t a_hi25 = value189 >> 8;
                                        uint16_t x31 = y9;
                                        for (;;) {
                                            LOOP_GUARD(loop_guard);
                                            if ((uint16_t)(x31 + 2) != RAM16(0x1E24)) {
                                                uint16_t value191 = BUS16_RDP(c, (uint16_t)(x31 + 0x1E8C));
                                                if (value191 != 0) {
                                                    a21 = (uint8_t)value191;
                                                    a_hi25 = value191 >> 8;
                                                    x31 = (uint16_t)(x31 + 2);
                                                    break;
                                                }
                                                a21 = (uint8_t)value191;
                                                a_hi25 = value191 >> 8;
                                                x31 = (uint16_t)(x31 + 2);
                                                continue;
                                            }
                                            a_hi24 = a_hi25;
                                            goto leave_loop_C30387_2;
                                        }
                                        BUS16_SET(c, (uint16_t)(x31 + 0x1E28), 0);
                                        BUS16_SET(c, (uint16_t)(x31 + 0x1E8A), 0);
                                        BUS16_SET(c, 0x001E28 + y9, (a_hi25 << 8) | a21);
                                        uint16_t value192 = BUS16_RDP(c, (uint16_t)(x31 + 0x1E48));
                                        BUS16_SET(c, 0x002142, value192);
                                        uint8_t value193 = RAM8(0x1E10);
                                        BUS8_SET(c, 0x002140, value193);
                                        for (;;) {
                                            LOOP_GUARD(loop_guard);
                                            uint8_t value194 = BUS8(c, 0x002140);
                                            if (!(value193 != value194)) break;
                                        }
                                        RAM8(0x1E10)++;
                                        uint16_t value195 = BUS16(c, 0x001E48 + y9);
                                        BUS16_SET(c, 0x002142, value195);
                                        uint8_t value196 = RAM8(0x1E10);
                                        BUS8_SET(c, 0x002140, value196);
                                        for (;;) {
                                            LOOP_GUARD(loop_guard);
                                            uint8_t value197 = BUS8(c, 0x002140);
                                            if (!(value196 != value197)) break;
                                        }
                                        RAM8(0x1E10)++;
                                        uint16_t value198 = BUS16_RDP(c, (uint16_t)(x31 + 0x1E6A));
                                        BUS16_SET(c, 0x002142, value198);
                                        BUS16_SET(c, 0x001E6A + y9, value198);
                                        uint16_t value199 = BUS16(c, 0x001E48 + y9);
                                        BUS16_SET(c, 0x001E4A + y9, (uint16_t)(value198 + value199));
                                        uint8_t value200 = RAM8(0x1E10);
                                        BUS8_SET(c, 0x002140, value200);
                                        for (;;) {
                                            LOOP_GUARD(loop_guard);
                                            uint8_t value201 = BUS8(c, 0x002140);
                                            if (!(value200 != value201)) break;
                                        }
                                        RAM8(0x1E10)++;
                                        if ((uint16_t)(y9 + 2) != RAM16(0x1E24)) {
                                            a_hi24 = (uint16_t)(value198 + value199) >> 8;
                                            y9 = (uint16_t)(y9 + 2);
                                            continue;
                                        }
                                        a_hi26 = (uint16_t)(value198 + value199) >> 8;
                                    } else {
                                        if ((uint16_t)(y9 + 2) != RAM16(0x1E24)) {
                                            a_hi24 = value189 >> 8;
                                            y9 = (uint16_t)(y9 + 2);
                                            continue;
                                        }
                                        a_hi26 = value189 >> 8;
                                    }
                                    a_hi24 = a_hi26;
                                    y9 = (uint16_t)(y9 + 2);
                                    break;
                                }
                                leave_loop_C30387_2:;
                                uint16_t x32 = y9;
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    BUS16_SET(c, (uint16_t)(x32 + 0x1E28), 0);
                                    x32 = (uint16_t)(x32 + 2);
                                    if (!(x32 != 0x20)) break;
                                }
                                a_hi27 = a_hi24;
                            } else {
                                uint16_t x33 = x29;
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    BUS16_SET(c, (uint16_t)(x33 + 0x1E28), 0);
                                    x33 = (uint16_t)(x33 + 2);
                                    if (!(x33 != 0x20)) break;
                                }
                                a_hi27 = a_hi23;
                            }
                            a_hi28 = a_hi27;
                        } else {
                            a_hi28 = (uint16_t)(value165 + value166) >> 8;
                        }
                        a_hi29 = a_hi28;
                    }
                    BUS8_SET(c, 0x002141, 3);
                    uint8_t a_hi30 = a_hi29;
                    uint16_t x34 = 0;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value204 = BUS8_RDP(c, (uint16_t)(x34 + 0x1E28));
                        if (value204 != 0) {
                            x34 = (uint16_t)(x34 + 2);
                            continue;
                        }
                        break;
                    }
                    RAM16_SET(0x1E24, x34);
                    uint8_t value205 = BUS8_RDP(c, (uint16_t)(x34 + 0x1E48));
                    BUS8_SET(c, 0x002142, value205);
                    uint8_t value206 = BUS8_RDP(c, (uint16_t)(x34 + 0x1E49));
                    BUS8_SET(c, 0x002143, value206);
                    BUS8_SET(c, 0x002140, 0);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value207 = BUS8(c, 0x002140);
                        if (!(value207 != 0)) break;
                    }
                    RAM8(0x1E10) = 1;
                    uint8_t a_hi31 = a_hi30;
                    uint16_t x35 = 0;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value208 = BUS8_RDP(c, (uint16_t)(x35 + 0x1ECA));
                        if (value208 != 0) {
                            BUS8_SET(c, 0x001E28 + RAM16(0x1E24), value208);
                            RAM8(0x0000 + sp0 - 0x0A) = x35 >> 8;
                            RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x35;
                            RAM8(0x0000 + sp0 - 0x0C) = 0;
                            RAM8(0x0000 + sp0 - 0x0D) = ((a_hi31 << 8) | (uint8_t)(value208 - 1)) & 0xFF;
                            RAM16_SET(0x1EEA, (((a_hi31 << 8) | (uint8_t)(value208 - 1)) & 0xFF) << 1);
                            uint16_t value210 = RAM16(0x1EEA);
                            uint8_t value211 = BUS8(c, 0xC33DF9 + (uint16_t)((((a_hi31 << 8) | (uint8_t)(value208 - 1)) & 0xFF) + value210));
                            RAM8(0x1E14) = value211;
                            uint8_t value212 = BUS8(c, 0xC33DFA + (uint16_t)((((a_hi31 << 8) | (uint8_t)(value208 - 1)) & 0xFF) + value210));
                            RAM8(0x1E15) = value212;
                            uint8_t value213 = BUS8(c, 0xC33DFB + (uint16_t)((((a_hi31 << 8) | (uint8_t)(value208 - 1)) & 0xFF) + value210));
                            RAM8(0x1E16) = value213;
                            uint16_t value214 = RAM16(0x1E14);
                            RAM8(0x1E14) = 0;
                            RAM8(0x1E15) = 0;
                            uint8_t value215 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + value214, RAM8(0x1E16));
                            if ((uint16_t)(value214 + 1) == 0) {
                                RAM8(0x1E16)++;
                            }
                            uint8_t value216 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(value214 + 1), RAM8(0x1E16));
                            if ((uint16_t)(value214 + 2) == 0) {
                                RAM8(0x1E16)++;
                            }
                            RAM8(0x0000 + sp0 - 0x0C) = value216;
                            RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)((value216 << 8) | value215);
                            uint16_t value217 = RAM16(0x1E24);
                            BUS16_SET(c, (uint16_t)(value217 + 0x1E6A), (value216 << 8) | value215);
                            uint16_t value218 = BUS16_RDP(c, (uint16_t)(value217 + 0x1E48));
                            BUS16_SET(c, (uint16_t)(value217 + 0x1E4A), (uint16_t)(((value216 << 8) | value215) + value218));
                            RAM16_SET(0x1E24, (uint16_t)(value217 + 2));
                            uint8_t value219 = RAM8(0x0000 + sp0 - 0x0D);
                            uint8_t value220 = RAM8(0x0000 + sp0 - 0x0C);
                            uint8_t a_hi32 = (uint16_t)(((value216 << 8) | value215) + value218) >> 8;
                            uint16_t x36 = (value220 << 8) | value219;
                            uint16_t y10 = (uint16_t)(value214 + 2);
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint8_t value221 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y10, RAM8(0x1E16));
                                BUS8_SET(c, 0x002141, value221);
                                if ((uint16_t)(y10 + 1) == 0) {
                                    RAM8(0x1E16)++;
                                }
                                uint8_t value222 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(y10 + 1), RAM8(0x1E16));
                                BUS8_SET(c, 0x002142, value222);
                                if ((uint16_t)(y10 + 2) == 0) {
                                    RAM8(0x1E16)++;
                                }
                                uint8_t value223 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(y10 + 2), RAM8(0x1E16));
                                BUS8_SET(c, 0x002143, value223);
                                if ((uint16_t)(y10 + 3) == 0) {
                                    RAM8(0x1E16)++;
                                }
                                uint8_t value224 = RAM8(0x1E10);
                                BUS8_SET(c, 0x002140, value224);
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    uint8_t value225 = BUS8(c, 0x002140);
                                    if (!(value224 != value225)) break;
                                }
                                RAM8(0x1E10)++;
                                if (RAM8(0x1E10) == 0) {
                                    RAM8(0x1E10)++;
                                }
                                x36 = (uint16_t)(x36 - 3);
                                y10 = (uint16_t)(y10 + 3);
                                if (!(x36 != 0)) break;
                            }
                            uint8_t value226 = RAM8(0x0000 + sp0 - 0x0B);
                            uint8_t value227 = RAM8(0x0000 + sp0 - 0x0A);
                            a_hi31 = a_hi32;
                            x35 = (uint16_t)(((value227 << 8) | value226) + 2);
                            continue;
                        }
                        break;
                    }
                    m_flag = 1;
                    a_hi33 = a_hi31;
                } else {
                    m_flag = 0;
                    a_hi33 = value153 >> 8;
                }
                uint16_t value228 = RAM16(0x1EAA);
                bool m_flag2;
                uint8_t a_hi38;
                uint16_t direct_page;
                if (value228 != 0) {
                    RAM16_SET(0x1E14, 0x1EAA);
                    RAM16_SET(0x1E16, 0x1F00);
                    RAM16_SET(0x1E18, 0x1F40);
                    RAM16_SET(0x1E1A, 0x1FC0);
                    uint8_t a_hi34 = 0x1F;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint16_t value229 = BUS16_RDP(c, RAM16(0x1E14));
                        if (value229 != 0) {
                            RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                            RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                            uint16_t y11 = 0;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint16_t value230 = BUS16(c, 0x001E28 + y11);
                                if (value229 != value230) {
                                    y11 = (uint16_t)(y11 + 2);
                                    continue;
                                }
                                break;
                            }
                            uint16_t value231 = BUS16(c, 0xC33E9E + (uint16_t)((uint16_t)(value229 - 1) << 1));
                            BUS16_SET(c, RAM16(0x1E16), value231);
                            RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                            RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                            uint16_t value232 = BUS16(c, 0x001E48 + y11);
                            BUS16_SET(c, RAM16(0x1E18), value232);
                            RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                            RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                            uint16_t value233 = BUS16(c, 0xC33E5C + (uint16_t)((uint16_t)(value229 - 1) << 1));
                            BUS16_SET(c, RAM16(0x1E18), (uint16_t)(value232 + value233));
                            RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                            RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                            uint16_t value234 = BUS16(c, 0xC33EE0 + (uint16_t)((uint16_t)(value229 - 1) << 1));
                            BUS16_SET(c, RAM16(0x1E1A), value234);
                            RAM16_SET(0x1E1A, (uint16_t)(RAM16(0x1E1A) + 1));
                            RAM16_SET(0x1E1A, (uint16_t)(RAM16(0x1E1A) + 1));
                            a_hi34 = value234 >> 8;
                            continue;
                        }
                        a_hi34 = value229 >> 8;
                        break;
                    }
                    BUS8_SET(c, 0x002141, 2);
                    RAM8(0x0000 + sp0 - 0x0A) = 0x1F;
                    RAM8(0x0000 + sp0 - 0x0B) = 0;
                    BUS16_SET(c, 0x002142, 0x1840);
                    uint8_t a22 = 0;
                    uint8_t a_hi35 = a_hi34;
                    uint16_t x37 = 0xFFFE;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        BUS8_SET(c, 0x002140, a22);
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint8_t value235 = BUS8(c, 0x002140);
                            if (!(a22 != value235)) break;
                        }
                        if ((uint16_t)(x37 + 2) != 0x40) {
                            uint16_t value236 = BUS16_RDP(c, (uint16_t)(x37 + 0x1F02));
                            BUS16_SET(c, 0x002142, value236);
                            a22 = (uint8_t)(a22 + 1);
                            x37 = (uint16_t)(x37 + 2);
                            continue;
                        }
                        a22 = (uint8_t)(a22 + 1);
                        x37 = (uint16_t)(x37 + 2);
                        break;
                    }
                    BUS16_SET(c, 0x002142, 0x1980);
                    uint8_t a23 = 0;
                    uint8_t a_hi36 = a_hi35;
                    uint16_t x38 = 0xFFFE;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        BUS8_SET(c, 0x002140, a23);
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint8_t value237 = BUS8(c, 0x002140);
                            if (!(a23 != value237)) break;
                        }
                        if ((uint16_t)(x38 + 2) != 0x80) {
                            uint16_t value238 = BUS16_RDP(c, (uint16_t)(x38 + 0x1F42));
                            BUS16_SET(c, 0x002142, value238);
                            a23 = (uint8_t)(a23 + 1);
                            x38 = (uint16_t)(x38 + 2);
                            continue;
                        }
                        a23 = (uint8_t)(a23 + 1);
                        x38 = (uint16_t)(x38 + 2);
                        break;
                    }
                    BUS16_SET(c, 0x002142, 0x18C0);
                    uint8_t a24 = 0;
                    uint8_t a_hi37 = a_hi36;
                    uint16_t x39 = 0xFFFE;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        BUS8_SET(c, 0x002140, a24);
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint8_t value239 = BUS8(c, 0x002140);
                            if (!(a24 != value239)) break;
                        }
                        if ((uint16_t)(x39 + 2) != 0x40) {
                            uint16_t value240 = BUS16_RDP(c, (uint16_t)(x39 + 0x1FC2));
                            BUS16_SET(c, 0x002142, value240);
                            a24 = (uint8_t)(a24 + 1);
                            x39 = (uint16_t)(x39 + 2);
                            continue;
                        }
                        a24 = (uint8_t)(a24 + 1);
                        x39 = (uint16_t)(x39 + 2);
                        break;
                    }
                    m_flag2 = 1;
                    a_hi38 = a_hi37;
                    direct_page = 0x1F00;
                } else {
                    m_flag2 = 0;
                    a_hi38 = value228 >> 8;
                    direct_page = 0x1E00;
                }
                BUS8_SET(c, 0x002141, 0);
                BUS8_SET(c, 0x002140, 0);
                a_hi39 = a_hi38;
                direct_page2 = direct_page;
            }
            uint8_t value241 = RAM8(0x0000 + sp0 - 9);
            uint8_t value242 = RAM8(0x0000 + sp0 - 8);
            uint8_t value243 = RAM8(0x0000 + sp0 - 7);
            uint8_t value244 = RAM8(0x0000 + sp0 - 6);
            uint8_t value245 = RAM8(0x0000 + sp0 - 5);
            uint8_t value246 = RAM8(0x0000 + sp0 - 4);
            uint8_t value247 = RAM8(0x0000 + sp0 - 3);
            uint8_t value248 = RAM8(0x0000 + sp0 - 2);
            uint8_t value249 = RAM8(0x0000 + sp0 - 1);
            uint8_t value250 = RAM8(0x0000 + sp0);
            r->a = (value246 << 8) | value245;
            r->x = (value244 << 8) | value243;
            r->y = (value242 << 8) | value241;
            r->c = value247 & 0x01;
            r->z = value250 == 0;
            r->n = value250 & 0x80;
            r->v = value247 & 0x40;
            r->mf = value247 & 0x20;
            r->xf = value247 & 0x10;
            r->db = value250;
            r->dp = (value249 << 8) | value248;
            r->i = value247 & 0x04;
            r->d = value247 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        if (value110 >= 0x70) {
            r->a = (a_hi9 << 8) | value110;
            r->x = x14;
            r->y = value109;
            r->c = value110 >= 0x70;
            r->z = value110 == 0x70;
            r->n = (uint8_t)(value110 - 0x70) & 0x80;
            r->v = overflow;
            r->mf = 1;
            r->db = 0;
            r->dp = 0x1E00;
            TAIL_CALL_FRAME(c, 0xC305F3, SOM_RTL, 10); /* expand_music_command_preset_and_dispatch_requested_song */
        }
        r->a = (a_hi9 << 8) | value110;
        r->x = x14;
        r->y = value109;
        r->c = value110 >= 0x70;
        r->z = value110 == 0x70;
        r->n = (uint8_t)(value110 - 0x70) & 0x80;
        r->v = overflow;
        r->mf = 1;
        r->db = 0;
        r->dp = 0x1E00;
        TAIL_CALL_FRAME(c, 0xC3059F, SOM_RTL, 10); /* send_non_music_audio_command_packet */
    }
}
SOM_REGISTER(0xC3002C, SOM_RTL, "gen", upload_six_spc_blocks_or_reset_ready_audio_metadata, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 14, 0, 0, 1395, 688)

/* SOM_POLL_HOOK */

/* C30160 audio_command_sender_save_dispatch_restore   [class D, 1087 bytes, 538 instructions]
 * Source: src/rom/upload_six_spc_blocks_or_reset_ready_audio_metadata.s
 * Interior entry C30160 of upload_six_spc_blocks_or_reset_ready_audio_metadata, same file.
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void upload_six_spc_blocks_or_reset_ready_audio_metadata_at_C30160(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = a_hi;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 6) = x >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 8) = y >> 8;
    RAM8(0x0000 + sp0 - 9) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 0x0A) = 0;
    RAM8(0x0000 + sp0 - 0x0A) = 0x1E;
    RAM8(0x0000 + sp0 - 0x0B) = 0;
    uint8_t value = RAM8(0x1E00);
    RAM8(0x1E00) = 0;
    if (value == 0) {
        SET_A8(r, (uint8_t)((a_hi << 8) | a));
        r->z = 0;
        r->n = 0;
        RETURN_RTL(c);
    }
    if (value & 0x80) {
        r->a = (a_hi << 8) | value;
        r->x = 0x1E00;
        r->z = value == 0;
        r->n = value & 0x80;
        r->db = 0;
        r->dp = 0x1E00;
        TAIL_CALL_FRAME(c, 0xC3059F, SOM_RTL, 10); /* send_non_music_audio_command_packet */
    }
    if (value == 1) {
        uint8_t value2 = RAM8(0x1E02);
        RAM8(0x0000 + sp0 - 0x0A) = value2 & 0x0F;
        uint8_t value3 = RAM8(0x1E01);
        RAM8(0x0000 + sp0 - 0x0B) = value3;
        uint16_t value4 = RAM16(0x1E05);
        uint8_t a_hi30;
        uint16_t direct_page2;
        if ((((value2 & 0x0F) << 8) | value3) == value4) {
            a_hi30 = value;
            direct_page2 = 0x1E00;
        } else {
            uint8_t value5 = BUS8(c, 0x002142);
            if (value5 != 0) {
                uint8_t value6 = RAM8(0x1E02);
                if ((value6 & 0xF0) != 0) {
                    BUS8_SET(c, 0x002141, value6 & 0xF0);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value7 = BUS8(c, 0x002140);
                        if (!(value7 == 0x83)) break;
                    }
                    BUS8_SET(c, 0x002140, 0x83);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value8 = BUS8(c, 0x002140);
                        if (!(value8 != 0x83)) break;
                    }
                    BUS8_SET(c, 0x002140, 0);
                }
            }
            uint8_t value9 = RAM8(0x1E05);
            if (!(value9 & 0x80)) {
                RAM8(0x1E09) = value9;
                RAM16_SET(0x1E0A, RAM16(0x1E06));
            }
            uint8_t value11 = RAM8(0x1E01);
            BUS8_SET(c, 0x002141, value11);
            RAM8(0x1E05) = value11;
            uint8_t value12 = RAM8(0x1E02);
            BUS8_SET(c, 0x002142, value12);
            RAM8(0x1E06) = value12 & 0x0F;
            uint8_t value13 = RAM8(0x1E03);
            BUS8_SET(c, 0x002143, value13);
            RAM8(0x1E07) = value13;
            uint8_t a1 = value13;
            uint8_t a_hi1 = value;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value14 = BUS8(c, 0x002141);
                a1 = value14;
                if (!(a1 != 0)) break;
            }
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value15 = BUS8(c, 0x002140);
                if (!(a_hi1 == value15)) break;
            }
            BUS8_SET(c, 0x002140, a_hi1);
            bool carry1 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value16 = BUS8(c, 0x002140);
                carry1 = a_hi1 >= value16;
                if (!(a_hi1 != value16)) break;
            }
            r->a = ((uint8_t)(a_hi1 + 1) << 8) | a1;
            r->y = y;
            r->c = carry1;
            r->z = a1 == 0;
            r->n = a1 & 0x80;
            r->v = overflow;
            r->db = 0;
            r->dp = 0x1E00;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0202, 0xC3060A); GUARD_JSR(c, sp_call, 0x0202); } /* configure_music_echo_and_evict_samples_above_echo_limit */
            r->sp += 10;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            BUS8_SET(c, 0x002141, 2);
            uint8_t value17 = RAM8(0x1EF3);
            uint8_t a2;
            uint8_t a_hi2;
            if (value17 == 0) {
                a2 = value17;
                a_hi2 = a_all >> 8;
            } else {
                r->a = (a_all >> 8 << 8) | value17;
                r->z = value17 == 0;
                r->n = value17 & 0x80;
                r->sp -= 10;
                { const uint16_t sp_call = r->sp; JSR(c, 0x020E, 0xC3067E); GUARD_JSR(c, sp_call, 0x020E); } /* transfer_fixed_extra_music_data_to_apu_address_2c00 */
                r->sp += 10;
                uint16_t a_all2 = r->a;
                a2 = (uint8_t)a_all2;
                a_hi2 = a_all2 >> 8;
            }
            BUS16_SET(c, 0x002142, 0x1A00);
            BUS8_SET(c, 0x002140, a_hi2);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value18 = BUS8(c, 0x002140);
                if (!(a_hi2 != value18)) break;
            }
            uint16_t value19 = RAM16(0x1E05);
            RAM8(0x0000 + sp0 - 0x0A) = 0;
            RAM8(0x0000 + sp0 - 0x0B) = value19 & 0xFF;
            RAM16_SET(0x1EEA, (value19 & 0xFF) << 1);
            uint16_t value20 = RAM16(0x1EEA);
            uint8_t value21 = BUS8(c, 0xC33D39 + (uint16_t)((value19 & 0xFF) + value20));
            RAM8(0x1E14) = value21;
            uint8_t value22 = BUS8(c, 0xC33D3A + (uint16_t)((value19 & 0xFF) + value20));
            RAM8(0x1E15) = value22;
            uint8_t value23 = BUS8(c, 0xC33D3B + (uint16_t)((value19 & 0xFF) + value20));
            RAM8(0x1E16) = value23;
            uint16_t value24 = RAM16(0x1E14);
            RAM8(0x1E14) = 0;
            RAM8(0x1E15) = 0;
            uint8_t value25 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + value24, RAM8(0x1E16));
            if ((uint16_t)(value24 + 1) == 0) {
                RAM8(0x1E16)++;
            }
            uint8_t value26 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(value24 + 1), RAM8(0x1E16));
            RAM8(0x0000 + sp0 - 0x0A) = value26;
            if ((uint16_t)(value24 + 2) == 0) {
                RAM8(0x1E16)++;
            }
            RAM8(0x0000 + sp0 - 0x0B) = value25;
            RAM8(0x1EF3) = 0;
            if (((value26 << 8) | value25) >= 0x1200) {
                RAM8(0x1EF3)++;
            }
            uint8_t a_hi3 = 0x80;
            uint16_t x1 = (value26 << 8) | value25;
            uint16_t y1 = (uint16_t)(value24 + 2);
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint8_t value27 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y1, RAM8(0x1E16));
                BUS8_SET(c, 0x002142, value27);
                if ((uint16_t)(y1 + 1) == 0) {
                    RAM8(0x1E16)++;
                }
                uint8_t value28 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(y1 + 1), RAM8(0x1E16));
                BUS8_SET(c, 0x002143, value28);
                if ((uint16_t)(y1 + 2) == 0) {
                    RAM8(0x1E16)++;
                }
                BUS8_SET(c, 0x002140, a_hi3);
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value29 = BUS8(c, 0x002140);
                    if (!(a_hi3 != value29)) break;
                }
                uint8_t a3;
                if ((uint8_t)(a_hi3 + 1) != 0) {
                    a3 = (uint8_t)(a_hi3 + 1);
                } else {
                    a3 = (uint8_t)(a_hi3 + 2);
                }
                a_hi3 = a3;
                x1 = (uint16_t)(x1 - 2);
                y1 = (uint16_t)(y1 + 2);
                if (!(!(x1 & 0x8000))) break;
            }
            uint16_t x2 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS16_SET(c, (uint16_t)(x2 + 0x1E8A), 0);
                BUS16_SET(c, (uint16_t)(x2 + 0x1ECA), 0);
                x2 = (uint16_t)(x2 + 2);
                if (!(x2 != 0x20)) break;
            }
            uint16_t value30 = RAM16(0x1E04);
            RAM16_SET(0x1E12, ((value30 & 0xFF00) >> 3) + 0x20);
            RAM16_SET(0x1E14, 0x1EAA);
            RAM16_SET(0x1E16, 0x1ECA);
            uint8_t a_hi4 = 0x1E;
            uint16_t x3 = (value30 & 0xFF00) >> 3;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value31 = BUS16(c, 0xC33F22 + x3);
                BUS16_SET(c, RAM16(0x1E14), value31);
                RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                uint16_t y2 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint16_t value32 = BUS16(c, 0x001E28 + y2);
                    if (value31 == value32) {
                        BUS16_SET(c, 0x001E8A + y2, value31);
                    } else {
                        if ((uint16_t)(y2 + 2) != 0x20) {
                            y2 = (uint16_t)(y2 + 2);
                            continue;
                        }
                        BUS16_SET(c, RAM16(0x1E16), value31);
                        RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                        RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                    }
                    break;
                }
                uint16_t value33 = RAM16(0x1E12);
                a_hi4 = value31 >> 8;
                x3 = (uint16_t)(x3 + 2);
                if (!(x3 != value33)) break;
            }
            uint16_t value34 = RAM16(0x1ECA);
            bool m_flag;
            uint8_t a_hi24;
            if (value34 != 0) {
                RAM16_SET(0x1E17, 0);
                uint8_t a_hi5 = value34 >> 8;
                uint16_t x4 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value35 = BUS8_RDP(c, (uint16_t)(x4 + 0x1ECA));
                    if (value35 != 0) {
                        RAM8(0x0000 + sp0 - 0x0A) = x4 >> 8;
                        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x4;
                        RAM8(0x0000 + sp0 - 0x0C) = 0;
                        RAM8(0x0000 + sp0 - 0x0D) = ((a_hi5 << 8) | (uint8_t)(value35 - 1)) & 0xFF;
                        RAM16_SET(0x1EEA, (((a_hi5 << 8) | (uint8_t)(value35 - 1)) & 0xFF) << 1);
                        uint16_t value36 = RAM16(0x1EEA);
                        uint8_t value37 = BUS8(c, 0xC33DF9 + (uint16_t)((((a_hi5 << 8) | (uint8_t)(value35 - 1)) & 0xFF) + value36));
                        RAM8(0x1E14) = value37;
                        uint8_t value38 = BUS8(c, 0xC33DFA + (uint16_t)((((a_hi5 << 8) | (uint8_t)(value35 - 1)) & 0xFF) + value36));
                        RAM8(0x1E15) = value38;
                        uint8_t value39 = BUS8(c, 0xC33DFB + (uint16_t)((((a_hi5 << 8) | (uint8_t)(value35 - 1)) & 0xFF) + value36));
                        RAM8(0x1E16) = value39;
                        uint16_t value40 = RAM16(0x1E14);
                        RAM8(0x1E14) = 0;
                        RAM8(0x1E15) = 0;
                        uint8_t value41 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + value40, RAM8(0x1E16));
                        uint8_t value42 = RAM8(0x1E17);
                        RAM8(0x1E17) = (uint8_t)(value41 + value42);
                        if ((uint16_t)(value40 + 1) == 0) {
                            RAM8(0x1E16)++;
                        }
                        uint8_t value43 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(value40 + 1), RAM8(0x1E16));
                        RAM8(0x1E18) = (uint8_t)(value43 + RAM8(0x1E18) + (value41 + value42 > 0xFF));
                        a_hi5 = (uint16_t)((((a_hi5 << 8) | (uint8_t)(value35 - 1)) & 0xFF) + value36) >> 8;
                        x4 = (uint16_t)(x4 + 2);
                        continue;
                    }
                    break;
                }
                uint8_t a_hi6 = a_hi5;
                uint16_t x5 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint16_t value45 = BUS16_RDP(c, (uint16_t)(x5 + 0x1E28));
                    if (value45 != 0) {
                        a_hi6 = value45 >> 8;
                        x5 = (uint16_t)(x5 + 2);
                        continue;
                    }
                    a_hi6 = value45 >> 8;
                    break;
                }
                uint16_t value46 = BUS16_RDP(c, (uint16_t)(x5 + 0x1E48));
                uint16_t value47 = RAM16(0x1E17);
                uint8_t a_hi20;
                if (value46 + value47 > 0xFFFF) {
                    uint8_t a_hi7 = (uint16_t)(value46 + value47) >> 8;
                    uint16_t x6 = 0x1E;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint16_t value48 = BUS16_RDP(c, (uint16_t)(x6 + 0x1E88));
                        uint16_t x7;
                        if (value48 != 0) {
                            x7 = x6;
                        } else {
                            if ((uint16_t)(x6 - 2) != 0) {
                                a_hi7 = value48 >> 8;
                                x6 = (uint16_t)(x6 - 2);
                                continue;
                            }
                            x7 = (uint16_t)(x6 - 2);
                        }
                        a_hi7 = value48 >> 8;
                        x6 = x7;
                        break;
                    }
                    RAM16_SET(0x1E24, x6);
                    uint8_t a_hi8 = a_hi7;
                    uint16_t x8 = 0;
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint16_t value49 = BUS16_RDP(c, (uint16_t)(x8 + 0x1E8A));
                        uint16_t x9;
                        if (value49 == 0) {
                            x9 = x8;
                        } else {
                            if ((uint16_t)(x8 + 2) != 0x20) {
                                a_hi8 = value49 >> 8;
                                x8 = (uint16_t)(x8 + 2);
                                continue;
                            }
                            x9 = (uint16_t)(x8 + 2);
                        }
                        a_hi8 = value49 >> 8;
                        x8 = x9;
                        break;
                    }
                    uint16_t value50 = RAM16(0x1E24);
                    uint8_t a_hi12;
                    if (x8 != value50) {
                        BUS8_SET(c, 0x002141, 7);
                        RAM8(0x1E10) = 0;
                        uint8_t a_hi9 = a_hi8;
                        uint16_t y3 = 0;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint16_t value51 = BUS16(c, 0x001E8A + y3);
                            uint8_t a_hi11;
                            if (value51 == 0) {
                                uint8_t a4 = (uint8_t)value51;
                                uint8_t a_hi10 = value51 >> 8;
                                uint16_t x10 = y3;
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    if ((uint16_t)(x10 + 2) != RAM16(0x1E24)) {
                                        uint16_t value53 = BUS16_RDP(c, (uint16_t)(x10 + 0x1E8C));
                                        if (value53 != 0) {
                                            a4 = (uint8_t)value53;
                                            a_hi10 = value53 >> 8;
                                            x10 = (uint16_t)(x10 + 2);
                                            break;
                                        }
                                        a4 = (uint8_t)value53;
                                        a_hi10 = value53 >> 8;
                                        x10 = (uint16_t)(x10 + 2);
                                        continue;
                                    }
                                    a_hi9 = a_hi10;
                                    goto leave_loop_C30387;
                                }
                                BUS16_SET(c, (uint16_t)(x10 + 0x1E28), 0);
                                BUS16_SET(c, (uint16_t)(x10 + 0x1E8A), 0);
                                BUS16_SET(c, 0x001E28 + y3, (a_hi10 << 8) | a4);
                                uint16_t value54 = BUS16_RDP(c, (uint16_t)(x10 + 0x1E48));
                                BUS16_SET(c, 0x002142, value54);
                                uint8_t value55 = RAM8(0x1E10);
                                BUS8_SET(c, 0x002140, value55);
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    uint8_t value56 = BUS8(c, 0x002140);
                                    if (!(value55 != value56)) break;
                                }
                                RAM8(0x1E10)++;
                                uint16_t value57 = BUS16(c, 0x001E48 + y3);
                                BUS16_SET(c, 0x002142, value57);
                                uint8_t value58 = RAM8(0x1E10);
                                BUS8_SET(c, 0x002140, value58);
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    uint8_t value59 = BUS8(c, 0x002140);
                                    if (!(value58 != value59)) break;
                                }
                                RAM8(0x1E10)++;
                                uint16_t value60 = BUS16_RDP(c, (uint16_t)(x10 + 0x1E6A));
                                BUS16_SET(c, 0x002142, value60);
                                BUS16_SET(c, 0x001E6A + y3, value60);
                                uint16_t value61 = BUS16(c, 0x001E48 + y3);
                                BUS16_SET(c, 0x001E4A + y3, (uint16_t)(value60 + value61));
                                uint8_t value62 = RAM8(0x1E10);
                                BUS8_SET(c, 0x002140, value62);
                                for (;;) {
                                    LOOP_GUARD(loop_guard);
                                    uint8_t value63 = BUS8(c, 0x002140);
                                    if (!(value62 != value63)) break;
                                }
                                RAM8(0x1E10)++;
                                if ((uint16_t)(y3 + 2) != RAM16(0x1E24)) {
                                    a_hi9 = (uint16_t)(value60 + value61) >> 8;
                                    y3 = (uint16_t)(y3 + 2);
                                    continue;
                                }
                                a_hi11 = (uint16_t)(value60 + value61) >> 8;
                            } else {
                                if ((uint16_t)(y3 + 2) != RAM16(0x1E24)) {
                                    a_hi9 = value51 >> 8;
                                    y3 = (uint16_t)(y3 + 2);
                                    continue;
                                }
                                a_hi11 = value51 >> 8;
                            }
                            a_hi9 = a_hi11;
                            y3 = (uint16_t)(y3 + 2);
                            break;
                        }
                        leave_loop_C30387:;
                        uint16_t x11 = y3;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            BUS16_SET(c, (uint16_t)(x11 + 0x1E28), 0);
                            x11 = (uint16_t)(x11 + 2);
                            if (!(x11 != 0x20)) break;
                        }
                        a_hi12 = a_hi9;
                    } else {
                        uint16_t x12 = x8;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            BUS16_SET(c, (uint16_t)(x12 + 0x1E28), 0);
                            x12 = (uint16_t)(x12 + 2);
                            if (!(x12 != 0x20)) break;
                        }
                        a_hi12 = a_hi8;
                    }
                    a_hi20 = a_hi12;
                } else {
                    uint16_t value66 = RAM16(0x1EF1);
                    uint8_t a_hi19;
                    if ((uint16_t)(value46 + value47) >= value66) {
                        uint8_t a_hi13 = (uint16_t)(value46 + value47) >> 8;
                        uint16_t x13 = 0x1E;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint16_t value67 = BUS16_RDP(c, (uint16_t)(x13 + 0x1E88));
                            uint16_t x14;
                            if (value67 != 0) {
                                x14 = x13;
                            } else {
                                if ((uint16_t)(x13 - 2) != 0) {
                                    a_hi13 = value67 >> 8;
                                    x13 = (uint16_t)(x13 - 2);
                                    continue;
                                }
                                x14 = (uint16_t)(x13 - 2);
                            }
                            a_hi13 = value67 >> 8;
                            x13 = x14;
                            break;
                        }
                        RAM16_SET(0x1E24, x13);
                        uint8_t a_hi14 = a_hi13;
                        uint16_t x15 = 0;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint16_t value68 = BUS16_RDP(c, (uint16_t)(x15 + 0x1E8A));
                            uint16_t x16;
                            if (value68 == 0) {
                                x16 = x15;
                            } else {
                                if ((uint16_t)(x15 + 2) != 0x20) {
                                    a_hi14 = value68 >> 8;
                                    x15 = (uint16_t)(x15 + 2);
                                    continue;
                                }
                                x16 = (uint16_t)(x15 + 2);
                            }
                            a_hi14 = value68 >> 8;
                            x15 = x16;
                            break;
                        }
                        uint16_t value69 = RAM16(0x1E24);
                        uint8_t a_hi18;
                        if (x15 != value69) {
                            BUS8_SET(c, 0x002141, 7);
                            RAM8(0x1E10) = 0;
                            uint8_t a_hi15 = a_hi14;
                            uint16_t y4 = 0;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint16_t value70 = BUS16(c, 0x001E8A + y4);
                                uint8_t a_hi17;
                                if (value70 == 0) {
                                    uint8_t a5 = (uint8_t)value70;
                                    uint8_t a_hi16 = value70 >> 8;
                                    uint16_t x17 = y4;
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        if ((uint16_t)(x17 + 2) != RAM16(0x1E24)) {
                                            uint16_t value72 = BUS16_RDP(c, (uint16_t)(x17 + 0x1E8C));
                                            if (value72 != 0) {
                                                a5 = (uint8_t)value72;
                                                a_hi16 = value72 >> 8;
                                                x17 = (uint16_t)(x17 + 2);
                                                break;
                                            }
                                            a5 = (uint8_t)value72;
                                            a_hi16 = value72 >> 8;
                                            x17 = (uint16_t)(x17 + 2);
                                            continue;
                                        }
                                        a_hi15 = a_hi16;
                                        goto leave_loop_C30387_2;
                                    }
                                    BUS16_SET(c, (uint16_t)(x17 + 0x1E28), 0);
                                    BUS16_SET(c, (uint16_t)(x17 + 0x1E8A), 0);
                                    BUS16_SET(c, 0x001E28 + y4, (a_hi16 << 8) | a5);
                                    uint16_t value73 = BUS16_RDP(c, (uint16_t)(x17 + 0x1E48));
                                    BUS16_SET(c, 0x002142, value73);
                                    uint8_t value74 = RAM8(0x1E10);
                                    BUS8_SET(c, 0x002140, value74);
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        uint8_t value75 = BUS8(c, 0x002140);
                                        if (!(value74 != value75)) break;
                                    }
                                    RAM8(0x1E10)++;
                                    uint16_t value76 = BUS16(c, 0x001E48 + y4);
                                    BUS16_SET(c, 0x002142, value76);
                                    uint8_t value77 = RAM8(0x1E10);
                                    BUS8_SET(c, 0x002140, value77);
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        uint8_t value78 = BUS8(c, 0x002140);
                                        if (!(value77 != value78)) break;
                                    }
                                    RAM8(0x1E10)++;
                                    uint16_t value79 = BUS16_RDP(c, (uint16_t)(x17 + 0x1E6A));
                                    BUS16_SET(c, 0x002142, value79);
                                    BUS16_SET(c, 0x001E6A + y4, value79);
                                    uint16_t value80 = BUS16(c, 0x001E48 + y4);
                                    BUS16_SET(c, 0x001E4A + y4, (uint16_t)(value79 + value80));
                                    uint8_t value81 = RAM8(0x1E10);
                                    BUS8_SET(c, 0x002140, value81);
                                    for (;;) {
                                        LOOP_GUARD(loop_guard);
                                        uint8_t value82 = BUS8(c, 0x002140);
                                        if (!(value81 != value82)) break;
                                    }
                                    RAM8(0x1E10)++;
                                    if ((uint16_t)(y4 + 2) != RAM16(0x1E24)) {
                                        a_hi15 = (uint16_t)(value79 + value80) >> 8;
                                        y4 = (uint16_t)(y4 + 2);
                                        continue;
                                    }
                                    a_hi17 = (uint16_t)(value79 + value80) >> 8;
                                } else {
                                    if ((uint16_t)(y4 + 2) != RAM16(0x1E24)) {
                                        a_hi15 = value70 >> 8;
                                        y4 = (uint16_t)(y4 + 2);
                                        continue;
                                    }
                                    a_hi17 = value70 >> 8;
                                }
                                a_hi15 = a_hi17;
                                y4 = (uint16_t)(y4 + 2);
                                break;
                            }
                            leave_loop_C30387_2:;
                            uint16_t x18 = y4;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                BUS16_SET(c, (uint16_t)(x18 + 0x1E28), 0);
                                x18 = (uint16_t)(x18 + 2);
                                if (!(x18 != 0x20)) break;
                            }
                            a_hi18 = a_hi15;
                        } else {
                            uint16_t x19 = x15;
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                BUS16_SET(c, (uint16_t)(x19 + 0x1E28), 0);
                                x19 = (uint16_t)(x19 + 2);
                                if (!(x19 != 0x20)) break;
                            }
                            a_hi18 = a_hi14;
                        }
                        a_hi19 = a_hi18;
                    } else {
                        a_hi19 = (uint16_t)(value46 + value47) >> 8;
                    }
                    a_hi20 = a_hi19;
                }
                BUS8_SET(c, 0x002141, 3);
                uint8_t a_hi21 = a_hi20;
                uint16_t x20 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value85 = BUS8_RDP(c, (uint16_t)(x20 + 0x1E28));
                    if (value85 != 0) {
                        x20 = (uint16_t)(x20 + 2);
                        continue;
                    }
                    break;
                }
                RAM16_SET(0x1E24, x20);
                uint8_t value86 = BUS8_RDP(c, (uint16_t)(x20 + 0x1E48));
                BUS8_SET(c, 0x002142, value86);
                uint8_t value87 = BUS8_RDP(c, (uint16_t)(x20 + 0x1E49));
                BUS8_SET(c, 0x002143, value87);
                BUS8_SET(c, 0x002140, 0);
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value88 = BUS8(c, 0x002140);
                    if (!(value88 != 0)) break;
                }
                RAM8(0x1E10) = 1;
                uint8_t a_hi22 = a_hi21;
                uint16_t x21 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint8_t value89 = BUS8_RDP(c, (uint16_t)(x21 + 0x1ECA));
                    if (value89 != 0) {
                        BUS8_SET(c, 0x001E28 + RAM16(0x1E24), value89);
                        RAM8(0x0000 + sp0 - 0x0A) = x21 >> 8;
                        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x21;
                        RAM8(0x0000 + sp0 - 0x0C) = 0;
                        RAM8(0x0000 + sp0 - 0x0D) = ((a_hi22 << 8) | (uint8_t)(value89 - 1)) & 0xFF;
                        RAM16_SET(0x1EEA, (((a_hi22 << 8) | (uint8_t)(value89 - 1)) & 0xFF) << 1);
                        uint16_t value91 = RAM16(0x1EEA);
                        uint8_t value92 = BUS8(c, 0xC33DF9 + (uint16_t)((((a_hi22 << 8) | (uint8_t)(value89 - 1)) & 0xFF) + value91));
                        RAM8(0x1E14) = value92;
                        uint8_t value93 = BUS8(c, 0xC33DFA + (uint16_t)((((a_hi22 << 8) | (uint8_t)(value89 - 1)) & 0xFF) + value91));
                        RAM8(0x1E15) = value93;
                        uint8_t value94 = BUS8(c, 0xC33DFB + (uint16_t)((((a_hi22 << 8) | (uint8_t)(value89 - 1)) & 0xFF) + value91));
                        RAM8(0x1E16) = value94;
                        uint16_t value95 = RAM16(0x1E14);
                        RAM8(0x1E14) = 0;
                        RAM8(0x1E15) = 0;
                        uint8_t value96 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + value95, RAM8(0x1E16));
                        if ((uint16_t)(value95 + 1) == 0) {
                            RAM8(0x1E16)++;
                        }
                        uint8_t value97 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(value95 + 1), RAM8(0x1E16));
                        if ((uint16_t)(value95 + 2) == 0) {
                            RAM8(0x1E16)++;
                        }
                        RAM8(0x0000 + sp0 - 0x0C) = value97;
                        RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)((value97 << 8) | value96);
                        uint16_t value98 = RAM16(0x1E24);
                        BUS16_SET(c, (uint16_t)(value98 + 0x1E6A), (value97 << 8) | value96);
                        uint16_t value99 = BUS16_RDP(c, (uint16_t)(value98 + 0x1E48));
                        BUS16_SET(c, (uint16_t)(value98 + 0x1E4A), (uint16_t)(((value97 << 8) | value96) + value99));
                        RAM16_SET(0x1E24, (uint16_t)(value98 + 2));
                        uint8_t value100 = RAM8(0x0000 + sp0 - 0x0D);
                        uint8_t value101 = RAM8(0x0000 + sp0 - 0x0C);
                        uint8_t a_hi23 = (uint16_t)(((value97 << 8) | value96) + value99) >> 8;
                        uint16_t x22 = (value101 << 8) | value100;
                        uint16_t y5 = (uint16_t)(value95 + 2);
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint8_t value102 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + y5, RAM8(0x1E16));
                            BUS8_SET(c, 0x002141, value102);
                            if ((uint16_t)(y5 + 1) == 0) {
                                RAM8(0x1E16)++;
                            }
                            uint8_t value103 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(y5 + 1), RAM8(0x1E16));
                            BUS8_SET(c, 0x002142, value103);
                            if ((uint16_t)(y5 + 2) == 0) {
                                RAM8(0x1E16)++;
                            }
                            uint8_t value104 = BUS8_RDL(c, (RAM8(0x1E16) << 0x10) + RAM16(0x1E14) + (uint16_t)(y5 + 2), RAM8(0x1E16));
                            BUS8_SET(c, 0x002143, value104);
                            if ((uint16_t)(y5 + 3) == 0) {
                                RAM8(0x1E16)++;
                            }
                            uint8_t value105 = RAM8(0x1E10);
                            BUS8_SET(c, 0x002140, value105);
                            for (;;) {
                                LOOP_GUARD(loop_guard);
                                uint8_t value106 = BUS8(c, 0x002140);
                                if (!(value105 != value106)) break;
                            }
                            RAM8(0x1E10)++;
                            if (RAM8(0x1E10) == 0) {
                                RAM8(0x1E10)++;
                            }
                            x22 = (uint16_t)(x22 - 3);
                            y5 = (uint16_t)(y5 + 3);
                            if (!(x22 != 0)) break;
                        }
                        uint8_t value107 = RAM8(0x0000 + sp0 - 0x0B);
                        uint8_t value108 = RAM8(0x0000 + sp0 - 0x0A);
                        a_hi22 = a_hi23;
                        x21 = (uint16_t)(((value108 << 8) | value107) + 2);
                        continue;
                    }
                    break;
                }
                m_flag = 1;
                a_hi24 = a_hi22;
            } else {
                m_flag = 0;
                a_hi24 = value34 >> 8;
            }
            uint16_t value109 = RAM16(0x1EAA);
            bool m_flag2;
            uint8_t a_hi29;
            uint16_t direct_page;
            if (value109 != 0) {
                RAM16_SET(0x1E14, 0x1EAA);
                RAM16_SET(0x1E16, 0x1F00);
                RAM16_SET(0x1E18, 0x1F40);
                RAM16_SET(0x1E1A, 0x1FC0);
                uint8_t a_hi25 = 0x1F;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    uint16_t value110 = BUS16_RDP(c, RAM16(0x1E14));
                    if (value110 != 0) {
                        RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                        RAM16_SET(0x1E14, (uint16_t)(RAM16(0x1E14) + 1));
                        uint16_t y6 = 0;
                        for (;;) {
                            LOOP_GUARD(loop_guard);
                            uint16_t value111 = BUS16(c, 0x001E28 + y6);
                            if (value110 != value111) {
                                y6 = (uint16_t)(y6 + 2);
                                continue;
                            }
                            break;
                        }
                        uint16_t value112 = BUS16(c, 0xC33E9E + (uint16_t)((uint16_t)(value110 - 1) << 1));
                        BUS16_SET(c, RAM16(0x1E16), value112);
                        RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                        RAM16_SET(0x1E16, (uint16_t)(RAM16(0x1E16) + 1));
                        uint16_t value113 = BUS16(c, 0x001E48 + y6);
                        BUS16_SET(c, RAM16(0x1E18), value113);
                        RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                        RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                        uint16_t value114 = BUS16(c, 0xC33E5C + (uint16_t)((uint16_t)(value110 - 1) << 1));
                        BUS16_SET(c, RAM16(0x1E18), (uint16_t)(value113 + value114));
                        RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                        RAM16_SET(0x1E18, (uint16_t)(RAM16(0x1E18) + 1));
                        uint16_t value115 = BUS16(c, 0xC33EE0 + (uint16_t)((uint16_t)(value110 - 1) << 1));
                        BUS16_SET(c, RAM16(0x1E1A), value115);
                        RAM16_SET(0x1E1A, (uint16_t)(RAM16(0x1E1A) + 1));
                        RAM16_SET(0x1E1A, (uint16_t)(RAM16(0x1E1A) + 1));
                        a_hi25 = value115 >> 8;
                        continue;
                    }
                    a_hi25 = value110 >> 8;
                    break;
                }
                BUS8_SET(c, 0x002141, 2);
                RAM8(0x0000 + sp0 - 0x0A) = 0x1F;
                RAM8(0x0000 + sp0 - 0x0B) = 0;
                BUS16_SET(c, 0x002142, 0x1840);
                uint8_t a6 = 0;
                uint8_t a_hi26 = a_hi25;
                uint16_t x23 = 0xFFFE;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    BUS8_SET(c, 0x002140, a6);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value116 = BUS8(c, 0x002140);
                        if (!(a6 != value116)) break;
                    }
                    if ((uint16_t)(x23 + 2) != 0x40) {
                        uint16_t value117 = BUS16_RDP(c, (uint16_t)(x23 + 0x1F02));
                        BUS16_SET(c, 0x002142, value117);
                        a6 = (uint8_t)(a6 + 1);
                        x23 = (uint16_t)(x23 + 2);
                        continue;
                    }
                    a6 = (uint8_t)(a6 + 1);
                    x23 = (uint16_t)(x23 + 2);
                    break;
                }
                BUS16_SET(c, 0x002142, 0x1980);
                uint8_t a7 = 0;
                uint8_t a_hi27 = a_hi26;
                uint16_t x24 = 0xFFFE;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    BUS8_SET(c, 0x002140, a7);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value118 = BUS8(c, 0x002140);
                        if (!(a7 != value118)) break;
                    }
                    if ((uint16_t)(x24 + 2) != 0x80) {
                        uint16_t value119 = BUS16_RDP(c, (uint16_t)(x24 + 0x1F42));
                        BUS16_SET(c, 0x002142, value119);
                        a7 = (uint8_t)(a7 + 1);
                        x24 = (uint16_t)(x24 + 2);
                        continue;
                    }
                    a7 = (uint8_t)(a7 + 1);
                    x24 = (uint16_t)(x24 + 2);
                    break;
                }
                BUS16_SET(c, 0x002142, 0x18C0);
                uint8_t a8 = 0;
                uint8_t a_hi28 = a_hi27;
                uint16_t x25 = 0xFFFE;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    BUS8_SET(c, 0x002140, a8);
                    for (;;) {
                        LOOP_GUARD(loop_guard);
                        uint8_t value120 = BUS8(c, 0x002140);
                        if (!(a8 != value120)) break;
                    }
                    if ((uint16_t)(x25 + 2) != 0x40) {
                        uint16_t value121 = BUS16_RDP(c, (uint16_t)(x25 + 0x1FC2));
                        BUS16_SET(c, 0x002142, value121);
                        a8 = (uint8_t)(a8 + 1);
                        x25 = (uint16_t)(x25 + 2);
                        continue;
                    }
                    a8 = (uint8_t)(a8 + 1);
                    x25 = (uint16_t)(x25 + 2);
                    break;
                }
                m_flag2 = 1;
                a_hi29 = a_hi28;
                direct_page = 0x1F00;
            } else {
                m_flag2 = 0;
                a_hi29 = value109 >> 8;
                direct_page = 0x1E00;
            }
            BUS8_SET(c, 0x002141, 0);
            BUS8_SET(c, 0x002140, 0);
            a_hi30 = a_hi29;
            direct_page2 = direct_page;
        }
        uint8_t value122 = RAM8(0x0000 + sp0 - 9);
        uint8_t value123 = RAM8(0x0000 + sp0 - 8);
        uint8_t value124 = RAM8(0x0000 + sp0 - 7);
        uint8_t value125 = RAM8(0x0000 + sp0 - 6);
        uint8_t value126 = RAM8(0x0000 + sp0 - 5);
        uint8_t value127 = RAM8(0x0000 + sp0 - 4);
        uint8_t value128 = RAM8(0x0000 + sp0 - 3);
        uint8_t value129 = RAM8(0x0000 + sp0 - 2);
        uint8_t value130 = RAM8(0x0000 + sp0 - 1);
        uint8_t value131 = RAM8(0x0000 + sp0);
        r->a = (value127 << 8) | value126;
        r->x = (value125 << 8) | value124;
        r->y = (value123 << 8) | value122;
        r->c = value128 & 0x01;
        r->z = value131 == 0;
        r->n = value131 & 0x80;
        r->v = value128 & 0x40;
        r->mf = value128 & 0x20;
        r->xf = value128 & 0x10;
        r->db = value131;
        r->dp = (value130 << 8) | value129;
        r->i = value128 & 0x04;
        r->d = value128 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    if (value >= 0x70) {
        r->a = (a_hi << 8) | value;
        r->x = 0x1E00;
        r->c = value >= 0x70;
        r->z = value == 0x70;
        r->n = (uint8_t)(value - 0x70) & 0x80;
        r->db = 0;
        r->dp = 0x1E00;
        TAIL_CALL_FRAME(c, 0xC305F3, SOM_RTL, 10); /* expand_music_command_preset_and_dispatch_requested_song */
    }
    r->a = (a_hi << 8) | value;
    r->x = 0x1E00;
    r->c = value >= 0x70;
    r->z = value == 0x70;
    r->n = (uint8_t)(value - 0x70) & 0x80;
    r->db = 0;
    r->dp = 0x1E00;
    TAIL_CALL_FRAME(c, 0xC3059F, SOM_RTL, 10); /* send_non_music_audio_command_packet */
}
SOM_REGISTER(0xC30160, SOM_RTL, "gen", upload_six_spc_blocks_or_reset_ready_audio_metadata_at_C30160, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 14, 1, 0, 1087, 538)

/* SOM_POLL_HOOK */

/* C30175 entry_C30175   [class D, 1066 bytes, 523 instructions]
 * Source: src/rom/upload_six_spc_blocks_or_reset_ready_audio_metadata.s
 * Interior entry C30175 of upload_six_spc_blocks_or_reset_ready_audio_metadata, same file.
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void upload_six_spc_blocks_or_reset_ready_audio_metadata_at_C30175(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 10;
    uint64_t loop_guard = 0;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_018d = 0;
    uint16_t direct_page_018d = 0;
    uint8_t a_0187 = 0;
    uint8_t a_hi_0187 = 0;
    uint16_t x_0187 = 0;
    uint16_t y_0187 = 0;
    bool carry_0187 = 0;
    bool zero_0187 = 0;
    bool negative_0187 = 0;
    bool overflow_0187 = 0;
    uint8_t a_hi_01ca = 0;
    bool overflow_01ca = 0;
    uint8_t a_01b8 = 0;
    uint8_t a_hi_01b8 = 0;
    bool overflow_01b8 = 0;
    uint8_t a_hi_01d4 = 0;
    bool overflow_01d4 = 0;
    uint8_t a_01c0 = 0;
    uint8_t a_hi_01c0 = 0;
    bool overflow_01c0 = 0;
    uint8_t a_hi_01eb = 0;
    bool overflow_01eb = 0;
    uint8_t a_01f1 = 0;
    uint8_t a_hi_01f1 = 0;
    bool overflow_01f1 = 0;
    uint8_t a_01f9 = 0;
    uint8_t a_hi_01f9 = 0;
    bool overflow_01f9 = 0;
    uint8_t a_020f = 0;
    uint8_t a_hi_020f = 0;
    uint8_t a_020f2 = 0;
    uint8_t a_hi_020f2 = 0;
    uint8_t a_0219 = 0;
    uint8_t a_hi_0219 = 0;
    uint8_t a_hi_0250 = 0;
    uint16_t y_0250 = 0;
    uint8_t a_0258 = 0;
    uint8_t a_hi_0258 = 0;
    uint16_t y_0258 = 0;
    uint8_t a_hi_0264 = 0;
    uint16_t x_0264 = 0;
    uint16_t y_0264 = 0;
    uint8_t a_hi_0267 = 0;
    uint16_t x_0267 = 0;
    uint16_t y_0267 = 0;
    uint8_t a_hi_0271 = 0;
    uint16_t x_0271 = 0;
    uint16_t y_0271 = 0;
    uint8_t a_027b = 0;
    uint8_t a_hi_027b = 0;
    uint16_t x_027b = 0;
    uint16_t y_027b = 0;
    uint8_t a_027f = 0;
    uint8_t a_hi_027f = 0;
    uint16_t x_027f = 0;
    uint16_t y_027f = 0;
    uint8_t a_0288 = 0;
    uint8_t a_hi_0288 = 0;
    uint16_t x_0288 = 0;
    uint16_t y_0288 = 0;
    uint8_t a_hi_0292 = 0;
    uint16_t x_0292 = 0;
    uint8_t a_hi_02b6 = 0;
    uint16_t x_02b6 = 0;
    uint8_t a_02c3 = 0;
    uint8_t a_hi_02c3 = 0;
    uint16_t x_02c3 = 0;
    uint16_t y_02c3 = 0;
    uint8_t a_hi_02da = 0;
    uint16_t x_02da = 0;
    uint8_t a_hi_02ee = 0;
    uint16_t x_02ee = 0;
    uint8_t a_hi_04c2 = 0;
    uint8_t a_hi_0328 = 0;
    uint16_t y_0328 = 0;
    bool carry_0328 = 0;
    uint8_t a_hi_0338 = 0;
    uint16_t x_0338 = 0;
    uint8_t a_hi_04df = 0;
    uint8_t a_hi_0592 = 0;
    uint8_t a_hi_034e = 0;
    uint8_t a_hi_0400 = 0;
    uint8_t a_04ea = 0;
    uint8_t a_hi_04ea = 0;
    uint16_t y_04ea = 0;
    uint8_t a_053e = 0;
    uint8_t a_hi_053e = 0;
    uint16_t x_053e = 0;
    uint8_t a_hi_0351 = 0;
    uint16_t x_0351 = 0;
    uint8_t a_hi_040a = 0;
    uint16_t x_040a = 0;
    uint8_t a_0541 = 0;
    uint8_t a_hi_0541 = 0;
    uint16_t x_0541 = 0;
    uint8_t a_hi_0359 = 0;
    uint16_t x_0359 = 0;
    uint8_t a_0423 = 0;
    uint8_t a_hi_0423 = 0;
    uint8_t a_0560 = 0;
    uint8_t a_hi_0560 = 0;
    uint16_t x_0560 = 0;
    uint8_t a_hi_035e = 0;
    uint16_t x_035e = 0;
    uint8_t a_hi_042e = 0;
    uint16_t x_042e = 0;
    uint8_t a_0563 = 0;
    uint8_t a_hi_0563 = 0;
    uint16_t x_0563 = 0;
    uint8_t a_hi_0369 = 0;
    uint16_t x_0369 = 0;
    uint8_t a_hi_046e = 0;
    uint16_t y_046e = 0;
    uint8_t a_hi_04c22 = 0;
    uint8_t a_0582 = 0;
    uint8_t a_hi_0582 = 0;
    uint16_t x_0582 = 0;
    uint8_t a_hi_0387 = 0;
    uint16_t y_0387 = 0;
    uint8_t a_hi_036d = 0;
    uint16_t x_036d = 0;
    uint8_t a_0475 = 0;
    uint8_t a_hi_0475 = 0;
    uint16_t y_0475 = 0;
    uint8_t a_0585 = 0;
    uint8_t a_hi_0585 = 0;
    uint16_t x_0585 = 0;
    uint8_t a_hi_039b = 0;
    uint16_t x_039b = 0;
    uint16_t y_039b = 0;
    uint8_t a_hi_038c = 0;
    uint16_t y_038c = 0;
    uint8_t a_hi_0489 = 0;
    uint16_t x_0489 = 0;
    uint16_t y_0489 = 0;
    uint8_t a_hi_05922 = 0;
    uint8_t a_03b6 = 0;
    uint8_t a_hi_03b6 = 0;
    uint16_t x_03b6 = 0;
    uint16_t y_03b6 = 0;
    uint8_t a_hi_03f6 = 0;
    uint16_t y_03f6 = 0;
    uint8_t a_hi_0493 = 0;
    uint16_t x_0493 = 0;
    uint16_t y_0493 = 0;
    uint8_t a_03cc = 0;
    uint8_t a_hi_03cc = 0;
    uint16_t x_03cc = 0;
    uint16_t y_03cc = 0;
    uint8_t a_hi_03f7 = 0;
    uint16_t x_03f7 = 0;
    uint8_t a_hi_049d = 0;
    uint16_t x_049d = 0;
    uint16_t y_049d = 0;
    uint8_t a_03eb = 0;
    uint8_t a_hi_03eb = 0;
    uint16_t y_03eb = 0;
    uint8_t a_hi_04a7 = 0;
    uint16_t x_04a7 = 0;
    uint16_t y_04a7 = 0;
    uint8_t a_04ac = 0;
    uint8_t a_hi_04ac = 0;
    uint16_t x_04ac = 0;
    uint16_t y_04ac = 0;
    uint8_t a_hi_04b7 = 0;
    uint16_t x_04b7 = 0;
    uint16_t y_04b7 = 0;
    uint8_t value = BUS8_RDP(c, dp);
    BUS8_SET(c, dp, 0);
    if (value == 0) {
        a_hi_018d = a_hi;
        direct_page_018d = dp;
        goto shared_018D;
    }
    if (value & 0x80) {
        a_0187 = value;
        a_hi_0187 = a_hi;
        x_0187 = x;
        y_0187 = y;
        carry_0187 = carry;
        zero_0187 = value == 0;
        negative_0187 = value & 0x80;
        overflow_0187 = overflow;
        goto shared_0187;
    }
    if (value == 1) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 2));
        RAM8(0x0000 + sp0 - 0x0A) = value2 & 0x0F;
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 1));
        RAM8(0x0000 + sp0 - 0x0B) = value3;
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 5));
        if ((((value2 & 0x0F) << 8) | value3) == value4) {
            a_hi_018d = value;
            direct_page_018d = dp;
            goto shared_018D;
        }
        if (RAM8(0x2142) == 0) {
            a_hi_01ca = value;
            overflow_01ca = overflow;
            goto shared_01CA;
        }
        uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 2));
        if ((value6 & 0xF0) == 0) {
            a_hi_01ca = value;
            overflow_01ca = overflow;
            goto shared_01CA;
        }
        RAM8(0x2141) = value6 & 0xF0;
        a_01b8 = 0x83;
        a_hi_01b8 = value;
        overflow_01b8 = overflow;
        goto shared_01B8;
    }
    if (value >= 0x70) {
        r->a = (a_hi << 8) | value;
        r->c = value >= 0x70;
        r->z = value == 0x70;
        r->n = (uint8_t)(value - 0x70) & 0x80;
        TAIL_CALL(c, 0xC305F3, SOM_RTL); /* expand_music_command_preset_and_dispatch_requested_song */
    }
    a_0187 = value;
    a_hi_0187 = a_hi;
    x_0187 = x;
    y_0187 = y;
    carry_0187 = value >= 0x70;
    zero_0187 = value == 0x70;
    negative_0187 = (uint8_t)(value - 0x70) & 0x80;
    overflow_0187 = overflow;
    shared_0187:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_0187 << 8) | a_0187;
    r->x = x_0187;
    r->y = y_0187;
    r->c = carry_0187;
    r->z = zero_0187;
    r->n = negative_0187;
    r->v = overflow_0187;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    TAIL_CALL(c, 0xC3059F, SOM_RTL); /* send_non_music_audio_command_packet */
    shared_018D:;
    LOOP_GUARD(loop_guard);
    uint8_t value7 = RAM8(0x0000 + sp0 - 9);
    uint8_t value8 = RAM8(0x0000 + sp0 - 8);
    uint8_t value9 = RAM8(0x0000 + sp0 - 7);
    uint8_t value10 = RAM8(0x0000 + sp0 - 6);
    uint8_t value11 = RAM8(0x0000 + sp0 - 5);
    uint8_t value12 = RAM8(0x0000 + sp0 - 4);
    uint8_t value13 = RAM8(0x0000 + sp0 - 3);
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->a = (value12 << 8) | value11;
    r->x = (value10 << 8) | value9;
    r->y = (value8 << 8) | value7;
    r->c = value13 & 0x01;
    r->z = value16 == 0;
    r->n = value16 & 0x80;
    r->v = value13 & 0x40;
    r->mf = value13 & 0x20;
    r->xf = value13 & 0x10;
    r->db = value16;
    r->dp = (value15 << 8) | value14;
    r->i = value13 & 0x04;
    r->d = value13 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    r->sp += 10;
    RETURN_RTL(c);
    shared_01CA:;
    LOOP_GUARD(loop_guard);
    uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp + 5));
    if (value17 & 0x80) {
        a_hi_01d4 = a_hi_01ca;
        overflow_01d4 = overflow_01ca;
        goto shared_01D4;
    }
    BUS8_SET(c, (uint16_t)(dp + 9), value17);
    uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp + 6));
    BUS16_SET(c, (uint16_t)(dp + 0x0A), value18);
    a_hi_01d4 = a_hi_01ca;
    overflow_01d4 = overflow_01ca;
    goto shared_01D4;
    shared_01B8:;
    LOOP_GUARD(loop_guard);
    if (a_01b8 == RAM8(0x2140)) {
        goto shared_01B8;
    }
    RAM8(0x2140) = a_01b8;
    a_01c0 = a_01b8;
    a_hi_01c0 = a_hi_01b8;
    overflow_01c0 = overflow_01b8;
    goto shared_01C0;
    shared_01D4:;
    LOOP_GUARD(loop_guard);
    uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp + 1));
    RAM8(0x2141) = value20;
    BUS8_SET(c, (uint16_t)(dp + 5), value20);
    uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp + 2));
    RAM8(0x2142) = value21;
    BUS8_SET(c, (uint16_t)(dp + 6), value21 & 0x0F);
    uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp + 3));
    RAM8(0x2143) = value22;
    BUS8_SET(c, (uint16_t)(dp + 7), value22);
    a_hi_01eb = a_hi_01d4;
    overflow_01eb = overflow_01d4;
    goto shared_01EB;
    shared_01C0:;
    LOOP_GUARD(loop_guard);
    if (a_01c0 != RAM8(0x2140)) {
        goto shared_01C0;
    }
    RAM8(0x2140) = 0;
    a_hi_01ca = a_hi_01c0;
    overflow_01ca = overflow_01c0;
    goto shared_01CA;
    shared_01EB:;
    LOOP_GUARD(loop_guard);
    uint8_t value24 = RAM8(0x2141);
    if (value24 != 0) {
        goto shared_01EB;
    }
    a_01f1 = a_hi_01eb;
    a_hi_01f1 = value24;
    overflow_01f1 = overflow_01eb;
    goto shared_01F1;
    shared_01F1:;
    LOOP_GUARD(loop_guard);
    if (a_01f1 == RAM8(0x2140)) {
        goto shared_01F1;
    }
    RAM8(0x2140) = a_01f1;
    a_01f9 = a_01f1;
    a_hi_01f9 = a_hi_01f1;
    overflow_01f9 = overflow_01f1;
    goto shared_01F9;
    shared_01F9:;
    LOOP_GUARD(loop_guard);
    uint8_t value26 = RAM8(0x2140);
    if (a_01f9 != value26) {
        goto shared_01F9;
    }
    r->a = ((uint8_t)(a_01f9 + 1) << 8) | a_hi_01f9;
    r->c = a_01f9 >= value26;
    r->z = a_hi_01f9 == 0;
    r->n = a_hi_01f9 & 0x80;
    r->v = overflow_01f9;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0202, 0xC3060A); GUARD_JSR(c, sp_call, 0x0202); } /* configure_music_echo_and_evict_samples_above_echo_limit */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    RAM8(0x2141) = 2;
    uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0xF3));
    if (value27 == 0) {
        if (x_ret) {
            a_020f = value27;
            a_hi_020f = a_all >> 8;
            goto shared_020F;
        } else {
            a_020f2 = value27;
            a_hi_020f2 = a_all >> 8;
            goto shared_020F_1;
        }
    }
    r->a = (a_all >> 8 << 8) | value27;
    r->z = value27 == 0;
    r->n = value27 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x020E, 0xC3067E); GUARD_JSR(c, sp_call, 0x020E); } /* transfer_fixed_extra_music_data_to_apu_address_2c00 */
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    a_020f2 = (uint8_t)a_all2;
    a_hi_020f2 = a_all2 >> 8;
    goto shared_020F_1;
    shared_020F:;
    LOOP_GUARD(loop_guard);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_020F_1:;
    LOOP_GUARD(loop_guard);
    RAM16_SET(0x2142, 0x1A00);
    RAM8(0x2140) = a_hi_020f2;
    a_0219 = a_hi_020f2;
    a_hi_0219 = a_020f2;
    goto shared_0219;
    shared_0219:;
    LOOP_GUARD(loop_guard);
    if (a_0219 != RAM8(0x2140)) {
        goto shared_0219;
    }
    uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp + 5));
    RAM8(0x0000 + sp0 - 0x0A) = 0;
    RAM8(0x0000 + sp0 - 0x0B) = value29 & 0xFF;
    BUS16_SET(c, (uint16_t)(dp + 0xEA), (value29 & 0xFF) << 1);
    uint8_t value30 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value31 = RAM8(0x0000 + sp0 - 0x0A);
    uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp + 0xEA));
    uint8_t value33 = BUS8(c, 0xC33D39 + (uint16_t)(((value31 << 8) | value30) + value32));
    BUS8_SET(c, (uint16_t)(dp + 0x14), value33);
    uint8_t value34 = BUS8(c, 0xC33D3A + (uint16_t)(((value31 << 8) | value30) + value32));
    BUS8_SET(c, (uint16_t)(dp + 0x15), value34);
    uint8_t value35 = BUS8(c, 0xC33D3B + (uint16_t)(((value31 << 8) | value30) + value32));
    BUS8_SET(c, (uint16_t)(dp + 0x16), value35);
    uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    BUS8_SET(c, (uint16_t)(dp + 0x14), 0);
    BUS8_SET(c, (uint16_t)(dp + 0x15), 0);
    uint8_t value37 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + value36, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    if ((uint16_t)(value36 + 1) != 0) {
        a_hi_0250 = value37;
        y_0250 = (uint16_t)(value36 + 1);
        goto shared_0250;
    }
    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value38 + 1));
    a_hi_0250 = value37;
    y_0250 = (uint16_t)(value36 + 1);
    goto shared_0250;
    shared_0250:;
    LOOP_GUARD(loop_guard);
    uint8_t value39 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_0250, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    RAM8(0x0000 + sp0 - 0x0A) = value39;
    if ((uint16_t)(y_0250 + 1) != 0) {
        a_0258 = value39;
        a_hi_0258 = a_hi_0250;
        y_0258 = (uint16_t)(y_0250 + 1);
        goto shared_0258;
    }
    uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value40 + 1));
    a_0258 = value39;
    a_hi_0258 = a_hi_0250;
    y_0258 = (uint16_t)(y_0250 + 1);
    goto shared_0258;
    shared_0258:;
    LOOP_GUARD(loop_guard);
    RAM8(0x0000 + sp0 - 0x0B) = a_hi_0258;
    uint8_t value41 = RAM8(0x0000 + sp0 - 0x0A);
    BUS8_SET(c, (uint16_t)(dp + 0xF3), 0);
    if (((value41 << 8) | a_hi_0258) < 0x1200) {
        a_hi_0264 = a_0258;
        x_0264 = (value41 << 8) | a_hi_0258;
        y_0264 = y_0258;
        goto shared_0264;
    }
    uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp + 0xF3));
    BUS8_SET(c, (uint16_t)(dp + 0xF3), (uint8_t)(value42 + 1));
    a_hi_0264 = a_0258;
    x_0264 = (value41 << 8) | a_hi_0258;
    y_0264 = y_0258;
    goto shared_0264;
    shared_0264:;
    LOOP_GUARD(loop_guard);
    a_hi_0267 = 0x80;
    x_0267 = x_0264;
    y_0267 = y_0264;
    goto shared_0267;
    shared_0267:;
    LOOP_GUARD(loop_guard);
    uint8_t value43 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_0267, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    RAM8(0x2142) = value43;
    if ((uint16_t)(y_0267 + 1) != 0) {
        a_hi_0271 = a_hi_0267;
        x_0271 = x_0267;
        y_0271 = (uint16_t)(y_0267 + 1);
        goto shared_0271;
    }
    uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value44 + 1));
    a_hi_0271 = a_hi_0267;
    x_0271 = x_0267;
    y_0271 = (uint16_t)(y_0267 + 1);
    goto shared_0271;
    shared_0271:;
    LOOP_GUARD(loop_guard);
    uint8_t value45 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_0271, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    RAM8(0x2143) = value45;
    if ((uint16_t)(y_0271 + 1) != 0) {
        a_027b = value45;
        a_hi_027b = a_hi_0271;
        x_027b = x_0271;
        y_027b = (uint16_t)(y_0271 + 1);
        goto shared_027B;
    }
    uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value46 + 1));
    a_027b = value45;
    a_hi_027b = a_hi_0271;
    x_027b = x_0271;
    y_027b = (uint16_t)(y_0271 + 1);
    goto shared_027B;
    shared_027B:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2140) = a_hi_027b;
    a_027f = a_hi_027b;
    a_hi_027f = a_027b;
    x_027f = x_027b;
    y_027f = y_027b;
    goto shared_027F;
    shared_027F:;
    LOOP_GUARD(loop_guard);
    if (a_027f != RAM8(0x2140)) {
        goto shared_027F;
    }
    if ((uint8_t)(a_027f + 1) != 0) {
        a_0288 = (uint8_t)(a_027f + 1);
        a_hi_0288 = a_hi_027f;
        x_0288 = x_027f;
        y_0288 = y_027f;
        goto shared_0288;
    }
    a_0288 = (uint8_t)(a_027f + 2);
    a_hi_0288 = a_hi_027f;
    x_0288 = x_027f;
    y_0288 = y_027f;
    goto shared_0288;
    shared_0288:;
    LOOP_GUARD(loop_guard);
    if (!((uint16_t)(x_0288 - 2) & 0x8000)) {
        a_hi_0267 = a_0288;
        x_0267 = (uint16_t)(x_0288 - 2);
        y_0267 = y_0288;
        goto shared_0267;
    }
    a_hi_0292 = a_0288;
    x_0292 = 0;
    goto shared_0292;
    shared_0292:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(dp + 0x8A + x_0292), 0);
    BUS16_SET(c, (uint16_t)(dp + 0xCA + x_0292), 0);
    if ((uint16_t)(x_0292 + 2) != 0x20) {
        x_0292 = (uint16_t)(x_0292 + 2);
        goto shared_0292;
    }
    uint16_t value48 = BUS16_RDP(c, (uint16_t)(dp + 4));
    BUS16_SET(c, (uint16_t)(dp + 0x12), ((value48 & 0xFF00) >> 3) + 0x20);
    BUS16_SET(c, (uint16_t)(dp + 0x14), 0x1EAA);
    BUS16_SET(c, (uint16_t)(dp + 0x16), 0x1ECA);
    a_hi_02b6 = 0x1E;
    x_02b6 = (value48 & 0xFF00) >> 3;
    goto shared_02B6;
    shared_02B6:;
    LOOP_GUARD(loop_guard);
    uint16_t value49 = BUS16(c, 0xC33F22 + x_02b6);
    BUS16_SET(c, BUS16_RDP(c, (uint16_t)(dp + 0x14)) + 0x7E0000, value49);
    uint16_t value50 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x14), (uint16_t)(value50 + 1));
    uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x14), (uint16_t)(value51 + 1));
    a_02c3 = (uint8_t)value49;
    a_hi_02c3 = value49 >> 8;
    x_02c3 = x_02b6;
    y_02c3 = 0;
    goto shared_02C3;
    shared_02C3:;
    LOOP_GUARD(loop_guard);
    if (((a_hi_02c3 << 8) | a_02c3) == RAM16(0x1E28 + y_02c3)) {
        RAM16_SET(0x1E8A + y_02c3, (a_hi_02c3 << 8) | a_02c3);
        a_hi_02da = a_hi_02c3;
        x_02da = x_02c3;
        goto shared_02DA;
    }
    if ((uint16_t)(y_02c3 + 2) != 0x20) {
        y_02c3 = (uint16_t)(y_02c3 + 2);
        goto shared_02C3;
    }
    BUS16_SET(c, BUS16_RDP(c, (uint16_t)(dp + 0x16)) + 0x7E0000, (a_hi_02c3 << 8) | a_02c3);
    uint16_t value53 = BUS16_RDP(c, (uint16_t)(dp + 0x16));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x16), (uint16_t)(value53 + 1));
    uint16_t value54 = BUS16_RDP(c, (uint16_t)(dp + 0x16));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x16), (uint16_t)(value54 + 1));
    a_hi_02da = a_hi_02c3;
    x_02da = x_02c3;
    goto shared_02DA;
    shared_02DA:;
    LOOP_GUARD(loop_guard);
    uint16_t value55 = BUS16_RDP(c, (uint16_t)(dp + 0x12));
    if ((uint16_t)(x_02da + 2) != value55) {
        a_hi_02b6 = a_hi_02da;
        x_02b6 = (uint16_t)(x_02da + 2);
        goto shared_02B6;
    }
    uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp + 0xCA));
    if (value56 != 0) {
        BUS16_SET(c, (uint16_t)(dp + 0x17), 0);
        a_hi_02ee = value56 >> 8;
        x_02ee = 0;
        goto shared_02EE;
    }
    a_hi_04c2 = value56 >> 8;
    goto shared_04C2;
    shared_02EE:;
    LOOP_GUARD(loop_guard);
    uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp + 0xCA + x_02ee));
    if (value57 != 0) {
        RAM8(0x0000 + sp0 - 0x0A) = x_02ee >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x_02ee;
        RAM8(0x0000 + sp0 - 0x0C) = 0;
        RAM8(0x0000 + sp0 - 0x0D) = ((a_hi_02ee << 8) | (uint8_t)(value57 - 1)) & 0xFF;
        BUS16_SET(c, (uint16_t)(dp + 0xEA), (((a_hi_02ee << 8) | (uint8_t)(value57 - 1)) & 0xFF) << 1);
        uint8_t value58 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value59 = RAM8(0x0000 + sp0 - 0x0C);
        uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp + 0xEA));
        uint8_t value61 = BUS8(c, 0xC33DF9 + (uint16_t)(((value59 << 8) | value58) + value60));
        BUS8_SET(c, (uint16_t)(dp + 0x14), value61);
        uint8_t value62 = BUS8(c, 0xC33DFA + (uint16_t)(((value59 << 8) | value58) + value60));
        BUS8_SET(c, (uint16_t)(dp + 0x15), value62);
        uint8_t value63 = BUS8(c, 0xC33DFB + (uint16_t)(((value59 << 8) | value58) + value60));
        BUS8_SET(c, (uint16_t)(dp + 0x16), value63);
        uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        BUS8_SET(c, (uint16_t)(dp + 0x14), 0);
        BUS8_SET(c, (uint16_t)(dp + 0x15), 0);
        uint8_t value65 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + value64, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
        uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp + 0x17));
        BUS8_SET(c, (uint16_t)(dp + 0x17), (uint8_t)(value65 + value66));
        if ((uint16_t)(value64 + 1) != 0) {
            a_hi_0328 = (uint16_t)(((value59 << 8) | value58) + value60) >> 8;
            y_0328 = (uint16_t)(value64 + 1);
            carry_0328 = value65 + value66 > 0xFF;
            goto shared_0328;
        }
        uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
        BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value67 + 1));
        a_hi_0328 = (uint16_t)(((value59 << 8) | value58) + value60) >> 8;
        y_0328 = (uint16_t)(value64 + 1);
        carry_0328 = value65 + value66 > 0xFF;
        goto shared_0328;
    }
    a_hi_0338 = a_hi_02ee;
    x_0338 = 0;
    goto shared_0338;
    shared_04C2:;
    LOOP_GUARD(loop_guard);
    uint16_t value68 = BUS16_RDP(c, (uint16_t)(dp + 0xAA));
    if (value68 != 0) {
        BUS16_SET(c, (uint16_t)(dp + 0x14), 0x1EAA);
        BUS16_SET(c, (uint16_t)(dp + 0x16), 0x1F00);
        BUS16_SET(c, (uint16_t)(dp + 0x18), 0x1F40);
        BUS16_SET(c, (uint16_t)(dp + 0x1A), 0x1FC0);
        a_hi_04df = 0x1F;
        goto shared_04DF;
    }
    a_hi_0592 = value68 >> 8;
    goto shared_0592;
    shared_0328:;
    LOOP_GUARD(loop_guard);
    uint8_t value69 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_0328, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp + 0x18));
    BUS8_SET(c, (uint16_t)(dp + 0x18), (uint8_t)(value69 + value70 + carry_0328));
    uint8_t value71 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value72 = RAM8(0x0000 + sp0 - 0x0A);
    a_hi_02ee = a_hi_0328;
    x_02ee = (uint16_t)(((value72 << 8) | value71) + 2);
    goto shared_02EE;
    shared_0338:;
    LOOP_GUARD(loop_guard);
    uint16_t value73 = BUS16_RDP(c, (uint16_t)(dp + 0x28 + x_0338));
    if (value73 != 0) {
        a_hi_0338 = value73 >> 8;
        x_0338 = (uint16_t)(x_0338 + 2);
        goto shared_0338;
    }
    uint16_t value74 = BUS16_RDP(c, (uint16_t)(dp + 0x48 + x_0338));
    uint16_t value75 = BUS16_RDP(c, (uint16_t)(dp + 0x17));
    if (value74 + value75 > 0xFFFF) {
        a_hi_034e = (uint16_t)(value74 + value75) >> 8;
        goto shared_034E;
    }
    uint16_t value76 = BUS16_RDP(c, (uint16_t)(dp + 0xF1));
    if ((uint16_t)(value74 + value75) >= value76) {
        a_hi_034e = (uint16_t)(value74 + value75) >> 8;
        goto shared_034E;
    }
    a_hi_0400 = (uint16_t)(value74 + value75) >> 8;
    goto shared_0400;
    shared_04DF:;
    LOOP_GUARD(loop_guard);
    uint16_t value77 = BUS16_RDP(c, BUS16_RDP(c, (uint16_t)(dp + 0x14)) + 0x7E0000);
    if (value77 != 0) {
        uint16_t value78 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        BUS16_RMW_SET(c, (uint16_t)(dp + 0x14), (uint16_t)(value78 + 1));
        uint16_t value79 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        BUS16_RMW_SET(c, (uint16_t)(dp + 0x14), (uint16_t)(value79 + 1));
        a_04ea = (uint8_t)value77;
        a_hi_04ea = value77 >> 8;
        y_04ea = 0;
        goto shared_04EA;
    }
    RAM8(0x2141) = 2;
    RAM8(0x0000 + sp0 - 0x0A) = 0x1F;
    RAM8(0x0000 + sp0 - 0x0B) = 0;
    RAM16_SET(0x2142, 0x1840);
    a_053e = 0;
    a_hi_053e = value77 >> 8;
    x_053e = 0xFFFE;
    goto shared_053E;
    shared_0592:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2141) = 0;
    RAM8(0x2140) = 0;
    a_hi_018d = a_hi_0592;
    direct_page_018d = dp;
    goto shared_018D;
    shared_034E:;
    LOOP_GUARD(loop_guard);
    a_hi_0351 = a_hi_034e;
    x_0351 = 0x1E;
    goto shared_0351;
    shared_0400:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2141) = 3;
    a_hi_040a = a_hi_0400;
    x_040a = 0;
    goto shared_040A;
    shared_04EA:;
    LOOP_GUARD(loop_guard);
    if (((a_hi_04ea << 8) | a_04ea) != RAM16(0x1E28 + y_04ea)) {
        y_04ea = (uint16_t)(y_04ea + 2);
        goto shared_04EA;
    }
    uint16_t value81 = BUS16(c, 0xC33E9E + (uint16_t)((uint16_t)(((a_hi_04ea << 8) | a_04ea) - 1) << 1));
    BUS16_SET(c, BUS16_RDP(c, (uint16_t)(dp + 0x16)) + 0x7E0000, value81);
    uint16_t value82 = BUS16_RDP(c, (uint16_t)(dp + 0x16));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x16), (uint16_t)(value82 + 1));
    uint16_t value83 = BUS16_RDP(c, (uint16_t)(dp + 0x16));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x16), (uint16_t)(value83 + 1));
    uint16_t value84 = RAM16(0x1E48 + y_04ea);
    BUS16_SET(c, BUS16_RDP(c, (uint16_t)(dp + 0x18)) + 0x7E0000, value84);
    uint16_t value85 = BUS16_RDP(c, (uint16_t)(dp + 0x18));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x18), (uint16_t)(value85 + 1));
    uint16_t value86 = BUS16_RDP(c, (uint16_t)(dp + 0x18));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x18), (uint16_t)(value86 + 1));
    uint16_t value87 = BUS16(c, 0xC33E5C + (uint16_t)((uint16_t)(((a_hi_04ea << 8) | a_04ea) - 1) << 1));
    BUS16_SET(c, BUS16_RDP(c, (uint16_t)(dp + 0x18)) + 0x7E0000, (uint16_t)(value84 + value87));
    uint16_t value88 = BUS16_RDP(c, (uint16_t)(dp + 0x18));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x18), (uint16_t)(value88 + 1));
    uint16_t value89 = BUS16_RDP(c, (uint16_t)(dp + 0x18));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x18), (uint16_t)(value89 + 1));
    uint16_t value90 = BUS16(c, 0xC33EE0 + (uint16_t)((uint16_t)(((a_hi_04ea << 8) | a_04ea) - 1) << 1));
    BUS16_SET(c, BUS16_RDP(c, (uint16_t)(dp + 0x1A)) + 0x7E0000, value90);
    uint16_t value91 = BUS16_RDP(c, (uint16_t)(dp + 0x1A));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x1A), (uint16_t)(value91 + 1));
    uint16_t value92 = BUS16_RDP(c, (uint16_t)(dp + 0x1A));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0x1A), (uint16_t)(value92 + 1));
    a_hi_04df = value90 >> 8;
    goto shared_04DF;
    shared_053E:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2140) = a_053e;
    a_0541 = a_053e;
    a_hi_0541 = a_hi_053e;
    x_0541 = x_053e;
    goto shared_0541;
    shared_0351:;
    LOOP_GUARD(loop_guard);
    uint16_t value93 = BUS16_RDP(c, (uint16_t)(dp + 0x88 + x_0351));
    if (value93 != 0) {
        a_hi_0359 = value93 >> 8;
        x_0359 = x_0351;
        goto shared_0359;
    }
    if ((uint16_t)(x_0351 - 2) != 0) {
        a_hi_0351 = value93 >> 8;
        x_0351 = (uint16_t)(x_0351 - 2);
        goto shared_0351;
    }
    a_hi_0359 = value93 >> 8;
    x_0359 = (uint16_t)(x_0351 - 2);
    goto shared_0359;
    shared_040A:;
    LOOP_GUARD(loop_guard);
    uint8_t value94 = BUS8_RDP(c, (uint16_t)(dp + 0x28 + x_040a));
    if (value94 != 0) {
        x_040a = (uint16_t)(x_040a + 2);
        goto shared_040A;
    }
    BUS16_SET(c, (uint16_t)(dp + 0x24), x_040a);
    uint8_t value95 = BUS8_RDP(c, (uint16_t)(dp + 0x48 + x_040a));
    RAM8(0x2142) = value95;
    uint8_t value96 = BUS8_RDP(c, (uint16_t)(dp + 0x49 + x_040a));
    RAM8(0x2143) = value96;
    RAM8(0x2140) = 0;
    a_0423 = 0;
    a_hi_0423 = a_hi_040a;
    goto shared_0423;
    shared_0541:;
    LOOP_GUARD(loop_guard);
    if (a_0541 != RAM8(0x2140)) {
        goto shared_0541;
    }
    if ((uint16_t)(x_0541 + 2) != 0x40) {
        uint16_t value98 = BUS16_RDP(c, (uint16_t)(x_0541 + 0x1F02));
        RAM16_SET(0x2142, value98);
        a_053e = (uint8_t)(a_0541 + 1);
        a_hi_053e = a_hi_0541;
        x_053e = (uint16_t)(x_0541 + 2);
        goto shared_053E;
    }
    RAM16_SET(0x2142, 0x1980);
    a_0560 = 0;
    a_hi_0560 = a_hi_0541;
    x_0560 = 0xFFFE;
    goto shared_0560;
    shared_0359:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(dp + 0x24), x_0359);
    a_hi_035e = a_hi_0359;
    x_035e = 0;
    goto shared_035E;
    shared_0423:;
    LOOP_GUARD(loop_guard);
    if (a_0423 != RAM8(0x2140)) {
        goto shared_0423;
    }
    BUS8_SET(c, (uint16_t)(dp + 0x10), (uint8_t)(a_0423 + 1));
    a_hi_042e = a_hi_0423;
    x_042e = 0;
    goto shared_042E;
    shared_0560:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2140) = a_0560;
    a_0563 = a_0560;
    a_hi_0563 = a_hi_0560;
    x_0563 = x_0560;
    goto shared_0563;
    shared_035E:;
    LOOP_GUARD(loop_guard);
    uint16_t value100 = BUS16_RDP(c, (uint16_t)(dp + 0x8A + x_035e));
    if (value100 == 0) {
        a_hi_0369 = value100 >> 8;
        x_0369 = x_035e;
        goto shared_0369;
    }
    if ((uint16_t)(x_035e + 2) != 0x20) {
        a_hi_035e = value100 >> 8;
        x_035e = (uint16_t)(x_035e + 2);
        goto shared_035E;
    }
    a_hi_0369 = value100 >> 8;
    x_0369 = (uint16_t)(x_035e + 2);
    goto shared_0369;
    shared_042E:;
    LOOP_GUARD(loop_guard);
    uint8_t value101 = BUS8_RDP(c, (uint16_t)(dp + 0xCA + x_042e));
    if (value101 != 0) {
        uint16_t value102 = BUS16_RDP(c, (uint16_t)(dp + 0x24));
        RAM8(0x1E28 + value102) = value101;
        RAM8(0x0000 + sp0 - 0x0A) = x_042e >> 8;
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)x_042e;
        RAM8(0x0000 + sp0 - 0x0C) = 0;
        RAM8(0x0000 + sp0 - 0x0D) = ((a_hi_042e << 8) | (uint8_t)(value101 - 1)) & 0xFF;
        BUS16_SET(c, (uint16_t)(dp + 0xEA), (((a_hi_042e << 8) | (uint8_t)(value101 - 1)) & 0xFF) << 1);
        uint8_t value103 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value104 = RAM8(0x0000 + sp0 - 0x0C);
        uint16_t value105 = BUS16_RDP(c, (uint16_t)(dp + 0xEA));
        uint8_t value106 = BUS8(c, 0xC33DF9 + (uint16_t)(((value104 << 8) | value103) + value105));
        BUS8_SET(c, (uint16_t)(dp + 0x14), value106);
        uint8_t value107 = BUS8(c, 0xC33DFA + (uint16_t)(((value104 << 8) | value103) + value105));
        BUS8_SET(c, (uint16_t)(dp + 0x15), value107);
        uint8_t value108 = BUS8(c, 0xC33DFB + (uint16_t)(((value104 << 8) | value103) + value105));
        BUS8_SET(c, (uint16_t)(dp + 0x16), value108);
        uint16_t value109 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        BUS8_SET(c, (uint16_t)(dp + 0x14), 0);
        BUS8_SET(c, (uint16_t)(dp + 0x15), 0);
        uint8_t value110 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + value109, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
        if ((uint16_t)(value109 + 1) != 0) {
            a_hi_046e = value110;
            y_046e = (uint16_t)(value109 + 1);
            goto shared_046E;
        }
        uint8_t value111 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
        BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value111 + 1));
        a_hi_046e = value110;
        y_046e = (uint16_t)(value109 + 1);
        goto shared_046E;
    }
    a_hi_04c22 = a_hi_042e;
    goto shared_04C2_1;
    shared_0563:;
    LOOP_GUARD(loop_guard);
    if (a_0563 != RAM8(0x2140)) {
        goto shared_0563;
    }
    if ((uint16_t)(x_0563 + 2) != 0x80) {
        uint16_t value113 = BUS16_RDP(c, (uint16_t)(x_0563 + 0x1F42));
        RAM16_SET(0x2142, value113);
        a_0560 = (uint8_t)(a_0563 + 1);
        a_hi_0560 = a_hi_0563;
        x_0560 = (uint16_t)(x_0563 + 2);
        goto shared_0560;
    }
    RAM16_SET(0x2142, 0x18C0);
    a_0582 = 0;
    a_hi_0582 = a_hi_0563;
    x_0582 = 0xFFFE;
    goto shared_0582;
    shared_0369:;
    LOOP_GUARD(loop_guard);
    uint16_t value114 = BUS16_RDP(c, (uint16_t)(dp + 0x24));
    if (x_0369 != value114) {
        RAM8(0x2141) = 7;
        BUS8_SET(c, (uint16_t)(dp + 0x10), 0);
        a_hi_0387 = a_hi_0369;
        y_0387 = 0;
        goto shared_0387;
    }
    a_hi_036d = a_hi_0369;
    x_036d = x_0369;
    goto shared_036D;
    shared_046E:;
    LOOP_GUARD(loop_guard);
    uint8_t value115 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_046e, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    if ((uint16_t)(y_046e + 1) != 0) {
        a_0475 = value115;
        a_hi_0475 = a_hi_046e;
        y_0475 = (uint16_t)(y_046e + 1);
        goto shared_0475;
    }
    uint8_t value116 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value116 + 1));
    a_0475 = value115;
    a_hi_0475 = a_hi_046e;
    y_0475 = (uint16_t)(y_046e + 1);
    goto shared_0475;
    shared_04C2_1:;
    LOOP_GUARD(loop_guard);
    uint16_t value117 = BUS16_RDP(c, (uint16_t)(dp + 0xAA));
    if (value117 != 0) {
        BUS16_SET(c, (uint16_t)(dp + 0x14), 0x1EAA);
        BUS16_SET(c, (uint16_t)(dp + 0x16), 0x1F00);
        BUS16_SET(c, (uint16_t)(dp + 0x18), 0x1F40);
        BUS16_SET(c, (uint16_t)(dp + 0x1A), 0x1FC0);
        a_hi_04df = 0x1F;
        goto shared_04DF;
    }
    a_hi_0592 = value117 >> 8;
    goto shared_0592;
    shared_0582:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2140) = a_0582;
    a_0585 = a_0582;
    a_hi_0585 = a_hi_0582;
    x_0585 = x_0582;
    goto shared_0585;
    shared_0387:;
    LOOP_GUARD(loop_guard);
    uint16_t value118 = RAM16(0x1E8A + y_0387);
    if (value118 == 0) {
        a_hi_039b = value118 >> 8;
        x_039b = y_0387;
        y_039b = y_0387;
        goto shared_039B;
    }
    a_hi_038c = value118 >> 8;
    y_038c = y_0387;
    goto shared_038C;
    shared_036D:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(dp + 0x28 + x_036d), 0);
    if ((uint16_t)(x_036d + 2) != 0x20) {
        x_036d = (uint16_t)(x_036d + 2);
        goto shared_036D;
    }
    a_hi_0400 = a_hi_036d;
    goto shared_0400;
    shared_0475:;
    LOOP_GUARD(loop_guard);
    RAM8(0x0000 + sp0 - 0x0C) = a_0475;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)((a_0475 << 8) | a_hi_0475);
    uint16_t value119 = BUS16_RDP(c, (uint16_t)(dp + 0x24));
    BUS16_SET(c, (uint16_t)(dp + 0x6A + value119), (a_0475 << 8) | a_hi_0475);
    uint16_t value120 = BUS16_RDP(c, (uint16_t)(dp + 0x48 + value119));
    BUS16_SET(c, (uint16_t)(dp + 0x4A + value119), (uint16_t)(((a_0475 << 8) | a_hi_0475) + value120));
    BUS16_SET(c, (uint16_t)(dp + 0x24), (uint16_t)(value119 + 2));
    uint8_t value121 = RAM8(0x0000 + sp0 - 0x0D);
    uint8_t value122 = RAM8(0x0000 + sp0 - 0x0C);
    a_hi_0489 = (uint16_t)(((a_0475 << 8) | a_hi_0475) + value120) >> 8;
    x_0489 = (value122 << 8) | value121;
    y_0489 = y_0475;
    goto shared_0489;
    shared_0585:;
    LOOP_GUARD(loop_guard);
    if (a_0585 != RAM8(0x2140)) {
        goto shared_0585;
    }
    if ((uint16_t)(x_0585 + 2) != 0x40) {
        uint16_t value124 = BUS16_RDP(c, (uint16_t)(x_0585 + 0x1FC2));
        RAM16_SET(0x2142, value124);
        a_0582 = (uint8_t)(a_0585 + 1);
        a_hi_0582 = a_hi_0585;
        x_0582 = (uint16_t)(x_0585 + 2);
        goto shared_0582;
    }
    a_hi_05922 = a_hi_0585;
    goto shared_0592_1;
    shared_039B:;
    LOOP_GUARD(loop_guard);
    uint16_t value125 = BUS16_RDP(c, (uint16_t)(dp + 0x24));
    if ((uint16_t)(x_039b + 2) != value125) {
        uint16_t value126 = BUS16_RDP(c, (uint16_t)(dp + 0x8A + (uint16_t)(x_039b + 2)));
        if (value126 != 0) {
            BUS16_SET(c, (uint16_t)(dp + 0x28 + (uint16_t)(x_039b + 2)), 0);
            BUS16_SET(c, (uint16_t)(dp + 0x8A + (uint16_t)(x_039b + 2)), 0);
            RAM16_SET(0x1E28 + y_039b, value126);
            uint16_t value127 = BUS16_RDP(c, (uint16_t)(dp + 0x48 + (uint16_t)(x_039b + 2)));
            RAM16_SET(0x2142, value127);
            uint8_t value128 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
            RAM8(0x2140) = value128;
            a_03b6 = value128;
            a_hi_03b6 = value127 >> 8;
            x_03b6 = (uint16_t)(x_039b + 2);
            y_03b6 = y_039b;
            goto shared_03B6;
        }
        a_hi_039b = value126 >> 8;
        x_039b = (uint16_t)(x_039b + 2);
        goto shared_039B;
    }
    a_hi_03f6 = a_hi_039b;
    y_03f6 = y_039b;
    goto shared_03F6;
    shared_038C:;
    LOOP_GUARD(loop_guard);
    uint16_t value129 = BUS16_RDP(c, (uint16_t)(dp + 0x24));
    if ((uint16_t)(y_038c + 2) != value129) {
        a_hi_0387 = a_hi_038c;
        y_0387 = (uint16_t)(y_038c + 2);
        goto shared_0387;
    }
    a_hi_03f6 = a_hi_038c;
    y_03f6 = (uint16_t)(y_038c + 2);
    goto shared_03F6;
    shared_0489:;
    LOOP_GUARD(loop_guard);
    uint8_t value130 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_0489, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    RAM8(0x2141) = value130;
    if ((uint16_t)(y_0489 + 1) != 0) {
        a_hi_0493 = a_hi_0489;
        x_0493 = x_0489;
        y_0493 = (uint16_t)(y_0489 + 1);
        goto shared_0493;
    }
    uint8_t value131 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value131 + 1));
    a_hi_0493 = a_hi_0489;
    x_0493 = x_0489;
    y_0493 = (uint16_t)(y_0489 + 1);
    goto shared_0493;
    shared_0592_1:;
    LOOP_GUARD(loop_guard);
    RAM8(0x2141) = 0;
    RAM8(0x2140) = 0;
    a_hi_018d = a_hi_05922;
    direct_page_018d = 0x1F00;
    goto shared_018D;
    shared_03B6:;
    LOOP_GUARD(loop_guard);
    if (a_03b6 != RAM8(0x2140)) {
        goto shared_03B6;
    }
    uint8_t value133 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    BUS8_SET(c, (uint16_t)(dp + 0x10), (uint8_t)(value133 + 1));
    uint16_t value134 = RAM16(0x1E48 + y_03b6);
    RAM16_SET(0x2142, value134);
    uint8_t value135 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    RAM8(0x2140) = value135;
    a_03cc = value135;
    a_hi_03cc = value134 >> 8;
    x_03cc = x_03b6;
    y_03cc = y_03b6;
    goto shared_03CC;
    shared_03F6:;
    LOOP_GUARD(loop_guard);
    a_hi_03f7 = a_hi_03f6;
    x_03f7 = y_03f6;
    goto shared_03F7;
    shared_0493:;
    LOOP_GUARD(loop_guard);
    uint8_t value136 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_0493, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    RAM8(0x2142) = value136;
    if ((uint16_t)(y_0493 + 1) != 0) {
        a_hi_049d = a_hi_0493;
        x_049d = x_0493;
        y_049d = (uint16_t)(y_0493 + 1);
        goto shared_049D;
    }
    uint8_t value137 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value137 + 1));
    a_hi_049d = a_hi_0493;
    x_049d = x_0493;
    y_049d = (uint16_t)(y_0493 + 1);
    goto shared_049D;
    shared_03CC:;
    LOOP_GUARD(loop_guard);
    if (a_03cc != RAM8(0x2140)) {
        goto shared_03CC;
    }
    uint8_t value139 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    BUS8_SET(c, (uint16_t)(dp + 0x10), (uint8_t)(value139 + 1));
    uint16_t value140 = BUS16_RDP(c, (uint16_t)(dp + 0x6A + x_03cc));
    RAM16_SET(0x2142, value140);
    RAM16_SET(0x1E6A + y_03cc, value140);
    uint16_t value141 = RAM16(0x1E48 + y_03cc);
    RAM16_SET(0x1E4A + y_03cc, (uint16_t)(value140 + value141));
    uint8_t value142 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    RAM8(0x2140) = value142;
    a_03eb = value142;
    a_hi_03eb = (uint16_t)(value140 + value141) >> 8;
    y_03eb = y_03cc;
    goto shared_03EB;
    shared_03F7:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (uint16_t)(dp + 0x28 + x_03f7), 0);
    if ((uint16_t)(x_03f7 + 2) != 0x20) {
        x_03f7 = (uint16_t)(x_03f7 + 2);
        goto shared_03F7;
    }
    a_hi_0400 = a_hi_03f7;
    goto shared_0400;
    shared_049D:;
    LOOP_GUARD(loop_guard);
    uint8_t value143 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0x16)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0x14)) + y_049d, BUS8_RDP(c, (uint16_t)(dp + 0x16)));
    RAM8(0x2143) = value143;
    if ((uint16_t)(y_049d + 1) != 0) {
        a_hi_04a7 = a_hi_049d;
        x_04a7 = x_049d;
        y_04a7 = (uint16_t)(y_049d + 1);
        goto shared_04A7;
    }
    uint8_t value144 = BUS8_RDP(c, (uint16_t)(dp + 0x16));
    BUS8_SET(c, (uint16_t)(dp + 0x16), (uint8_t)(value144 + 1));
    a_hi_04a7 = a_hi_049d;
    x_04a7 = x_049d;
    y_04a7 = (uint16_t)(y_049d + 1);
    goto shared_04A7;
    shared_03EB:;
    LOOP_GUARD(loop_guard);
    if (a_03eb != RAM8(0x2140)) {
        goto shared_03EB;
    }
    uint8_t value146 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    BUS8_SET(c, (uint16_t)(dp + 0x10), (uint8_t)(value146 + 1));
    a_hi_038c = a_hi_03eb;
    y_038c = y_03eb;
    goto shared_038C;
    shared_04A7:;
    LOOP_GUARD(loop_guard);
    uint8_t value147 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    RAM8(0x2140) = value147;
    a_04ac = value147;
    a_hi_04ac = a_hi_04a7;
    x_04ac = x_04a7;
    y_04ac = y_04a7;
    goto shared_04AC;
    shared_04AC:;
    LOOP_GUARD(loop_guard);
    if (a_04ac != RAM8(0x2140)) {
        goto shared_04AC;
    }
    uint8_t value149 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    BUS8_SET(c, (uint16_t)(dp + 0x10), (uint8_t)(value149 + 1));
    if ((uint8_t)(value149 + 1) != 0) {
        a_hi_04b7 = a_hi_04ac;
        x_04b7 = x_04ac;
        y_04b7 = y_04ac;
        goto shared_04B7;
    }
    uint8_t value150 = BUS8_RDP(c, (uint16_t)(dp + 0x10));
    BUS8_SET(c, (uint16_t)(dp + 0x10), (uint8_t)(value150 + 1));
    a_hi_04b7 = a_hi_04ac;
    x_04b7 = x_04ac;
    y_04b7 = y_04ac;
    goto shared_04B7;
    shared_04B7:;
    LOOP_GUARD(loop_guard);
    if ((uint16_t)(x_04b7 - 3) != 0) {
        a_hi_0489 = a_hi_04b7;
        x_0489 = (uint16_t)(x_04b7 - 3);
        y_0489 = y_04b7;
        goto shared_0489;
    }
    uint8_t value151 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value152 = RAM8(0x0000 + sp0 - 0x0A);
    a_hi_042e = a_hi_04b7;
    x_042e = (uint16_t)(((value152 << 8) | value151) + 2);
    goto shared_042E;
}
SOM_REGISTER(0xC30175, SOM_RTL, "gen", upload_six_spc_blocks_or_reset_ready_audio_metadata_at_C30175, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 14, 1, 0, 1066, 523)

/* C3018D entry_C3018D   [class D, 11 bytes, 9 instructions]
 * Source: src/rom/upload_six_spc_blocks_or_reset_ready_audio_metadata.s
 * Interior entry C3018D of upload_six_spc_blocks_or_reset_ready_audio_metadata, same file.
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void upload_six_spc_blocks_or_reset_ready_audio_metadata_at_C3018D(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 10;
    uint8_t value = RAM8(0x0000 + sp0 - 9);
    uint8_t value2 = RAM8(0x0000 + sp0 - 8);
    uint8_t value3 = RAM8(0x0000 + sp0 - 7);
    uint8_t value4 = RAM8(0x0000 + sp0 - 6);
    uint8_t value5 = RAM8(0x0000 + sp0 - 5);
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (value6 << 8) | value5;
    r->x = (value4 << 8) | value3;
    r->y = (value2 << 8) | value;
    r->c = value7 & 0x01;
    r->z = value10 == 0;
    r->n = value10 & 0x80;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = value10;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    r->sp += 10;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC3018D, SOM_RTL, "gen", upload_six_spc_blocks_or_reset_ready_audio_metadata_at_C3018D, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 1, 0, 11, 9)
