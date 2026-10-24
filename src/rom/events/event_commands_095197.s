; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5197
.include "src/rom/event_command_macros.inc"
event_16D_command_5197:
    event_decrement_flag 255
event_16D_command_5199:
    event_jump 1796
event_16D_command_519B:
    event_end 
event_16E_command_519C:
    event_set_flag 26, 6
event_16E_command_519F:
    event_call 1285
event_16E_command_51A1:
    event_call 1987
event_16E_command_51A3:
    event_change_map 52
event_16E_command_51A5:
    event_freeze 
event_16E_command_51A6:
    event_actor_walk 0, 0, 40
event_16E_command_51A9:
    event_wait_idle 
event_16E_command_51AA:
    event_call 1152
