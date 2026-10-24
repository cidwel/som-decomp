.setcpu "65816"
.segment "CODE"
.org $440A
map_control_0d440a:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
