.setcpu "65816"
.segment "CODE"
.org $38C4
map_control_0f38c4:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
