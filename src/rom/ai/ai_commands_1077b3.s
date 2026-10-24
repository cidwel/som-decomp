.setcpu "65816"
.segment "CODE"
.org $77B3
.include "ai_command_macros.inc"
ai_pc_289e:
    ai_pose_e2 $0005
ai_pc_28a0:
    ai_call_ff $6AE1
ai_pc_28a3:
    ai_pose_e2 $0005
ai_pc_28a5:
    ai_if_word_gt_bd_short $0080, $0002, $0021, $0001, $28A5, $28AE
ai_pc_28ab:
    ai_jmp_01_long $28AB, $28B0
ai_pc_28ae:
    ai_if_tgt_not_within_32_4c_short $28AE, $28A0
ai_pc_28b0:
    ai_pose_e2 $0000
ai_pc_28b2:
    ai_ret_00
ai_pc_28b3:
    ai_move_toward_e4 $0000, $0005
ai_pc_28b6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $28B6, $28CF
ai_pc_28bb:
    ai_rnd_var3_2c $000F
ai_pc_28bd:
    ai_if_var3_nz_05_short $28BD, $28C9
ai_pc_28bf:
    ai_move_toward_e4 $0000, $0000
ai_pc_28c2:
    ai_pose_e2 $0003
ai_pc_28c4:
    ai_move_toward_e4 $0009, $0000
ai_pc_28c7:
    ai_jmp_01_short $28C7, $28CF
ai_pc_28c9:
    ai_move_toward_e4 $0000, $0005
ai_pc_28cc:
    ai_call_ff $6B19
ai_pc_28cf:
    ai_move_toward_e4 $000E, $0000
ai_pc_28d2:
    ai_ret_00
ai_pc_28d3:
    ai_move_toward_e4 $0000, $0005
ai_pc_28d6:
    ai_if_field_gt_30_short $0080, $006D, $0000, $28D6, $28F1
ai_pc_28db:
    ai_rnd_var3_2c $000F
ai_pc_28dd:
    ai_if_var3_nz_05_short $28DD, $28E9
ai_pc_28df:
    ai_move_toward_e4 $0000, $0000
ai_pc_28e2:
    ai_pose_e2 $0003
ai_pc_28e4:
    ai_move_toward_e4 $0009, $0000
ai_pc_28e7:
    ai_jmp_01_short $28E7, $28EF
ai_pc_28e9:
    ai_move_toward_e4 $0000, $0005
ai_pc_28ec:
    ai_call_ff $6B19
ai_pc_28ef:
    ai_jmp_01_short $28EF, $28F4
ai_pc_28f1:
    ai_move_toward_e4 $0000, $0000
ai_pc_28f4:
    ai_ret_00
ai_pc_28f5:
    ai_if_obj_outside_5f_short $0080, $28F5, $2905
ai_pc_28f8:
    ai_rnd_var3_2c $000F
ai_pc_28fa:
    ai_if_var3_ne_0d_short $0001, $28FA, $2905
ai_pc_28fd:
    ai_tgt2_cur_c1
ai_pc_28fe:
    ai_cast_all_ea $0004, $001A
ai_pc_2901:
    ai_tgt2_none_c0
ai_pc_2902:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_2905:
    ai_call_ff $6AE1
ai_pc_2908:
    ai_rnd_var3_2c $0001
ai_pc_290a:
    ai_if_var3_nz_05_short $290A, $291A
ai_pc_290c:
    ai_if_pos_same_9d_short $290C, $2914
ai_pc_290e:
    ai_pos_save_9f
ai_pc_290f:
    ai_move_toward_e4 $0002, $0000
ai_pc_2912:
    ai_jmp_01_short $2912, $2918
ai_pc_2914:
    ai_pos_save_9f
ai_pc_2915:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_2918:
    ai_jmp_01_short $2918, $2926
ai_pc_291a:
    ai_if_pos_same_9d_short $291A, $2922
ai_pc_291c:
    ai_pos_save_9f
ai_pc_291d:
    ai_move_toward_e4 $0001, $0000
ai_pc_2920:
    ai_jmp_01_short $2920, $2926
ai_pc_2922:
    ai_pos_save_9f
ai_pc_2923:
    ai_move_toward_alt_fd $0001, $0000
ai_pc_2926:
    ai_if_tgt_not_within_64_56_short $2926, $2905
ai_pc_2928:
    ai_ret_00
ai_pc_2929:
    ai_call_ff $2951
ai_pc_292c:
    ai_rnd_var3_2c $000F
ai_pc_292e:
    ai_if_var3_nz_05_short $292E, $2935
ai_pc_2930:
    ai_call_ff $690F
ai_pc_2933:
    ai_jmp_01_short $2933, $2949
ai_pc_2935:
    ai_call_ff $6AE1
ai_pc_2938:
    ai_if_tgt_not_within_48_51_short $2938, $293F
ai_pc_293a:
    ai_call_ff $1201
ai_pc_293d:
    ai_jmp_01_short $293D, $2949
ai_pc_293f:
    ai_if_tgt_not_within_64_56_short $293F, $2946
ai_pc_2941:
    ai_call_ff $2956
ai_pc_2944:
    ai_jmp_01_short $2944, $2949
ai_pc_2946:
    ai_call_ff $11EF
ai_pc_2949:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $2949, $292C
ai_pc_294e:
    ai_jmp_01_short $294E, $292C
