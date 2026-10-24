; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D73B
.include "src/rom/event_command_macros.inc"
event_373_command_D73B:
    event_jump 1535
event_373_command_D73D:
    event_end 
