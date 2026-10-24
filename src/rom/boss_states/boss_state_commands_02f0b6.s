.setcpu "65816"
.segment "CODE"
.org $F0B6
.include "boss_state_command_macros.inc"
boss_state_pc_c2f0b6:
    boss_state_set98_40
boss_state_pc_c2f0b7:
    boss_state_anim $0153
boss_state_pc_c2f0ba:
    boss_state_jump $F0C1
boss_state_pc_c2f0bd:
    boss_state_clr98_40
boss_state_pc_c2f0be:
    boss_state_anim $0153
boss_state_pc_c2f0c1:
    boss_state_duration14 $0024
boss_state_pc_c2f0c4:
    boss_state_speed90 $8CFB
boss_state_pc_c2f0c7:
    boss_state_end
boss_state_pc_c2f0c8:
    boss_state_anim $0154
boss_state_pc_c2f0cb:
    boss_state_duration14 $0003
boss_state_pc_c2f0ce:
    boss_state_speed90 $8CFB
boss_state_pc_c2f0d1:
    boss_state_end
boss_state_pc_c2f0d2:
    boss_state_anim $0155
boss_state_pc_c2f0d5:
    boss_state_f4a $34B9
boss_state_pc_c2f0d8:
    boss_state_speed90 $8CFB
boss_state_pc_c2f0db:
    boss_state_end
boss_state_pc_c2f0dc:
    boss_state_spawn $0001, $00EC, $0018
boss_state_pc_c2f0e0:
    boss_state_c0_006c $0037
boss_state_pc_c2f0e3:
    boss_state_jump $F115
boss_state_pc_c2f0e6:
    boss_state_spawn $0000, $00EC, $0018
boss_state_pc_c2f0ea:
    boss_state_c0_006c $0036
boss_state_pc_c2f0ed:
    boss_state_jump $F115
boss_state_pc_c2f0f0:
    boss_state_spawn $0002, $00EC, $0018
boss_state_pc_c2f0f4:
    boss_state_c0_006c $0002
boss_state_pc_c2f0f7:
    boss_state_jump $F115
boss_state_pc_c2f0fa:
    boss_state_spawn $0012, $00EC, $0018
boss_state_pc_c2f0fe:
    boss_state_c0_006c $0012
boss_state_pc_c2f101:
    boss_state_jump $F115
boss_state_pc_c2f104:
    boss_state_spawn $0014, $00EC, $0018
boss_state_pc_c2f108:
    boss_state_c0_006c $0014
boss_state_pc_c2f10b:
    boss_state_jump $F115
boss_state_pc_c2f10e:
    boss_state_spawn $0010, $00EC, $0018
boss_state_pc_c2f112:
    boss_state_c0_006c $0010
boss_state_pc_c2f115:
    boss_state_store $00A9, $0004
boss_state_pc_c2f11a:
    boss_state_duration14 $000F
boss_state_pc_c2f11d:
    boss_state_speed90 $8CFB
boss_state_pc_c2f120:
    boss_state_end
boss_state_pc_c2f121:
    boss_state_spell $0006
boss_state_pc_c2f124:
    boss_state_jump $F130
boss_state_pc_c2f127:
    boss_state_spell $000D
boss_state_pc_c2f12a:
    boss_state_jump $F130
boss_state_pc_c2f12d:
    boss_state_spell $0013
boss_state_pc_c2f130:
    boss_state_anim $0156
boss_state_pc_c2f133:
    boss_state_speed90 $8CFB
boss_state_pc_c2f136:
    boss_state_duration14 $0006
boss_state_pc_c2f139:
    boss_state_end
boss_state_pc_c2f13a:
    boss_state_anim $0156
boss_state_pc_c2f13d:
    boss_state_duration14 $0018
boss_state_pc_c2f140:
    boss_state_call30e3 $0083
boss_state_pc_c2f143:
    boss_state_c0_006c $006D
boss_state_pc_c2f146:
    boss_state_store $00A9, $0004
boss_state_pc_c2f14b:
    boss_state_spawn $001D, $0000, $0000
boss_state_pc_c2f14f:
    boss_state_speed90 $8CFB
boss_state_pc_c2f152:
    boss_state_end
boss_state_pc_c2f153:
    boss_state_anim $0156
boss_state_pc_c2f156:
    boss_state_speed90 $8CFB
boss_state_pc_c2f159:
    boss_state_end
boss_state_pc_c2f15a:
    boss_state_anim $0153
boss_state_pc_c2f15d:
    boss_state_duration14 $0024
boss_state_pc_c2f160:
    boss_state_speed90 $8D29
boss_state_pc_c2f163:
    boss_state_end
boss_state_pc_c2f164:
    boss_state_anim $0153
boss_state_pc_c2f167:
    boss_state_c0_006c $0067
boss_state_pc_c2f16a:
    boss_state_speed90 $8CFB
boss_state_pc_c2f16d:
    boss_state_duration14 $000C
boss_state_pc_c2f170:
    boss_state_end
boss_state_pc_c2f171:
    boss_state_anim $0153
boss_state_pc_c2f174:
    boss_state_callnative $8D42
boss_state_pc_c2f177:
    boss_state_speed90 $8D82
boss_state_pc_c2f17a:
    boss_state_f4a $8D89
boss_state_pc_c2f17d:
    boss_state_end
boss_state_pc_c2f17e:
    boss_state_anim $0153
boss_state_pc_c2f181:
    boss_state_callnative $8D62
boss_state_pc_c2f184:
    boss_state_speed90 $8D82
boss_state_pc_c2f187:
    boss_state_f4a $8DA5
boss_state_pc_c2f18a:
    boss_state_end
boss_state_pc_c2f18b:
    boss_state_anim $0153
boss_state_pc_c2f18e:
    boss_state_callnative $8D42
boss_state_pc_c2f191:
    boss_state_callnative $8D62
boss_state_pc_c2f194:
    boss_state_speed90 $8D82
boss_state_pc_c2f197:
    boss_state_f4a $8DC1
boss_state_pc_c2f19a:
    boss_state_end
boss_state_pc_c2f19b:
    boss_state_end
