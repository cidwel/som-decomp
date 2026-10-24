.setcpu "65816"
.segment "CODE"
.org $44A7
map_control_0d44a7:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
