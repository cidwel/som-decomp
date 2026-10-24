; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $97D1
.include "src/rom/event_command_macros.inc"
event_226_command_97D1:
    event_test_flag_range 26, 8, 15
event_226_command_97D4:
    event_jump 551
