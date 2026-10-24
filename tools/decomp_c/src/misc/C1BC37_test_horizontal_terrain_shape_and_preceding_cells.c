#include "som_c.h"

/* C1BC37 test_horizontal_terrain_shape_and_preceding_cells   [class C, 478 bytes, 267 instructions]
 * Source: src/rom/test_horizontal_terrain_shape_and_preceding_cells.s
 * Documented in docs/actor-map-terrain-queries.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYC.
 */
static void test_horizontal_terrain_shape_and_preceding_cells(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t a_hi_bc55 = 0;
    uint16_t y_bc55 = 0;
    uint8_t a_hi_bc69 = 0;
    uint16_t y_bc69 = 0;
    uint8_t a_hi_bcfb = 0;
    uint16_t y_bcfb = 0;
    uint8_t a_hi_bd12 = 0;
    uint16_t y_bd12 = 0;
    uint8_t a_hi_bcd4 = 0;
    uint16_t y_bcd4 = 0;
    uint8_t a_hi_bcb5 = 0;
    uint16_t y_bcb5 = 0;
    uint8_t a_hi_bcc6 = 0;
    uint16_t y_bcc6 = 0;
    uint8_t a_hi_bc8f = 0;
    uint16_t y_bc8f = 0;
    uint8_t a_bd16 = 0;
    uint8_t a_hi_bd16 = 0;
    uint8_t a_hi_bc67 = 0;
    uint16_t y_bc67 = 0;
    uint8_t a_hi_bd03 = 0;
    uint16_t y_bd03 = 0;
    RAM8(0x0003) = RAM8(0x001A);
    RAM8(0x0002) = 0;
    uint8_t value2 = RAM8(0x0007);
    if ((value2 & 7) == 0) {
        a_hi_bc55 = a_hi;
        y_bc55 = y;
        goto shared_BC55;
    }
    if ((value2 & 7) >= 4) {
        a_hi_bc55 = a_hi;
        y_bc55 = y;
        goto shared_BC55;
    }
    if ((value2 & 7) == 3) {
        a_hi_bc69 = a_hi;
        y_bc69 = y;
        goto shared_BC69;
    }
    if ((((value2 & 7) ^ RAM8(0x001B)) & 3) == 3) {
        a_hi_bc69 = a_hi;
        y_bc69 = y;
        goto shared_BC69;
    }
    a_hi_bc55 = a_hi;
    y_bc55 = y;
    shared_BC55:;
    uint8_t value4 = RAM8(0x0006);
    if ((value4 & 7) != 0) {
        if ((value4 & 7) != 4) {
            if ((value4 & 7) != 5) {
                if ((value4 & 7) != 6) {
                    if ((value4 & 7) != 7) {
                        r->a = a_hi_bc55 << 8 | (value4 & 7);
                        r->y = y_bc55;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (!(RAM8(0x001F) & 0x80)) {
                        a_hi_bcfb = a_hi_bc55;
                        y_bcfb = y_bc55;
                        goto shared_BCFB;
                    }
                    if (RAM8(0x001E) != 0) {
                        a_hi_bcfb = a_hi_bc55;
                        y_bcfb = y_bc55;
                        goto shared_BCFB;
                    }
                    if (RAM8(0x0004) < 2) {
                        a_hi_bd12 = a_hi_bc55;
                        y_bd12 = y_bc55;
                        goto shared_BD12;
                    }
                    a_hi_bcfb = a_hi_bc55;
                    y_bcfb = y_bc55;
                    goto shared_BCFB;
                }
                uint8_t value8 = RAM8(0x0004);
                uint8_t value9 = RAM8(0x0005);
                if ((value8 ^ 0x0F) < value9) {
                    uint8_t value10 = RAM8(0x0003);
                    if ((uint8_t)(value8 - value10) & 0x80) {
                        a_hi_bcd4 = a_hi_bc55;
                        y_bcd4 = y_bc55;
                        goto shared_BCD4;
                    }
                    if (((uint8_t)(value8 - value10) ^ 0x0F) >= value9) {
                        a_hi_bcd4 = a_hi_bc55;
                        y_bcd4 = y_bc55;
                        goto shared_BCD4;
                    }
                    r->a = (a_hi_bc55 << 8) | ((uint8_t)(value8 - value10) ^ 0x0F);
                    r->y = y_bc55;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                a_hi_bcd4 = a_hi_bc55;
                y_bcd4 = y_bc55;
                goto shared_BCD4;
            }
            if (RAM8(0x001F) & 0x80) {
                a_hi_bcb5 = a_hi_bc55;
                y_bcb5 = y_bc55;
                goto shared_BCB5;
            }
            if (RAM8(0x001E) != 0) {
                a_hi_bcb5 = a_hi_bc55;
                y_bcb5 = y_bc55;
                goto shared_BCB5;
            }
            if (RAM8(0x0004) < 2) {
                a_hi_bcc6 = a_hi_bc55;
                y_bcc6 = y_bc55;
                goto shared_BCC6;
            }
            a_hi_bcb5 = a_hi_bc55;
            y_bcb5 = y_bc55;
            goto shared_BCB5;
        }
        uint8_t value14 = RAM8(0x0004);
        uint8_t value15 = RAM8(0x0005);
        if (value14 >= value15) {
            if (value14 == value15) {
                a_hi_bc8f = a_hi_bc55;
                y_bc8f = y_bc55;
                goto shared_BC8F;
            }
            uint8_t value16 = RAM8(0x0003);
            if ((uint8_t)(value14 - value16 - (value14 >= value15 ^ 1)) & 0x80) {
                a_hi_bc8f = a_hi_bc55;
                y_bc8f = y_bc55;
                goto shared_BC8F;
            }
            if ((uint8_t)(value14 - value16 - (value14 >= value15 ^ 1)) == value15) {
                a_hi_bc8f = a_hi_bc55;
                y_bc8f = y_bc55;
                goto shared_BC8F;
            }
            if ((uint8_t)(value14 - value16 - (value14 >= value15 ^ 1)) < value15) {
                a_hi_bc8f = a_hi_bc55;
                y_bc8f = y_bc55;
                goto shared_BC8F;
            }
            r->a = (a_hi_bc55 << 8) | (uint8_t)(value14 - value16 - (value14 >= value15 ^ 1));
            r->y = y_bc55;
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        a_hi_bc8f = a_hi_bc55;
        y_bc8f = y_bc55;
        goto shared_BC8F;
    }
    uint8_t value17 = RAM8(0x0004);
    uint8_t value18 = RAM8(0x0003);
    if (!((uint8_t)(value17 - value18) & 0x80)) {
        r->a = (a_hi_bc55 << 8) | (uint8_t)(value17 - value18);
        r->y = y_bc55;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    a_bd16 = (uint8_t)(value17 - value18);
    a_hi_bd16 = a_hi_bc55;
    goto shared_BD16;
    shared_BC69:;
    if (RAM8(0x001E) != 0) {
        a_hi_bc67 = a_hi_bc69;
        y_bc67 = y_bc69;
        goto shared_BC67;
    }
    uint8_t value20 = RAM8(0x0004);
    if (value20 >= 8) {
        a_hi_bc67 = a_hi_bc69;
        y_bc67 = y_bc69;
        goto shared_BC67;
    }
    uint8_t value21 = RAM8(0x001F);
    uint8_t a1;
    if (!(value21 & 0x80)) {
        a1 = 9;
    } else {
        a1 = 8;
    }
    RAM8(0x0002) = a1;
    a_bd16 = (uint8_t)(value20 - RAM8(0x0003));
    a_hi_bd16 = a_hi_bc69;
    goto shared_BD16;
    shared_BCFB:;
    uint8_t value23 = RAM8(0x0004);
    uint8_t value24 = RAM8(0x0005);
    if ((value23 ^ 0x0F) >= value24) {
        if ((value23 ^ 0x0F) == value24) {
            a_hi_bd03 = a_hi_bcfb;
            y_bd03 = y_bcfb;
            goto shared_BD03;
        }
        uint8_t value25 = RAM8(0x0003);
        if ((uint8_t)(value23 - value25) & 0x80) {
            a_bd16 = (uint8_t)(value23 - value25);
            a_hi_bd16 = a_hi_bcfb;
            goto shared_BD16;
        }
        a_hi_bd12 = a_hi_bcfb;
        y_bd12 = y_bcfb;
        goto shared_BD12;
    }
    a_hi_bd03 = a_hi_bcfb;
    y_bd03 = y_bcfb;
    goto shared_BD03;
    shared_BD12:;
    r->a = (a_hi_bd12 << 8) | a;
    r->y = y_bd12;
    r->c = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BCD4:;
    RAM8(0x0002) = 6;
    r->a = (a_hi_bcd4 << 8) | 6;
    r->y = y_bcd4;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BCB5:;
    uint8_t value26 = RAM8(0x0004);
    if (value26 < RAM8(0x0005)) {
        uint8_t value28 = RAM8(0x0003);
        if ((uint8_t)(value26 - value28) & 0x80) {
            a_bd16 = (uint8_t)(value26 - value28);
            a_hi_bd16 = a_hi_bcb5;
            goto shared_BD16;
        }
        a_hi_bcc6 = a_hi_bcb5;
        y_bcc6 = y_bcb5;
        goto shared_BCC6;
    }
    RAM8(0x0002) = 5;
    r->a = (a_hi_bcb5 << 8) | 5;
    r->y = y_bcb5;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BCC6:;
    r->a = (a_hi_bcc6 << 8) | a;
    r->y = y_bcc6;
    r->c = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BC8F:;
    RAM8(0x0002) = 4;
    r->a = (a_hi_bc8f << 8) | 4;
    r->y = y_bc8f;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BD16:;
    uint8_t a2 = (uint8_t)((a_bd16 ^ 0xFF) + 1);
    uint8_t a_hi1 = a_hi_bd16;
    for (;;) {
        RAM8(0x0003) = a2;
        RAM8(0x0004) = 0x0F;
        uint8_t value29 = RAM8(0x0008);
        uint8_t a3;
        if (!((uint8_t)((value29 & 0x7F) - 1) & 0x80)) {
            a3 = (uint8_t)((value29 & 0x7F) - 1);
        } else {
            a3 = (uint8_t)(RAM8(0x009C) - 1);
        }
        uint8_t a4;
        if (!(value29 & 0x80)) {
            a4 = a3;
        } else {
            a4 = a3 | 0x80;
        }
        RAM8(0x0008) = a4;
        uint8_t value32;
        BUS8_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + RAM16(0x0008), value32);
        uint8_t value33;
        BUS8_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1), value33);
        RAM8(0x0007) = value33;
        uint8_t value34;
        BUS8_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2), value34);
        RAM8(0x0006) = value34;
        if ((value34 & 0xF0) != 0x10) {
            RAM8(0x0006) = 0;
        }
        uint8_t value35 = RAM8(0x0007);
        if ((value35 & 7) == 0) {
            uint8_t value36 = RAM8(0x0006);
            if ((value36 & 7) != 0) {
                if ((value36 & 7) != 4) {
                    if ((value36 & 7) != 5) {
                        if ((value36 & 7) != 6) {
                            if ((value36 & 7) != 7) {
                                r->a = (((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8 | (value36 & 7);
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            if (RAM8(0x0002) < 8) {
                                RAM8(0x0002) = 7;
                            }
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value38 = RAM8(0x0004);
                        uint8_t value39 = RAM8(0x0003);
                        if (!((uint8_t)(value38 - value39) & 0x80)) {
                            RAM8(0x0004) = (uint8_t)(value38 - value39);
                            if (!(RAM8(0x001F) & 0x80)) {
                                uint8_t value41 = RAM8(0x0004);
                                if ((value41 ^ 0x0F) >= RAM8(0x0005)) {
                                    RAM8(0x0002) = 6;
                                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                    r->c = 1;
                                    r->mf = 1;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    RETURN_RTS(c);
                                }
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value41 ^ 0x0F);
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            if (RAM8(0x001E) != 0) {
                                uint8_t value44 = RAM8(0x0004);
                                if ((value44 ^ 0x0F) >= RAM8(0x0005)) {
                                    RAM8(0x0002) = 6;
                                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                    r->c = 1;
                                    r->mf = 1;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    RETURN_RTS(c);
                                }
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value44 ^ 0x0F);
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            uint8_t value46 = RAM8(0x0004);
                            if (value46 >= 0x0E) {
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value46;
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            if ((value46 ^ 0x0F) >= RAM8(0x0005)) {
                                RAM8(0x0002) = 6;
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 1;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value46 ^ 0x0F);
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0002) = 6;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x0002) < 8) {
                        RAM8(0x0002) = 5;
                    }
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value49 = RAM8(0x0004);
                uint8_t value50 = RAM8(0x0003);
                if (!((uint8_t)(value49 - value50) & 0x80)) {
                    RAM8(0x0004) = (uint8_t)(value49 - value50);
                    if (!(RAM8(0x001F) & 0x80)) {
                        uint8_t value52 = RAM8(0x0004);
                        uint8_t value53 = RAM8(0x0005);
                        if (value52 == value53) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if (value52 < value53) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value52;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x001E) != 0) {
                        uint8_t value55 = RAM8(0x0004);
                        uint8_t value56 = RAM8(0x0005);
                        if (value55 == value56) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if (value55 < value56) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value55;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value57 = RAM8(0x0004);
                    if (value57 >= 0x0E) {
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value57;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value58 = RAM8(0x0005);
                    if (value57 == value58) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (value57 < value58) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value57;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 4;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value59 = RAM8(0x0003);
            if (!((uint8_t)(value59 - 0x10) & 0x80)) {
                a2 = (uint8_t)(value59 - 0x10);
                a_hi1 = (((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8;
                continue;
            }
            uint8_t value60 = RAM8(0x0002);
            if (value60 != 0) {
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value60;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value60;
            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((value35 & 7) >= 4) {
            uint8_t value61 = RAM8(0x0006);
            if ((value61 & 7) != 0) {
                if ((value61 & 7) != 4) {
                    if ((value61 & 7) != 5) {
                        if ((value61 & 7) != 6) {
                            if ((value61 & 7) != 7) {
                                r->a = (((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8 | (value61 & 7);
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            if (RAM8(0x0002) < 8) {
                                RAM8(0x0002) = 7;
                            }
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value63 = RAM8(0x0004);
                        uint8_t value64 = RAM8(0x0003);
                        if (!((uint8_t)(value63 - value64) & 0x80)) {
                            RAM8(0x0004) = (uint8_t)(value63 - value64);
                            if (!(RAM8(0x001F) & 0x80)) {
                                uint8_t value66 = RAM8(0x0004);
                                if ((value66 ^ 0x0F) >= RAM8(0x0005)) {
                                    RAM8(0x0002) = 6;
                                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                    r->c = 1;
                                    r->mf = 1;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    RETURN_RTS(c);
                                }
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value66 ^ 0x0F);
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            if (RAM8(0x001E) != 0) {
                                uint8_t value69 = RAM8(0x0004);
                                if ((value69 ^ 0x0F) >= RAM8(0x0005)) {
                                    RAM8(0x0002) = 6;
                                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                    r->c = 1;
                                    r->mf = 1;
                                    r->xf = 0;
                                    r->db = 0x7E;
                                    r->dp = 0;
                                    RETURN_RTS(c);
                                }
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value69 ^ 0x0F);
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            uint8_t value71 = RAM8(0x0004);
                            if (value71 >= 0x0E) {
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value71;
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 0;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            if ((value71 ^ 0x0F) >= RAM8(0x0005)) {
                                RAM8(0x0002) = 6;
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 1;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value71 ^ 0x0F);
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0002) = 6;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x0002) < 8) {
                        RAM8(0x0002) = 5;
                    }
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value74 = RAM8(0x0004);
                uint8_t value75 = RAM8(0x0003);
                if (!((uint8_t)(value74 - value75) & 0x80)) {
                    RAM8(0x0004) = (uint8_t)(value74 - value75);
                    if (!(RAM8(0x001F) & 0x80)) {
                        uint8_t value77 = RAM8(0x0004);
                        uint8_t value78 = RAM8(0x0005);
                        if (value77 == value78) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if (value77 < value78) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value77;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x001E) != 0) {
                        uint8_t value80 = RAM8(0x0004);
                        uint8_t value81 = RAM8(0x0005);
                        if (value80 == value81) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if (value80 < value81) {
                            RAM8(0x0002) = 4;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value80;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value82 = RAM8(0x0004);
                    if (value82 >= 0x0E) {
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value82;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value83 = RAM8(0x0005);
                    if (value82 == value83) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (value82 < value83) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value82;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 4;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value84 = RAM8(0x0003);
            if (!((uint8_t)(value84 - 0x10) & 0x80)) {
                a2 = (uint8_t)(value84 - 0x10);
                a_hi1 = (((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8;
                continue;
            }
            uint8_t value85 = RAM8(0x0002);
            if (value85 != 0) {
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value85;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value85;
            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((value35 & 7) == 3) {
            uint8_t value86 = RAM8(0x001E);
            if (value86 != 0) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value86;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value87 = RAM8(0x0002);
            if (value87 != 0) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value87;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value88 = RAM8(0x0004);
            uint8_t value89 = RAM8(0x0003);
            if ((uint8_t)(value88 - value89) & 0x80) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value88 - value89);
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)(value88 - value89) < 8) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value88 - value89);
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value90 = RAM8(0x001F);
            uint8_t a5;
            if (!(value90 & 0x80)) {
                a5 = 8;
            } else {
                a5 = 9;
            }
            RAM8(0x0002) = a5;
            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a5;
            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((((value35 & 7) ^ RAM8(0x001B)) & 3) == 3) {
            uint8_t value92 = RAM8(0x001E);
            if (value92 != 0) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value92;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value93 = RAM8(0x0002);
            if (value93 != 0) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value93;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value94 = RAM8(0x0004);
            uint8_t value95 = RAM8(0x0003);
            if ((uint8_t)(value94 - value95) & 0x80) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value94 - value95);
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)(value94 - value95) < 8) {
                RAM8(0x0002) = 0;
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value94 - value95);
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value96 = RAM8(0x001F);
            uint8_t a6;
            if (!(value96 & 0x80)) {
                a6 = 8;
            } else {
                a6 = 9;
            }
            RAM8(0x0002) = a6;
            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a6;
            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value97 = RAM8(0x0006);
        if ((value97 & 7) != 0) {
            if ((value97 & 7) != 4) {
                if ((value97 & 7) != 5) {
                    if ((value97 & 7) != 6) {
                        if ((value97 & 7) != 7) {
                            r->a = (((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8 | (value97 & 7);
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if (RAM8(0x0002) < 8) {
                            RAM8(0x0002) = 7;
                        }
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value99 = RAM8(0x0004);
                    uint8_t value100 = RAM8(0x0003);
                    if (!((uint8_t)(value99 - value100) & 0x80)) {
                        RAM8(0x0004) = (uint8_t)(value99 - value100);
                        if (!(RAM8(0x001F) & 0x80)) {
                            uint8_t value102 = RAM8(0x0004);
                            if ((value102 ^ 0x0F) >= RAM8(0x0005)) {
                                RAM8(0x0002) = 6;
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 1;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value102 ^ 0x0F);
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if (RAM8(0x001E) != 0) {
                            uint8_t value105 = RAM8(0x0004);
                            if ((value105 ^ 0x0F) >= RAM8(0x0005)) {
                                RAM8(0x0002) = 6;
                                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                                r->c = 1;
                                r->mf = 1;
                                r->xf = 0;
                                r->db = 0x7E;
                                r->dp = 0;
                                RETURN_RTS(c);
                            }
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value105 ^ 0x0F);
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        uint8_t value107 = RAM8(0x0004);
                        if (value107 >= 0x0E) {
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value107;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        if ((value107 ^ 0x0F) >= RAM8(0x0005)) {
                            RAM8(0x0002) = 6;
                            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | (value107 ^ 0x0F);
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 6;
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (RAM8(0x0002) < 8) {
                    RAM8(0x0002) = 5;
                }
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value110 = RAM8(0x0004);
            uint8_t value111 = RAM8(0x0003);
            if (!((uint8_t)(value110 - value111) & 0x80)) {
                RAM8(0x0004) = (uint8_t)(value110 - value111);
                if (!(RAM8(0x001F) & 0x80)) {
                    uint8_t value113 = RAM8(0x0004);
                    uint8_t value114 = RAM8(0x0005);
                    if (value113 == value114) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (value113 < value114) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value113;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (RAM8(0x001E) != 0) {
                    uint8_t value116 = RAM8(0x0004);
                    uint8_t value117 = RAM8(0x0005);
                    if (value116 == value117) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (value116 < value117) {
                        RAM8(0x0002) = 4;
                        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value116;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value118 = RAM8(0x0004);
                if (value118 >= 0x0E) {
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value118;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value119 = RAM8(0x0005);
                if (value118 == value119) {
                    RAM8(0x0002) = 4;
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (value118 < value119) {
                    RAM8(0x0002) = 4;
                    r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
                    r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value118;
                r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            RAM8(0x0002) = 4;
            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | 4;
            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value120 = RAM8(0x0003);
        if (!((uint8_t)(value120 - 0x10) & 0x80)) {
            a2 = (uint8_t)(value120 - 0x10);
            a_hi1 = (((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8;
            continue;
        }
        uint8_t value121 = RAM8(0x0002);
        if (value121 != 0) {
            r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value121;
            r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->a = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1 >> 8 << 8) | value121;
        r->y = ((((a_hi1 << 8) | value32) & 0xFF) << 1 << 1) + 2;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    shared_BC67:;
    r->a = (a_hi_bc67 << 8) | a;
    r->y = y_bc67;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BD03:;
    RAM8(0x0002) = 7;
    r->a = (a_hi_bd03 << 8) | 7;
    r->y = y_bd03;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1BC37, SOM_RTS, "hand", test_horizontal_terrain_shape_and_preceding_cells, 0, L_B | L_Y | L_C, 1, 1, 0, 478, 267)
