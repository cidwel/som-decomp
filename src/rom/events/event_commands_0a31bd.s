; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $31BD
.include "src/rom/event_command_macros.inc"
event_4E2_command_31BD:
    event_test_flag_range 33, 5, 12
event_4E2_command_31C0:
    event_jump 595
