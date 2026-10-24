.setcpu "65816"
.segment "CODE"
.org $D16F
map_control_0fd16f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
