.setcpu "65816"
.segment "CODE"
.org $9598
map_control_0f9598:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
