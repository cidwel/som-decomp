.setcpu "65816"
.segment "CODE"
.org $6EDD
map_control_0f6edd:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
