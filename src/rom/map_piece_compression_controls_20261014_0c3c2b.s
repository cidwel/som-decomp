.setcpu "65816"
.segment "CODE"
.org $3C2B
map_control_0c3c2b:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
