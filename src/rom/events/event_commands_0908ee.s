; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $08EE
.include "src/rom/event_command_macros.inc"
event_010_command_08EE:
    event_return 
event_010_command_08EF:
    event_end 
