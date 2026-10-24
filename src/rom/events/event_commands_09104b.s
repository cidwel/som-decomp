; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $104B
.include "src/rom/event_command_macros.inc"
event_041_command_104B:
    event_wait 20
event_041_command_104D:
    event_wait 0
