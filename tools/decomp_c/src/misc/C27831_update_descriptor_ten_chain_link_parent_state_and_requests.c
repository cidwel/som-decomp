#include "som_c.h"

/* C27831 update_descriptor_ten_chain_link_parent_state_and_requests   [class B, 44 bytes, 19 instructions]
 * Source: src/rom/update_descriptor_ten_chain_link_parent_state_and_requests.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void update_descriptor_ten_chain_link_parent_state_and_requests(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    uint16_t value3 = RAM16(OBJECT_PHASE + value2);
    if (value3 >= 7) {
        RAM16_SET(OBJECT_PHASE + value, 6);
        r->a = 6;
        r->x = value;
        r->y = value2;
        r->c = 0;
        r->z = 0;
        r->n = 0;
        RETURN_RTS(c);
    }
    r->a = value3;
    r->x = value;
    JSR(c, 0x7840, 0xC278AA); /* orient_descriptor_ten_chain_link_from_parent_quadrant */
    uint16_t value5 = RAM16(0x00B0 + RAM16(0x0287));
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    if (value5 != 0xE600) {
        r->a = value5;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x7852, 0xC279E3); /* propagate_predecessor_request_and_seed_chain_animation */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
    } else {
        r->a = value5;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x784D, 0xC279B8); /* consume_primary_boss_request_into_chain_delay_queue */
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret3;
        y1 = y_ret3;
        zero1 = zero_ret3;
        negative1 = negative_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27831, SOM_RTS, "gen", update_descriptor_ten_chain_link_parent_state_and_requests, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 44, 19)
