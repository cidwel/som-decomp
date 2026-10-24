.setcpu "65816"
.segment "CODE"
.org $9D67
map_control_0e9d67:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
