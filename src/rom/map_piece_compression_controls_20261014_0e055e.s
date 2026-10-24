.setcpu "65816"
.segment "CODE"
.org $055E
map_control_0e055e:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
