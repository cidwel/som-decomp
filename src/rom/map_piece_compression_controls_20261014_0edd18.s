.setcpu "65816"
.segment "CODE"
.org $DD18
map_control_0edd18:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
