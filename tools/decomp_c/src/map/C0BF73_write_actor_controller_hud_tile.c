#include "som_c.h"

/* C0BF73 write_actor_controller_hud_tile   [class D, 47 bytes, 22 instructions]
 * Source: src/rom/write_actor_controller_hud_tile.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void write_actor_controller_hud_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    BUS16_SET(c, 0x002116, (uint16_t)(((a_hi << 8) | a) - 0x21));
    uint8_t value = RAM8(0xE02C + x);
    uint8_t a6;
    bool carry4;
    if (value != 0) {
        uint8_t a2;
        bool carry1;
        if (value & 0x01) {
            a2 = 0x21;
            carry1 = value & 0x01;
        } else {
            uint8_t a1;
            if (value >> 1 & 0x01) {
                a1 = 0x22;
            } else {
                a1 = 0x23;
            }
            a2 = a1;
            carry1 = value >> 1 & 0x01;
        }
        a6 = a2;
        carry4 = carry1;
    } else {
        uint8_t value2 = RAM8(0xE08C + x);
        uint8_t a5;
        bool carry3;
        if (value2 == 0) {
            a5 = 0x16;
            carry3 = ((a_hi << 8) | a) >= 0x21;
        } else {
            uint8_t a4;
            bool carry2;
            if (value2 & 0x01) {
                a4 = 0x21;
                carry2 = value2 & 0x01;
            } else {
                uint8_t a3;
                if (value2 >> 1 & 0x01) {
                    a3 = 0x22;
                } else {
                    a3 = 0x23;
                }
                a4 = a3;
                carry2 = value2 >> 1 & 0x01;
            }
            a5 = a4;
            carry3 = carry2;
        }
        a6 = a5;
        carry4 = carry3;
    }
    BUS8_SET(c, 0x002118, a6);
    r->a = (r->a & 0x00FF) | (((uint16_t)(((a_hi << 8) | a) - 0x21) >> 8) << 8);
    r->c = carry4;
    r->v = ((((a_hi << 8) | a) ^ 0x21) & (((a_hi << 8) | a) ^ (uint16_t)(((a_hi << 8) | a) - 0x21)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BF73, SOM_RTS, "gen", write_actor_controller_hud_tile, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 47, 22)
