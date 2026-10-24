.setcpu "65816"
.segment "CODE"
.org $507E
map_control_0d507e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
