; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7714
.include "src/rom/event_command_macros.inc"
event_59B_command_7714:
    event_screen 7
event_59B_command_7716:
    event_increment_flag 64
event_59B_command_7718:
    event_refresh_objects 
event_59B_command_7719:
    event_wait 32
