.setcpu "65816"
.segment "CODE"
.org $7E7C
.include "ai_command_macros.inc"
ai_pc_2f67:
    ai_set_var2_27 $0004
ai_pc_2f69:
    ai_call_ff $6AE1
ai_pc_2f6c:
    ai_if_pos_same_9d_short $2F6C, $2F74
ai_pc_2f6e:
    ai_pos_save_9f
ai_pc_2f6f:
    ai_move_toward_card_be $0004, $000A
ai_pc_2f72:
    ai_jmp_01_short $2F72, $2F78
ai_pc_2f74:
    ai_pos_save_9f
ai_pc_2f75:
    ai_move_toward_alt_fd $0004, $000A
ai_pc_2f78:
    ai_dec_var2_20
ai_pc_2f79:
    ai_if_var2_nz_04_short $2F79, $2F7E
ai_pc_2f7b:
    ai_jmp_01_long $2F7B, $2F80
ai_pc_2f7e:
    ai_if_tgt_not_within_48_51_short $2F7E, $2F69
ai_pc_2f80:
    ai_ret_00
ai_pc_2f81:
    ai_if_tgt_not_within_48_51_short $2F81, $2F94
ai_pc_2f83:
    ai_call_ff $6AE1
ai_pc_2f86:
    ai_if_pos_same_9d_short $2F86, $2F8E
ai_pc_2f88:
    ai_pos_save_9f
ai_pc_2f89:
    ai_move_away_card_bf $0004, $000A
ai_pc_2f8c:
    ai_jmp_01_short $2F8C, $2F92
ai_pc_2f8e:
    ai_pos_save_9f
ai_pc_2f8f:
    ai_move_away_alt_fe $0004, $000A
ai_pc_2f92:
    ai_jmp_01_short $2F92, $2F81
ai_pc_2f94:
    ai_ret_00
ai_pc_2f95:
    ai_flash_fc
ai_pc_2f96:
    ai_move_away_card_bf $0000, $0000
ai_pc_2f99:
    ai_pose_e2 $0003
ai_pc_2f9b:
    ai_flash_fc
ai_pc_2f9c:
    ai_move_toward_card_be $0000, $0000
ai_pc_2f9f:
    ai_rnd_var3_2c $0004
ai_pc_2fa1:
    ai_if_var3_nz_05_short $2FA1, $2FAB
ai_pc_2fa3:
    ai_move_away_e6 $0007, $0000
ai_pc_2fa6:
    ai_pose_e2 $0004
ai_pc_2fa8:
    ai_move_away_e6 $000B, $0000
ai_pc_2fab:
    ai_ret_00
ai_pc_2fac:
    ai_call_ff $2FDB
ai_pc_2faf:
    ai_rnd_var3_2c $000F
