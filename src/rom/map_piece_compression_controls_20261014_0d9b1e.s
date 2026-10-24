.setcpu "65816"
.segment "CODE"
.org $9B1E
map_control_0d9b1e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
