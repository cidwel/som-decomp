#include "som_c.h"
#include "som_hand_b.h"

/* C23551 choose_next_boss_script_list   [class B, 67 bytes, 26 instructions]
 * Source: src/rom/choose_next_boss_script_list.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void choose_next_boss_script_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0287);
        r->a = (a_hi1 << 8) | a1;
        r->x = value;
        r->y = y1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR_CHK(c, 0x3555, 0xC235CC); /* choose_script_with_hp_action_and_nonlocal_death_gate */
        uint16_t a_all = r->a;
        bool overflow_ret = r->v;
        uint16_t value2 = RAM16(0x0287);
        RAM16_SET(0x00B0 + value2, a_all);
        RAM16_SET(0x00B2 + value2, 0);
        RAM16_SET(OBJECT_PHASE + value2, (uint16_t)(RAM16(OBJECT_PHASE + value2) + 1));
        uint16_t value3 = RAM16(0x0287);
        RAM16_SET(0x0231, 0xC200);
        RAM16_SET(0x0230, RAM16(0x00B0 + value3));
        uint16_t value5 = RAM16(0x00B2 + value3);
        uint16_t value6 = BUS16(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230) + value5);
        if ((value6 & 0xFF) == 0xFF) {
            RAM16_SET(OBJECT_PHASE + value3, (uint16_t)(RAM16(OBJECT_PHASE + value3) - 1));
            a1 = value6 & 0xFF;
            a_hi1 = 0;
            y1 = value5;
            overflow1 = overflow_ret;
            continue;
        }
        RAM16_SET(0x0236, (uint16_t)(value5 + 1));
        r->a = value6 & 0xFF;
        r->x = value3;
        r->y = (uint16_t)(value5 + 1);
        r->mf = 0;
        r->xf = 0;
        JSR_CHK(c, 0x357F, 0xC2377A); /* select_changed_boss_state_reset_transients_and_interpret_commands */
        uint16_t x_ret2 = r->x;
        uint16_t value7 = RAM16(0x0236);
        RAM16_SET(0x00B2 + x_ret2, value7);
        RAM16_SET(OBJECT_AGE + x_ret2, 0);
        RAM16_SET(OBJECT_PHASE + x_ret2, (uint16_t)(RAM16(OBJECT_PHASE + x_ret2) + 1));
        r->a = value7;
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC23594, SOM_RTS); /* update_boss_action_and_completion */
    }
}
SOM_REGISTER(0xC23551, SOM_RTS, "hand", choose_next_boss_script_list, 0, 0, 1, 0, 0, 67, 26)
