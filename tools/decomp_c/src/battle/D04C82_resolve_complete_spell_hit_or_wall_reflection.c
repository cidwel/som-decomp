#include "som_c.h"
#include "som_hand_b.h"

/* D04C82 resolve_complete_spell_hit_or_wall_reflection   [class B, 252 bytes, 118 instructions]
 * Source: src/rom/resolve_complete_spell_hit_or_wall_reflection.s
 * Documented in docs/actor-cast-spell-reflection.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXCV.
 */
/* Accumulator helpers: they keep r->a and the N/Z flags exact so the call arguments match the original. */
#define LDA8(v) do { uint8_t v_ = (v); r->a = (r->a & 0xFF00) | v_; hand_nz8(r, v_); } while (0)
#define A8 ((uint8_t)r->a)

static void resolve_complete_spell_hit_or_wall_reflection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    i_phd(c);
    i_phb(c);
    i_php(c);
    JSL_CHK(c, 0x4C88, 0xC0395E); /* prepare_cast_actor_context_long: leaves D = $0300, M = 8, X = 16 */
    if (!r->mf || r->xf) { c->fail = 3; return; }
    const uint16_t d = r->dp;
    uint16_t x = r->x;
    uint16_t y = r->y;

    LDA8(RAM8(0xE1FB + x));
    if (A8 & 0x80) {
        LDA8(RAM8(0xE191 + x));
        if (A8 & 0x80) {
            LDA8(RAM8(0xE1B1 + x));
            LDA8(A8 | 0x08);
            RAM8(0xE1B1 + x) = A8;
        }
    }
    LDA8(RAM8(0xE1B1 + x));
    r->z = (A8 & 0x40) == 0; /* BIT #$40 */
    bool plain_hit = true;
    if (A8 & 0x40) {
        LDA8(RAM8(0xE170 + y));
        plain_hit = A8 == 0x20 || A8 == 0x23 || A8 == 0x26;
        if (!plain_hit) {
            x = 3;
            LDA8(RAM8(0x0081 + d));
            LDA8(A8 + 1);
            for (;;) {
                uint8_t slot = RAM8(0xE178 + y);
                hand_cmp16(r, A8, slot);
                if (A8 == slot) break;
                y++;
                x--;
                if (x == 0) { plain_hit = true; break; }
            }
        }
    }
    if (!plain_hit) {
        /* The shield counter matched: consume a charge and try up to three reflection directions. */
        y = RAM16(0x0085 + d);
        x = RAM16(0x0083 + d);
        LDA8(RAM8(0xE1B8 + y));
        LDA8(A8 - 1);
        RAM8(0xE1B8 + y) = A8;
        if (A8 == 0) {
            LDA8(RAM8(0xE1B1 + y));
            LDA8(A8 & 0xBF);
            RAM8(0xE1B1 + y) = A8;
        }
        LDA8(RAM8(0xE1FB + y));
        x = (A8 & 0x80) ? 0x0600 : 0x0000;
        LDA8(3);
        RAM8(0x00B2 + d) = 3;
        r->x = x;
        r->y = y;
        JSL_CHK(c, 0x4CFC, 0xC0389C); /* random_byte_long_wrapper */
        x = r->x;
        y = r->y;
        r->mf = 0; /* REP #$20 */
        RAM16_SET(0x00D0 + d, x);
        r->a = (uint16_t)((r->a & 0x0003) << 3);
        RAM16_SET(0x00D4 + d, r->a);
        r->a = RAM16(0xE002 + y);
        RAM16_SET(0x00AC + d, r->a);
        r->a = RAM16(0xE004 + y);
        RAM16_SET(0x00AE + d, r->a);
        for (;;) {
            r->mf = 0;
            r->a = RAM16(0x00D4 + d);
            x = r->a;
            r->a = BUS16(c, 0xD04D7E + x);
            r->a = (uint16_t)(r->a + RAM16(0x00D0 + d));
            x = r->a;
            r->mf = 1; /* SEP #$20 */
            LDA8(RAM8(0xE000 + x));
            bool reflected = false;
            if (A8 == 1) {
                LDA8(RAM8(0xE191 + x));
                if (!(A8 & 0x80)) {
                    LDA8(RAM8(0xE1FB + x));
                    if ((A8 & 0x30) == 0) {
                        LDA8(RAM8(0x00ED));
                        if (A8 & 0x80) {
                            r->mf = 0;
                            uint16_t dx = (uint16_t)(RAM16(0xE002 + x) - RAM16(0x00AC + d));
                            if (dx & 0x8000) dx = (uint16_t)(~dx + 1);
                            RAM16_SET(0x00A8 + d, dx);
                            uint16_t dy = (uint16_t)(RAM16(0xE004 + x) - RAM16(0x00AE + d));
                            if (dy & 0x8000) dy = (uint16_t)(~dy + 1);
                            RAM16_SET(0x00AA + d, dy);
                            r->a = (uint16_t)(dy + dx);
                            hand_cmp16(r, r->a, 0x00F0);
                            r->mf = 1;
                            reflected = r->a < 0x00F0;
                        }
                    }
                }
            }
            if (reflected) {
                r->x = x;
                i_phx(c);
                JSL_CHK(c, 0x4D68, 0xC0595F); /* enqueue_unique_spell_reflection_notice */
                i_plx(c);
                LDA8(0xFF);
                goto leave;
            }
            RAM8(0x00CD + d)++;
            RAM8(0x00CD + d)++;
            RAM8(0x00D4 + d)++;
            RAM8(0x00D4 + d)++;
            RAM8(0x00B2 + d)--;
            if (RAM8(0x00B2 + d) == 0) break;
        }
    }
    y = RAM16(0x0085 + d);
    x = RAM16(0x0083 + d);
    r->x = x;
    r->y = y;
    JSL_CHK(c, 0x4CA9, 0xC8E6D4); /* apply_spell_hit_to_actor */
    LDA8(0);
    r->x = 0;
    hand_nz16(r, 0);
leave:
    hand_plp(c);
    hand_plb(c);
    hand_pld(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xD04C82, SOM_RTL, "hand", resolve_complete_spell_hit_or_wall_reflection, 0, L_A | L_B | L_X | L_C | L_V, 6, 0, 0, 252, 118)
