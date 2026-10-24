.setcpu "65816"
.segment "CODE"
.org $B4E6
map_control_0db4e6:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
