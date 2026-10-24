.setcpu "65816"
.segment "CODE"
.org $A92E
map_control_0da92e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
