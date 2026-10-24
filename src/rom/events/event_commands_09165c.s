; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $165C
.include "src/rom/event_command_macros.inc"
event_0AE_command_165C:
    event_wait 0
