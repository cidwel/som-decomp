; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D3E9
.include "src/rom/event_command_macros.inc"
event_36A_command_D3E9:
    event_change_map 451
event_36A_command_D3EB:
    event_call 1999
