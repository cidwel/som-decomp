.setcpu "65816"
.segment "CODE"
.org $2ED5
map_control_0f2ed5:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
