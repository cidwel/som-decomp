.setcpu "65816"
.segment "CODE"
.org $F2DD
map_control_0ef2dd:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
