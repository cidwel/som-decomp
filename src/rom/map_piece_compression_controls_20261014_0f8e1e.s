.setcpu "65816"
.segment "CODE"
.org $8E1E
map_control_0f8e1e:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
