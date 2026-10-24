; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9D52
.include "src/rom/event_command_macros.inc"
event_23B_command_9D52:
    event_test_actor_field 1, 3, 145, 128
event_23B_command_9D56:
    event_jump 559
event_23B_command_9D58:
    event_wait 0
