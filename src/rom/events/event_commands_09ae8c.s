; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AE8C
.include "src/rom/event_command_macros.inc"
event_292_command_AE8C:
    event_set_flag 40, 3
event_292_command_AE8F:
    event_end 
