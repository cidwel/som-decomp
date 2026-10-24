#include "som_c.h"

/* C0CD93 decode_map_piece_body   [class C, 676 bytes, 369 instructions]
 * Source: src/rom/decode_map_piece_body.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: BCV.
 */
static void decode_map_piece_body(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t a_hi_cd99 = 0;
    bool overflow_cd99 = 0;
    uint8_t data_bank_cd99 = 0;
    uint8_t a_hi_cd9b = 0;
    bool overflow_cd9b = 0;
    uint8_t data_bank_cd9b = 0;
    uint8_t a_cda7 = 0;
    uint8_t a_hi_cda7 = 0;
    bool overflow_cda7 = 0;
    uint8_t data_bank_cda7 = 0;
    uint8_t a_hi_cdaf = 0;
    uint8_t y_cdaf = 0;
    bool overflow_cdaf = 0;
    uint8_t data_bank_cdaf = 0;
    uint8_t a_ce93 = 0;
    uint8_t a_hi_ce93 = 0;
    uint8_t y_ce93 = 0;
    uint8_t data_bank_ce93 = 0;
    uint8_t a_ce5a = 0;
    uint8_t a_hi_ce5a = 0;
    bool overflow_ce5a = 0;
    uint8_t data_bank_ce5a = 0;
    uint8_t a_ce36 = 0;
    uint8_t a_hi_ce36 = 0;
    uint8_t data_bank_ce36 = 0;
    uint8_t a_hi_cf05 = 0;
    uint8_t x_cf05 = 0;
    uint8_t y_cf05 = 0;
    uint8_t data_bank_cf05 = 0;
    uint8_t a_cdee = 0;
    uint8_t a_hi_cdee = 0;
    uint8_t data_bank_cdee = 0;
    uint8_t a_d00d = 0;
    uint8_t a_hi_d00d = 0;
    uint8_t x_d00d = 0;
    bool overflow_d00d = 0;
    uint8_t data_bank_d00d = 0;
    uint8_t a_ceae = 0;
    uint8_t a_hi_ceae = 0;
    uint8_t x_ceae = 0;
    uint8_t data_bank_ceae = 0;
    uint8_t a_hi_cfad = 0;
    uint8_t x_cfad = 0;
    bool overflow_cfad = 0;
    uint8_t data_bank_cfad = 0;
    uint8_t a_cf49 = 0;
    uint8_t a_hi_cf49 = 0;
    uint16_t x_cf49 = 0;
    uint16_t y_cf49 = 0;
    uint8_t data_bank_cf49 = 0;
    uint8_t a_d011 = 0;
    uint8_t a_hi_d011 = 0;
    uint8_t x_d011 = 0;
    uint8_t y_d011 = 0;
    bool overflow_d011 = 0;
    uint8_t data_bank_d011 = 0;
    uint8_t a_cedc = 0;
    uint8_t a_hi_cedc = 0;
    uint8_t x_cedc = 0;
    uint8_t y_cedc = 0;
    bool overflow_cedc = 0;
    uint8_t data_bank_cedc = 0;
    uint8_t a_ceb3 = 0;
    uint8_t a_hi_ceb3 = 0;
    uint8_t x_ceb3 = 0;
    uint8_t y_ceb3 = 0;
    bool overflow_ceb3 = 0;
    uint8_t data_bank_ceb3 = 0;
    uint8_t a_hi_cfcd = 0;
    uint8_t x_cfcd = 0;
    uint8_t y_cfcd = 0;
    bool overflow_cfcd = 0;
    uint8_t data_bank_cfcd = 0;
    uint8_t a_hi_cf91 = 0;
    bool overflow_cf91 = 0;
    uint8_t data_bank_cf91 = 0;
    uint8_t a_d02f = 0;
    uint8_t a_hi_d02f = 0;
    uint8_t x_d02f = 0;
    uint8_t y_d02f = 0;
    bool overflow_d02f = 0;
    uint8_t data_bank_d02f = 0;
    uint8_t a_cefd = 0;
    uint8_t a_hi_cefd = 0;
    uint8_t x_cefd = 0;
    uint8_t y_cefd = 0;
    bool overflow_cefd = 0;
    uint8_t data_bank_cefd = 0;
    uint8_t a_ced4 = 0;
    uint8_t a_hi_ced4 = 0;
    uint8_t x_ced4 = 0;
    uint8_t y_ced4 = 0;
    bool overflow_ced4 = 0;
    uint8_t data_bank_ced4 = 0;
    uint8_t a_hi_cfeb = 0;
    uint8_t x_cfeb = 0;
    bool overflow_cfeb = 0;
    uint8_t data_bank_cfeb = 0;
    RAM8(0x0004) = 0;
    a_hi_cd99 = a_hi;
    overflow_cd99 = overflow;
    data_bank_cd99 = 0x7F;
    shared_CD99:;
    a_hi_cd9b = a_hi_cd99;
    overflow_cd9b = overflow_cd99;
    data_bank_cd9b = data_bank_cd99;
    goto shared_CD9B;
    shared_CD9B:;
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D), value2);
    RAM8(0x001D)++;
    if (RAM8(0x001D) != 0) {
        a_cda7 = value2;
        a_hi_cda7 = a_hi_cd9b;
        overflow_cda7 = overflow_cd9b;
        data_bank_cda7 = data_bank_cd9b;
        goto shared_CDA7;
    }
    RAM8(0x001E)++;
    if (RAM8(0x001E) != 0) {
        a_cda7 = value2;
        a_hi_cda7 = a_hi_cd9b;
        overflow_cda7 = overflow_cd9b;
        data_bank_cda7 = data_bank_cd9b;
        goto shared_CDA7;
    }
    RAM8(0x001F)++;
    a_cda7 = value2;
    a_hi_cda7 = a_hi_cd9b;
    overflow_cda7 = overflow_cd9b;
    data_bank_cda7 = data_bank_cd9b;
    goto shared_CDA7;
    shared_CDA7:;
    uint8_t value3 = RAM8(0x0004);
    if (a_cda7 >= 0xC0) {
        if (a_cda7 >= 0xE0) {
            if (a_cda7 != 0xE0) {
                if (a_cda7 >= 0xE8) {
                    if (a_cda7 >= 0xF0) {
                        if (a_cda7 != 0xF0) {
                            if (a_cda7 >= 0xF8) {
                                RAM8(0x0000 + sp0) = a_cda7 & 7;
                                uint8_t value4;
                                BUS8_OK(c, (data_bank_cda7 << 0x10) + 0xFF00 + (uint8_t)((a_hi_cda7 << 8) | ((a_cda7 & 7) << 1 << 1)), value4);
                                uint8_t value5 = RAM8(0x0016);
                                RAM8(0x0016)++;
                                uint8_t value6 = RAM8(0x0012);
                                uint8_t value7 = RAM8(0x0004);
                                BUS8_SET(c, (data_bank_cda7 << 0x10) + 0xFF22 + (uint8_t)((a_hi_cda7 << 8) | (uint8_t)(value5 << 2)), (uint8_t)(value6 + value7));
                                BUS8_SET(c, (data_bank_cda7 << 0x10) + 0xFF23 + (uint8_t)((a_hi_cda7 << 8) | (uint8_t)(value5 << 2)), RAM8(0x0013));
                                BUS8_SET(c, (data_bank_cda7 << 0x10) + 0xFF20 + (uint8_t)((a_hi_cda7 << 8) | (uint8_t)(value5 << 2)), RAM8(0x0000 + sp0) | 0x80);
                                a_hi_cdaf = a_hi_cda7;
                                y_cdaf = value3;
                                overflow_cdaf = ((value6 ^ (uint8_t)(value6 + value7)) & (value7 ^ (uint8_t)(value6 + value7)) & 0x80) != 0;
                                data_bank_cdaf = data_bank_cda7;
                                goto shared_CDAF;
                            }
                            RAM8(0x0000 + sp0) = (((((a_cda7 & 7) >> 7 << 7) | (overflow_cda7 << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (((a_cda7 & 7) == 0) << 1);
                            a_ce93 = a_cda7 & 7;
                            a_hi_ce93 = a_hi_cda7;
                            y_ce93 = value3;
                            data_bank_ce93 = data_bank_cda7;
                            goto shared_CE93;
                        }
                        uint8_t value10;
                        BUS8_OK(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D), value10);
                        RAM8(0x001D)++;
                        if (RAM8(0x001D) != 0) {
                            a_ce5a = value10;
                            a_hi_ce5a = a_hi_cda7;
                            overflow_ce5a = overflow_cda7;
                            data_bank_ce5a = data_bank_cda7;
                            goto shared_CE5A;
                        }
                        RAM8(0x001E)++;
                        if (RAM8(0x001E) != 0) {
                            a_ce5a = value10;
                            a_hi_ce5a = a_hi_cda7;
                            overflow_ce5a = overflow_cda7;
                            data_bank_ce5a = data_bank_cda7;
                            goto shared_CE5A;
                        }
                        RAM8(0x001F)++;
                        a_ce5a = value10;
                        a_hi_ce5a = a_hi_cda7;
                        overflow_ce5a = overflow_cda7;
                        data_bank_ce5a = data_bank_cda7;
                        goto shared_CE5A;
                    }
                    RAM8(0x0002) = a_cda7 & 7;
                    uint8_t value11;
                    BUS8_OK(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D), value11);
                    RAM8(0x001D)++;
                    if (RAM8(0x001D) != 0) {
                        a_ce36 = value11;
                        a_hi_ce36 = a_hi_cda7;
                        data_bank_ce36 = data_bank_cda7;
                        goto shared_CE36;
                    }
                    RAM8(0x001E)++;
                    if (RAM8(0x001E) != 0) {
                        a_ce36 = value11;
                        a_hi_ce36 = a_hi_cda7;
                        data_bank_ce36 = data_bank_cda7;
                        goto shared_CE36;
                    }
                    RAM8(0x001F)++;
                    a_ce36 = value11;
                    a_hi_ce36 = a_hi_cda7;
                    data_bank_ce36 = data_bank_cda7;
                    goto shared_CE36;
                }
                uint16_t value12 = RAM16(0x0012);
                RAM16_SET(0x0000, (uint16_t)(value12 - 0x80));
                a_hi_cf05 = (uint16_t)(value12 - 0x80) >> 8;
                x_cf05 = (uint8_t)(a_hi_cda7 << 8 | (a_cda7 & 7));
                y_cf05 = value3;
                data_bank_cf05 = data_bank_cda7;
                goto shared_CF05;
            }
            uint8_t value13;
            BUS8_OK(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D), value13);
            RAM8(0x001D)++;
            if (RAM8(0x001D) != 0) {
                a_cdee = value13;
                a_hi_cdee = a_hi_cda7;
                data_bank_cdee = data_bank_cda7;
                goto shared_CDEE;
            }
            RAM8(0x001E)++;
            if (RAM8(0x001E) != 0) {
                a_cdee = value13;
                a_hi_cdee = a_hi_cda7;
                data_bank_cdee = data_bank_cda7;
                goto shared_CDEE;
            }
            RAM8(0x001F)++;
            a_cdee = value13;
            a_hi_cdee = a_hi_cda7;
            data_bank_cdee = data_bank_cda7;
            goto shared_CDEE;
        }
        RAM8(0x0000 + sp0) = a_cda7;
        RAM8(0x0002) = ((a_cda7 >> 3) & 3) + 1;
        uint8_t value14 = RAM8(0x0004);
        uint8_t value15 = RAM8(0x0002);
        uint8_t value16;
        BUS8_OK(c, (data_bank_cda7 << 0x10) + RAM16(0x0012) + (uint8_t)((a_hi_cda7 << 8) | (uint8_t)(value14 - value15)), value16);
        if (value14 >= value15) {
            a_d00d = value16;
            a_hi_d00d = a_hi_cda7;
            x_d00d = (uint8_t)(a_hi_cda7 << 8 | (a_cda7 & 7));
            overflow_d00d = ((value14 ^ value15) & (value14 ^ (uint8_t)(value14 - value15)) & 0x80) != 0;
            data_bank_d00d = data_bank_cda7;
            goto shared_D00D;
        }
        uint8_t value17 = RAM8(0x0014);
        uint16_t value18 = RAM16(0x0012);
        RAM16_SET(0x0000, (uint16_t)(value18 - 0x80));
        uint8_t value19;
        BUS8_OK(c, (data_bank_cda7 << 0x10) + RAM16(0x0000) + (uint8_t)((a_hi_cda7 << 8) | (uint8_t)((uint8_t)((a_hi_cda7 << 8) | (uint8_t)(value14 - value15)) + value17 + (value14 >= value15))), value19);
        a_d00d = value19;
        a_hi_d00d = (uint16_t)(value18 - 0x80) >> 8;
        x_d00d = (uint8_t)(a_hi_cda7 << 8 | (a_cda7 & 7));
        overflow_d00d = ((value18 ^ 0x80) & (value18 ^ (uint16_t)(value18 - 0x80)) & 0x8000) != 0;
        data_bank_d00d = data_bank_cda7;
        goto shared_D00D;
    }
    BUS8_SET(c, (data_bank_cda7 << 0x10) + RAM16(0x0012) + value3, a_cda7);
    a_hi_cdaf = a_hi_cda7;
    y_cdaf = value3;
    overflow_cdaf = overflow_cda7;
    data_bank_cdaf = data_bank_cda7;
    goto shared_CDAF;
    shared_CDAF:;
    RAM8(0x0004) = (uint8_t)(y_cdaf + 1);
    uint8_t value20 = RAM8(0x0014);
    if ((uint8_t)(y_cdaf + 1) < value20) {
        a_hi_cd9b = a_hi_cdaf;
        overflow_cd9b = overflow_cdaf;
        data_bank_cd9b = data_bank_cdaf;
        goto shared_CD9B;
    }
    RAM8(0x0004) = (uint8_t)((uint8_t)(y_cdaf + 1) - value20 - ((uint8_t)(y_cdaf + 1) >= value20 ^ 1));
    uint16_t value21 = RAM16(0x0012);
    RAM16_SET(0x0012, (uint16_t)(value21 + 0x80));
    RAM8(0x0015)--;
    if (RAM8(0x0015) != 0) {
        a_hi_cd99 = (uint16_t)(value21 + 0x80) >> 8;
        overflow_cd99 = ((value21 ^ (uint16_t)(value21 + 0x80)) & ((uint16_t)(value21 + 0x80) ^ 0x80) & 0x8000) != 0;
        data_bank_cd99 = data_bank_cdaf;
        goto shared_CD99;
    }
    r->a = (uint16_t)(value21 + 0x80);
    r->c = value21 + 0x80 > 0xFFFF;
    r->v = ((value21 ^ (uint16_t)(value21 + 0x80)) & ((uint16_t)(value21 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_cdaf;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CE93:;
    uint8_t value22;
    BUS8_OK(c, (data_bank_ce93 << 0x10) + RAM16(0x0012) + (uint8_t)(y_ce93 - 1), value22);
    if ((uint8_t)(y_ce93 - 1) < 0x80) {
        a_ceae = value22;
        a_hi_ceae = a_hi_ce93;
        x_ceae = (uint8_t)((a_hi_ce93 << 8) | a_ce93);
        data_bank_ceae = data_bank_ce93;
        goto shared_CEAE;
    }
    uint8_t value23 = RAM8(0x0014);
    uint16_t value24 = RAM16(0x0012);
    RAM16_SET(0x0000, (uint16_t)(value24 - 0x80));
    uint8_t value25;
    BUS8_OK(c, (data_bank_ce93 << 0x10) + RAM16(0x0000) + (uint8_t)((a_hi_ce93 << 8) | (uint8_t)((uint8_t)(y_ce93 - 1) + value23)), value25);
    a_ceae = value25;
    a_hi_ceae = (uint16_t)(value24 - 0x80) >> 8;
    x_ceae = (uint8_t)((a_hi_ce93 << 8) | a_ce93);
    data_bank_ceae = data_bank_ce93;
    goto shared_CEAE;
    shared_CE5A:;
    uint8_t value26 = RAM8(0x0004);
    RAM8(0x0000 + sp0) = (((((uint8_t)(a_ce5a - 0x80) >> 7 << 7) | (overflow_ce5a << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | ((a_ce5a == 0x80) << 1) | a_ce5a >= 0x80;
    a_ce93 = a_ce5a & 0x7F;
    a_hi_ce93 = a_hi_ce5a;
    y_ce93 = value26;
    data_bank_ce93 = data_bank_ce5a;
    goto shared_CE93;
    shared_CE36:;
    uint8_t value27 = RAM8(0x0004);
    RAM8(0x0002) = (uint8_t)((RAM8(0x0002) << 1) | (a_ce36 >= 0x80));
    RAM8(0x0002)++;
    RAM8(0x0000) = RAM8(0x0012);
    RAM8(0x0001) = RAM8(0x0013);
    uint8_t value31 = RAM8(0x0002);
    RAM8(0x0002) = (uint8_t)(value27 - value31);
    if (value27 >= value31) {
        a_hi_cfad = a_hi_ce36;
        x_cfad = (uint8_t)(a_hi_ce36 << 8 | (a_ce36 & 0x7F));
        overflow_cfad = ((value27 ^ value31) & (value27 ^ (uint8_t)(value27 - value31)) & 0x80) != 0;
        data_bank_cfad = data_bank_ce36;
        goto shared_CFAD;
    }
    RAM8(0x0002) = (uint8_t)((uint8_t)(value27 - value31) + RAM8(0x0014) + (value27 >= value31));
    uint16_t value33 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)(value33 - 0x80));
    a_hi_cfad = (uint16_t)(value33 - 0x80) >> 8;
    x_cfad = (uint8_t)(a_hi_ce36 << 8 | (a_ce36 & 0x7F));
    overflow_cfad = ((value33 ^ 0x80) & (value33 ^ (uint16_t)(value33 - 0x80)) & 0x8000) != 0;
    data_bank_cfad = data_bank_ce36;
    goto shared_CFAD;
    shared_CF05:;
    RAM8(0x0002) = x_cf05;
    uint8_t value34 = RAM8(0x0004);
    uint8_t value35 = RAM8(0x0014);
    if ((uint8_t)(x_cf05 + value34 + 1) >= value35) {
        RAM8(0x0004) = (uint8_t)((uint8_t)(x_cf05 + value34 + 1) - value35 - ((uint8_t)(x_cf05 + value34 + 1) >= value35 ^ 1));
        RAM8(0x0002) = (uint8_t)((uint8_t)(((uint8_t)((uint8_t)(x_cf05 + value34 + 1) - value35 - ((uint8_t)(x_cf05 + value34 + 1) >= value35 ^ 1)) ^ 0xFF) + 1) + RAM8(0x0002));
        uint16_t value37 = RAM16(0x0000);
        uint16_t value38 = RAM16(0x0012);
        a_cf49 = RAM16(0x0002) & 0x7F;
        a_hi_cf49 = 0;
        x_cf49 = (uint16_t)(y_cf05 + value37);
        y_cf49 = (uint16_t)(y_cf05 + value38);
        data_bank_cf49 = data_bank_cf05;
        goto shared_CF49;
    }
    RAM8(0x0004) = (uint8_t)(x_cf05 + value34 + 1);
    uint16_t value40 = RAM16(0x0000);
    uint16_t value41 = RAM16(0x0012);
    r->a = RAM16(0x0002) & 0x7F;
    r->x = (uint16_t)(y_cf05 + value40);
    r->y = (uint16_t)(y_cf05 + value41);
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_cf05;
    r->dp = 0;
    i_mvn(c, 0x7F, 0x7F); /* copy up bank $7F to bank $7F */
    a_hi_cd9b = 0xFF;
    overflow_cd9b = ((y_cf05 ^ (uint16_t)(y_cf05 + value41)) & (value41 ^ (uint16_t)(y_cf05 + value41)) & 0x8000) != 0;
    data_bank_cd9b = 0x7F;
    goto shared_CD9B;
    shared_CDEE:;
    uint8_t value44 = RAM8(0x0004);
    RAM8(0x0000 + sp0) = a_cdee;
    RAM8(0x0000) = a_cdee & 0x80;
    RAM8(0x0001) = 0;
    uint16_t value45 = RAM16(0x0012);
    uint16_t value46 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)((uint16_t)(value45 - value46) - 0x80 - (value45 >= value46 ^ 1)));
    a_hi_cf05 = (uint16_t)((uint16_t)(value45 - value46) - 0x80 - (value45 >= value46 ^ 1)) >> 8;
    x_cf05 = (uint8_t)(a_hi_cdee << 8 | (a_cdee & 0x7F));
    y_cf05 = value44;
    data_bank_cf05 = data_bank_cdee;
    goto shared_CF05;
    shared_D00D:;
    RAM8(0x0002) = a_d00d;
    uint8_t value47 = RAM8(0x0004);
    a_d011 = a_d00d;
    a_hi_d011 = a_hi_d00d;
    x_d011 = x_d00d;
    y_d011 = value47;
    overflow_d011 = overflow_d00d;
    data_bank_d011 = data_bank_d00d;
    goto shared_D011;
    shared_CEAE:;
    uint8_t value48 = RAM8(0x0004);
    uint8_t value49 = RAM8(0x0000 + sp0);
    if (value49 & 0x01) {
        a_cedc = a_ceae;
        a_hi_cedc = a_hi_ceae;
        x_cedc = x_ceae;
        y_cedc = value48;
        overflow_cedc = value49 & 0x40;
        data_bank_cedc = data_bank_ceae;
        goto shared_CEDC;
    }
    a_ceb3 = a_ceae;
    a_hi_ceb3 = a_hi_ceae;
    x_ceb3 = x_ceae;
    y_ceb3 = value48;
    overflow_ceb3 = value49 & 0x40;
    data_bank_ceb3 = data_bank_ceae;
    goto shared_CEB3;
    shared_CFAD:;
    uint8_t value51;
    BUS8_OK(c, (data_bank_cfad << 0x10) + RAM16(0x0000) + RAM8(0x0002), value51);
    uint8_t value52 = RAM8(0x0004);
    BUS8_SET(c, (data_bank_cfad << 0x10) + RAM16(0x0012) + value52, value51);
    RAM8(0x0002)++;
    uint8_t value53 = RAM8(0x0002);
    uint8_t value54 = RAM8(0x0014);
    if (value53 < value54) {
        a_hi_cfcd = a_hi_cfad;
        x_cfcd = x_cfad;
        y_cfcd = value52;
        overflow_cfcd = overflow_cfad;
        data_bank_cfcd = data_bank_cfad;
        goto shared_CFCD;
    }
    RAM8(0x0002) = (uint8_t)(value53 - value54 - (value53 >= value54 ^ 1));
    uint16_t value55 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)(value55 + 0x80));
    a_hi_cfcd = (uint16_t)(value55 + 0x80) >> 8;
    x_cfcd = x_cfad;
    y_cfcd = value52;
    overflow_cfcd = ((value55 ^ (uint16_t)(value55 + 0x80)) & ((uint16_t)(value55 + 0x80) ^ 0x80) & 0x8000) != 0;
    data_bank_cfcd = data_bank_cfad;
    goto shared_CFCD;
    shared_CF49:;
    r->a = (a_hi_cf49 << 8) | a_cf49;
    r->x = x_cf49;
    r->y = y_cf49;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_cf49;
    r->dp = 0;
    i_mvn(c, 0x7F, 0x7F); /* copy up bank $7F to bank $7F */
    RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) + 0x80));
    uint16_t value57 = RAM16(0x0012);
    RAM16_SET(0x0012, (uint16_t)(value57 + 0x80));
    RAM8(0x0015)--;
    if (RAM8(0x0015) != 0) {
        uint8_t value58 = RAM8(0x0004);
        if (value58 == 0) {
            a_hi_cf91 = (uint16_t)(value57 + 0x80) >> 8;
            overflow_cf91 = ((value57 ^ (uint16_t)(value57 + 0x80)) & ((uint16_t)(value57 + 0x80) ^ 0x80) & 0x8000) != 0;
            data_bank_cf91 = 0x7F;
            goto shared_CF91;
        }
        uint8_t value59 = RAM8(0x0014);
        if (value58 < value59) {
            uint16_t value60 = RAM16(0x0000);
            uint16_t value61 = RAM16(0x0012);
            r->a = (uint16_t)((RAM16(0x0004) & 0x7F) - 1);
            r->x = value60;
            r->y = value61;
            i_mvn(c, 0x7F, 0x7F); /* copy up bank $7F to bank $7F */
            a_hi_cf91 = 0xFF;
            overflow_cf91 = ((value57 ^ (uint16_t)(value57 + 0x80)) & ((uint16_t)(value57 + 0x80) ^ 0x80) & 0x8000) != 0;
            data_bank_cf91 = 0x7F;
            goto shared_CF91;
        }
        RAM8(0x0004) = (uint8_t)(value58 - value59 - (value58 >= value59 ^ 1));
        uint16_t value64 = RAM16(0x0000);
        uint16_t value65 = RAM16(0x0012);
        uint16_t value66 = RAM16(0x0014);
        a_cf49 = (uint8_t)((value66 & 0x7F) - 1);
        a_hi_cf49 = (uint16_t)((value66 & 0x7F) - 1) >> 8;
        x_cf49 = value64;
        y_cf49 = value65;
        data_bank_cf49 = 0x7F;
        goto shared_CF49;
    }
    r->a = (r->a & 0x00FF) | (((uint16_t)(value57 + 0x80) >> 8) << 8);
    r->c = value57 + 0x80 > 0xFFFF;
    r->v = ((value57 ^ (uint16_t)(value57 + 0x80)) & ((uint16_t)(value57 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
    shared_D011:;
    BUS8_SET(c, (data_bank_d011 << 0x10) + RAM16(0x0012) + y_d011, a_d011);
    uint8_t value67 = RAM8(0x0014);
    if ((uint8_t)(y_d011 + 1) < value67) {
        a_d02f = a_d011;
        a_hi_d02f = a_hi_d011;
        x_d02f = x_d011;
        y_d02f = (uint8_t)(y_d011 + 1);
        overflow_d02f = overflow_d011;
        data_bank_d02f = data_bank_d011;
        goto shared_D02F;
    }
    uint16_t value68 = RAM16(0x0012);
    RAM16_SET(0x0012, (uint16_t)(value68 + 0x80));
    RAM8(0x0015)--;
    if (RAM8(0x0015) != 0) {
        a_d02f = RAM8(0x0002);
        a_hi_d02f = (uint16_t)(value68 + 0x80) >> 8;
        x_d02f = x_d011;
        y_d02f = (uint8_t)((a_hi_d011 << 8) | (uint8_t)((uint8_t)(y_d011 + 1) - value67 - ((uint8_t)(y_d011 + 1) >= value67 ^ 1)));
        overflow_d02f = ((value68 ^ (uint16_t)(value68 + 0x80)) & ((uint16_t)(value68 + 0x80) ^ 0x80) & 0x8000) != 0;
        data_bank_d02f = data_bank_d011;
        goto shared_D02F;
    }
    r->a = (uint16_t)(value68 + 0x80);
    r->c = value68 + 0x80 > 0xFFFF;
    r->v = ((value68 ^ (uint16_t)(value68 + 0x80)) & ((uint16_t)(value68 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d011;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CEDC:;
    BUS8_SET(c, (data_bank_cedc << 0x10) + RAM16(0x0012) + y_cedc, (uint8_t)(a_cedc - 1));
    uint8_t value70 = RAM8(0x0014);
    if ((uint8_t)(y_cedc + 1) < value70) {
        a_cefd = (uint8_t)(a_cedc - 1);
        a_hi_cefd = a_hi_cedc;
        x_cefd = x_cedc;
        y_cefd = (uint8_t)(y_cedc + 1);
        overflow_cefd = overflow_cedc;
        data_bank_cefd = data_bank_cedc;
        goto shared_CEFD;
    }
    RAM8(0x0000 + sp0) = (uint8_t)(a_cedc - 1);
    uint8_t value71 = RAM8(0x0014);
    RAM8(0x0004) = (uint8_t)((uint8_t)(y_cedc + 1) - value71 - ((uint8_t)(y_cedc + 1) >= value70 ^ 1));
    uint16_t value72 = RAM16(0x0012);
    RAM16_SET(0x0012, (uint16_t)(value72 + 0x80));
    RAM8(0x0015)--;
    if (RAM8(0x0015) != 0) {
        a_cefd = (uint8_t)(a_cedc - 1);
        a_hi_cefd = (uint16_t)(value72 + 0x80) >> 8;
        x_cefd = x_cedc;
        y_cefd = (uint8_t)((a_hi_cedc << 8) | (uint8_t)((uint8_t)(y_cedc + 1) - value71 - ((uint8_t)(y_cedc + 1) >= value70 ^ 1)));
        overflow_cefd = ((value72 ^ (uint16_t)(value72 + 0x80)) & ((uint16_t)(value72 + 0x80) ^ 0x80) & 0x8000) != 0;
        data_bank_cefd = data_bank_cedc;
        goto shared_CEFD;
    }
    r->a = ((uint16_t)(value72 + 0x80) >> 8 << 8) | (uint8_t)(a_cedc - 1);
    r->c = value72 + 0x80 > 0xFFFF;
    r->v = ((value72 ^ (uint16_t)(value72 + 0x80)) & ((uint16_t)(value72 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_cedc;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CEB3:;
    BUS8_SET(c, (data_bank_ceb3 << 0x10) + RAM16(0x0012) + y_ceb3, (uint8_t)(a_ceb3 + 1));
    uint8_t value73 = RAM8(0x0014);
    if ((uint8_t)(y_ceb3 + 1) < value73) {
        a_ced4 = (uint8_t)(a_ceb3 + 1);
        a_hi_ced4 = a_hi_ceb3;
        x_ced4 = x_ceb3;
        y_ced4 = (uint8_t)(y_ceb3 + 1);
        overflow_ced4 = overflow_ceb3;
        data_bank_ced4 = data_bank_ceb3;
        goto shared_CED4;
    }
    RAM8(0x0000 + sp0) = (uint8_t)(a_ceb3 + 1);
    uint8_t value74 = RAM8(0x0014);
    RAM8(0x0004) = (uint8_t)((uint8_t)(y_ceb3 + 1) - value74 - ((uint8_t)(y_ceb3 + 1) >= value73 ^ 1));
    uint16_t value75 = RAM16(0x0012);
    RAM16_SET(0x0012, (uint16_t)(value75 + 0x80));
    RAM8(0x0015)--;
    if (RAM8(0x0015) != 0) {
        a_ced4 = (uint8_t)(a_ceb3 + 1);
        a_hi_ced4 = (uint16_t)(value75 + 0x80) >> 8;
        x_ced4 = x_ceb3;
        y_ced4 = (uint8_t)((a_hi_ceb3 << 8) | (uint8_t)((uint8_t)(y_ceb3 + 1) - value74 - ((uint8_t)(y_ceb3 + 1) >= value73 ^ 1)));
        overflow_ced4 = ((value75 ^ (uint16_t)(value75 + 0x80)) & ((uint16_t)(value75 + 0x80) ^ 0x80) & 0x8000) != 0;
        data_bank_ced4 = data_bank_ceb3;
        goto shared_CED4;
    }
    r->a = ((uint16_t)(value75 + 0x80) >> 8 << 8) | (uint8_t)(a_ceb3 + 1);
    r->c = value75 + 0x80 > 0xFFFF;
    r->v = ((value75 ^ (uint16_t)(value75 + 0x80)) & ((uint16_t)(value75 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_ceb3;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CFCD:;
    RAM8(0x0004) = (uint8_t)(y_cfcd + 1);
    uint8_t value76 = RAM8(0x0014);
    if ((uint8_t)(y_cfcd + 1) < value76) {
        a_hi_cfeb = a_hi_cfcd;
        x_cfeb = x_cfcd;
        overflow_cfeb = overflow_cfcd;
        data_bank_cfeb = data_bank_cfcd;
        goto shared_CFEB;
    }
    RAM8(0x0004) = (uint8_t)((uint8_t)(y_cfcd + 1) - value76 - ((uint8_t)(y_cfcd + 1) >= value76 ^ 1));
    uint16_t value77 = RAM16(0x0012);
    RAM16_SET(0x0012, (uint16_t)(value77 + 0x80));
    RAM8(0x0015)--;
    if (RAM8(0x0015) != 0) {
        a_hi_cfeb = (uint16_t)(value77 + 0x80) >> 8;
        x_cfeb = x_cfcd;
        overflow_cfeb = ((value77 ^ (uint16_t)(value77 + 0x80)) & ((uint16_t)(value77 + 0x80) ^ 0x80) & 0x8000) != 0;
        data_bank_cfeb = data_bank_cfcd;
        goto shared_CFEB;
    }
    r->a = (uint16_t)(value77 + 0x80);
    r->c = value77 + 0x80 > 0xFFFF;
    r->v = ((value77 ^ (uint16_t)(value77 + 0x80)) & ((uint16_t)(value77 + 0x80) ^ 0x80) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_cfcd;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CF91:;
    a_hi_cd9b = a_hi_cf91;
    overflow_cd9b = overflow_cf91;
    data_bank_cd9b = data_bank_cf91;
    goto shared_CD9B;
    shared_D02F:;
    if (!((uint8_t)(x_d02f - 1) & 0x80)) {
        a_d011 = a_d02f;
        a_hi_d011 = a_hi_d02f;
        x_d011 = (uint8_t)(x_d02f - 1);
        y_d011 = y_d02f;
        overflow_d011 = overflow_d02f;
        data_bank_d011 = data_bank_d02f;
        goto shared_D011;
    }
    RAM8(0x0004) = y_d02f;
    a_hi_cd9b = a_hi_d02f;
    overflow_cd9b = overflow_d02f;
    data_bank_cd9b = data_bank_d02f;
    goto shared_CD9B;
    shared_CEFD:;
    if (!((uint8_t)(x_cefd - 1) & 0x80)) {
        a_cedc = a_cefd;
        a_hi_cedc = a_hi_cefd;
        x_cedc = (uint8_t)(x_cefd - 1);
        y_cedc = y_cefd;
        overflow_cedc = overflow_cefd;
        data_bank_cedc = data_bank_cefd;
        goto shared_CEDC;
    }
    RAM8(0x0004) = y_cefd;
    a_hi_cd9b = a_hi_cefd;
    overflow_cd9b = overflow_cefd;
    data_bank_cd9b = data_bank_cefd;
    goto shared_CD9B;
    shared_CED4:;
    if (!((uint8_t)(x_ced4 - 1) & 0x80)) {
        a_ceb3 = a_ced4;
        a_hi_ceb3 = a_hi_ced4;
        x_ceb3 = (uint8_t)(x_ced4 - 1);
        y_ceb3 = y_ced4;
        overflow_ceb3 = overflow_ced4;
        data_bank_ceb3 = data_bank_ced4;
        goto shared_CEB3;
    }
    RAM8(0x0004) = y_ced4;
    a_hi_cd9b = a_hi_ced4;
    overflow_cd9b = overflow_ced4;
    data_bank_cd9b = data_bank_ced4;
    goto shared_CD9B;
    shared_CFEB:;
    if (!((uint8_t)(x_cfeb - 1) & 0x80)) {
        a_hi_cfad = a_hi_cfeb;
        x_cfad = (uint8_t)(x_cfeb - 1);
        overflow_cfad = overflow_cfeb;
        data_bank_cfad = data_bank_cfeb;
        goto shared_CFAD;
    }
    a_hi_cd9b = a_hi_cfeb;
    overflow_cd9b = overflow_cfeb;
    data_bank_cd9b = data_bank_cfeb;
    goto shared_CD9B;
}
SOM_REGISTER(0xC0CD93, SOM_RTS, "gen", decode_map_piece_body, 0, L_B | L_C | L_V, 1, 1, 1, 676, 369)
