; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC9C
.include "src/rom/event_command_macros.inc"
event_3DC_command_EC9C:
    event_wait 0
