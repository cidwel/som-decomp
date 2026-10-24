.setcpu "65816"
.segment "CODE"
.org $139A
map_control_0d139a:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
