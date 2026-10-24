.setcpu "65816"
.segment "CODE"
.org $357E
map_control_0d357e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
