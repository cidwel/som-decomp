.setcpu "65816"
.segment "CODE"
.org $923E
map_control_0d923e:
    .byte $E8 ; backreference distance high bits
    .byte $3B ; distance low bit/count
