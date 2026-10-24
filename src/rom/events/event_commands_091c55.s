; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1C55
.include "src/rom/event_command_macros.inc"
event_0D2_command_1C55:
    event_return 
event_0D2_command_1C56:
    event_end 
