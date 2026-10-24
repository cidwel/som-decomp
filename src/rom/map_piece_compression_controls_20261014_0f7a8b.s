.setcpu "65816"
.segment "CODE"
.org $7A8B
map_control_0f7a8b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
