.setcpu "65816"
.segment "CODE"
.org $70E7
map_control_0f70e7:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
