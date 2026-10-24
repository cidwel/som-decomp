.setcpu "65816"
.segment "CODE"
.org $53B4
map_control_0c53b4:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
