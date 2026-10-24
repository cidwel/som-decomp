.setcpu "65816"
.segment "CODE"
.org $9988
map_control_0e9988:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
