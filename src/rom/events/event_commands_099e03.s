; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9E03
.include "src/rom/event_command_macros.inc"
event_23D_command_9E03:
    event_set_flag 20, 15
event_23D_command_9E06:
    event_jump 574
event_23D_command_9E08:
    event_end 
event_23E_command_9E09:
    event_call 1152
event_23E_command_9E0B:
    event_call 96
event_23E_command_9E0D:
    event_jump 439
event_23E_command_9E0F:
    event_end 
event_23F_command_9E10:
    event_freeze 
event_23F_command_9E11:
    event_change_map 497
