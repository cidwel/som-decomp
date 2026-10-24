.setcpu "65816"
.segment "CODE"
.org $BA4E
map_control_0eba4e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
