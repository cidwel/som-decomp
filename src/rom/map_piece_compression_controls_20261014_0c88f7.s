.setcpu "65816"
.segment "CODE"
.org $88F7
map_control_0c88f7:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
