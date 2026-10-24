.setcpu "65816"
.segment "CODE"
.org $963E
map_control_0e963e:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
