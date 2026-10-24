.setcpu "65816"
.segment "CODE"
.org $471E
map_control_0d471e:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
