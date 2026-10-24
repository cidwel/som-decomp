.setcpu "65816"
.segment "CODE"
.org $075E
map_control_0f075e:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
