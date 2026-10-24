; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7861
.include "src/rom/event_command_macros.inc"
event_1CE_command_7861:
    event_jump 527
event_1CE_command_7863:
    event_jump 463
event_1CE_command_7865:
    event_jump 527
event_1CE_command_7867:
    event_end 
event_1CF_command_7868:
    event_call 94
event_1CF_command_786A:
    event_set_flag 15, 0
event_1CF_command_786D:
    event_object_command_37 100
