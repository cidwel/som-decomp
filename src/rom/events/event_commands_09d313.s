; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D313
.include "src/rom/event_command_macros.inc"
event_365_command_D313:
    event_jump 1535
event_365_command_D315:
    event_end 
event_366_command_D316:
    event_test_flag_range 27, 4, 15
event_366_command_D319:
    event_jump 871
