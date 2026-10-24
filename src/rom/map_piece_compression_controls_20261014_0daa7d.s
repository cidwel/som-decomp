.setcpu "65816"
.segment "CODE"
.org $AA7D
map_control_0daa7d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
