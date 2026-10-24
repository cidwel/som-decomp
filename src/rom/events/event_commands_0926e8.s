; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $26E8
.include "src/rom/event_command_macros.inc"
event_103_command_26E8:
    event_wait 32
event_103_command_26EA:
    event_increment_flag 10
event_103_command_26EC:
    event_refresh_objects 
event_103_command_26ED:
    event_screen 7
event_103_command_26EF:
    event_wait 4
