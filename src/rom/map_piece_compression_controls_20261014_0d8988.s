.setcpu "65816"
.segment "CODE"
.org $8988
map_control_0d8988:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
