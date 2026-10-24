#include "som_c.h"

/* C2581D choose_linked_boss_child_attack_projectile_or_spell_after_hp_change   [class B, 210 bytes, 85 instructions]
 * Source: src/rom/choose_linked_boss_child_attack_projectile_or_spell_after_hp_change.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void choose_linked_boss_child_attack_projectile_or_spell_after_hp_change(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x002D + value);
    uint16_t value3 = RAM16(0x00AD + value);
    if (value2 < value3) {
        RAM16_SET(0x00AD + value, 0);
        uint16_t value4 = RAM16(0x00A9 + value);
        r->a = value4;
        r->x = value;
        r->c = value2 >= value3;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5830, 0xC208D9); GUARD_JSR(c, sp_call, 0x5830); } /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all = r->a;
        uint16_t value5 = RAM16(0x0287);
        if (a_all >= 8) {
            RAM16_SET(0x00B8 + value5, 0x20);
            RAM16_SET(0x0081 + RAM16(0x00B0 + value5), 5);
            uint16_t value7 = RAM16(0x00B2 + value5);
            RAM16_SET(0x0081 + value7, 5);
            r->a = 2;
            r->x = value5;
            r->y = value7;
            r->c = a_all >= 8;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x58A9, 0xC2300B); GUARD_JSR(c, sp_call, 0x58A9); } /* draw_boss_frame_random_number */
            uint16_t a_all2 = r->a;
            RAM16_SET(0x0200, a_all2);
            uint16_t value8 = RAM16(0x0287);
            if (a_all2 == 0) {
                uint16_t value9 = RAM16(0x0184 + value8);
                uint16_t value10 = RAM16(0x0182 + value8);
                if (value9 >> 2 >= value10) {
                    r->a = 0x020B;
                    r->x = value8;
                    r->c = value9 >> 2 >= value10;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x58ED, 0xC25906); GUARD_JSR(c, sp_call, 0x58ED); } /* prepare_boss_spell_if_enabled_otherwise_unwind_caller */
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0x0107;
                r->x = value8;
                r->c = value9 >> 2 >= value10;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x58E6, 0xC25906); GUARD_JSR(c, sp_call, 0x58E6); } /* prepare_boss_spell_if_enabled_otherwise_unwind_caller */
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM16_SET(0x00A9 + value8, 4);
            if (RAM16(0x0042 + value8) != 0) {
                RAM16_SET(0x0200, (uint16_t)(RAM16(0x0200) - 1));
                uint16_t value12 = RAM16(0x0200);
                uint8_t a1;
                if (value12 == 0) {
                    a1 = 0x1B;
                } else {
                    a1 = 0;
                }
                r->a = a1;
                r->x = value8;
                r->c = a_all2 >= 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x58D5, 0xC258EF); GUARD_JSR(c, sp_call, 0x58D5); } /* prepare_boss_attack_row_and_create_selected_projectile */
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = 9;
            r->x = value8;
            r->c = a_all2 >= 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x58C3, 0xC258EF); GUARD_JSR(c, sp_call, 0x58C3); } /* prepare_boss_attack_row_and_create_selected_projectile */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = 7;
        r->x = value5;
        r->c = a_all >= 8;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x583D, 0xC2300B); GUARD_JSR(c, sp_call, 0x583D); } /* draw_boss_frame_random_number */
        uint16_t a_all7 = r->a;
        uint16_t value13 = RAM16(0x0287);
        if (a_all7 == 0) {
            RAM16_SET(0x00B8 + value13, 0x20);
            RAM16_SET(0x0081 + RAM16(0x00B0 + value13), 5);
            uint16_t value15 = RAM16(0x00B2 + value13);
            RAM16_SET(0x0081 + value15, 5);
            r->a = 2;
            r->x = value13;
            r->y = value15;
            r->c = a_all7 >= 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x58A9, 0xC2300B); GUARD_JSR(c, sp_call, 0x58A9); } /* draw_boss_frame_random_number */
            uint16_t a_all8 = r->a;
            RAM16_SET(0x0200, a_all8);
            uint16_t value16 = RAM16(0x0287);
            if (a_all8 == 0) {
                uint16_t value17 = RAM16(0x0184 + value16);
                uint16_t value18 = RAM16(0x0182 + value16);
                if (value17 >> 2 >= value18) {
                    r->a = 0x020B;
                    r->x = value16;
                    r->c = value17 >> 2 >= value18;
                    r->z = 0;
                    r->n = 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x58ED, 0xC25906); GUARD_JSR(c, sp_call, 0x58ED); } /* prepare_boss_spell_if_enabled_otherwise_unwind_caller */
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0x0107;
                r->x = value16;
                r->c = value17 >> 2 >= value18;
                r->z = 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x58E6, 0xC25906); GUARD_JSR(c, sp_call, 0x58E6); } /* prepare_boss_spell_if_enabled_otherwise_unwind_caller */
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM16_SET(0x00A9 + value16, 4);
            if (RAM16(0x0042 + value16) != 0) {
                RAM16_SET(0x0200, (uint16_t)(RAM16(0x0200) - 1));
                uint16_t value20 = RAM16(0x0200);
                uint8_t a2;
                if (value20 == 0) {
                    a2 = 0x1B;
                } else {
                    a2 = 0;
                }
                r->a = a2;
                r->x = value16;
                r->c = a_all8 >= 0;
                r->n = 0;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x58D5, 0xC258EF); GUARD_JSR(c, sp_call, 0x58D5); } /* prepare_boss_attack_row_and_create_selected_projectile */
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = 9;
            r->x = value16;
            r->c = a_all8 >= 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x58C3, 0xC258EF); GUARD_JSR(c, sp_call, 0x58C3); } /* prepare_boss_attack_row_and_create_selected_projectile */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM16_SET(0x00B8 + value13, 8);
        r->a = 3;
        r->x = value13;
        r->c = a_all7 >= 0;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5850, 0xC2300B); GUARD_JSR(c, sp_call, 0x5850); } /* draw_boss_frame_random_number */
        uint16_t a_all13 = r->a;
        uint16_t value21 = RAM16(0x0287);
        r->a = (uint16_t)(a_all13 + 0x60);
        r->x = value21;
        r->c = a_all13 + 0x60 > 0xFFFF;
        r->z = value21 == 0;
        r->n = value21 & 0x8000;
        r->v = ((a_all13 ^ (uint16_t)(a_all13 + 0x60)) & ((uint16_t)(a_all13 + 0x60) ^ 0x60) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x585A, 0xC0006C); GUARD_JSL(c, sp_call, 0x585A); } /* boss_attack_row_public_jump */
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret18 = r->xf;
        if (x_ret18) {
            uint8_t value22 = RAM8(0x0287);
            uint16_t value23 = RAM16(0x00A9 + value22);
            uint16_t value24 = RAM16(0x0002 + (uint8_t)((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) + 0xE000));
            uint16_t value25 = RAM16(0x002B + value22);
            if (value24 < value25) {
                uint8_t value26 = RAM8(0x00B0 + value22);
                RAM16_SET(0x0081 + value26, 3);
                uint16_t value27 = RAM16(0x00A9 + value22);
                RAM16_SET(0x00A9 + value26, value27);
                r->a = value27;
                r->x = value22;
                r->y = value26;
                r->c = value24 >= value25;
                r->v = (((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) ^ (uint16_t)((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) + 0xE000)) & ((uint16_t)((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->xf = 1;
                RETURN_RTS(c);
            }
            uint8_t value28 = RAM8(0x00B2 + value22);
            RAM16_SET(0x0081 + value28, 3);
            uint16_t value29 = RAM16(0x00A9 + value22);
            RAM16_SET(0x00A9 + value28, value29);
            r->a = value29;
            r->x = value22;
            r->y = value28;
            r->c = value24 >= value25;
            r->v = (((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) ^ (uint16_t)((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) + 0xE000)) & ((uint16_t)((((uint8_t)(value23 << 1) << 8) | ((uint16_t)(value23 << 1) >> 8)) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value30 = RAM16(0x0287);
            uint16_t value31 = RAM16(0x00A9 + value30);
            uint16_t value32 = RAM16(0x0002 + (uint16_t)((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) + 0xE000));
            uint16_t value33 = RAM16(0x002B + value30);
            if (value32 < value33) {
                uint16_t value34 = RAM16(0x00B0 + value30);
                RAM16_SET(0x0081 + value34, 3);
                uint16_t value35 = RAM16(0x00A9 + value30);
                RAM16_SET(0x00A9 + value34, value35);
                r->a = value35;
                r->x = value30;
                r->y = value34;
                r->c = value32 >= value33;
                r->v = (((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) ^ (uint16_t)((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) + 0xE000)) & ((uint16_t)((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value36 = RAM16(0x00B2 + value30);
            RAM16_SET(0x0081 + value36, 3);
            uint16_t value37 = RAM16(0x00A9 + value30);
            RAM16_SET(0x00A9 + value36, value37);
            r->a = value37;
            r->x = value30;
            r->y = value36;
            r->c = value32 >= value33;
            r->v = (((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) ^ (uint16_t)((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) + 0xE000)) & ((uint16_t)((((uint8_t)(value31 << 1) << 8) | ((uint16_t)(value31 << 1) >> 8)) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    r->a = value2;
    r->x = value;
    r->c = value2 >= value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2581D, SOM_RTS, "gen", choose_linked_boss_child_attack_projectile_or_spell_after_hp_change, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 210, 85)
