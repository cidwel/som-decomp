.setcpu "65816"
.segment "CODE"
.org $522F
map_control_0d522f:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
