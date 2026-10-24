; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8714
.include "src/rom/event_command_macros.inc"
event_1EB_command_8714:
    event_end 
event_1EC_command_8715:
    event_call 7
event_1EC_command_8717:
    event_test_actor_field 6, 0, 228, 2
event_1EC_command_871B:
    event_jump 495
