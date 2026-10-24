; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E349
.include "src/rom/event_command_macros.inc"
event_3AC_command_E349:
    event_jump 1535
event_3AC_command_E34B:
    event_end 
