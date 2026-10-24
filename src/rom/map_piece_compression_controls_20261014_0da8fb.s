.setcpu "65816"
.segment "CODE"
.org $A8FB
map_control_0da8fb:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
