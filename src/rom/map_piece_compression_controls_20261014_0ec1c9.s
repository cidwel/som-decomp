.setcpu "65816"
.segment "CODE"
.org $C1C9
map_control_0ec1c9:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
