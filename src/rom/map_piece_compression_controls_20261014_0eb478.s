.setcpu "65816"
.segment "CODE"
.org $B478
map_control_0eb478:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
