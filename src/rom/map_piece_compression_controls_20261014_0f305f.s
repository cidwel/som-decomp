.setcpu "65816"
.segment "CODE"
.org $305F
map_control_0f305f:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
