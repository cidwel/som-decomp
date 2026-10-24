#include "som_c.h"

/* C1251A dispatch_actor_script_opcode   [class C, 26 bytes, 14 instructions]
 * Source: src/rom/dispatch_actor_script_opcode.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABYV.
 */
static void dispatch_actor_script_opcode(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value2 = BUS16(c, 0xD04F15 + RAM16(0x0144 + y));
    r->a = (value2 & 0xFF) << 1;
    r->x = (value2 & 0xFF) << 1;
    r->c = value2 & 0xFF & 0x8000;
    r->z = (value2 & 0xFF) << 1 == 0;
    r->n = (value2 & 0xFF) << 1 & 0x8000;
    r->sp -= 3;
    switch ((value2 & 0xFF) << 1) {
    case 0x0000: JSR(c, 0x252E, 0xC102F8); break; /* actor_script_return */
    case 0x0002: JSR(c, 0x252E, 0xC10285); break; /* jump_actor_script_after_1_bytes */
    case 0x0004: JSR(c, 0x252E, 0xC10645); break; /* actor_script_if_variable_0_nonzero */
    case 0x0006: JSR(c, 0x252E, 0xC10655); break; /* actor_script_if_variable_1_nonzero */
    case 0x0008: JSR(c, 0x252E, 0xC10665); break; /* actor_script_if_variable_2_nonzero */
    case 0x000A: JSR(c, 0x252E, 0xC10675); break; /* actor_script_if_variable_3_nonzero */
    case 0x000C: JSR(c, 0x252E, 0xC10685); break; /* actor_script_if_variable_0_zero */
    case 0x000E: JSR(c, 0x252E, 0xC10695); break; /* actor_script_if_variable_1_zero */
    case 0x0010: JSR(c, 0x252E, 0xC106A5); break; /* actor_script_if_variable_2_zero */
    case 0x0012: JSR(c, 0x252E, 0xC106B5); break; /* actor_script_if_variable_3_zero */
    case 0x0014: JSR(c, 0x252E, 0xC11741); break; /* actor_script_if_variable_0_not_equal */
    case 0x0016: JSR(c, 0x252E, 0xC11756); break; /* actor_script_if_variable_1_not_equal */
    case 0x0018: JSR(c, 0x252E, 0xC1176B); break; /* actor_script_if_variable_2_not_equal */
    case 0x001A: JSR(c, 0x252E, 0xC11780); break; /* actor_script_if_variable_3_not_equal */
    case 0x001C: JSR(c, 0x252E, 0xC11795); break; /* actor_script_if_variable_0_equal */
    case 0x001E: JSR(c, 0x252E, 0xC117AA); break; /* actor_script_if_variable_1_equal */
    case 0x0020: JSR(c, 0x252E, 0xC117BF); break; /* actor_script_if_variable_2_equal */
    case 0x0022: JSR(c, 0x252E, 0xC117D4); break; /* actor_script_if_variable_3_equal */
    case 0x0024: JSR(c, 0x252E, 0xC117E9); break; /* actor_script_if_variable_0_greater */
    case 0x0026: JSR(c, 0x252E, 0xC11800); break; /* actor_script_if_variable_1_greater */
    case 0x0028: JSR(c, 0x252E, 0xC11817); break; /* actor_script_if_variable_2_greater */
    case 0x002A: JSR(c, 0x252E, 0xC1182E); break; /* actor_script_if_variable_3_greater */
    case 0x002C: JSR(c, 0x252E, 0xC11845); break; /* actor_script_if_variable_0_less */
    case 0x002E: JSR(c, 0x252E, 0xC1185A); break; /* actor_script_if_variable_1_less */
    case 0x0030: JSR(c, 0x252E, 0xC1186F); break; /* actor_script_if_variable_2_less */
    case 0x0032: JSR(c, 0x252E, 0xC11884); break; /* actor_script_if_variable_3_less */
    case 0x0034: JSR(c, 0x252E, 0xC105DA); break; /* actor_script_increment_variable_0 */
    case 0x0036: JSR(c, 0x252E, 0xC105E4); break; /* actor_script_increment_variable_1 */
    case 0x0038: JSR(c, 0x252E, 0xC105EE); break; /* actor_script_increment_variable_2 */
    case 0x003A: JSR(c, 0x252E, 0xC105F8); break; /* actor_script_increment_variable_3 */
    case 0x003C: JSR(c, 0x252E, 0xC10602); break; /* actor_script_decrement_variable_0 */
    case 0x003E: JSR(c, 0x252E, 0xC1060C); break; /* actor_script_decrement_variable_1 */
    case 0x0040: JSR(c, 0x252E, 0xC10616); break; /* actor_script_decrement_variable_2 */
    case 0x0042: JSR(c, 0x252E, 0xC10620); break; /* actor_script_decrement_variable_3 */
    case 0x0044: JSR(c, 0x252E, 0xC1062A); break; /* actor_script_copy_variable_0_to_1 */
    case 0x0046: JSR(c, 0x252E, 0xC10633); break; /* actor_script_copy_variable_0_to_2 */
    case 0x0048: JSR(c, 0x252E, 0xC1063C); break; /* actor_script_copy_variable_0_to_3 */
    case 0x004A: JSR(c, 0x252E, 0xC116B8); break; /* actor_script_set_variable_0 */
    case 0x004C: JSR(c, 0x252E, 0xC116C7); break; /* actor_script_set_variable_1 */
    case 0x004E: JSR(c, 0x252E, 0xC116D6); break; /* actor_script_set_variable_2 */
    case 0x0050: JSR(c, 0x252E, 0xC116E5); break; /* actor_script_set_variable_3 */
    case 0x0052: JSR(c, 0x252E, 0xC1171D); break; /* actor_script_random_variable_0 */
    case 0x0054: JSR(c, 0x252E, 0xC11726); break; /* actor_script_random_variable_1 */
    case 0x0056: JSR(c, 0x252E, 0xC1172F); break; /* actor_script_random_variable_2 */
    case 0x0058: JSR(c, 0x252E, 0xC11738); break; /* actor_script_random_variable_3 */
    case 0x005A: JSR(c, 0x252E, 0xC12042); break; /* actor_script_if_byte_field_mask_nonzero */
    case 0x005C: JSR(c, 0x252E, 0xC1205A); break; /* actor_script_if_byte_field_mask_zero */
    case 0x005E: JSR(c, 0x252E, 0xC12072); break; /* actor_script_if_byte_field_less */
    case 0x0060: JSR(c, 0x252E, 0xC1208A); break; /* actor_script_if_byte_field_greater */
    case 0x0062: JSR(c, 0x252E, 0xC108AC); break; /* actor_script_if_no_hero_class_1 */
    case 0x0064: JSR(c, 0x252E, 0xC10B23); break; /* actor_script_if_no_ally_class_1 */
    case 0x0066: JSR(c, 0x252E, 0xC10DB1); break; /* actor_script_if_no_monster_class_1 */
    case 0x0068: JSR(c, 0x252E, 0xC11195); break; /* actor_script_if_not_current_equal_class_1_op_34 */
    case 0x006A: JSR(c, 0x252E, 0xC11286); break; /* actor_script_if_not_second_equal_class_1_op_35 */
    case 0x006C: JSR(c, 0x252E, 0xC11899); break; /* actor_script_explicit_slot_distance_equal_class_1 */
    case 0x006E: JSR(c, 0x252E, 0xC108F3); break; /* actor_script_if_no_hero_class_2 */
    case 0x0070: JSR(c, 0x252E, 0xC10B6A); break; /* actor_script_if_no_ally_class_2 */
    case 0x0072: JSR(c, 0x252E, 0xC10DF8); break; /* actor_script_if_no_monster_class_2 */
    case 0x0074: JSR(c, 0x252E, 0xC111AA); break; /* actor_script_if_not_current_equal_class_2_op_3a */
    case 0x0076: JSR(c, 0x252E, 0xC1129B); break; /* actor_script_if_not_second_equal_class_2_op_3b */
    case 0x0078: JSR(c, 0x252E, 0xC118C4); break; /* actor_script_explicit_slot_distance_equal_class_2 */
    case 0x007A: JSR(c, 0x252E, 0xC1093A); break; /* actor_script_if_no_hero_class_4 */
    case 0x007C: JSR(c, 0x252E, 0xC10BB1); break; /* actor_script_if_no_ally_class_4 */
    case 0x007E: JSR(c, 0x252E, 0xC10E3F); break; /* actor_script_if_no_monster_class_4 */
    case 0x0080: JSR(c, 0x252E, 0xC111BF); break; /* actor_script_if_not_current_equal_class_4_op_40 */
    case 0x0082: JSR(c, 0x252E, 0xC112B0); break; /* actor_script_if_not_second_equal_class_4_op_41 */
    case 0x0084: JSR(c, 0x252E, 0xC118EF); break; /* actor_script_explicit_slot_distance_equal_class_4 */
    case 0x0086: JSR(c, 0x252E, 0xC10981); break; /* actor_script_if_no_hero_class_8 */
    case 0x0088: JSR(c, 0x252E, 0xC10BF8); break; /* actor_script_if_no_ally_class_8 */
    case 0x008A: JSR(c, 0x252E, 0xC10E86); break; /* actor_script_if_no_monster_class_8 */
    case 0x008C: JSR(c, 0x252E, 0xC111D4); break; /* actor_script_if_not_current_equal_class_8_op_46 */
    case 0x008E: JSR(c, 0x252E, 0xC112C5); break; /* actor_script_if_not_second_equal_class_8_op_47 */
    case 0x0090: JSR(c, 0x252E, 0xC1191A); break; /* actor_script_explicit_slot_distance_equal_class_8 */
    case 0x0092: JSR(c, 0x252E, 0xC10A01); break; /* actor_script_if_no_hero_within_class_2 */
    case 0x0094: JSR(c, 0x252E, 0xC10C41); break; /* actor_script_if_no_ally_within_class_2 */
    case 0x0096: JSR(c, 0x252E, 0xC10ECF); break; /* actor_script_if_no_monster_within_class_2 */
    case 0x0098: JSR(c, 0x252E, 0xC111E9); break; /* actor_script_if_not_current_within_class_2_op_4c */
    case 0x009A: JSR(c, 0x252E, 0xC112DA); break; /* actor_script_if_not_second_within_class_2_op_4d */
    case 0x009C: JSR(c, 0x252E, 0xC10A4A); break; /* actor_script_if_no_hero_within_class_4 */
    case 0x009E: JSR(c, 0x252E, 0xC10C8A); break; /* actor_script_if_no_ally_within_class_4 */
    case 0x00A0: JSR(c, 0x252E, 0xC10F18); break; /* actor_script_if_no_monster_within_class_4 */
    case 0x00A2: JSR(c, 0x252E, 0xC11200); break; /* actor_script_if_not_current_within_class_4_op_51 */
    case 0x00A4: JSR(c, 0x252E, 0xC112F1); break; /* actor_script_if_not_second_within_class_4_op_52 */
    case 0x00A6: JSR(c, 0x252E, 0xC10A93); break; /* actor_script_if_no_hero_within_class_8 */
    case 0x00A8: JSR(c, 0x252E, 0xC10CD3); break; /* actor_script_if_no_ally_within_class_8 */
    case 0x00AA: JSR(c, 0x252E, 0xC10F61); break; /* actor_script_if_no_monster_within_class_8 */
    case 0x00AC: JSR(c, 0x252E, 0xC11217); break; /* actor_script_if_not_current_within_class_8_op_56 */
    case 0x00AE: JSR(c, 0x252E, 0xC11308); break; /* actor_script_if_not_second_within_class_8_op_57 */
    case 0x00B0: JSR(c, 0x252E, 0xC10ADC); break; /* actor_script_if_no_hero_on_screen */
    case 0x00B2: JSR(c, 0x252E, 0xC1122E); break; /* actor_script_if_not_current_within_class_48_op_59 */
    case 0x00B4: JSR(c, 0x252E, 0xC11245); break; /* actor_script_if_not_current_distance_bits_class_16_op_5a */
    case 0x00B6: JSR(c, 0x252E, 0xC1125A); break; /* actor_script_if_not_second_within_class_48_op_5b */
    case 0x00B8: JSR(c, 0x252E, 0xC11271); break; /* actor_script_if_not_second_distance_bits_class_16_op_5c */
    case 0x00BA: JSR(c, 0x252E, 0xC11367); break; /* actor_script_set_current_target_hero_beyond_class_8 */
    case 0x00BC: JSR(c, 0x252E, 0xC11515); break; /* actor_script_set_second_target_hero_beyond_class_8 */
    case 0x00BE: JSR(c, 0x252E, 0xC12194); break; /* actor_script_if_reference_outside_rectangle */
    case 0x00C0: JSR(c, 0x252E, 0xC121DD); break; /* actor_script_if_reference_inside_rectangle */
    case 0x00C2: JSR(c, 0x252E, 0xC11FC8); break; /* actor_script_apply_selected_effect_to_current_target */
    case 0x00C4: JSR(c, 0x252E, 0xC11CB0); break; /* actor_script_controller_distance_gate */
    case 0x00C6: JSR(c, 0x252E, 0xC106FD); break; /* actor_script_if_no_lane_hero_vertical */
    case 0x00C8: JSR(c, 0x252E, 0xC1078D); break; /* actor_script_if_no_lane_raw_e006_vertical */
    case 0x00CA: JSR(c, 0x252E, 0xC1081D); break; /* actor_script_if_no_lane_monster_vertical */
    case 0x00CC: JSR(c, 0x252E, 0xC10F71); break; /* actor_script_if_not_current_lane_mask_f3_within_8_op_66 */
    case 0x00CE: JSR(c, 0x252E, 0xC1102B); break; /* actor_script_if_not_second_lane_mask_f3_within_8_op_67 */
    case 0x00D0: JSR(c, 0x252E, 0xC10F90); break; /* actor_script_if_not_current_lane_mask_f3_within_4_op_68 */
    case 0x00D2: JSR(c, 0x252E, 0xC1104A); break; /* actor_script_if_not_second_lane_mask_f3_within_4_op_69 */
    case 0x00D4: JSR(c, 0x252E, 0xC10FAF); break; /* actor_script_if_not_current_lane_mask_f3_within_48_op_6a */
    case 0x00D6: JSR(c, 0x252E, 0xC11069); break; /* actor_script_if_not_second_lane_mask_f3_within_48_op_6b */
    case 0x00D8: JSR(c, 0x252E, 0xC10745); break; /* actor_script_if_no_lane_hero_horizontal */
    case 0x00DA: JSR(c, 0x252E, 0xC107D5); break; /* actor_script_if_no_lane_raw_e006_horizontal */
    case 0x00DC: JSR(c, 0x252E, 0xC10865); break; /* actor_script_if_no_lane_monster_horizontal */
    case 0x00DE: JSR(c, 0x252E, 0xC10FCE); break; /* actor_script_if_not_current_lane_mask_fc_within_8_op_6f */
    case 0x00E0: JSR(c, 0x252E, 0xC11088); break; /* actor_script_if_not_second_lane_mask_fc_within_8_op_70 */
    case 0x00E2: JSR(c, 0x252E, 0xC10FED); break; /* actor_script_if_not_current_lane_mask_fc_within_4_op_71 */
    case 0x00E4: JSR(c, 0x252E, 0xC110A7); break; /* actor_script_if_not_second_lane_mask_fc_within_4_op_72 */
    case 0x00E6: JSR(c, 0x252E, 0xC1100C); break; /* actor_script_if_not_current_lane_mask_fc_within_48_op_73 */
    case 0x00E8: JSR(c, 0x252E, 0xC110C6); break; /* actor_script_if_not_second_lane_mask_fc_within_48_op_74 */
    case 0x00EA: JSR(c, 0x252E, 0xC110E5); break; /* actor_script_if_not_current_direction_bits_mask_08_op_75 */
    case 0x00EC: JSR(c, 0x252E, 0xC1113D); break; /* actor_script_if_not_second_direction_bits_mask_03_op_76 */
    case 0x00EE: JSR(c, 0x252E, 0xC110FB); break; /* actor_script_if_not_current_direction_bits_mask_04_op_77 */
    case 0x00F0: JSR(c, 0x252E, 0xC11153); break; /* actor_script_if_not_second_direction_bits_mask_03_op_78 */
    case 0x00F2: JSR(c, 0x252E, 0xC11111); break; /* actor_script_if_not_current_direction_bits_mask_02_op_79 */
    case 0x00F4: JSR(c, 0x252E, 0xC11169); break; /* actor_script_if_not_second_direction_bits_mask_03_op_7a */
    case 0x00F6: JSR(c, 0x252E, 0xC11127); break; /* actor_script_if_not_current_direction_bits_mask_01_op_7b */
    case 0x00F8: JSR(c, 0x252E, 0xC1117F); break; /* actor_script_if_not_second_direction_bits_mask_03_op_7c */
    case 0x00FA: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x00FC: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x00FE: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0100: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0102: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0104: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0106: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0108: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x010A: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x010C: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x010E: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0110: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0112: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0114: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0116: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0118: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x011A: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x011C: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x011E: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0120: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0122: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0124: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0126: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0128: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x012A: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x012C: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x012E: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0130: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0132: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0134: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0136: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0138: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x013A: JSR(c, 0x252E, 0xC1214D); break; /* actor_script_if_saved_position_same */
    case 0x013C: JSR(c, 0x252E, 0xC12168); break; /* actor_script_if_saved_position_changed */
    case 0x013E: JSR(c, 0x252E, 0xC12183); break; /* actor_script_save_current_position */
    case 0x0140: JSR(c, 0x252E, 0xC114C5); break; /* actor_script_current_target_clear */
    case 0x0142: JSR(c, 0x252E, 0xC114BC); break; /* actor_script_current_target_copy_second */
    case 0x0144: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0146: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0148: JSR(c, 0x252E, 0xC114AB); break; /* actor_script_current_target_self */
    case 0x014A: JSR(c, 0x252E, 0xC1131F); break; /* actor_script_set_current_target_hero_class_1 */
    case 0x014C: JSR(c, 0x252E, 0xC113AF); break; /* actor_script_set_current_target_ally_class_1 */
    case 0x014E: JSR(c, 0x252E, 0xC1142D); break; /* actor_script_set_current_target_monster_class_1 */
    case 0x0150: JSR(c, 0x252E, 0xC11331); break; /* actor_script_set_current_target_hero_class_2 */
    case 0x0152: JSR(c, 0x252E, 0xC113C1); break; /* actor_script_set_current_target_ally_class_2 */
    case 0x0154: JSR(c, 0x252E, 0xC1143F); break; /* actor_script_set_current_target_monster_class_2 */
    case 0x0156: JSR(c, 0x252E, 0xC11343); break; /* actor_script_set_current_target_hero_class_4 */
    case 0x0158: JSR(c, 0x252E, 0xC113D3); break; /* actor_script_set_current_target_ally_class_4 */
    case 0x015A: JSR(c, 0x252E, 0xC11451); break; /* actor_script_set_current_target_monster_class_4 */
    case 0x015C: JSR(c, 0x252E, 0xC11355); break; /* actor_script_set_current_target_hero_class_8 */
    case 0x015E: JSR(c, 0x252E, 0xC113E5); break; /* actor_script_set_current_target_ally_class_8 */
    case 0x0160: JSR(c, 0x252E, 0xC11463); break; /* actor_script_set_current_target_monster_class_8 */
    case 0x0162: JSR(c, 0x252E, 0xC11379); break; /* actor_script_set_current_target_hero_within_class_2 */
    case 0x0164: JSR(c, 0x252E, 0xC113F7); break; /* actor_script_set_current_target_ally_within_class_2 */
    case 0x0166: JSR(c, 0x252E, 0xC11475); break; /* actor_script_set_current_target_monster_within_class_2 */
    case 0x0168: JSR(c, 0x252E, 0xC1138B); break; /* actor_script_set_current_target_hero_within_class_4 */
    case 0x016A: JSR(c, 0x252E, 0xC11409); break; /* actor_script_set_current_target_ally_within_class_4 */
    case 0x016C: JSR(c, 0x252E, 0xC11487); break; /* actor_script_set_current_target_monster_within_class_4 */
    case 0x016E: JSR(c, 0x252E, 0xC1139D); break; /* actor_script_set_current_target_hero_within_class_8 */
    case 0x0170: JSR(c, 0x252E, 0xC1141B); break; /* actor_script_set_current_target_ally_within_class_8 */
    case 0x0172: JSR(c, 0x252E, 0xC11499); break; /* actor_script_set_current_target_monster_within_class_8 */
    case 0x0174: JSR(c, 0x252E, 0xC120A4); break; /* actor_script_if_word_field_mask_nonzero */
    case 0x0176: JSR(c, 0x252E, 0xC120BE); break; /* actor_script_if_word_field_mask_zero */
    case 0x0178: JSR(c, 0x252E, 0xC120D8); break; /* actor_script_if_word_field_less */
    case 0x017A: JSR(c, 0x252E, 0xC120F2); break; /* actor_script_if_word_field_greater */
    case 0x017C: JSR(c, 0x252E, 0xC11B0E); break; /* actor_script_command_c1_current_forward_high_code */
    case 0x017E: JSR(c, 0x252E, 0xC11B51); break; /* actor_script_command_c1_current_reverse_high_code */
    case 0x0180: JSR(c, 0x252E, 0xC1164F); break; /* actor_script_clear_second_target */
    case 0x0182: JSR(c, 0x252E, 0xC11646); break; /* actor_script_copy_current_to_second_target */
    case 0x0184: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0186: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x0188: JSR(c, 0x252E, 0xC11635); break; /* actor_script_set_second_target_self */
    case 0x018A: JSR(c, 0x252E, 0xC114CD); break; /* actor_script_set_second_target_hero_class_1 */
    case 0x018C: JSR(c, 0x252E, 0xC1155D); break; /* actor_script_set_second_target_ally_class_1 */
    case 0x018E: JSR(c, 0x252E, 0xC115DB); break; /* actor_script_set_second_target_monster_class_1 */
    case 0x0190: JSR(c, 0x252E, 0xC114DF); break; /* actor_script_set_second_target_hero_class_2 */
    case 0x0192: JSR(c, 0x252E, 0xC1156F); break; /* actor_script_set_second_target_ally_class_2 */
    case 0x0194: JSR(c, 0x252E, 0xC115ED); break; /* actor_script_set_second_target_monster_class_2 */
    case 0x0196: JSR(c, 0x252E, 0xC114F1); break; /* actor_script_set_second_target_hero_class_4 */
    case 0x0198: JSR(c, 0x252E, 0xC11581); break; /* actor_script_set_second_target_ally_class_4 */
    case 0x019A: JSR(c, 0x252E, 0xC115FF); break; /* actor_script_set_second_target_monster_class_4 */
    case 0x019C: JSR(c, 0x252E, 0xC11503); break; /* actor_script_set_second_target_hero_class_8 */
    case 0x019E: JSR(c, 0x252E, 0xC11593); break; /* actor_script_set_second_target_ally_class_8 */
    case 0x01A0: JSR(c, 0x252E, 0xC11611); break; /* actor_script_set_second_target_monster_class_8 */
    case 0x01A2: JSR(c, 0x252E, 0xC11527); break; /* actor_script_set_second_target_hero_within_class_2 */
    case 0x01A4: JSR(c, 0x252E, 0xC115A5); break; /* actor_script_set_second_target_ally_within_class_2 */
    case 0x01A6: JSR(c, 0x252E, 0xC11623); break; /* actor_script_set_second_target_monster_within_class_2 */
    case 0x01A8: JSR(c, 0x252E, 0xC11539); break; /* actor_script_set_second_target_hero_within_class_4 */
    case 0x01AA: JSR(c, 0x252E, 0xC115B7); break; /* actor_script_set_second_target_ally_within_class_4 */
    case 0x01AC: JSR(c, 0x252E, 0xC10D20); break; /* actor_script_if_no_ally_below_class_32_or_select_current */
    case 0x01AE: JSR(c, 0x252E, 0xC1154B); break; /* actor_script_set_second_target_hero_within_class_8 */
    case 0x01B0: JSR(c, 0x252E, 0xC115C9); break; /* actor_script_set_second_target_ally_within_class_8 */
    case 0x01B2: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x01B4: JSR(c, 0x252E, 0xC1210E); break; /* actor_script_byte_field_or */
    case 0x01B6: JSR(c, 0x252E, 0xC12124); break; /* actor_script_byte_field_and */
    case 0x01B8: JSR(c, 0x252E, 0xC1213A); break; /* actor_script_byte_field_set */
    case 0x01BA: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x01BC: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x01BE: JSR(c, 0x252E, 0xC11D74); break; /* actor_script_command_02_clear_flag_if_gauge_zero */
    case 0x01C0: JSR(c, 0x252E, 0xC11C8E); break; /* actor_script_write_hop_command */
    case 0x01C2: JSR(c, 0x252E, 0xC11D52); break; /* actor_script_command_01 */
    case 0x01C4: JSR(c, 0x252E, 0xC11E02); break; /* actor_script_write_pose_command */
    case 0x01C6: JSR(c, 0x252E, 0xC11C24); break; /* actor_script_command_c1_from_velocity_and_native_mask */
    case 0x01C8: JSR(c, 0x252E, 0xC119FE); break; /* actor_script_command_c1_current_forward_low_nibble */
    case 0x01CA: JSR(c, 0x252E, 0xC11A40); break; /* actor_script_command_c1_second_forward_low_nibble */
    case 0x01CC: JSR(c, 0x252E, 0xC11A82); break; /* actor_script_command_c1_current_reverse_low_nibble */
    case 0x01CE: JSR(c, 0x252E, 0xC11AC8); break; /* actor_script_command_c1_second_reverse_low_nibble */
    case 0x01D0: JSR(c, 0x252E, 0xC11D5C); break; /* actor_script_command_02_copy_field_1c0_if_gauge_zero */
    case 0x01D2: JSR(c, 0x252E, 0xC11E47); break; /* actor_script_cast_single_second_target */
    case 0x01D4: JSR(c, 0x252E, 0xC11E98); break; /* actor_script_cast_group_from_fixed_first_candidate */
    case 0x01D6: JSR(c, 0x252E, 0xC11F66); break; /* actor_script_command_c0_quantized_low_x */
    case 0x01D8: JSR(c, 0x252E, 0xC11DAA); break; /* actor_script_command_03 */
    case 0x01DA: JSR(c, 0x252E, 0xC11F37); break; /* actor_script_write_command_43 */
    case 0x01DC: JSR(c, 0x252E, 0xC11DF8); break; /* actor_script_write_command_04 */
    case 0x01DE: JSR(c, 0x252E, 0xC11F4B); break; /* actor_script_write_command_81 */
    case 0x01E0: JSR(c, 0x252E, 0xC11FD1); break; /* actor_script_current_target_from_literal_byte */
    case 0x01E2: JSR(c, 0x252E, 0xC11FDE); break; /* actor_script_second_target_from_literal_byte */
    case 0x01E4: JSR(c, 0x252E, 0xC12226); break; /* actor_script_compare_shared_charge_stage */
    case 0x01E6: JSR(c, 0x252E, 0xC11DCD); break; /* actor_script_command_06_set_flag_if_global_byte */
    case 0x01E8: JSR(c, 0x252E, 0xC11DB4); break; /* actor_script_command_07_clear_flag_if_set */
    case 0x01EA: JSR(c, 0x252E, 0xC10D63); break; /* actor_script_if_visible_actor_count_above_byte */
    case 0x01EC: JSR(c, 0x252E, 0xC11CFF); break; /* actor_script_controller_near_distance_gate */
    case 0x01EE: JSR(c, 0x252E, 0xC11F98); break; /* actor_script_command_82_two_arguments */
    case 0x01F0: JSR(c, 0x252E, 0xC10100); break; /* restart_actor_program_on_script_error */
    case 0x01F2: JSR(c, 0x252E, 0xC119F1); break; /* actor_script_set_field_19b_from_byte */
    case 0x01F4: JSR(c, 0x252E, 0xC11D8E); break; /* actor_script_command_02_argument_if_gauge_zero */
    case 0x01F6: JSR(c, 0x252E, 0xC11657); break; /* actor_script_copy_variable_zero_to_charge_stage */
    case 0x01F8: JSR(c, 0x252E, 0xC11673); break; /* actor_script_toggle_flash_and_refresh_appearance */
    case 0x01FA: JSR(c, 0x252E, 0xC11B98); break; /* actor_script_command_c1_current_forward_high_nibble */
    case 0x01FC: JSR(c, 0x252E, 0xC11BDC); break; /* actor_script_command_c1_current_reverse_high_nibble */
    case 0x01FE: JSR(c, 0x252E, 0xC102B7); break; /* actor_script_call */
    default: JSR(c, 0x252E, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x2257 + ((value2 & 0xFF) << 1))));
    }
    r->sp += 3;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1251A, SOM_RTS, "gen", dispatch_actor_script_opcode, 0, L_A | L_B | L_Y | L_V, 3, 1, 0, 26, 14)
