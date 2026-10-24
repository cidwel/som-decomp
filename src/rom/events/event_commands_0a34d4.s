; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $34D4
.include "src/rom/event_command_macros.inc"
event_4E2_command_34D4:
    event_call 1942
event_4E2_command_34D6:
    event_set_flag 33, 4
event_4E2_command_34D9:
    event_refresh_objects 
event_4E2_command_34DA:
    event_wait 16
