; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E515
.include "src/rom/event_command_macros.inc"
event_3B7_command_E515:
    event_jump 1535
event_3B7_command_E517:
    event_end 
