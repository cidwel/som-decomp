#include "som_c.h"

/* C0BEAA request_actual_map_entry_event_and_restore_deferred_party_actor   [class B, 82 bytes, 37 instructions]
 * Source: src/rom/request_actual_map_entry_event_and_restore_deferred_party_actor.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYC.
 */
static void request_actual_map_entry_event_and_restore_deferred_party_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM8(EVENT_FLAG_BYTES) == 0) {
        uint8_t value = RAM8(0x00ED);
        if (value & 0x80) {
            RAM8(0x00ED) = value & 0x7F;
            RAM8(0xEC82) = RAM8(0xE882);
            RAM8(0xEC83) = 4;
        }
    }
    uint8_t value3 = RAM8(0x00B8);
    RAM8(0x004D) = (uint8_t)(((value3 & 3) ^ 0xFF) + 0xC1);
    if ((value3 & 4) != 0) {
        uint8_t value4 = RAM8(0x00E8);
        if (value4 & 0x80) {
            SET_A8(r, value4);
            r->c = ((value3 & 3) ^ 0xFF) + 0xC1 > 0xFF;
            RETURN_RTS(c);
        }
        if ((value4 & 3) != 3) {
            uint16_t value5 = RAM16(0x00DC);
            uint16_t value6 = BUS16(c, 0xC84000 + (uint16_t)(value5 << 1));
            uint16_t value7 = BUS16(c, 0xC80000 + value6);
            r->a = value7 & 0x0FFF;
            r->x = value6;
            r->c = value5 & 0x8000;
            r->z = (value7 & 0x0FFF) == 0;
            r->n = value7 & 0x0FFF & 0x8000;
            r->v = (((value3 & 3) ^ 0xFF ^ (uint8_t)(((value3 & 3) ^ 0xFF) + 0xC1)) & ((uint8_t)(((value3 & 3) ^ 0xFF) + 0xC1) ^ 0xC0) & 0x80) != 0;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xBEFA, 0x01E76D); GUARD_JSL(c, sp_call, 0xBEFA); } /* event_command_map_context_entry */
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        SET_A8(r, value4 & 3);
        r->c = (value4 & 3) >= 3;
        RETURN_RTS(c);
    }
    SET_A8(r, value3 & 4);
    r->c = ((value3 & 3) ^ 0xFF) + 0xC1 > 0xFF;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BEAA, SOM_RTS, "gen", request_actual_map_entry_event_and_restore_deferred_party_actor, 0, L_A | L_B | L_X | L_Y | L_C, 1, 1, 0, 82, 37)
