.setcpu "65816"
.segment "CODE"
.org $A94A
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_5a35:
    ai_call_ff $590F
ai_pc_5a38:
    ai_if_obj_outside_5f_long $0081, $5A38, $5B01
ai_pc_5a3c:
    ai_if_field_gt_30_long $0080, $002C, $00FE, $5A3C, $5AFE
ai_pc_5a42:
    ai_if_field_gt_30_short $0080, $0064, $0000, $5A42, $5A81
ai_pc_5a47:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5A47, $5A7E
ai_pc_5a4c:
    ai_if_tgt_not_within_64_56_short $5A4C, $5A6F
ai_pc_5a4e:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5A4E, $5A6A
ai_pc_5a53:
    ai_if_charge_set_f2_short $0000, $5A53, $5A65
ai_pc_5a56:
    ai_rnd_var2_2b $000F
ai_pc_5a58:
    ai_call_ff $5B21
ai_pc_5a5b:
    ai_move_toward_e4 $0003, $0005
ai_pc_5a5e:
    ai_swing_plain_df
ai_pc_5a5f:
    ai_move_toward_e4 $0013, $0000
ai_pc_5a62:
    ai_charge_start_f3
ai_pc_5a63:
    ai_jmp_01_short $5A63, $5A68
ai_pc_5a65:
    ai_call_ff $5B62
ai_pc_5a68:
    ai_jmp_01_short $5A68, $5A6D
ai_pc_5a6a:
    ai_call_ff $5B62
ai_pc_5a6d:
    ai_jmp_01_short $5A6D, $5A7C
ai_pc_5a6f:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5A6F, $5A79
ai_pc_5a74:
    ai_call_ff $5B03
ai_pc_5a77:
    ai_jmp_01_short $5A77, $5A7C
ai_pc_5a79:
    ai_move_toward_e4 $0000, $0005
ai_pc_5a7c:
    ai_jmp_01_short $5A7C, $5A47
ai_pc_5a7e:
    ai_jmp_01_long $5A7E, $5AFB
ai_pc_5a81:
    ai_if_field_gt_30_short $0080, $0064, $0002, $5A81, $5ABC
ai_pc_5a86:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5A86, $5ABA
ai_pc_5a8b:
    ai_if_tgt_not_within_64_56_short $5A8B, $5AAB
ai_pc_5a8d:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5A8D, $5AA6
ai_pc_5a92:
    ai_if_charge_set_f2_short $0000, $5A92, $5AA1
ai_pc_5a95:
    ai_rnd_var2_2b $000F
ai_pc_5a97:
    ai_call_ff $5B85
ai_pc_5a9a:
    ai_move_toward_e4 $0003, $0005
ai_pc_5a9d:
    ai_swing_plain_df
ai_pc_5a9e:
    ai_charge_start_f3
ai_pc_5a9f:
    ai_jmp_01_short $5A9F, $5AA4
ai_pc_5aa1:
    ai_call_ff $5BC6
ai_pc_5aa4:
    ai_jmp_01_short $5AA4, $5AA9
ai_pc_5aa6:
    ai_call_ff $5BC6
ai_pc_5aa9:
    ai_jmp_01_short $5AA9, $5AB8
ai_pc_5aab:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5AAB, $5AB5
ai_pc_5ab0:
    ai_call_ff $5B03
ai_pc_5ab3:
    ai_jmp_01_short $5AB3, $5AB8
ai_pc_5ab5:
    ai_move_toward_e4 $0000, $0005
ai_pc_5ab8:
    ai_jmp_01_short $5AB8, $5A86
ai_pc_5aba:
    ai_jmp_01_short $5ABA, $5AFB
ai_pc_5abc:
    ai_if_field_gt_30_short $0080, $002C, $00FE, $5ABC, $5AFB
ai_pc_5ac1:
    ai_if_tgt_not_within_64_56_short $5AC1, $5AEC
ai_pc_5ac3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5AC3, $5AE7
ai_pc_5ac8:
    ai_if_charge_set_f2_short $0000, $5AC8, $5AE2
ai_pc_5acb:
    ai_if_tgt_not_lane_v64_66_short $5ACB, $5AD4
ai_pc_5acd:
    ai_move_toward_card_be $0003, $0005
ai_pc_5ad0:
    ai_swing_plain_df
ai_pc_5ad1:
    ai_charge_start_f3
ai_pc_5ad2:
    ai_jmp_01_short $5AD2, $5AE0
ai_pc_5ad4:
    ai_if_tgt_not_lane_h64_6f_short $5AD4, $5ADD
ai_pc_5ad6:
    ai_move_toward_card_be $0003, $0005
ai_pc_5ad9:
    ai_swing_plain_df
ai_pc_5ada:
    ai_charge_start_f3
ai_pc_5adb:
    ai_jmp_01_short $5ADB, $5AE0
ai_pc_5add:
    ai_call_ff $593D
ai_pc_5ae0:
    ai_jmp_01_short $5AE0, $5AE5
ai_pc_5ae2:
    ai_call_ff $5BE6
ai_pc_5ae5:
    ai_jmp_01_short $5AE5, $5AEA
ai_pc_5ae7:
    ai_call_ff $5BE6
ai_pc_5aea:
    ai_jmp_01_short $5AEA, $5AF9
ai_pc_5aec:
    ai_if_field_gt_30_short $0080, $006D, $0000, $5AEC, $5AF6
ai_pc_5af1:
    ai_call_ff $5B12
ai_pc_5af4:
    ai_jmp_01_short $5AF4, $5AF9
ai_pc_5af6:
    ai_move_toward_card_be $0000, $0005
ai_pc_5af9:
    ai_jmp_01_short $5AF9, $5ABC
ai_pc_5afb:
    ai_jmp_01_long $5AFB, $5A3C
ai_pc_5afe:
    ai_jmp_01_long $5AFE, $5A38
