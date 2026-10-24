#include "som_c.h"

/* C1CDCD scan_active_map_contact_pool_for_one_hero   [class B, 140 bytes, 65 instructions]
 * Source: src/rom/scan_active_map_contact_pool_for_one_hero.s
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void scan_active_map_contact_pool_for_one_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_cdd4 = 0;
    uint16_t y_cdd4 = 0;
    bool carry_cdd4 = 0;
    bool overflow_cdd4 = 0;
    uint8_t a_hi_ce20 = 0;
    uint16_t x_ce20 = 0;
    uint8_t a_hi_ce202 = 0;
    uint16_t x_ce202 = 0;
    uint8_t a_hi_cdec = 0;
    uint16_t x_cdec = 0;
    uint16_t y_cdec = 0;
    uint8_t a_hi_ce29 = 0;
    uint16_t x_ce29 = 0;
    uint16_t y_ce29 = 0;
    uint8_t a_hi_ce06 = 0;
    uint16_t x_ce06 = 0;
    uint16_t y_ce06 = 0;
    uint8_t a_hi_ce062 = 0;
    uint8_t x_ce062 = 0;
    uint8_t y_ce062 = 0;
    uint8_t a_hi_ce063 = 0;
    uint8_t x_ce063 = 0;
    uint8_t y_ce063 = 0;
    uint8_t a_hi_ce064 = 0;
    uint16_t x_ce064 = 0;
    uint16_t y_ce064 = 0;
    uint8_t a_hi_ce43 = 0;
    uint16_t x_ce43 = 0;
    uint16_t y_ce43 = 0;
    uint16_t direct_page_ce43 = 0;
    uint8_t data_bank_ce43 = 0;
    uint8_t a_hi_ce432 = 0;
    uint8_t x_ce432 = 0;
    uint8_t y_ce432 = 0;
    uint16_t direct_page_ce432 = 0;
    uint8_t data_bank_ce432 = 0;
    uint8_t a_hi_ce433 = 0;
    uint8_t x_ce433 = 0;
    uint8_t y_ce433 = 0;
    uint16_t direct_page_ce433 = 0;
    uint8_t data_bank_ce433 = 0;
    uint8_t a_hi_ce434 = 0;
    uint16_t x_ce434 = 0;
    uint16_t y_ce434 = 0;
    uint16_t direct_page_ce434 = 0;
    uint8_t data_bank_ce434 = 0;
    uint8_t a_hi_cdec2 = 0;
    uint16_t x_cdec2 = 0;
    uint16_t y_cdec2 = 0;
    uint8_t a_hi_cdec3 = 0;
    uint8_t x_cdec3 = 0;
    uint8_t y_cdec3 = 0;
    uint8_t a_hi_ce292 = 0;
    uint16_t x_ce292 = 0;
    uint16_t y_ce292 = 0;
    uint16_t direct_page_ce29 = 0;
    uint8_t data_bank_ce29 = 0;
    uint8_t a_hi_ce293 = 0;
    uint8_t x_ce293 = 0;
    uint8_t y_ce293 = 0;
    uint16_t direct_page_ce292 = 0;
    uint8_t data_bank_ce292 = 0;
    uint8_t value = RAM8(0xE000 + x);
    if (value != 0) {
        if (value & 0x80) {
            a_hi_cdd4 = a >> 8;
            y_cdd4 = y;
            carry_cdd4 = carry;
            overflow_cdd4 = overflow;
            goto shared_CDD4;
        }
        if ((RAM8(0xE00E + x) | RAM8(ACTOR_STATUS_HIGH + x)) & 0x80) {
            a_hi_cdd4 = a >> 8;
            y_cdd4 = y;
            carry_cdd4 = carry;
            overflow_cdd4 = overflow;
            goto shared_CDD4;
        }
        uint8_t value4 = RAM8(0x00ED);
        if (value4 & 0x80) {
            if (RAM8(0x0082) != 0) {
                a_hi_ce20 = a >> 8;
                x_ce20 = x;
                goto shared_CE20;
            }
            uint8_t value6 = RAM8(0xE0C2 + x);
            if (value6 == 0) {
                a_hi_ce20 = a >> 8;
                x_ce20 = x;
                goto shared_CE20;
            }
            r->a = (a >> 8 << 8) | value6;
            r->z = value6 == 0;
            r->n = value6 & 0x80;
            r->v = value4 & 0x40;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCE1F, 0xC1D293); GUARD_JSR(c, sp_call, 0xCE1F); } /* probe_map_cell_contact_and_update_live_tile */
            bool m_ret = r->mf;
            uint16_t a_all = r->a;
            if (m_ret) {
                a_hi_ce20 = a_all >> 8;
                x_ce20 = x;
                goto shared_CE20;
            } else {
                a_hi_ce202 = a_all >> 8;
                x_ce202 = x;
                goto shared_CE20_1;
            }
        }
        if (RAM8(0xE02C + x) != 0) {
            a_hi_cdec = a >> 8;
            x_cdec = x;
            y_cdec = 0x0600;
            goto shared_CDEC;
        }
        r->v = value4 & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    a_hi_cdd4 = a >> 8;
    y_cdd4 = y;
    carry_cdd4 = carry;
    overflow_cdd4 = overflow;
    shared_CDD4:;
    r->a = (a_hi_cdd4 << 8) | (uint8_t)a;
    r->y = y_cdd4;
    r->c = carry_cdd4;
    r->v = overflow_cdd4;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CE20:;
    RAM8(0x0050) = 0x11;
    a_hi_ce29 = a_hi_ce20;
    x_ce29 = x_ce20;
    y_ce29 = 0x0600;
    goto shared_CE29;
    shared_CE20_1:;
    RAM8(0x0050) = 0x11;
    a_hi_ce29 = a_hi_ce202;
    x_ce29 = x_ce202;
    y_ce29 = 0x0600;
    goto shared_CE29;
    shared_CDEC:;
    uint8_t value8 = RAM8(0xE000 + y_cdec);
    if (value8 == 0) {
        a_hi_ce06 = a_hi_cdec;
        x_ce06 = x_cdec;
        y_ce06 = y_cdec;
        goto shared_CE06;
    }
    if (value8 & 0x80) {
        a_hi_ce06 = a_hi_cdec;
        x_ce06 = x_cdec;
        y_ce06 = y_cdec;
        goto shared_CE06;
    }
    uint8_t value9 = RAM8(0xE00B + x_cdec);
    uint8_t value10 = RAM8(0xE00B + y_cdec);
    if ((value9 ^ value10) & 0x80) {
        a_hi_ce06 = a_hi_cdec;
        x_ce06 = x_cdec;
        y_ce06 = y_cdec;
        goto shared_CE06;
    }
    if (((value9 ^ value10) & 3) == 3) {
        a_hi_ce06 = a_hi_cdec;
        x_ce06 = x_cdec;
        y_ce06 = y_cdec;
        goto shared_CE06;
    }
    r->a = a_hi_cdec << 8 | ((value9 ^ value10) & 3);
    r->x = x_cdec;
    r->y = y_cdec;
    r->c = ((value9 ^ value10) & 3) >= 3;
    r->z = ((value9 ^ value10) & 3) == 3;
    r->n = (uint8_t)(((value9 ^ value10) & 3) - 3) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE05, 0xC1CE59); GUARD_JSR(c, sp_call, 0xCE05); } /* prepare_fixed_radius_contact_distance */
    bool m_ret2 = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    if (m_ret2) {
        if (x_ret) {
            a_hi_ce062 = a_all2 >> 8;
            x_ce062 = (uint8_t)x_cdec;
            y_ce062 = (uint8_t)y_ret2;
            goto shared_CE06_1;
        } else {
            a_hi_ce06 = a_all2 >> 8;
            x_ce06 = x_cdec;
            y_ce06 = y_ret2;
            goto shared_CE06;
        }
    } else {
        if (x_ret) {
            a_hi_ce063 = a_all2 >> 8;
            x_ce063 = (uint8_t)x_cdec;
            y_ce063 = (uint8_t)y_ret2;
            goto shared_CE06_2;
        } else {
            a_hi_ce064 = a_all2 >> 8;
            x_ce064 = x_cdec;
            y_ce064 = y_ret2;
            goto shared_CE06_3;
        }
    }
    shared_CE29:;
    uint8_t value11 = RAM8(0xE000 + y_ce29);
    if (value11 == 0) {
        a_hi_ce43 = a_hi_ce29;
        x_ce43 = x_ce29;
        y_ce43 = y_ce29;
        direct_page_ce43 = 0;
        data_bank_ce43 = 0x7E;
        goto shared_CE43;
    }
    if (value11 & 0x80) {
        a_hi_ce43 = a_hi_ce29;
        x_ce43 = x_ce29;
        y_ce43 = y_ce29;
        direct_page_ce43 = 0;
        data_bank_ce43 = 0x7E;
        goto shared_CE43;
    }
    uint8_t value12 = RAM8(0xE00B + x_ce29);
    uint8_t value13 = RAM8(0xE00B + y_ce29);
    if ((value12 ^ value13) & 0x80) {
        a_hi_ce43 = a_hi_ce29;
        x_ce43 = x_ce29;
        y_ce43 = y_ce29;
        direct_page_ce43 = 0;
        data_bank_ce43 = 0x7E;
        goto shared_CE43;
    }
    if (((value12 ^ value13) & 3) == 3) {
        a_hi_ce43 = a_hi_ce29;
        x_ce43 = x_ce29;
        y_ce43 = y_ce29;
        direct_page_ce43 = 0;
        data_bank_ce43 = 0x7E;
        goto shared_CE43;
    }
    r->a = a_hi_ce29 << 8 | ((value12 ^ value13) & 3);
    r->x = x_ce29;
    r->y = y_ce29;
    r->c = ((value12 ^ value13) & 3) >= 3;
    r->z = ((value12 ^ value13) & 3) == 3;
    r->n = (uint8_t)(((value12 ^ value13) & 3) - 3) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE42, 0xC1CE62); GUARD_JSR(c, sp_call, 0xCE42); } /* resolve_toroidal_map_contact_distance_event_and_motion */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret3 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    if (m_ret3) {
        if (x_ret2) {
            a_hi_ce432 = a_all3 >> 8;
            x_ce432 = (uint8_t)x_ce29;
            y_ce432 = (uint8_t)y_ret3;
            direct_page_ce432 = dp_ret;
            data_bank_ce432 = db_ret;
            goto shared_CE43_1;
        } else {
            a_hi_ce43 = a_all3 >> 8;
            x_ce43 = x_ce29;
            y_ce43 = y_ret3;
            direct_page_ce43 = dp_ret;
            data_bank_ce43 = db_ret;
            goto shared_CE43;
        }
    } else {
        if (x_ret2) {
            a_hi_ce433 = a_all3 >> 8;
            x_ce433 = (uint8_t)x_ce29;
            y_ce433 = (uint8_t)y_ret3;
            direct_page_ce433 = dp_ret;
            data_bank_ce433 = db_ret;
            goto shared_CE43_2;
        } else {
            a_hi_ce434 = a_all3 >> 8;
            x_ce434 = x_ce29;
            y_ce434 = y_ret3;
            direct_page_ce434 = dp_ret;
            data_bank_ce434 = db_ret;
            goto shared_CE43_3;
        }
    }
    shared_CE06:;
    if ((uint16_t)(y_ce06 + 0x0200) < 0x1800) {
        a_hi_cdec2 = (uint16_t)(y_ce06 + 0x0200) >> 8;
        x_cdec2 = x_ce06;
        y_cdec2 = (uint16_t)(y_ce06 + 0x0200);
        goto shared_CDEC_1;
    }
    r->a = (uint16_t)(y_ce06 + 0x0200);
    r->y = (uint16_t)(y_ce06 + 0x0200);
    r->c = (uint16_t)(y_ce06 + 0x0200) >= 0x1800;
    r->v = ((y_ce06 ^ (uint16_t)(y_ce06 + 0x0200)) & ((uint16_t)(y_ce06 + 0x0200) ^ 0x0200) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CE06_1:;
    if (y_ce062 + 0x0200 < 0x1800) {
        a_hi_cdec3 = y_ce062 + 0x0200 >> 8;
        x_cdec3 = x_ce062;
        y_cdec3 = (uint8_t)(y_ce062 + 0x0200);
        goto shared_CDEC_2;
    }
    r->a = y_ce062 + 0x0200;
    r->y = (uint8_t)(y_ce062 + 0x0200);
    r->c = y_ce062 + 0x0200 >= 0x1800;
    r->v = ((y_ce062 ^ y_ce062 + 0x0200) & (y_ce062 + 0x0200 ^ 0x0200) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CE06_2:;
    if (y_ce063 + 0x0200 < 0x1800) {
        a_hi_cdec3 = y_ce063 + 0x0200 >> 8;
        x_cdec3 = x_ce063;
        y_cdec3 = (uint8_t)(y_ce063 + 0x0200);
        goto shared_CDEC_2;
    }
    r->a = y_ce063 + 0x0200;
    r->y = (uint8_t)(y_ce063 + 0x0200);
    r->c = y_ce063 + 0x0200 >= 0x1800;
    r->v = ((y_ce063 ^ y_ce063 + 0x0200) & (y_ce063 + 0x0200 ^ 0x0200) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CE06_3:;
    if ((uint16_t)(y_ce064 + 0x0200) < 0x1800) {
        a_hi_cdec2 = (uint16_t)(y_ce064 + 0x0200) >> 8;
        x_cdec2 = x_ce064;
        y_cdec2 = (uint16_t)(y_ce064 + 0x0200);
        goto shared_CDEC_1;
    }
    r->a = (uint16_t)(y_ce064 + 0x0200);
    r->y = (uint16_t)(y_ce064 + 0x0200);
    r->c = (uint16_t)(y_ce064 + 0x0200) >= 0x1800;
    r->v = ((y_ce064 ^ (uint16_t)(y_ce064 + 0x0200)) & ((uint16_t)(y_ce064 + 0x0200) ^ 0x0200) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_CE43:;
    uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page_ce43 + 0x50));
    BUS8_SET(c, (uint16_t)(direct_page_ce43 + 0x50), (uint8_t)(value14 << 1));
    if ((uint16_t)(y_ce43 + 0x0200) < 0x0C00) {
        a_hi_ce292 = (uint16_t)(y_ce43 + 0x0200) >> 8;
        x_ce292 = x_ce43;
        y_ce292 = (uint16_t)(y_ce43 + 0x0200);
        direct_page_ce29 = direct_page_ce43;
        data_bank_ce29 = data_bank_ce43;
        goto shared_CE29_1;
    }
    uint8_t value15 = BUS8_RDP(c, (uint16_t)(direct_page_ce43 + 0x51));
    BUS8_SET(c, (uint16_t)(direct_page_ce43 + 0x51), (uint8_t)(value15 << 1));
    r->a = (uint16_t)(y_ce43 + 0x0200);
    r->y = (uint16_t)(y_ce43 + 0x0200);
    r->c = value15 & 0x80;
    r->v = ((y_ce43 ^ (uint16_t)(y_ce43 + 0x0200)) & ((uint16_t)(y_ce43 + 0x0200) ^ 0x0200) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_ce43;
    r->dp = direct_page_ce43;
    RETURN_RTS(c);
    shared_CE43_1:;
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(direct_page_ce432 + 0x50));
    BUS8_SET(c, (uint16_t)(direct_page_ce432 + 0x50), (uint8_t)(value16 << 1));
    if (y_ce432 + 0x0200 < 0x0C00) {
        a_hi_ce293 = y_ce432 + 0x0200 >> 8;
        x_ce293 = x_ce432;
        y_ce293 = (uint8_t)(y_ce432 + 0x0200);
        direct_page_ce292 = direct_page_ce432;
        data_bank_ce292 = data_bank_ce432;
        goto shared_CE29_2;
    }
    uint8_t value17 = BUS8_RDP(c, (uint16_t)(direct_page_ce432 + 0x51));
    BUS8_SET(c, (uint16_t)(direct_page_ce432 + 0x51), (uint8_t)(value17 << 1));
    r->a = y_ce432 + 0x0200;
    r->y = (uint8_t)(y_ce432 + 0x0200);
    r->c = value17 & 0x80;
    r->v = ((y_ce432 ^ y_ce432 + 0x0200) & (y_ce432 + 0x0200 ^ 0x0200) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_ce432;
    r->dp = direct_page_ce432;
    RETURN_RTS(c);
    shared_CE43_2:;
    uint8_t value18 = BUS8_RDP(c, (uint16_t)(direct_page_ce433 + 0x50));
    BUS8_SET(c, (uint16_t)(direct_page_ce433 + 0x50), (uint8_t)(value18 << 1));
    if (y_ce433 + 0x0200 < 0x0C00) {
        a_hi_ce293 = y_ce433 + 0x0200 >> 8;
        x_ce293 = x_ce433;
        y_ce293 = (uint8_t)(y_ce433 + 0x0200);
        direct_page_ce292 = direct_page_ce433;
        data_bank_ce292 = data_bank_ce433;
        goto shared_CE29_2;
    }
    uint8_t value19 = BUS8_RDP(c, (uint16_t)(direct_page_ce433 + 0x51));
    BUS8_SET(c, (uint16_t)(direct_page_ce433 + 0x51), (uint8_t)(value19 << 1));
    r->a = y_ce433 + 0x0200;
    r->y = (uint8_t)(y_ce433 + 0x0200);
    r->c = value19 & 0x80;
    r->v = ((y_ce433 ^ y_ce433 + 0x0200) & (y_ce433 + 0x0200 ^ 0x0200) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_ce433;
    r->dp = direct_page_ce433;
    RETURN_RTS(c);
    shared_CE43_3:;
    uint8_t value20 = BUS8_RDP(c, (uint16_t)(direct_page_ce434 + 0x50));
    BUS8_SET(c, (uint16_t)(direct_page_ce434 + 0x50), (uint8_t)(value20 << 1));
    if ((uint16_t)(y_ce434 + 0x0200) < 0x0C00) {
        a_hi_ce292 = (uint16_t)(y_ce434 + 0x0200) >> 8;
        x_ce292 = x_ce434;
        y_ce292 = (uint16_t)(y_ce434 + 0x0200);
        direct_page_ce29 = direct_page_ce434;
        data_bank_ce29 = data_bank_ce434;
        goto shared_CE29_1;
    }
    uint8_t value21 = BUS8_RDP(c, (uint16_t)(direct_page_ce434 + 0x51));
    BUS8_SET(c, (uint16_t)(direct_page_ce434 + 0x51), (uint8_t)(value21 << 1));
    r->a = (uint16_t)(y_ce434 + 0x0200);
    r->y = (uint16_t)(y_ce434 + 0x0200);
    r->c = value21 & 0x80;
    r->v = ((y_ce434 ^ (uint16_t)(y_ce434 + 0x0200)) & ((uint16_t)(y_ce434 + 0x0200) ^ 0x0200) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_ce434;
    r->dp = direct_page_ce434;
    RETURN_RTS(c);
    shared_CDEC_1:;
    uint8_t value22 = RAM8(0xE000 + y_cdec2);
    if (value22 == 0) {
        a_hi_ce06 = a_hi_cdec2;
        x_ce06 = x_cdec2;
        y_ce06 = y_cdec2;
        goto shared_CE06;
    }
    if (value22 & 0x80) {
        a_hi_ce06 = a_hi_cdec2;
        x_ce06 = x_cdec2;
        y_ce06 = y_cdec2;
        goto shared_CE06;
    }
    uint8_t value23 = RAM8(0xE00B + x_cdec2);
    uint8_t value24 = RAM8(0xE00B + y_cdec2);
    if ((value23 ^ value24) & 0x80) {
        a_hi_ce06 = a_hi_cdec2;
        x_ce06 = x_cdec2;
        y_ce06 = y_cdec2;
        goto shared_CE06;
    }
    if (((value23 ^ value24) & 3) == 3) {
        a_hi_ce06 = a_hi_cdec2;
        x_ce06 = x_cdec2;
        y_ce06 = y_cdec2;
        goto shared_CE06;
    }
    r->a = a_hi_cdec2 << 8 | ((value23 ^ value24) & 3);
    r->x = x_cdec2;
    r->y = y_cdec2;
    r->c = ((value23 ^ value24) & 3) >= 3;
    r->z = ((value23 ^ value24) & 3) == 3;
    r->n = (uint8_t)(((value23 ^ value24) & 3) - 3) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE05, 0xC1CE59); GUARD_JSR(c, sp_call, 0xCE05); } /* prepare_fixed_radius_contact_distance */
    bool m_ret4 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t y_ret4 = r->y;
    if (m_ret4) {
        if (x_ret3) {
            a_hi_ce062 = a_all4 >> 8;
            x_ce062 = (uint8_t)x_cdec2;
            y_ce062 = (uint8_t)y_ret4;
            goto shared_CE06_1;
        } else {
            a_hi_ce06 = a_all4 >> 8;
            x_ce06 = x_cdec2;
            y_ce06 = y_ret4;
            goto shared_CE06;
        }
    } else {
        if (x_ret3) {
            a_hi_ce063 = a_all4 >> 8;
            x_ce063 = (uint8_t)x_cdec2;
            y_ce063 = (uint8_t)y_ret4;
            goto shared_CE06_2;
        } else {
            a_hi_ce064 = a_all4 >> 8;
            x_ce064 = x_cdec2;
            y_ce064 = y_ret4;
            goto shared_CE06_3;
        }
    }
    shared_CDEC_2:;
    uint8_t value25 = RAM8(0xE000 + y_cdec3);
    if (value25 == 0) {
        a_hi_ce062 = a_hi_cdec3;
        x_ce062 = x_cdec3;
        y_ce062 = y_cdec3;
        goto shared_CE06_1;
    }
    if (value25 & 0x80) {
        a_hi_ce062 = a_hi_cdec3;
        x_ce062 = x_cdec3;
        y_ce062 = y_cdec3;
        goto shared_CE06_1;
    }
    uint8_t value26 = RAM8(0xE00B + x_cdec3);
    uint8_t value27 = RAM8(0xE00B + y_cdec3);
    if ((value26 ^ value27) & 0x80) {
        a_hi_ce062 = a_hi_cdec3;
        x_ce062 = x_cdec3;
        y_ce062 = y_cdec3;
        goto shared_CE06_1;
    }
    if (((value26 ^ value27) & 3) == 3) {
        a_hi_ce062 = a_hi_cdec3;
        x_ce062 = x_cdec3;
        y_ce062 = y_cdec3;
        goto shared_CE06_1;
    }
    r->a = a_hi_cdec3 << 8 | ((value26 ^ value27) & 3);
    r->x = x_cdec3;
    r->y = y_cdec3;
    r->c = ((value26 ^ value27) & 3) >= 3;
    r->z = ((value26 ^ value27) & 3) == 3;
    r->n = (uint8_t)(((value26 ^ value27) & 3) - 3) & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE05, 0xC1CE59); GUARD_JSR(c, sp_call, 0xCE05); } /* prepare_fixed_radius_contact_distance */
    bool m_ret5 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t y_ret5 = r->y;
    if (m_ret5) {
        if (x_ret4) {
            a_hi_ce062 = a_all5 >> 8;
            x_ce062 = x_cdec3;
            y_ce062 = (uint8_t)y_ret5;
            goto shared_CE06_1;
        } else {
            a_hi_ce06 = a_all5 >> 8;
            x_ce06 = x_cdec3;
            y_ce06 = y_ret5;
            goto shared_CE06;
        }
    } else {
        if (x_ret4) {
            a_hi_ce063 = a_all5 >> 8;
            x_ce063 = x_cdec3;
            y_ce063 = (uint8_t)y_ret5;
            goto shared_CE06_2;
        } else {
            a_hi_ce064 = a_all5 >> 8;
            x_ce064 = x_cdec3;
            y_ce064 = y_ret5;
            goto shared_CE06_3;
        }
    }
    shared_CE29_1:;
    uint8_t value28 = BUS8_RDP(c, (data_bank_ce29 << 0x10) + 0xE000 + y_ce292);
    if (value28 == 0) {
        a_hi_ce43 = a_hi_ce292;
        x_ce43 = x_ce292;
        y_ce43 = y_ce292;
        direct_page_ce43 = direct_page_ce29;
        data_bank_ce43 = data_bank_ce29;
        goto shared_CE43;
    }
    if (value28 & 0x80) {
        a_hi_ce43 = a_hi_ce292;
        x_ce43 = x_ce292;
        y_ce43 = y_ce292;
        direct_page_ce43 = direct_page_ce29;
        data_bank_ce43 = data_bank_ce29;
        goto shared_CE43;
    }
    uint8_t value29 = BUS8_RDP(c, (data_bank_ce29 << 0x10) + 0xE00B + x_ce292);
    uint8_t value30 = BUS8_RDP(c, (data_bank_ce29 << 0x10) + 0xE00B + y_ce292);
    if ((value29 ^ value30) & 0x80) {
        a_hi_ce43 = a_hi_ce292;
        x_ce43 = x_ce292;
        y_ce43 = y_ce292;
        direct_page_ce43 = direct_page_ce29;
        data_bank_ce43 = data_bank_ce29;
        goto shared_CE43;
    }
    if (((value29 ^ value30) & 3) == 3) {
        a_hi_ce43 = a_hi_ce292;
        x_ce43 = x_ce292;
        y_ce43 = y_ce292;
        direct_page_ce43 = direct_page_ce29;
        data_bank_ce43 = data_bank_ce29;
        goto shared_CE43;
    }
    r->a = a_hi_ce292 << 8 | ((value29 ^ value30) & 3);
    r->x = x_ce292;
    r->y = y_ce292;
    r->c = ((value29 ^ value30) & 3) >= 3;
    r->z = ((value29 ^ value30) & 3) == 3;
    r->n = (uint8_t)(((value29 ^ value30) & 3) - 3) & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_ce29;
    r->dp = direct_page_ce29;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE42, 0xC1CE62); GUARD_JSR(c, sp_call, 0xCE42); } /* resolve_toroidal_map_contact_distance_event_and_motion */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret6 = r->mf;
    bool x_ret5 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t y_ret6 = r->y;
    if (m_ret6) {
        if (x_ret5) {
            a_hi_ce432 = a_all6 >> 8;
            x_ce432 = (uint8_t)x_ce292;
            y_ce432 = (uint8_t)y_ret6;
            direct_page_ce432 = dp_ret2;
            data_bank_ce432 = db_ret2;
            goto shared_CE43_1;
        } else {
            a_hi_ce43 = a_all6 >> 8;
            x_ce43 = x_ce292;
            y_ce43 = y_ret6;
            direct_page_ce43 = dp_ret2;
            data_bank_ce43 = db_ret2;
            goto shared_CE43;
        }
    } else {
        if (x_ret5) {
            a_hi_ce433 = a_all6 >> 8;
            x_ce433 = (uint8_t)x_ce292;
            y_ce433 = (uint8_t)y_ret6;
            direct_page_ce433 = dp_ret2;
            data_bank_ce433 = db_ret2;
            goto shared_CE43_2;
        } else {
            a_hi_ce434 = a_all6 >> 8;
            x_ce434 = x_ce292;
            y_ce434 = y_ret6;
            direct_page_ce434 = dp_ret2;
            data_bank_ce434 = db_ret2;
            goto shared_CE43_3;
        }
    }
    shared_CE29_2:;
    uint8_t value31 = BUS8_RDP(c, (data_bank_ce292 << 0x10) + 0xE000 + y_ce293);
    if (value31 == 0) {
        a_hi_ce432 = a_hi_ce293;
        x_ce432 = x_ce293;
        y_ce432 = y_ce293;
        direct_page_ce432 = direct_page_ce292;
        data_bank_ce432 = data_bank_ce292;
        goto shared_CE43_1;
    }
    if (value31 & 0x80) {
        a_hi_ce432 = a_hi_ce293;
        x_ce432 = x_ce293;
        y_ce432 = y_ce293;
        direct_page_ce432 = direct_page_ce292;
        data_bank_ce432 = data_bank_ce292;
        goto shared_CE43_1;
    }
    uint8_t value32 = BUS8_RDP(c, (data_bank_ce292 << 0x10) + 0xE00B + x_ce293);
    uint8_t value33 = BUS8_RDP(c, (data_bank_ce292 << 0x10) + 0xE00B + y_ce293);
    if ((value32 ^ value33) & 0x80) {
        a_hi_ce432 = a_hi_ce293;
        x_ce432 = x_ce293;
        y_ce432 = y_ce293;
        direct_page_ce432 = direct_page_ce292;
        data_bank_ce432 = data_bank_ce292;
        goto shared_CE43_1;
    }
    if (((value32 ^ value33) & 3) == 3) {
        a_hi_ce432 = a_hi_ce293;
        x_ce432 = x_ce293;
        y_ce432 = y_ce293;
        direct_page_ce432 = direct_page_ce292;
        data_bank_ce432 = data_bank_ce292;
        goto shared_CE43_1;
    }
    r->a = a_hi_ce293 << 8 | ((value32 ^ value33) & 3);
    r->x = x_ce293;
    r->y = y_ce293;
    r->c = ((value32 ^ value33) & 3) >= 3;
    r->z = ((value32 ^ value33) & 3) == 3;
    r->n = (uint8_t)(((value32 ^ value33) & 3) - 3) & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_ce292;
    r->dp = direct_page_ce292;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCE42, 0xC1CE62); GUARD_JSR(c, sp_call, 0xCE42); } /* resolve_toroidal_map_contact_distance_event_and_motion */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret7 = r->mf;
    bool x_ret6 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t y_ret7 = r->y;
    if (m_ret7) {
        if (x_ret6) {
            a_hi_ce432 = a_all7 >> 8;
            x_ce432 = x_ce293;
            y_ce432 = (uint8_t)y_ret7;
            direct_page_ce432 = dp_ret3;
            data_bank_ce432 = db_ret3;
            goto shared_CE43_1;
        } else {
            a_hi_ce43 = a_all7 >> 8;
            x_ce43 = x_ce293;
            y_ce43 = y_ret7;
            direct_page_ce43 = dp_ret3;
            data_bank_ce43 = db_ret3;
            goto shared_CE43;
        }
    } else {
        if (x_ret6) {
            a_hi_ce433 = a_all7 >> 8;
            x_ce433 = x_ce293;
            y_ce433 = (uint8_t)y_ret7;
            direct_page_ce433 = dp_ret3;
            data_bank_ce433 = db_ret3;
            goto shared_CE43_2;
        } else {
            a_hi_ce434 = a_all7 >> 8;
            x_ce434 = x_ce293;
            y_ce434 = y_ret7;
            direct_page_ce434 = dp_ret3;
            data_bank_ce434 = db_ret3;
            goto shared_CE43_3;
        }
    }
}
SOM_REGISTER(0xC1CDCD, SOM_RTS, "gen", scan_active_map_contact_pool_for_one_hero, 0, L_B | L_Y | L_C | L_V, 1, -1, 0, 140, 65)
