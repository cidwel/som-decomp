; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DA13
.include "src/rom/event_command_macros.inc"
event_387_command_DA13:
    event_jump 1535
event_387_command_DA15:
    event_end 
