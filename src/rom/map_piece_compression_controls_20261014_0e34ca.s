.setcpu "65816"
.segment "CODE"
.org $34CA
map_control_0e34ca:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
