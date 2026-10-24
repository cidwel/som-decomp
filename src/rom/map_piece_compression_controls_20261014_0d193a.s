.setcpu "65816"
.segment "CODE"
.org $193A
map_control_0d193a:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
