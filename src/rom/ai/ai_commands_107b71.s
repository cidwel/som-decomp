.setcpu "65816"
.segment "CODE"
.org $7B71
.include "ai_command_macros.inc"
ai_pc_2c5c:
    ai_pose_e2 $0000
ai_pc_2c5e:
    ai_call_ff $6AE1
ai_pc_2c61:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2c64:
    ai_if_word_gt_bd_short $0080, $0002, $0014, $0000, $2C64, $2C6D
ai_pc_2c6a:
    ai_jmp_01_long $2C6A, $2C6F
ai_pc_2c6d:
    ai_if_tgt_not_within_16_34_short $2C6D, $2C5E
ai_pc_2c6f:
    ai_pose_e2 $0002
ai_pc_2c71:
    ai_if_obj_outside_5f_short $0080, $2C71, $2C7C
ai_pc_2c74:
    ai_tgt2_cur_c1
ai_pc_2c75:
    ai_cast_e9 $0001, $0000
ai_pc_2c78:
    ai_tgt2_none_c0
ai_pc_2c79:
    ai_turn_facing_e3 $0000, $00F0
ai_pc_2c7c:
    ai_ret_00
ai_pc_2c7d:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2c80:
    ai_pose_e2 $0002
ai_pc_2c82:
    ai_if_obj_outside_5f_short $0080, $2C82, $2C8D
ai_pc_2c85:
    ai_tgt2_cur_c1
ai_pc_2c86:
    ai_cast_e9 $0001, $0000
ai_pc_2c89:
    ai_tgt2_none_c0
ai_pc_2c8a:
    ai_turn_facing_e3 $0000, $00F0
ai_pc_2c8d:
    ai_ret_00
ai_pc_2c8e:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2c91:
    ai_if_obj_outside_5f_short $0080, $2C91, $2C9F
ai_pc_2c94:
    ai_rnd_var3_2c $0003
ai_pc_2c96:
    ai_if_var3_nz_05_short $2C96, $2C9F
ai_pc_2c98:
    ai_rnd_var3_2c $0003
ai_pc_2c9a:
    ai_if_var3_nz_05_short $2C9A, $2C9F
ai_pc_2c9c:
    ai_call_ff $2CCD
ai_pc_2c9f:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2ca2:
    ai_ret_00
ai_pc_2ca3:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2ca6:
    ai_if_obj_outside_5f_short $0080, $2CA6, $2CB4
ai_pc_2ca9:
    ai_rnd_var3_2c $0007
ai_pc_2cab:
    ai_if_var3_nz_05_short $2CAB, $2CB4
ai_pc_2cad:
    ai_rnd_var3_2c $0007
ai_pc_2caf:
    ai_if_var3_nz_05_short $2CAF, $2CB4
ai_pc_2cb1:
    ai_call_ff $2CCD
ai_pc_2cb4:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2cb7:
    ai_ret_00
ai_pc_2cb8:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2cbb:
    ai_if_obj_outside_5f_short $0080, $2CBB, $2CC9
ai_pc_2cbe:
    ai_rnd_var3_2c $000F
ai_pc_2cc0:
    ai_if_var3_nz_05_short $2CC0, $2CC9
ai_pc_2cc2:
    ai_rnd_var3_2c $000F
ai_pc_2cc4:
    ai_if_var3_nz_05_short $2CC4, $2CC9
ai_pc_2cc6:
    ai_call_ff $2CCD
ai_pc_2cc9:
    ai_turn_facing_e3 $0000, $0005
ai_pc_2ccc:
    ai_ret_00
ai_pc_2ccd:
    ai_pose_e2 $0002
ai_pc_2ccf:
    ai_tgt2_cur_c1
ai_pc_2cd0:
    ai_cast_e9 $0001, $0001
ai_pc_2cd3:
    ai_tgt2_none_c0
ai_pc_2cd4:
    ai_turn_facing_e3 $0000, $00F0
ai_pc_2cd7:
    ai_ret_00
ai_pc_2cd8:
    ai_call_ff $2D07
ai_pc_2cdb:
    ai_rnd_var3_2c $000F
ai_pc_2cdd:
    ai_if_var3_nz_05_short $2CDD, $2CE4
ai_pc_2cdf:
    ai_call_ff $693B
ai_pc_2ce2:
    ai_jmp_01_short $2CE2, $2CFF
ai_pc_2ce4:
    ai_call_ff $6AE1
ai_pc_2ce7:
    ai_if_tgt_not_within_32_4c_short $2CE7, $2CEE
ai_pc_2ce9:
    ai_call_ff $2D0A
ai_pc_2cec:
    ai_jmp_01_short $2CEC, $2CFF
ai_pc_2cee:
    ai_if_tgt_not_within_48_51_short $2CEE, $2CF5
ai_pc_2cf0:
    ai_call_ff $2D11
ai_pc_2cf3:
    ai_jmp_01_short $2CF3, $2CFF
ai_pc_2cf5:
    ai_if_tgt_not_within_64_56_short $2CF5, $2CFC
ai_pc_2cf7:
    ai_call_ff $2D36
ai_pc_2cfa:
    ai_jmp_01_short $2CFA, $2CFF
ai_pc_2cfc:
    ai_call_ff $2D6B
ai_pc_2cff:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2CFF, $2CDB
ai_pc_2d04:
    ai_jmp_01_short $2D04, $2CDB
