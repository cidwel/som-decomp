.setcpu "65816"
.segment "CODE"
.org $D7B1
map_control_0ed7b1:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
