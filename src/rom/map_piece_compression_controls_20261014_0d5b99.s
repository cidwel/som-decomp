.setcpu "65816"
.segment "CODE"
.org $5B99
map_control_0d5b99:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
