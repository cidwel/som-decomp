.setcpu "65816"
.segment "CODE"
.org $873E
map_control_0c873e:
    .byte $EC ; backreference distance high bits
    .byte $0F ; distance low bit/count
