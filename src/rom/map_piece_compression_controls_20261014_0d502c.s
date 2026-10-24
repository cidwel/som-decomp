.setcpu "65816"
.segment "CODE"
.org $502C
map_control_0d502c:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
