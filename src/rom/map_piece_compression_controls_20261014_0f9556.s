.setcpu "65816"
.segment "CODE"
.org $9556
map_control_0f9556:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
