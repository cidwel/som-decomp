.setcpu "65816"
.segment "CODE"
.org $D97A
.include "boss_state_command_macros.inc"
boss_state_pc_c2d97a:
    boss_state_anim $0080
boss_state_pc_c2d97d:
    boss_state_duration14 $0018
boss_state_pc_c2d980:
    boss_state_end
boss_state_pc_c2d981:
    boss_state_anim $007F
boss_state_pc_c2d984:
    boss_state_f4a $34B9
boss_state_pc_c2d987:
    boss_state_end
boss_state_pc_c2d988:
    boss_state_spell $001F
boss_state_pc_c2d98b:
    boss_state_jump $D997
boss_state_pc_c2d98e:
    boss_state_spell $001E
boss_state_pc_c2d991:
    boss_state_jump $D997
boss_state_pc_c2d994:
    boss_state_spell $0222
boss_state_pc_c2d997:
    boss_state_anim $0082
boss_state_pc_c2d99a:
    boss_state_duration14 $000C
boss_state_pc_c2d99d:
    boss_state_end
boss_state_pc_c2d99e:
    boss_state_anim $007E
boss_state_pc_c2d9a1:
    boss_state_duration14 $0018
boss_state_pc_c2d9a4:
    boss_state_end
boss_state_pc_c2d9a5:
    boss_state_anim $007E
boss_state_pc_c2d9a8:
    boss_state_store $007E, $0001
boss_state_pc_c2d9ad:
    boss_state_duration14 $0005
boss_state_pc_c2d9b0:
    boss_state_end
boss_state_pc_c2d9b1:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0010
boss_state_pc_c2d9be:
    boss_state_store $00A7, $0005
boss_state_pc_c2d9c3:
    boss_state_speed90 $5278
boss_state_pc_c2d9c6:
    boss_state_f4a $52B0
boss_state_pc_c2d9c9:
    boss_state_end
boss_state_pc_c2d9ca:
    boss_state_speed90 $5663
boss_state_pc_c2d9cd:
    boss_state_duration14 $000C
boss_state_pc_c2d9d0:
    boss_state_end
boss_state_pc_c2d9d1:
    boss_state_anim $007F
boss_state_pc_c2d9d4:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFF0
boss_state_pc_c2d9e1:
    boss_state_store $00A7, $0004
boss_state_pc_c2d9e6:
    boss_state_store $00A5, $0018
boss_state_pc_c2d9eb:
    boss_state_c0_006c $005C
boss_state_pc_c2d9ee:
    boss_state_speed90 $5278
boss_state_pc_c2d9f1:
    boss_state_f4a $3766
boss_state_pc_c2d9f4:
    boss_state_end
boss_state_pc_c2d9f5:
    boss_state_anim $007F
boss_state_pc_c2d9f8:
    boss_state_callnative $560B
boss_state_pc_c2d9fb:
    boss_state_c0_006c $005D
boss_state_pc_c2d9fe:
    boss_state_speed90 $5612
boss_state_pc_c2da01:
    boss_state_duration14 $000C
boss_state_pc_c2da04:
    boss_state_end
boss_state_pc_c2da05:
    boss_state_anim $007F
boss_state_pc_c2da08:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFF0
boss_state_pc_c2da15:
    boss_state_callnative $560B
boss_state_pc_c2da18:
    boss_state_c0_006c $005F
boss_state_pc_c2da1b:
    boss_state_speed90 $5612
boss_state_pc_c2da1e:
    boss_state_duration14 $000C
boss_state_pc_c2da21:
    boss_state_end
boss_state_pc_c2da22:
    boss_state_anim $007E
boss_state_pc_c2da25:
    boss_state_store $007E, $0000
boss_state_pc_c2da2a:
    boss_state_duration14 $0005
boss_state_pc_c2da2d:
    boss_state_end
boss_state_pc_c2da2e:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0010
boss_state_pc_c2da3b:
    boss_state_store $00A7, $0005
boss_state_pc_c2da40:
    boss_state_speed90 $5278
boss_state_pc_c2da43:
    boss_state_f4a $52B0
boss_state_pc_c2da46:
    boss_state_end
boss_state_pc_c2da47:
    boss_state_anim $007F
boss_state_pc_c2da4a:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFF0
boss_state_pc_c2da57:
    boss_state_store $00A7, $0004
boss_state_pc_c2da5c:
    boss_state_store $00A5, $002A
boss_state_pc_c2da61:
    boss_state_c0_006c $005C
boss_state_pc_c2da64:
    boss_state_speed90 $5278
boss_state_pc_c2da67:
    boss_state_f4a $3766
boss_state_pc_c2da6a:
    boss_state_end
boss_state_pc_c2da6b:
    boss_state_anim $007E
boss_state_pc_c2da6e:
    boss_state_end
boss_state_pc_c2da6f:
    boss_state_anim $007F
boss_state_pc_c2da72:
    boss_state_f4a $34B9
boss_state_pc_c2da75:
    boss_state_end
boss_state_pc_c2da76:
    boss_state_anim $0083
boss_state_pc_c2da79:
    boss_state_store $007E, $0000
boss_state_pc_c2da7e:
    boss_state_callnative $52B7
boss_state_pc_c2da81:
    boss_state_duration14 $0006
boss_state_pc_c2da84:
    boss_state_end
boss_state_pc_c2da85:
    boss_state_anim $0084
boss_state_pc_c2da88:
    boss_state_callnative $52B7
boss_state_pc_c2da8b:
    boss_state_duration14 $000C
boss_state_pc_c2da8e:
    boss_state_end
boss_state_pc_c2da8f:
    boss_state_callnative $52F0
boss_state_pc_c2da92:
    boss_state_c0_006c $004F
boss_state_pc_c2da95:
    boss_state_callnative $3CAB
boss_state_pc_c2da98:
    boss_state_callnative $5329
boss_state_pc_c2da9b:
    boss_state_duration14 $0001
boss_state_pc_c2da9e:
    boss_state_end
boss_state_pc_c2da9f:
    boss_state_anim $0083
boss_state_pc_c2daa2:
    boss_state_store $007E, $8000
boss_state_pc_c2daa7:
    boss_state_duration14 $0024
boss_state_pc_c2daaa:
    boss_state_end
boss_state_pc_c2daab:
    boss_state_store $007E, $0000
boss_state_pc_c2dab0:
    boss_state_duration14 $0001
boss_state_pc_c2dab3:
    boss_state_end
boss_state_pc_c2dab4:
    boss_state_end
