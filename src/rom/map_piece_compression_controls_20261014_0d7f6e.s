.setcpu "65816"
.segment "CODE"
.org $7F6E
map_control_0d7f6e:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
