; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $10C7
.include "src/rom/event_command_macros.inc"
event_050_command_10C7:
    event_jump 0
event_050_command_10C9:
    event_party_command 6
event_050_command_10CB:
    event_jump 0
event_050_command_10CD:
    event_end 
event_051_command_10CE:
    event_actor_animation 1, 131
event_051_command_10D1:
    event_actor_animation 2, 131
event_051_command_10D4:
    event_actor_animation 3, 131
event_051_command_10D7:
    event_wait_idle 
event_051_command_10D8:
    event_return 
event_051_command_10D9:
    event_end 
event_052_command_10DA:
    event_actor_walk 1, 0, 0
event_052_command_10DD:
    event_actor_walk 2, 0, 0
event_052_command_10E0:
    event_actor_walk 3, 0, 0
event_052_command_10E3:
    event_wait_idle 
event_052_command_10E4:
    event_return 
event_052_command_10E5:
    event_end 
event_053_command_10E6:
    event_actor_walk 1, 1, 0
event_053_command_10E9:
    event_actor_walk 2, 1, 0
event_053_command_10EC:
    event_actor_walk 3, 1, 0
event_053_command_10EF:
    event_wait_idle 
event_053_command_10F0:
    event_return 
event_053_command_10F1:
    event_end 
event_054_command_10F2:
    event_actor_walk 1, 2, 0
event_054_command_10F5:
    event_actor_walk 2, 2, 0
event_054_command_10F8:
    event_actor_walk 3, 2, 0
event_054_command_10FB:
    event_wait_idle 
event_054_command_10FC:
    event_return 
event_054_command_10FD:
    event_end 
event_055_command_10FE:
    event_actor_walk 1, 3, 0
event_055_command_1101:
    event_actor_walk 2, 3, 0
event_055_command_1104:
    event_actor_walk 3, 3, 0
event_055_command_1107:
    event_wait_idle 
event_055_command_1108:
    event_return 
event_055_command_1109:
    event_end 
event_056_command_110A:
    event_actor_animation 1, 168
event_056_command_110D:
    event_actor_animation 2, 168
event_056_command_1110:
    event_actor_animation 3, 168
event_056_command_1113:
    event_wait_idle 
event_056_command_1114:
    event_wait 8
event_056_command_1116:
    event_return 
event_056_command_1117:
    event_end 
event_057_command_1118:
    event_actor_animation 1, 169
event_057_command_111B:
    event_actor_animation 2, 169
event_057_command_111E:
    event_actor_animation 3, 169
event_057_command_1121:
    event_wait_idle 
event_057_command_1122:
    event_wait 8
event_057_command_1124:
    event_return 
event_057_command_1125:
    event_end 
event_058_command_1126:
    event_actor_animation 1, 168
event_058_command_1129:
    event_wait_idle 
event_058_command_112A:
    event_wait 8
event_058_command_112C:
    event_return 
event_058_command_112D:
    event_end 
event_059_command_112E:
    event_actor_animation 2, 168
event_059_command_1131:
    event_wait_idle 
event_059_command_1132:
    event_wait 8
event_059_command_1134:
    event_return 
event_059_command_1135:
    event_end 
event_05A_command_1136:
    event_actor_animation 3, 168
event_05A_command_1139:
    event_wait_idle 
event_05A_command_113A:
    event_wait 8
event_05A_command_113C:
    event_return 
event_05A_command_113D:
    event_end 
event_05B_command_113E:
    event_actor_animation 1, 169
event_05B_command_1141:
    event_wait_idle 
event_05B_command_1142:
    event_wait 8
event_05B_command_1144:
    event_return 
event_05B_command_1145:
    event_end 
event_05C_command_1146:
    event_actor_animation 2, 169
event_05C_command_1149:
    event_wait_idle 
event_05C_command_114A:
    event_wait 8
event_05C_command_114C:
    event_return 
event_05C_command_114D:
    event_end 
event_05D_command_114E:
    event_actor_animation 3, 169
event_05D_command_1151:
    event_wait_idle 
event_05D_command_1152:
    event_wait 8
event_05D_command_1154:
    event_return 
event_05D_command_1155:
    event_end 
event_05E_command_1156:
    event_actor_animation 0, 168
event_05E_command_1159:
    event_wait_idle 
event_05E_command_115A:
    event_wait 8
event_05E_command_115C:
    event_return 
event_05E_command_115D:
    event_end 
event_05F_command_115E:
    event_actor_animation 0, 169
event_05F_command_1161:
    event_wait_idle 
event_05F_command_1162:
    event_wait 8
event_05F_command_1164:
    event_return 
event_05F_command_1165:
    event_end 
event_060_command_1166:
    event_actor_animation 1, 140
event_060_command_1169:
    event_actor_animation 2, 140
event_060_command_116C:
    event_actor_animation 3, 140
event_060_command_116F:
    event_wait_idle 
event_060_command_1170:
    event_return 
event_060_command_1171:
    event_end 
event_061_command_1172:
    event_end 
event_062_command_1173:
    event_call 94
