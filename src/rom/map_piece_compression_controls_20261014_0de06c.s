.setcpu "65816"
.segment "CODE"
.org $E06C
map_control_0de06c:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
