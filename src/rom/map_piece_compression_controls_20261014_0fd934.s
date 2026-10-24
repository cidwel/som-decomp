.setcpu "65816"
.segment "CODE"
.org $D934
map_control_0fd934:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
