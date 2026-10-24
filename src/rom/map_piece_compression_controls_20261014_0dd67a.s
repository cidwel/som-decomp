.setcpu "65816"
.segment "CODE"
.org $D67A
map_control_0dd67a:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
