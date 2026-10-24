.setcpu "65816"
.segment "CODE"
.org $33B6
map_control_0f33b6:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
