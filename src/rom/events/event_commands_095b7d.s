; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B7D
.include "src/rom/event_command_macros.inc"
event_189_command_5B7D:
    event_jump 1535
event_189_command_5B7F:
    event_end 
