; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AA98
.include "src/rom/event_command_macros.inc"
event_28B_command_AA98:
    event_wait 0
