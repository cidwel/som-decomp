.setcpu "65816"
.segment "CODE"
.org $CD49
map_control_0ecd49:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
