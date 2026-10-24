.setcpu "65816"
.segment "CODE"
.org $E6C0
map_control_0fe6c0:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
