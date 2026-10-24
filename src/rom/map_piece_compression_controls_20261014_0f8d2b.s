.setcpu "65816"
.segment "CODE"
.org $8D2B
map_control_0f8d2b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
