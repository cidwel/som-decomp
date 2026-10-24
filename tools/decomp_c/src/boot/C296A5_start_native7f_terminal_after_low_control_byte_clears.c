#include "som_c.h"

/* C296A5 start_native7f_terminal_after_low_control_byte_clears   [class A, 24 bytes, 10 instructions]
 * Source: src/rom/start_native7f_terminal_after_low_control_byte_clears.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void start_native7f_terminal_after_low_control_byte_clears(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x0060 + battle_defence_work);
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 0xFF) != 0) {
        x_flag = 0;
        a1 = value & 0xFF;
        a_hi1 = 0;
        x1 = battle_defence_work;
        y1 = y;
        zero1 = (value & 0xFF) == 0;
        negative1 = value & 0xFF & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        uint16_t value2 = RAM16(OBJECT_PHASE + battle_defence_work);
        r->a = value & 0xFF;
        r->x = battle_defence_work;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96B4, 0xC296BD); GUARD_JSR(c, sp_call, 0x96B4); } /* prepare_native7f_terminal_palettes_rng_and_selected_actor_command */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        r->a = 0xF0;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96BA, 0xC2310A); GUARD_JSR(c, sp_call, 0x96BA); } /* request_audio_macro_eighty_with_operand_byte */
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        x_flag = x_ret3;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret4;
        y1 = y_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC296A5, SOM_RTS, "gen", start_native7f_terminal_after_low_control_byte_clears, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 10)
