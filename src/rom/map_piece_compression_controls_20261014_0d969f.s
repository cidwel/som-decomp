.setcpu "65816"
.segment "CODE"
.org $969F
map_control_0d969f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
