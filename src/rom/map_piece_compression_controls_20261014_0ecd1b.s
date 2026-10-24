.setcpu "65816"
.segment "CODE"
.org $CD1B
map_control_0ecd1b:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
