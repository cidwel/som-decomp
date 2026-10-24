.setcpu "65816"
.segment "CODE"
.org $FA8E
map_control_0efa8e:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
