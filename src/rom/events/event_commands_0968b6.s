; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $68B6
.include "src/rom/event_command_macros.inc"
event_1B4_command_68B6:
    event_jump 1535
event_1B4_command_68B8:
    event_end 
