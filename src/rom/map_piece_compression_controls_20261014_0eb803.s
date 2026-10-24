.setcpu "65816"
.segment "CODE"
.org $B803
map_control_0eb803:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
