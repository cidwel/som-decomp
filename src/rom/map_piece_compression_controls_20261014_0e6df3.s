.setcpu "65816"
.segment "CODE"
.org $6DF3
map_control_0e6df3:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
