#include "som_c.h"

/* C0D65D resolve_hero_party_window_terrain_and_publish_motion   [class B, 107 bytes, 48 instructions]
 * Source: src/rom/resolve_hero_party_window_terrain_and_publish_motion.s
 * Documented in docs/map-hero-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void resolve_hero_party_window_terrain_and_publish_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xD65F, 0xC0D6C8); GUARD_JSR(c, sp_call, 0xD65F); } /* limit_hero_signed_motion_to_live_party_window */
    { const uint16_t sp_call = r->sp; JSR(c, 0xD662, 0xC0D74F); GUARD_JSR(c, sp_call, 0xD662); } /* resolve_actor_terrain_motion_and_publish_cell_layer */
    uint16_t a_all2 = r->a;
    bool carry_ret2 = r->c;
    if (carry_ret2) {
        uint16_t value = RAM16(0x0010);
        uint8_t value2 = RAM8(0xE02C + value);
        uint8_t value3 = RAM8(0xE00A + value);
        uint8_t a1;
        if ((value2 | value3) != 0) {
            a1 = value2 | value3;
        } else {
            uint8_t value4 = RAM8(0xE02D + value);
            RAM8(0xE02D + value) = (uint8_t)(value4 + 1);
            a1 = (uint8_t)(value4 + 1);
        }
        SET_A8(r, a1);
        r->x = value;
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x0010);
    uint8_t value6 = RAM8(0x00FF);
    uint8_t value7 = RAM8(0x00D0);
    bool carry3;
    if ((value6 | value7) != 0) {
        carry3 = carry_ret2;
    } else {
        uint8_t value8 = RAM8(0xE02C + value5);
        bool carry2;
        if (value8 == 0) {
            carry2 = carry_ret2;
        } else {
            uint8_t value9 = RAM8(0xE00E + value5);
            bool carry1;
            if (value9 & 0x80) {
                carry1 = carry_ret2;
            } else {
                uint8_t value10 = RAM8(0x0006);
                uint8_t value11 = RAM8(0xE04C + value5);
                if (value10 != value11) {
                    RAM8(0xE04B + value5) = value10;
                    RAM8(0xE04C + value5) = value10;
                }
                if ((RAM8(0x0001) & 0x10) != 0) {
                    RAM16_SET(0x00D4, value5);
                    RAM8(0xE04A + value5) = 0x80;
                }
                carry1 = value10 >= value11;
            }
            carry2 = carry1;
        }
        carry3 = carry2;
    }
    RAM8(0xE02D + value5) = 0;
    uint8_t value13 = RAM8(0x0000);
    uint8_t a2;
    if ((value13 & 4) != 0) {
        a2 = value13 & 4;
    } else {
        uint8_t value14 = RAM8(0x0001);
        if ((value14 & 7) != 0) {
            RAM8(0xE08E + value5) = value14 & 7;
        }
        a2 = value14 & 7;
    }
    r->a = (a_all2 >> 8 << 8) | a2;
    r->x = value5;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD6AB, 0xC0D890); GUARD_JSR(c, sp_call, 0xD6AB); } /* publish_actor_wrapped_position_layer_and_camera_step */
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD6AE, 0xC0DA6E); GUARD_JSR(c, sp_call, 0xD6AE); } /* dispatch_moving_hero_camera_by_layer */
    r->c = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D65D, SOM_RTS, "gen", resolve_hero_party_window_terrain_and_publish_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 107, 48)
