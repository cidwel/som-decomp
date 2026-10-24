.setcpu "65816"
.segment "CODE"
.org $8A93
map_control_0e8a93:
    .byte $EB ; backreference distance high bits
    .byte $95 ; distance low bit/count
