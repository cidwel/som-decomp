.setcpu "65816"
.segment "CODE"
.org $4F15
.include "ai_command_macros.inc"
ai_pc_0000:
    ai_call_ff $0043
ai_pc_0003:
    ai_if_word_gt_bd_short $0080, $0002, $0009, $0000, $0003, $000E
ai_pc_0009:
    ai_call_ff $0081
ai_pc_000c:
    ai_jmp_01_short $000C, $003B
ai_pc_000e:
    ai_rnd_var3_2c $0007
ai_pc_0010:
    ai_if_var3_nz_05_short $0010, $0017
ai_pc_0012:
    ai_call_ff $67DF
ai_pc_0015:
    ai_jmp_01_short $0015, $003B
ai_pc_0017:
    ai_call_ff $6AE1
ai_pc_001a:
    ai_if_tgt_not_within_32_4c_short $001A, $0021
ai_pc_001c:
    ai_call_ff $004A
ai_pc_001f:
    ai_jmp_01_short $001F, $003B
ai_pc_0021:
    ai_if_tgt_not_within_48_51_short $0021, $0028
ai_pc_0023:
    ai_call_ff $0063
ai_pc_0026:
    ai_jmp_01_short $0026, $003B
ai_pc_0028:
    ai_if_tgt_not_within_64_56_short $0028, $002F
ai_pc_002a:
    ai_call_ff $0074
ai_pc_002d:
    ai_jmp_01_short $002D, $003B
ai_pc_002f:
    ai_rnd_var3_2c $0005
ai_pc_0031:
    ai_if_var3_nz_05_short $0031, $0038
ai_pc_0033:
    ai_move_toward_e4 $0000, $0000
ai_pc_0036:
    ai_jmp_01_short $0036, $003B
ai_pc_0038:
    ai_call_ff $6902
ai_pc_003b:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $003B, $0003
ai_pc_0040:
    ai_jmp_01_short $0040, $0003
