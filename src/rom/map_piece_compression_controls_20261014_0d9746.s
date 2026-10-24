.setcpu "65816"
.segment "CODE"
.org $9746
map_control_0d9746:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
