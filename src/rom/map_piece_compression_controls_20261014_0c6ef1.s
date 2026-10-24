.setcpu "65816"
.segment "CODE"
.org $6EF1
map_control_0c6ef1:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
