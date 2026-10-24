; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44E7
.include "src/rom/event_command_macros.inc"
event_142_command_44E7:
    event_jump 1535
event_142_command_44E9:
    event_end 
