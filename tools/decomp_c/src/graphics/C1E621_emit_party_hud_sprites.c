#include "som_c.h"

/* C1E621 emit_party_hud_sprites   [class B, 71 bytes, 30 instructions]
 * Source: src/rom/emit_party_hud_sprites.s
 * Documented in docs/graphics.md
 * Entry: M=any X=any DB=$00 D=$0000.  Callers read: BXC.
 */
static void emit_party_hud_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (RAM8(EVENT_FLAG_BYTES) != 0) {
        if (RAM8(0x0052) == 0) {
            uint8_t value2 = RAM8(0x00E8);
            if (value2 == 3) {
                r->c = value2 >= 3;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value3 = RAM8(0x0A55);
            uint8_t a_hi1;
            bool carry1;
            if (value3 == 0) {
                a_hi1 = a >> 8;
                carry1 = value2 >= 3;
            } else {
                r->a = (value3 << 8) | RAM8(0xE093);
                r->y = 0x01E8;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xE646, 0xC1E668); GUARD_JSR(c, sp_call, 0xE646); } /* emit_one_party_hud_sprite */
                uint16_t a_all = r->a;
                bool carry_ret = r->c;
                a_hi1 = a_all >> 8;
                carry1 = carry_ret;
            }
            uint8_t value5 = RAM8(0x0A65);
            uint8_t a_hi2;
            bool carry2;
            if (value5 == 0) {
                a_hi2 = a_hi1;
                carry2 = carry1;
            } else {
                r->a = (value5 << 8) | RAM8(0xE293);
                r->y = 0x01EA;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xE656, 0xC1E668); GUARD_JSR(c, sp_call, 0xE656); } /* emit_one_party_hud_sprite */
                uint16_t a_all2 = r->a;
                bool carry_ret2 = r->c;
                a_hi2 = a_all2 >> 8;
                carry2 = carry_ret2;
            }
            uint8_t value7 = RAM8(0x0A75);
            uint8_t a_hi3;
            bool carry3;
            if (value7 == 0) {
                a_hi3 = a_hi2;
                carry3 = carry2;
            } else {
                r->a = (value7 << 8) | RAM8(0xE493);
                r->y = 0x01EC;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xE666, 0xC1E668); GUARD_JSR(c, sp_call, 0xE666); } /* emit_one_party_hud_sprite */
                uint16_t a_all3 = r->a;
                bool carry_ret3 = r->c;
                a_hi3 = a_all3 >> 8;
                carry3 = carry_ret3;
            }
            r->a = (a_hi3 << 8) | (uint8_t)a;
            r->c = carry3;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E621, SOM_RTS, "gen", emit_party_hud_sprites, 0, L_B | L_X | L_C, 1, -1, -1, 71, 30)
