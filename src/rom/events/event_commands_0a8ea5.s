; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8EA5
.include "src/rom/event_command_macros.inc"
event_67F_command_8EA5:
    event_return 
event_67F_command_8EA6:
    event_end 
event_680_command_8EA7:
    event_call 2
event_680_command_8EA9:
    event_call 1663
event_680_command_8EAB:
    event_set_flag 9, 1
event_680_command_8EAE:
    event_set_flag 208, 1
event_680_command_8EB1:
    event_refresh_objects 
event_680_command_8EB2:
    event_end 
event_681_command_8EB3:
    event_call 2
event_681_command_8EB5:
    event_call 1663
event_681_command_8EB7:
    event_set_flag 209, 1
event_681_command_8EBA:
    event_refresh_objects 
event_681_command_8EBB:
    event_end 
event_682_command_8EBC:
    event_call 2
event_682_command_8EBE:
    event_call 1663
event_682_command_8EC0:
    event_set_flag 210, 1
event_682_command_8EC3:
    event_refresh_objects 
event_682_command_8EC4:
    event_end 
event_683_command_8EC5:
    event_call 2
event_683_command_8EC7:
    event_call 1663
event_683_command_8EC9:
    event_set_flag 211, 1
event_683_command_8ECC:
    event_refresh_objects 
event_683_command_8ECD:
    event_end 
event_684_command_8ECE:
    event_call 2
event_684_command_8ED0:
    event_call 1663
event_684_command_8ED2:
    event_set_flag 212, 1
event_684_command_8ED5:
    event_refresh_objects 
event_684_command_8ED6:
    event_end 
event_685_command_8ED7:
    event_call 2
event_685_command_8ED9:
    event_call 1663
event_685_command_8EDB:
    event_set_flag 213, 1
event_685_command_8EDE:
    event_refresh_objects 
event_685_command_8EDF:
    event_end 
event_686_command_8EE0:
    event_call 2
event_686_command_8EE2:
    event_call 1663
event_686_command_8EE4:
    event_set_flag 214, 1
event_686_command_8EE7:
    event_refresh_objects 
event_686_command_8EE8:
    event_end 
event_687_command_8EE9:
    event_call 2
