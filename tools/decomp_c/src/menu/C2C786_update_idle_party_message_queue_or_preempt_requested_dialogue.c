#include "som_c.h"
#include "som_hand_b.h"

/* C2C786 update_idle_party_message_queue_or_preempt_requested_dialogue   [class B, 44 bytes, 22 instructions]
 * Source: src/rom/update_idle_party_message_queue_or_preempt_requested_dialogue.s
 * Documented in docs/event-party-message-update.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void update_idle_party_message_queue_or_preempt_requested_dialogue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0048);
    if (value != 0) {
        uint16_t value2 = RAM16(0x00D4);
        r->a = (a_hi << 8) | value;
        r->x = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->xf = 0;
        r->sp -= 1;
        JSL_CHK(c, 0xC79D, 0xC00003); /* jump_public_preemptive_native_dialogue */
        r->sp += 1;
        uint16_t value3 = RAM16(0x010E);
        uint8_t value4 = RAM8(0x1D04);
        if (!(value4 & 0x01)) {
            RAM8(0x0048) = 0;
            r->a = (r->a & 0x00FF) | ((value3 >> 8) << 8);
            r->c = value4 & 0x01;
            r->mf = 1;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            RETURN_RTL(c);
        }
        r->a = (r->a & 0x00FF) | ((value3 >> 8) << 8);
        r->c = value4 & 0x01;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTL(c);
    }
    uint8_t value5 = RAM8(0x00D0);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (value5 != 0) {
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        r->a = (a_hi << 8) | value5;
        r->xf = 0;
        JSL_CHK(c, 0xC795, 0xC0005D); /* jump_public_party_message_queue_update */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C786, SOM_RTL, "hand", update_idle_party_message_queue_or_preempt_requested_dialogue, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 44, 22)
