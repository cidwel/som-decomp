.setcpu "65816"
.segment "CODE"
.org $553E
map_control_0e553e:
    .byte $E8 ; backreference distance high bits
    .byte $7E ; distance low bit/count
