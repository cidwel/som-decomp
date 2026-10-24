.setcpu "65816"
.segment "CODE"
.org $9DC4
map_control_0d9dc4:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
