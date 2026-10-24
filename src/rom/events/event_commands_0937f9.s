; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $37F9
.include "src/rom/event_command_macros.inc"
event_11A_command_37F9:
    event_jump 285
event_11A_command_37FB:
    event_jump 284
event_11A_command_37FD:
    event_jump 285
event_11A_command_37FF:
    event_end 
