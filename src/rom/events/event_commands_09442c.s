; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $442C
.include "src/rom/event_command_macros.inc"
event_13E_command_442C:
    event_set_flag 30, 7
event_13E_command_442F:
    event_set_flag 164, 1
event_13E_command_4432:
    event_redraw_pieces 
event_13E_command_4433:
    event_jump 1535
event_13E_command_4435:
    event_end 
