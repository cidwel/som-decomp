; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4F24
.include "src/rom/event_command_macros.inc"
event_16D_command_4F24:
    event_screen 8
event_16D_command_4F26:
    event_gather 
event_16D_command_4F27:
    event_wait 8
event_16D_command_4F29:
    event_increment_flag 26
event_16D_command_4F2B:
    event_refresh_objects 
event_16D_command_4F2C:
    event_wait 16
