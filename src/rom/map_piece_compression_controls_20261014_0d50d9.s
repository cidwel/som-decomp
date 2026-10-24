.setcpu "65816"
.segment "CODE"
.org $50D9
map_control_0d50d9:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
