.setcpu "65816"
.segment "CODE"
.org $183E
map_control_0d183e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
