; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8338
.include "src/rom/event_command_macros.inc"
event_1E6_command_8338:
    event_actor_walk 0, 1, 0
event_1E6_command_833B:
    event_test_actor_field 6, 1, 128, 128
event_1E6_command_833F:
    event_jump 1535
event_1E6_command_8341:
    event_wait 0
