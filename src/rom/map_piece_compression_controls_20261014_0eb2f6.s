.setcpu "65816"
.segment "CODE"
.org $B2F6
map_control_0eb2f6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
