; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $67EB
.include "src/rom/event_command_macros.inc"
event_55D_command_67EB:
    event_jump 1535
event_55D_command_67ED:
    event_end 
event_55E_command_67EE:
    event_call 1149
