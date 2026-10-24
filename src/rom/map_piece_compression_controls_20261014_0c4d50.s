.setcpu "65816"
.segment "CODE"
.org $4D50
map_control_0c4d50:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
