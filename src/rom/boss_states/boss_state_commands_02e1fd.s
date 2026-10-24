.setcpu "65816"
.segment "CODE"
.org $E1FD
.include "boss_state_command_macros.inc"
boss_state_pc_c2e1fd:
    boss_state_clr98_40
boss_state_pc_c2e1fe:
    boss_state_frames $0000, $FFFE, $0000, $0000, $0000, $0000
boss_state_pc_c2e20b:
    boss_state_jump $E21C
boss_state_pc_c2e20e:
    boss_state_set98_40
boss_state_pc_c2e20f:
    boss_state_frames $0000, $0002, $0000, $0000, $0000, $0000
boss_state_pc_c2e21c:
    boss_state_anim $00C2
boss_state_pc_c2e21f:
    boss_state_f48 $65E7
boss_state_pc_c2e222:
    boss_state_duration14 $0006
boss_state_pc_c2e225:
    boss_state_end
boss_state_pc_c2e226:
    boss_state_anim $00C3
boss_state_pc_c2e229:
    boss_state_f4a $34B9
boss_state_pc_c2e22c:
    boss_state_end
boss_state_pc_c2e22d:
    boss_state_store $007E, $0000
boss_state_pc_c2e232:
    boss_state_store $0192, $4020
boss_state_pc_c2e237:
    boss_state_jump $E26B
boss_state_pc_c2e23a:
    boss_state_store $007E, $0001
boss_state_pc_c2e23f:
    boss_state_store $0192, $0420
boss_state_pc_c2e244:
    boss_state_jump $E26B
boss_state_pc_c2e247:
    boss_state_store $007E, $0002
boss_state_pc_c2e24c:
    boss_state_store $0192, $0120
boss_state_pc_c2e251:
    boss_state_jump $E26B
boss_state_pc_c2e254:
    boss_state_store $007E, $0003
boss_state_pc_c2e259:
    boss_state_store $0192, $0820
boss_state_pc_c2e25e:
    boss_state_jump $E26B
boss_state_pc_c2e261:
    boss_state_store $007E, $0004
boss_state_pc_c2e266:
    boss_state_store $0192, $0220
boss_state_pc_c2e26b:
    boss_state_callnative $65ED
boss_state_pc_c2e26e:
    boss_state_duration14 $0001
boss_state_pc_c2e271:
    boss_state_end
boss_state_pc_c2e272:
    boss_state_spell $0026
boss_state_pc_c2e275:
    boss_state_jump $E28D
boss_state_pc_c2e278:
    boss_state_spell $000C
boss_state_pc_c2e27b:
    boss_state_jump $E28D
boss_state_pc_c2e27e:
    boss_state_spell $0000
boss_state_pc_c2e281:
    boss_state_jump $E28D
boss_state_pc_c2e284:
    boss_state_spell $0006
boss_state_pc_c2e287:
    boss_state_jump $E28D
boss_state_pc_c2e28a:
    boss_state_spell $0012
boss_state_pc_c2e28d:
    boss_state_anim $00C4
boss_state_pc_c2e290:
    boss_state_end
boss_state_pc_c2e291:
    boss_state_spell $000E
boss_state_pc_c2e294:
    boss_state_jump $E2A6
boss_state_pc_c2e297:
    boss_state_spell $0001
boss_state_pc_c2e29a:
    boss_state_jump $E2A6
boss_state_pc_c2e29d:
    boss_state_spell $0007
boss_state_pc_c2e2a0:
    boss_state_jump $E2A6
boss_state_pc_c2e2a3:
    boss_state_spell $0014
boss_state_pc_c2e2a6:
    boss_state_anim $00C5
boss_state_pc_c2e2a9:
    boss_state_end
boss_state_pc_c2e2aa:
    boss_state_spell $000C
boss_state_pc_c2e2ad:
    boss_state_jump $E2BF
boss_state_pc_c2e2b0:
    boss_state_spell $0000
boss_state_pc_c2e2b3:
    boss_state_jump $E2BF
boss_state_pc_c2e2b6:
    boss_state_spell $0006
boss_state_pc_c2e2b9:
    boss_state_jump $E2BF
boss_state_pc_c2e2bc:
    boss_state_spell $0012
boss_state_pc_c2e2bf:
    boss_state_anim $00C4
boss_state_pc_c2e2c2:
    boss_state_end
boss_state_pc_c2e2c3:
    boss_state_spell $000E
boss_state_pc_c2e2c6:
    boss_state_jump $E2D8
boss_state_pc_c2e2c9:
    boss_state_spell $0001
boss_state_pc_c2e2cc:
    boss_state_jump $E2D8
boss_state_pc_c2e2cf:
    boss_state_spell $0007
boss_state_pc_c2e2d2:
    boss_state_jump $E2D8
boss_state_pc_c2e2d5:
    boss_state_spell $0014
boss_state_pc_c2e2d8:
    boss_state_anim $00C6
boss_state_pc_c2e2db:
    boss_state_end
boss_state_pc_c2e2dc:
    boss_state_anim $00C1
boss_state_pc_c2e2df:
    boss_state_spawn $0016, $0000, $00E6
boss_state_pc_c2e2e3:
    boss_state_c0_006c $0016
boss_state_pc_c2e2e6:
    boss_state_duration14 $0018
boss_state_pc_c2e2e9:
    boss_state_end
boss_state_pc_c2e2ea:
    boss_state_callnative $65DD
boss_state_pc_c2e2ed:
    boss_state_c0_006c $0064
boss_state_pc_c2e2f0:
    boss_state_duration14 $0001
boss_state_pc_c2e2f3:
    boss_state_end
boss_state_pc_c2e2f4:
    boss_state_end
