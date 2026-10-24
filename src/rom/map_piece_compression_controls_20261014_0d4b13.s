.setcpu "65816"
.segment "CODE"
.org $4B13
map_control_0d4b13:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
