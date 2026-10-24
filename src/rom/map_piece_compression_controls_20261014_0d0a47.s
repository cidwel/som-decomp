.setcpu "65816"
.segment "CODE"
.org $0A47
map_control_0d0a47:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
