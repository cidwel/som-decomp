#include "som_c.h"

/* C7571E pack_three_party_name_prefixes_into_saved_slot   [class B, 19 bytes, 7 instructions]
 * Source: src/rom/pack_three_party_name_prefixes_into_saved_slot.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void pack_three_party_name_prefixes_into_saved_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->y = 0xE000;
    JSR(c, 0x5723, 0xC757B1); /* pack_six_party_name_bytes_into_two_slot_copies */
    r->y = 0xE200;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5729, 0xC757B1); /* pack_six_party_name_bytes_into_two_slot_copies */
    r->y = 0xE400;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x572F, 0xC757B1); /* pack_six_party_name_bytes_into_two_slot_copies */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7571E, SOM_RTS, "gen", pack_three_party_name_prefixes_into_saved_slot, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 19, 7)
