.setcpu "65816"
.segment "CODE"
.org $BB2B
map_control_0fbb2b:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
