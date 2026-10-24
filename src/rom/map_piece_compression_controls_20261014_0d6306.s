.setcpu "65816"
.segment "CODE"
.org $6306
map_control_0d6306:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
