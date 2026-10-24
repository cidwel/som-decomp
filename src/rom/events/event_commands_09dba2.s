; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DBA2
.include "src/rom/event_command_macros.inc"
event_38D_command_DBA2:
    event_wait 0
