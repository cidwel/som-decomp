.setcpu "65816"
.segment "CODE"
.org $6300
map_control_0d6300:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
