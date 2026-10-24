.setcpu "65816"
.segment "CODE"
.org $9C6B
map_control_0f9c6b:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
