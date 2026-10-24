; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DE87
.include "src/rom/event_command_macros.inc"
event_399_command_DE87:
    event_wait 0
