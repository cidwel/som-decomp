.setcpu "65816"
.segment "CODE"
.org $8693
map_control_0f8693:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
