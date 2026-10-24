; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E6D
.include "src/rom/event_command_macros.inc"
event_4B2_command_1E6D:
    event_change_map 984
