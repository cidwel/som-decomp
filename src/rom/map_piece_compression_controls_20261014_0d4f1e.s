.setcpu "65816"
.segment "CODE"
.org $4F1E
map_control_0d4f1e:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
