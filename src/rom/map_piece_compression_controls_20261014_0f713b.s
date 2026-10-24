.setcpu "65816"
.segment "CODE"
.org $713B
map_control_0f713b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
