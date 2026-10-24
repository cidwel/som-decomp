; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4578
.include "src/rom/event_command_macros.inc"
event_145_command_4578:
    event_jump 1535
event_145_command_457A:
    event_end 
