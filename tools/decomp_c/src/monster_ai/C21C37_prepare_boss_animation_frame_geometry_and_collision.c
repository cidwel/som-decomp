#include "som_c.h"

/* C21C37 prepare_boss_animation_frame_geometry_and_collision   [class B, 109 bytes, 50 instructions]
 * Source: src/rom/prepare_boss_animation_frame_geometry_and_collision.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void prepare_boss_animation_frame_geometry_and_collision(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM16_SET(0x0279, RAM16(0x00A0 + x));
    RAM16_SET(0x027B, RAM16(0x00A2 + x));
    uint16_t value3 = BUS16(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279));
    if (value3 & 0x8000) {
        RAM16_SET(0x0293, RAM16(0x0088 + x));
        uint16_t value5 = BUS16(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279));
        RAM16_SET(0x0266, value5 & 0xFF);
        uint16_t value6 = BUS16(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 2);
        RAM16_SET(0x0FB4, value6);
        uint16_t value7 = BUS16(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 4);
        RAM16_SET(0x0FB6, value7);
        uint16_t value8 = RAM16(0x0279);
        RAM16_SET(0x0279, (uint16_t)(value8 + 6));
        r->a = (uint16_t)(value8 + 6);
        r->xf = 1;
        JSR(c, 0x1C95, 0xC21CA4); /* prepare_boss_animation_background_blocks */
        uint8_t y_ret = r->y;
        uint16_t value9 = RAM16(0x0287);
        uint16_t value10 = RAM16(0x0279);
        RAM16_SET(0x0279, (uint16_t)(y_ret + value10));
        r->x = value9;
        r->v = ((y_ret ^ (uint16_t)(y_ret + value10)) & (value10 ^ (uint16_t)(y_ret + value10)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x1CA2, 0xC21E06); /* read_and_mirror_boss_animation_collision_shapes */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0293, RAM16(0x0088 + x));
    RAM16_SET(0x027C, RAM16(0x0289));
    uint16_t value13 = BUS16(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279));
    BUS16_SET(c, RAM16(0x027C) + 0x7E0000, value13 & 0xFF);
    uint16_t y1;
    bool overflow1;
    if ((value13 & 0xFF) == 0) {
        y1 = y;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x0285, value13 & 0xFF);
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        RAM16_SET(0x027C, (uint16_t)(RAM16(0x027C) + 1));
        RAM16_SET(0x0266, 0);
        uint16_t value14 = RAM16(0x0098 + x);
        RAM16_SET(0x028D, value14);
        r->a = value14;
        JSR(c, 0x1C68, 0xC21E80); /* prepare_boss_animation_sprite_piece_records */
        uint16_t y_ret3 = r->y;
        bool overflow_ret2 = r->v;
        y1 = y_ret3;
        overflow1 = overflow_ret2;
    }
    r->x = RAM16(0x0287);
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x1C6D, 0xC21E06); /* read_and_mirror_boss_animation_collision_shapes */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21C37, SOM_RTS, "gen", prepare_boss_animation_frame_geometry_and_collision, 0, L_Y | L_V, 1, 0, 0, 109, 50)
