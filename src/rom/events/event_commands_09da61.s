; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DA61
.include "src/rom/event_command_macros.inc"
event_389_command_DA61:
    event_jump 1535
event_389_command_DA63:
    event_end 
event_38A_command_DA64:
    event_end 
event_38B_command_DA65:
    event_change_map 351
event_38B_command_DA67:
    event_jump 1828
event_38B_command_DA69:
    event_end 
event_38C_command_DA6A:
    event_call 1152
event_38C_command_DA6C:
    event_call 1929
event_38C_command_DA6E:
    event_wait 16
event_38C_command_DA70:
    event_call 1929
event_38C_command_DA72:
    event_wait 4
event_38C_command_DA74:
    event_call 1929
event_38C_command_DA76:
    event_wait 24
