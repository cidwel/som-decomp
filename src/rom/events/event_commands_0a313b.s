; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $313B
.include "src/rom/event_command_macros.inc"
event_4E1_command_313B:
    event_call 1843
event_4E1_command_313D:
    event_increment_flag 78
event_4E1_command_313F:
    event_change_map 47
event_4E1_command_3141:
    event_increment_flag 255
