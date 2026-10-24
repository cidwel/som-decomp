; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3199
.include "src/rom/event_command_macros.inc"
event_10C_command_3199:
    event_call 1988
event_10C_command_319B:
    event_screen 7
event_10C_command_319D:
    event_wait_idle 
