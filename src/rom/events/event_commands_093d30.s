; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3D30
.include "src/rom/event_command_macros.inc"
event_134_command_3D30:
    event_jump 310
event_134_command_3D32:
    event_party_command 6
event_134_command_3D34:
    event_jump 310
event_134_command_3D36:
    event_end 
