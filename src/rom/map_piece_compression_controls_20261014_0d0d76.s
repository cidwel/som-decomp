.setcpu "65816"
.segment "CODE"
.org $0D76
map_control_0d0d76:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
