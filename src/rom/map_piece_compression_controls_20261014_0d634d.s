.setcpu "65816"
.segment "CODE"
.org $634D
map_control_0d634d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
