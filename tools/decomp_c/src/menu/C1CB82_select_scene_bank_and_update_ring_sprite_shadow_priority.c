#include "som_c.h"

/* C1CB82 select_scene_bank_and_update_ring_sprite_shadow_priority   [class B, 73 bytes, 35 instructions]
 * Source: src/rom/select_scene_bank_and_update_ring_sprite_shadow_priority.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void select_scene_bank_and_update_ring_sprite_shadow_priority(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x7E;
    r->a = (a >> 8 << 8) | 0x7E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->db = 0x7E;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCB8B, 0x02AB42); GUARD_JSL(c, sp_call, 0xCB8B); } /* snapshot_event_sprite_palette_to_shadow */
    uint16_t value = RAM16(0x0098);
    RAM16_SET(0x0000, (uint16_t)(value << 4));
    uint8_t a_hi1 = (uint16_t)(value << 4) >> 8;
    uint16_t y1 = 0x0100;
    bool carry1 = (uint16_t)(value << 3) & 0x8000;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value2 = RAM16(0x0802 + y1);
        uint16_t value3 = RAM16(0x0000);
        uint8_t a_hi4;
        if (!(value3 & 0x8000)) {
            uint8_t a_hi2;
            if ((value2 & 0x0E00) < 0x0800) {
                a_hi2 = (value2 & 0x0E00) >> 8;
            } else {
                RAM16_SET(0x0802 + y1, value2 & 0xF1FF);
                a_hi2 = (value2 & 0xF1FF) >> 8;
            }
            a_hi4 = a_hi2;
        } else {
            uint8_t a_hi3;
            if ((value2 & 0x0E00) >= 0x0800) {
                a_hi3 = (value2 & 0x0E00) >> 8;
            } else {
                RAM16_SET(0x0802 + y1, (value2 & 0xF1FF) | 0x0800);
                a_hi3 = ((value2 & 0xF1FF) | 0x0800) >> 8;
            }
            a_hi4 = a_hi3;
        }
        uint8_t a_hi1_next = a_hi4;
        uint16_t y1_next = (uint16_t)(y1 + 4);
        bool carry1_next = (uint16_t)(y1 + 4) >= 0x0200;
        bool overflow1_next = value3 & 0x4000;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 < 0x0200)) break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CB82, SOM_RTS, "gen", select_scene_bank_and_update_ring_sprite_shadow_priority, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 73, 35)
