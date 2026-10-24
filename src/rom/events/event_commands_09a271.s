; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A271
.include "src/rom/event_command_macros.inc"
event_262_command_A271:
    event_test_flag_range 36, 8, 15
event_262_command_A274:
    event_jump 618
