; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $13AC
.include "src/rom/event_command_macros.inc"
event_082_command_13AC:
    event_wait 0
