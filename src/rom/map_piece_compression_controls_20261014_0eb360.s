.setcpu "65816"
.segment "CODE"
.org $B360
map_control_0eb360:
    .byte $EC ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
