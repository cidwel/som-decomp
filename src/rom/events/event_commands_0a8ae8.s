; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8AE8
.include "src/rom/event_command_macros.inc"
event_66C_command_8AE8:
    event_decrement_flag 248
event_66C_command_8AEA:
    event_change_map 714
event_66C_command_8AEC:
    event_jump 1796
event_66C_command_8AEE:
    event_end 
event_66D_command_8AEF:
    event_set_flag 11, 2
event_66D_command_8AF2:
    event_set_flag 86, 6
event_66D_command_8AF5:
    event_set_flag 38, 4
event_66D_command_8AF8:
    event_call 1286
event_66D_command_8AFA:
    event_call 1987
event_66D_command_8AFC:
    event_change_map 715
event_66D_command_8AFE:
    event_call 1152
event_66D_command_8B00:
    event_actor_walk 1, 0, 60
event_66D_command_8B03:
    event_actor_walk 2, 0, 60
event_66D_command_8B06:
    event_actor_walk 3, 0, 60
event_66D_command_8B09:
    event_wait_idle 
event_66D_command_8B0A:
    event_screen 8
