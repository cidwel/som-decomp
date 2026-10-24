; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $752B
.include "src/rom/event_command_macros.inc"
event_592_command_752B:
    event_wait 0
