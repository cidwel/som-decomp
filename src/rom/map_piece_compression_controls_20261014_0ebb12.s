.setcpu "65816"
.segment "CODE"
.org $BB12
map_control_0ebb12:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
