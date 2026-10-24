.setcpu "65816"
.segment "CODE"
.org $B940
map_control_0eb940:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
