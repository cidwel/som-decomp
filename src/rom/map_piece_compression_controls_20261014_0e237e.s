.setcpu "65816"
.segment "CODE"
.org $237E
map_control_0e237e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
