.setcpu "65816"
.segment "CODE"
.org $8843
.include "ai_command_macros.inc"
ai_pc_392e:
    ai_pose_e2 $0000
ai_pc_3930:
    ai_pose_e2 $0001
ai_pc_3932:
    ai_pose_e2 $0001
ai_pc_3934:
    ai_ret_00
ai_pc_3935:
    ai_move_toward_e4 $0000, $0005
ai_pc_3938:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3938, $3948
ai_pc_393d:
    ai_move_toward_e4 $0000, $0005
ai_pc_3940:
    ai_flash_fc
ai_pc_3941:
    ai_call_ff $6B19
ai_pc_3944:
    ai_flash_fc
ai_pc_3945:
    ai_move_toward_e4 $0000, $0005
ai_pc_3948:
    ai_call_ff $39C2
ai_pc_394b:
    ai_ret_00
ai_pc_394c:
    ai_move_toward_e4 $0000, $0000
ai_pc_394f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $394F, $3970
ai_pc_3954:
    ai_call_ff $6AE1
ai_pc_3957:
    ai_if_pos_same_9d_short $3957, $395F
ai_pc_3959:
    ai_pos_save_9f
ai_pc_395a:
    ai_move_toward_card_be $0002, $0005
ai_pc_395d:
    ai_jmp_01_short $395D, $3963
ai_pc_395f:
    ai_pos_save_9f
ai_pc_3960:
    ai_move_toward_alt_fd $0002, $0005
ai_pc_3963:
    ai_if_tgt_not_within_32_4c_short $3963, $3954
ai_pc_3965:
    ai_move_toward_e4 $0000, $0005
ai_pc_3968:
    ai_flash_fc
ai_pc_3969:
    ai_call_ff $6B19
ai_pc_396c:
    ai_flash_fc
ai_pc_396d:
    ai_move_toward_e4 $0000, $0005
ai_pc_3970:
    ai_call_ff $39C2
ai_pc_3973:
    ai_ret_00
ai_pc_3974:
    ai_move_toward_e4 $0000, $0005
ai_pc_3977:
    ai_if_field_gt_30_short $0080, $006D, $0000, $3977, $39A0
ai_pc_397c:
    ai_if_field_gt_30_short $0080, $001D, $0000, $397C, $3989
ai_pc_3981:
    ai_tgt2_self_c4
ai_pc_3982:
    ai_cast_e9 $0003, $0027
ai_pc_3985:
    ai_tgt2_none_c0
ai_pc_3986:
    ai_turn_facing_e3 $0000, $00B4
ai_pc_3989:
    ai_move_toward_e4 $0000, $0005
ai_pc_398c:
    ai_rnd_var3_2c $000F
ai_pc_398e:
    ai_if_var3_nz_05_short $398E, $399D
ai_pc_3990:
    ai_pose_e2 $0004
ai_pc_3992:
    ai_move_toward_e4 $0008, $0005
ai_pc_3995:
    ai_move_away_e6 $0000, $000F
ai_pc_3998:
    ai_move_toward_e4 $0000, $000F
ai_pc_399b:
    ai_jmp_01_short $399B, $39A0
ai_pc_399d:
    ai_call_ff $6B19
ai_pc_39a0:
    ai_rnd_var3_2c $0007
ai_pc_39a2:
    ai_if_var3_nz_05_short $39A2, $39AC
ai_pc_39a4:
    ai_hop_e0 $0002, $0000, $000F
ai_pc_39a8:
    ai_hop_e0 $0001, $0000, $000F
ai_pc_39ac:
    ai_move_toward_e4 $0000, $0005
ai_pc_39af:
    ai_ret_00
ai_pc_39b0:
    ai_call_ff $6AE1
ai_pc_39b3:
    ai_if_pos_same_9d_short $39B3, $39BB
ai_pc_39b5:
    ai_pos_save_9f
ai_pc_39b6:
    ai_move_toward_card_be $0004, $000F
ai_pc_39b9:
    ai_jmp_01_short $39B9, $39BF
ai_pc_39bb:
    ai_pos_save_9f
ai_pc_39bc:
    ai_move_toward_alt_fd $0004, $000F
ai_pc_39bf:
    ai_if_tgt_not_within_64_56_short $39BF, $39B0
ai_pc_39c1:
    ai_ret_00
ai_pc_39c2:
    ai_if_tgt_not_within_48_51_short $39C2, $39E7
ai_pc_39c4:
    ai_call_ff $6AE1
ai_pc_39c7:
    ai_if_pos_same_9d_short $39C7, $39CF
ai_pc_39c9:
    ai_pos_save_9f
ai_pc_39ca:
    ai_move_away_card_bf $0004, $000F
ai_pc_39cd:
    ai_jmp_01_short $39CD, $39D3
ai_pc_39cf:
    ai_pos_save_9f
ai_pc_39d0:
    ai_move_away_alt_fe $0004, $000F
ai_pc_39d3:
    ai_if_tgt_not_within_32_4c_short $39D3, $39E5
ai_pc_39d5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $39D5, $39E5
ai_pc_39da:
    ai_move_toward_e4 $0000, $0005
ai_pc_39dd:
    ai_flash_fc
ai_pc_39de:
    ai_call_ff $6B19
ai_pc_39e1:
    ai_flash_fc
ai_pc_39e2:
    ai_move_toward_e4 $0000, $0005
ai_pc_39e5:
    ai_jmp_01_short $39E5, $39C2
ai_pc_39e7:
    ai_ret_00
ai_pc_39e8:
    ai_call_ff $3A10
ai_pc_39eb:
    ai_rnd_var3_2c $000F
ai_pc_39ed:
    ai_if_var3_nz_05_short $39ED, $39F4
ai_pc_39ef:
    ai_call_ff $675B
ai_pc_39f2:
    ai_jmp_01_short $39F2, $3A08
ai_pc_39f4:
    ai_call_ff $6AE1
ai_pc_39f7:
    ai_if_tgt_not_within_48_51_short $39F7, $39FE
ai_pc_39f9:
    ai_call_ff $3A30
ai_pc_39fc:
    ai_jmp_01_short $39FC, $3A08
ai_pc_39fe:
    ai_if_tgt_not_within_64_56_short $39FE, $3A05
ai_pc_3a00:
    ai_call_ff $3A66
ai_pc_3a03:
    ai_jmp_01_short $3A03, $3A08
ai_pc_3a05:
    ai_call_ff $3A66
ai_pc_3a08:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $3A08, $39EB
ai_pc_3a0d:
    ai_jmp_01_short $3A0D, $39EB
