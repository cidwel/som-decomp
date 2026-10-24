.setcpu "65816"
.segment "CODE"
.org $D78F
map_control_0fd78f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
