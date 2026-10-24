.setcpu "65816"
.segment "CODE"
.org $938E
map_control_0e938e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
