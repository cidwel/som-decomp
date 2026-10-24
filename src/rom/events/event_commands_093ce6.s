; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3CE6
.include "src/rom/event_command_macros.inc"
event_134_command_3CE6:
    event_test_flag_range 195, 0, 0
event_134_command_3CE9:
    event_call 314
