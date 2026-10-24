.setcpu "65816"
.segment "CODE"
.org $09D5
map_control_0f09d5:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
