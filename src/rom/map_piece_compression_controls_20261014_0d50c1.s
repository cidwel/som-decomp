.setcpu "65816"
.segment "CODE"
.org $50C1
map_control_0d50c1:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
