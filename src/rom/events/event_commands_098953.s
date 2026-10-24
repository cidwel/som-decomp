; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8953
.include "src/rom/event_command_macros.inc"
event_1F4_command_8953:
    event_jump 1535
event_1F4_command_8955:
    event_end 
