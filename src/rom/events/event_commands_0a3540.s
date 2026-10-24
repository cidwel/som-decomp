; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3540
.include "src/rom/event_command_macros.inc"
event_4E2_command_3540:
    event_call 1942
event_4E2_command_3542:
    event_increment_flag 33
event_4E2_command_3544:
    event_refresh_objects 
event_4E2_command_3545:
    event_call 1411
