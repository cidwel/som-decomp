#include "som_c.h"

/* C1E40E select_actor_target_and_attack_animation   [class B, 190 bytes, 86 instructions]
 * Source: src/rom/select_actor_target_and_attack_animation.s
 * Documented in docs/actor-action-target-selection.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void select_actor_target_and_attack_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    r->a = (a_hi << 8) | 0x7E;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xE417, 0xC1E4CC); /* select_actor_target_and_distance_class */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    BUS8_SET(c, 0x004202, (uint8_t)a_all);
    BUS8_SET(c, 0x004203, 0x90);
    RAM8(0x0000) = (uint8_t)(RAM8(ACTOR_CHARGE_STAGE + x) << 4);
    RAM8(0x0001) = 0;
    uint8_t value2 = RAM8(0xE000 + y_ret);
    if (value2 != 0) {
        if (!(value2 & 0x80)) {
            uint8_t value3 = RAM8(ACTOR_STATUS + y_ret);
            if ((value3 & 1) == 0) {
                if ((value3 & 2) == 0) {
                    if ((value3 & 0x10) != 0) {
                        RAM8(0x0000) |= 0x0C;
                    }
                } else {
                    RAM8(0x0000) |= 8;
                }
            } else {
                RAM8(0x0000) |= 4;
            }
            RAM8(0x0000) = (RAM8(ACTOR_GUARD_FLAGS + y_ret) & 2) | RAM8(0x0000);
        }
    }
    RAM8(0x0000) = (RAM8(0x00F4) & 1) | RAM8(0x0000);
    RAM16_SET(0xE05E + x, y_ret);
    uint16_t value11 = BUS16(c, 0x004216);
    uint16_t value12 = RAM16(0x0000);
    uint8_t a2;
    uint8_t a_hi2;
    bool carry2;
    bool overflow1;
    if (x < 0x0600) {
        BUS8_SET(c, 0x004202, RAM8(0xE068 + x));
        BUS8_SET(c, 0x004203, 0x28);
        uint8_t value14 = BUS8(c, 0xD10000 + (uint16_t)(value11 + value12));
        uint16_t value15 = BUS16(c, 0x004216);
        uint8_t value16 = BUS8(c, 0xD10480 + (uint16_t)(((((uint16_t)(value11 + value12) >> 8 << 8) | value14) & 0xFF) + value15));
        a2 = value16;
        a_hi2 = (uint16_t)(((((uint16_t)(value11 + value12) >> 8 << 8) | value14) & 0xFF) + value15) >> 8;
        carry2 = ((((uint16_t)(value11 + value12) >> 8 << 8) | value14) & 0xFF) + value15 > 0xFFFF;
        overflow1 = ((((((uint16_t)(value11 + value12) >> 8 << 8) | value14) & 0xFF) ^ (uint16_t)(((((uint16_t)(value11 + value12) >> 8 << 8) | value14) & 0xFF) + value15)) & (value15 ^ (uint16_t)(((((uint16_t)(value11 + value12) >> 8 << 8) | value14) & 0xFF) + value15)) & 0x8000) != 0;
    } else {
        BUS8_SET(c, 0x004202, RAM8(0xE180 + x));
        BUS8_SET(c, 0x004203, 0x20);
        uint8_t value18 = RAM8(0xE1E4 + x);
        uint8_t value19 = BUS8(c, 0xD10240 + (uint16_t)(value11 + value12));
        uint8_t a1;
        uint8_t a_hi1;
        bool carry1;
        if (!(value18 & 0x80)) {
            a1 = (((uint16_t)(value11 + value12) >> 8 << 8) | value19) & 0xFF;
            a_hi1 = 0;
            carry1 = value18 & 0x80;
        } else {
            a1 = (uint8_t)(((((uint16_t)(value11 + value12) >> 8 << 8) | value19) & 0xFF) + 0x10);
            a_hi1 = ((((uint16_t)(value11 + value12) >> 8 << 8) | value19) & 0xFF) + 0x10 >> 8;
            carry1 = ((((uint16_t)(value11 + value12) >> 8 << 8) | value19) & 0xFF) + 0x10 > 0xFFFF;
        }
        uint16_t value20 = BUS16(c, 0x004216);
        uint8_t value21 = BUS8(c, 0xD105C0 + (uint16_t)(((a_hi1 << 8) | a1) + value20 + carry1));
        a2 = value21;
        a_hi2 = (uint16_t)(((a_hi1 << 8) | a1) + value20 + carry1) >> 8;
        carry2 = ((a_hi1 << 8) | a1) + value20 + carry1 > 0xFFFF;
        overflow1 = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + value20 + carry1)) & (value20 ^ (uint16_t)(((a_hi1 << 8) | a1) + value20 + carry1)) & 0x8000) != 0;
    }
    r->a = (a_hi2 << 8) | a2;
    r->y = x;
    r->c = carry2;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E40E, SOM_RTL, "gen", select_actor_target_and_attack_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 190, 86)
