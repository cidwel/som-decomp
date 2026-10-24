; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DB37
.include "src/rom/event_command_macros.inc"
event_38D_command_DB37:
    event_wait 0
