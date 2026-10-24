.setcpu "65816"
.segment "CODE"
.org $853A
map_control_0c853a:
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
