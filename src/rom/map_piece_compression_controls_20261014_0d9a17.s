.setcpu "65816"
.segment "CODE"
.org $9A17
map_control_0d9a17:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
