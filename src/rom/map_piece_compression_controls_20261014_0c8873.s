.setcpu "65816"
.segment "CODE"
.org $8873
map_control_0c8873:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
