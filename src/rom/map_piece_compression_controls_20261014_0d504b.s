.setcpu "65816"
.segment "CODE"
.org $504B
map_control_0d504b:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
