#include "som_c.h"

/* C75BDA scan_native_save_slot_primary_and_backup_signatures   [class B, 42 bytes, 22 instructions]
 * Source: src/rom/scan_native_save_slot_primary_and_backup_signatures.s
 * Documented in docs/ui-native-loaded-game-save-validation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void scan_native_save_slot_primary_and_backup_signatures(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA175) = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    do {
        r->x = x1;
        r->y = y1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        r->sp -= 4;
        JSR(c, 0x5BE6, 0xC75C04); /* test_native_save_signature_pair_and_rotate_invalid_mask */
        r->sp += 4;
        r->x = (uint16_t)(x1 + 0x1000);
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x5BF3, 0xC75C04); /* test_native_save_signature_pair_and_rotate_invalid_mask */
        r->sp += 2;
        RAM8(0xA175)--;
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x0400) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x0400);
        bool carry1_next = x1 + 0x0400 > 0xFFFF;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x0400)) & ((uint16_t)(x1 + 0x0400) ^ 0x0400) & 0x8000) != 0;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
    } while (RAM8(0xA175) != 0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75BDA, SOM_RTS, "gen", scan_native_save_slot_primary_and_backup_signatures, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 42, 22)
