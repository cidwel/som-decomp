.setcpu "65816"
.segment "CODE"
.org $3A4A
map_control_0f3a4a:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
