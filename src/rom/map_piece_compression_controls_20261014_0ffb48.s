.setcpu "65816"
.segment "CODE"
.org $FB48
map_control_0ffb48:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
