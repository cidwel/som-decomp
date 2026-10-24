; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46FB
.include "src/rom/event_command_macros.inc"
event_149_command_46FB:
    event_jump 1535
event_149_command_46FD:
    event_end 
