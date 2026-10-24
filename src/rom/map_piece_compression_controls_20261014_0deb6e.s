.setcpu "65816"
.segment "CODE"
.org $EB6E
map_control_0deb6e:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
