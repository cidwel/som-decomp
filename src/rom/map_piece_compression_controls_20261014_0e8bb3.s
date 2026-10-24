.setcpu "65816"
.segment "CODE"
.org $8BB3
map_control_0e8bb3:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
