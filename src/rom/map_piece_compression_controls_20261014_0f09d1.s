.setcpu "65816"
.segment "CODE"
.org $09D1
map_control_0f09d1:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
