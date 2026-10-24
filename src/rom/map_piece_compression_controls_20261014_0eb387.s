.setcpu "65816"
.segment "CODE"
.org $B387
map_control_0eb387:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
