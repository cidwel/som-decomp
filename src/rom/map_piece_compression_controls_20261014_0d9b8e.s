.setcpu "65816"
.segment "CODE"
.org $9B8E
map_control_0d9b8e:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
