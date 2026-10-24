#include "som_c.h"
/* SOM_POLL_HOOK */

/* C0AC5E run_world_map_survey_input_cancel_and_reentry_loop   [class C, 55 bytes, 26 instructions]
 * Source: src/rom/run_world_map_survey_input_cancel_and_reentry_loop.s
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void run_world_map_survey_input_cancel_and_reentry_loop(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 3;
    uint64_t loop_guard = 0;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t a_ac64 = 0;
    uint8_t a_hi_ac64 = 0;
    uint8_t x_ac64 = 0;
    uint8_t y_ac64 = 0;
    bool carry_ac64 = 0;
    RAM8(0x000E) = 1;
    a_ac64 = 1;
    a_hi_ac64 = a >> 8;
    x_ac64 = (uint8_t)x;
    y_ac64 = (uint8_t)y;
    carry_ac64 = carry;
    shared_AC64:;
    LOOP_GUARD(loop_guard);
    uint8_t value = RAM8(0x000E);
    if ((a_ac64 & value) != 0) {
        goto shared_AC64;
    }
    r->a = (a_hi_ac64 << 8) | a_ac64;
    r->x = x_ac64;
    r->y = y_ac64;
    r->c = carry_ac64;
    r->z = (a_ac64 & value) == 0;
    r->n = value & 0x80;
    r->v = value & 0x40;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xAC6B, 0x02A852); GUARD_JSL(c, sp_call, 0xAC6B); } /* animate_and_upload_world_map_survey_cursor_objects */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAC6E, 0xC0AC95); GUARD_JSR(c, sp_call, 0xAC6E); } /* consume_world_map_survey_motion_and_page_boundaries */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    if (!carry_ret2) {
        RAM8(0x000E) = 1;
        a_ac64 = 1;
        a_hi_ac64 = a_all2 >> 8;
        x_ac64 = (uint8_t)x_ret3;
        y_ac64 = (uint8_t)y_ret2;
        carry_ac64 = carry_ret2;
        goto shared_AC64;
    }
    if ((uint8_t)a_all2 == 0) {
        RAM8(0x0102) = RAM8(0x0000 + sp0 - 2);
        RAM8(0x0101) = RAM8(0x0000 + sp0 - 1);
        RAM8(0x0100) = RAM8(0x0000 + sp0);
        r->c = (uint8_t)a_all2 >= 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 3;
        RETURN_RTS(c);
    }
    RAM8(0x0102) = RAM8(0x0000 + sp0 - 2);
    RAM8(0x0101) = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    RAM8(0x0100) = value7;
    r->a = (a_all2 >> 8 << 8) | value7;
    r->c = (uint8_t)a_all2 >= 0;
    r->z = value7 == 0;
    r->n = value7 & 0x80;
    r->sp += 3;
    TAIL_CALL(c, 0xC0A5CC, SOM_RTS); /* initialize_and_run_complete_world_map_picker_scene */
}
SOM_REGISTER(0xC0AC5E, SOM_RTS, "gen", run_world_map_survey_input_cancel_and_reentry_loop, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 3, -1, 0, 55, 26)
