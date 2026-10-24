.setcpu "65816"
.segment "CODE"
.org $AB43
map_control_0eab43:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
