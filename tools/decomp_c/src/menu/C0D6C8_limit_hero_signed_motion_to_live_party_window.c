#include "som_c.h"
#include "som_hand_b.h"

/* C0D6C8 limit_hero_signed_motion_to_live_party_window   [class B, 135 bytes, 58 instructions]
 * Source: src/rom/limit_hero_signed_motion_to_live_party_window.s
 * Documented in docs/map-hero-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 * Hand written: register widths on every exit are whatever the last callee left, except where the code itself
 * executes SEP/REP. */

/* After a blocked step the hero is tested against the other party members: the first two checks use the two
 * partner slots that are not the hero's own ($0200, $0400, $0000 depending on $11). */
static void partner_checks_horizontal(SomCtx *c, uint8_t who)
{
    Cpu *r = &c->cpu;
    if (who == 0) {
        r->x = 0x0200;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD707, 0xC0D9AE); GUARD_JSR_DB(c, sp_call, 0xD707, db_call); }
        r->x = 0x0400;
    } else if (who == 2) {
        r->x = 0x0000; r->c = 1;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD6FF, 0xC0D9AE); GUARD_JSR_DB(c, sp_call, 0xD6FF, db_call); }
        r->x = 0x0400;
    } else {
        r->x = 0x0000; r->c = who >= 2;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD6F4, 0xC0D9AE); GUARD_JSR_DB(c, sp_call, 0xD6F4, db_call); }
        r->x = 0x0200;
    }
    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD70D, 0xC0D9AE); GUARD_JSR_DB(c, sp_call, 0xD70D, db_call); }
}

static void partner_checks_vertical(SomCtx *c, uint8_t who)
{
    Cpu *r = &c->cpu;
    if (who == 0) {
        r->x = 0x0200;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD744, 0xC0DA34); GUARD_JSR_DB(c, sp_call, 0xD744, db_call); }
        r->x = 0x0400;
    } else if (who == 2) {
        r->x = 0x0000; r->c = 1;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD73C, 0xC0DA34); GUARD_JSR_DB(c, sp_call, 0xD73C, db_call); }
        r->x = 0x0400;
    } else {
        r->x = 0x0000; r->c = who >= 2;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD731, 0xC0DA34); GUARD_JSR_DB(c, sp_call, 0xD731, db_call); }
        r->x = 0x0200;
    }
    TAIL_CALL(c, 0xC0DA34, SOM_RTS);
}

static void limit_hero_signed_motion_to_live_party_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }

    r->mf = 1; r->xf = 1;                        /* SEP #$30 */
    r->x &= 0xFF; r->y &= 0xFF;
    uint8_t busy = RAM8(0x00FF);
    hand_lda8(r, busy);
    if (busy != 0) RETURN_RTS(c);

    uint8_t dx = RAM8(0x001E);
    hand_lda8(r, dx);
    if (dx != 0) {
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD6D5, 0xC0D962); GUARD_JSR_DB(c, sp_call, 0xD6D5, db_call); }            /* test_hero_horizontal_step_against_camera_window */
        if (r->c) {
            r->mf = 1; r->xf = 0;                /* SEP #$20, REP #$10 */
            r->x = RAM16(0x10);
            uint8_t partner_flag = RAM8(0xE02C + r->x);
            hand_lda8(r, partner_flag);
            if (partner_flag == 0) {
                RAM8(0x001E) = 0;
            } else {
                uint8_t who = RAM8(0x11);
                hand_lda8(r, who);
                partner_checks_horizontal(c, who);
                if (c->fail || c->unwound) return;
            }
        }
    }

    r->mf = 1;                                   /* SEP #$20 */
    uint8_t dy = RAM8(0x001F);
    hand_lda8(r, dy);
    if (dy == 0) RETURN_RTS(c);
    { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0xD716, 0xC0D9E8); GUARD_JSR_DB(c, sp_call, 0xD716, db_call); }                /* test_hero_vertical_step_against_camera_window */
    if (!r->c) RETURN_RTS(c);

    r->mf = 1; r->xf = 0;                        /* SEP #$20, REP #$10 */
    r->x = RAM16(0x10);
    uint8_t partner_flag = RAM8(0xE02C + r->x);
    hand_lda8(r, partner_flag);
    if (partner_flag == 0) {
        RAM8(0x001F) = 0;
        RETURN_RTS(c);
    }
    uint8_t who = RAM8(0x11);
    hand_lda8(r, who);
    partner_checks_vertical(c, who);
}
SOM_REGISTER(0xC0D6C8, SOM_RTS, "hand", limit_hero_signed_motion_to_live_party_window, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 135, 58)
