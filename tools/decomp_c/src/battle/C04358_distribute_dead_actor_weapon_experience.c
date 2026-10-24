#include "som_c.h"

/* C04358 distribute_dead_actor_weapon_experience   [class B, 84 bytes, 35 instructions]
 * Source: src/rom/distribute_dead_actor_weapon_experience.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void distribute_dead_actor_weapon_experience(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(ACTOR_WEAPON_LEVEL + y);
    RAM8(BATTLE_TEMP_A6) = (uint8_t)(9 - value);
    uint8_t value2 = RAM8(ACTOR_LEVEL + x);
    uint8_t value3 = RAM8(ACTOR_LEVEL + y);
    bool carry1;
    if (value2 >= value3) {
        carry1 = value2 >= value3;
    } else {
        uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
        RAM8(BATTLE_TEMP_A6) >>= 1;
        carry1 = battle_temp_a6 & 0x01;
    }
    uint8_t value4 = RAM8(0xE1F0 + x);
    if (!(value4 & 0x80)) {
        if (value4 != 0) {
            if (value4 == 2) {
                r->a = (a_hi << 8) | value4;
                r->c = value4 >= 2;
                r->z = value4 == 2;
                r->n = (uint8_t)(value4 - 2) & 0x80;
                r->v = ((value ^ 9) & ((uint8_t)(9 - value) ^ 9) & 0x80) != 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x439C, 0xC043B7); GUARD_JSR(c, sp_call, 0x439C); } /* advance_actor_weapon_experience_and_level */
                uint16_t dp_ret = r->dp;
                bool m_ret = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                if (m_ret) {
                    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xA6));
                    BUS8_SET(c, (uint16_t)(dp_ret + 0xA6), value5 >> 1);
                    r->y = 0;
                    r->c = value5 & 0x01;
                    r->z = 1;
                    r->n = 0;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x43A4, 0xC043B7); GUARD_JSR(c, sp_call, 0x43A4); } /* advance_actor_weapon_experience_and_level */
                    if (r->xf != 0) { c->fail = 3; return; }
                    r->y = 0x0200;
                    r->z = 0;
                    r->n = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x43AA, 0xC043B7); GUARD_JSR(c, sp_call, 0x43AA); } /* advance_actor_weapon_experience_and_level */
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xA6));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret + 0xA6), value6 >> 1);
                    r->y = 0;
                    r->c = value6 & 0x01;
                    r->z = 1;
                    r->n = 0;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x43A4, 0xC043B7); GUARD_JSR(c, sp_call, 0x43A4); } /* advance_actor_weapon_experience_and_level */
                    if (r->xf != 0) { c->fail = 3; return; }
                    r->y = 0x0200;
                    r->z = 0;
                    r->n = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x43AA, 0xC043B7); GUARD_JSR(c, sp_call, 0x43AA); } /* advance_actor_weapon_experience_and_level */
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
            r->a = (a_hi << 8) | value4;
            r->c = value4 >= 2;
            r->z = value4 == 2;
            r->n = (uint8_t)(value4 - 2) & 0x80;
            r->v = ((value ^ 9) & ((uint8_t)(9 - value) ^ 9) & 0x80) != 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x438A, 0xC043B7); GUARD_JSR(c, sp_call, 0x438A); } /* advance_actor_weapon_experience_and_level */
            uint16_t dp_ret6 = r->dp;
            bool m_ret6 = r->mf;
            if (r->xf != 0) { c->fail = 3; return; }
            if (m_ret6) {
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0xA6));
                BUS8_SET(c, (uint16_t)(dp_ret6 + 0xA6), value7 >> 1);
                r->y = 0;
                r->c = value7 & 0x01;
                r->z = 1;
                r->n = 0;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x4392, 0xC043B7); GUARD_JSR(c, sp_call, 0x4392); } /* advance_actor_weapon_experience_and_level */
                if (r->xf != 0) { c->fail = 3; return; }
                r->y = 0x0400;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x4398, 0xC043B7); GUARD_JSR(c, sp_call, 0x4398); } /* advance_actor_weapon_experience_and_level */
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0xA6));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret6 + 0xA6), value8 >> 1);
                r->y = 0;
                r->c = value8 & 0x01;
                r->z = 1;
                r->n = 0;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x4392, 0xC043B7); GUARD_JSR(c, sp_call, 0x4392); } /* advance_actor_weapon_experience_and_level */
                if (r->xf != 0) { c->fail = 3; return; }
                r->y = 0x0400;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x4398, 0xC043B7); GUARD_JSR(c, sp_call, 0x4398); } /* advance_actor_weapon_experience_and_level */
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        r->a = (a_hi << 8) | value4;
        r->c = carry1;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->v = ((value ^ 9) & ((uint8_t)(9 - value) ^ 9) & 0x80) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4374, 0xC043B7); GUARD_JSR(c, sp_call, 0x4374); } /* advance_actor_weapon_experience_and_level */
        uint16_t dp_ret11 = r->dp;
        bool m_ret11 = r->mf;
        if (r->xf != 0) { c->fail = 3; return; }
        if (m_ret11) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 0xA6));
            BUS8_SET(c, (uint16_t)(dp_ret11 + 0xA6), value9 >> 1);
            r->y = 0x0200;
            r->c = value9 & 0x01;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x437C, 0xC043B7); GUARD_JSR(c, sp_call, 0x437C); } /* advance_actor_weapon_experience_and_level */
            if (r->xf != 0) { c->fail = 3; return; }
            r->y = 0x0400;
            r->z = 0;
            r->n = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4382, 0xC043B7); GUARD_JSR(c, sp_call, 0x4382); } /* advance_actor_weapon_experience_and_level */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 0xA6));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret11 + 0xA6), value10 >> 1);
            r->y = 0x0200;
            r->c = value10 & 0x01;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x437C, 0xC043B7); GUARD_JSR(c, sp_call, 0x437C); } /* advance_actor_weapon_experience_and_level */
            if (r->xf != 0) { c->fail = 3; return; }
            r->y = 0x0400;
            r->z = 0;
            r->n = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4382, 0xC043B7); GUARD_JSR(c, sp_call, 0x4382); } /* advance_actor_weapon_experience_and_level */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    r->c = carry1;
    r->v = ((value ^ 9) & ((uint8_t)(9 - value) ^ 9) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04358, SOM_RTS, "gen", distribute_dead_actor_weapon_experience, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 84, 35)
