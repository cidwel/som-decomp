.setcpu "65816"
.segment "CODE"
.org $C70E
map_control_0ec70e:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
