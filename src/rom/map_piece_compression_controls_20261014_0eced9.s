.setcpu "65816"
.segment "CODE"
.org $CED9
map_control_0eced9:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
