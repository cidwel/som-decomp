.setcpu "65816"
.segment "CODE"
.org $EDC5
.include "boss_state_command_macros.inc"
boss_state_pc_c2edc5:
    boss_state_clr98_40
boss_state_pc_c2edc6:
    boss_state_anim $0135
boss_state_pc_c2edc9:
    boss_state_frames $C000, $0001, $C000, $0001, $0000, $0000
boss_state_pc_c2edd6:
    boss_state_store $007E, $0000
boss_state_pc_c2eddb:
    boss_state_speed90 $772A
boss_state_pc_c2edde:
    boss_state_duration14 $000C
boss_state_pc_c2ede1:
    boss_state_c0_006c $003C
boss_state_pc_c2ede4:
    boss_state_end
boss_state_pc_c2ede5:
    boss_state_set98_40
boss_state_pc_c2ede6:
    boss_state_anim $0135
boss_state_pc_c2ede9:
    boss_state_frames $4000, $FFFE, $C000, $0001, $0000, $0000
boss_state_pc_c2edf6:
    boss_state_store $007E, $0000
boss_state_pc_c2edfb:
    boss_state_speed90 $7716
boss_state_pc_c2edfe:
    boss_state_duration14 $000C
boss_state_pc_c2ee01:
    boss_state_c0_006c $003C
boss_state_pc_c2ee04:
    boss_state_end
boss_state_pc_c2ee05:
    boss_state_set98_40
boss_state_pc_c2ee06:
    boss_state_anim $0137
boss_state_pc_c2ee09:
    boss_state_frames $4000, $FFFE, $4000, $FFFE, $0000, $0000
boss_state_pc_c2ee16:
    boss_state_store $007E, $0000
boss_state_pc_c2ee1b:
    boss_state_speed90 $772A
boss_state_pc_c2ee1e:
    boss_state_duration14 $000C
boss_state_pc_c2ee21:
    boss_state_c0_006c $003C
boss_state_pc_c2ee24:
    boss_state_end
boss_state_pc_c2ee25:
    boss_state_clr98_40
boss_state_pc_c2ee26:
    boss_state_anim $0137
boss_state_pc_c2ee29:
    boss_state_frames $C000, $0001, $4000, $FFFE, $0000, $0000
boss_state_pc_c2ee36:
    boss_state_store $007E, $0000
boss_state_pc_c2ee3b:
    boss_state_speed90 $7716
boss_state_pc_c2ee3e:
    boss_state_duration14 $000C
boss_state_pc_c2ee41:
    boss_state_c0_006c $003C
boss_state_pc_c2ee44:
    boss_state_end
boss_state_pc_c2ee45:
    boss_state_set98_40
boss_state_pc_c2ee46:
    boss_state_anim $0135
boss_state_pc_c2ee49:
    boss_state_jump $EE5E
boss_state_pc_c2ee4c:
    boss_state_clr98_40
boss_state_pc_c2ee4d:
    boss_state_anim $0135
boss_state_pc_c2ee50:
    boss_state_jump $EE5E
boss_state_pc_c2ee53:
    boss_state_set98_40
boss_state_pc_c2ee54:
    boss_state_anim $0137
boss_state_pc_c2ee57:
    boss_state_jump $EE5E
boss_state_pc_c2ee5a:
    boss_state_clr98_40
boss_state_pc_c2ee5b:
    boss_state_anim $0137
boss_state_pc_c2ee5e:
    boss_state_call30e3 $00D7
boss_state_pc_c2ee61:
    boss_state_duration14 $000C
boss_state_pc_c2ee64:
    boss_state_c0_006c $003C
boss_state_pc_c2ee67:
    boss_state_end
boss_state_pc_c2ee68:
    boss_state_clr98_40
boss_state_pc_c2ee69:
    boss_state_anim $0134
boss_state_pc_c2ee6c:
    boss_state_frames $C000, $0001, $C000, $0001, $0000, $0000
boss_state_pc_c2ee79:
    boss_state_speed90 $772A
boss_state_pc_c2ee7c:
    boss_state_c0_006c $003C
boss_state_pc_c2ee7f:
    boss_state_end
boss_state_pc_c2ee80:
    boss_state_set98_40
boss_state_pc_c2ee81:
    boss_state_anim $0134
boss_state_pc_c2ee84:
    boss_state_frames $4000, $FFFE, $C000, $0001, $0000, $0000
boss_state_pc_c2ee91:
    boss_state_speed90 $7716
boss_state_pc_c2ee94:
    boss_state_c0_006c $003C
boss_state_pc_c2ee97:
    boss_state_end
boss_state_pc_c2ee98:
    boss_state_set98_40
boss_state_pc_c2ee99:
    boss_state_anim $0136
boss_state_pc_c2ee9c:
    boss_state_frames $4000, $FFFE, $4000, $FFFE, $0000, $0000
boss_state_pc_c2eea9:
    boss_state_speed90 $772A
boss_state_pc_c2eeac:
    boss_state_c0_006c $003C
boss_state_pc_c2eeaf:
    boss_state_end
boss_state_pc_c2eeb0:
    boss_state_clr98_40
boss_state_pc_c2eeb1:
    boss_state_anim $0136
boss_state_pc_c2eeb4:
    boss_state_frames $C000, $0001, $4000, $FFFE, $0000, $0000
boss_state_pc_c2eec1:
    boss_state_speed90 $7716
boss_state_pc_c2eec4:
    boss_state_c0_006c $003C
boss_state_pc_c2eec7:
    boss_state_end
boss_state_pc_c2eec8:
    boss_state_clr98_40
boss_state_pc_c2eec9:
    boss_state_anim $0138
boss_state_pc_c2eecc:
    boss_state_f4a $34B9
boss_state_pc_c2eecf:
    boss_state_end
boss_state_pc_c2eed0:
    boss_state_set98_40
boss_state_pc_c2eed1:
    boss_state_anim $0138
boss_state_pc_c2eed4:
    boss_state_f4a $34B9
boss_state_pc_c2eed7:
    boss_state_end
boss_state_pc_c2eed8:
    boss_state_clr98_40
boss_state_pc_c2eed9:
    boss_state_anim $0139
boss_state_pc_c2eedc:
    boss_state_f4a $34B9
boss_state_pc_c2eedf:
    boss_state_end
boss_state_pc_c2eee0:
    boss_state_set98_40
boss_state_pc_c2eee1:
    boss_state_anim $0139
boss_state_pc_c2eee4:
    boss_state_f4a $34B9
boss_state_pc_c2eee7:
    boss_state_end
boss_state_pc_c2eee8:
    boss_state_spawn $0012, $0000, $0000
boss_state_pc_c2eeec:
    boss_state_duration14 $000C
boss_state_pc_c2eeef:
    boss_state_c0_006c $0012
boss_state_pc_c2eef2:
    boss_state_end
boss_state_pc_c2eef3:
    boss_state_spawn $0007, $0000, $0000
boss_state_pc_c2eef7:
    boss_state_duration14 $000C
boss_state_pc_c2eefa:
    boss_state_c0_006c $003A
boss_state_pc_c2eefd:
    boss_state_end
boss_state_pc_c2eefe:
    boss_state_duration14 $0006
boss_state_pc_c2ef01:
    boss_state_spell $0000
boss_state_pc_c2ef04:
    boss_state_end
boss_state_pc_c2ef05:
    boss_state_c0_006c $003D
boss_state_pc_c2ef08:
    boss_state_clr98_40
boss_state_pc_c2ef09:
    boss_state_anim $0134
boss_state_pc_c2ef0c:
    boss_state_store $00B4, $FFFF
boss_state_pc_c2ef11:
    boss_state_frames $C000, $0001, $C000, $0001, $0000, $0000
boss_state_pc_c2ef1e:
    boss_state_speed90 $772A
boss_state_pc_c2ef21:
    boss_state_f48 $76E3
boss_state_pc_c2ef24:
    boss_state_duration14 $000B
boss_state_pc_c2ef27:
    boss_state_end
boss_state_pc_c2ef28:
    boss_state_c0_006c $003D
boss_state_pc_c2ef2b:
    boss_state_set98_40
boss_state_pc_c2ef2c:
    boss_state_anim $0134
boss_state_pc_c2ef2f:
    boss_state_store $00B4, $FFFF
boss_state_pc_c2ef34:
    boss_state_frames $4000, $FFFE, $C000, $0001, $0000, $0000
boss_state_pc_c2ef41:
    boss_state_speed90 $7716
boss_state_pc_c2ef44:
    boss_state_f48 $76E3
boss_state_pc_c2ef47:
    boss_state_duration14 $000B
boss_state_pc_c2ef4a:
    boss_state_end
boss_state_pc_c2ef4b:
    boss_state_c0_006c $003D
boss_state_pc_c2ef4e:
    boss_state_set98_40
boss_state_pc_c2ef4f:
    boss_state_anim $0136
boss_state_pc_c2ef52:
    boss_state_store $00B4, $FFFF
boss_state_pc_c2ef57:
    boss_state_frames $C000, $0001, $4000, $FFFE, $0000, $0000
boss_state_pc_c2ef64:
    boss_state_speed90 $772A
boss_state_pc_c2ef67:
    boss_state_f48 $76E3
boss_state_pc_c2ef6a:
    boss_state_duration14 $000B
boss_state_pc_c2ef6d:
    boss_state_end
boss_state_pc_c2ef6e:
    boss_state_c0_006c $003D
boss_state_pc_c2ef71:
    boss_state_clr98_40
boss_state_pc_c2ef72:
    boss_state_anim $0136
boss_state_pc_c2ef75:
    boss_state_store $00B4, $FFFF
boss_state_pc_c2ef7a:
    boss_state_frames $4000, $FFFE, $4000, $FFFE, $0000, $0000
boss_state_pc_c2ef87:
    boss_state_speed90 $7716
boss_state_pc_c2ef8a:
    boss_state_f48 $76E3
boss_state_pc_c2ef8d:
    boss_state_call30e3 $0054
boss_state_pc_c2ef90:
    boss_state_duration14 $000B
boss_state_pc_c2ef93:
    boss_state_end
boss_state_pc_c2ef94:
    boss_state_callnative $7A29
boss_state_pc_c2ef97:
    boss_state_callnative $3CAB
boss_state_pc_c2ef9a:
    boss_state_duration14 $0001
boss_state_pc_c2ef9d:
    boss_state_end
boss_state_pc_c2ef9e:
    boss_state_c0_006c $003E
boss_state_pc_c2efa1:
    boss_state_jump $EF08
boss_state_pc_c2efa4:
    boss_state_c0_006c $003E
boss_state_pc_c2efa7:
    boss_state_jump $EF2B
boss_state_pc_c2efaa:
    boss_state_c0_006c $003E
boss_state_pc_c2efad:
    boss_state_jump $EF4E
boss_state_pc_c2efb0:
    boss_state_c0_006c $003E
boss_state_pc_c2efb3:
    boss_state_jump $EF71
boss_state_pc_c2efb6:
    boss_state_duration14 $0006
boss_state_pc_c2efb9:
    boss_state_spell $0001
boss_state_pc_c2efbc:
    boss_state_end
boss_state_pc_c2efbd:
    boss_state_end
