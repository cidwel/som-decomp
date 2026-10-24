; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3115
.include "src/rom/event_command_macros.inc"
event_10C_command_3115:
    event_call 1925
event_10C_command_3117:
    event_screen 2
event_10C_command_3119:
    event_wait 8
event_10C_command_311B:
    event_screen 8
event_10C_command_311D:
    event_gather 
