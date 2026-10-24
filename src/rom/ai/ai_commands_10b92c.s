.setcpu "65816"
.segment "CODE"
.org $B92C
.include "ai_command_macros.inc"
ai_pc_6a17:
    ai_set_var2_27 $0004
ai_pc_6a19:
    ai_call_ff $6AE1
ai_pc_6a1c:
    ai_if_pos_same_9d_short $6A1C, $6A24
ai_pc_6a1e:
    ai_pos_save_9f
ai_pc_6a1f:
    ai_move_toward_e4 $0002, $0000
ai_pc_6a22:
    ai_jmp_01_short $6A22, $6A28
ai_pc_6a24:
    ai_pos_save_9f
ai_pc_6a25:
    ai_move_toward_alt_fd $0002, $0000
ai_pc_6a28:
    ai_if_tgt_not_within_64_56_short $6A28, $6A2D
ai_pc_6a2a:
    ai_jmp_01_long $6A2A, $6A30
ai_pc_6a2d:
    ai_dec_var2_20
ai_pc_6a2e:
    ai_if_var2_nz_04_short $6A2E, $6A19
ai_pc_6a30:
    ai_ret_00
ai_pc_6a31:
    ai_rnd_var3_2c $0003
ai_pc_6a33:
    ai_set_var2_27 $0002
ai_pc_6a35:
    ai_pos_save_9f
ai_pc_6a36:
    ai_if_var3_nz_05_short $6A36, $6A3E
ai_pc_6a38:
    ai_hop_e0 $0008, $0004, $000A
ai_pc_6a3c:
    ai_jmp_01_short $6A3C, $6A54
ai_pc_6a3e:
    ai_if_var3_ne_0d_short $0001, $6A3E, $6A47
ai_pc_6a41:
    ai_hop_e0 $0004, $0004, $000A
ai_pc_6a45:
    ai_jmp_01_short $6A45, $6A54
ai_pc_6a47:
    ai_if_var3_ne_0d_short $0002, $6A47, $6A50
ai_pc_6a4a:
    ai_hop_e0 $0001, $0004, $000A
ai_pc_6a4e:
    ai_jmp_01_short $6A4E, $6A54
ai_pc_6a50:
    ai_hop_e0 $0002, $0004, $000A
ai_pc_6a54:
    ai_if_pos_moved_9e_short $6A54, $6A59
ai_pc_6a56:
    ai_jmp_01_long $6A56, $6A5C
ai_pc_6a59:
    ai_dec_var2_20
ai_pc_6a5a:
    ai_if_var2_nz_04_short $6A5A, $6A35
ai_pc_6a5c:
    ai_ret_00
ai_pc_6a5d:
    ai_rnd_var3_2c $0003
ai_pc_6a5f:
    ai_set_var2_27 $0002
ai_pc_6a61:
    ai_pos_save_9f
ai_pc_6a62:
    ai_if_var3_nz_05_short $6A62, $6A6A
ai_pc_6a64:
    ai_hop_e0 $0008, $0001, $000A
ai_pc_6a68:
    ai_jmp_01_short $6A68, $6A80
ai_pc_6a6a:
    ai_if_var3_ne_0d_short $0001, $6A6A, $6A73
ai_pc_6a6d:
    ai_hop_e0 $0004, $0001, $000A
ai_pc_6a71:
    ai_jmp_01_short $6A71, $6A80
ai_pc_6a73:
    ai_if_var3_ne_0d_short $0002, $6A73, $6A7C
ai_pc_6a76:
    ai_hop_e0 $0001, $0001, $000A
ai_pc_6a7a:
    ai_jmp_01_short $6A7A, $6A80
ai_pc_6a7c:
    ai_hop_e0 $0002, $0001, $000A
ai_pc_6a80:
    ai_if_pos_moved_9e_short $6A80, $6A85
ai_pc_6a82:
    ai_jmp_01_long $6A82, $6A88
ai_pc_6a85:
    ai_dec_var2_20
ai_pc_6a86:
    ai_if_var2_nz_04_short $6A86, $6A61
ai_pc_6a88:
    ai_ret_00
