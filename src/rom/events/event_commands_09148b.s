; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $148B
.include "src/rom/event_command_macros.inc"
event_084_command_148B:
    event_change_map 160
event_084_command_148D:
    event_increment_flag 255
event_084_command_148F:
    event_call 1771
