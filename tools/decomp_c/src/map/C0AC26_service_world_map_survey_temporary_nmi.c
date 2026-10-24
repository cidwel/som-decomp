#include "som_c.h"

/* C0AC26 service_world_map_survey_temporary_nmi   [class D, 35 bytes, 18 instructions]
 * Source: src/rom/service_world_map_survey_temporary_nmi.s
 * Entry: M=8 bit X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void service_world_map_survey_temporary_nmi(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = BUS8(c, 0x004210);
    RAM8(0x00F4)++;
    uint8_t value2 = RAM8(0x000E);
    uint8_t value3 = RAM8(0x000F);
    uint8_t a_hi2;
    if ((value2 & value3) == 0) {
        a_hi2 = a_hi;
    } else {
        uint8_t a_hi1;
        if (value2 & value3 & 0x80) {
            a_hi1 = a_hi;
        } else {
            r->a = a_hi << 8 | (value2 & value3);
            r->z = (value2 & value3) == 0;
            r->n = value2 & value3 & 0x80;
            r->db = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAC40, 0xC0AC49); GUARD_JSR(c, sp_call, 0xAC40); } /* converge_world_map_survey_brightness_to_requested_level */
            r->sp += 2;
            uint16_t a_all = r->a;
            a_hi1 = a_all >> 8;
        }
        a_hi2 = a_hi1;
    }
    RAM8(0x000E) = 0;
    r->a = (a_hi2 << 8) | a;
    r->db = db;
    RETURN_RTI(c);
}
SOM_REGISTER(0xC0AC26, SOM_RTI, "gen", service_world_map_survey_temporary_nmi, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, -1, 35, 18)
