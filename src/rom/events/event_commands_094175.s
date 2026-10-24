; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4175
.include "src/rom/event_command_macros.inc"
event_13B_command_4175:
    event_jump 1535
event_13B_command_4177:
    event_end 
