.setcpu "65816"
.segment "CODE"
.org $D1F4
map_control_0ed1f4:
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count
