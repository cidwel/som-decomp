; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $20E8
.include "src/rom/event_command_macros.inc"
event_0EC_command_20E8:
    event_test_flag_range 15, 1, 15
event_0EC_command_20EB:
    event_jump 248
event_0EC_command_20ED:
    event_call 1943
event_0EC_command_20EF:
    event_call 1040
event_0EC_command_20F1:
    event_test_flag_range 40, 1, 15
event_0EC_command_20F4:
    event_jump 242
