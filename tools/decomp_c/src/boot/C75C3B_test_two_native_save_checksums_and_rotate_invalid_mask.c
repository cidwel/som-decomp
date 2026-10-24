#include "som_c.h"

/* C75C3B test_two_native_save_checksums_and_rotate_invalid_mask   [class B, 57 bytes, 28 instructions]
 * Source: src/rom/test_two_native_save_checksums_and_rotate_invalid_mask.s
 * Documented in docs/ui-native-loaded-game-save-validation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: Y.
 */
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)

static void test_two_native_save_checksums_and_rotate_invalid_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t value;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    a_lda(r, 0x02);
    do {
        i_pha(c);
        BUS8_OK(c, ABS(0xA216), value);
        BUS8_SET(c, ABS(0xA216), m_ror(r, value));
        bool invalid = r->c;
        if (!invalid) {
            { const uint16_t sp_call = r->sp; JSR(c, 0x5C45, 0xC75CDC); GUARD_JSR_DB(c, sp_call, 0x5C45, 0x7E); } /* sum_native_save_payload_bytes_into_sixteen_bit_checksum */
            if (!r->mf || r->xf) { c->fail = 3; return; }
            BUS8_OK(c, ABS(0xA173), value);
            a_lda(r, value);
            value = BUS8(c, (0x306001 + r->x) & 0xFFFFFF); /* SRAM: mapped, read like the bus does */
            if (c->fail) return;
            a_cmp(r, value);
            if (r->z) {
                BUS8_OK(c, ABS(0xA174), value);
                a_lda(r, value);
                value = BUS8(c, (0x306002 + r->x) & 0xFFFFFF);
                if (c->fail) return;
                a_cmp(r, value);
            }
            invalid = !r->z;
        }
        r->c = invalid;                       /* the rotate shifts the verdict into the mask */
        BUS8_OK(c, ABS(0xA215), value);
        BUS8_SET(c, ABS(0xA215), m_ror(r, value));
        i_rep(r, 0x20);
        i_txa(r);
        r->c = 0;
        a_adc(r, 0x1000);
        i_tax(r);
        i_sep(r, 0x20);
        i_pla(c);
        i_deca(r);
    } while (!r->z);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75C3B, SOM_RTS, "hand", test_two_native_save_checksums_and_rotate_invalid_mask, 0, L_Y, 1, 1, 0, 57, 28)
