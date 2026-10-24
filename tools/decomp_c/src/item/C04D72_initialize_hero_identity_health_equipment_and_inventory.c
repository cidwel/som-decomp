#include "som_c.h"

/* C04D72 initialize_hero_identity_health_equipment_and_inventory   [class B, 185 bytes, 78 instructions]
 * Source: src/rom/initialize_hero_identity_health_equipment_and_inventory.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void initialize_hero_identity_health_equipment_and_inventory(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_4e04 = 0;
    uint8_t y_4e04 = 0;
    bool carry_4e04 = 0;
    bool overflow_4e04 = 0;
    uint8_t a_hi_4e042 = 0;
    uint16_t y_4e042 = 0;
    bool carry_4e042 = 0;
    bool overflow_4e042 = 0;
    uint8_t a_hi_4e043 = 0;
    uint8_t y_4e043 = 0;
    bool carry_4e043 = 0;
    bool overflow_4e043 = 0;
    uint8_t a_hi_4e044 = 0;
    uint16_t y_4e044 = 0;
    bool carry_4e044 = 0;
    bool overflow_4e044 = 0;
    uint8_t a_hi_4e12 = 0;
    uint8_t y_4e12 = 0;
    uint8_t a_hi_4e122 = 0;
    uint16_t y_4e122 = 0;
    uint8_t a_hi_4e123 = 0;
    uint8_t y_4e123 = 0;
    uint8_t a_hi_4e124 = 0;
    uint16_t y_4e124 = 0;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM16_SET(0x03BD, x);
    r->a = 0x037E;
    r->z = 0;
    r->n = 0;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4D85, 0xC04E31); GUARD_JSR(c, sp_call, 0x4D85); } /* clear_actor_identity_attribute_record */
    r->sp += 4;
    uint16_t a_all = r->a;
    uint16_t value = RAM16(0x03BD);
    uint8_t value2 = RAM8(0x03BE);
    RAM8(0x03BA) = value2 >> 1;
    RAM8(0xE180 + value) = (uint8_t)((value2 >> 1) + 0x80);
    RAM8(0xE1E7 + value) = (uint8_t)((value2 >> 1) + 0x80);
    r->a = (a_all >> 8 << 8) | (uint8_t)((value2 >> 1) + 0x80);
    r->x = value;
    r->c = (value2 >> 1) + 0x80 > 0xFF;
    r->z = (uint8_t)((value2 >> 1) + 0x80) == 0;
    r->n = (uint8_t)((value2 >> 1) + 0x80) & 0x80;
    r->v = (((value2 >> 1) ^ (uint8_t)((value2 >> 1) + 0x80)) & ((uint8_t)((value2 >> 1) + 0x80) ^ 0x80) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4D9A, 0xC0464F); GUARD_JSR(c, sp_call, 0x4D9A); } /* load_hero_level_attributes_and_controller_adjustments */
    r->sp += 4;
    uint16_t x_ret2 = r->x;
    bool overflow_ret = r->v;
    RAM16_SET(ACTOR_HP + x_ret2, RAM16(ACTOR_MAX_HP + x_ret2));
    RAM8(ACTOR_MP + x_ret2) = RAM8(ACTOR_MAX_MP + x_ret2);
    RAM8(0xE1FA + x_ret2) = 7;
    uint8_t value5 = RAM8(0x03BA);
    uint16_t value6 = BUS16(c, 0xC04E2B + (uint8_t)(value5 << 1));
    RAM16_SET(0x03B4, value6);
    uint16_t value7 = RAM16(0x03BD);
    RAM8(ACTOR_KIND_FLAGS + value7) = 0x80;
    uint8_t value8 = BUS8(c, 0xC00000 + value6);
    RAM8(0xE1E0 + value7) = value8;
    uint8_t value9 = BUS8(c, 0xC00001 + value6);
    RAM8(0xE1E1 + value7) = value9;
    uint8_t value10 = BUS8(c, 0xC00002 + value6);
    RAM8(0xE1E2 + value7) = value10;
    uint8_t value11 = BUS8(c, 0xC00003 + value6);
    RAM8(0xE1E3 + value7) = value11;
    RAM8(0xE1E8 + value7) = value11;
    RAM8(0x03BA)++;
    uint8_t value12 = BUS8(c, 0xC00000 + value6);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (value12 == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = value6 >> 8;
        y1 = value7;
        carry1 = value5 & 0x80;
        overflow1 = overflow_ret;
    } else {
        uint16_t value13 = RAM16(0x03BA);
        r->a = (value6 >> 8 << 8) | value12;
        r->x = value13;
        r->y = value7;
        r->c = value5 & 0x80;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4DF5, 0xC06423); GUARD_JSL(c, sp_call, 0x4DF5); } /* jump_inventory_insert_with_explicit_hero_owner */
        r->sp += 4;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret3;
        a_hi1 = a_all3 >> 8;
        y1 = y_ret3;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    if (x_flag) {
        uint8_t value14 = RAM8(0x03B4);
        if (m_flag) {
            uint8_t value15 = BUS8(c, 0xC00001 + value14);
            bool m_flag2;
            bool x_flag2;
            uint8_t a_hi2;
            uint16_t y2;
            bool carry2;
            bool overflow2;
            if (value15 == 0) {
                m_flag2 = 1;
                x_flag2 = 1;
                a_hi2 = a_hi1;
                y2 = (uint8_t)y1;
                carry2 = carry1;
                overflow2 = overflow1;
            } else {
                uint8_t value16 = RAM8(0x03BA);
                r->a = (a_hi1 << 8) | value15;
                r->x = value16;
                r->y = (uint8_t)y1;
                r->c = carry1;
                r->z = value16 == 0;
                r->n = value16 & 0x80;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSL(c, 0x4E03, 0xC06423); GUARD_JSL(c, sp_call, 0x4E03); } /* jump_inventory_insert_with_explicit_hero_owner */
                r->sp += 4;
                bool m_ret2 = r->mf;
                bool x_ret5 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t y_ret4 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                m_flag2 = m_ret2;
                x_flag2 = x_ret5;
                a_hi2 = a_all4 >> 8;
                y2 = y_ret4;
                carry2 = carry_ret3;
                overflow2 = overflow_ret3;
            }
            if (m_flag2) {
                if (x_flag2) {
                    a_hi_4e04 = a_hi2;
                    y_4e04 = (uint8_t)y2;
                    carry_4e04 = carry2;
                    overflow_4e04 = overflow2;
                    goto shared_4E04;
                } else {
                    a_hi_4e042 = a_hi2;
                    y_4e042 = y2;
                    carry_4e042 = carry2;
                    overflow_4e042 = overflow2;
                    goto shared_4E04_1;
                }
            } else {
                if (x_flag2) {
                    a_hi_4e043 = a_hi2;
                    y_4e043 = (uint8_t)y2;
                    carry_4e043 = carry2;
                    overflow_4e043 = overflow2;
                    goto shared_4E04_2;
                } else {
                    a_hi_4e044 = a_hi2;
                    y_4e044 = y2;
                    carry_4e044 = carry2;
                    overflow_4e044 = overflow2;
                    goto shared_4E04_3;
                }
            }
        } else {
            uint16_t value17 = BUS16(c, 0xC00001 + value14);
            bool m_flag3;
            bool x_flag3;
            uint8_t a_hi3;
            uint16_t y3;
            bool carry3;
            bool overflow3;
            if (value17 == 0) {
                m_flag3 = 0;
                x_flag3 = 1;
                a_hi3 = value17 >> 8;
                y3 = (uint8_t)y1;
                carry3 = carry1;
                overflow3 = overflow1;
            } else {
                uint8_t value18 = RAM8(0x03BA);
                r->a = value17;
                r->x = value18;
                r->y = (uint8_t)y1;
                r->c = carry1;
                r->z = value18 == 0;
                r->n = value18 & 0x80;
                r->v = overflow1;
                r->mf = 0;
                r->xf = 1;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSL(c, 0x4E03, 0xC06423); GUARD_JSL(c, sp_call, 0x4E03); } /* jump_inventory_insert_with_explicit_hero_owner */
                r->sp += 4;
                bool m_ret3 = r->mf;
                bool x_ret7 = r->xf;
                uint16_t a_all5 = r->a;
                uint16_t y_ret5 = r->y;
                bool carry_ret4 = r->c;
                bool overflow_ret4 = r->v;
                m_flag3 = m_ret3;
                x_flag3 = x_ret7;
                a_hi3 = a_all5 >> 8;
                y3 = y_ret5;
                carry3 = carry_ret4;
                overflow3 = overflow_ret4;
            }
            if (m_flag3) {
                if (x_flag3) {
                    a_hi_4e04 = a_hi3;
                    y_4e04 = (uint8_t)y3;
                    carry_4e04 = carry3;
                    overflow_4e04 = overflow3;
                    goto shared_4E04;
                } else {
                    a_hi_4e042 = a_hi3;
                    y_4e042 = y3;
                    carry_4e042 = carry3;
                    overflow_4e042 = overflow3;
                    goto shared_4E04_1;
                }
            } else {
                if (x_flag3) {
                    a_hi_4e043 = a_hi3;
                    y_4e043 = (uint8_t)y3;
                    carry_4e043 = carry3;
                    overflow_4e043 = overflow3;
                    goto shared_4E04_2;
                } else {
                    a_hi_4e044 = a_hi3;
                    y_4e044 = y3;
                    carry_4e044 = carry3;
                    overflow_4e044 = overflow3;
                    goto shared_4E04_3;
                }
            }
        }
    } else {
        uint16_t value19 = RAM16(0x03B4);
        if (m_flag) {
            uint8_t value20 = BUS8(c, 0xC00001 + value19);
            bool m_flag4;
            bool x_flag4;
            uint8_t a_hi4;
            uint16_t y4;
            bool carry4;
            bool overflow4;
            if (value20 == 0) {
                m_flag4 = 1;
                x_flag4 = 0;
                a_hi4 = a_hi1;
                y4 = y1;
                carry4 = carry1;
                overflow4 = overflow1;
            } else {
                uint16_t value21 = RAM16(0x03BA);
                r->a = (a_hi1 << 8) | value20;
                r->x = value21;
                r->y = y1;
                r->c = carry1;
                r->z = value21 == 0;
                r->n = value21 & 0x8000;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSL(c, 0x4E03, 0xC06423); GUARD_JSL(c, sp_call, 0x4E03); } /* jump_inventory_insert_with_explicit_hero_owner */
                r->sp += 4;
                bool m_ret4 = r->mf;
                bool x_ret9 = r->xf;
                uint16_t a_all6 = r->a;
                uint16_t y_ret6 = r->y;
                bool carry_ret5 = r->c;
                bool overflow_ret5 = r->v;
                m_flag4 = m_ret4;
                x_flag4 = x_ret9;
                a_hi4 = a_all6 >> 8;
                y4 = y_ret6;
                carry4 = carry_ret5;
                overflow4 = overflow_ret5;
            }
            if (m_flag4) {
                if (x_flag4) {
                    a_hi_4e04 = a_hi4;
                    y_4e04 = (uint8_t)y4;
                    carry_4e04 = carry4;
                    overflow_4e04 = overflow4;
                    goto shared_4E04;
                } else {
                    a_hi_4e042 = a_hi4;
                    y_4e042 = y4;
                    carry_4e042 = carry4;
                    overflow_4e042 = overflow4;
                    goto shared_4E04_1;
                }
            } else {
                if (x_flag4) {
                    a_hi_4e043 = a_hi4;
                    y_4e043 = (uint8_t)y4;
                    carry_4e043 = carry4;
                    overflow_4e043 = overflow4;
                    goto shared_4E04_2;
                } else {
                    a_hi_4e044 = a_hi4;
                    y_4e044 = y4;
                    carry_4e044 = carry4;
                    overflow_4e044 = overflow4;
                    goto shared_4E04_3;
                }
            }
        } else {
            uint16_t value22 = BUS16(c, 0xC00001 + value19);
            bool m_flag5;
            bool x_flag5;
            uint8_t a_hi5;
            uint16_t y5;
            bool carry5;
            bool overflow5;
            if (value22 == 0) {
                m_flag5 = 0;
                x_flag5 = 0;
                a_hi5 = value22 >> 8;
                y5 = y1;
                carry5 = carry1;
                overflow5 = overflow1;
            } else {
                uint16_t value23 = RAM16(0x03BA);
                r->a = value22;
                r->x = value23;
                r->y = y1;
                r->c = carry1;
                r->z = value23 == 0;
                r->n = value23 & 0x8000;
                r->v = overflow1;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSL(c, 0x4E03, 0xC06423); GUARD_JSL(c, sp_call, 0x4E03); } /* jump_inventory_insert_with_explicit_hero_owner */
                r->sp += 4;
                bool m_ret5 = r->mf;
                bool x_ret11 = r->xf;
                uint16_t a_all7 = r->a;
                uint16_t y_ret7 = r->y;
                bool carry_ret6 = r->c;
                bool overflow_ret6 = r->v;
                m_flag5 = m_ret5;
                x_flag5 = x_ret11;
                a_hi5 = a_all7 >> 8;
                y5 = y_ret7;
                carry5 = carry_ret6;
                overflow5 = overflow_ret6;
            }
            if (m_flag5) {
                if (x_flag5) {
                    a_hi_4e04 = a_hi5;
                    y_4e04 = (uint8_t)y5;
                    carry_4e04 = carry5;
                    overflow_4e04 = overflow5;
                    goto shared_4E04;
                } else {
                    a_hi_4e042 = a_hi5;
                    y_4e042 = y5;
                    carry_4e042 = carry5;
                    overflow_4e042 = overflow5;
                    goto shared_4E04_1;
                }
            } else {
                if (x_flag5) {
                    a_hi_4e043 = a_hi5;
                    y_4e043 = (uint8_t)y5;
                    carry_4e043 = carry5;
                    overflow_4e043 = overflow5;
                    goto shared_4E04_2;
                } else {
                    a_hi_4e044 = a_hi5;
                    y_4e044 = y5;
                    carry_4e044 = carry5;
                    overflow_4e044 = overflow5;
                    goto shared_4E04_3;
                }
            }
        }
    }
    shared_4E04:;
    uint8_t value25 = BUS8(c, 0xC00002 + RAM8(0x03B4));
    bool x_flag6;
    uint8_t a_hi6;
    uint16_t y6;
    if (value25 == 0) {
        x_flag6 = 1;
        a_hi6 = a_hi_4e04;
        y6 = y_4e04;
    } else {
        uint8_t value26 = RAM8(0x03BA);
        r->a = (a_hi_4e04 << 8) | value25;
        r->x = value26;
        r->y = y_4e04;
        r->c = carry_4e04;
        r->z = value26 == 0;
        r->n = value26 & 0x80;
        r->v = overflow_4e04;
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7E;
        r->dp = 0x0300;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E11, 0xC06423); GUARD_JSL(c, sp_call, 0x4E11); } /* jump_inventory_insert_with_explicit_hero_owner */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret13 = r->xf;
        uint16_t a_all8 = r->a;
        uint16_t y_ret8 = r->y;
        x_flag6 = x_ret13;
        a_hi6 = a_all8 >> 8;
        y6 = y_ret8;
    }
    if (x_flag6) {
        a_hi_4e12 = a_hi6;
        y_4e12 = (uint8_t)y6;
        goto shared_4E12;
    } else {
        a_hi_4e122 = a_hi6;
        y_4e122 = y6;
        goto shared_4E12_1;
    }
    shared_4E04_1:;
    uint8_t value28 = BUS8(c, 0xC00002 + RAM16(0x03B4));
    bool x_flag7;
    uint8_t a_hi7;
    uint16_t y7;
    if (value28 == 0) {
        x_flag7 = 0;
        a_hi7 = a_hi_4e042;
        y7 = y_4e042;
    } else {
        uint16_t value29 = RAM16(0x03BA);
        r->a = (a_hi_4e042 << 8) | value28;
        r->x = value29;
        r->y = y_4e042;
        r->c = carry_4e042;
        r->z = value29 == 0;
        r->n = value29 & 0x8000;
        r->v = overflow_4e042;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0300;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E11, 0xC06423); GUARD_JSL(c, sp_call, 0x4E11); } /* jump_inventory_insert_with_explicit_hero_owner */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret15 = r->xf;
        uint16_t a_all9 = r->a;
        uint16_t y_ret9 = r->y;
        x_flag7 = x_ret15;
        a_hi7 = a_all9 >> 8;
        y7 = y_ret9;
    }
    if (x_flag7) {
        a_hi_4e12 = a_hi7;
        y_4e12 = (uint8_t)y7;
        goto shared_4E12;
    } else {
        a_hi_4e122 = a_hi7;
        y_4e122 = y7;
        goto shared_4E12_1;
    }
    shared_4E04_2:;
    uint16_t value31 = BUS16(c, 0xC00002 + RAM8(0x03B4));
    bool m_flag6;
    bool x_flag8;
    uint8_t a_hi8;
    uint16_t y8;
    if (value31 == 0) {
        m_flag6 = 0;
        x_flag8 = 1;
        a_hi8 = value31 >> 8;
        y8 = y_4e043;
    } else {
        uint8_t value32 = RAM8(0x03BA);
        r->a = value31;
        r->x = value32;
        r->y = y_4e043;
        r->c = carry_4e043;
        r->z = value32 == 0;
        r->n = value32 & 0x80;
        r->v = overflow_4e043;
        r->mf = 0;
        r->xf = 1;
        r->db = 0x7E;
        r->dp = 0x0300;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E11, 0xC06423); GUARD_JSL(c, sp_call, 0x4E11); } /* jump_inventory_insert_with_explicit_hero_owner */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret17 = r->xf;
        uint16_t a_all10 = r->a;
        uint16_t y_ret10 = r->y;
        m_flag6 = 1;
        x_flag8 = x_ret17;
        a_hi8 = a_all10 >> 8;
        y8 = y_ret10;
    }
    if (m_flag6) {
        if (x_flag8) {
            a_hi_4e12 = a_hi8;
            y_4e12 = (uint8_t)y8;
            goto shared_4E12;
        } else {
            a_hi_4e122 = a_hi8;
            y_4e122 = y8;
            goto shared_4E12_1;
        }
    } else {
        if (x_flag8) {
            a_hi_4e123 = a_hi8;
            y_4e123 = (uint8_t)y8;
            goto shared_4E12_2;
        } else {
            a_hi_4e124 = a_hi8;
            y_4e124 = y8;
            goto shared_4E12_3;
        }
    }
    shared_4E04_3:;
    uint16_t value34 = BUS16(c, 0xC00002 + RAM16(0x03B4));
    bool m_flag7;
    bool x_flag9;
    uint8_t a_hi9;
    uint16_t y9;
    if (value34 == 0) {
        m_flag7 = 0;
        x_flag9 = 0;
        a_hi9 = value34 >> 8;
        y9 = y_4e044;
    } else {
        uint16_t value35 = RAM16(0x03BA);
        r->a = value34;
        r->x = value35;
        r->y = y_4e044;
        r->c = carry_4e044;
        r->z = value35 == 0;
        r->n = value35 & 0x8000;
        r->v = overflow_4e044;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0300;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E11, 0xC06423); GUARD_JSL(c, sp_call, 0x4E11); } /* jump_inventory_insert_with_explicit_hero_owner */
        r->sp += 4;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret19 = r->xf;
        uint16_t a_all11 = r->a;
        uint16_t y_ret11 = r->y;
        m_flag7 = 1;
        x_flag9 = x_ret19;
        a_hi9 = a_all11 >> 8;
        y9 = y_ret11;
    }
    if (m_flag7) {
        if (x_flag9) {
            a_hi_4e12 = a_hi9;
            y_4e12 = (uint8_t)y9;
            goto shared_4E12;
        } else {
            a_hi_4e122 = a_hi9;
            y_4e122 = y9;
            goto shared_4E12_1;
        }
    } else {
        if (x_flag9) {
            a_hi_4e123 = a_hi9;
            y_4e123 = (uint8_t)y9;
            goto shared_4E12_2;
        } else {
            a_hi_4e124 = a_hi9;
            y_4e124 = y9;
            goto shared_4E12_3;
        }
    }
    shared_4E12:;
    uint8_t value37 = BUS8(c, 0xC00003 + RAM8(0x03B4));
    uint8_t value38 = RAM8(0x03BA);
    r->a = (a_hi_4e12 << 8) | (uint8_t)(value37 + 0x80);
    r->x = value38;
    r->y = y_4e12;
    r->c = value37 + 0x80 > 0xFF;
    r->z = value38 == 0;
    r->n = value38 & 0x80;
    r->v = ((value37 ^ (uint8_t)(value37 + 0x80)) & ((uint8_t)(value37 + 0x80) ^ 0x80) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4E20, 0xC06423); GUARD_JSL(c, sp_call, 0x4E20); } /* jump_inventory_insert_with_explicit_hero_owner */
    r->sp += 4;
    bool x_ret21 = r->xf;
    uint16_t y_ret12 = r->y;
    if (x_ret21) {
        uint8_t value39 = RAM8(0x03BD);
        r->x = value39;
        r->y = (uint8_t)y_ret12;
        r->z = value39 == 0;
        r->n = value39 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E26, 0xC04530); GUARD_JSL(c, sp_call, 0x4E26); } /* rebuild_actor_attributes_native */
        r->sp += 4;
        uint8_t value40 = RAM8(0x0000 + sp0 - 3);
        uint8_t value41 = RAM8(0x0000 + sp0 - 2);
        uint8_t value42 = RAM8(0x0000 + sp0 - 1);
        uint8_t value43 = RAM8(0x0000 + sp0);
        r->mf = value40 & 0x20;
        r->xf = value40 & 0x10;
        r->db = value41;
        r->dp = (value43 << 8) | value42;
        r->i = value40 & 0x04;
        r->d = value40 & 0x08;
        RETURN_RTL(c);
    } else {
        uint16_t value44 = RAM16(0x03BD);
        r->x = value44;
        r->z = value44 == 0;
        r->n = value44 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E26, 0xC04530); GUARD_JSL(c, sp_call, 0x4E26); } /* rebuild_actor_attributes_native */
        r->sp += 4;
        uint8_t value45 = RAM8(0x0000 + sp0 - 3);
        uint8_t value46 = RAM8(0x0000 + sp0 - 2);
        uint8_t value47 = RAM8(0x0000 + sp0 - 1);
        uint8_t value48 = RAM8(0x0000 + sp0);
        r->mf = value45 & 0x20;
        r->xf = value45 & 0x10;
        r->db = value46;
        r->dp = (value48 << 8) | value47;
        r->i = value45 & 0x04;
        r->d = value45 & 0x08;
        RETURN_RTL(c);
    }
    shared_4E12_1:;
    uint8_t value50 = BUS8(c, 0xC00003 + RAM16(0x03B4));
    uint16_t value51 = RAM16(0x03BA);
    r->a = (a_hi_4e122 << 8) | (uint8_t)(value50 + 0x80);
    r->x = value51;
    r->y = y_4e122;
    r->c = value50 + 0x80 > 0xFF;
    r->z = value51 == 0;
    r->n = value51 & 0x8000;
    r->v = ((value50 ^ (uint8_t)(value50 + 0x80)) & ((uint8_t)(value50 + 0x80) ^ 0x80) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4E20, 0xC06423); GUARD_JSL(c, sp_call, 0x4E20); } /* jump_inventory_insert_with_explicit_hero_owner */
    r->sp += 4;
    bool x_ret27 = r->xf;
    uint16_t y_ret15 = r->y;
    if (x_ret27) {
        uint8_t value52 = RAM8(0x03BD);
        r->x = value52;
        r->y = (uint8_t)y_ret15;
        r->z = value52 == 0;
        r->n = value52 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E26, 0xC04530); GUARD_JSL(c, sp_call, 0x4E26); } /* rebuild_actor_attributes_native */
        r->sp += 4;
        uint8_t value53 = RAM8(0x0000 + sp0 - 3);
        uint8_t value54 = RAM8(0x0000 + sp0 - 2);
        uint8_t value55 = RAM8(0x0000 + sp0 - 1);
        uint8_t value56 = RAM8(0x0000 + sp0);
        r->mf = value53 & 0x20;
        r->xf = value53 & 0x10;
        r->db = value54;
        r->dp = (value56 << 8) | value55;
        r->i = value53 & 0x04;
        r->d = value53 & 0x08;
        RETURN_RTL(c);
    } else {
        uint16_t value57 = RAM16(0x03BD);
        r->x = value57;
        r->z = value57 == 0;
        r->n = value57 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4E26, 0xC04530); GUARD_JSL(c, sp_call, 0x4E26); } /* rebuild_actor_attributes_native */
        r->sp += 4;
        uint8_t value58 = RAM8(0x0000 + sp0 - 3);
        uint8_t value59 = RAM8(0x0000 + sp0 - 2);
        uint8_t value60 = RAM8(0x0000 + sp0 - 1);
        uint8_t value61 = RAM8(0x0000 + sp0);
        r->mf = value58 & 0x20;
        r->xf = value58 & 0x10;
        r->db = value59;
        r->dp = (value61 << 8) | value60;
        r->i = value58 & 0x04;
        r->d = value58 & 0x08;
        RETURN_RTL(c);
    }
    shared_4E12_2:;
    uint16_t value63 = BUS16(c, 0xC00003 + RAM8(0x03B4));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_4E12_3:;
    uint16_t value65 = BUS16(c, 0xC00003 + RAM16(0x03B4));
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0xC04D72, SOM_RTL, "gen", initialize_hero_identity_health_equipment_and_inventory, 0, L_B, 5, 1, 0, 185, 78)
