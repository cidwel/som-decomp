.setcpu "65816"
.segment "CODE"
.org $D4C8
map_control_0fd4c8:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
