; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FAB
.include "src/rom/event_command_macros.inc"
event_194_command_5FAB:
    event_jump 1535
event_194_command_5FAD:
    event_end 
