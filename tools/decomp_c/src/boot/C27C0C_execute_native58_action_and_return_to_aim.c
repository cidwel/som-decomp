#include "som_c.h"
#include "som_hand_b.h"

/* C27C0C execute_native58_action_and_return_to_aim   [class A, 22 bytes, 10 instructions]
 * Source: src/rom/execute_native58_action_and_return_to_aim.s
 * Documented in docs/boss-native58-parent-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void execute_native58_action_and_return_to_aim(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x0380);
    RAM8(0x0380) = value & 0x7F;
    uint16_t value2 = RAM16(0x0287);
    r->a = a >> 8 << 8 | (value & 0x7F);
    r->x = value2;
    JSR_CHK(c, 0x7C1C, 0xC27C38); /* cycle_native58_living_body_parts_and_dispatch_order */
    uint16_t x_ret = r->x;
    if (r->mf) { /* the callee decides the accumulator width of the DEC */
        uint8_t phase = (uint8_t)(RAM8(OBJECT_PHASE + x_ret) - 1);
        RAM8(OBJECT_PHASE + x_ret) = phase;
        hand_nz8(r, phase);
    } else {
        uint16_t phase = (uint16_t)(RAM16(OBJECT_PHASE + x_ret) - 1);
        RAM16_SET(OBJECT_PHASE + x_ret, phase);
        hand_nz16(r, phase);
    }
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27C0C, SOM_RTS, "hand", execute_native58_action_and_return_to_aim, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 22, 10)
