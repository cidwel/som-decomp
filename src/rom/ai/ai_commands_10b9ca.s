.setcpu "65816"
.segment "CODE"
.org $B9CA
.include "ai_command_macros.inc"
ai_pc_6ab5:
    ai_rnd_var3_2c $0003
ai_pc_6ab7:
    ai_set_var2_27 $0002
ai_pc_6ab9:
    ai_pos_save_9f
ai_pc_6aba:
    ai_if_var3_nz_05_short $6ABA, $6AC2
ai_pc_6abc:
    ai_hop_e0 $0009, $0001, $000A
ai_pc_6ac0:
    ai_jmp_01_short $6AC0, $6AD8
ai_pc_6ac2:
    ai_if_var3_ne_0d_short $0001, $6AC2, $6ACB
ai_pc_6ac5:
    ai_hop_e0 $000A, $0001, $000A
ai_pc_6ac9:
    ai_jmp_01_short $6AC9, $6AD8
ai_pc_6acb:
    ai_if_var3_ne_0d_short $0002, $6ACB, $6AD4
ai_pc_6ace:
    ai_hop_e0 $0005, $0001, $000A
ai_pc_6ad2:
    ai_jmp_01_short $6AD2, $6AD8
ai_pc_6ad4:
    ai_hop_e0 $0006, $0001, $000A
ai_pc_6ad8:
    ai_if_pos_moved_9e_short $6AD8, $6ADD
ai_pc_6ada:
    ai_jmp_01_long $6ADA, $6AE0
ai_pc_6add:
    ai_dec_var2_20
ai_pc_6ade:
    ai_if_var2_nz_04_short $6ADE, $6AB9
ai_pc_6ae0:
    ai_ret_00
ai_pc_6ae1:
    ai_if_no_hero_48_4e_short $6AE1, $6AF9
ai_pc_6ae3:
    ai_if_no_hero_16_31_short $6AE3, $6AEB
ai_pc_6ae5:
    ai_tgt_within_16_a5
ai_pc_6ae6:
    ai_jmp_01_long $6AE6, $6B0E
