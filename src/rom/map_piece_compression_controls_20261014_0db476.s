.setcpu "65816"
.segment "CODE"
.org $B476
map_control_0db476:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
