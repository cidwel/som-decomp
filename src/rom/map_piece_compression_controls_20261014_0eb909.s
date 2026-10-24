.setcpu "65816"
.segment "CODE"
.org $B909
map_control_0eb909:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
