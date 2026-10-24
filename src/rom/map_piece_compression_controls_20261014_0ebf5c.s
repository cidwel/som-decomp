.setcpu "65816"
.segment "CODE"
.org $BF5C
map_control_0ebf5c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
