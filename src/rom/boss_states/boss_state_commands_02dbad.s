.setcpu "65816"
.segment "CODE"
.org $DBAD
.include "boss_state_command_macros.inc"
boss_state_pc_c2dbad:
    boss_state_clr98_40
boss_state_pc_c2dbae:
    boss_state_anim $008E
boss_state_pc_c2dbb1:
    boss_state_duration14 $0018
boss_state_pc_c2dbb4:
    boss_state_end
boss_state_pc_c2dbb5:
    boss_state_clr98_40
boss_state_pc_c2dbb6:
    boss_state_anim $0095
boss_state_pc_c2dbb9:
    boss_state_duration14 $0018
boss_state_pc_c2dbbc:
    boss_state_end
boss_state_pc_c2dbbd:
    boss_state_anim $0092
boss_state_pc_c2dbc0:
    boss_state_callnative $5572
boss_state_pc_c2dbc3:
    boss_state_f48 $5576
boss_state_pc_c2dbc6:
    boss_state_duration14 $003C
boss_state_pc_c2dbc9:
    boss_state_end
boss_state_pc_c2dbca:
    boss_state_clr98_40
boss_state_pc_c2dbcb:
    boss_state_anim $0098
boss_state_pc_c2dbce:
    boss_state_duration14 $0018
boss_state_pc_c2dbd1:
    boss_state_end
boss_state_pc_c2dbd2:
    boss_state_clr98_40
boss_state_pc_c2dbd3:
    boss_state_anim $0097
boss_state_pc_c2dbd6:
    boss_state_duration14 $0018
boss_state_pc_c2dbd9:
    boss_state_end
boss_state_pc_c2dbda:
    boss_state_anim $0096
boss_state_pc_c2dbdd:
    boss_state_end
boss_state_pc_c2dbde:
    boss_state_spawn $0000, $0010, $00FE
boss_state_pc_c2dbe2:
    boss_state_c0_006c $0000
boss_state_pc_c2dbe5:
    boss_state_duration14 $000F
boss_state_pc_c2dbe8:
    boss_state_end
boss_state_pc_c2dbe9:
    boss_state_spawn $0005, $0010, $00FE
boss_state_pc_c2dbed:
    boss_state_c0_006c $0005
boss_state_pc_c2dbf0:
    boss_state_duration14 $000F
boss_state_pc_c2dbf3:
    boss_state_end
boss_state_pc_c2dbf4:
    boss_state_anim $0091
boss_state_pc_c2dbf7:
    boss_state_end
boss_state_pc_c2dbf8:
    boss_state_anim $0094
boss_state_pc_c2dbfb:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $001E
boss_state_pc_c2dc08:
    boss_state_store $0066, $0040
boss_state_pc_c2dc0d:
    boss_state_store $00A7, $0005
boss_state_pc_c2dc12:
    boss_state_speed90 $36BC
boss_state_pc_c2dc15:
    boss_state_duration14 $0006
boss_state_pc_c2dc18:
    boss_state_end
boss_state_pc_c2dc19:
    boss_state_anim $0090
boss_state_pc_c2dc1c:
    boss_state_spell $0010
boss_state_pc_c2dc1f:
    boss_state_end
boss_state_pc_c2dc20:
    boss_state_anim $0090
boss_state_pc_c2dc23:
    boss_state_spell $000C
boss_state_pc_c2dc26:
    boss_state_end
boss_state_pc_c2dc27:
    boss_state_anim $008E
boss_state_pc_c2dc2a:
    boss_state_duration14 $0024
boss_state_pc_c2dc2d:
    boss_state_end
boss_state_pc_c2dc2e:
    boss_state_anim $0093
boss_state_pc_c2dc31:
    boss_state_callnative $5586
boss_state_pc_c2dc34:
    boss_state_end
boss_state_pc_c2dc35:
    boss_state_anim $008F
boss_state_pc_c2dc38:
    boss_state_f4a $34B9
boss_state_pc_c2dc3b:
    boss_state_end
boss_state_pc_c2dc3c:
    boss_state_anim $0099
boss_state_pc_c2dc3f:
    boss_state_end
boss_state_pc_c2dc40:
    boss_state_anim $0090
boss_state_pc_c2dc43:
    boss_state_end
boss_state_pc_c2dc44:
    boss_state_anim $0094
boss_state_pc_c2dc47:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $FFE2
boss_state_pc_c2dc54:
    boss_state_store $0070, $0001
boss_state_pc_c2dc59:
    boss_state_c0_006c $0022
boss_state_pc_c2dc5c:
    boss_state_speed90 $36BC
boss_state_pc_c2dc5f:
    boss_state_f4a $56C3
boss_state_pc_c2dc62:
    boss_state_end
boss_state_pc_c2dc63:
    boss_state_store $00A7, $0004
boss_state_pc_c2dc68:
    boss_state_store $0066, $0000
boss_state_pc_c2dc6d:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0010
boss_state_pc_c2dc7a:
    boss_state_call30e3 $004A
boss_state_pc_c2dc7d:
    boss_state_c18003 $BCEF
boss_state_pc_c2dc80:
    boss_state_duration14 $0001
boss_state_pc_c2dc83:
    boss_state_end
boss_state_pc_c2dc84:
    boss_state_anim $0094
boss_state_pc_c2dc87:
    boss_state_store $0070, $0000
boss_state_pc_c2dc8c:
    boss_state_speed90 $5663
boss_state_pc_c2dc8f:
    boss_state_duration14 $000C
boss_state_pc_c2dc92:
    boss_state_end
boss_state_pc_c2dc93:
    boss_state_anim $0094
boss_state_pc_c2dc96:
    boss_state_callnative $560B
boss_state_pc_c2dc99:
    boss_state_c0_006c $0021
boss_state_pc_c2dc9c:
    boss_state_speed90 $5612
boss_state_pc_c2dc9f:
    boss_state_duration14 $000C
boss_state_pc_c2dca2:
    boss_state_end
boss_state_pc_c2dca3:
    boss_state_anim $0099
boss_state_pc_c2dca6:
    boss_state_c0_006c $0023
boss_state_pc_c2dca9:
    boss_state_f48 $55A2
boss_state_pc_c2dcac:
    boss_state_end
boss_state_pc_c2dcad:
    boss_state_callnative $55E3
boss_state_pc_c2dcb0:
    boss_state_callnative $3CAB
boss_state_pc_c2dcb3:
    boss_state_duration14 $0001
boss_state_pc_c2dcb6:
    boss_state_end
boss_state_pc_c2dcb7:
    boss_state_store $002B, $00D0
boss_state_pc_c2dcbc:
    boss_state_store $0032, $00E0
boss_state_pc_c2dcc1:
    boss_state_store $007E, $0000
boss_state_pc_c2dcc6:
    boss_state_duration14 $0001
boss_state_pc_c2dcc9:
    boss_state_end
boss_state_pc_c2dcca:
    boss_state_store $002B, $0070
boss_state_pc_c2dccf:
    boss_state_store $0032, $00C0
boss_state_pc_c2dcd4:
    boss_state_store $007E, $0001
boss_state_pc_c2dcd9:
    boss_state_duration14 $0001
boss_state_pc_c2dcdc:
    boss_state_end
boss_state_pc_c2dcdd:
    boss_state_store $002B, $0130
boss_state_pc_c2dce2:
    boss_state_store $0032, $00C0
boss_state_pc_c2dce7:
    boss_state_store $007E, $0001
boss_state_pc_c2dcec:
    boss_state_duration14 $0001
boss_state_pc_c2dcef:
    boss_state_end
boss_state_pc_c2dcf0:
    boss_state_spawn $0015, $0010, $00EE
boss_state_pc_c2dcf4:
    boss_state_c0_006c $0015
boss_state_pc_c2dcf7:
    boss_state_duration14 $000F
boss_state_pc_c2dcfa:
    boss_state_end
boss_state_pc_c2dcfb:
    boss_state_store $002B, $0080
boss_state_pc_c2dd00:
    boss_state_store $0032, $0130
boss_state_pc_c2dd05:
    boss_state_store $007E, $0001
boss_state_pc_c2dd0a:
    boss_state_duration14 $0001
boss_state_pc_c2dd0d:
    boss_state_end
boss_state_pc_c2dd0e:
    boss_state_store $002B, $0160
boss_state_pc_c2dd13:
    boss_state_store $0032, $00F0
boss_state_pc_c2dd18:
    boss_state_store $007E, $0001
boss_state_pc_c2dd1d:
    boss_state_duration14 $0001
boss_state_pc_c2dd20:
    boss_state_end
boss_state_pc_c2dd21:
    boss_state_store $002B, $00F0
boss_state_pc_c2dd26:
    boss_state_store $0032, $0120
boss_state_pc_c2dd2b:
    boss_state_store $007E, $0000
boss_state_pc_c2dd30:
    boss_state_duration14 $0001
boss_state_pc_c2dd33:
    boss_state_end
boss_state_pc_c2dd34:
    boss_state_end
