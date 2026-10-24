; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FF8
.include "src/rom/event_command_macros.inc"
event_195_command_5FF8:
    event_jump 1535
event_195_command_5FFA:
    event_end 
