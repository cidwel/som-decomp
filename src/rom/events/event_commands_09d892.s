; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D892
.include "src/rom/event_command_macros.inc"
event_37C_command_D892:
    event_wait 0
