.setcpu "65816"
.segment "CODE"
.org $765D
map_control_0f765d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
