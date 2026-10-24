.setcpu "65816"
.segment "CODE"
.org $9845
map_control_0e9845:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
