.setcpu "65816"
.segment "CODE"
.org $09B5
map_control_0f09b5:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
