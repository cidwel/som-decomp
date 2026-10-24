.setcpu "65816"
.segment "CODE"
.org $63CD
.include "ai_command_macros.inc"
ai_pc_14b8:
    ai_pose_e2 $0000
ai_pc_14ba:
    ai_ret_00
ai_pc_14bb:
    ai_if_tgt_not_within_16_34_short $14BB, $14C2
ai_pc_14bd:
    ai_move_toward_e4 $000E, $0000
ai_pc_14c0:
    ai_jmp_01_short $14C0, $14C5
ai_pc_14c2:
    ai_move_toward_e4 $0000, $0000
ai_pc_14c5:
    ai_if_field_gt_30_short $0080, $006D, $0000, $14C5, $14D5
ai_pc_14ca:
    ai_flash_fc
ai_pc_14cb:
    ai_move_toward_e4 $0000, $0000
ai_pc_14ce:
    ai_call_ff $6B0F
ai_pc_14d1:
    ai_flash_fc
ai_pc_14d2:
    ai_move_toward_e4 $0000, $0005
ai_pc_14d5:
    ai_call_ff $3883
ai_pc_14d8:
    ai_ret_00
ai_pc_14d9:
    ai_move_toward_e4 $0000, $0000
ai_pc_14dc:
    ai_if_field_gt_30_short $0080, $006D, $0000, $14DC, $14EC
ai_pc_14e1:
    ai_flash_fc
ai_pc_14e2:
    ai_move_toward_e4 $0000, $0000
ai_pc_14e5:
    ai_call_ff $6B0F
ai_pc_14e8:
    ai_flash_fc
ai_pc_14e9:
    ai_move_toward_e4 $0000, $0005
ai_pc_14ec:
    ai_call_ff $386F
ai_pc_14ef:
    ai_ret_00
ai_pc_14f0:
    ai_move_toward_e4 $0000, $0000
ai_pc_14f3:
    ai_if_field_gt_30_short $0080, $006D, $0000, $14F3, $1528
ai_pc_14f8:
    ai_if_tgt_not_lane_v64_66_short $14F8, $1502
ai_pc_14fa:
    ai_move_toward_card_be $0000, $0000
ai_pc_14fd:
    ai_call_ff $6B0F
ai_pc_1500:
    ai_jmp_01_short $1500, $1526
ai_pc_1502:
    ai_if_tgt_not_lane_h64_6f_short $1502, $150C
ai_pc_1504:
    ai_move_toward_card_be $0000, $0000
ai_pc_1507:
    ai_call_ff $6B0F
ai_pc_150a:
    ai_jmp_01_short $150A, $1526
ai_pc_150c:
    ai_move_toward_e4 $0000, $0000
ai_pc_150f:
    ai_rnd_var3_2c $000F
ai_pc_1511:
    ai_if_var3_nz_05_short $1511, $1523
ai_pc_1513:
    ai_call_ff $3834
ai_pc_1516:
    ai_flash_fc
ai_pc_1517:
    ai_move_toward_e4 $0000, $0000
ai_pc_151a:
    ai_call_ff $6B0F
ai_pc_151d:
    ai_flash_fc
ai_pc_151e:
    ai_call_ff $3883
ai_pc_1521:
    ai_jmp_01_short $1521, $1526
ai_pc_1523:
    ai_move_toward_e4 $0000, $0000
ai_pc_1526:
    ai_jmp_01_short $1526, $152B
ai_pc_1528:
    ai_move_toward_e4 $0000, $0000
ai_pc_152b:
    ai_ret_00
ai_pc_152c:
    ai_call_ff $153D
ai_pc_152f:
    ai_call_ff $6AE1
ai_pc_1532:
    ai_call_ff $1540
ai_pc_1535:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $1535, $152F
ai_pc_153a:
    ai_jmp_01_short $153A, $152F
