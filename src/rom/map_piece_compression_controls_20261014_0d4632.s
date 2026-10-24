.setcpu "65816"
.segment "CODE"
.org $4632
map_control_0d4632:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
