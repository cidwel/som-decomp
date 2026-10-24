#include "som_c.h"

/* C262C2 choose_descriptor_three_state_and_target   [class B, 77 bytes, 31 instructions]
 * Source: src/rom/choose_descriptor_three_state_and_target.s
 * Documented in docs/boss-descriptor-three.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_three_state_and_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM16(0x007E + x) == 0) {
        r->a = 4;
        JSR(c, 0x62D7, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret = r->z;
        if (!zero_ret) {
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x62ED, 0xC23224); /* select_nearest_active_living_party_actor */
            uint16_t a_all2 = r->a;
            RAM16_SET(0x00A9 + RAM16(0x0287), a_all2);
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x62F5, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            RAM16_SET(0x00AB + x_ret3, a_all3);
            if ((a_all3 & 1) == 0) {
                if ((a_all3 & 2) != 0) {
                    r->a = 0xDFC0;
                    r->z = 0;
                    r->n = 1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = 0xDFBE;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xDFBC;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x62DF, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all4 = r->a;
        uint16_t value4 = RAM16(0x0287);
        RAM16_SET(0x00A9 + value4, a_all4);
        r->a = 0xDFC2;
        r->x = value4;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x007E + x, 0);
    r->a = 1;
    JSR(c, 0x62CF, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret5 = r->z;
    if (zero_ret5) {
        r->a = 2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x62DF, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all6 = r->a;
        uint16_t value5 = RAM16(0x0287);
        RAM16_SET(0x00A9 + value5, a_all6);
        r->a = 0xDFC2;
        r->x = value5;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 4;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x62D7, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret7 = r->z;
    if (!zero_ret7) {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x62ED, 0xC23224); /* select_nearest_active_living_party_actor */
        uint16_t a_all8 = r->a;
        RAM16_SET(0x00A9 + RAM16(0x0287), a_all8);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x62F5, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
        uint16_t a_all9 = r->a;
        uint16_t x_ret9 = r->x;
        RAM16_SET(0x00AB + x_ret9, a_all9);
        if ((a_all9 & 1) == 0) {
            if ((a_all9 & 2) != 0) {
                r->a = 0xDFC0;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = 0xDFBE;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xDFBC;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x62DF, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all10 = r->a;
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x00A9 + value8, a_all10);
    r->a = 0xDFC2;
    r->x = value8;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC262C2, SOM_RTS, "gen", choose_descriptor_three_state_and_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 77, 31)
