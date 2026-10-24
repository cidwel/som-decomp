.setcpu "65816"
.segment "CODE"
.org $49C7
map_control_0c49c7:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
