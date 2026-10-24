.setcpu "65816"
.segment "CODE"
.org $B4F8
map_control_0db4f8:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
