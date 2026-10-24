.setcpu "65816"
.segment "CODE"
.org $4428
map_control_0d4428:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
