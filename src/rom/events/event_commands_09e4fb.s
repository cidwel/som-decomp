; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E4FB
.include "src/rom/event_command_macros.inc"
event_3B6_command_E4FB:
    event_jump 1535
event_3B6_command_E4FD:
    event_end 
