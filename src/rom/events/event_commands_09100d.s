; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $100D
.include "src/rom/event_command_macros.inc"
event_041_command_100D:
    event_test_actor 1
event_041_command_100F:
    event_jump 66
