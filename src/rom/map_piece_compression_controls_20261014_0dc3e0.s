.setcpu "65816"
.segment "CODE"
.org $C3E0
map_control_0dc3e0:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
