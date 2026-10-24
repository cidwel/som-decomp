; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DC10
.include "src/rom/event_command_macros.inc"
event_38D_command_DC10:
    event_wait 0
