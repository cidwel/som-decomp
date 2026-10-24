.setcpu "65816"
.segment "CODE"
.org $CF51
map_control_0ecf51:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
