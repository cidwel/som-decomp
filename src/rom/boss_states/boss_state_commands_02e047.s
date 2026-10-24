.setcpu "65816"
.segment "CODE"
.org $E047
.include "boss_state_command_macros.inc"
boss_state_pc_c2e047:
    boss_state_set98_40
boss_state_pc_c2e048:
    boss_state_jump $E04C
boss_state_pc_c2e04b:
    boss_state_clr98_40
boss_state_pc_c2e04c:
    boss_state_anim $00B6
boss_state_pc_c2e04f:
    boss_state_duration14 $0018
boss_state_pc_c2e052:
    boss_state_end
boss_state_pc_c2e053:
    boss_state_set98_40
boss_state_pc_c2e054:
    boss_state_jump $E058
boss_state_pc_c2e057:
    boss_state_clr98_40
boss_state_pc_c2e058:
    boss_state_anim $00B7
boss_state_pc_c2e05b:
    boss_state_duration14 $0018
boss_state_pc_c2e05e:
    boss_state_end
boss_state_pc_c2e05f:
    boss_state_anim $00B8
boss_state_pc_c2e062:
    boss_state_end
boss_state_pc_c2e063:
    boss_state_anim $00BA
boss_state_pc_c2e066:
    boss_state_store $007C, $0001
boss_state_pc_c2e06b:
    boss_state_store $0082, $0000
boss_state_pc_c2e070:
    boss_state_end
boss_state_pc_c2e071:
    boss_state_anim $00BB
boss_state_pc_c2e074:
    boss_state_store $00A7, $0004
boss_state_pc_c2e079:
    boss_state_store $007C, $0001
boss_state_pc_c2e07e:
    boss_state_store $0000, $0001
boss_state_pc_c2e083:
    boss_state_end
boss_state_pc_c2e084:
    boss_state_anim $0000
boss_state_pc_c2e087:
    boss_state_f48 $63AC
boss_state_pc_c2e08a:
    boss_state_store $00A7, $0005
boss_state_pc_c2e08f:
    boss_state_store $007C, $0001
boss_state_pc_c2e094:
    boss_state_duration14 $0074
boss_state_pc_c2e097:
    boss_state_end
boss_state_pc_c2e098:
    boss_state_anim $00BD
boss_state_pc_c2e09b:
    boss_state_spell $010E
boss_state_pc_c2e09e:
    boss_state_end
boss_state_pc_c2e09f:
    boss_state_anim $00BD
boss_state_pc_c2e0a2:
    boss_state_spell $010C
boss_state_pc_c2e0a5:
    boss_state_end
boss_state_pc_c2e0a6:
    boss_state_anim $00BD
boss_state_pc_c2e0a9:
    boss_state_spell $0109
boss_state_pc_c2e0ac:
    boss_state_end
boss_state_pc_c2e0ad:
    boss_state_anim $00BD
boss_state_pc_c2e0b0:
    boss_state_spell $0107
boss_state_pc_c2e0b3:
    boss_state_end
boss_state_pc_c2e0b4:
    boss_state_spawn $0000, $0000, $00E8
boss_state_pc_c2e0b8:
    boss_state_c0_006c $0035
boss_state_pc_c2e0bb:
    boss_state_duration14 $000F
boss_state_pc_c2e0be:
    boss_state_end
boss_state_pc_c2e0bf:
    boss_state_spawn $0001, $0000, $00E8
boss_state_pc_c2e0c3:
    boss_state_c0_006c $0001
boss_state_pc_c2e0c6:
    boss_state_duration14 $000F
boss_state_pc_c2e0c9:
    boss_state_end
boss_state_pc_c2e0ca:
    boss_state_anim $00BC
boss_state_pc_c2e0cd:
    boss_state_f4a $34B9
boss_state_pc_c2e0d0:
    boss_state_end
boss_state_pc_c2e0d1:
    boss_state_callnative $63D4
boss_state_pc_c2e0d4:
    boss_state_store $0000, $0000
boss_state_pc_c2e0d9:
    boss_state_end
boss_state_pc_c2e0da:
    boss_state_store $007C, $0000
boss_state_pc_c2e0df:
    boss_state_store $0082, $0001
boss_state_pc_c2e0e4:
    boss_state_end
boss_state_pc_c2e0e5:
    boss_state_anim $00BD
boss_state_pc_c2e0e8:
    boss_state_spell $0012
boss_state_pc_c2e0eb:
    boss_state_end
boss_state_pc_c2e0ec:
    boss_state_anim $00BD
boss_state_pc_c2e0ef:
    boss_state_spell $0014
boss_state_pc_c2e0f2:
    boss_state_end
boss_state_pc_c2e0f3:
    boss_state_spawn $0002, $0000, $00E8
boss_state_pc_c2e0f7:
    boss_state_c0_006c $0002
boss_state_pc_c2e0fa:
    boss_state_duration14 $000F
boss_state_pc_c2e0fd:
    boss_state_end
boss_state_pc_c2e0fe:
    boss_state_anim $00BF
boss_state_pc_c2e101:
    boss_state_end
boss_state_pc_c2e102:
    boss_state_spell $0106
boss_state_pc_c2e105:
    boss_state_jump $E111
boss_state_pc_c2e108:
    boss_state_spell $010D
boss_state_pc_c2e10b:
    boss_state_jump $E111
boss_state_pc_c2e10e:
    boss_state_spell $0013
boss_state_pc_c2e111:
    boss_state_anim $00B9
boss_state_pc_c2e114:
    boss_state_c0_006c $0048
boss_state_pc_c2e117:
    boss_state_end
boss_state_pc_c2e118:
    boss_state_anim $00BD
boss_state_pc_c2e11b:
    boss_state_spell $0015
boss_state_pc_c2e11e:
    boss_state_end
boss_state_pc_c2e11f:
    boss_state_end
