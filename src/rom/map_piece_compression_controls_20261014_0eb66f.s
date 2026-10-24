.setcpu "65816"
.segment "CODE"
.org $B66F
map_control_0eb66f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
