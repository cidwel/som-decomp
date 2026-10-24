#include "som_c.h"

/* C04CB8 refresh_three_party_weapon_records_and_rebuild_attributes   [class B, 186 bytes, 85 instructions]
 * Source: src/rom/refresh_three_party_weapon_records_and_rebuild_attributes.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void refresh_three_party_weapon_records_and_rebuild_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM16_SET(BATTLE_MUL_WORK, 0);
    RAM8(0x03D1) = 0;
    RAM8(0x03B0) = 3;
    uint8_t a_hi1 = 3;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x03D0) = 7;
        RAM8(BATTLE_TEMP_AC) = RAM8(0xE1E4 + y1);
        uint8_t a_hi2 = a_hi1;
        bool carry2 = carry1;
        bool overflow2 = overflow1;
        for (;;) {
            uint8_t inventory_weapons = RAM8(INVENTORY_WEAPONS + RAM16(0x03D0));
            uint8_t a_hi5;
            bool carry4;
            bool overflow4;
            if (inventory_weapons == 0xFF) {
                RAM8(0x03D0)--;
                if (!(RAM8(0x03D0) & 0x80)) {
                    carry2 = inventory_weapons >= 0xFF;
                    continue;
                }
                a_hi5 = a_hi2;
                carry4 = inventory_weapons >= 0xFF;
                overflow4 = overflow2;
            } else {
                uint8_t a_hi4;
                bool carry3;
                bool overflow3;
                if ((inventory_weapons & 0x3F) == 0) {
                    RAM8(0x03D0)--;
                    if (!(RAM8(0x03D0) & 0x80)) {
                        carry2 = inventory_weapons >= 0xFF;
                        continue;
                    }
                    a_hi4 = a_hi2;
                    carry3 = inventory_weapons >= 0xFF;
                    overflow3 = overflow2;
                } else {
                    RAM8(BATTLE_TEMP_A4) = inventory_weapons & 0x3F;
                    BUS8_SET(c, 0x004202, RAM8(0x03D0));
                    BUS8_SET(c, 0x004203, 9);
                    uint8_t value4 = BUS8(c, 0x004216);
                    uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
                    RAM8(BATTLE_TEMP_A8) = (uint8_t)(value4 + battle_temp_a4);
                    BUS8_SET(c, 0x004202, (uint8_t)(value4 + battle_temp_a4));
                    BUS8_SET(c, 0x004203, 0x0C);
                    uint16_t value5 = BUS16(c, 0x004216);
                    uint8_t value6 = BUS8(c, 0xD01000 + value5);
                    uint8_t battle_temp_ac = RAM8(BATTLE_TEMP_AC);
                    uint8_t a_hi3;
                    if (value6 == battle_temp_ac) {
                        uint8_t battle_temp_a8 = RAM8(BATTLE_TEMP_A8);
                        RAM8(0xE1E8 + y1) = battle_temp_a8;
                        RAM8(BATTLE_TEMP_A6) = battle_temp_a8;
                        RAM8(0xE1FA + y1) |= 4;
                        uint16_t value8 = RAM16(ACTOR_STATUS + y1);
                        if ((value8 & 0xC760) == 0) {
                            uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
                            RAM8(0xE1E3 + y1) = battle_temp_a6;
                            RAM8(0xE1E8 + y1) = battle_temp_a6;
                        }
                        a_hi3 = value8 >> 8;
                    } else {
                        RAM8(0x03D0)--;
                        if (!(RAM8(0x03D0) & 0x80)) {
                            a_hi2 = value5 >> 8;
                            carry2 = value6 >= battle_temp_ac;
                            overflow2 = ((value4 ^ (uint8_t)(value4 + battle_temp_a4)) & (battle_temp_a4 ^ (uint8_t)(value4 + battle_temp_a4)) & 0x80) != 0;
                            continue;
                        }
                        a_hi3 = value5 >> 8;
                    }
                    a_hi4 = a_hi3;
                    carry3 = value6 >= battle_temp_ac;
                    overflow3 = ((value4 ^ (uint8_t)(value4 + battle_temp_a4)) & (battle_temp_a4 ^ (uint8_t)(value4 + battle_temp_a4)) & 0x80) != 0;
                }
                a_hi5 = a_hi4;
                carry4 = carry3;
                overflow4 = overflow3;
            }
            a_hi2 = a_hi5;
            carry2 = carry4;
            overflow2 = overflow4;
            break;
        }
        RAM8(0x03CD)++;
        RAM8(0x03CD)++;
        uint16_t battle_mul_work = RAM16(BATTLE_MUL_WORK);
        RAM8(0x03B0)--;
        if (RAM8(0x03B0) != 0) {
            a_hi1 = a_hi2;
            y1 = battle_mul_work;
            carry1 = carry2;
            overflow1 = overflow2;
            continue;
        }
        a_hi1 = a_hi2;
        y1 = battle_mul_work;
        carry1 = carry2;
        overflow1 = overflow2;
        break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = 0;
    r->y = y1;
    r->c = carry1;
    r->z = 1;
    r->n = 0;
    r->v = overflow1;
    r->xf = 0;
    r->dp = 0x0300;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4D5F, 0xC04530); GUARD_JSL(c, sp_call, 0x4D5F); } /* rebuild_actor_attributes_native */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4D66, 0xC04530); GUARD_JSL(c, sp_call, 0x4D66); } /* rebuild_actor_attributes_native */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4D6D, 0xC04530); GUARD_JSL(c, sp_call, 0x4D6D); } /* rebuild_actor_attributes_native */
    r->sp += 4;
    uint8_t value9 = RAM8(0x0000 + sp0 - 3);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->db = value10;
    r->dp = (value12 << 8) | value11;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC04CB8, SOM_RTL, "gen", refresh_three_party_weapon_records_and_rebuild_attributes, 0, 0, 5, 1, 1, 186, 85)
