; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8AE5
.include "src/rom/event_command_macros.inc"
event_66C_command_8AE5:
    event_wait 32
