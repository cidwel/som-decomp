.setcpu "65816"
.segment "CODE"
.org $D7AA
map_control_0ed7aa:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
