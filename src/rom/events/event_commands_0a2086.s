; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2086
.include "src/rom/event_command_macros.inc"
event_4B3_command_2086:
    event_increment_flag 69
event_4B3_command_2088:
    event_change_map 856
event_4B3_command_208A:
    event_call 1988
event_4B3_command_208C:
    event_increment_flag 255
