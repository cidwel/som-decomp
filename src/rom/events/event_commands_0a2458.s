; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2458
.include "src/rom/event_command_macros.inc"
event_4B6_command_2458:
    event_call 1413
event_4B6_command_245A:
    event_set_flag 175, 2
event_4B6_command_245D:
    event_refresh_objects 
event_4B6_command_245E:
    event_wait 32
event_4B6_command_2460:
    event_call 1925
event_4B6_command_2462:
    event_screen 2
event_4B6_command_2464:
    event_wait 8
event_4B6_command_2466:
    event_screen 8
