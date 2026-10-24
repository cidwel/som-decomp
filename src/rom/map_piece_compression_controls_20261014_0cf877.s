.setcpu "65816"
.segment "CODE"
.org $F877
map_control_0cf877:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
