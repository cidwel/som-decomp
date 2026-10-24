.setcpu "65816"
.segment "CODE"
.org $C1AF
map_control_0ec1af:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
