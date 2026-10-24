.setcpu "65816"
.segment "CODE"
.org $6CF4
map_control_0f6cf4:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
