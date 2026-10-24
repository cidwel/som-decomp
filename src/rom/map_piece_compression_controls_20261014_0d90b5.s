.setcpu "65816"
.segment "CODE"
.org $90B5
map_control_0d90b5:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
