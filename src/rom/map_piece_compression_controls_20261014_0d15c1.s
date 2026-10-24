.setcpu "65816"
.segment "CODE"
.org $15C1
map_control_0d15c1:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
