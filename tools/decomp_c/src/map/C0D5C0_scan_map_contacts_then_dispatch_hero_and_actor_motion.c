#include "som_c.h"

/* C0D5C0 scan_map_contacts_then_dispatch_hero_and_actor_motion   [class B, 45 bytes, 21 instructions]
 * Source: src/rom/scan_map_contacts_then_dispatch_hero_and_actor_motion.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void scan_map_contacts_then_dispatch_hero_and_actor_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00F1);
    if (!(value & 0x40)) {
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0x7E;
        r->a = (a_hi << 8) | 0x7E;
        r->z = 0;
        r->n = 0;
        r->v = value & 0x40;
        r->db = 0x7E;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD5CF, 0x01CD4E); GUARD_JSL(c, sp_call, 0xD5CF); } /* scan_three_heroes_against_map_contacts_and_publish_first_event */
        r->sp += 1;
        r->x = 0;
        r->z = 1;
        r->n = 0;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD5D7, 0xC0D5ED); GUARD_JSR(c, sp_call, 0xD5D7); } /* move_live_hero_through_ground_terrain_and_camera */
        r->sp += 1;
        r->x = 0x0200;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD5DF, 0xC0D5ED); GUARD_JSR(c, sp_call, 0xD5DF); } /* move_live_hero_through_ground_terrain_and_camera */
        r->sp += 1;
        r->x = 0x0400;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD5E7, 0xC0D5ED); GUARD_JSR(c, sp_call, 0xD5E7); } /* move_live_hero_through_ground_terrain_and_camera */
        r->sp += 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD5EA, 0xC0D1FE); GUARD_JSR(c, sp_call, 0xD5EA); } /* dispatch_live_map_actor_motion_pool */
        r->sp += 1;
        uint8_t value2 = RAM8(0x0000 + sp0);
        r->mf = 1;
        r->xf = 0;
        r->db = value2;
        RETURN_RTS(c);
    }
    r->v = value & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D5C0, SOM_RTS, "gen", scan_map_contacts_then_dispatch_hero_and_actor_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 45, 21)
