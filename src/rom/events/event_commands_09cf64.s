; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CF64
.include "src/rom/event_command_macros.inc"
event_337_command_CF64:
    event_end 
event_338_command_CF65:
    event_actor_walk 1, 3, 12
event_338_command_CF68:
    event_return 
event_338_command_CF69:
    event_end 
event_339_command_CF6A:
    event_actor_walk 2, 3, 12
event_339_command_CF6D:
    event_return 
event_339_command_CF6E:
    event_end 
event_33A_command_CF6F:
    event_actor_walk 3, 3, 12
event_33A_command_CF72:
    event_return 
event_33A_command_CF73:
    event_end 
event_33B_command_CF74:
    event_actor_animation 1, 163
event_33B_command_CF77:
    event_return 
event_33B_command_CF78:
    event_end 
event_33C_command_CF79:
    event_actor_animation 2, 163
event_33C_command_CF7C:
    event_return 
event_33C_command_CF7D:
    event_end 
event_33D_command_CF7E:
    event_actor_animation 3, 163
event_33D_command_CF81:
    event_return 
event_33D_command_CF82:
    event_end 
event_33E_command_CF83:
    event_actor_walk 1, 2, 12
event_33E_command_CF86:
    event_return 
event_33E_command_CF87:
    event_end 
event_33F_command_CF88:
    event_actor_walk 2, 2, 12
event_33F_command_CF8B:
    event_return 
event_33F_command_CF8C:
    event_end 
event_340_command_CF8D:
    event_object_command_37 5
event_340_command_CF90:
    event_return 
event_340_command_CF91:
    event_end 
event_341_command_CF92:
    event_object_command_37 10
event_341_command_CF95:
    event_return 
event_341_command_CF96:
    event_end 
event_342_command_CF97:
    event_object_command_37 15
event_342_command_CF9A:
    event_return 
event_342_command_CF9B:
    event_end 
event_343_command_CF9C:
    event_object_command_37 30
event_343_command_CF9F:
    event_return 
event_343_command_CFA0:
    event_end 
event_344_command_CFA1:
    event_object_command_37 50
event_344_command_CFA4:
    event_return 
event_344_command_CFA5:
    event_end 
event_345_command_CFA6:
    event_object_command_37 100
event_345_command_CFA9:
    event_return 
event_345_command_CFAA:
    event_end 
event_346_command_CFAB:
    event_object_command_37 120
event_346_command_CFAE:
    event_return 
event_346_command_CFAF:
    event_end 
event_347_command_CFB0:
    event_object_command_37 150
event_347_command_CFB3:
    event_return 
event_347_command_CFB4:
    event_end 
event_348_command_CFB5:
    event_object_command_37 200
event_348_command_CFB8:
    event_return 
event_348_command_CFB9:
    event_end 
event_349_command_CFBA:
    event_end 
event_34A_command_CFBB:
    event_end 
event_34B_command_CFBC:
    event_end 
event_34C_command_CFBD:
    event_end 
event_34D_command_CFBE:
    event_end 
event_34E_command_CFBF:
    event_end 
event_34F_command_CFC0:
    event_end 
event_350_command_CFC1:
    event_actor_animation_loop 4, 128
event_350_command_CFC4:
    event_wait_idle 
event_350_command_CFC5:
    event_set_flag 152, 0
event_350_command_CFC8:
    event_test_actor_field 6, 4, 129, 23
event_350_command_CFCC:
    event_jump 856
event_350_command_CFCE:
    event_test_actor_field 1, 4, 129, 3
event_350_command_CFD2:
    event_return 
event_350_command_CFD3:
    event_noop 
event_350_command_CFD4:
    event_set_flag 152, 3
event_350_command_CFD7:
    event_test_actor_field 1, 4, 129, 2
event_350_command_CFDB:
    event_return 
event_350_command_CFDC:
    event_noop 
event_350_command_CFDD:
    event_decrement_flag 152
event_350_command_CFDF:
    event_test_actor_field 1, 4, 129, 1
event_350_command_CFE3:
    event_return 
event_350_command_CFE4:
    event_noop 
event_350_command_CFE5:
    event_decrement_flag 152
event_350_command_CFE7:
    event_return 
event_350_command_CFE8:
    event_end 
event_351_command_CFE9:
    event_actor_animation_loop 4, 128
event_351_command_CFEC:
    event_wait_idle 
event_351_command_CFED:
    event_set_flag 153, 0
event_351_command_CFF0:
    event_test_actor_field 6, 4, 129, 23
event_351_command_CFF4:
    event_jump 857
event_351_command_CFF6:
    event_test_actor_field 1, 4, 129, 9
event_351_command_CFFA:
    event_return 
event_351_command_CFFB:
    event_noop 
event_351_command_CFFC:
    event_set_flag 153, 3
event_351_command_CFFF:
    event_test_actor_field 1, 4, 129, 8
event_351_command_D003:
    event_return 
event_351_command_D004:
    event_noop 
event_351_command_D005:
    event_decrement_flag 153
event_351_command_D007:
    event_test_actor_field 1, 4, 129, 7
event_351_command_D00B:
    event_return 
event_351_command_D00C:
    event_noop 
event_351_command_D00D:
    event_decrement_flag 153
event_351_command_D00F:
    event_test_actor_field 1, 4, 129, 6
event_351_command_D013:
    event_return 
event_351_command_D014:
    event_noop 
event_351_command_D015:
    event_decrement_flag 153
event_351_command_D017:
    event_return 
event_351_command_D018:
    event_end 
event_352_command_D019:
    event_actor_animation_loop 4, 128
event_352_command_D01C:
    event_wait_idle 
event_352_command_D01D:
    event_set_flag 154, 0
event_352_command_D020:
    event_test_actor_field 6, 4, 129, 23
event_352_command_D024:
    event_jump 858
event_352_command_D026:
    event_test_actor_field 1, 4, 129, 21
event_352_command_D02A:
    event_return 
event_352_command_D02B:
    event_noop 
event_352_command_D02C:
    event_set_flag 154, 3
event_352_command_D02F:
    event_test_actor_field 1, 4, 129, 20
event_352_command_D033:
    event_return 
event_352_command_D034:
    event_noop 
event_352_command_D035:
    event_decrement_flag 154
event_352_command_D037:
    event_test_actor_field 1, 4, 129, 19
event_352_command_D03B:
    event_return 
event_352_command_D03C:
    event_noop 
event_352_command_D03D:
    event_decrement_flag 154
event_352_command_D03F:
    event_test_actor_field 1, 4, 129, 18
event_352_command_D043:
    event_return 
event_352_command_D044:
    event_noop 
event_352_command_D045:
    event_decrement_flag 154
event_352_command_D047:
    event_return 
event_352_command_D048:
    event_end 
event_353_command_D049:
    event_actor_animation_loop 4, 128
event_353_command_D04C:
    event_wait_idle 
event_353_command_D04D:
    event_set_flag 155, 0
event_353_command_D050:
    event_test_actor_field 6, 4, 129, 23
event_353_command_D054:
    event_jump 859
event_353_command_D056:
    event_test_actor_field 1, 4, 129, 15
event_353_command_D05A:
    event_return 
event_353_command_D05B:
    event_noop 
event_353_command_D05C:
    event_set_flag 155, 3
event_353_command_D05F:
    event_test_actor_field 1, 4, 129, 14
event_353_command_D063:
    event_return 
event_353_command_D064:
    event_noop 
event_353_command_D065:
    event_decrement_flag 155
event_353_command_D067:
    event_test_actor_field 1, 4, 129, 13
event_353_command_D06B:
    event_return 
event_353_command_D06C:
    event_noop 
event_353_command_D06D:
    event_decrement_flag 155
event_353_command_D06F:
    event_test_actor_field 1, 4, 129, 12
event_353_command_D073:
    event_return 
event_353_command_D074:
    event_noop 
event_353_command_D075:
    event_decrement_flag 155
event_353_command_D077:
    event_return 
event_353_command_D078:
    event_end 
event_354_command_D079:
    event_actor_animation_loop 4, 128
event_354_command_D07C:
    event_wait_idle 
event_354_command_D07D:
    event_set_flag 156, 0
event_354_command_D080:
    event_test_actor_field 6, 4, 129, 23
event_354_command_D084:
    event_jump 860
event_354_command_D086:
    event_test_actor_field 1, 4, 129, 41
event_354_command_D08A:
    event_return 
event_354_command_D08B:
    event_noop 
event_354_command_D08C:
    event_set_flag 156, 1
event_354_command_D08F:
    event_test_actor_field 1, 4, 129, 40
event_354_command_D093:
    event_return 
event_354_command_D094:
    event_noop 
event_354_command_D095:
    event_decrement_flag 156
event_354_command_D097:
    event_return 
event_354_command_D098:
    event_end 
event_355_command_D099:
    event_actor_animation_loop 4, 128
event_355_command_D09C:
    event_wait_idle 
event_355_command_D09D:
    event_set_flag 157, 0
event_355_command_D0A0:
    event_test_actor_field 6, 4, 129, 23
event_355_command_D0A4:
    event_jump 861
event_355_command_D0A6:
    event_test_actor_field 1, 4, 129, 39
event_355_command_D0AA:
    event_return 
event_355_command_D0AB:
    event_noop 
event_355_command_D0AC:
    event_set_flag 157, 3
event_355_command_D0AF:
    event_test_actor_field 1, 4, 129, 38
event_355_command_D0B3:
    event_return 
event_355_command_D0B4:
    event_noop 
event_355_command_D0B5:
    event_decrement_flag 157
event_355_command_D0B7:
    event_test_actor_field 1, 4, 129, 37
event_355_command_D0BB:
    event_return 
event_355_command_D0BC:
    event_noop 
event_355_command_D0BD:
    event_decrement_flag 157
event_355_command_D0BF:
    event_test_actor_field 1, 4, 129, 36
event_355_command_D0C3:
    event_return 
event_355_command_D0C4:
    event_noop 
event_355_command_D0C5:
    event_decrement_flag 157
event_355_command_D0C7:
    event_return 
event_355_command_D0C8:
    event_end 
event_356_command_D0C9:
    event_actor_animation_loop 4, 128
event_356_command_D0CC:
    event_wait_idle 
event_356_command_D0CD:
    event_set_flag 158, 0
event_356_command_D0D0:
    event_test_actor_field 6, 4, 129, 23
event_356_command_D0D4:
    event_jump 862
event_356_command_D0D6:
    event_test_actor_field 1, 4, 129, 27
event_356_command_D0DA:
    event_return 
event_356_command_D0DB:
    event_noop 
event_356_command_D0DC:
    event_set_flag 158, 3
event_356_command_D0DF:
    event_test_actor_field 1, 4, 129, 26
event_356_command_D0E3:
    event_return 
event_356_command_D0E4:
    event_noop 
event_356_command_D0E5:
    event_decrement_flag 158
event_356_command_D0E7:
    event_test_actor_field 1, 4, 129, 25
event_356_command_D0EB:
    event_return 
event_356_command_D0EC:
    event_noop 
event_356_command_D0ED:
    event_decrement_flag 158
event_356_command_D0EF:
    event_test_actor_field 1, 4, 129, 24
event_356_command_D0F3:
    event_return 
event_356_command_D0F4:
    event_noop 
event_356_command_D0F5:
    event_decrement_flag 158
event_356_command_D0F7:
    event_return 
event_356_command_D0F8:
    event_end 
event_357_command_D0F9:
    event_actor_animation_loop 4, 128
event_357_command_D0FC:
    event_wait_idle 
event_357_command_D0FD:
    event_set_flag 159, 0
event_357_command_D100:
    event_test_actor_field 6, 4, 129, 23
event_357_command_D104:
    event_jump 863
event_357_command_D106:
    event_test_actor_field 1, 4, 129, 32
event_357_command_D10A:
    event_return 
event_357_command_D10B:
    event_noop 
event_357_command_D10C:
    event_set_flag 159, 2
event_357_command_D10F:
    event_test_actor_field 1, 4, 129, 31
event_357_command_D113:
    event_return 
event_357_command_D114:
    event_noop 
event_357_command_D115:
    event_decrement_flag 159
event_357_command_D117:
    event_test_actor_field 1, 4, 129, 30
event_357_command_D11B:
    event_return 
event_357_command_D11C:
    event_noop 
event_357_command_D11D:
    event_decrement_flag 159
event_357_command_D11F:
    event_return 
event_357_command_D120:
    event_end 
event_358_command_D121:
    event_audio_request 2, 23, 15, 136
event_358_command_D126:
    event_actor_animation_loop 4, 129
