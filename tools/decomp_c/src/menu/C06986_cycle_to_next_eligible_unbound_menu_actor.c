#include "som_c.h"

/* C06986 cycle_to_next_eligible_unbound_menu_actor   [class B, 106 bytes, 53 instructions]
 * Source: src/rom/cycle_to_next_eligible_unbound_menu_actor.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void cycle_to_next_eligible_unbound_menu_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x1820) = 0;
    uint8_t value = RAM8(0x1877);
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = (uint8_t)x;
    uint16_t y1 = (uint8_t)(value - 1);
    bool carry1 = carry;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t y2;
            if ((uint8_t)((uint8_t)y1 + 1) < 3) {
                y2 = (uint8_t)((uint8_t)y1 + 1);
            } else {
                y2 = 0;
            }
            uint8_t value2 = RAM8(0x1820);
            RAM8(0x1820)++;
            uint8_t a_hi2;
            uint8_t x2;
            bool carry4;
            bool overflow2;
            if (value2 == 3) {
                a_hi2 = a_hi1;
                x2 = 0;
                carry4 = value2 >= 3;
                overflow2 = overflow1;
            } else {
                uint8_t ring_owner = RAM8(RING_OWNER);
                if (y2 == ring_owner) {
                    x1 = 0;
                    y1 = y2;
                    carry1 = y2 >= ring_owner;
                    continue;
                }
                uint16_t value3 = RAM16(0x0000 + (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000));
                if ((value3 & 0xFF) != 1) {
                    a_hi1 = 0;
                    x1 = (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000);
                    y1 = y2;
                    carry1 = (value3 & 0xFF) >= 1;
                    overflow1 = (((uint16_t)(((y2 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    first_pass = false;
                    continue;
                }
                uint16_t value4 = RAM16(0x0190 + (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000));
                if ((value4 & 0x8000) != 0) {
                    a_hi1 = (value4 & 0x8000) >> 8;
                    x1 = (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000);
                    y1 = y2;
                    carry1 = (value3 & 0xFF) >= 1;
                    overflow1 = (((uint16_t)(((y2 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    first_pass = false;
                    continue;
                }
                uint8_t a2;
                bool carry3;
                if (y2 == 0) {
                    a2 = 1;
                    carry3 = y2 >= 0;
                } else {
                    uint8_t a1;
                    bool carry2;
                    if (y2 == 1) {
                        a1 = 2;
                        carry2 = y2 >= 1;
                    } else {
                        a1 = 4;
                        carry2 = 0;
                    }
                    a2 = a1;
                    carry3 = carry2;
                }
                RAM8(0x0000 + sp0) = a2;
                r->a = ((value4 & 0x8000) >> 8 << 8) | a2;
                r->x = (uint8_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000);
                r->y = y2;
                r->c = carry3;
                r->v = (((uint16_t)(((y2 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 1;
                r->db = 0;
                r->dp = 0;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x69D9, 0xC06B03); GUARD_JSR(c, sp_call, 0x69D9); } /* read_union_of_party_controller_bindings */
                r->sp += 1;
                uint16_t a_all = r->a;
                uint8_t value5 = RAM8(0x0000 + sp0);
                if ((uint8_t)(a_all >> 8 << 8 | ((uint8_t)a_all & value5)) != 0) {
                    a_hi1 = a_all >> 8;
                    x1 = (uint8_t)(a_all >> 8 << 8 | ((uint8_t)a_all & value5));
                    y1 = y2;
                    carry1 = carry3;
                    overflow1 = (((uint16_t)(((y2 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    continue;
                }
                RAM8(RING_OWNER) = y2;
                a_hi2 = a_all >> 8;
                x2 = 1;
                carry4 = carry3;
                overflow2 = (((uint16_t)(((y2 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y2 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            }
            a_hi1 = a_hi2;
            x1 = x2;
            y1 = y2;
            carry1 = carry4;
            overflow1 = overflow2;
            break;
        } else {
            uint8_t y3;
            if ((uint8_t)((uint8_t)y1 + 1) < 3) {
                y3 = (uint8_t)((uint8_t)y1 + 1);
            } else {
                y3 = 0;
            }
            uint8_t value6 = RAM8(0x1820);
            RAM8(0x1820)++;
            uint8_t a_hi3;
            uint8_t x3;
            bool carry7;
            bool overflow3;
            if (value6 == 3) {
                a_hi3 = a_hi1;
                x3 = 0;
                carry7 = value6 >= 3;
                overflow3 = overflow1;
            } else {
                uint8_t ring_owner2 = RAM8(RING_OWNER);
                if (y3 == ring_owner2) {
                    x1 = 0;
                    y1 = y3;
                    carry1 = y3 >= ring_owner2;
                    first_pass = true;
                    continue;
                }
                uint16_t value7 = RAM16(0x0000 + (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000));
                if ((value7 & 0xFF) != 1) {
                    a_hi1 = 0;
                    x1 = (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000);
                    y1 = y3;
                    carry1 = (value7 & 0xFF) >= 1;
                    overflow1 = (((uint16_t)(((y3 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    continue;
                }
                uint16_t value8 = RAM16(0x0190 + (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000));
                if ((value8 & 0x8000) != 0) {
                    a_hi1 = (value8 & 0x8000) >> 8;
                    x1 = (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000);
                    y1 = y3;
                    carry1 = (value7 & 0xFF) >= 1;
                    overflow1 = (((uint16_t)(((y3 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    continue;
                }
                uint8_t a4;
                bool carry6;
                if (y3 == 0) {
                    a4 = 1;
                    carry6 = y3 >= 0;
                } else {
                    uint8_t a3;
                    bool carry5;
                    if (y3 == 1) {
                        a3 = 2;
                        carry5 = y3 >= 1;
                    } else {
                        a3 = 4;
                        carry5 = 0;
                    }
                    a4 = a3;
                    carry6 = carry5;
                }
                RAM8(0x0000 + sp0) = a4;
                r->a = ((value8 & 0x8000) >> 8 << 8) | a4;
                r->x = (uint8_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000);
                r->y = y3;
                r->c = carry6;
                r->v = (((uint16_t)(((y3 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 1;
                r->db = 0;
                r->dp = 0;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x69D9, 0xC06B03); GUARD_JSR(c, sp_call, 0x69D9); } /* read_union_of_party_controller_bindings */
                r->sp += 1;
                uint16_t a_all2 = r->a;
                uint8_t value9 = RAM8(0x0000 + sp0);
                if ((uint8_t)(a_all2 >> 8 << 8 | ((uint8_t)a_all2 & value9)) != 0) {
                    a_hi1 = a_all2 >> 8;
                    x1 = (uint8_t)(a_all2 >> 8 << 8 | ((uint8_t)a_all2 & value9));
                    y1 = y3;
                    carry1 = carry6;
                    overflow1 = (((uint16_t)(((y3 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                    first_pass = true;
                    continue;
                }
                RAM8(RING_OWNER) = y3;
                a_hi3 = a_all2 >> 8;
                x3 = 1;
                carry7 = carry6;
                overflow3 = (((uint16_t)(((y3 << 8) | 0) << 1) ^ (uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)(((y3 << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            }
            a_hi1 = a_hi3;
            x1 = x3;
            y1 = y3;
            carry1 = carry7;
            overflow1 = overflow3;
            break;
        }
    }
    r->a = (uint8_t)x1;
    r->x = (uint8_t)x1;
    r->y = (uint8_t)y1;
    r->c = carry1;
    r->z = (uint8_t)x1 == 0;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06986, SOM_RTS, "gen", cycle_to_next_eligible_unbound_menu_actor, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 106, 53)
