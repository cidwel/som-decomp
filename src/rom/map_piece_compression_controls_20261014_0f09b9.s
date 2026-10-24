.setcpu "65816"
.segment "CODE"
.org $09B9
map_control_0f09b9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
