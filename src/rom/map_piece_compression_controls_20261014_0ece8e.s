.setcpu "65816"
.segment "CODE"
.org $CE8E
map_control_0ece8e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
