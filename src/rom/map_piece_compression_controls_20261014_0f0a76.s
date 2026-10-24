.setcpu "65816"
.segment "CODE"
.org $0A76
map_control_0f0a76:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
