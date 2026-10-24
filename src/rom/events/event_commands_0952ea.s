; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $52EA
.include "src/rom/event_command_macros.inc"
event_171_command_52EA:
    event_jump 1535
event_171_command_52EC:
    event_end 
