; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B2CB
.include "src/rom/event_command_macros.inc"
event_29C_command_B2CB:
    event_increment_flag 40
event_29C_command_B2CD:
    event_refresh_objects 
