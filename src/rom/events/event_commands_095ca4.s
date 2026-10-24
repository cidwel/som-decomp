; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5CA4
.include "src/rom/event_command_macros.inc"
event_18D_command_5CA4:
    event_jump 1535
event_18D_command_5CA6:
    event_end 
