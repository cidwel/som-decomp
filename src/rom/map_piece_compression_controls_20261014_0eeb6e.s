.setcpu "65816"
.segment "CODE"
.org $EB6E
map_control_0eeb6e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
