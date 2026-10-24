; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4A72
.include "src/rom/event_command_macros.inc"
event_157_command_4A72:
    event_jump 1535
event_157_command_4A74:
    event_end 
