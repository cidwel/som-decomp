#include "som_c.h"

/* C048E6 read_appearance_level_and_party_charge   [class B, 180 bytes, 93 instructions]
 * Source: src/rom/read_appearance_level_and_party_charge.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void read_appearance_level_and_party_charge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    RAM16_SET(0x03D0, x);
    RAM8(BATTLE_DIV_WORK) = RAM8(0xE1E4 + x);
    if (!(RAM8(ACTOR_KIND_FLAGS + x) & 0x80)) {
        RAM8(BATTLE_DIV_WORK) = 1;
    }
    uint8_t battle_div_work = RAM8(BATTLE_DIV_WORK);
    RAM8(0x03D0) = battle_div_work >> 1;
    uint16_t value3 = RAM16(0x03D0);
    RAM8(0x03D4) = RAM8(0xE1C0 + value3);
    bool carry1;
    if ((battle_div_work & 1) != 0) {
        carry1 = battle_div_work & 0x01;
    } else {
        RAM8(0x03D4) >>= 1;
        RAM8(0x03D4) >>= 1;
        RAM8(0x03D4) >>= 1;
        uint8_t value8 = RAM8(0x03D4);
        RAM8(0x03D4) >>= 1;
        carry1 = value8 & 0x01;
    }
    RAM8(ACTOR_WEAPON_LEVEL + x) = RAM8(0x03D4) & 0x0F;
    uint8_t value10 = RAM8(0x03BA);
    if (value10 == 0) {
        RAM8(0xCC76) = 0;
        r->a = value10;
        r->y = value3;
        r->c = carry1;
        r->z = value10 == 0;
        r->n = value10 & 0x80;
        r->v = battle_div_work & 0x40;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4924, 0xC0499A); GUARD_JSR(c, sp_call, 0x4924); } /* test_both_party_charge_globals */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        if (!carry_ret) {
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if (RAM8(0xE1E4) == 1) {
            RAM8(ACTOR_WEAPON_FLAGS + x) = 0x80;
            RAM16_SET(BATTLE_TEMP_A4, 0);
            uint8_t a1 = 0x80;
            uint8_t a_hi1 = a_all >> 8;
            uint16_t y1 = 7;
            bool overflow1 = battle_div_work & 0x40;
            for (;;) {
                uint16_t value12 = RAM16(0xE1D0 + y1);
                uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
                RAM16_SET(BATTLE_TEMP_A4, (uint16_t)((value12 & 0xFF) + battle_temp_a4));
                a1 = (uint8_t)((value12 & 0xFF) + battle_temp_a4);
                a_hi1 = (uint16_t)((value12 & 0xFF) + battle_temp_a4) >> 8;
                y1 = (uint16_t)(y1 - 1);
                overflow1 = (((value12 & 0xFF) ^ (uint16_t)((value12 & 0xFF) + battle_temp_a4)) & (battle_temp_a4 ^ (uint16_t)((value12 & 0xFF) + battle_temp_a4)) & 0x8000) != 0;
                if (!(!(y1 & 0x8000))) break;
            }
            BUS16_SET(c, 0x004204, (a_hi1 << 8) | a1);
            BUS8_SET(c, 0x004206, 0x64);
            uint8_t value13 = BUS8(c, 0x004214);
            RAM8(BATTLE_TEMP_A4) = value13;
            RAM8(BATTLE_TEMP_A6) = 7;
            RAM8(0x03AA) = 0;
            uint8_t a_hi2 = 0;
            uint16_t y2 = y1;
            bool overflow2 = overflow1;
            do {
                uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
                RAM8(0x0000 + sp0) = (((((battle_temp_a6 >> 8 << 7) | (overflow2 << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((battle_temp_a6 >> 1 == 0) << 1)) | (battle_temp_a6 & 1);
                RAM8(BATTLE_TEMP_A8) = RAM8(0xE1C0 + ((a_hi2 << 8) | (battle_temp_a6 >> 1)));
                if (!(battle_temp_a6 & 0x01)) {
                    RAM8(BATTLE_TEMP_A8) >>= 1;
                    RAM8(BATTLE_TEMP_A8) >>= 1;
                    RAM8(BATTLE_TEMP_A8) >>= 1;
                    RAM8(BATTLE_TEMP_A8) >>= 1;
                }
                uint8_t battle_temp_a85 = RAM8(BATTLE_TEMP_A8);
                uint8_t value15 = RAM8(0x03AA);
                RAM8(0x03AA) = (uint8_t)((battle_temp_a85 & 0x0F) + value15);
                RAM8(BATTLE_TEMP_A6)--;
                y2 = (a_hi2 << 8) | (battle_temp_a6 >> 1);
                overflow2 = (((battle_temp_a85 & 0x0F) ^ (uint8_t)((battle_temp_a85 & 0x0F) + value15)) & (value15 ^ (uint8_t)((battle_temp_a85 & 0x0F) + value15)) & 0x80) != 0;
            } while (!(RAM8(BATTLE_TEMP_A6) & 0x80));
            uint8_t value16 = RAM8(0x03AA);
            uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
            RAM8(0xCC76) = (uint8_t)((value16 >> 3) + battle_temp_a42);
            r->a = (a_hi2 << 8) | (uint8_t)((value16 >> 3) + battle_temp_a42);
            r->x = x;
            r->y = y2;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->y = value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC048E6, SOM_RTS, "gen", read_appearance_level_and_party_charge, 0, L_B | L_X | L_Y, 1, 1, 0, 180, 93)
