; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE92
.include "src/rom/event_command_macros.inc"
event_328_command_CE92:
    event_jump 817
event_328_command_CE94:
    event_end 
event_329_command_CE95:
    event_end 
event_32A_command_CE96:
    event_end 
event_32B_command_CE97:
    event_end 
event_32C_command_CE98:
    event_end 
event_32D_command_CE99:
    event_end 
event_32E_command_CE9A:
    event_end 
event_32F_command_CE9B:
    event_end 
event_330_command_CE9C:
    event_freeze 
event_330_command_CE9D:
    event_gather 
event_330_command_CE9E:
    event_screen 8
