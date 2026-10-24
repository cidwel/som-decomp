#include "som_c.h"

/* C18089 consume_complete_ordinary_actor_combat_requests   [class B, 133 bytes, 67 instructions]
 * Source: src/rom/consume_complete_ordinary_actor_combat_requests.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void consume_complete_ordinary_actor_combat_requests(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_80ae = 0;
    uint8_t a_hi_80ae = 0;
    uint16_t x_80ae = 0;
    uint16_t y_80ae = 0;
    bool carry_80ae = 0;
    uint8_t a_80aa = 0;
    uint8_t a_hi_80aa = 0;
    uint16_t x_80aa = 0;
    uint16_t y_80aa = 0;
    bool overflow_80aa = 0;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x52));
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0xFF));
    if ((value | value2) != 0) {
        RETURN_RTL(c);
    }
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0xF1));
    if (value3 & 0x80) {
        RETURN_RTL(c);
    }
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0xE8));
    if ((value4 & 4) != 0) {
        RETURN_RTL(c);
    }
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0xD0));
    if (value5 == 0) {
        a_80ae = value5;
        a_hi_80ae = a_hi;
        x_80ae = x;
        y_80ae = y;
        carry_80ae = carry;
        goto shared_80AE;
    }
    if (x < 0x0600) {
        a_80aa = value5;
        a_hi_80aa = a_hi;
        x_80aa = x;
        y_80aa = y;
        overflow_80aa = overflow;
        goto shared_80AA;
    }
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0x3A));
    if (x != value6) {
        a_80ae = value5;
        a_hi_80ae = a_hi;
        x_80ae = x;
        y_80ae = y;
        carry_80ae = x >= value6;
        goto shared_80AE;
    }
    if (x == value6) {
        r->c = x >= value6;
        RETURN_RTL(c);
    }
    a_80aa = value5;
    a_hi_80aa = a_hi;
    x_80aa = x;
    y_80aa = y;
    overflow_80aa = overflow;
    shared_80AA:;
    uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp + 0xD4));
    if (x_80aa == value42) {
        r->a = (a_hi_80aa << 8) | a_80aa;
        r->x = x_80aa;
        r->y = y_80aa;
        r->c = x_80aa >= value42;
        r->v = overflow_80aa;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = dp;
        RETURN_RTL(c);
    }
    a_80ae = a_80aa;
    a_hi_80ae = a_hi_80aa;
    x_80ae = x_80aa;
    y_80ae = y_80aa;
    carry_80ae = x_80aa >= value42;
    goto shared_80AE;
    shared_80AE:;
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
    if (value7 & 0x80) {
        RAM8(0x0000 + sp0) = x_80ae >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_80ae;
        r->a = (a_hi_80ae << 8) | 0;
        r->x = x_80ae;
        r->y = y_80ae;
        r->c = carry_80ae;
        r->z = 1;
        r->n = 0;
        r->v = value7 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = dp;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x80BE, 0xC0002D); GUARD_JSL(c, sp_call, 0x80BE); } /* actor_combat_tick_public_jump */
        r->sp += 2;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        if ((uint8_t)a_all == 0) {
            if (x_ret) {
                c->fail = 3;
                return;
            } else {
                r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                r->c = (uint8_t)a_all >= 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
        if ((uint8_t)a_all != 1) {
            if ((uint8_t)a_all != 2) {
                if ((uint8_t)a_all != 3) {
                    if ((uint8_t)a_all != 4) {
                        if (x_ret) {
                            c->fail = 3;
                            return;
                        } else {
                            r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                            r->c = (uint8_t)a_all >= 4;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                    }
                    if (x_ret) {
                        c->fail = 3;
                        return;
                    } else {
                        uint8_t value15 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value16 = RAM8(0x0000 + sp0);
                        if (((uint8_t)x_ret2 & 0x0F) == 0) {
                            r->x = (value16 << 8) | value15;
                            r->c = (uint8_t)a_all >= 4;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                        r->a = (a_all >> 8 << 8) | (uint8_t)x_ret2;
                        r->x = (value16 << 8) | value15;
                        r->c = (uint8_t)a_all >= 4;
                        r->z = ((uint8_t)x_ret2 & 0x0F) == 0;
                        r->n = ((value16 << 8) | value15) & 0x8000;
                        r->mf = 1;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x810A, 0xC1939C); GUARD_JSR(c, sp_call, 0x810A); } /* refresh_actor_graphics_status_and_controller */
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTL(c);
                    }
                }
                r->c = (uint8_t)a_all >= 3;
                r->z = (uint8_t)a_all == 3;
                r->n = (uint8_t)((uint8_t)a_all - 3) & 0x80;
                r->mf = 1;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSR(c, 0x80F9, 0xC1E326); GUARD_JSR(c, sp_call, 0x80F9); } /* wait_for_native_nmi_and_refresh_party_hud_numbers */
                r->sp += 2;
                r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (x_ret) {
                c->fail = 3;
                return;
            } else {
                uint8_t value20 = RAM8(0x0000 + sp0 - 1);
                uint8_t value21 = RAM8(0x0000 + sp0);
                RAM8(0xE011 + ((value21 << 8) | value20)) = (a_all >> 8) | 0x80;
                r->a = ((uint8_t)a_all << 8) | ((a_all >> 8) | 0x80);
                r->x = (value21 << 8) | value20;
                r->c = (uint8_t)a_all >= 2;
                r->z = ((a_all >> 8) | 0x80) == 0;
                r->n = ((a_all >> 8) | 0x80) & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x80E1, 0xC1CA58); GUARD_JSR(c, sp_call, 0x80E1); } /* cancel_actor_charge_for_interrupting_motion */
                RAM8(0xE01C + ((value21 << 8) | value20)) = 0x40;
                RAM8(0xE006 + ((value21 << 8) | value20)) = 0;
                RAM8(0xE007 + ((value21 << 8) | value20)) = 0;
                RAM8(0xE030 + ((value21 << 8) | value20)) = 0xFF;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
        if (x_ret) {
            c->fail = 3;
            return;
        } else {
            uint8_t value23 = RAM8(0x0000 + sp0 - 1);
            uint8_t value24 = RAM8(0x0000 + sp0);
            RAM8(0xE04F + ((value24 << 8) | value23)) = (uint8_t)x_ret2;
            BUS16_SET(c, (uint16_t)(dp + 0x1E), y_ret);
            r->a = (a_all >> 8 << 8) | (uint8_t)x_ret2;
            r->x = (value24 << 8) | value23;
            r->c = (uint8_t)a_all >= 1;
            r->z = ((value24 << 8) | value23) == 0;
            r->n = ((value24 << 8) | value23) & 0x8000;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x80D2, 0xC1810E); GUARD_JSR(c, sp_call, 0x80D2); } /* create_complete_floating_combat_number */
            r->xf = 0;
            RETURN_RTL(c);
        }
    }
    if (x_80ae < 0x0600) {
        RAM8(0x0000 + sp0) = x_80ae >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_80ae;
        r->a = (a_hi_80ae << 8) | 0;
        r->x = x_80ae;
        r->y = y_80ae;
        r->c = x_80ae >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->v = value7 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = dp;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x80BE, 0xC0002D); GUARD_JSL(c, sp_call, 0x80BE); } /* actor_combat_tick_public_jump */
        r->sp += 2;
        bool x_ret10 = r->xf;
        uint16_t a_all8 = r->a;
        uint16_t x_ret11 = r->x;
        uint16_t y_ret6 = r->y;
        if ((uint8_t)a_all8 == 0) {
            if (x_ret10) {
                c->fail = 3;
                return;
            } else {
                r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                r->c = (uint8_t)a_all8 >= 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
        if ((uint8_t)a_all8 != 1) {
            if ((uint8_t)a_all8 != 2) {
                if ((uint8_t)a_all8 != 3) {
                    if ((uint8_t)a_all8 != 4) {
                        if (x_ret10) {
                            c->fail = 3;
                            return;
                        } else {
                            r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                            r->c = (uint8_t)a_all8 >= 4;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                    }
                    if (x_ret10) {
                        c->fail = 3;
                        return;
                    } else {
                        uint8_t value32 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value33 = RAM8(0x0000 + sp0);
                        if (((uint8_t)x_ret11 & 0x0F) == 0) {
                            r->x = (value33 << 8) | value32;
                            r->c = (uint8_t)a_all8 >= 4;
                            r->mf = 1;
                            r->xf = 0;
                            RETURN_RTL(c);
                        }
                        r->a = (a_all8 >> 8 << 8) | (uint8_t)x_ret11;
                        r->x = (value33 << 8) | value32;
                        r->c = (uint8_t)a_all8 >= 4;
                        r->z = ((uint8_t)x_ret11 & 0x0F) == 0;
                        r->n = ((value33 << 8) | value32) & 0x8000;
                        r->mf = 1;
                        r->xf = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x810A, 0xC1939C); GUARD_JSR(c, sp_call, 0x810A); } /* refresh_actor_graphics_status_and_controller */
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTL(c);
                    }
                }
                r->c = (uint8_t)a_all8 >= 3;
                r->z = (uint8_t)a_all8 == 3;
                r->n = (uint8_t)((uint8_t)a_all8 - 3) & 0x80;
                r->mf = 1;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSR(c, 0x80F9, 0xC1E326); GUARD_JSR(c, sp_call, 0x80F9); } /* wait_for_native_nmi_and_refresh_party_hud_numbers */
                r->sp += 2;
                r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (x_ret10) {
                c->fail = 3;
                return;
            } else {
                uint8_t value37 = RAM8(0x0000 + sp0 - 1);
                uint8_t value38 = RAM8(0x0000 + sp0);
                RAM8(0xE011 + ((value38 << 8) | value37)) = (a_all8 >> 8) | 0x80;
                r->a = ((uint8_t)a_all8 << 8) | ((a_all8 >> 8) | 0x80);
                r->x = (value38 << 8) | value37;
                r->c = (uint8_t)a_all8 >= 2;
                r->z = ((a_all8 >> 8) | 0x80) == 0;
                r->n = ((a_all8 >> 8) | 0x80) & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x80E1, 0xC1CA58); GUARD_JSR(c, sp_call, 0x80E1); } /* cancel_actor_charge_for_interrupting_motion */
                RAM8(0xE01C + ((value38 << 8) | value37)) = 0x40;
                RAM8(0xE006 + ((value38 << 8) | value37)) = 0;
                RAM8(0xE007 + ((value38 << 8) | value37)) = 0;
                RAM8(0xE030 + ((value38 << 8) | value37)) = 0xFF;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
        if (x_ret10) {
            c->fail = 3;
            return;
        } else {
            uint8_t value40 = RAM8(0x0000 + sp0 - 1);
            uint8_t value41 = RAM8(0x0000 + sp0);
            RAM8(0xE04F + ((value41 << 8) | value40)) = (uint8_t)x_ret11;
            BUS16_SET(c, (uint16_t)(dp + 0x1E), y_ret6);
            r->a = (a_all8 >> 8 << 8) | (uint8_t)x_ret11;
            r->x = (value41 << 8) | value40;
            r->c = (uint8_t)a_all8 >= 1;
            r->z = ((value41 << 8) | value40) == 0;
            r->n = ((value41 << 8) | value40) & 0x8000;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x80D2, 0xC1810E); GUARD_JSR(c, sp_call, 0x80D2); } /* create_complete_floating_combat_number */
            r->xf = 0;
            RETURN_RTL(c);
        }
    }
    r->a = (a_hi_80ae << 8) | a_80ae;
    r->x = x_80ae;
    r->y = y_80ae;
    r->c = x_80ae >= 0x0600;
    r->v = value7 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC18089, SOM_RTL, "gen", consume_complete_ordinary_actor_combat_requests, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 133, 67)
