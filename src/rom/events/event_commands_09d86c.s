; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D86C
.include "src/rom/event_command_macros.inc"
event_37C_command_D86C:
    event_wait 0
