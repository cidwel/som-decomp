.setcpu "65816"
.segment "CODE"
.org $BF70
map_control_0ebf70:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
