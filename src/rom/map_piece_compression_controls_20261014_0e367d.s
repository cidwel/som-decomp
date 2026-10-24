.setcpu "65816"
.segment "CODE"
.org $367D
map_control_0e367d:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
