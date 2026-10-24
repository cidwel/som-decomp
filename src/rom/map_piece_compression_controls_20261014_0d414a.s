.setcpu "65816"
.segment "CODE"
.org $414A
map_control_0d414a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
