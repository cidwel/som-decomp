#include "som_c.h"

/* C055EC change_actor_identity_and_attributes   [class B, 345 bytes, 142 instructions]
 * Source: src/rom/change_actor_identity_and_attributes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void change_actor_identity_and_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM16_SET(BATTLE_ATTACKER_PTR, x & 0x1FFF);
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    RAM8(0x03B2) = a;
    if (!(a & 0x80)) {
        BUS8_SET(c, 0x004202, a);
        BUS8_SET(c, 0x004203, 0x1D);
        r->a = ((x & 0x1FFF) >> 8 << 8) | 0x1D;
        r->x = battle_attacker_ptr;
        r->y = x & 0x1FFF;
        r->z = 0;
        r->n = 0;
        r->dp = 0x0300;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x561B, 0xC04E31); GUARD_JSR(c, sp_call, 0x561B); } /* clear_actor_identity_attribute_record */
        r->sp += 4;
        uint16_t battle_attacker_ptr2 = RAM16(BATTLE_ATTACKER_PTR);
        uint16_t value = BUS16(c, 0x004216);
        uint16_t value2 = BUS16(c, 0xD01C01 + value);
        RAM16_SET(ACTOR_HP + battle_attacker_ptr2, value2);
        RAM16_SET(ACTOR_MAX_HP + battle_attacker_ptr2, value2);
        uint16_t value3 = BUS16(c, 0xD01C0E + value);
        RAM16_SET(ACTOR_MONSTER_TYPE + battle_attacker_ptr2, value3);
        uint16_t value4 = BUS16(c, 0xD01C09 + value);
        RAM16_SET(ACTOR_DEFENSE + battle_attacker_ptr2, value4);
        uint16_t value5 = BUS16(c, 0xD01C0C + value);
        RAM16_SET(ACTOR_MAGIC_DEFENSE + battle_attacker_ptr2, value5);
        uint16_t value6 = BUS16(c, 0xD01C14 + value);
        RAM16_SET(ACTOR_STATUS_IMMUNITY + battle_attacker_ptr2, value6);
        uint16_t value7 = BUS16(c, 0xD01C17 + value);
        RAM16_SET(0xE1E8 + battle_attacker_ptr2, value7);
        uint16_t value8 = BUS16(c, 0xD01C04 + value);
        RAM16_SET(ACTOR_STRENGTH + battle_attacker_ptr2, value8);
        uint16_t value9 = BUS16(c, 0xD01C06 + value);
        RAM16_SET(ACTOR_INTELLIGENCE + battle_attacker_ptr2, value9);
        uint16_t value10 = BUS16(c, 0xD01C10 + value);
        RAM16_SET(0xE18D + battle_attacker_ptr2, value10);
        uint16_t value11 = BUS16(c, 0xD01C1B + value);
        RAM16_SET(0xE1C8 + battle_attacker_ptr2, value11);
        uint8_t value12 = RAM8(0x03B2);
        RAM8(0xE180 + battle_attacker_ptr2) = value12;
        RAM8(0xE1E7 + battle_attacker_ptr2) = value12;
        uint8_t value13 = BUS8(c, 0xD01C00 + value);
        RAM8(ACTOR_LEVEL + battle_attacker_ptr2) = value13;
        uint8_t value14 = BUS8(c, 0xD01C03 + value);
        RAM8(ACTOR_MP + battle_attacker_ptr2) = value14;
        RAM8(ACTOR_MAX_MP + battle_attacker_ptr2) = value14;
        uint8_t value15 = BUS8(c, 0xD01C08 + value);
        RAM8(ACTOR_EVADE + battle_attacker_ptr2) = value15;
        uint8_t value16 = BUS8(c, 0xD01C0B + value);
        RAM8(ACTOR_MAGIC_EVADE + battle_attacker_ptr2) = value16;
        uint8_t value17 = BUS8(c, 0xD01C19 + value);
        RAM8(0xE1CA + battle_attacker_ptr2) = value17;
        RAM8(BATTLE_TEMP_A4) = value17;
        RAM8(ACTOR_GUARD_FLAGS + battle_attacker_ptr2) = value17 & 1;
        RAM8(ACTOR_GUARD_FLAGS + battle_attacker_ptr2) = ((RAM8(BATTLE_TEMP_A4) & 0x80) >> 6) | RAM8(ACTOR_GUARD_FLAGS + battle_attacker_ptr2);
        RAM8(ACTOR_GUARD_FLAGS + battle_attacker_ptr2) = ((RAM8(BATTLE_TEMP_A4) & 0x40) >> 4) | RAM8(ACTOR_GUARD_FLAGS + battle_attacker_ptr2);
        uint8_t value20 = BUS8(c, 0xD01C1A + value);
        RAM8(0xE1C4 + battle_attacker_ptr2) = value20 & 0x0F;
        uint8_t value21 = BUS8(c, 0xD01C1A + value);
        RAM8(0xE1C0 + battle_attacker_ptr2) = value21 >> 4;
        uint8_t value22 = RAM8(0xE1E8 + battle_attacker_ptr2);
        RAM8(0xE1E3 + battle_attacker_ptr2) = value22;
        uint16_t battle_attacker_ptr3 = RAM16(BATTLE_ATTACKER_PTR);
        r->a = (value11 >> 8 << 8) | value22;
        r->x = battle_attacker_ptr3;
        r->y = battle_attacker_ptr2;
        r->c = value21 >> 3 & 0x01;
        r->z = battle_attacker_ptr3 == 0;
        r->n = battle_attacker_ptr3 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x56E2, 0xC0457C); GUARD_JSL(c, sp_call, 0x56E2); } /* refresh_actor_appearance_native */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        uint8_t value23 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1E7 + x_ret3);
        BUS8_SET(c, 0x004202, value23);
        BUS8_SET(c, 0x004203, 5);
        uint16_t value24 = BUS16(c, 0x004216);
        if (x_ret2) {
            uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x83));
            uint8_t value26 = BUS8(c, 0xD03A50 + (uint8_t)value24);
            BUS8_SET(c, (db_ret << 0x10) + 0xE1CE + value25, value26);
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x83));
            uint8_t value28 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FB + value27);
            if ((value28 & 1) != 0) {
                BUS8_SET(c, (db_ret << 0x10) + 0xE033 + value27, 0xD2);
            }
            uint8_t value29 = RAM8(0x0000 + sp0 - 3);
            uint8_t value30 = RAM8(0x0000 + sp0 - 2);
            uint8_t value31 = RAM8(0x0000 + sp0 - 1);
            uint8_t value32 = RAM8(0x0000 + sp0);
            r->a = (value24 >> 8 << 8) | (uint8_t)a_all2;
            r->y = value25;
            r->c = value29 & 0x01;
            r->v = value29 & 0x40;
            r->mf = value29 & 0x20;
            r->xf = value29 & 0x10;
            r->db = value30;
            r->dp = (value32 << 8) | value31;
            r->i = value29 & 0x04;
            r->d = value29 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        } else {
            uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x83));
            uint8_t value34 = BUS8(c, 0xD03A50 + value24);
            BUS8_SET(c, (db_ret << 0x10) + 0xE1CE + value33, value34);
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x83));
            uint8_t value36 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FB + value35);
            if ((value36 & 1) != 0) {
                BUS8_SET(c, (db_ret << 0x10) + 0xE033 + value35, 0xD2);
            }
            uint8_t value37 = RAM8(0x0000 + sp0 - 3);
            uint8_t value38 = RAM8(0x0000 + sp0 - 2);
            uint8_t value39 = RAM8(0x0000 + sp0 - 1);
            uint8_t value40 = RAM8(0x0000 + sp0);
            r->a = (value24 >> 8 << 8) | (uint8_t)a_all2;
            r->y = value33;
            r->c = value37 & 0x01;
            r->v = value37 & 0x40;
            r->mf = value37 & 0x20;
            r->xf = value37 & 0x10;
            r->db = value38;
            r->dp = (value40 << 8) | value39;
            r->i = value37 & 0x04;
            r->d = value37 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
    }
    RAM8(0xE180 + (x & 0x1FFF)) = a;
    RAM8(0xE1E7 + (x & 0x1FFF)) = a;
    RAM16_SET(ACTOR_STATUS + battle_attacker_ptr, 0);
    RAM16_SET(0xE1EE + battle_attacker_ptr, 0);
    RAM16_SET(0xE19E + battle_attacker_ptr, 0);
    RAM8(0xE1E3 + battle_attacker_ptr) = 0;
    RAM8(0xE1E9 + battle_attacker_ptr) = 0;
    RAM8(0xE1E8 + battle_attacker_ptr) = 0;
    RAM8(ACTOR_KIND_FLAGS + battle_attacker_ptr) = 0;
    RAM8(0xE1FA + battle_attacker_ptr) = 7;
    r->a = ((x & 0x1FFF) >> 8 << 8) | 7;
    r->x = battle_attacker_ptr;
    r->y = x & 0x1FFF;
    r->z = 0;
    r->n = 0;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5740, 0xC04530); GUARD_JSL(c, sp_call, 0x5740); } /* rebuild_actor_attributes_native */
    r->sp += 4;
    uint8_t value41 = RAM8(0x0000 + sp0 - 3);
    uint8_t value42 = RAM8(0x0000 + sp0 - 2);
    uint8_t value43 = RAM8(0x0000 + sp0 - 1);
    uint8_t value44 = RAM8(0x0000 + sp0);
    r->c = value41 & 0x01;
    r->v = value41 & 0x40;
    r->mf = value41 & 0x20;
    r->xf = value41 & 0x10;
    r->db = value42;
    r->dp = (value44 << 8) | value43;
    r->i = value41 & 0x04;
    r->d = value41 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC055EC, SOM_RTL, "gen", change_actor_identity_and_attributes, 0, L_B | L_Y | L_C | L_V, 6, 1, 0, 345, 142)
