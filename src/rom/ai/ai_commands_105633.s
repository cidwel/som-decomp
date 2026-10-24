.setcpu "65816"
.segment "CODE"
.org $5633
.include "ai_command_macros.inc"
ai_pc_071e:
    ai_pose_e2 $0003
ai_pc_0720:
    ai_call_ff $6AE1
ai_pc_0723:
    ai_pose_e2 $0003
ai_pc_0725:
    ai_if_word_gt_bd_short $0080, $0002, $00C7, $0000, $0725, $072E
ai_pc_072b:
    ai_jmp_01_long $072B, $0730
ai_pc_072e:
    ai_if_tgt_not_within_48_51_short $072E, $0720
ai_pc_0730:
    ai_move_toward_e4 $000B, $0000
ai_pc_0733:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_0737:
    ai_hop_e0 $0001, $0000, $001E
ai_pc_073b:
    ai_ret_00
ai_pc_073c:
    ai_pose_e2 $0003
ai_pc_073e:
    ai_set_var1_26 $0000
ai_pc_0740:
    ai_if_tgt_not_within_32_4c_short $0740, $0760
ai_pc_0742:
    ai_pose_e2 $0003
ai_pc_0744:
    ai_if_word_gt_bd_short $0080, $0002, $0064, $0000, $0744, $0751
ai_pc_074a:
    ai_set_var1_26 $0001
ai_pc_074c:
    ai_jmp_01_long $074C, $0760
