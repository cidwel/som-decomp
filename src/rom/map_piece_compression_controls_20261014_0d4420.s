.setcpu "65816"
.segment "CODE"
.org $4420
map_control_0d4420:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
