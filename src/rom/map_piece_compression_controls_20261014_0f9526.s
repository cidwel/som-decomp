.setcpu "65816"
.segment "CODE"
.org $9526
map_control_0f9526:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
