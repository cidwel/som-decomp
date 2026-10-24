.setcpu "65816"
.segment "CODE"
.org $50D5
map_control_0d50d5:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
