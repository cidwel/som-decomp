.setcpu "65816"
.segment "CODE"
.org $5666
.include "ai_command_macros.inc"
ai_pc_0751:
    ai_if_field_lt_2f_short $0080, $002C, $00FF, $0751, $075E
ai_pc_0756:
    ai_call_ff $6AE1
ai_pc_0759:
    ai_set_var1_26 $0002
ai_pc_075b:
    ai_jmp_01_long $075B, $0760
ai_pc_075e:
    ai_jmp_01_short $075E, $0740
ai_pc_0760:
    ai_move_toward_e4 $000B, $0000
ai_pc_0763:
    ai_if_obj_outside_5f_short $0080, $0763, $0780
ai_pc_0766:
    ai_move_toward_e4 $0003, $0000
ai_pc_0769:
    ai_if_var1_nz_03_short $0769, $0775
ai_pc_076b:
    ai_tgt2_cur_c1
ai_pc_076c:
    ai_cast_e9 $0001, $0006
ai_pc_076f:
    ai_tgt2_none_c0
ai_pc_0770:
    ai_move_toward_e4 $0000, $00B4
ai_pc_0773:
    ai_jmp_01_short $0773, $0780
ai_pc_0775:
    ai_if_var1_ne_0b_short $0001, $0775, $0780
ai_pc_0778:
    ai_tgt2_cur_c1
ai_pc_0779:
    ai_cast_e9 $0001, $0008
ai_pc_077c:
    ai_tgt2_none_c0
ai_pc_077d:
    ai_move_toward_e4 $0000, $00B4
ai_pc_0780:
    ai_hop_e0 $0002, $0000, $001E
ai_pc_0784:
    ai_hop_e0 $0001, $0000, $001E
ai_pc_0788:
    ai_move_toward_e4 $0000, $0005
ai_pc_078b:
    ai_set_var1_26 $0000
ai_pc_078d:
    ai_ret_00
ai_pc_078e:
    ai_call_ff $6AE1
ai_pc_0791:
    ai_if_pos_same_9d_short $0791, $0799
ai_pc_0793:
    ai_pos_save_9f
ai_pc_0794:
    ai_move_toward_card_be $0004, $0000
ai_pc_0797:
    ai_jmp_01_short $0797, $079D
ai_pc_0799:
    ai_pos_save_9f
ai_pc_079a:
    ai_move_toward_alt_fd $0004, $0000
ai_pc_079d:
    ai_if_tgt_not_within_16_34_short $079D, $078E
ai_pc_079f:
    ai_ret_00
