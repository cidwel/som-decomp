; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B3EA
.include "src/rom/event_command_macros.inc"
event_29E_command_B3EA:
    event_change_map 403
event_29E_command_B3EC:
    event_call 1988
event_29E_command_B3EE:
    event_increment_flag 255
