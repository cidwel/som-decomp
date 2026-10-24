#include "som_c.h"
#include "som_hand_d.h"

/* C75BCA validate_four_native_save_slot_signatures_copies_and_checksums   [class B, 16 bytes, 6 instructions]
 * Source: src/rom/validate_four_native_save_slot_signatures_copies_and_checksums.s
 * Documented in docs/ui-native-loaded-game-save-validation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void validate_four_native_save_slot_signatures_copies_and_checksums(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, -1)) return;
L_C75BCA:;
    STZ(c, ABS, 0xa215);
    STZ(c, ABS, 0xa216);
    JSR(c, 0x5bd2, 0xC75BDA);
    JSR(c, 0x5bd5, 0xC75C74);
    JSR(c, 0x5bd8, 0xC75C1F);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75BCA, SOM_RTS, "hand", validate_four_native_save_slot_signatures_copies_and_checksums, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 16, 6)
