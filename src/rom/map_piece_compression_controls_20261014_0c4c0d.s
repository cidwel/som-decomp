.setcpu "65816"
.segment "CODE"
.org $4C0D
map_control_0c4c0d:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
