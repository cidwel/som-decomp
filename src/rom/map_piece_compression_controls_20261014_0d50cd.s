.setcpu "65816"
.segment "CODE"
.org $50CD
map_control_0d50cd:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
