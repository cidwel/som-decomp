.setcpu "65816"
.segment "CODE"
.org $4446
map_control_0d4446:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
