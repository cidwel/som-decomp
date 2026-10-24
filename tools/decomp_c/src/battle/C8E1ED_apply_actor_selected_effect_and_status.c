#include "som_c.h"

/* C8E1ED apply_actor_selected_effect_and_status   [class C, 108 bytes, 50 instructions]
 * Source: src/rom/apply_actor_selected_effect_and_status.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void apply_actor_selected_effect_and_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0x7E;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 6) = y >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)y;
    r->x = y;
    r->y = x;
    r->z = x == 0;
    r->n = x & 0x8000;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE1F7, 0xC0395E); GUARD_JSL(c, sp_call, 0xE1F7); } /* prepare_cast_actor_context_long */
    r->sp += 4;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    BUS8_SET(c, (uint16_t)(dp_ret + 0xA4), 3);
    BUS16_SET(c, (uint16_t)(dp_ret + 0xB4), 0);
    uint8_t a_hi1 = a_all >> 8;
    for (;;) {
        uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret + 0xB4));
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FB + value);
        if ((value2 & 4) == 0) {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xB5));
            BUS8_SET(c, (uint16_t)(dp_ret + 0xB5), (uint8_t)(value3 + 1));
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xB5));
            BUS8_SET(c, (uint16_t)(dp_ret + 0xB5), (uint8_t)(value4 + 1));
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xA4));
            BUS8_SET(c, (uint16_t)(dp_ret + 0xA4), (uint8_t)(value5 - 1));
            if ((uint8_t)(value5 - 1) != 0) {
                continue;
            }
        } else {
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xB5));
            BUS8_SET(c, (uint16_t)(dp_ret + 0x81), value6 >> 1);
            BUS16_SET(c, (uint16_t)(dp_ret + 0x85), value);
        }
        break;
    }
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x85));
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x82));
    BUS8_SET(c, (db_ret << 0x10) + 0xE1EC + value7, value8);
    uint8_t value9 = BUS8_RDP(c, (db_ret << 0x10) + 0xE190 + value7);
    BUS8_SET(c, (db_ret << 0x10) + 0xE190 + value7, value9 & 0xFC);
    BUS8_SET(c, (db_ret << 0x10) + 0xE1F1 + value7, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0xE1F2 + value7, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0xE059 + value7, 0);
    uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FB + value7);
    BUS8_SET(c, (db_ret << 0x10) + 0xE1FB + value7, value10 & 0xFB);
    uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0xE181 + value7);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x96), (uint16_t)(value11 << 1) & 0xFF);
    uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1C8 + y_ret);
    r->a = (uint8_t)(value12 << 1);
    r->x = (uint8_t)(value12 << 1);
    r->y = y_ret;
    r->c = value12 & 0x80;
    r->z = (uint8_t)(value12 << 1) == 0;
    r->n = (uint8_t)(value12 << 1) & 0x8000;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp;
    switch ((uint8_t)(value12 << 1)) {
    case 0x0000: JSR(c, 0xE24F, 0xC8E26B); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_no_change */
    case 0x0002: JSR(c, 0xE24F, 0xC8E26C); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_random_low_status */
    case 0x0004: JSR(c, 0xE24F, 0xC8E29C); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_level_plus_random_damage */
    case 0x0006: JSR(c, 0xE24F, 0xC8E2B5); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_high_status_bit20 */
    case 0x0008: JSR(c, 0xE24F, 0xC8E29C); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_level_plus_random_damage */
    case 0x000A: JSR(c, 0xE24F, 0xC8E2C0); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_low_status_bit40 */
    case 0x000C: JSR(c, 0xE24F, 0xC8E2CB); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_hp_or_damage_and_message */
    case 0x000E: JSR(c, 0xE24F, 0xC8E26B); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_no_change */
    case 0x0010: JSR(c, 0xE24F, 0xC8E2F6); GUARD_JSR(c, sp_call, 0xE24F); break; /* actor_selected_effect_request_event */
    default: JSR(c, 0xE24F, 0xC80000 | BUS16(c, 0xC80000 + (uint16_t)(0xE259 + ((uint8_t)(value12 << 1))))); GUARD_JSR(c, sp_call, 0xE24F);
    }
    }
    r->sp += 4;
    uint16_t dp_ret2 = r->dp;
    bool x_ret2 = r->xf;
    uint16_t y_ret2 = r->y;
    if (x_ret2) {
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x85));
        r->x = value13;
        r->y = (uint8_t)y_ret2;
        r->z = value13 == 0;
        r->n = value13 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE255, 0xC8E301); GUARD_JSL(c, sp_call, 0xE255); } /* apply_actor_status_and_timers */
        r->sp += 4;
        TAIL_CALL_FRAME(c, 0xC8E128, SOM_RTL, 4); /* restore_selected_effect_native_context_long */
    } else {
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x85));
        r->x = value14;
        r->z = value14 == 0;
        r->n = value14 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE255, 0xC8E301); GUARD_JSL(c, sp_call, 0xE255); } /* apply_actor_status_and_timers */
        r->sp += 4;
        TAIL_CALL_FRAME(c, 0xC8E128, SOM_RTL, 4); /* restore_selected_effect_native_context_long */
    }
}
SOM_REGISTER(0xC8E1ED, SOM_RTL, "gen", apply_actor_selected_effect_and_status, 0, 0, 8, 1, 0, 108, 50)
