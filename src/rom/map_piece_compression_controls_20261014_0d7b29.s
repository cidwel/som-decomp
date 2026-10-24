.setcpu "65816"
.segment "CODE"
.org $7B29
map_control_0d7b29:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
