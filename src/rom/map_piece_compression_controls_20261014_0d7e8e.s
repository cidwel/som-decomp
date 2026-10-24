.setcpu "65816"
.segment "CODE"
.org $7E8E
map_control_0d7e8e:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
