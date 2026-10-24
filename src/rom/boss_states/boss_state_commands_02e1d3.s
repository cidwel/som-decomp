.setcpu "65816"
.segment "CODE"
.org $E1D3
.include "boss_state_command_macros.inc"
boss_state_pc_c2e1d3:
    boss_state_anim $00C1
boss_state_pc_c2e1d6:
    boss_state_duration14 $0006
boss_state_pc_c2e1d9:
    boss_state_end
boss_state_pc_c2e1da:
    boss_state_frames $0000, $0000, $0000, $FFFE, $0000, $0000
boss_state_pc_c2e1e7:
    boss_state_jump $E21C
boss_state_pc_c2e1ea:
    boss_state_frames $0000, $0000, $0000, $0002, $0000, $0000
boss_state_pc_c2e1f7:
    boss_state_jump $E21C
