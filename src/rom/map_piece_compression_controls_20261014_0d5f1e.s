.setcpu "65816"
.segment "CODE"
.org $5F1E
map_control_0d5f1e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
