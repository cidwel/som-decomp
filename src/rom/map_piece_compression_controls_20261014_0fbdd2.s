.setcpu "65816"
.segment "CODE"
.org $BDD2
map_control_0fbdd2:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
