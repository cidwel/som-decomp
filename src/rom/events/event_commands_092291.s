; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2291
.include "src/rom/event_command_macros.inc"
event_0F4_command_2291:
    event_test_flag_range 15, 1, 15
event_0F4_command_2294:
    event_jump 248
event_0F4_command_2296:
    event_call 1943
event_0F4_command_2298:
    event_call 1040
