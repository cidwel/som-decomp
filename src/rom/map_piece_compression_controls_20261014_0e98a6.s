.setcpu "65816"
.segment "CODE"
.org $98A6
map_control_0e98a6:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
