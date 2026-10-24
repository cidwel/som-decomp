.setcpu "65816"
.segment "CODE"
.org $DDF4
.include "boss_state_command_macros.inc"
boss_state_pc_c2ddf4:
    boss_state_anim $009A
boss_state_pc_c2ddf7:
    boss_state_duration14 $0018
boss_state_pc_c2ddfa:
    boss_state_f4a $619A
boss_state_pc_c2ddfd:
    boss_state_end
boss_state_pc_c2ddfe:
    boss_state_anim $009B
boss_state_pc_c2de01:
    boss_state_end
boss_state_pc_c2de02:
    boss_state_anim $009C
boss_state_pc_c2de05:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0005
boss_state_pc_c2de12:
    boss_state_callnative $61B1
boss_state_pc_c2de15:
    boss_state_store $0066, $0001
boss_state_pc_c2de1a:
    boss_state_speed90 $36BC
boss_state_pc_c2de1d:
    boss_state_f4a $3766
boss_state_pc_c2de20:
    boss_state_end
boss_state_pc_c2de21:
    boss_state_anim $009D
boss_state_pc_c2de24:
    boss_state_f4a $34B9
boss_state_pc_c2de27:
    boss_state_end
boss_state_pc_c2de28:
    boss_state_anim $009E
boss_state_pc_c2de2b:
    boss_state_callnative $6292
boss_state_pc_c2de2e:
    boss_state_store $007C, $0001
boss_state_pc_c2de33:
    boss_state_store $0082, $0000
boss_state_pc_c2de38:
    boss_state_end
boss_state_pc_c2de39:
    boss_state_anim $00A7
boss_state_pc_c2de3c:
    boss_state_duration14 $0006
boss_state_pc_c2de3f:
    boss_state_end
boss_state_pc_c2de40:
    boss_state_anim $00AF
boss_state_pc_c2de43:
    boss_state_duration14 $0006
boss_state_pc_c2de46:
    boss_state_end
boss_state_pc_c2de47:
    boss_state_set98_40
boss_state_pc_c2de48:
    boss_state_anim $009F
boss_state_pc_c2de4b:
    boss_state_duration14 $0006
boss_state_pc_c2de4e:
    boss_state_end
boss_state_pc_c2de4f:
    boss_state_clr98_40
boss_state_pc_c2de50:
    boss_state_anim $009F
boss_state_pc_c2de53:
    boss_state_duration14 $0006
boss_state_pc_c2de56:
    boss_state_end
boss_state_pc_c2de57:
    boss_state_anim $00A8
boss_state_pc_c2de5a:
    boss_state_duration14 $0006
boss_state_pc_c2de5d:
    boss_state_end
boss_state_pc_c2de5e:
    boss_state_anim $00B0
boss_state_pc_c2de61:
    boss_state_duration14 $0006
boss_state_pc_c2de64:
    boss_state_end
boss_state_pc_c2de65:
    boss_state_set98_40
boss_state_pc_c2de66:
    boss_state_anim $00A0
boss_state_pc_c2de69:
    boss_state_duration14 $0006
boss_state_pc_c2de6c:
    boss_state_end
boss_state_pc_c2de6d:
    boss_state_clr98_40
boss_state_pc_c2de6e:
    boss_state_anim $00A0
boss_state_pc_c2de71:
    boss_state_duration14 $0006
boss_state_pc_c2de74:
    boss_state_end
boss_state_pc_c2de75:
    boss_state_anim $00AA
boss_state_pc_c2de78:
    boss_state_callnative $61D0
boss_state_pc_c2de7b:
    boss_state_end
boss_state_pc_c2de7c:
    boss_state_anim $00B2
boss_state_pc_c2de7f:
    boss_state_callnative $61D0
boss_state_pc_c2de82:
    boss_state_end
boss_state_pc_c2de83:
    boss_state_set98_40
boss_state_pc_c2de84:
    boss_state_anim $00A2
boss_state_pc_c2de87:
    boss_state_callnative $61D0
boss_state_pc_c2de8a:
    boss_state_end
boss_state_pc_c2de8b:
    boss_state_clr98_40
boss_state_pc_c2de8c:
    boss_state_anim $00A2
boss_state_pc_c2de8f:
    boss_state_callnative $61D0
boss_state_pc_c2de92:
    boss_state_end
boss_state_pc_c2de93:
    boss_state_anim $00AB
boss_state_pc_c2de96:
    boss_state_callnative $620D
boss_state_pc_c2de99:
    boss_state_end
boss_state_pc_c2de9a:
    boss_state_anim $00B3
boss_state_pc_c2de9d:
    boss_state_callnative $620D
boss_state_pc_c2dea0:
    boss_state_end
boss_state_pc_c2dea1:
    boss_state_set98_40
boss_state_pc_c2dea2:
    boss_state_anim $00A3
boss_state_pc_c2dea5:
    boss_state_callnative $620D
boss_state_pc_c2dea8:
    boss_state_end
boss_state_pc_c2dea9:
    boss_state_clr98_40
boss_state_pc_c2deaa:
    boss_state_anim $00A3
boss_state_pc_c2dead:
    boss_state_callnative $620D
boss_state_pc_c2deb0:
    boss_state_end
boss_state_pc_c2deb1:
    boss_state_anim $00A7
boss_state_pc_c2deb4:
    boss_state_spell $030B
boss_state_pc_c2deb7:
    boss_state_duration14 $0018
boss_state_pc_c2deba:
    boss_state_end
boss_state_pc_c2debb:
    boss_state_anim $00AD
boss_state_pc_c2debe:
    boss_state_f4a $34B9
boss_state_pc_c2dec1:
    boss_state_end
boss_state_pc_c2dec2:
    boss_state_anim $00A5
boss_state_pc_c2dec5:
    boss_state_duration14 $0024
boss_state_pc_c2dec8:
    boss_state_callnative $6183
boss_state_pc_c2decb:
    boss_state_f48 $620D
boss_state_pc_c2dece:
    boss_state_end
boss_state_pc_c2decf:
    boss_state_anim $00A6
boss_state_pc_c2ded2:
    boss_state_callnative $6242
boss_state_pc_c2ded5:
    boss_state_callnative $3CAB
boss_state_pc_c2ded8:
    boss_state_f4a $34B9
boss_state_pc_c2dedb:
    boss_state_end
boss_state_pc_c2dedc:
    boss_state_anim $00AE
boss_state_pc_c2dedf:
    boss_state_callnative $6273
boss_state_pc_c2dee2:
    boss_state_duration14 $0018
boss_state_pc_c2dee5:
    boss_state_end
boss_state_pc_c2dee6:
    boss_state_anim $00B5
boss_state_pc_c2dee9:
    boss_state_frames $0000, $0000, $0000, $0000, $0000, $0005
boss_state_pc_c2def6:
    boss_state_callnative $61B1
boss_state_pc_c2def9:
    boss_state_store $0066, $0001
boss_state_pc_c2defe:
    boss_state_speed90 $36BC
boss_state_pc_c2df01:
    boss_state_f4a $3766
boss_state_pc_c2df04:
    boss_state_c0_006c $0024
boss_state_pc_c2df07:
    boss_state_end
boss_state_pc_c2df08:
    boss_state_anim $009C
boss_state_pc_c2df0b:
    boss_state_duration14 $0001
boss_state_pc_c2df0e:
    boss_state_end
boss_state_pc_c2df0f:
    boss_state_anim $00B4
boss_state_pc_c2df12:
    boss_state_callnative $6292
boss_state_pc_c2df15:
    boss_state_callnative $629C
boss_state_pc_c2df18:
    boss_state_end
boss_state_pc_c2df19:
    boss_state_anim $00A6
boss_state_pc_c2df1c:
    boss_state_callnative $6242
boss_state_pc_c2df1f:
    boss_state_callnative $3CAB
boss_state_pc_c2df22:
    boss_state_duration14 $0006
boss_state_pc_c2df25:
    boss_state_end
boss_state_pc_c2df26:
    boss_state_anim $00AF
boss_state_pc_c2df29:
    boss_state_frames $0000, $0000, $0000, $0002, $0000, $0008
boss_state_pc_c2df36:
    boss_state_jump $DF71
boss_state_pc_c2df39:
    boss_state_anim $00A7
boss_state_pc_c2df3c:
    boss_state_frames $0000, $0000, $0000, $FFFE, $0000, $0008
boss_state_pc_c2df49:
    boss_state_jump $DF71
boss_state_pc_c2df4c:
    boss_state_clr98_40
boss_state_pc_c2df4d:
    boss_state_anim $009F
boss_state_pc_c2df50:
    boss_state_frames $0000, $FFFE, $0000, $0000, $0000, $0008
boss_state_pc_c2df5d:
    boss_state_jump $DF71
boss_state_pc_c2df60:
    boss_state_set98_40
boss_state_pc_c2df61:
    boss_state_anim $009F
boss_state_pc_c2df64:
    boss_state_frames $0000, $0002, $0000, $0000, $0000, $0008
boss_state_pc_c2df71:
    boss_state_store $0066, $0001
boss_state_pc_c2df76:
    boss_state_store $007A, $0000
boss_state_pc_c2df7b:
    boss_state_speed90 $36BC
boss_state_pc_c2df7e:
    boss_state_f4a $3766
boss_state_pc_c2df81:
    boss_state_end
boss_state_pc_c2df82:
    boss_state_callnative $6292
boss_state_pc_c2df85:
    boss_state_callnative $629C
boss_state_pc_c2df88:
    boss_state_store $007C, $0000
boss_state_pc_c2df8d:
    boss_state_store $0082, $0001
boss_state_pc_c2df92:
    boss_state_end
boss_state_pc_c2df93:
    boss_state_anim $00A7
boss_state_pc_c2df96:
    boss_state_spell $020B
boss_state_pc_c2df99:
    boss_state_duration14 $0018
boss_state_pc_c2df9c:
    boss_state_end
boss_state_pc_c2df9d:
    boss_state_end
