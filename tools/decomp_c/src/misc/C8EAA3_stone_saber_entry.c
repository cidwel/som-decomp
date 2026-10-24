#include "som_c.h"

/* C8EAA3 stone_saber_entry   [class C, 97 bytes, 49 instructions]
 * Source: src/rom/stone_saber_entry.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void stone_saber_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = 1;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    RAM8(ACTOR_SABER_HITS_LEFT + battle_defender_ptr) = 0;
    RAM8(0x0000 + sp0 - 1) = y >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 3) = battle_defender_ptr >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)battle_defender_ptr;
    r->a = (a_hi << 8) | 1;
    r->x = battle_defender_ptr;
    r->z = battle_defender_ptr == 0;
    r->n = battle_defender_ptr & 0x8000;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEAC9, 0xC04530); GUARD_JSL(c, sp_call, 0xEAC9); } /* rebuild_actor_attributes_native */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t value = RAM8(0x0000 + sp0 - 4);
        uint8_t value2 = RAM8(0x0000 + sp0 - 3);
        BUS8_SET(c, (uint16_t)(dp_ret + 0x8F), 4);
        r->a = (a_all >> 8 << 8) | 4;
        r->x = value;
        r->y = value2;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEAD2, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xEAD2); } /* calculate_spell_attack_roll */
        r->sp += 3;
        bool x_ret3 = r->xf;
        uint16_t x_ret4 = r->x;
        uint8_t value3 = RAM8(0x0000 + sp0 - 2);
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xE195 + x_ret4);
        BUS8_SET(c, (db_ret << 0x10) + 0xE195 + x_ret4, value3 | value4);
        BUS16_SET(c, (db_ret << 0x10) + 0xCC78, 0);
        if (x_ret3) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            uint16_t value5 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 0xDE)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 0xDC)) + 0x2ADD, BUS8_RDP(c, (uint16_t)(dp_ret + 0xDE)));
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x83));
            uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0xE199 + x_ret4);
            BUS16_SET(c, (db_ret << 0x10) + 0xE199 + x_ret4, value5 | value7);
            r->a = value5 | value7;
            r->y = value6;
            r->z = (value5 | value7) == 0;
            r->n = (value5 | value7) & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEAF0, 0xC8EA69); GUARD_JSR(c, sp_call, 0xEAF0); } /* divide_spell_level_by_target_count */
            r->sp += 2;
            uint16_t a_all3 = r->a;
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS8_SET(c, (db_ret << 0x10) + 0xE19D + x_ret4, (uint8_t)((uint8_t)(value8 + 1) << 2));
            uint8_t value9 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1AE + x_ret4);
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS8_SET(c, (db_ret << 0x10) + 0xE1AE + x_ret4, (value9 & 0xF0) | value10);
            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->a = (a_all3 >> 8 << 8) | ((value9 & 0xF0) | value10);
            r->c = (uint8_t)((uint8_t)(value8 + 1) << 1) & 0x80;
            r->z = ((value9 & 0xF0) | value10) == 0;
            r->n = ((value9 & 0xF0) | value10) & 0x80;
            r->mf = 1;
            r->xf = 0;
            TAIL_CALL_DYN(c, 0xC80000 | (uint16_t)(((value12 << 8) | value11) + 1), SOM_RTS); /* jump through a pushed address */
        }
    } else {
        uint8_t value13 = RAM8(0x0000 + sp0 - 4);
        uint8_t value14 = RAM8(0x0000 + sp0 - 3);
        uint8_t value15 = RAM8(0x0000 + sp0 - 2);
        uint8_t value16 = RAM8(0x0000 + sp0 - 1);
        BUS8_SET(c, (uint16_t)(dp_ret + 0x8F), 4);
        r->a = (a_all >> 8 << 8) | 4;
        r->x = (value14 << 8) | value13;
        r->y = (value16 << 8) | value15;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEAD2, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xEAD2); } /* calculate_spell_attack_roll */
        r->sp += 1;
        bool x_ret5 = r->xf;
        uint16_t x_ret6 = r->x;
        uint8_t value17 = RAM8(0x0000 + sp0);
        uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + 0xE195 + x_ret6);
        BUS8_SET(c, (db_ret << 0x10) + 0xE195 + x_ret6, value17 | value18);
        BUS16_SET(c, (db_ret << 0x10) + 0xCC78, 0);
        if (x_ret5) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            uint16_t value19 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp_ret + 0xDE)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp_ret + 0xDC)) + 0x2ADD, BUS8_RDP(c, (uint16_t)(dp_ret + 0xDE)));
            uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x83));
            uint16_t value21 = BUS16_RDP(c, (db_ret << 0x10) + 0xE199 + x_ret6);
            BUS16_SET(c, (db_ret << 0x10) + 0xE199 + x_ret6, value19 | value21);
            r->a = value19 | value21;
            r->y = value20;
            r->z = (value19 | value21) == 0;
            r->n = (value19 | value21) & 0x8000;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEAF0, 0xC8EA69); GUARD_JSR(c, sp_call, 0xEAF0); } /* divide_spell_level_by_target_count */
            uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS8_SET(c, (db_ret << 0x10) + 0xE19D + x_ret6, (uint8_t)((uint8_t)(value22 + 1) << 2));
            uint8_t value23 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1AE + x_ret6);
            uint8_t value24 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS8_SET(c, (db_ret << 0x10) + 0xE1AE + x_ret6, (value23 & 0xF0) | value24);
            SET_A8(r, (value23 & 0xF0) | value24);
            r->c = (uint8_t)((uint8_t)(value22 + 1) << 1) & 0x80;
            r->z = ((value23 & 0xF0) | value24) == 0;
            r->n = ((value23 & 0xF0) | value24) & 0x80;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC8EAA3, SOM_RTS, "gen", stone_saber_entry, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 97, 49)
