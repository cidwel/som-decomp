.setcpu "65816"
.segment "CODE"
.org $9CF0
map_control_0d9cf0:
    .byte $E8 ; backreference distance high bits
    .byte $9E ; distance low bit/count
