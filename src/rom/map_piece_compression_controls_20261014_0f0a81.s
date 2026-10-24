.setcpu "65816"
.segment "CODE"
.org $0A81
map_control_0f0a81:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
