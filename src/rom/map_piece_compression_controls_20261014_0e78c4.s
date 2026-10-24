.setcpu "65816"
.segment "CODE"
.org $78C4
map_control_0e78c4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
