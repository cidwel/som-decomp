.setcpu "65816"
.segment "CODE"
.org $D858
map_control_0dd858:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
