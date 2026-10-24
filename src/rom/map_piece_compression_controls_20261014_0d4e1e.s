.setcpu "65816"
.segment "CODE"
.org $4E1E
map_control_0d4e1e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
