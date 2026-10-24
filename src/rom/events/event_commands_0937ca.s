; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $37CA
.include "src/rom/event_command_macros.inc"
event_119_command_37CA:
    event_jump 1535
event_119_command_37CC:
    event_end 
