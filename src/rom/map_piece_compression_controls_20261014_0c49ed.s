.setcpu "65816"
.segment "CODE"
.org $49ED
map_control_0c49ed:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
