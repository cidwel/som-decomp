.setcpu "65816"
.segment "CODE"
.org $302E
map_control_0f302e:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
