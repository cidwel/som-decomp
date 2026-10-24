; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B09
.include "src/rom/event_command_macros.inc"
event_187_command_5B09:
    event_actor_walk 4, 1, 32
event_187_command_5B0C:
    event_test_flag_range 46, 1, 1
event_187_command_5B0F:
    event_jump 390
