.setcpu "65816"
.segment "CODE"
.org $CE76
map_control_0ece76:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
