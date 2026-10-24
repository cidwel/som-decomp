; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E1B
.include "src/rom/event_command_macros.inc"
event_66F_command_8E1B:
    event_decrement_flag 248
event_66F_command_8E1D:
    event_call 1864
event_66F_command_8E1F:
    event_actor_walk 0, 1, 0
event_66F_command_8E22:
    event_set_actor_field 0, 144, 0
event_66F_command_8E26:
    event_set_actor_field 0, 145, 0
event_66F_command_8E2A:
    event_restore_hero 0
event_66F_command_8E2C:
    event_restore_hero 64
event_66F_command_8E2E:
    event_audio_request 2, 7, 0, 136
event_66F_command_8E33:
    event_native_command_35 
event_66F_command_8E34:
    event_wait 16
event_66F_command_8E36:
    event_jump 1590
event_66F_command_8E38:
    event_end 
event_670_command_8E39:
    event_call 2
event_670_command_8E3B:
    event_call 1280
event_670_command_8E3D:
    event_refresh_objects 
event_670_command_8E3E:
    event_end 
event_671_command_8E3F:
    event_call 2
event_671_command_8E41:
    event_call 1281
event_671_command_8E43:
    event_refresh_objects 
event_671_command_8E44:
    event_end 
event_672_command_8E45:
    event_call 2
event_672_command_8E47:
    event_call 1282
event_672_command_8E49:
    event_refresh_objects 
event_672_command_8E4A:
    event_end 
event_673_command_8E4B:
    event_call 2
event_673_command_8E4D:
    event_call 1283
event_673_command_8E4F:
    event_refresh_objects 
event_673_command_8E50:
    event_end 
event_674_command_8E51:
    event_call 2
event_674_command_8E53:
    event_call 1284
event_674_command_8E55:
    event_refresh_objects 
event_674_command_8E56:
    event_end 
event_675_command_8E57:
    event_call 2
event_675_command_8E59:
    event_call 1285
event_675_command_8E5B:
    event_refresh_objects 
event_675_command_8E5C:
    event_end 
event_676_command_8E5D:
    event_call 2
event_676_command_8E5F:
    event_call 1286
event_676_command_8E61:
    event_refresh_objects 
event_676_command_8E62:
    event_end 
event_677_command_8E63:
    event_call 2
event_677_command_8E65:
    event_call 1287
event_677_command_8E67:
    event_refresh_objects 
event_677_command_8E68:
    event_end 
event_678_command_8E69:
    event_end 
event_679_command_8E6A:
    event_end 
event_67A_command_8E6B:
    event_end 
event_67B_command_8E6C:
    event_end 
event_67C_command_8E6D:
    event_end 
event_67D_command_8E6E:
    event_end 
