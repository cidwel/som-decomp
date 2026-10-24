; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46B9
.include "src/rom/event_command_macros.inc"
event_148_command_46B9:
    event_test_flag_range 18, 0, 2
event_148_command_46BC:
    event_jump 332
