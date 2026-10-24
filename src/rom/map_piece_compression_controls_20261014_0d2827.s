.setcpu "65816"
.segment "CODE"
.org $2827
map_control_0d2827:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
