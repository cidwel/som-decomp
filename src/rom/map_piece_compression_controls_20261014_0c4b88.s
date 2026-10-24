.setcpu "65816"
.segment "CODE"
.org $4B88
map_control_0c4b88:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
