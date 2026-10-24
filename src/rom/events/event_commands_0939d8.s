; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $39D8
.include "src/rom/event_command_macros.inc"
event_122_command_39D8:
    event_set_flag 84, 1
event_122_command_39DB:
    event_jump 1535
event_122_command_39DD:
    event_end 
