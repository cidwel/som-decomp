.setcpu "65816"
.segment "CODE"
.org $D2E4
map_control_0dd2e4:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
