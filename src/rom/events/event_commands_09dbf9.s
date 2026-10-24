; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DBF9
.include "src/rom/event_command_macros.inc"
event_38D_command_DBF9:
    event_wait 32
