#include "som_c.h"

/* C139CD construct_temporary_spell_entity   [class B, 248 bytes, 107 instructions]
 * Source: src/rom/construct_temporary_spell_entity.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XYV.
 */
static void construct_temporary_spell_entity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    r->a = 0x0238;
    r->x = 0x0238;
    r->c = 1;
    r->z = 0;
    r->n = 0;
    r->v = 0;
    r->mf = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39DC, 0xC13BD3); GUARD_JSR(c, sp_call, 0x39DC); } /* initialize_spell_entity_heap */
    r->sp += 5;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39DF, 0xC143F1); GUARD_JSR(c, sp_call, 0x39DF); } /* initialize_spell_entity_linked_emission_records */
    r->sp += 5;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39E2, 0xC14161); GUARD_JSR(c, sp_call, 0x39E2); } /* initialize_spell_entity_sprite_slots */
    r->sp += 5;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39E5, 0xC1280F); GUARD_JSR(c, sp_call, 0x39E5); } /* initialize_spell_entity_actor_pools */
    r->sp += 5;
    if (r->mf != 0) { c->fail = 3; return; }
    r->a = 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39EB, 0xC12896); GUARD_JSR(c, sp_call, 0x39EB); } /* allocate_spell_entity_actor_slot */
    r->sp += 5;
    uint8_t db_ret5 = r->db;
    bool m_ret4 = r->mf;
    uint16_t x_ret10 = r->x;
    if (m_ret4) {
        BUS8_SET(c, (db_ret5 << 0x10) + 4 + x_ret10, 0);
        BUS8_SET(c, (db_ret5 << 0x10) + 0x0A + x_ret10, 0);
        BUS16_SET(c, (db_ret5 << 0x10) + 2 + x_ret10, 0x0600);
        BUS16_SET(c, (db_ret5 << 0x10) + 5 + x_ret10, 0x18);
        r->a = 0x18;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3A02, 0xC12997); GUARD_JSR(c, sp_call, 0x3A02); } /* publish_spell_entity_record_or_dma_channel */
        r->sp += 5;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3A05, 0xC12EEC); GUARD_JSR(c, sp_call, 0x3A05); } /* install_spell_entity_irq_handler */
        r->sp += 5;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3A08, 0xC139A1); GUARD_JSR(c, sp_call, 0x3A08); } /* prepare_spell_entity_script_buffer */
        r->sp += 5;
        uint8_t db_ret7 = r->db;
        bool x_ret14 = r->xf;
        uint16_t a_all8 = r->a;
        if (x_ret14) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (a_all8 >> 8 << 8) | 0;
            r->x = 0x2E;
            r->z = 1;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x3A12, 0xC13D48); GUARD_JSR(c, sp_call, 0x3A12); } /* allocate_and_fill_spell_entity_heap_bytes */
            r->sp += 5;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret16 = r->xf;
            uint16_t a_all9 = r->a;
            uint16_t x_ret17 = r->x;
            BUS8_SET(c, (db_ret7 << 0x10) + 0x26 + x_ret17, RAM8(0x0099) & 8);
            if (x_ret16) {
                c->fail = 3;
                return;
            } else {
                uint8_t value7 = RAM8(0x0000 + sp0 - 4);
                uint8_t value8 = RAM8(0x0000 + sp0 - 3);
                uint8_t value9 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x0170 + ((value8 << 8) | value7));
                uint8_t a6;
                bool carry6;
                bool zero1;
                if (value9 == 0x0C) {
                    a6 = 0;
                    carry6 = value9 >= 0x0C;
                    zero1 = 1;
                } else {
                    uint8_t a5;
                    bool carry5;
                    if (value9 == 0x0D) {
                        a5 = 1;
                        carry5 = value9 >= 0x0D;
                    } else {
                        uint8_t a4;
                        bool carry4;
                        if (value9 == 0x24) {
                            a4 = 2;
                            carry4 = value9 >= 0x24;
                        } else {
                            uint8_t a3;
                            bool carry3;
                            if (value9 == 0x25) {
                                a3 = 3;
                                carry3 = value9 >= 0x25;
                            } else {
                                uint8_t a2;
                                bool carry2;
                                if (value9 == 0x10) {
                                    a2 = 4;
                                    carry2 = value9 >= 0x10;
                                } else {
                                    uint8_t a1;
                                    bool carry1;
                                    if (value9 == 0x1F) {
                                        a1 = 5;
                                        carry1 = value9 >= 0x1F;
                                    } else {
                                        if (value9 != 0x28) {
                                            r->a = (a_all9 >> 8 << 8) | value9;
                                            r->y = (value8 << 8) | value7;
                                            r->c = value9 >= 0x28;
                                            r->z = value9 == 0x28;
                                            r->n = (uint8_t)(value9 - 0x28) & 0x80;
                                            r->xf = 0;
                                            r->sp -= 3;
                                            { const uint16_t sp_call = r->sp; JSR(c, 0x3A3E, 0xC13D7D); GUARD_JSR(c, sp_call, 0x3A3E); } /* release_spell_entity_heap_with_saved_bank */
                                            r->sp += 3;
                                            if (r->xf != 0) { c->fail = 3; return; }
                                            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
                                            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
                                            uint8_t value12 = RAM8(0x0000 + sp0);
                                            r->x = 0;
                                            r->v = value10 & 0x40;
                                            r->mf = value10 & 0x20;
                                            r->xf = value10 & 0x10;
                                            r->dp = (value12 << 8) | value11;
                                            r->i = value10 & 0x04;
                                            r->d = value10 & 0x08;
                                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                                            RETURN_RTS(c);
                                        }
                                        a1 = 6;
                                        carry1 = value9 >= 0x28;
                                    }
                                    a2 = a1;
                                    carry2 = carry1;
                                }
                                a3 = a2;
                                carry3 = carry2;
                            }
                            a4 = a3;
                            carry4 = carry3;
                        }
                        a5 = a4;
                        carry5 = carry4;
                    }
                    a6 = a5;
                    carry6 = carry5;
                    zero1 = 0;
                }
                BUS8_SET(c, (db_ret7 << 0x10) + 0x25 + x_ret17, a6);
                r->a = (a_all9 >> 8 << 8) | a6;
                r->y = (value8 << 8) | value7;
                r->c = carry6;
                r->z = zero1;
                r->n = 0;
                r->xf = 0;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0x3A65, 0xC1397D); GUARD_JSR(c, sp_call, 0x3A65); } /* classify_spell_entity_facing */
                r->sp += 3;
                bool m_ret10 = r->mf;
                bool x_ret20 = r->xf;
                uint16_t a_all12 = r->a;
                if (m_ret10) {
                    BUS8_SET(c, (db_ret7 << 0x10) + 0x24 + x_ret17, (uint8_t)a_all12);
                    uint8_t value13 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x0178 + ((value8 << 8) | value7));
                    BUS8_SET(c, (db_ret7 << 0x10) + x_ret17, (uint8_t)(value13 - 1));
                    uint8_t value14 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x27 + x_ret17);
                    BUS8_SET(c, (db_ret7 << 0x10) + 0x27 + x_ret17, (uint8_t)(value14 + 1));
                    uint8_t value15 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x0179 + ((value8 << 8) | value7));
                    if (value15 != 0) {
                        BUS8_SET(c, (db_ret7 << 0x10) + 8 + x_ret17, (uint8_t)(value15 - 1));
                        uint8_t value16 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x27 + x_ret17);
                        BUS8_SET(c, (db_ret7 << 0x10) + 0x27 + x_ret17, (uint8_t)(value16 + 1));
                        uint8_t value17 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x017A + ((value8 << 8) | value7));
                        if (value17 != 0) {
                            BUS8_SET(c, (db_ret7 << 0x10) + 0x10 + x_ret17, (uint8_t)(value17 - 1));
                            uint8_t value18 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x27 + x_ret17);
                            BUS8_SET(c, (db_ret7 << 0x10) + 0x27 + x_ret17, (uint8_t)(value18 + 1));
                        }
                    }
                    uint16_t value19 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x20 + ((value8 << 8) | value7));
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x22 + x_ret17, value19);
                    uint16_t value20 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x22 + ((value8 << 8) | value7));
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x20 + x_ret17, value20);
                    if (x_ret20) {
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x28 + (uint8_t)x_ret17, (uint8_t)((value8 << 8) | value7));
                        c->fail = 3; /* operand size does not fit the register width on this path */
                        return;
                    } else {
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x28 + x_ret17, (value8 << 8) | value7);
                        uint16_t value21 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x24 + x_ret17);
                        uint16_t y1;
                        if ((value21 & 0x80) == 0) {
                            y1 = 0x14;
                        } else {
                            y1 = 0xFFEC;
                        }
                        if ((value21 & 0x40) == 0) {
                            uint16_t value22 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x22 + x_ret17);
                            BUS16_SET(c, (db_ret7 << 0x10) + 0x22 + x_ret17, (uint16_t)(y1 + value22));
                        } else {
                            uint16_t value23 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x20 + x_ret17);
                            BUS16_SET(c, (db_ret7 << 0x10) + 0x20 + x_ret17, (uint16_t)(y1 + value23));
                        }
                        uint8_t value24 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value25 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value26 = RAM8(0x0000 + sp0);
                        r->y = y1;
                        r->v = value24 & 0x40;
                        r->mf = value24 & 0x20;
                        r->xf = value24 & 0x10;
                        r->dp = (value26 << 8) | value25;
                        r->i = value24 & 0x04;
                        r->d = value24 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x24 + x_ret17, a_all12);
                    uint16_t value27 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x0178 + ((value8 << 8) | value7));
                    BUS16_SET(c, (db_ret7 << 0x10) + x_ret17, (uint16_t)(value27 - 1));
                    uint16_t value28 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x27 + x_ret17);
                    BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x27 + x_ret17, (uint16_t)(value28 + 1));
                    uint16_t value29 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x0179 + ((value8 << 8) | value7));
                    uint8_t a_hi2;
                    if (value29 == 0) {
                        a_hi2 = value29 >> 8;
                    } else {
                        BUS16_SET(c, (db_ret7 << 0x10) + 8 + x_ret17, (uint16_t)(value29 - 1));
                        uint16_t value30 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x27 + x_ret17);
                        BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x27 + x_ret17, (uint16_t)(value30 + 1));
                        uint16_t value31 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x017A + ((value8 << 8) | value7));
                        uint8_t a_hi1;
                        if (value31 == 0) {
                            a_hi1 = value31 >> 8;
                        } else {
                            BUS16_SET(c, (db_ret7 << 0x10) + 0x10 + x_ret17, (uint16_t)(value31 - 1));
                            uint16_t value32 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x27 + x_ret17);
                            BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x27 + x_ret17, (uint16_t)(value32 + 1));
                            a_hi1 = (uint16_t)(value31 - 1) >> 8;
                        }
                        a_hi2 = a_hi1;
                    }
                    uint16_t value33 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x20 + ((value8 << 8) | value7));
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x22 + x_ret17, value33);
                    uint16_t value34 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x22 + ((value8 << 8) | value7));
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x20 + x_ret17, value34);
                    if (x_ret20) {
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x28 + (uint8_t)x_ret17, (uint8_t)((value8 << 8) | value7));
                        c->fail = 3; /* operand size does not fit the register width on this path */
                        return;
                    } else {
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x28 + x_ret17, (value8 << 8) | value7);
                        uint16_t value35 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x24 + x_ret17);
                        uint16_t y2;
                        if ((value35 & 0x80) == 0) {
                            y2 = 0x14;
                        } else {
                            y2 = 0xFFEC;
                        }
                        if ((value35 & 0x40) == 0) {
                            uint16_t value36 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x22 + x_ret17);
                            BUS16_SET(c, (db_ret7 << 0x10) + 0x22 + x_ret17, (uint16_t)(y2 + value36));
                        } else {
                            uint16_t value37 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x20 + x_ret17);
                            BUS16_SET(c, (db_ret7 << 0x10) + 0x20 + x_ret17, (uint16_t)(y2 + value37));
                        }
                        uint8_t value38 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value39 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value40 = RAM8(0x0000 + sp0);
                        r->y = y2;
                        r->v = value38 & 0x40;
                        r->mf = value38 & 0x20;
                        r->xf = value38 & 0x10;
                        r->dp = (value40 << 8) | value39;
                        r->i = value38 & 0x04;
                        r->d = value38 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                }
            }
        }
    } else {
        BUS16_SET(c, (db_ret5 << 0x10) + 4 + x_ret10, 0);
        BUS16_SET(c, (db_ret5 << 0x10) + 0x0A + x_ret10, 0);
        BUS16_SET(c, (db_ret5 << 0x10) + 2 + x_ret10, 0x0600);
        BUS16_SET(c, (db_ret5 << 0x10) + 5 + x_ret10, 0x18);
        r->a = 0x18;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3A02, 0xC12997); GUARD_JSR(c, sp_call, 0x3A02); } /* publish_spell_entity_record_or_dma_channel */
        r->sp += 5;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3A05, 0xC12EEC); GUARD_JSR(c, sp_call, 0x3A05); } /* install_spell_entity_irq_handler */
        r->sp += 5;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3A08, 0xC139A1); GUARD_JSR(c, sp_call, 0x3A08); } /* prepare_spell_entity_script_buffer */
        r->sp += 5;
        uint8_t db_ret11 = r->db;
        bool x_ret24 = r->xf;
        uint16_t a_all15 = r->a;
        if (x_ret24) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (a_all15 >> 8 << 8) | 0;
            r->x = 0x2E;
            r->z = 1;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x3A12, 0xC13D48); GUARD_JSR(c, sp_call, 0x3A12); } /* allocate_and_fill_spell_entity_heap_bytes */
            r->sp += 5;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret26 = r->xf;
            uint16_t a_all16 = r->a;
            uint16_t x_ret27 = r->x;
            BUS8_SET(c, (db_ret11 << 0x10) + 0x26 + x_ret27, RAM8(0x0099) & 8);
            if (x_ret26) {
                c->fail = 3;
                return;
            } else {
                uint8_t value47 = RAM8(0x0000 + sp0 - 4);
                uint8_t value48 = RAM8(0x0000 + sp0 - 3);
                uint8_t value49 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x0170 + ((value48 << 8) | value47));
                uint8_t a12;
                bool carry12;
                bool zero2;
                if (value49 == 0x0C) {
                    a12 = 0;
                    carry12 = value49 >= 0x0C;
                    zero2 = 1;
                } else {
                    uint8_t a11;
                    bool carry11;
                    if (value49 == 0x0D) {
                        a11 = 1;
                        carry11 = value49 >= 0x0D;
                    } else {
                        uint8_t a10;
                        bool carry10;
                        if (value49 == 0x24) {
                            a10 = 2;
                            carry10 = value49 >= 0x24;
                        } else {
                            uint8_t a9;
                            bool carry9;
                            if (value49 == 0x25) {
                                a9 = 3;
                                carry9 = value49 >= 0x25;
                            } else {
                                uint8_t a8;
                                bool carry8;
                                if (value49 == 0x10) {
                                    a8 = 4;
                                    carry8 = value49 >= 0x10;
                                } else {
                                    uint8_t a7;
                                    bool carry7;
                                    if (value49 == 0x1F) {
                                        a7 = 5;
                                        carry7 = value49 >= 0x1F;
                                    } else {
                                        if (value49 != 0x28) {
                                            r->a = (a_all16 >> 8 << 8) | value49;
                                            r->y = (value48 << 8) | value47;
                                            r->c = value49 >= 0x28;
                                            r->z = value49 == 0x28;
                                            r->n = (uint8_t)(value49 - 0x28) & 0x80;
                                            r->xf = 0;
                                            r->sp -= 3;
                                            { const uint16_t sp_call = r->sp; JSR(c, 0x3A3E, 0xC13D7D); GUARD_JSR(c, sp_call, 0x3A3E); } /* release_spell_entity_heap_with_saved_bank */
                                            r->sp += 3;
                                            if (r->xf != 0) { c->fail = 3; return; }
                                            uint8_t value50 = RAM8(0x0000 + sp0 - 2);
                                            uint8_t value51 = RAM8(0x0000 + sp0 - 1);
                                            uint8_t value52 = RAM8(0x0000 + sp0);
                                            r->x = 0;
                                            r->v = value50 & 0x40;
                                            r->mf = value50 & 0x20;
                                            r->xf = value50 & 0x10;
                                            r->dp = (value52 << 8) | value51;
                                            r->i = value50 & 0x04;
                                            r->d = value50 & 0x08;
                                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                                            RETURN_RTS(c);
                                        }
                                        a7 = 6;
                                        carry7 = value49 >= 0x28;
                                    }
                                    a8 = a7;
                                    carry8 = carry7;
                                }
                                a9 = a8;
                                carry9 = carry8;
                            }
                            a10 = a9;
                            carry10 = carry9;
                        }
                        a11 = a10;
                        carry11 = carry10;
                    }
                    a12 = a11;
                    carry12 = carry11;
                    zero2 = 0;
                }
                BUS8_SET(c, (db_ret11 << 0x10) + 0x25 + x_ret27, a12);
                r->a = (a_all16 >> 8 << 8) | a12;
                r->y = (value48 << 8) | value47;
                r->c = carry12;
                r->z = zero2;
                r->n = 0;
                r->xf = 0;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0x3A65, 0xC1397D); GUARD_JSR(c, sp_call, 0x3A65); } /* classify_spell_entity_facing */
                r->sp += 3;
                bool m_ret16 = r->mf;
                bool x_ret30 = r->xf;
                uint16_t a_all19 = r->a;
                if (m_ret16) {
                    BUS8_SET(c, (db_ret11 << 0x10) + 0x24 + x_ret27, (uint8_t)a_all19);
                    uint8_t value53 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x0178 + ((value48 << 8) | value47));
                    BUS8_SET(c, (db_ret11 << 0x10) + x_ret27, (uint8_t)(value53 - 1));
                    uint8_t value54 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x27 + x_ret27);
                    BUS8_SET(c, (db_ret11 << 0x10) + 0x27 + x_ret27, (uint8_t)(value54 + 1));
                    uint8_t value55 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x0179 + ((value48 << 8) | value47));
                    if (value55 != 0) {
                        BUS8_SET(c, (db_ret11 << 0x10) + 8 + x_ret27, (uint8_t)(value55 - 1));
                        uint8_t value56 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x27 + x_ret27);
                        BUS8_SET(c, (db_ret11 << 0x10) + 0x27 + x_ret27, (uint8_t)(value56 + 1));
                        uint8_t value57 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x017A + ((value48 << 8) | value47));
                        if (value57 != 0) {
                            BUS8_SET(c, (db_ret11 << 0x10) + 0x10 + x_ret27, (uint8_t)(value57 - 1));
                            uint8_t value58 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x27 + x_ret27);
                            BUS8_SET(c, (db_ret11 << 0x10) + 0x27 + x_ret27, (uint8_t)(value58 + 1));
                        }
                    }
                    uint16_t value59 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x20 + ((value48 << 8) | value47));
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x22 + x_ret27, value59);
                    uint16_t value60 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x22 + ((value48 << 8) | value47));
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x20 + x_ret27, value60);
                    if (x_ret30) {
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x28 + (uint8_t)x_ret27, (uint8_t)((value48 << 8) | value47));
                        c->fail = 3; /* operand size does not fit the register width on this path */
                        return;
                    } else {
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x28 + x_ret27, (value48 << 8) | value47);
                        uint16_t value61 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x24 + x_ret27);
                        uint16_t y3;
                        if ((value61 & 0x80) == 0) {
                            y3 = 0x14;
                        } else {
                            y3 = 0xFFEC;
                        }
                        if ((value61 & 0x40) == 0) {
                            uint16_t value62 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x22 + x_ret27);
                            BUS16_SET(c, (db_ret11 << 0x10) + 0x22 + x_ret27, (uint16_t)(y3 + value62));
                        } else {
                            uint16_t value63 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x20 + x_ret27);
                            BUS16_SET(c, (db_ret11 << 0x10) + 0x20 + x_ret27, (uint16_t)(y3 + value63));
                        }
                        uint8_t value64 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value65 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value66 = RAM8(0x0000 + sp0);
                        r->y = y3;
                        r->v = value64 & 0x40;
                        r->mf = value64 & 0x20;
                        r->xf = value64 & 0x10;
                        r->dp = (value66 << 8) | value65;
                        r->i = value64 & 0x04;
                        r->d = value64 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                } else {
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x24 + x_ret27, a_all19);
                    uint16_t value67 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x0178 + ((value48 << 8) | value47));
                    BUS16_SET(c, (db_ret11 << 0x10) + x_ret27, (uint16_t)(value67 - 1));
                    uint16_t value68 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x27 + x_ret27);
                    BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0x27 + x_ret27, (uint16_t)(value68 + 1));
                    uint16_t value69 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x0179 + ((value48 << 8) | value47));
                    uint8_t a_hi4;
                    if (value69 == 0) {
                        a_hi4 = value69 >> 8;
                    } else {
                        BUS16_SET(c, (db_ret11 << 0x10) + 8 + x_ret27, (uint16_t)(value69 - 1));
                        uint16_t value70 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x27 + x_ret27);
                        BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0x27 + x_ret27, (uint16_t)(value70 + 1));
                        uint16_t value71 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x017A + ((value48 << 8) | value47));
                        uint8_t a_hi3;
                        if (value71 == 0) {
                            a_hi3 = value71 >> 8;
                        } else {
                            BUS16_SET(c, (db_ret11 << 0x10) + 0x10 + x_ret27, (uint16_t)(value71 - 1));
                            uint16_t value72 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x27 + x_ret27);
                            BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0x27 + x_ret27, (uint16_t)(value72 + 1));
                            a_hi3 = (uint16_t)(value71 - 1) >> 8;
                        }
                        a_hi4 = a_hi3;
                    }
                    uint16_t value73 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x20 + ((value48 << 8) | value47));
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x22 + x_ret27, value73);
                    uint16_t value74 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x22 + ((value48 << 8) | value47));
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x20 + x_ret27, value74);
                    if (x_ret30) {
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x28 + (uint8_t)x_ret27, (uint8_t)((value48 << 8) | value47));
                        c->fail = 3; /* operand size does not fit the register width on this path */
                        return;
                    } else {
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x28 + x_ret27, (value48 << 8) | value47);
                        uint16_t value75 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x24 + x_ret27);
                        uint16_t y4;
                        if ((value75 & 0x80) == 0) {
                            y4 = 0x14;
                        } else {
                            y4 = 0xFFEC;
                        }
                        if ((value75 & 0x40) == 0) {
                            uint16_t value76 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x22 + x_ret27);
                            BUS16_SET(c, (db_ret11 << 0x10) + 0x22 + x_ret27, (uint16_t)(y4 + value76));
                        } else {
                            uint16_t value77 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x20 + x_ret27);
                            BUS16_SET(c, (db_ret11 << 0x10) + 0x20 + x_ret27, (uint16_t)(y4 + value77));
                        }
                        uint8_t value78 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value79 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value80 = RAM8(0x0000 + sp0);
                        r->y = y4;
                        r->v = value78 & 0x40;
                        r->mf = value78 & 0x20;
                        r->xf = value78 & 0x10;
                        r->dp = (value80 << 8) | value79;
                        r->i = value78 & 0x04;
                        r->d = value78 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                }
            }
        }
    }
}
SOM_REGISTER(0xC139CD, SOM_RTS, "gen", construct_temporary_spell_entity, 0, L_X | L_Y | L_V, 5, 1, 0, 248, 107)
