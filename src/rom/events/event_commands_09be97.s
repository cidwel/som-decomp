; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BE97
.include "src/rom/event_command_macros.inc"
event_2CE_command_BE97:
    event_jump 1535
event_2CE_command_BE99:
    event_end 
