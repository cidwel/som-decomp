.setcpu "65816"
.segment "CODE"
.org $306E
map_control_0f306e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
