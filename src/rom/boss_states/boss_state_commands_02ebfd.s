.setcpu "65816"
.segment "CODE"
.org $EBFD
.include "boss_state_command_macros.inc"
boss_state_pc_c2ebfd:
    boss_state_set98_40
boss_state_pc_c2ebfe:
    boss_state_jump $EC02
boss_state_pc_c2ec01:
    boss_state_clr98_40
boss_state_pc_c2ec02:
    boss_state_anim $00FD
boss_state_pc_c2ec05:
    boss_state_duration14 $0024
boss_state_pc_c2ec08:
    boss_state_end
boss_state_pc_c2ec09:
    boss_state_set98_40
boss_state_pc_c2ec0a:
    boss_state_store $003C, $0006
boss_state_pc_c2ec0f:
    boss_state_store $007E, $FFFF
boss_state_pc_c2ec14:
    boss_state_jump $EC22
boss_state_pc_c2ec17:
    boss_state_clr98_40
boss_state_pc_c2ec18:
    boss_state_store $003C, $FFFA
boss_state_pc_c2ec1d:
    boss_state_store $007E, $0000
boss_state_pc_c2ec22:
    boss_state_anim $00FE
boss_state_pc_c2ec25:
    boss_state_duration14 $0024
boss_state_pc_c2ec28:
    boss_state_speed90 $73A7
boss_state_pc_c2ec2b:
    boss_state_c0_006c $003F
boss_state_pc_c2ec2e:
    boss_state_end
boss_state_pc_c2ec2f:
    boss_state_set98_40
boss_state_pc_c2ec30:
    boss_state_anim $0100
boss_state_pc_c2ec33:
    boss_state_end
boss_state_pc_c2ec34:
    boss_state_clr98_40
boss_state_pc_c2ec35:
    boss_state_anim $0100
boss_state_pc_c2ec38:
    boss_state_end
boss_state_pc_c2ec39:
    boss_state_set98_40
boss_state_pc_c2ec3a:
    boss_state_store $003C, $0004
boss_state_pc_c2ec3f:
    boss_state_jump $EC48
boss_state_pc_c2ec42:
    boss_state_clr98_40
boss_state_pc_c2ec43:
    boss_state_store $003C, $FFFC
boss_state_pc_c2ec48:
    boss_state_anim $00FF
boss_state_pc_c2ec4b:
    boss_state_speed90 $73A7
boss_state_pc_c2ec4e:
    boss_state_duration14 $000C
boss_state_pc_c2ec51:
    boss_state_c0_006c $0042
boss_state_pc_c2ec54:
    boss_state_end
boss_state_pc_c2ec55:
    boss_state_spell $0204
boss_state_pc_c2ec58:
    boss_state_jump $EC5E
boss_state_pc_c2ec5b:
    boss_state_spell $0222
boss_state_pc_c2ec5e:
    boss_state_anim $0101
boss_state_pc_c2ec61:
    boss_state_duration14 $000C
boss_state_pc_c2ec64:
    boss_state_end
boss_state_pc_c2ec65:
    boss_state_spawn $0019, $001A, $00F1
boss_state_pc_c2ec69:
    boss_state_c0_006c $0019
boss_state_pc_c2ec6c:
    boss_state_jump $EC7B
boss_state_pc_c2ec6f:
    boss_state_spawn $001A, $001A, $00F1
boss_state_pc_c2ec73:
    boss_state_c0_006c $001A
boss_state_pc_c2ec76:
    boss_state_store $00A9, $0004
boss_state_pc_c2ec7b:
    boss_state_anim $0101
boss_state_pc_c2ec7e:
    boss_state_duration14 $0024
boss_state_pc_c2ec81:
    boss_state_end
boss_state_pc_c2ec82:
    boss_state_anim $0102
boss_state_pc_c2ec85:
    boss_state_c0_006c $0046
boss_state_pc_c2ec88:
    boss_state_end
boss_state_pc_c2ec89:
    boss_state_set98_40
boss_state_pc_c2ec8a:
    boss_state_jump $EC8E
boss_state_pc_c2ec8d:
    boss_state_clr98_40
boss_state_pc_c2ec8e:
    boss_state_anim $00FD
boss_state_pc_c2ec91:
    boss_state_f4a $734B
boss_state_pc_c2ec94:
    boss_state_end
boss_state_pc_c2ec95:
    boss_state_anim $0103
boss_state_pc_c2ec98:
    boss_state_callnative $73E6
boss_state_pc_c2ec9b:
    boss_state_end
boss_state_pc_c2ec9c:
    boss_state_anim $0107
boss_state_pc_c2ec9f:
    boss_state_duration14 $34B9
boss_state_pc_c2eca2:
    boss_state_end
boss_state_pc_c2eca3:
    boss_state_set98_40
boss_state_pc_c2eca4:
    boss_state_store $003C, $0006
boss_state_pc_c2eca9:
    boss_state_store $007E, $FFFF
boss_state_pc_c2ecae:
    boss_state_jump $ECBC
boss_state_pc_c2ecb1:
    boss_state_clr98_40
boss_state_pc_c2ecb2:
    boss_state_store $003C, $FFFA
boss_state_pc_c2ecb7:
    boss_state_store $007E, $0000
boss_state_pc_c2ecbc:
    boss_state_anim $00FE
boss_state_pc_c2ecbf:
    boss_state_f4a $7388
boss_state_pc_c2ecc2:
    boss_state_duration14 $0024
boss_state_pc_c2ecc5:
    boss_state_speed90 $73A7
boss_state_pc_c2ecc8:
    boss_state_c0_006c $003F
boss_state_pc_c2eccb:
    boss_state_end
boss_state_pc_c2eccc:
    boss_state_set98_40
boss_state_pc_c2eccd:
    boss_state_store $003C, $0006
boss_state_pc_c2ecd2:
    boss_state_store $007E, $0001
boss_state_pc_c2ecd7:
    boss_state_jump $ECE5
boss_state_pc_c2ecda:
    boss_state_clr98_40
boss_state_pc_c2ecdb:
    boss_state_store $003C, $FFFA
boss_state_pc_c2ece0:
    boss_state_store $007E, $0000
boss_state_pc_c2ece5:
    boss_state_anim $00FE
boss_state_pc_c2ece8:
    boss_state_callnative $73AD
boss_state_pc_c2eceb:
    boss_state_duration14 $0024
boss_state_pc_c2ecee:
    boss_state_speed90 $73B7
boss_state_pc_c2ecf1:
    boss_state_c0_006c $0041
boss_state_pc_c2ecf4:
    boss_state_end
boss_state_pc_c2ecf5:
    boss_state_callnative $7273
boss_state_pc_c2ecf8:
    boss_state_duration14 $0001
boss_state_pc_c2ecfb:
    boss_state_end
boss_state_pc_c2ecfc:
    boss_state_end
