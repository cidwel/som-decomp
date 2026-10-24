; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CC13
.include "src/rom/event_command_macros.inc"
event_2FE_command_CC13:
    event_return 
event_2FE_command_CC14:
    event_end 
event_2FF_command_CC15:
    event_end 
event_300_command_CC16:
    event_test_flag_range 16, 0, 3
event_300_command_CC19:
    event_call 210
event_300_command_CC1B:
    event_test_flag_range 16, 4, 9
event_300_command_CC1E:
    event_jump 211
event_300_command_CC20:
    event_test_flag_range 16, 10, 10
event_300_command_CC23:
    event_call 212
event_300_command_CC25:
    event_set_flag 250, 0
event_300_command_CC28:
    event_jump 784
event_300_command_CC2A:
    event_end 
event_301_command_CC2B:
    event_set_flag 250, 1
event_301_command_CC2E:
    event_jump 786
event_301_command_CC30:
    event_end 
event_302_command_CC31:
    event_set_flag 250, 2
event_302_command_CC34:
    event_jump 784
event_302_command_CC36:
    event_end 
event_303_command_CC37:
    event_set_flag 250, 3
event_303_command_CC3A:
    event_jump 784
event_303_command_CC3C:
    event_end 
event_304_command_CC3D:
    event_set_flag 250, 4
event_304_command_CC40:
    event_jump 784
event_304_command_CC42:
    event_end 
event_305_command_CC43:
    event_set_flag 250, 5
event_305_command_CC46:
    event_jump 784
event_305_command_CC48:
    event_end 
event_306_command_CC49:
    event_set_flag 250, 6
event_306_command_CC4C:
    event_jump 786
event_306_command_CC4E:
    event_end 
event_307_command_CC4F:
    event_set_flag 250, 7
event_307_command_CC52:
    event_jump 784
event_307_command_CC54:
    event_end 
event_308_command_CC55:
    event_set_flag 250, 8
event_308_command_CC58:
    event_jump 784
event_308_command_CC5A:
    event_end 
event_309_command_CC5B:
    event_set_flag 250, 9
event_309_command_CC5E:
    event_jump 784
event_309_command_CC60:
    event_end 
event_30A_command_CC61:
    event_set_flag 250, 10
event_30A_command_CC64:
    event_jump 784
event_30A_command_CC66:
    event_end 
event_30B_command_CC67:
    event_set_flag 250, 11
event_30B_command_CC6A:
    event_jump 784
event_30B_command_CC6C:
    event_end 
event_30C_command_CC6D:
    event_set_flag 250, 12
event_30C_command_CC70:
    event_jump 784
event_30C_command_CC72:
    event_end 
event_30D_command_CC73:
    event_set_flag 250, 13
event_30D_command_CC76:
    event_jump 784
event_30D_command_CC78:
    event_end 
event_30E_command_CC79:
    event_set_flag 250, 14
event_30E_command_CC7C:
    event_jump 784
event_30E_command_CC7E:
    event_end 
event_30F_command_CC7F:
    event_set_flag 250, 15
event_30F_command_CC82:
    event_jump 786
event_30F_command_CC84:
    event_end 
event_310_command_CC85:
    event_call 1152
