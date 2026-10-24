.setcpu "65816"
.segment "CODE"
.org $858E
map_control_0f858e:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
