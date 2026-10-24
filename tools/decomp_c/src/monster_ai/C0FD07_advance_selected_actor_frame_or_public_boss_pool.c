#include "som_c.h"

/* C0FD07 advance_selected_actor_frame_or_public_boss_pool   [class B, 24 bytes, 10 instructions]
 * Source: src/rom/advance_selected_actor_frame_or_public_boss_pool.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_selected_actor_frame_or_public_boss_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x005C);
    if (!(value & 0x80)) {
        r->z = (a & value) == 0;
        r->n = value & 0x80;
        r->v = value & 0x40;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFD19, 0xC0F4CB); GUARD_JSR(c, sp_call, 0xFD19); } /* advance_actor_animation_and_resume_native_frame_stream */
        uint16_t dp_ret = r->dp;
        bool x_ret = r->xf;
        uint16_t y_ret = r->y;
        if (x_ret) {
            uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x14));
            r->x = value2;
            r->y = (uint8_t)y_ret;
            r->z = value2 == 0;
            r->n = value2 & 0x80;
            r->xf = 1;
            TAIL_CALL(c, 0xC0F1CF, SOM_RTS); /* publish_actor_frame_tiles_points_and_collision_rectangle */
        } else {
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x14));
            r->x = value3;
            r->z = value3 == 0;
            r->n = value3 & 0x8000;
            r->xf = 0;
            TAIL_CALL(c, 0xC0F1CF, SOM_RTS); /* publish_actor_frame_tiles_points_and_collision_rectangle */
        }
    }
    uint8_t value4 = RAM8(0xE060 + x);
    if (value4 & 0x80) {
        r->a = (a_hi << 8) | value4;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->v = value & 0x40;
        TAIL_CALL(c, 0xC0F1CF, SOM_RTS); /* publish_actor_frame_tiles_points_and_collision_rectangle */
    }
    r->a = (a_hi << 8) | value4;
    r->z = value4 == 0;
    r->n = value4 & 0x80;
    r->v = value & 0x40;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFD15, 0xC20003); GUARD_JSL(c, sp_call, 0xFD15); } /* public_boss_pool_update_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0FD07, SOM_RTS, "gen", advance_selected_actor_frame_or_public_boss_pool, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 24, 10)
