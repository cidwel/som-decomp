.setcpu "65816"
.segment "CODE"
.org $EB43
map_control_0feb43:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
