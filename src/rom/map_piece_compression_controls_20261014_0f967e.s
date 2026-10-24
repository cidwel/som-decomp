.setcpu "65816"
.segment "CODE"
.org $967E
map_control_0f967e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
