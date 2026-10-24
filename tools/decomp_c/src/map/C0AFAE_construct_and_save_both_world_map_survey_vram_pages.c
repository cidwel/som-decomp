#include "som_c.h"
/* SOM_POLL_HOOK */

static void sub_C0AFC4(SomCtx *c);

/* C0AFAE construct_and_save_both_world_map_survey_vram_pages   [class D, 75 bytes, 29 instructions]
 * Source: src/rom/construct_and_save_both_world_map_survey_vram_pages.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYV.
 */
static void construct_and_save_both_world_map_survey_vram_pages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAFB0, 0xC0AFF9); GUARD_JSR(c, sp_call, 0xAFB0); } /* decode_last_two_world_map_survey_tile_groups */
    r->a = 0x2000;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xAFB8, sub_C0AFC4, sp_in, 2); GUARD_JSR(c, sp_call, 0xAFB8); }
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAFBB, 0xC0B00D); GUARD_JSR(c, sp_call, 0xAFBB); } /* await_survey_nmi_and_clear_complete_vram_page */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAFBE, 0xC0AE35); GUARD_JSR(c, sp_call, 0xAFBE); } /* decode_and_pack_complete_world_map_survey_tile_groups */
    r->a = 0x1000;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    sub_C0AFC4(c); return;
}
SOM_REGISTER(0xC0AFAE, SOM_RTS, "gen", construct_and_save_both_world_map_survey_vram_pages, 0, L_X | L_Y | L_V, 5, 1, 1, 75, 29)

/* C0AFC4 sub_C0AFC4   [class A, 53 bytes, 21 instructions]
 * Source: src/rom/construct_and_save_both_world_map_survey_vram_pages.s
 * Subroutine of construct_and_save_both_world_map_survey_vram_pages, translated in place.
 * Entry: M=16 bit X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void sub_C0AFC4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, -1)) return;
    uint64_t loop_guard = 0;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    BUS16_SET(c, (db << 0x10) + 0x4372, a);
    BUS16_SET(c, (db << 0x10) + 0x4370, 0x3981);
    BUS16_SET(c, (db << 0x10) + 0x4375, 0x1000);
    BUS8_SET(c, (db << 0x10) + 0x4374, 0x7F);
    BUS8_SET(c, (uint16_t)(dp + 0x0E), 0x80);
    bool overflow1 = overflow;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x0E));
        overflow1 = value & 0x40;
        if (!((value & 0x80) != 0)) break;
    }
    BUS8_SET(c, (db << 0x10) + 0x2116, 0);
    BUS8_SET(c, (db << 0x10) + 0x2117, 0);
    BUS8_SET(c, (db << 0x10) + 0x2115, 0x80);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x213A);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x213B);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x80);
    r->a = 0x1080;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->z = 0;
    r->n = 1;
    r->v = overflow1;
    r->mf = 1;
    RETURN_RTS(c);
}
