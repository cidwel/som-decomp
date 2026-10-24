#include "som_c.h"

/* C1BE15 test_vertical_terrain_shape_and_preceding_cells   [class C, 459 bytes, 260 instructions]
 * Source: src/rom/test_vertical_terrain_shape_and_preceding_cells.s
 * Documented in docs/actor-map-terrain-queries.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYC.
 */
static void test_vertical_terrain_shape_and_preceding_cells(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t a_hi_be33 = 0;
    uint16_t y_be33 = 0;
    uint8_t a_hi_be47 = 0;
    uint16_t y_be47 = 0;
    uint8_t a_hi_bedb = 0;
    uint16_t y_bedb = 0;
    uint8_t a_hi_bef2 = 0;
    uint16_t y_bef2 = 0;
    uint8_t a_hi_beb4 = 0;
    uint16_t y_beb4 = 0;
    uint8_t a_hi_be93 = 0;
    uint16_t y_be93 = 0;
    uint8_t a_hi_be76 = 0;
    uint16_t y_be76 = 0;
    uint8_t a_hi_be87 = 0;
    uint16_t y_be87 = 0;
    uint8_t a_be40 = 0;
    uint8_t a_hi_be40 = 0;
    uint8_t a_hi_be45 = 0;
    uint16_t y_be45 = 0;
    uint8_t a_hi_bee3 = 0;
    uint16_t y_bee3 = 0;
    uint8_t a_bef6 = 0;
    uint8_t a_hi_bef6 = 0;
    RAM8(0x0003) = 8;
    RAM8(0x0002) = 0;
    uint8_t value = RAM8(0x0007);
    if ((value & 7) == 0) {
        a_hi_be33 = a_hi;
        y_be33 = y;
        goto shared_BE33;
    }
    if ((value & 7) >= 4) {
        a_hi_be33 = a_hi;
        y_be33 = y;
        goto shared_BE33;
    }
    if ((value & 7) == 3) {
        a_hi_be47 = a_hi;
        y_be47 = y;
        goto shared_BE47;
    }
    if ((((value & 7) ^ RAM8(0x001B)) & 3) == 3) {
        a_hi_be47 = a_hi;
        y_be47 = y;
        goto shared_BE47;
    }
    a_hi_be33 = a_hi;
    y_be33 = y;
    shared_BE33:;
    uint8_t value3 = RAM8(0x0006);
    if ((value3 & 7) != 0) {
        if ((value3 & 7) != 4) {
            if ((value3 & 7) != 5) {
                if ((value3 & 7) != 6) {
                    if ((value3 & 7) != 7) {
                        r->a = a_hi_be33 << 8 | (value3 & 7);
                        r->y = y_be33;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (!(RAM8(0x001E) & 0x80)) {
                        a_hi_bedb = a_hi_be33;
                        y_bedb = y_be33;
                        goto shared_BEDB;
                    }
                    if (RAM8(0x001F) != 0) {
                        a_hi_bedb = a_hi_be33;
                        y_bedb = y_be33;
                        goto shared_BEDB;
                    }
                    if (RAM8(0x0005) < 4) {
                        a_hi_bef2 = a_hi_be33;
                        y_bef2 = y_be33;
                        goto shared_BEF2;
                    }
                    a_hi_bedb = a_hi_be33;
                    y_bedb = y_be33;
                    goto shared_BEDB;
                }
                uint8_t value7 = RAM8(0x0004);
                uint8_t value8 = RAM8(0x0005);
                if ((value7 ^ 0x0F) < value8) {
                    uint8_t value9 = RAM8(0x0003);
                    if ((uint8_t)(value8 - value9) & 0x80) {
                        a_hi_beb4 = a_hi_be33;
                        y_beb4 = y_be33;
                        goto shared_BEB4;
                    }
                    if (((uint8_t)(value8 - value9) ^ 0x0F) >= value7) {
                        a_hi_beb4 = a_hi_be33;
                        y_beb4 = y_be33;
                        goto shared_BEB4;
                    }
                    r->a = (a_hi_be33 << 8) | ((uint8_t)(value8 - value9) ^ 0x0F);
                    r->y = y_be33;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                a_hi_beb4 = a_hi_be33;
                y_beb4 = y_be33;
                goto shared_BEB4;
            }
            uint8_t value10 = RAM8(0x0005);
            uint8_t value11 = RAM8(0x0004);
            if (value10 >= value11) {
                if (value10 == value11) {
                    a_hi_be93 = a_hi_be33;
                    y_be93 = y_be33;
                    goto shared_BE93;
                }
                uint8_t value12 = RAM8(0x0003);
                if ((uint8_t)(value10 - value12) & 0x80) {
                    a_hi_be93 = a_hi_be33;
                    y_be93 = y_be33;
                    goto shared_BE93;
                }
                if ((uint8_t)(value10 - value12) < value11) {
                    a_hi_be93 = a_hi_be33;
                    y_be93 = y_be33;
                    goto shared_BE93;
                }
                if ((uint8_t)(value10 - value12) == value11) {
                    a_hi_be93 = a_hi_be33;
                    y_be93 = y_be33;
                    goto shared_BE93;
                }
                r->a = (a_hi_be33 << 8) | (uint8_t)(value10 - value12);
                r->y = y_be33;
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            a_hi_be93 = a_hi_be33;
            y_be93 = y_be33;
            goto shared_BE93;
        }
        if (RAM8(0x001E) & 0x80) {
            a_hi_be76 = a_hi_be33;
            y_be76 = y_be33;
            goto shared_BE76;
        }
        if (RAM8(0x001F) != 0) {
            a_hi_be76 = a_hi_be33;
            y_be76 = y_be33;
            goto shared_BE76;
        }
        if (RAM8(0x0005) < 4) {
            a_hi_be87 = a_hi_be33;
            y_be87 = y_be33;
            goto shared_BE87;
        }
        a_hi_be76 = a_hi_be33;
        y_be76 = y_be33;
        goto shared_BE76;
    }
    uint8_t value16 = RAM8(0x0005);
    uint8_t value17 = RAM8(0x0003);
    if (!((uint8_t)(value16 - value17) & 0x80)) {
        r->a = (a_hi_be33 << 8) | (uint8_t)(value16 - value17);
        r->y = y_be33;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    a_be40 = (uint8_t)(value16 - value17);
    a_hi_be40 = a_hi_be33;
    goto shared_BE40;
    shared_BE47:;
    if (RAM8(0x001F) != 0) {
        a_hi_be45 = a_hi_be47;
        y_be45 = y_be47;
        goto shared_BE45;
    }
    uint8_t value19 = RAM8(0x0005);
    if (value19 >= 8) {
        a_hi_be45 = a_hi_be47;
        y_be45 = y_be47;
        goto shared_BE45;
    }
    uint8_t value20 = RAM8(0x001E);
    uint8_t a1;
    if (!(value20 & 0x80)) {
        a1 = 9;
    } else {
        a1 = 8;
    }
    RAM8(0x0002) = a1;
    uint8_t value21 = RAM8(0x0003);
    if ((uint8_t)(value19 - value21) & 0x80) {
        a_be40 = (uint8_t)(value19 - value21);
        a_hi_be40 = a_hi_be47;
        goto shared_BE40;
    }
    r->a = (a_hi_be47 << 8) | (uint8_t)(value19 - value21);
    r->y = y_be47;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BEDB:;
    uint8_t value22 = RAM8(0x0004);
    uint8_t value23 = RAM8(0x0005);
    if ((value22 ^ 0x0F) >= value23) {
        if ((value22 ^ 0x0F) == value23) {
            a_hi_bee3 = a_hi_bedb;
            y_bee3 = y_bedb;
            goto shared_BEE3;
        }
        uint8_t value24 = RAM8(0x0003);
        if ((uint8_t)(value23 - value24) & 0x80) {
            a_bef6 = (uint8_t)(value23 - value24);
            a_hi_bef6 = a_hi_bedb;
            goto shared_BEF6;
        }
        a_hi_bef2 = a_hi_bedb;
        y_bef2 = y_bedb;
        goto shared_BEF2;
    }
    a_hi_bee3 = a_hi_bedb;
    y_bee3 = y_bedb;
    goto shared_BEE3;
    shared_BEF2:;
    r->a = (a_hi_bef2 << 8) | a;
    r->y = y_bef2;
    r->c = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BEB4:;
    RAM8(0x0002) = 6;
    r->a = (a_hi_beb4 << 8) | 6;
    r->y = y_beb4;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BE93:;
    RAM8(0x0002) = 5;
    r->a = (a_hi_be93 << 8) | 5;
    r->y = y_be93;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BE76:;
    uint8_t value25 = RAM8(0x0005);
    if (value25 < RAM8(0x0004)) {
        uint8_t value27 = RAM8(0x0003);
        if ((uint8_t)(value25 - value27) & 0x80) {
            a_bef6 = (uint8_t)(value25 - value27);
            a_hi_bef6 = a_hi_be76;
            goto shared_BEF6;
        }
        a_hi_be87 = a_hi_be76;
        y_be87 = y_be76;
        goto shared_BE87;
    }
    RAM8(0x0002) = 4;
    r->a = (a_hi_be76 << 8) | 4;
    r->y = y_be76;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BE87:;
    r->a = (a_hi_be87 << 8) | a;
    r->y = y_be87;
    r->c = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BE40:;
    a_bef6 = a_be40;
    a_hi_bef6 = a_hi_be40;
    goto shared_BEF6;
    shared_BE45:;
    r->a = (a_hi_be45 << 8) | a;
    r->y = y_be45;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BEE3:;
    RAM8(0x0002) = 7;
    r->a = (a_hi_bee3 << 8) | 7;
    r->y = y_bee3;
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_BEF6:;
    RAM8(0x0003) = (uint8_t)((a_bef6 ^ 0xFF) + 1);
    RAM8(0x0005) = 0x0F;
    uint8_t value28 = RAM8(0x0009);
    uint8_t value29 = RAM8(0x0008);
    RAM8(0x0008) <<= 1;
    uint8_t a2;
    if (!((uint8_t)(((uint8_t)((value28 << 1) | (value29 >> 7)) & 0x7F) - 1) & 0x80)) {
        a2 = (uint8_t)(((uint8_t)((value28 << 1) | (value29 >> 7)) & 0x7F) - 1);
    } else {
        a2 = (uint8_t)(RAM8(0x009D) - 1);
    }
    RAM8(0x0009) = a2 >> 1;
    RAM8(0x0008) = (RAM8(0x0008) >> 1) | ((a2 & 1) << 7);
    uint8_t value33;
    BUS8_PTR(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + RAM16(0x0008), RAM8(0x000C), value33);
    uint8_t value34;
    BUS8_PTR(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1), RAM8(0x000F), value34);
    RAM8(0x0007) = value34;
    uint8_t value35;
    BUS8_PTR(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2), RAM8(0x000F), value35);
    RAM8(0x0006) = value35;
    if ((value35 & 0xF0) != 0x10) {
        RAM8(0x0006) = 0;
    }
    uint8_t value36 = RAM8(0x0007);
    if ((value36 & 7) == 0) {
        uint8_t value37 = RAM8(0x0006);
        if ((value37 & 7) != 0) {
            if ((value37 & 7) != 4) {
                if ((value37 & 7) != 5) {
                    if ((value37 & 7) != 6) {
                        if ((value37 & 7) != 7) {
                            r->a = (((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8 | (value37 & 7);
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
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
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x001E) & 0x80) {
                        uint8_t value40 = RAM8(0x0005);
                        uint8_t value41 = RAM8(0x0003);
                        if (((uint8_t)(value40 - value41) ^ 0x0F) < RAM8(0x0004)) {
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value40 - value41) ^ 0x0F);
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0002) = 6;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x001F) != 0) {
                        uint8_t value44 = RAM8(0x0005);
                        uint8_t value45 = RAM8(0x0003);
                        if (((uint8_t)(value44 - value45) ^ 0x0F) < RAM8(0x0004)) {
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value44 - value45) ^ 0x0F);
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0002) = 6;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value47 = RAM8(0x0005);
                    if (value47 >= 0x0C) {
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value47;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value48 = RAM8(0x0003);
                    if (((uint8_t)(value47 - value48) ^ 0x0F) < RAM8(0x0004)) {
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value47 - value48) ^ 0x0F);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 6;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (!(RAM8(0x001E) & 0x80)) {
                    uint8_t value51 = RAM8(0x0005);
                    uint8_t value52 = RAM8(0x0003);
                    uint8_t value53 = RAM8(0x0004);
                    if ((uint8_t)(value51 - value52) >= value53) {
                        if ((uint8_t)(value51 - value52) == value53) {
                            RAM8(0x0002) = 5;
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value51 - value52);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 5;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (RAM8(0x001F) != 0) {
                    uint8_t value55 = RAM8(0x0005);
                    uint8_t value56 = RAM8(0x0003);
                    uint8_t value57 = RAM8(0x0004);
                    if ((uint8_t)(value55 - value56) >= value57) {
                        if ((uint8_t)(value55 - value56) == value57) {
                            RAM8(0x0002) = 5;
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value55 - value56);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 5;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value58 = RAM8(0x0005);
                if (value58 >= 0x0C) {
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value58;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value59 = RAM8(0x0003);
                uint8_t value60 = RAM8(0x0004);
                if ((uint8_t)(value58 - value59) >= value60) {
                    if ((uint8_t)(value58 - value59) == value60) {
                        RAM8(0x0002) = 5;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value58 - value59);
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 5;
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (RAM8(0x0002) < 8) {
                RAM8(0x0002) = 4;
            }
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value62 = RAM8(0x0002);
        if (value62 != 0) {
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value62;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value62;
        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if ((value36 & 7) >= 4) {
        uint8_t value63 = RAM8(0x0006);
        if ((value63 & 7) != 0) {
            if ((value63 & 7) != 4) {
                if ((value63 & 7) != 5) {
                    if ((value63 & 7) != 6) {
                        if ((value63 & 7) != 7) {
                            r->a = (((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8 | (value63 & 7);
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
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
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x001E) & 0x80) {
                        uint8_t value66 = RAM8(0x0005);
                        uint8_t value67 = RAM8(0x0003);
                        if (((uint8_t)(value66 - value67) ^ 0x0F) < RAM8(0x0004)) {
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value66 - value67) ^ 0x0F);
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0002) = 6;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    if (RAM8(0x001F) != 0) {
                        uint8_t value70 = RAM8(0x0005);
                        uint8_t value71 = RAM8(0x0003);
                        if (((uint8_t)(value70 - value71) ^ 0x0F) < RAM8(0x0004)) {
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value70 - value71) ^ 0x0F);
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 0;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0002) = 6;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value73 = RAM8(0x0005);
                    if (value73 >= 0x0C) {
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value73;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    uint8_t value74 = RAM8(0x0003);
                    if (((uint8_t)(value73 - value74) ^ 0x0F) < RAM8(0x0004)) {
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value73 - value74) ^ 0x0F);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 6;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (!(RAM8(0x001E) & 0x80)) {
                    uint8_t value77 = RAM8(0x0005);
                    uint8_t value78 = RAM8(0x0003);
                    uint8_t value79 = RAM8(0x0004);
                    if ((uint8_t)(value77 - value78) >= value79) {
                        if ((uint8_t)(value77 - value78) == value79) {
                            RAM8(0x0002) = 5;
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value77 - value78);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 5;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (RAM8(0x001F) != 0) {
                    uint8_t value81 = RAM8(0x0005);
                    uint8_t value82 = RAM8(0x0003);
                    uint8_t value83 = RAM8(0x0004);
                    if ((uint8_t)(value81 - value82) >= value83) {
                        if ((uint8_t)(value81 - value82) == value83) {
                            RAM8(0x0002) = 5;
                            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                            r->c = 1;
                            r->mf = 1;
                            r->xf = 0;
                            r->db = 0x7E;
                            r->dp = 0;
                            RETURN_RTS(c);
                        }
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value81 - value82);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 5;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value84 = RAM8(0x0005);
                if (value84 >= 0x0C) {
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value84;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value85 = RAM8(0x0003);
                uint8_t value86 = RAM8(0x0004);
                if ((uint8_t)(value84 - value85) >= value86) {
                    if ((uint8_t)(value84 - value85) == value86) {
                        RAM8(0x0002) = 5;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value84 - value85);
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 5;
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (RAM8(0x0002) < 8) {
                RAM8(0x0002) = 4;
            }
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value88 = RAM8(0x0002);
        if (value88 != 0) {
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value88;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value88;
        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if ((value36 & 7) == 3) {
        uint8_t value89 = RAM8(0x001F);
        if (value89 != 0) {
            RAM8(0x0002) = 0;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value89;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value90 = RAM8(0x0002);
        if (value90 != 0) {
            RAM8(0x0002) = 0;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value90;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value91 = RAM8(0x0005);
        uint8_t value92 = RAM8(0x0003);
        if ((uint8_t)(value91 - value92) < 8) {
            RAM8(0x0002) = 0;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value91 - value92);
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value93 = RAM8(0x001E);
        uint8_t a3;
        if (!(value93 & 0x80)) {
            a3 = 8;
        } else {
            a3 = 9;
        }
        RAM8(0x0002) = a3;
        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a3;
        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if ((((value36 & 7) ^ RAM8(0x001B)) & 3) == 3) {
        uint8_t value95 = RAM8(0x001F);
        if (value95 != 0) {
            RAM8(0x0002) = 0;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value95;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value96 = RAM8(0x0002);
        if (value96 != 0) {
            RAM8(0x0002) = 0;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value96;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value97 = RAM8(0x0005);
        uint8_t value98 = RAM8(0x0003);
        if ((uint8_t)(value97 - value98) < 8) {
            RAM8(0x0002) = 0;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value97 - value98);
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value99 = RAM8(0x001E);
        uint8_t a4;
        if (!(value99 & 0x80)) {
            a4 = 8;
        } else {
            a4 = 9;
        }
        RAM8(0x0002) = a4;
        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a4;
        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value100 = RAM8(0x0006);
    if ((value100 & 7) != 0) {
        if ((value100 & 7) != 4) {
            if ((value100 & 7) != 5) {
                if ((value100 & 7) != 6) {
                    if ((value100 & 7) != 7) {
                        r->a = (((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8 | (value100 & 7);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
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
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (RAM8(0x001E) & 0x80) {
                    uint8_t value103 = RAM8(0x0005);
                    uint8_t value104 = RAM8(0x0003);
                    if (((uint8_t)(value103 - value104) ^ 0x0F) < RAM8(0x0004)) {
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value103 - value104) ^ 0x0F);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 6;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                if (RAM8(0x001F) != 0) {
                    uint8_t value107 = RAM8(0x0005);
                    uint8_t value108 = RAM8(0x0003);
                    if (((uint8_t)(value107 - value108) ^ 0x0F) < RAM8(0x0004)) {
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value107 - value108) ^ 0x0F);
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 0;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    RAM8(0x0002) = 6;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value110 = RAM8(0x0005);
                if (value110 >= 0x0C) {
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value110;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                uint8_t value111 = RAM8(0x0003);
                if (((uint8_t)(value110 - value111) ^ 0x0F) < RAM8(0x0004)) {
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | ((uint8_t)(value110 - value111) ^ 0x0F);
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 6;
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 6;
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (!(RAM8(0x001E) & 0x80)) {
                uint8_t value114 = RAM8(0x0005);
                uint8_t value115 = RAM8(0x0003);
                uint8_t value116 = RAM8(0x0004);
                if ((uint8_t)(value114 - value115) >= value116) {
                    if ((uint8_t)(value114 - value115) == value116) {
                        RAM8(0x0002) = 5;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value114 - value115);
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 5;
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            if (RAM8(0x001F) != 0) {
                uint8_t value118 = RAM8(0x0005);
                uint8_t value119 = RAM8(0x0003);
                uint8_t value120 = RAM8(0x0004);
                if ((uint8_t)(value118 - value119) >= value120) {
                    if ((uint8_t)(value118 - value119) == value120) {
                        RAM8(0x0002) = 5;
                        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                        r->c = 1;
                        r->mf = 1;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        RETURN_RTS(c);
                    }
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value118 - value119);
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 0;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM8(0x0002) = 5;
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value121 = RAM8(0x0005);
            if (value121 >= 0x0C) {
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value121;
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint8_t value122 = RAM8(0x0003);
            uint8_t value123 = RAM8(0x0004);
            if ((uint8_t)(value121 - value122) >= value123) {
                if ((uint8_t)(value121 - value122) == value123) {
                    RAM8(0x0002) = 5;
                    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
                    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                    r->c = 1;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | (uint8_t)(value121 - value122);
                r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            RAM8(0x0002) = 5;
            r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | 5;
            r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (RAM8(0x0002) < 8) {
            RAM8(0x0002) = 4;
        }
        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | a;
        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value125 = RAM8(0x0002);
    if (value125 != 0) {
        r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value125;
        r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1 >> 8 << 8) | value125;
    r->y = ((((a_hi_bef6 << 8) | value33) & 0xFF) << 1 << 1) + 2;
    r->c = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1BE15, SOM_RTS, "hand", test_vertical_terrain_shape_and_preceding_cells, 0, L_B | L_Y | L_C, 1, 1, 0, 459, 260)
