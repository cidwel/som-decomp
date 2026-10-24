#include "som_c.h"

/* C27D5B choose_native58_farthest_close_or_nearest_projectile_attack   [class B, 90 bytes, 35 instructions]
 * Source: src/rom/choose_native58_farthest_close_or_nearest_projectile_attack.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void choose_native58_farthest_close_or_nearest_projectile_attack(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint8_t a_hi_7d8b = 0;
    uint8_t a_hi_7d8b2 = 0;
    r->a = 1;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7D60, 0xC2300B); GUARD_JSR(c, sp_call, 0x7D60); } /* draw_boss_frame_random_number */
    bool zero_ret = r->z;
    if (!zero_ret) {
        uint16_t value = RAM16(0x0287);
        r->x = value;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7D9B, 0xC23A41); GUARD_JSR(c, sp_call, 0x7D9B); } /* select_nearest_living_target_and_eight_way_direction */
        uint16_t x_ret2 = r->x;
        RAM16_SET(0x0295, 0);
        RAM16_SET(0x0297, 0);
        uint16_t value2 = RAM16(0x00A9 + x_ret2);
        r->a = 0x1E;
        r->y = value2;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7DA8, 0xC233BE); GUARD_JSR(c, sp_call, 0x7DA8); } /* create_boss_projectile_with_graphics_and_palette */
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t y_ret3 = r->y;
        if (x_ret3) {
            uint8_t value3 = RAM8(0x0287);
            r->a = 0x2E;
            r->x = value3;
            r->y = (uint8_t)y_ret3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x7DB1, 0xC0006C); GUARD_JSL(c, sp_call, 0x7DB1); } /* boss_attack_row_public_jump */
            bool x_ret5 = r->xf;
            if (x_ret5) {
                r->xf = 1;
                RETURN_RTS(c);
            } else {
                r->xf = 0;
                RETURN_RTS(c);
            }
        } else {
            uint16_t value6 = RAM16(0x0287);
            r->a = 0x2E;
            r->x = value6;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x7DB1, 0xC0006C); GUARD_JSL(c, sp_call, 0x7DB1); } /* boss_attack_row_public_jump */
            bool x_ret7 = r->xf;
            if (x_ret7) {
                r->xf = 1;
                RETURN_RTS(c);
            } else {
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
    }
    uint16_t value9 = RAM16(0x0287);
    r->x = value9;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7D67, 0xC2325A); GUARD_JSR(c, sp_call, 0x7D67); } /* select_farthest_active_living_party_actor_last_tie */
    uint16_t a_all6 = r->a;
    uint16_t value10 = RAM16(0x0287);
    RAM16_SET(0x00A9 + value10, a_all6);
    r->x = value10;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7D6F, 0xC208D9); GUARD_JSR(c, sp_call, 0x7D6F); } /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all7 = r->a;
    uint16_t x_ret10 = r->x;
    if (a_all7 >= 8) {
        a_hi_7d8b = a_all7 >> 8;
        goto shared_7D8B;
    }
    RAM16_SET(0x0295, 0);
    RAM16_SET(0x0297, 0);
    uint16_t value11 = RAM16(0x00A9 + x_ret10);
    r->a = 0x1C;
    r->y = value11;
    r->c = a_all7 >= 8;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7D81, 0xC233BE); GUARD_JSR(c, sp_call, 0x7D81); } /* create_boss_projectile_with_graphics_and_palette */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret11 = r->xf;
    uint16_t y_ret7 = r->y;
    if (x_ret11) {
        uint8_t value12 = RAM8(0x0287);
        r->a = 0x2E;
        r->x = value12;
        r->y = (uint8_t)y_ret7;
        r->z = value12 == 0;
        r->n = value12 & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7D8A, 0xC0006C); GUARD_JSL(c, sp_call, 0x7D8A); } /* boss_attack_row_public_jump */
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret13 = r->xf;
        uint16_t a_all9 = r->a;
        if (x_ret13) {
            a_hi_7d8b2 = a_all9 >> 8;
            goto shared_7D8B_1;
        } else {
            a_hi_7d8b = a_all9 >> 8;
            goto shared_7D8B;
        }
    } else {
        uint16_t value13 = RAM16(0x0287);
        r->a = 0x2E;
        r->x = value13;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7D8A, 0xC0006C); GUARD_JSL(c, sp_call, 0x7D8A); } /* boss_attack_row_public_jump */
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret15 = r->xf;
        uint16_t a_all10 = r->a;
        if (x_ret15) {
            a_hi_7d8b2 = a_all10 >> 8;
            goto shared_7D8B_1;
        } else {
            a_hi_7d8b = a_all10 >> 8;
            goto shared_7D8B;
        }
    }
    shared_7D8B:;
    uint16_t value14 = RAM16(0x0287);
    RAM16_SET(0x00B8 + value14, RAM16(0x00B8 + value14) ^ 1);
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
    shared_7D8B_1:;
    uint8_t value16 = RAM8(0x0287);
    RAM16_SET(0x00B8 + value16, RAM16(0x00B8 + value16) ^ 1);
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27D5B, SOM_RTS, "gen", choose_native58_farthest_close_or_nearest_projectile_attack, 0, 0, 1, 0, 0, 90, 35)
