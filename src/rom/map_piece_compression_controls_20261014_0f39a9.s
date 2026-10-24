.setcpu "65816"
.segment "CODE"
.org $39A9
map_control_0f39a9:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
