.setcpu "65816"
.segment "CODE"
.org $44D6
map_control_0d44d6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
