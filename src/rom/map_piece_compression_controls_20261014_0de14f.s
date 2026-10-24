.setcpu "65816"
.segment "CODE"
.org $E14F
map_control_0de14f:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
