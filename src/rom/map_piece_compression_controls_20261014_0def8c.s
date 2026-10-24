.setcpu "65816"
.segment "CODE"
.org $EF8C
map_control_0def8c:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
