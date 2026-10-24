#include "som_c.h"

/* C64285 clip_and_pack_visible_mode_seven_transition_objects   [class B, 266 bytes, 124 instructions]
 * Source: src/rom/clip_and_pack_visible_mode_seven_transition_objects.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BY.
 */
static void clip_and_pack_visible_mode_seven_transition_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x004E, 0);
    RAM16_SET(0x0026, (uint16_t)(0x0320 - RAM16(0x004A)));
    uint16_t value2 = RAM16(0x0026);
    uint8_t a_hi2;
    if (value2 > 0xF0) {
        a_hi2 = (uint16_t)(0xF0 - value2) >> 8;
    } else {
        uint8_t a_hi1;
        if ((uint16_t)((uint16_t)(0xF0 - value2) - 0x20 - (value2 <= 0xF0 ^ 1)) >= 0xE0) {
            a_hi1 = (uint16_t)((uint16_t)(0xF0 - value2) - 0x20 - (value2 <= 0xF0 ^ 1)) >> 8;
        } else {
            RAM8(0x0022) = (uint8_t)((uint16_t)(0xF0 - value2) - 0x20 - (value2 <= 0xF0 ^ 1));
            RAM8(0x0020) = 0xB4;
            RAM8(0x0021) = 2;
            RAM16_SET(0x0024, 0);
            r->db = 0xC7;
            r->sp -= 1;
            JSL(c, 0x42BA, 0xC64604); /* append_five_byte_mode_seven_scene_object */
            r->sp += 1;
            RAM8(0x0020) = (uint8_t)(RAM8(0x0020) + 0x10);
            RAM8(0x0024) = 2;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 1;
            JSL(c, 0x42C9, 0xC64604); /* append_five_byte_mode_seven_scene_object */
            r->sp += 1;
            RAM8(0x0022) = (uint8_t)(RAM8(0x0022) + 0x10);
            RAM8(0x0024) = 0x22;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 1;
            JSL(c, 0x42D8, 0xC64604); /* append_five_byte_mode_seven_scene_object */
            r->sp += 1;
            RAM8(0x0020) = (uint8_t)(RAM8(0x0020) - 0x10);
            RAM8(0x0024) = 0x20;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 1;
            JSL(c, 0x42E7, 0xC64604); /* append_five_byte_mode_seven_scene_object */
            r->sp += 1;
            uint16_t a_all4 = r->a;
            a_hi1 = a_all4 >> 8;
        }
        a_hi2 = a_hi1;
    }
    RAM16_SET(0x0028, 8);
    uint8_t a_hi3 = 0;
    uint16_t y1 = 0xFBA0;
    do {
        uint16_t value6 = BUS16(c, 0xC70001 + y1);
        uint16_t value7 = RAM16(0x0026);
        uint8_t a_hi5;
        if ((uint16_t)(value6 + 0x10) < value7) {
            a_hi5 = (uint16_t)((uint16_t)(value6 + 0x10) - value7) >> 8;
        } else {
            uint8_t a_hi4;
            if ((uint16_t)((uint16_t)((uint16_t)(value6 + 0x10) - value7) - 0x10 - ((uint16_t)(value6 + 0x10) >= value7 ^ 1)) >= 0xE0) {
                a_hi4 = (uint16_t)((uint16_t)((uint16_t)(value6 + 0x10) - value7) - 0x10 - ((uint16_t)(value6 + 0x10) >= value7 ^ 1)) >> 8;
            } else {
                RAM8(0x0022) = (uint8_t)((uint16_t)((uint16_t)(value6 + 0x10) - value7) - 0x10 - ((uint16_t)(value6 + 0x10) >= value7 ^ 1));
                uint8_t value8 = BUS8(c, 0xC70000 + y1);
                RAM8(0x0020) = value8;
                RAM8(0x0021) = 0;
                RAM16_SET(0x0024, 4);
                r->y = y1;
                r->mf = 1;
                r->xf = 0;
                r->db = 0xC7;
                r->dp = 0;
                r->sp -= 1;
                JSL(c, 0x431B, 0xC64604); /* append_five_byte_mode_seven_scene_object */
                r->sp += 1;
                RAM8(0x0020) = (uint8_t)(RAM8(0x0020) + 8);
                RAM8(0x0024)++;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 1;
                JSL(c, 0x4328, 0xC64604); /* append_five_byte_mode_seven_scene_object */
                r->sp += 1;
                RAM8(0x0020) = (uint8_t)(RAM8(0x0020) + 8);
                RAM8(0x0024)++;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 1;
                JSL(c, 0x4335, 0xC64604); /* append_five_byte_mode_seven_scene_object */
                r->sp += 1;
                RAM8(0x0020) = (uint8_t)(RAM8(0x0020) + 8);
                RAM8(0x0024)++;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 1;
                JSL(c, 0x4342, 0xC64604); /* append_five_byte_mode_seven_scene_object */
                r->sp += 1;
                uint16_t a_all8 = r->a;
                a_hi4 = a_all8 >> 8;
            }
            a_hi5 = a_hi4;
        }
        RAM16_SET(0x0028, (uint16_t)(RAM16(0x0028) - 1));
        a_hi3 = a_hi5;
        y1 = (uint16_t)(y1 + 3);
    } while (RAM16(0x0028) != 0);
    RAM16_SET(0x0028, 8);
    uint8_t a_hi6 = 0;
    uint16_t y2 = 0xFBB8;
    do {
        uint16_t value15 = BUS16(c, 0xC70001 + y2);
        uint16_t value16 = RAM16(0x0026);
        uint8_t a_hi8;
        if ((uint16_t)(value15 + 0x20) < value16) {
            a_hi8 = (uint16_t)((uint16_t)(value15 + 0x20) - value16) >> 8;
        } else {
            uint8_t a_hi7;
            if ((uint16_t)((uint16_t)((uint16_t)(value15 + 0x20) - value16) - 0x20 - ((uint16_t)(value15 + 0x20) >= value16 ^ 1)) >= 0xE0) {
                a_hi7 = (uint16_t)((uint16_t)((uint16_t)(value15 + 0x20) - value16) - 0x20 - ((uint16_t)(value15 + 0x20) >= value16 ^ 1)) >> 8;
            } else {
                RAM8(0x0022) = (uint8_t)((uint16_t)((uint16_t)(value15 + 0x20) - value16) - 0x20 - ((uint16_t)(value15 + 0x20) >= value16 ^ 1));
                uint8_t value17 = BUS8(c, 0xC70000 + y2);
                RAM8(0x0020) = value17;
                RAM8(0x0021) = 2;
                RAM16_SET(0x0024, 8);
                r->y = y2;
                r->mf = 1;
                r->xf = 0;
                r->db = 0xC7;
                r->dp = 0;
                r->sp -= 1;
                JSL(c, 0x437D, 0xC64604); /* append_five_byte_mode_seven_scene_object */
                r->sp += 1;
                uint16_t a_all9 = r->a;
                a_hi7 = a_all9 >> 8;
            }
            a_hi8 = a_hi7;
        }
        RAM16_SET(0x0028, (uint16_t)(RAM16(0x0028) - 1));
        a_hi6 = a_hi8;
        y2 = (uint16_t)(y2 + 3);
    } while (RAM16(0x0028) != 0);
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    JSL(c, 0x438D, 0xC6462B); /* pack_mode_seven_scene_objects_into_complete_oam_buffer */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC64285, SOM_RTS, "gen", clip_and_pack_visible_mode_seven_transition_objects, 0, L_B | L_Y, 2, 1, 0, 266, 124)
