.setcpu "65816"
.segment "CODE"
.org $E6C9
map_control_0fe6c9:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
