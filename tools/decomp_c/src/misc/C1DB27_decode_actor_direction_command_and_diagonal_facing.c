#include "som_c.h"

/* C1DB27 decode_actor_direction_command_and_diagonal_facing   [class B, 68 bytes, 35 instructions]
 * Source: src/rom/decode_actor_direction_command_and_diagonal_facing.s
 * Documented in docs/actor-action-direction.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void decode_actor_direction_command_and_diagonal_facing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE141 + x);
    if ((value & 1) == 0) {
        if ((value & 2) == 0) {
            if ((value & 4) == 0) {
                if ((value & 8) == 0) {
                    SET_A8(r, 0);
                    RETURN_RTS(c);
                }
                SET_A8(r, 0);
                RETURN_RTS(c);
            }
            SET_A8(r, 1);
            RETURN_RTS(c);
        }
        if ((value & 4) == 0) {
            if ((value & 8) != 0) {
                RAM8(0xE013 + x) = 1;
            }
        } else {
            RAM8(0xE013 + x) = 0x80;
        }
        SET_A8(r, 0x82);
        RETURN_RTS(c);
    }
    if ((value & 4) == 0) {
        if ((value & 8) != 0) {
            RAM8(0xE013 + x) = 0x80;
        }
    } else {
        RAM8(0xE013 + x) = 1;
    }
    SET_A8(r, 2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1DB27, SOM_RTS, "gen", decode_actor_direction_command_and_diagonal_facing, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 0, 68, 35)
