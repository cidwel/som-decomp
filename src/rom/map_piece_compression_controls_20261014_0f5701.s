.setcpu "65816"
.segment "CODE"
.org $5701
map_control_0f5701:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
