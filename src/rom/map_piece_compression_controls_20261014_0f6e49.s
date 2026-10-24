.setcpu "65816"
.segment "CODE"
.org $6E49
map_control_0f6e49:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
