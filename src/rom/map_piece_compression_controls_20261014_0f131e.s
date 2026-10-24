.setcpu "65816"
.segment "CODE"
.org $131E
map_control_0f131e:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
