.setcpu "65816"
.segment "CODE"
.org $291E
map_control_0e291e:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
