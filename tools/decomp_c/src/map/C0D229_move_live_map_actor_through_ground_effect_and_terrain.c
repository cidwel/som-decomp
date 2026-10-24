#include "som_c.h"
#include "som_hand_b.h"

/* C0D229 move_live_map_actor_through_ground_effect_and_terrain   [class B, 153 bytes, 72 instructions]
 * Source: src/rom/move_live_map_actor_through_ground_effect_and_terrain.s
 * Documented in docs/map-actor-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: Y.
 * Hand written: the exit register widths are those the last callee left (the original returns straight after the
 * call), so they are never forced here. */

/* LDX/LDY from a direct-page word or byte according to the live index width. */
static uint16_t load_index_dp(SomCtx *c, uint16_t dp_addr)
{
    uint8_t *ram = c->wram;
    uint16_t v = c->cpu.xf ? RAM8(dp_addr) : RAM16(dp_addr);
    c->cpu.z = v == 0;
    c->cpu.n = c->cpu.xf ? v >> 7 : v >> 15;
    return v;
}

static void store_index_dp(SomCtx *c, uint16_t dp_addr, uint16_t v)
{
    uint8_t *ram = c->wram;
    if (c->cpu.xf) RAM8(dp_addr) = (uint8_t)v;
    else RAM16_SET(dp_addr, v);
}

static void move_live_map_actor_through_ground_effect_and_terrain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }

    r->mf = 1;                                   /* SEP #$20 */
    store_index_dp(c, 0x10, r->x);               /* actor slot offset */

    uint8_t state = RAM8(0xE000 + r->x);
    hand_lda8(r, state);
    if (state == 0 || (state & 0x80)) RETURN_RTS(c);

    uint8_t delay = RAM8(0xE036 + r->x);
    hand_lda8(r, delay);
    if (delay != 0) {
        uint8_t left = (uint8_t)(RAM8(0xE037 + r->x) - 1);
        RAM8(0xE037 + r->x) = left;
        hand_nz8(r, left);
        if (!(left & 0x80)) RETURN_RTS(c);
        RAM8(0xE037 + r->x) = delay;             /* reload the countdown */
    }

    uint8_t fixed_height = RAM8(0xE060 + r->x);
    hand_lda8(r, fixed_height);
    if (!(fixed_height & 0x80)) {
        uint8_t climb = RAM8(0xE008 + r->x);
        hand_lda8(r, climb);
        if (climb != 0) { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD24F, 0xC0D2C2); GUARD_JSR_DB(c, sp_call, 0xD24F, db_call); } /* advance_and_clamp_actor_vertical_motion */
    }

    /* motion request for the ground-effect helper: velocity bytes, box origin, box size, current position */
    hand_lda8(r, RAM8(0xE006 + r->x)); RAM8(0x1E) = r->a;
    hand_lda8(r, RAM8(0xE007 + r->x)); RAM8(0x1F) = r->a;
    r->y = load_index_dp(c, 0xA8); store_index_dp(c, 0x16, r->y);
    r->y = load_index_dp(c, 0xAA); store_index_dp(c, 0x18, r->y);
    uint8_t size = RAM8(0xE089 + r->x);
    hand_lda8(r, size & 3);
    hand_lda8(r, (uint8_t)((size & 3) + 1));     /* INC */
    r->c = 0;                                    /* ASL, ASL, CLC */
    uint8_t box = hand_adc8(r, (uint8_t)(((size & 3) + 1) << 2), 6);
    hand_lda8(r, box); RAM8(0x1A) = box;
    uint8_t layer = RAM8(0xE00B + r->x);
    hand_lda8(r, layer); RAM8(0x1B) = layer;
    if (layer & 0x80) {
        r->y = load_index_dp(c, 0xAC); store_index_dp(c, 0x16, r->y);
        r->y = load_index_dp(c, 0xAE); store_index_dp(c, 0x18, r->y);
    }
    r->mf = 0;                                   /* REP #$20 */
    r->a = RAM16(0xE002 + r->x); RAM16_SET(0x12, r->a);
    r->a = RAM16(0xE004 + r->x); RAM16_SET(0x14, r->a);
    hand_nz16(r, r->a);
    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD28C, 0xC0D2E0); GUARD_JSR_DB(c, sp_call, 0xD28C, db_call); }                /* apply_actor_ground_contact_effect_to_live_motion */

    r->mf = 1;                                   /* SEP #$20 */
    uint8_t moved = RAM8(0x1F);
    hand_lda8(r, moved);
    moved |= RAM8(0x1E);
    hand_lda8(r, moved);
    if (moved == 0) RETURN_RTS(c);

    r->x = load_index_dp(c, 0x10);
    r->mf = 1;
    uint8_t flags = RAM8(0xED);                  /* BIT $ED */
    r->z = (r->a & flags & 0xFF) == 0;
    r->n = flags >> 7;
    r->v = (flags >> 6) & 1;
    bool publish_only = false;
    if (flags & 0x80) {
        uint8_t step = RAM8(0xE074 + r->x);
        hand_lda8(r, step);
        r->c = step >> 7;                        /* ASL */
        hand_lda8(r, (uint8_t)(step << 1));
        publish_only = !r->c;
    }
    if (!publish_only) {
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD2A6, 0xC0D74F); GUARD_JSR_DB(c, sp_call, 0xD2A6, db_call); }            /* resolve_actor_terrain_motion_and_publish_cell_layer */
        if (r->c) RETURN_RTS(c);
        r->mf = 1;                               /* SEP #$20, REP #$10 */
        r->xf = 0;
        r->x = RAM16(0x10);
        hand_lda8(r, RAM8(0x00) & 4);
        if (r->a & 4) goto publish;
        uint8_t kind = RAM8(0x01) & 7;
        hand_lda8(r, kind);
        if (kind == 0) goto publish;
        RAM8(0xE08E + r->x) = kind;
    }
publish:
    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD2C0, 0xC0D890); GUARD_JSR_DB(c, sp_call, 0xD2C0, db_call); }                /* publish_actor_wrapped_position_layer_and_camera_step */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D229, SOM_RTS, "hand", move_live_map_actor_through_ground_effect_and_terrain, 0, L_Y, 1, 1, 0, 153, 72)
