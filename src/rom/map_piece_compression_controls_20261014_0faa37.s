.setcpu "65816"
.segment "CODE"
.org $AA37
map_control_0faa37:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
