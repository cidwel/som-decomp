; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ECD0
.include "src/rom/event_command_macros.inc"
event_3DC_command_ECD0:
    event_wait 0
