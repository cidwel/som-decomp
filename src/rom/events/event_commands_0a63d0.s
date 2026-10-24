; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $63D0
.include "src/rom/event_command_macros.inc"
event_555_command_63D0:
    event_set_flag 13, 8
event_555_command_63D3:
    event_delete_actor 1
