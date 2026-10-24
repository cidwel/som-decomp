#include "som_c.h"

static void write_hud_decimal_number(SomCtx *c);
static void write_hud_decimal_number_v2(SomCtx *c);

/* C1E369 write_actor_hud_hp   [class D, 145 bytes, 65 instructions]
 * Source: src/rom/write_actor_hud_hp.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void write_actor_hud_hp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM16_SET(0x0008, 0);
    BUS16_SET(c, 0x002116, (uint16_t)(((((a_hi << 8) | a) & 0xFF) | 0x5B00) - 0x20));
    uint16_t value = RAM16(ACTOR_HP + x);
    r->a = value;
    r->c = ((((a_hi << 8) | a) & 0xFF) | 0x5B00) >= 0x20;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = ((((((a_hi << 8) | a) & 0xFF) | 0x5B00) ^ 0x20) & (((((a_hi << 8) | a) & 0xFF) | 0x5B00) ^ (uint16_t)(((((a_hi << 8) | a) & 0xFF) | 0x5B00) - 0x20)) & 0x8000) != 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xE380, write_hud_decimal_number, sp_in, 2); GUARD_JSR(c, sp_call, 0xE380); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    BUS8_SET(c, (db_ret << 0x10) + 0x2118, 0x12);
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 8));
    BUS8_SET(c, (uint16_t)(dp_ret + 8), (uint8_t)(value2 - 1));
    BUS8_SET(c, (uint16_t)(dp_ret + 9), 0);
    uint16_t value3 = RAM16(ACTOR_MAX_HP + x);
    r->a = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    write_hud_decimal_number_v2(c); return;
}
SOM_REGISTER(0xC1E369, SOM_RTS, "gen", write_actor_hud_hp, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 145, 65)

/* C1E390 write_hud_decimal_number   [class A, 106 bytes, 50 instructions]
 * Source: src/rom/write_actor_hud_hp.s
 * Subroutine of write_actor_hud_hp, translated in place.
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void write_hud_decimal_number(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->y = a;
    r->z = a == 0;
    r->n = a & 0x8000;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE395, 0xC1E3FA); GUARD_JSR(c, sp_call, 0xE395); } /* divide_hud_number_by_ten */
    uint16_t a_all = r->a;
    RAM8(0x0001) = (uint8_t)a_all;
    RAM8(0x0000) = 0;
    uint16_t value = BUS16(c, 0x004214);
    r->y = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE39F, 0xC1E3FA); GUARD_JSR(c, sp_call, 0xE39F); } /* divide_hud_number_by_ten */
    uint16_t a_all2 = r->a;
    RAM8(0x0002) = (uint8_t)a_all2;
    uint8_t value2 = BUS8(c, 0x004214);
    if (value2 != 0) {
        BUS8_SET(c, 0x002118, (uint8_t)(value2 + 8));
        RAM8(0x0000)--;
    } else {
        if (!(RAM8(0x0008) & 0x80)) {
            BUS8_SET(c, 0x002118, 0x13);
        } else {
            RAM8(0x0009)++;
        }
    }
    uint8_t value4 = RAM8(0x0002);
    if (value4 != 0) {
        BUS8_SET(c, 0x002118, (uint8_t)(value4 + 8));
        RAM8(0x0000)--;
    } else {
        if (RAM8(0x0000) & 0x80) {
            BUS8_SET(c, 0x002118, (uint8_t)(value4 + 8));
            RAM8(0x0000)--;
        } else {
            if (!(RAM8(0x0008) & 0x80)) {
                BUS8_SET(c, 0x002118, 0x13);
            } else {
                RAM8(0x0009)++;
            }
        }
    }
    uint8_t value7 = RAM8(0x0001);
    BUS8_SET(c, 0x002118, (uint8_t)(value7 + 8));
    uint8_t value8 = RAM8(0x0008);
    uint8_t a1;
    bool zero1;
    bool negative1;
    if (!(value8 & 0x80)) {
        a1 = (uint8_t)(value7 + 8);
        zero1 = ((uint8_t)(value7 + 8) & value8) == 0;
        negative1 = value8 & 0x80;
    } else {
        RAM8(0x0009)--;
        if (!(RAM8(0x0009) & 0x80)) {
            BUS8_SET(c, 0x002118, 0x13);
            RAM8(0x0009)--;
            if (!(RAM8(0x0009) & 0x80)) {
                BUS8_SET(c, 0x002118, 0x13);
            }
        }
        a1 = 0x13;
        zero1 = RAM8(0x0009) == 0;
        negative1 = RAM8(0x0009) & 0x80;
    }
    SET_A8(r, a1);
    r->c = value7 + 8 > 0xFF;
    r->z = zero1;
    r->n = negative1;
    r->v = value8 & 0x40;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}

/* C1E390 write_hud_decimal_number_v2   [class A, 106 bytes, 50 instructions]
 * Source: src/rom/write_actor_hud_hp.s
 * Subroutine of write_actor_hud_hp, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void write_hud_decimal_number_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint8_t db = r->db;
    r->y = a;
    r->z = a == 0;
    r->n = a & 0x8000;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE395, 0xC1E3FA); GUARD_JSR(c, sp_call, 0xE395); } /* divide_hud_number_by_ten */
    uint16_t a_all = r->a;
    BUS8_SET(c, (uint16_t)(dp + 1), (uint8_t)a_all);
    BUS8_SET(c, dp, 0);
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x4214);
    r->y = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE39F, 0xC1E3FA); GUARD_JSR(c, sp_call, 0xE39F); } /* divide_hud_number_by_ten */
    uint16_t a_all2 = r->a;
    BUS8_SET(c, (uint16_t)(dp + 2), (uint8_t)a_all2);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x4214);
    if (value2 != 0) {
        BUS8_SET(c, (db << 0x10) + 0x2118, (uint8_t)(value2 + 8));
        uint8_t value3 = BUS8_RDP(c, dp);
        BUS8_SET(c, dp, (uint8_t)(value3 - 1));
    } else {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 8));
        if (!(value4 & 0x80)) {
            BUS8_SET(c, (db << 0x10) + 0x2118, 0x13);
        } else {
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 9));
            BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)(value5 + 1));
        }
    }
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 2));
    if (value6 != 0) {
        BUS8_SET(c, (db << 0x10) + 0x2118, (uint8_t)(value6 + 8));
        uint8_t value7 = BUS8_RDP(c, dp);
        BUS8_SET(c, dp, (uint8_t)(value7 - 1));
    } else {
        uint8_t value8 = BUS8_RDP(c, dp);
        if (value8 & 0x80) {
            BUS8_SET(c, (db << 0x10) + 0x2118, (uint8_t)(value6 + 8));
            uint8_t value9 = BUS8_RDP(c, dp);
            BUS8_SET(c, dp, (uint8_t)(value9 - 1));
        } else {
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 8));
            if (!(value10 & 0x80)) {
                BUS8_SET(c, (db << 0x10) + 0x2118, 0x13);
            } else {
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp + 9));
                BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)(value11 + 1));
            }
        }
    }
    uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 1));
    BUS8_SET(c, (db << 0x10) + 0x2118, (uint8_t)(value12 + 8));
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp + 8));
    uint8_t a1;
    bool zero2;
    bool negative2;
    if (!(value13 & 0x80)) {
        a1 = (uint8_t)(value12 + 8);
        zero2 = ((uint8_t)(value12 + 8) & value13) == 0;
        negative2 = value13 & 0x80;
    } else {
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp + 9));
        BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)(value14 - 1));
        bool zero1;
        bool negative1;
        if ((uint8_t)(value14 - 1) & 0x80) {
            zero1 = (uint8_t)(value14 - 1) == 0;
            negative1 = (uint8_t)(value14 - 1) & 0x80;
        } else {
            BUS8_SET(c, (db << 0x10) + 0x2118, 0x13);
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 9));
            BUS8_SET(c, (uint16_t)(dp + 9), (uint8_t)(value15 - 1));
            if (!((uint8_t)(value15 - 1) & 0x80)) {
                BUS8_SET(c, (db << 0x10) + 0x2118, 0x13);
            }
            zero1 = (uint8_t)(value15 - 1) == 0;
            negative1 = (uint8_t)(value15 - 1) & 0x80;
        }
        a1 = 0x13;
        zero2 = zero1;
        negative2 = negative1;
    }
    SET_A8(r, a1);
    r->c = value12 + 8 > 0xFF;
    r->z = zero2;
    r->n = negative2;
    r->v = value13 & 0x40;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
