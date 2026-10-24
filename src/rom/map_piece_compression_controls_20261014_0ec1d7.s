.setcpu "65816"
.segment "CODE"
.org $C1D7
map_control_0ec1d7:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
