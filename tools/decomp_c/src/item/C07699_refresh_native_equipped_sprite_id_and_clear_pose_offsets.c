#include "som_c.h"

/* C07699 refresh_native_equipped_sprite_id_and_clear_pose_offsets   [class B, 46 bytes, 24 instructions]
 * Source: src/rom/refresh_native_equipped_sprite_id_and_clear_pose_offsets.s
 * Documented in docs/event-menu-equipment-refresh.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void refresh_native_equipped_sprite_id_and_clear_pose_offsets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x769B, 0xC07A54); /* read_native_actor_equipment_field_and_restore_index_status */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = BUS8(c, 0xD01000 + (uint16_t)(a_all << 2));
    RAM8(0x0001 + x_ret) = value;
    RAM8(0x0015 + (x_ret & 0xFF80)) = 0;
    RAM8(0x001D + (x_ret & 0xFF80)) = 0;
    r->c = (uint16_t)(a_all << 3) + (uint16_t)(a_all << 2) > 0xFFFF;
    r->v = (((uint16_t)(a_all << 3) ^ (uint16_t)((uint16_t)(a_all << 3) + (uint16_t)(a_all << 2))) & ((uint16_t)(a_all << 2) ^ (uint16_t)((uint16_t)(a_all << 3) + (uint16_t)(a_all << 2))) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07699, SOM_RTS, "gen", refresh_native_equipped_sprite_id_and_clear_pose_offsets, 0, L_Y | L_C | L_V, 2, 1, 0, 46, 24)
