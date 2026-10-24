; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D9CA
.include "src/rom/event_command_macros.inc"
event_386_command_D9CA:
    event_jump 1535
event_386_command_D9CC:
    event_end 
