.setcpu "65816"
.segment "CODE"
.org $B34A
map_control_0fb34a:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
