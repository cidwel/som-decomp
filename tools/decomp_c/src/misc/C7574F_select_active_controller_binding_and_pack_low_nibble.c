#include "som_c.h"

/* C7574F select_active_controller_binding_and_pack_low_nibble   [class A, 32 bytes, 15 instructions]
 * Source: src/rom/select_active_controller_binding_and_pack_low_nibble.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void select_active_controller_binding_and_pack_low_nibble(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x00D9);
    uint8_t a3;
    if ((value & 0x80) != 0) {
        a3 = value;
    } else {
        uint8_t value2 = RAM8(0x00DA);
        uint8_t a2;
        if ((value2 & 0x80) != 0) {
            a2 = value2;
        } else {
            uint8_t value3 = RAM8(0x00DB);
            uint8_t a1;
            if ((value3 & 0x80) != 0) {
                a1 = value3;
            } else {
                a1 = 1;
            }
            a2 = a1;
        }
        a3 = a2;
    }
    BUS8_SET(c, 0x306000 + x, a3 & 0x0F);
    BUS8_SET(c, 0x307000 + x, a3 & 0x0F);
    r->x = (uint16_t)(x + 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7574F, SOM_RTS, "gen", select_active_controller_binding_and_pack_low_nibble, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 32, 15)
