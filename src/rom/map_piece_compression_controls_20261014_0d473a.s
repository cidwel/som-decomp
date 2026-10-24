.setcpu "65816"
.segment "CODE"
.org $473A
map_control_0d473a:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
