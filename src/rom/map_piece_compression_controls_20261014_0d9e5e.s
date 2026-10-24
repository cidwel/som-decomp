.setcpu "65816"
.segment "CODE"
.org $9E5E
map_control_0d9e5e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
