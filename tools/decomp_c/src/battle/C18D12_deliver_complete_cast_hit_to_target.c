#include "som_c.h"

/* C18D12 deliver_complete_cast_hit_to_target   [class B, 110 bytes, 54 instructions]
 * Source: src/rom/deliver_complete_cast_hit_to_target.s
 * Documented in docs/actor-cast-spell-reflection.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void deliver_complete_cast_hit_to_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x00ED);
    if (value & 0x80) {
        uint8_t value2 = RAM8(0xE000 + y);
        if (value2 == 0) {
            SET_A8(r, value2);
            r->c = 0;
            r->v = value & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (value2 & 0x80) {
            SET_A8(r, value2);
            r->c = 0;
            r->v = value & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint16_t value3 = RAM16(0xE116 + x);
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        RAM8(0x0000 + sp0 - 2) = y >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
        r->a = value3;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->v = value & 0x40;
        r->mf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8D30, 0xC00054); GUARD_JSL(c, sp_call, 0x8D30); } /* spell_hit_or_reflection_public_jump */
        r->sp += 4;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        if ((a_all & 0xFF) == 0) {
            if (x_ret) {
                c->fail = 3;
                return;
            } else {
                uint8_t value11 = RAM8(0x0000 + sp0 - 3);
                uint8_t value12 = RAM8(0x0000 + sp0 - 2);
                uint8_t value13 = RAM8(0x0000 + sp0 - 1);
                uint8_t value14 = RAM8(0x0000 + sp0);
                BUS8_SET(c, (db_ret << 0x10) + 0xE108 + ((value12 << 8) | value11), 0x80);
                uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 0xE170 + ((value14 << 8) | value13));
                BUS8_SET(c, (db_ret << 0x10) + 0xE10A + ((value12 << 8) | value11), value15);
                uint8_t value16 = BUS8_RDP(c, (db_ret << 0x10) + 0xE110 + ((value14 << 8) | value13));
                BUS8_SET(c, (db_ret << 0x10) + 0xE109 + ((value12 << 8) | value11), value16);
                uint8_t value17 = BUS8_RDP(c, (db_ret << 0x10) + 0xE111 + ((value14 << 8) | value13));
                BUS8_SET(c, (db_ret << 0x10) + 0xE10B + ((value12 << 8) | value11), value17);
                RAM8(0x0000 + sp0) = value14;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)((value14 << 8) | value13);
                uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + 0xE060 + ((value12 << 8) | value11));
                if (value18 == 0) {
                    BUS16_SET(c, (db_ret << 0x10) + 0xE10C + ((value12 << 8) | value11), (value14 << 8) | value13);
                    r->a = (value14 << 8) | value13;
                    r->x = (value14 << 8) | value13;
                    r->y = (value12 << 8) | value11;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8D7D, 0xC187C2); GUARD_JSR(c, sp_call, 0x8D7D); } /* transfer_cast_presentation_to_target */
                    r->c = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (value18 == 0x40) {
                    BUS16_SET(c, (db_ret << 0x10) + 0xE10C + ((value12 << 8) | value11), (value14 << 8) | value13);
                    r->a = (value14 << 8) | value13;
                    r->x = (value14 << 8) | value13;
                    r->y = (value12 << 8) | value11;
                    r->c = value18 >= 0x40;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8D7D, 0xC187C2); GUARD_JSR(c, sp_call, 0x8D7D); } /* transfer_cast_presentation_to_target */
                    r->c = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (value18 != 0xC0) {
                    BUS16_SET(c, (db_ret << 0x10) + 0xE10C + ((value12 << 8) | value11), (value14 << 8) | value13);
                    r->a = (value14 << 8) | value13;
                    r->y = (value12 << 8) | value11;
                    r->c = 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = value18;
                r->x = (value14 << 8) | value13;
                r->y = (value12 << 8) | value11;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8D6A, 0xC181F2); GUARD_JSR(c, sp_call, 0x8D6A); } /* restore_target_state_after_previous_cast */
                r->sp += 2;
                uint16_t y_ret5 = r->y;
                uint8_t value19 = RAM8(0x0000 + sp0 - 1);
                uint8_t value20 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (db_ret << 0x10) + 0xE10C + y_ret5, (value20 << 8) | value19);
                r->a = (value20 << 8) | value19;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8D7D, 0xC187C2); GUARD_JSR(c, sp_call, 0x8D7D); } /* transfer_cast_presentation_to_target */
                r->c = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if (x_ret) {
            uint8_t value21 = RAM8(0x0000 + sp0 - 3);
            uint8_t value22 = RAM8(0x0000 + sp0 - 2);
            uint8_t value23 = RAM8(0x0000 + sp0 - 1);
            uint8_t value24 = RAM8(0x0000 + sp0);
            r->a = (uint8_t)x_ret2;
            r->x = value22;
            r->y = value21;
            r->c = (a_all & 0xFF) >= 0x80;
            r->z = value22 == 0;
            r->n = value22 & 0x80;
            r->mf = 0;
            r->xf = 1;
            TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value24 << 8) | value23) + 1), SOM_RTS); /* jump through a pushed address */
        } else {
            uint8_t value25 = RAM8(0x0000 + sp0 - 3);
            uint8_t value26 = RAM8(0x0000 + sp0 - 2);
            r->a = x_ret2;
            r->y = (value26 << 8) | value25;
            r->c = (a_all & 0xFF) >= 0x80;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    if (y < 0x0600) {
        uint8_t value29 = RAM8(0xE000 + y);
        if (value29 == 0) {
            SET_A8(r, value29);
            r->c = 0;
            r->v = value & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (value29 & 0x80) {
            SET_A8(r, value29);
            r->c = 0;
            r->v = value & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint16_t value30 = RAM16(0xE116 + x);
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        RAM8(0x0000 + sp0 - 2) = y >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
        r->a = value30;
        r->c = y >= 0x0600;
        r->z = value30 == 0;
        r->n = value30 & 0x8000;
        r->v = value & 0x40;
        r->mf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x8D30, 0xC00054); GUARD_JSL(c, sp_call, 0x8D30); } /* spell_hit_or_reflection_public_jump */
        r->sp += 4;
        uint8_t db_ret6 = r->db;
        bool x_ret13 = r->xf;
        uint16_t a_all7 = r->a;
        uint16_t x_ret14 = r->x;
        if ((a_all7 & 0xFF) == 0) {
            if (x_ret13) {
                c->fail = 3;
                return;
            } else {
                uint8_t value38 = RAM8(0x0000 + sp0 - 3);
                uint8_t value39 = RAM8(0x0000 + sp0 - 2);
                uint8_t value40 = RAM8(0x0000 + sp0 - 1);
                uint8_t value41 = RAM8(0x0000 + sp0);
                BUS8_SET(c, (db_ret6 << 0x10) + 0xE108 + ((value39 << 8) | value38), 0x80);
                uint8_t value42 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xE170 + ((value41 << 8) | value40));
                BUS8_SET(c, (db_ret6 << 0x10) + 0xE10A + ((value39 << 8) | value38), value42);
                uint8_t value43 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xE110 + ((value41 << 8) | value40));
                BUS8_SET(c, (db_ret6 << 0x10) + 0xE109 + ((value39 << 8) | value38), value43);
                uint8_t value44 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xE111 + ((value41 << 8) | value40));
                BUS8_SET(c, (db_ret6 << 0x10) + 0xE10B + ((value39 << 8) | value38), value44);
                RAM8(0x0000 + sp0) = value41;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)((value41 << 8) | value40);
                uint8_t value45 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xE060 + ((value39 << 8) | value38));
                if (value45 == 0) {
                    BUS16_SET(c, (db_ret6 << 0x10) + 0xE10C + ((value39 << 8) | value38), (value41 << 8) | value40);
                    r->a = (value41 << 8) | value40;
                    r->x = (value41 << 8) | value40;
                    r->y = (value39 << 8) | value38;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8D7D, 0xC187C2); GUARD_JSR(c, sp_call, 0x8D7D); } /* transfer_cast_presentation_to_target */
                    r->c = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (value45 == 0x40) {
                    BUS16_SET(c, (db_ret6 << 0x10) + 0xE10C + ((value39 << 8) | value38), (value41 << 8) | value40);
                    r->a = (value41 << 8) | value40;
                    r->x = (value41 << 8) | value40;
                    r->y = (value39 << 8) | value38;
                    r->c = value45 >= 0x40;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8D7D, 0xC187C2); GUARD_JSR(c, sp_call, 0x8D7D); } /* transfer_cast_presentation_to_target */
                    r->c = 0;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (value45 != 0xC0) {
                    BUS16_SET(c, (db_ret6 << 0x10) + 0xE10C + ((value39 << 8) | value38), (value41 << 8) | value40);
                    r->a = (value41 << 8) | value40;
                    r->y = (value39 << 8) | value38;
                    r->c = 0;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = value45;
                r->x = (value41 << 8) | value40;
                r->y = (value39 << 8) | value38;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8D6A, 0xC181F2); GUARD_JSR(c, sp_call, 0x8D6A); } /* restore_target_state_after_previous_cast */
                r->sp += 2;
                uint16_t y_ret11 = r->y;
                uint8_t value46 = RAM8(0x0000 + sp0 - 1);
                uint8_t value47 = RAM8(0x0000 + sp0);
                BUS16_SET(c, (db_ret6 << 0x10) + 0xE10C + y_ret11, (value47 << 8) | value46);
                r->a = (value47 << 8) | value46;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8D7D, 0xC187C2); GUARD_JSR(c, sp_call, 0x8D7D); } /* transfer_cast_presentation_to_target */
                r->c = 0;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if (x_ret13) {
            uint8_t value48 = RAM8(0x0000 + sp0 - 3);
            uint8_t value49 = RAM8(0x0000 + sp0 - 2);
            uint8_t value50 = RAM8(0x0000 + sp0 - 1);
            uint8_t value51 = RAM8(0x0000 + sp0);
            r->a = (uint8_t)x_ret14;
            r->x = value49;
            r->y = value48;
            r->c = (a_all7 & 0xFF) >= 0x80;
            r->z = value49 == 0;
            r->n = value49 & 0x80;
            r->mf = 0;
            r->xf = 1;
            TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value51 << 8) | value50) + 1), SOM_RTS); /* jump through a pushed address */
        } else {
            uint8_t value52 = RAM8(0x0000 + sp0 - 3);
            uint8_t value53 = RAM8(0x0000 + sp0 - 2);
            r->a = x_ret14;
            r->y = (value53 << 8) | value52;
            r->c = (a_all7 & 0xFF) >= 0x80;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    r->c = 0;
    r->v = value & 0x40;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18D12, SOM_RTS, "gen", deliver_complete_cast_hit_to_target, SOM_UNWINDS, L_A | L_B | L_Y | L_C | L_V, 4, -1, 0, 110, 54)
