; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D83B
.include "src/rom/event_command_macros.inc"
event_37C_command_D83B:
    event_wait 0
