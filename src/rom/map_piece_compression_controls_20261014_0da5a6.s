.setcpu "65816"
.segment "CODE"
.org $A5A6
map_control_0da5a6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
