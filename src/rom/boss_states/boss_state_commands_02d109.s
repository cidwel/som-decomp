.setcpu "65816"
.segment "CODE"
.org $D109
.include "boss_state_command_macros.inc"
boss_state_pc_c2d109:
    boss_state_clr98_40
boss_state_pc_c2d10a:
    boss_state_anim $000A
boss_state_pc_c2d10d:
    boss_state_duration14 $000C
boss_state_pc_c2d110:
    boss_state_end
boss_state_pc_c2d111:
    boss_state_set98_40
boss_state_pc_c2d112:
    boss_state_anim $000B
boss_state_pc_c2d115:
    boss_state_duration14 $0009
boss_state_pc_c2d118:
    boss_state_end
boss_state_pc_c2d119:
    boss_state_clr98_40
boss_state_pc_c2d11a:
    boss_state_anim $000B
boss_state_pc_c2d11d:
    boss_state_duration14 $0009
boss_state_pc_c2d120:
    boss_state_end
boss_state_pc_c2d121:
    boss_state_clr98_40
boss_state_pc_c2d122:
    boss_state_anim $000C
boss_state_pc_c2d125:
    boss_state_f4a $34B9
boss_state_pc_c2d128:
    boss_state_end
boss_state_pc_c2d129:
    boss_state_set98_40
boss_state_pc_c2d12a:
    boss_state_anim $000D
boss_state_pc_c2d12d:
    boss_state_duration14 $000C
boss_state_pc_c2d130:
    boss_state_end
boss_state_pc_c2d131:
    boss_state_clr98_40
boss_state_pc_c2d132:
    boss_state_anim $000D
boss_state_pc_c2d135:
    boss_state_duration14 $000C
boss_state_pc_c2d138:
    boss_state_end
boss_state_pc_c2d139:
    boss_state_anim $000E
boss_state_pc_c2d13c:
    boss_state_duration14 $000C
boss_state_pc_c2d13f:
    boss_state_end
boss_state_pc_c2d140:
    boss_state_clr98_40
boss_state_pc_c2d141:
    boss_state_anim $000F
boss_state_pc_c2d144:
    boss_state_c0_006c $0044
boss_state_pc_c2d147:
    boss_state_end
boss_state_pc_c2d148:
    boss_state_anim $0010
boss_state_pc_c2d14b:
    boss_state_duration14 $0009
boss_state_pc_c2d14e:
    boss_state_spell $0001
boss_state_pc_c2d151:
    boss_state_end
boss_state_pc_c2d152:
    boss_state_anim $0011
boss_state_pc_c2d155:
    boss_state_duration14 $000C
boss_state_pc_c2d158:
    boss_state_end
boss_state_pc_c2d159:
    boss_state_set98_40
boss_state_pc_c2d15a:
    boss_state_anim $0012
boss_state_pc_c2d15d:
    boss_state_c0_006c $0044
boss_state_pc_c2d160:
    boss_state_end
boss_state_pc_c2d161:
    boss_state_anim $0013
boss_state_pc_c2d164:
    boss_state_frames $0000, $0000, $0000, $FFFE, $0000, $0014
boss_state_pc_c2d171:
    boss_state_jump $D1BA
boss_state_pc_c2d174:
    boss_state_anim $0014
boss_state_pc_c2d177:
    boss_state_duration14 $0018
boss_state_pc_c2d17a:
    boss_state_end
boss_state_pc_c2d17b:
    boss_state_anim $0015
boss_state_pc_c2d17e:
    boss_state_end
boss_state_pc_c2d17f:
    boss_state_anim $0016
boss_state_pc_c2d182:
    boss_state_store $0066, $0000
boss_state_pc_c2d187:
    boss_state_store $00A7, $0004
boss_state_pc_c2d18c:
    boss_state_end
boss_state_pc_c2d18d:
    boss_state_callnative $3E7F
boss_state_pc_c2d190:
    boss_state_duration14 $0003
boss_state_pc_c2d193:
    boss_state_c0_006c $0063
boss_state_pc_c2d196:
    boss_state_end
boss_state_pc_c2d197:
    boss_state_anim $0013
boss_state_pc_c2d19a:
    boss_state_frames $0000, $FFFE, $0000, $FFFE, $0000, $0014
boss_state_pc_c2d1a7:
    boss_state_jump $D1BA
boss_state_pc_c2d1aa:
    boss_state_anim $0013
boss_state_pc_c2d1ad:
    boss_state_frames $0000, $0002, $0000, $FFFE, $0000, $0014
boss_state_pc_c2d1ba:
    boss_state_store $0066, $0001
boss_state_pc_c2d1bf:
    boss_state_store $00A7, $0003
boss_state_pc_c2d1c4:
    boss_state_speed90 $36BC
boss_state_pc_c2d1c7:
    boss_state_f4a $3766
boss_state_pc_c2d1ca:
    boss_state_end
boss_state_pc_c2d1cb:
    boss_state_anim $000C
boss_state_pc_c2d1ce:
    boss_state_spawn $0003, $0000, $00E0
boss_state_pc_c2d1d2:
    boss_state_duration14 $0024
boss_state_pc_c2d1d5:
    boss_state_c0_006c $0003
boss_state_pc_c2d1d8:
    boss_state_end
boss_state_pc_c2d1d9:
    boss_state_anim $000C
boss_state_pc_c2d1dc:
    boss_state_spawn $000A, $0000, $00E0
boss_state_pc_c2d1e0:
    boss_state_duration14 $0024
boss_state_pc_c2d1e3:
    boss_state_c0_006c $000A
boss_state_pc_c2d1e6:
    boss_state_end
boss_state_pc_c2d1e7:
    boss_state_anim $000C
boss_state_pc_c2d1ea:
    boss_state_spawn $000B, $0000, $00E0
boss_state_pc_c2d1ee:
    boss_state_duration14 $0024
boss_state_pc_c2d1f1:
    boss_state_c0_006c $000B
boss_state_pc_c2d1f4:
    boss_state_end
boss_state_pc_c2d1f5:
    boss_state_anim $0010
boss_state_pc_c2d1f8:
    boss_state_duration14 $0009
boss_state_pc_c2d1fb:
    boss_state_spell $021C
boss_state_pc_c2d1fe:
    boss_state_end
boss_state_pc_c2d1ff:
    boss_state_anim $0010
boss_state_pc_c2d202:
    boss_state_duration14 $0009
boss_state_pc_c2d205:
    boss_state_spell $0101
boss_state_pc_c2d208:
    boss_state_end
boss_state_pc_c2d209:
    boss_state_end
